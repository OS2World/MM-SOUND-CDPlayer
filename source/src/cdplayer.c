#include "cdglobal.h"
#include "cdctl.h"
#include "cddevice.h"
#include "cdmenu.h"
#include "cdmsg.h"
#include "cdpos.h"
#include "cdprf.h"
#include "cdtset.h"
#include "cdtslide.h"
#include "cdtitle.h"
#include "cdvolume.h"
#include "subclass.h"
#include "wutil.h"
#include "cdplayer.h"
#include <io.h>

static BOOL SetProgramPath(char *argv0);
static BOOL SetDlgTitle(HWND hwnd, PSZ Title);
static BOOL StartWatchdog(HWND hwnd);
static BOOL StopWatchdog(HWND hwnd);

char CopyRightString[] = "Copyright (c) 1993-94 Michael Bock";

static BOOL Minimized = FALSE;
static BOOL InDestroy = FALSE;
static BOOL Initialized = FALSE;
static BOOL AdviseOn = FALSE;
static BOOL TrackFrame = FALSE;

HPOINTER hptrWait = NULL;

char SharedMemName[] = "\\SHAREMEM\\CDPLAYER.MEM";

int main(int argc, char *argv[], char *envp[])
{
    BOOL bResult;
    APIRET uResult;
    QMSG Msg, TmpMsg;
    FILE *fperr;
    HWND *SharedMem = NULLHANDLE;

    /*
    fperr = fopen("CDPLAYER.ERR", "w");

    _dup2(_fileno(fperr), 2);
    */

    hab = WinInitialize(0);
    if ( hab == NULLHANDLE )
        return 1;

    hmq = WinCreateMsgQueue(hab, 50);
    if ( hmq == NULLHANDLE )
        return 2;

    uResult = DosGetNamedSharedMem((PPVOID)&SharedMem, SharedMemName,
        PAG_READ | PAG_WRITE);

    if ( ! uResult ) {
        bResult = WinSetActiveWindow(HWND_DESKTOP, *SharedMem);
        bResult = WinDestroyMsgQueue(hmq);
        bResult = WinTerminate(hab);
        return 0;
        }

    bResult = WinRegisterGraphicButton();
    if ( ! bResult ) {
        return 3;
        }

    bResult = LoadResStrings(0);
    bResult = InitMousePointers();
    bResult = SetProgramPath(argv[0]);

    hwndDlg = WinLoadDlg(HWND_DESKTOP, HWND_DESKTOP, (PFNWP)MainDlgProc,
                (HMODULE)NULL, ID_DLG_MAIN, NULL);

    if ( hwndDlg == NULLHANDLE ) {
        return 4;
        } 

    uResult = DosAllocSharedMem((PPVOID)&SharedMem, SharedMemName, sizeof(HWND),
        PAG_COMMIT | PAG_READ | PAG_WRITE);

    if ( ! uResult )
        *SharedMem = hwndDlg;

    while ( WinGetMsg(hab, &Msg, NULLHANDLE, 0, 0) ) {
        if ( Msg.hwnd != hwndDlg || Msg.msg != MM_MCIPOSITIONCHANGE ||
             ! WinPeekMsg(hab, &TmpMsg, hwndDlg, MM_MCIPOSITIONCHANGE,
                    MM_MCIPOSITIONCHANGE, PM_NOREMOVE) )
            WinDispatchMsg(hab, &Msg);
        }

    InDestroy = TRUE;

    if ( TitleEditorInProcess ) {
        if ( ! TitleEditorHidden )
            WinSendMsg(TitleEditorDlg, WM_CLOSE, NULL, NULL);
        WinDestroyWindow(TitleEditorDlg);
        TitleEditorInProcess = FALSE;
        }

    if ( ProgramEditorInProcess ) {
        if ( ! ProgramEditorHidden )
            WinSendMsg(ProgramEditorDlg, WM_CLOSE, NULL, NULL);
        WinDestroyWindow(ProgramEditorDlg);
        ProgramEditorInProcess = FALSE;
        }

    if ( SettingsDlgInProcess ) {
        if ( ! SettingsDlgHidden )
            WinSendMsg(SettingsDlg, WM_CLOSE, NULL, NULL);
        WinDestroyWindow(SettingsDlg);
        SettingsDlgInProcess = FALSE;
        }

    if ( InfoInProcess ) {
        if ( ! InfoHidden )
            WinSendMsg(InfoDlg, WM_CLOSE, NULL, NULL);
        WinDestroyWindow(InfoDlg);
        InfoInProcess = FALSE;
        }

#if !(defined(RELEASE))
    if ( ! Registered )
        SharewareBox(hwndDlg, SharewareText);
#endif

    bResult = WinDestroyWindow(hwndDlg);
    bResult = WinDestroyMsgQueue(hmq);
    bResult = WinTerminate(hab);
 
    return 0;
}

/* Device Data */
USHORT DevID;
CDAUDIO_DRIVERINFO DriverInfo;
CDAUDIO_POSITION Position;
CDAUDIO_CONTENTS Contents;
CDAUDIO_PLAYLIST PlayList;
// CDAUDIO_TITLES Titles;
PSZ TitleAccess;
CDAUDIO_STATUS Status = CDSTATUS_NO_CD;

BOOL InitMainDlg(HWND hwnd)
{
    BOOL bResult;
    ULONG x, y, cx, cy, State;
    HELPINIT HelpInit;
    char TaskTitle[32];

    SliderSet = FALSE;
    TimeSliderDragged = FALSE;
    SeekInPause = FALSE;
    WinTimerStarted = FALSE;
    SettingsDlgInProcess = FALSE;
    // CuePointSet = -1;
    // SettingsDlgHidden = FALSE;
    AdviseOn = FALSE;
    TrackFrame = FALSE;

    /*
    if ( 0 == WinQuerySessionTitle(hab, 0, TaskTitle, sizeof(TaskTitle)) ) {
        DosBeep(1000, 1000);
        strcpy(ApplTitle, TaskTitle);
        }
    */

    HelpInit.cb = sizeof(HELPINIT);
    HelpInit.pszTutorialName = NULL;
    HelpInit.phtHelpTable = (HELPTABLE *)MAKELONG(ID_DLG_MAIN, 0xFFFF);
    HelpInit.hmodHelpTableModule = NULLHANDLE;
    HelpInit.hmodAccelActionBarModule = NULLHANDLE;
    HelpInit.idAccelTable = 0;
    HelpInit.idActionBar = 0;
    HelpInit.pszHelpWindowTitle = HelpTitle;
    HelpInit.fShowPanelId = CMIC_HIDE_PANEL_ID;
    HelpInit.pszHelpLibraryName = "CDPLAYER.HLP";

    hwndMainHelp = WinCreateHelpInstance(hab, &HelpInit);
    if ( hwndMainHelp == NULLHANDLE ) {
        CDError(hwnd, ERR_HELP_OPEN);
        }
    else {
        bResult = WinAssociateHelpInstance(hwndMainHelp, hwnd);
        if ( bResult ) {
            bResult = CDPrfLoadWindowPos(CDWINDOW_HELP, &x, &y, &cx, &cy, &State);
            if ( bResult ) 
                WinSetWindowPos(hwndMainHelp, HWND_TOP, x, y, cx, cy, SWP_MOVE | SWP_SIZE);
            }
        else {
            CDError(hwnd, ERR_HELP_OPEN);
            }

        }

    bResult = CDPrfOpen(ProgramPath, IniFileName);
    if ( ! bResult ) {
        CDFatalError(hwnd, ERR_PROFILE_OPEN);
        return FALSE;
        }

    bResult = CDPrfInitOptions();

    hptrIcon = WinLoadPointer(HWND_DESKTOP, 0, ID_ICON);
    hSwitch = MakeMainWindow(hwnd, ApplTitle, hptrIcon);

    bResult = InitVolume(hwnd);
    bResult = InitMenus(hwnd);
    bResult = InitPosition(hwnd);
    bResult = InitTrackSet(hwnd);
    bResult = InitTitleSelect(hwnd);
    bResult = InitTimeSlider(hwnd);
    bResult = InitButtons(hwnd);
    bResult = InitSubclasses();

    bResult = CDPrfLoadWindowPos(CDWINDOW_MAIN, &x, &y, &cx, &cy, &State);
    if ( bResult ) {
        WinSetWindowPos(hwnd, HWND_TOP, x, y, cx, cy, SWP_MOVE);
        if ( State == WINDOWSTATE_MINIMIZED) {
            WinSetWindowPos(hwnd, HWND_TOP, x, y, cx, cy, SWP_MINIMIZE);
            }
        }

    Initialized = TRUE;
    return TRUE;
}

_Inline BOOL GetPositionExt(
    USHORT DevID,
    MMTIME ProvideTime,
    CDAUDIO_CONTENTS *Contents,
    CDAUDIO_PLAYLIST *PlayList,
    CDAUDIO_POSITION *Pos)
{
    MMTIME CurrPosition;
    BOOL bResult;

    if ( ProvideTime == (MMTIME)-1 ) {
        bResult = CDGetRawPosition(DevID, &ProvideTime);
        }

    while ( ProvideTime >
            Contents->Track[PlayList->Track[PlayList->CurrTrack].ToPlay-1].Start +
            Contents->Track[PlayList->Track[PlayList->CurrTrack].ToPlay-1].Length ) {
        PlayList->CurrTrack++;
        }

    bResult = CDGetPosition(DevID, ProvideTime, Contents, PlayList, Pos);

    /*
    if ( Pos->TrackPlayed > 3000*60*60 ) {
        printf("");
        }
    */

    return bResult;
}

MRESULT EXPENTRY MainDlgProc( HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2 )
{
    BOOL bResult;
    ULONG MCIStatus;
    ULONG NextTrack, NextPosition;
    ULONG PlayLength;
    PSWP PSwp;
    static char Buffer[MAX_TITLE_LENGTH];
    static QMSG TmpMsg;
    static ULONG RegID;

    switch ( msg ) {
      case WM_INITDLG:
        SetWaitPointer(TRUE);
        bResult = InitMainDlg(hwnd);
 
        if ( ! bResult ) {
            WinPostMsg(hwnd, WM_QUIT, NULL, NULL);
            return 0;
            }

#if !(defined(RELEASE))
        if ( ! CDPrfQueryRegistered(&RegID, UserNameText) ) {
            SharewareBox(hwnd, SharewareText);
            }
        else {
            Registered = TRUE;
            sprintf(RegIDText, "%8.8X", RegID);
            }
#endif

#ifdef OLDVERSION
        bResult = CDGetStatus(DevID, &MCIStatus);

        if ( MCIStatus != MCI_MODE_NOT_READY ) {
            WinSendMsg(hwnd, CD_INSERTED, NULL, NULL);
            }
        else {
            WinSendMsg(hwnd, CD_REMOVED, NULL, NULL);
            }
#else
        Status = CDSTATUS_NO_DEVICE;
        WinSendMsg(hwnd, CD_NEWDEVICE, MPFROMP(DeviceName), NULL);
#endif

        return 0;

      case CD_NEWDEVICE :
        StopWatchdog(hwnd);

        if ( Status > CDSTATUS_NO_DEVICE ) {
            switch ( Status ) {
              case CDSTATUS_PAUSED :
                WinSendMsg(hwndPause, GBM_SETSTATE, MPFROMSHORT(GB_UP),
                    MPFROMLONG(TRUE));
              case CDSTATUS_PLAYING :
                if ( AnimationOn )
                    WinSendMsg(hwndPlay, GBM_ANIMATE, MPFROMLONG(FALSE),
                        MPFROMLONG(FALSE));
                WinSendMsg(hwndPlay, GBM_SETSTATE, MPFROMSHORT(GB_UP),
                    MPFROMLONG(TRUE));
                break;
                }

            CDCloseDevice(DevID);
            }

        bResult = CDOpenDevice(hwnd, PVOIDFROMMP(mp1), &DevID);
        if ( ! bResult ) {
            CDError(hwnd, ERR_DEVICE_OPEN);
            return WinSendMsg(hwnd, CD_DEVICEREMOVED, NULL, NULL);
            }

        bResult = CDDriverInfo(DevID, &DriverInfo);
        if ( ! bResult ) {
            CDError(hwnd, ERR_DEVICE_INFO);
            return WinSendMsg(hwnd, CD_DEVICEREMOVED, NULL, NULL);
            }

        if ( ! DriverInfo.CanPlayAudio ) {
            CDError(hwnd, ERR_NOAUDIO);
            return WinSendMsg(hwnd, CD_DEVICEREMOVED, NULL, NULL);
            }

        bResult = EnableVolume(TRUE, DevID, &DriverInfo);

        bResult = CDGetStatus(DevID, &MCIStatus);

        if ( MCIStatus != MCI_MODE_NOT_READY ) {
            WinSendMsg(hwnd, CD_INSERTED, NULL, NULL);
            }
        else {
            WinSendMsg(hwnd, CD_REMOVED, NULL, NULL);
            }
        return NULL;

      case HM_HELPSUBITEM_NOT_FOUND :
        if ( IsHelpButton(SHORT2FROMMP(mp2)) ) {
            WinSendMsg(hwndMainHelp, HM_DISPLAY_HELP, NULL, NULL);
            return MRFROMLONG(TRUE);
            }
        else {
            return MRFROMLONG(FALSE);
            }

      case WM_TIMER :
        if ( LONGFROMMP(mp1) != 1 ) {
            return WinDefDlgProc(hwnd, msg, mp1, mp2);
            } 
        else {
            bResult = CDGetStatus(DevID, &MCIStatus);
            if ( Status == CDSTATUS_NO_CD && MCIStatus != MCI_MODE_NOT_READY ) {
                SetWaitPointer(TRUE);
                WinSendMsg(hwnd, CD_INSERTED, NULL, NULL);
                } 
            else if ( Status != CDSTATUS_NO_CD && MCIStatus == MCI_MODE_NOT_READY ) {
                SetWaitPointer(TRUE);
                switch ( Status ) {
                  case CDSTATUS_PAUSED :
                    WinSendMsg(hwndPause, GBM_SETSTATE, MPFROMSHORT(GB_UP),
                        MPFROMLONG(TRUE));
                  case CDSTATUS_PLAYING :
                    if ( AnimationOn )
                        WinSendMsg(hwndPlay, GBM_ANIMATE, MPFROMLONG(FALSE),
                            MPFROMLONG(FALSE));
                    WinSendMsg(hwndPlay, GBM_SETSTATE, MPFROMSHORT(GB_UP),
                        MPFROMLONG(TRUE));
                    break;
                    }
                if ( Status != CDSTATUS_NO_AUDIO_CD) {
                    WinSendMsg(hwnd, CD_CLEANUP, NULL, NULL);
                    }
                WinSendMsg(hwnd, CD_REMOVED, NULL, NULL);
                }
            return NULL;
            }

      case CD_CLEANUP :
        return NULL;

      case CD_DEVICEREMOVED :
        if ( TitleAccess != NULL ) {
            if ( SavePosition )
                CDPrfSetPosition(TitleAccess, PlayList.CurrTrack, Position.CDPlayed);
            CDPrfReleaseAccess(TitleAccess);
            }
        SetDlgTitle(hwnd, NoDeviceText);
        EnableVolume(FALSE, 0, NULL);
        EnablePosition(FALSE);
        EnableTrackSet(FALSE);
        EnableTitleSelect(FALSE);
        EnableTimeSlider(FALSE);
        EnablePlayControls(FALSE);
        EnableEject(FALSE);
        EnableMenuItemControl(FALSE);
        Status = CDSTATUS_NO_DEVICE;
        return NULL;

      case CD_REMOVED :
        StopWatchdog(hwnd);

        SetDlgTitle(hwnd, CDNone);
        EnablePosition(FALSE);
        EnableTrackSet(FALSE);
        EnableTitleSelect(FALSE);
        EnableTimeSlider(FALSE);
        EnablePlayControls(FALSE);
        EnableEject(FALSE);
        EnableMenuItemControl(FALSE);
        Status = CDSTATUS_NO_CD;
        if ( TitleAccess != NULL ) {
            if ( SavePosition )
                CDPrfSetPosition(TitleAccess, PlayList.CurrTrack, Position.CDPlayed);
            CDPrfReleaseAccess(TitleAccess);
            }
        bResult = StartWatchdog(hwnd);        
        CDOptFatalError(bResult, hwnd, ERR_WATCHDOG);

        SetWaitPointer(FALSE);
        return NULL;

      case CD_INSERTED :
        StopWatchdog(hwnd);

        bResult = CDGetContents(DevID, &Contents);
        CDOptError(bResult, hwnd, ERR_DEVICE_CONTENTS);
 
        if ( bResult && Contents.AudioCDInserted ) {
            bResult = CDSetAdviseRate(DevID, hwnd, TimeRefreshRate * 3);
            CDOptFatalError(bResult, hwnd, ERR_DEVICE_ADVISE);
            AdviseOn = TRUE;

            if ( DriverInfo.CanLock && LockWhilePlay ) {
                bResult = CDLock(DevID);
                }

            /*
            bResult = CDSetConnector(DevID, MCI_AMP_STREAM_CONNECTOR, OutputExtAmp);
            CDOptError(bResult, hwnd, ERR_DEVICE_CONNECTOR);
            */
 
            TitleAccess = CDPrfQueryAccess(&Contents);

            if ( ! CDPrfQueryPlayList(TitleAccess, &PlayList) )
                CDGetDefPlayList(&Contents, &PlayList);

            bResult = CDPrfQueryCDTitle(TitleAccess, Buffer, sizeof(Buffer));
            if ( ! bResult ) {
                SetDlgTitle(hwnd, CDUntitled);
                }
            else {
                SetDlgTitle(hwnd, Buffer);
                }

            WinSendMsg(sysSubmenu, MM_SETITEMATTR, MPFROM2SHORT(ID_CONTROL_MENU, FALSE),
                MPFROM2SHORT(MIA_DISABLED, 0));

            ResetVolume(DevID);

            EnablePosition(TRUE);
            EnableTrackSet(TRUE);
            EnableTitleSelect(TRUE);
            EnableTimeSlider(TRUE);
            EnablePlayControls(TRUE);

            SetupTrackSet(&PlayList);
            SetupTitleSelect(&PlayList, TitleAccess);
            SetupTimeSlider(&PlayList);

            WinSendMsg(hwnd, CD_STOP, NULL, NULL);

            if ( CDPrfQueryPosition(TitleAccess, &NextTrack, &NextPosition) )
                WinSendMsg(hwnd, CD_SEEK,  MPFROMLONG(NextTrack),
                    MPFROMLONG(NextPosition));

            bResult = CDSetConnector(DevID, MCI_HEADPHONES_CONNECTOR, OutputHeadphones);
            if ( OutputHeadphones && ! bResult ) {
                CDError(hwnd, ERR_DEVICE_CONNECTOR);
                if ( ! OutputSoundcard ) {
                    bResult = CDSetConnector(DevID, MCI_CD_STREAM_CONNECTOR, TRUE);
                    CDOptError(bResult, hwnd, ERR_DEVICE_CONNECTOR);
                    }
                }

            bResult = CDSetConnector(DevID, MCI_CD_STREAM_CONNECTOR, OutputSoundcard);
            if ( OutputSoundcard &&! bResult ) {
                CDError(hwnd, ERR_DEVICE_CONNECTOR);
                if ( ! OutputHeadphones ) {
                    bResult = CDSetConnector(DevID, MCI_HEADPHONES_CONNECTOR, TRUE);
                    CDOptError(bResult, hwnd, ERR_DEVICE_CONNECTOR);
                    }
                }

            if ( AutoStart ) {
                WinPostMsg(hwnd, WM_COMMAND,
                    MPFROMSHORT(ID_PLAY), MPFROM2SHORT(CMDSRC_OTHER, FALSE));
                }
            }
        else {
            SetDlgTitle(hwnd, CDNoAudio);

            EnablePosition(FALSE);
            EnableTrackSet(FALSE);
            EnableTitleSelect(FALSE);
            EnableTimeSlider(FALSE);
            EnablePlayControls(FALSE);

            Status = CDSTATUS_NO_AUDIO_CD;
            }

        if ( DriverInfo.CanEject ) {
            // WinEnableWindow(hwndEject, TRUE);
            EnableEject(TRUE);
            EnableMenuItemControl(TRUE);
            }

        bResult = StartWatchdog(hwnd);
        CDOptFatalError(bResult, hwnd, ERR_WATCHDOG);
        SetWaitPointer(FALSE);
        return 0;

      case CD_STOP :
        bResult = CDStop(DevID);
        CDOptFatalError(bResult, hwnd, ERR_DEVICE_STOP);
        PlayList.CurrTrack = 0;
        // bResult = CDSeek(DevID, hwnd, Contents.Track[PlayList.TrackToPlay[0]-1].Start);
        bResult = CDGetPosition(DevID, Contents.Track[PlayList.Track[0].ToPlay-1].Start, 
            &Contents, &PlayList, &Position); 
        WinSendMsg(hwnd, CD_POSITION, NULL, NULL);
        Status = CDSTATUS_STOPPED;
        return 0;

      case CD_POSITION :
        bResult = PosPosition(&Position);
        bResult = PosTrackSet(&PlayList);
        bResult = PosTitleSelect(&PlayList);
        bResult = PosTimeSlider(&Position, &PlayList);
        return NULL;

      case CD_STARTPLAY :
        PlayLength =
            Contents.Track[PlayList.Track[PlayList.CurrTrack].ToPlay-1].Length -
            Position.TrackPlayed;

        NextTrack = PlayList.CurrTrack + 1;

        while ( NextTrack < PlayList.TotalTracks &&
                PlayList.Track[NextTrack].ToPlay == PlayList.Track[NextTrack-1].ToPlay + 1 ) {
            PlayLength += Contents.Track[PlayList.Track[NextTrack].ToPlay-1].Length;
            NextTrack++;
            }

        bResult = CDPlay(DevID, hwnd,
            Contents.Track[PlayList.Track[PlayList.CurrTrack].ToPlay-1].Start +
                Position.TrackPlayed, PlayLength, (USHORT)NextTrack);

        Status = CDSTATUS_PLAYING;
        if ( ! bResult ) {
            CDError(hwnd, ERR_DEVICE_PLAY);
            WinPostMsg(hwnd, WM_COMMAND,
                MPFROMSHORT(ID_STOP), MPFROM2SHORT(CMDSRC_OTHER, FALSE));
            }
        return 0;

      case MM_MCINOTIFY :
        if ( SHORT1FROMMP(mp2) == DevID ) {
            if ( SHORT2FROMMP(mp2) == MCI_PLAY ) {
                switch ( SHORT1FROMMP(mp1) ) {
                  case MCI_NOTIFY_SUCCESSFUL :
                    PlayList.CurrTrack = SHORT2FROMMP(mp1);
                    if ( PlayList.CurrTrack == PlayList.TotalTracks ) {
                        if ( AutoRepeat ) {
                            PlayList.CurrTrack = 0;
                            // bResult = CDSeek(DevID, hwnd, Contents.Track[PlayList.TrackToPlay[0]-1].Start);
                            bResult = CDGetPosition(DevID, 
                                Contents.Track[PlayList.Track[0].ToPlay-1].Start, 
                                &Contents, &PlayList, &Position);
                            WinSendMsg(hwnd, CD_POSITION, NULL, NULL);
                            WinSendMsg(hwnd, CD_STARTPLAY, NULL, NULL);
                            } 
                        else {
                            if ( AnimationOn )
                                WinSendMsg(hwndPlay, GBM_ANIMATE, MPFROMLONG(FALSE),
                                    MPFROMLONG(FALSE));
                            WinSendMsg(hwndPlay, GBM_SETSTATE, MPFROMSHORT(GB_UP),
                                MPFROMLONG(TRUE));
                            WinSendMsg(hwnd, CD_STOP, NULL, NULL);
                            }
                        }
                    else {
                        PlayLength =
                            Contents.Track[PlayList.Track[PlayList.CurrTrack].ToPlay-1].Length;

                        NextTrack = PlayList.CurrTrack + 1;
 
                        while ( NextTrack < PlayList.TotalTracks &&
                                PlayList.Track[NextTrack].ToPlay ==
                                    PlayList.Track[NextTrack-1].ToPlay + 1 ) {
                            PlayLength +=
                                Contents.Track[PlayList.Track[NextTrack].ToPlay-1].Length;
                            NextTrack++;
                            }

                        bResult = CDGetPosition(DevID,
                            Contents.Track[PlayList.Track[PlayList.CurrTrack].ToPlay-1].Start,
                            &Contents, &PlayList, &Position);
                        WinSendMsg(hwnd, CD_POSITION, NULL, NULL);

                        bResult = CDPlay(DevID, hwnd,
                            Contents.Track[PlayList.Track[PlayList.CurrTrack].ToPlay-1].Start,
                            PlayLength, (USHORT)NextTrack);
                        if ( ! bResult ) {
                            CDError(hwnd, ERR_DEVICE_PLAY);
                            WinPostMsg(hwnd, WM_COMMAND,
                                MPFROMSHORT(ID_STOP), MPFROM2SHORT(CMDSRC_OTHER, FALSE));
                            }
                        }
                    break;

                  case MCI_NOTIFY_SUPERSEDED :
                  case MCI_NOTIFY_ABORTED :
                    break;
                  default :
                    break;
                    }
                }
            }
        return NULL;

      case MM_MCIPASSDEVICE :
        if ( DevID == SHORT1FROMMP(mp1) ) {
            if ( SHORT1FROMMP(mp2) == MCI_GAINING_USE ) {
                }
            else if ( SHORT1FROMMP(mp2) == MCI_LOSING_USE ) {
                }
            }
        return NULL;

      case MM_MCIPOSITIONCHANGE :
        if ( DevID == SHORT2FROMMP(mp1) ) {
            bResult = GetPositionExt(DevID, LONGFROMMP(mp2),
                &Contents, &PlayList, &Position);

            WinSendMsg(hwnd, CD_POSITION, NULL, NULL);
            }
        return NULL;

      case CD_SEEK :
        if ( Status >= CDSTATUS_STOPPED ) {
            while ( WinPeekMsg(hab, &TmpMsg, hwnd, MM_MCIPOSITIONCHANGE,
                        MM_MCIPOSITIONCHANGE, PM_REMOVE) );

            PlayList.CurrTrack = LONGFROMMP(mp1);
            bResult = CDGetPosition(DevID,
                Contents.Track[PlayList.Track[PlayList.CurrTrack].ToPlay-1].Start +
                (LONGFROMMP(mp2) - PlayList.Track[PlayList.CurrTrack].StartInPlayList),
                &Contents, &PlayList, &Position);

            /*
            if ( Position.TrackPlayed > 3000*10 ) {
                bResult = CDGetPosition(DevID,
                    Contents.Track[PlayList.Track[PlayList.CurrTrack].ToPlay-1].Start +
                    (LONGFROMMP(mp2) - PlayList.Track[PlayList.CurrTrack].StartInPlayList),
                    &Contents, &PlayList, &Position);

                printf("Hello, World!");
                }
            */

            /*
            bResult = CDSeek(DevID, hwnd,
                Contents.Track[PlayList.TrackToPlay[PlayList.CurrTrack]-1].Start +
                (LONGFROMMP(mp2) - PlayList.StartInPlayList[PlayList.CurrTrack]));
            */

            switch ( Status ) { 
              case CDSTATUS_PLAYING :
                bResult = CDPause(DevID);
                WinSendMsg(hwnd, CD_POSITION, NULL, NULL);
                WinSendMsg(hwnd, CD_STARTPLAY, NULL, NULL);
                break;

              case CDSTATUS_STOPPED :
                WinSendMsg(hwnd, CD_POSITION, NULL, NULL);
                break;

              case CDSTATUS_PAUSED :
                SeekInPause = TRUE;
                WinSendMsg(hwnd, CD_POSITION, NULL, NULL);
                break;
                }
            }
        return NULL;

      case CD_TITLECHANGED :
        if ( Status >= CDSTATUS_STOPPED &&
            ! strcmp(PVOIDFROMMP(mp1), TitleAccess) ) {
            CDTITLE_CHANGE *Change = (CDTITLE_CHANGE *)PVOIDFROMMP(mp2);

            if ( Change->Track > 0 ) {
                if  ( Status == CDSTATUS_PLAYING )
                    bResult = GetPositionExt(DevID, -1, &Contents, &PlayList, &Position);
                bResult = ChangeTitle(&PlayList, Change->Track, Change->Title);
                }
            else {
                if ( Change->Title == NULL ) {
                    SetDlgTitle(hwnd, CDUntitled);
                    }
                else {
                    SetDlgTitle(hwnd, Change->Title);
                    }
                }

            return MRFROMLONG(TRUE);
            }
        return NULL;

      case CD_PLAYLISTCHANGED :
        if ( Status >= CDSTATUS_STOPPED &&
            ! strcmp(PVOIDFROMMP(mp1), TitleAccess) ) {
            memcpy(&PlayList, PVOIDFROMMP(mp2), sizeof(CDAUDIO_PLAYLIST));

            switch ( Status ) {
              case CDSTATUS_PAUSED :
                WinSendMsg(hwndPause, GBM_SETSTATE, MPFROMSHORT(GB_UP),
                    MPFROMLONG(TRUE));
              case CDSTATUS_PLAYING :
                if ( AnimationOn )
                    WinSendMsg(hwndPlay, GBM_ANIMATE, MPFROMLONG(FALSE),
                        MPFROMLONG(FALSE));
                WinSendMsg(hwndPlay, GBM_SETSTATE, MPFROMSHORT(GB_UP),
                    MPFROMLONG(TRUE));
                break;
                }

            WinSendMsg(hwnd, CD_STOP, NULL, NULL);
            SetupTrackSet(&PlayList);
            SetupTitleSelect(&PlayList, TitleAccess);
            SetupTimeSlider(&PlayList); 
            }
        return NULL;

      case CD_INFOCHANGED :
        return NULL;

      case CD_OPTIONCHANGED :
        switch ( LONGFROMMP(mp1) ) {
          case CDOPT_TIMEFORMAT :
            TimeFormat = LONGFROMMP(mp2);
            if ( Status >= CDSTATUS_STOPPED ) {
                PosPosition(&Position);
                } 
            else {
                EnablePosition(FALSE);
                }

            if ( TitleEditorInProcess )
                WinSendMsg(TitleEditorDlg, CTL_TIMEFORMAT, NULL, NULL);

            if ( ProgramEditorInProcess )
                WinSendMsg(ProgramEditorDlg, CTL_TIMEFORMAT, NULL, NULL);

            if ( InfoInProcess )
                WinSendMsg(InfoDlg, CTL_TIMEFORMAT, NULL, NULL);

            break;

          case CDOPT_TIMESEPARATOR :
            TimeSeparator = LONGFROMMP(mp2);
            if ( Status >= CDSTATUS_STOPPED ) {
                PosPosition(&Position);
                }
            else {
                EnablePosition(FALSE);
                }

            if ( TitleEditorInProcess )
                WinSendMsg(TitleEditorDlg, CTL_TIMEFORMAT, NULL, NULL);

            if ( ProgramEditorInProcess )
                WinSendMsg(ProgramEditorDlg, CTL_TIMEFORMAT, NULL, NULL);

            if ( InfoInProcess )
                WinSendMsg(InfoDlg, CTL_TIMEFORMAT, NULL, NULL);

            break;

          case CDOPT_TIMEFREQ :
            TimeRefreshRate = LONGFROMMP(mp2);
            if ( AdviseOn ) {
                bResult = CDSetAdviseRate(DevID, hwnd, TimeRefreshRate * 3);
                CDOptFatalError(bResult, hwnd, ERR_DEVICE_ADVISE);
                }
            break;

          case CDOPT_ANIMATION :
            if ( Status == CDSTATUS_PLAYING ) {
                if ( AnimationOn && ! LONGFROMMP(mp2)) {
                    WinSendMsg(hwndPlay, GBM_ANIMATE, MPFROMLONG(FALSE),
                        MPFROMLONG(FALSE));
                    WinSendMsg(hwndPlay, GBM_SETSTATE, MPFROMSHORT(GB_DOWN),
                        MPFROMLONG(TRUE));
                    }
                else if ( ! AnimationOn && LONGFROMMP(mp2)) {
                    WinSendMsg(hwndPlay, GBM_ANIMATE, MPFROMLONG(TRUE),
                        MPFROMLONG(TRUE));
                    WinSendMsg(hwndPlay, GBM_SETSTATE, MPFROMSHORT(GB_DOWN),
                        MPFROMLONG(TRUE));
                    }
                }
            else if ( Status == CDSTATUS_PAUSED ) {
                if ( AnimationOn && ! LONGFROMMP(mp2)) {
                    WinSendMsg(hwndPlay, GBM_ANIMATE, MPFROMLONG(FALSE),
                        MPFROMLONG(FALSE));
                    WinSendMsg(hwndPlay, GBM_SETSTATE, MPFROMSHORT(GB_DOWN),
                        MPFROMLONG(TRUE));
                    }
                }

            AnimationOn = LONGFROMMP(mp2);
            break;

          case CDOPT_ANIMATIONFREQ :
            AnimationRate = LONGFROMMP(mp2);
            WinSendMsg(hwndPlay, GBM_SETANIMATIONRATE, MPFROMLONG(AnimationRate), NULL);
            break;

          case CDOPT_LISTBOXANIMATION :
            ListBoxAnimation = LONGFROMMP(mp2);
            break;

          case CDOPT_AUTOREPEAT :
            if ( AutoRepeat != LONGFROMMP(mp2) ) {
                AutoRepeat = LONGFROMMP(mp2);
                WinSendMsg(hwndRepeat, GBM_SETSTATE, MPFROMSHORT(GB_HILITE),
                    MPFROMLONG(TRUE));
 
                WinSendMsg(hwndRepeat, GBM_SETSTATE, 
                    MPFROMSHORT(AutoRepeat ? GB_DOWN : GB_UP),
                    MPFROMLONG(TRUE));
                }
            break;

          case CDOPT_AUTOSTART :
            AutoStart = LONGFROMMP(mp2);
            break;

          case CDOPT_BACKWARDTHRESHOLD :
            BackwardThreshold = LONGFROMMP(mp2);
            break;

          case CDOPT_SAVEWINDOWPOS :
            SaveWindowPos = LONGFROMMP(mp2);
            break;

          case CDOPT_SAVEVOLUME :
            SaveVolume = LONGFROMMP(mp2);
            break;

          case CDOPT_SAVEPOSITION :
            SavePosition = LONGFROMMP(mp2);
            break;

          case CDOPT_SAVEMARKERS :
            SaveMarkers = LONGFROMMP(mp2);
            break;

          case CDOPT_OUTPUTHEADPHONES :
            if ( ! LONGFROMMP(mp2) && ! OutputSoundcard && ! OutputExtAmp )
                return MRFROMLONG(FALSE);
 
            if ( Status >= CDSTATUS_STOPPED ) {
                bResult = CDSetConnector(DevID, MCI_HEADPHONES_CONNECTOR, LONGFROMMP(mp2));
                if ( ! bResult ) {
                    CDError(hwnd, ERR_DEVICE_CONNECTOR);
                    return MRFROMLONG(FALSE);
                    }
                }
            OutputHeadphones = LONGFROMMP(mp2);
            break;

          case CDOPT_OUTPUTSOUNDCARD :
            if ( ! LONGFROMMP(mp2) && ! OutputHeadphones && ! OutputExtAmp )
                return MRFROMLONG(FALSE);

            if ( Status >= CDSTATUS_STOPPED ) {
                bResult = CDSetConnector(DevID, MCI_CD_STREAM_CONNECTOR, LONGFROMMP(mp2));
                if ( ! bResult ) {
                    CDError(hwnd, ERR_DEVICE_CONNECTOR);
                    return MRFROMLONG(FALSE);
                    }
                }
            OutputSoundcard = LONGFROMMP(mp2);
            break;

          case CDOPT_OUTPUTEXTAMP :
            if ( ! LONGFROMMP(mp2) && ! OutputSoundcard && ! OutputHeadphones )
                return MRFROMLONG(FALSE);

            /*
            bResult = CDSetConnector(DevID, MCI_AMP_STREAM_CONNECTOR, LONGFROMMP(mp2));
            if ( ! bResult ) {
                CDError(hwnd, ERR_DEVICE_CONNECTOR);
                return MRFROMLONG(FALSE);
                }
            OutputExtAmp = LONGFROMMP(mp2);
            */
            break;

          case CDOPT_LOCKWHILEPLAY :
            if ( DriverInfo.CanLock ) {
                if ( LockWhilePlay && ! LONGFROMMP(mp2) ) {
                    bResult = CDUnlock(DevID);
                    }
                else if ( ! LockWhilePlay && LONGFROMMP(mp2) ) {
                    bResult = CDLock(DevID);
                    }
                }
            else if ( LONGFROMMP(mp2) ) {
                return MRFROMLONG(FALSE);
                }

            LockWhilePlay = LONGFROMMP(mp2);
            break;

          case CDOPT_DEVICENAME :
            strcpy(DeviceName, (PSZ)PVOIDFROMMP(mp2));
            WinSendMsg(hwnd, CD_NEWDEVICE, mp2, NULL);
            break;
            }

        return MRFROMLONG(TRUE);

      case WM_BUTTON2CLICK :
        return PopupFromClick(hwnd, mp1, mp2);
 
      case WM_BUTTON3CLICK :
        if ( 0 == (SHORT2FROMMP(mp2) & (KC_CTRL | KC_ALT | KC_SHIFT)) ) {
            switch ( Status ) {
              case CDSTATUS_PLAYING :
                WinSendMsg(hwnd, WM_COMMAND,
                    MPFROMSHORT(ID_PAUSE), MPFROM2SHORT(CMDSRC_OTHER, FALSE));
                break;
 
              case CDSTATUS_PAUSED :
              case CDSTATUS_STOPPED :
                WinSendMsg(hwnd, WM_COMMAND,
                    MPFROMSHORT(ID_PLAY), MPFROM2SHORT(CMDSRC_OTHER, FALSE));
                break;
 
              default :
                WinAlarm(HWND_DESKTOP, WA_ERROR);
                break;
                }
            return MPFROMLONG(TRUE);
            }
        else if ( KC_CTRL == (SHORT2FROMMP(mp2) & (KC_CTRL | KC_ALT | KC_SHIFT)) ) {
            if ( Status > CDSTATUS_STOPPED )
                WinSendMsg(hwnd, WM_COMMAND,
                    MPFROMSHORT(ID_STOP), MPFROM2SHORT(CMDSRC_OTHER, FALSE));

            return MPFROMLONG(TRUE);
            }

        return NULL;

      case WM_COMMAND :
        switch ( SHORT1FROMMP(mp1) ) {
          case ID_CHANGE_TITLES :
            if ( Status >= CDSTATUS_STOPPED )
                return CmdChangeTitles(&Contents, TitleAccess);
            else
                return CmdChangeTitles(NULL, NULL);

          case ID_PROGRAM_TITLES :
            if ( Status >= CDSTATUS_STOPPED ) {
                return CmdProgramPlayList(&Contents, TitleAccess);
                }
            else {
                WinAlarm(HWND_DESKTOP, WA_ERROR);
                return NULL;
                }

          case ID_OPTIONS :
            return CmdOptions();

          case ID_INFO :
            if ( Status >= CDSTATUS_STOPPED ) {
                return CmdInfo(&Contents, TitleAccess);
                }
            else {
                WinAlarm(HWND_DESKTOP, WA_ERROR);
                return NULL;
                }

          case ID_KSEEKM75 :
          case ID_KSEEKM15 :
          case ID_KSEEKM1 :
          case ID_KSEEKM10 :
          case ID_KSEEKM60 :
          case ID_KSEEKM600 :
            switch ( SHORT1FROMMP(mp1) ) {
              case ID_KSEEKM75 :
                NextPosition = 3000 / 75;
                break;

              case ID_KSEEKM15 :
                NextPosition = 3000 / 5;
                break;

              case ID_KSEEKM1 :
                NextPosition = 3000;
                break;

              case ID_KSEEKM10 :
                NextPosition = 3000 * 10;
                break;

              case ID_KSEEKM60 :
                NextPosition = 3000 * 60;
                break;

              case ID_KSEEKM600 :
                NextPosition = 3000 * 600;
                break;
                }

            if ( Status == CDSTATUS_PLAYING ) {
                bResult = GetPositionExt(DevID, -1, &Contents, &PlayList, &Position);
                }

            if ( Position.CDPlayed < NextPosition ) {
                NextPosition = Position.CDPlayed + PlayList.TotalLength - NextPosition;
                NextTrack = PlayList.TotalTracks - 1;
                }
            else {
                NextPosition = Position.CDPlayed - NextPosition;
                NextTrack = PlayList.CurrTrack;
                }

            while ( NextPosition < PlayList.Track[NextTrack].StartInPlayList )
                NextTrack--;

            WinSendMsg(hwnd, CD_SEEK,  MPFROMLONG(NextTrack), MPFROMLONG(NextPosition));
            return NULL;

          case ID_KSEEKP75 :
          case ID_KSEEKP15 :
          case ID_KSEEKP1 :
          case ID_KSEEKP10 :
          case ID_KSEEKP60 :
          case ID_KSEEKP600 :
            switch ( SHORT1FROMMP(mp1) ) {
              case ID_KSEEKP75 :
                NextPosition = 3000 / 75;
                break;

              case ID_KSEEKP15 :
                NextPosition = 3000 / 5;
                break;

              case ID_KSEEKP1 :
                NextPosition = 3000;
                break;

              case ID_KSEEKP10 :
                NextPosition = 3000 * 10;
                break;

              case ID_KSEEKP60 :
                NextPosition = 3000 * 60;
                break;

              case ID_KSEEKP600 :
                NextPosition = 3000 * 600;
                break;
                }

            if ( Status == CDSTATUS_PLAYING ) {
                bResult = GetPositionExt(DevID, -1, &Contents, &PlayList, &Position);
                }

            if ( Position.CDPlayed + NextPosition >= PlayList.TotalLength ) {
                NextPosition += Position.CDPlayed - PlayList.TotalLength;
                NextTrack = 0;
                }
            else {
                NextPosition += Position.CDPlayed;
                NextTrack = PlayList.CurrTrack;
                }

            while ( NextPosition >= 
                        PlayList.Track[NextTrack].StartInPlayList +
                        Contents.Track[PlayList.Track[NextTrack].ToPlay-1].Length )
                NextTrack++;

            WinSendMsg(hwnd, CD_SEEK,  MPFROMLONG(NextTrack), MPFROMLONG(NextPosition));
            return NULL;

          case ID_BACKWARD :
            if ( Status < CDSTATUS_STOPPED ) {
                WinAlarm(HWND_DESKTOP, WA_ERROR);
                return NULL;
                }

            if ( Status == CDSTATUS_PLAYING ) {
                bResult = GetPositionExt(DevID, -1, &Contents, &PlayList, &Position);
                }
 
            /*
            if ( Position.TrackPlayed > 3000*10 ) {
                printf("Hello, World!");
                }
            */

            if ( Position.TrackPlayed <= BackwardThreshold*3000 ) {
                if ( PlayList.CurrTrack == 0 )
                    NextTrack = PlayList.TotalTracks - 1;
                else
                    NextTrack = PlayList.CurrTrack - 1;
                }
            else {
                NextTrack = PlayList.CurrTrack;
                }

            NextPosition = PlayList.Track[NextTrack].StartInPlayList;
            WinSendMsg(hwnd, CD_SEEK,  MPFROMLONG(NextTrack), MPFROMLONG(NextPosition));

            return NULL;

          case ID_FORWARD :
            if ( Status < CDSTATUS_STOPPED ) {
                WinAlarm(HWND_DESKTOP, WA_ERROR);
                return NULL;
                }

            if ( Status == CDSTATUS_PLAYING ) {
                bResult = GetPositionExt(DevID, -1, &Contents, &PlayList, &Position);
                }

            NextTrack = PlayList.CurrTrack + 1;
            if ( NextTrack >= PlayList.TotalTracks )
                NextTrack = 0;

            NextPosition = PlayList.Track[NextTrack].StartInPlayList;
            WinSendMsg(hwnd, CD_SEEK,  MPFROMLONG(NextTrack), MPFROMLONG(NextPosition));
            return NULL;

          case ID_PLAY :
            switch ( Status ) {
              case CDSTATUS_NO_DEVICE :
              case CDSTATUS_NO_CD :
              case CDSTATUS_NO_AUDIO_CD :
                WinAlarm(HWND_DESKTOP, WA_ERROR);
                return NULL;
                break;

              case CDSTATUS_PLAYING :
                break;

              case CDSTATUS_STOPPED :
                if ( AnimationOn )
                    WinSendMsg(hwndPlay, GBM_ANIMATE, MPFROMLONG(TRUE),
                        MPFROMLONG(TRUE));
                WinSendMsg(hwndPlay, GBM_SETSTATE, MPFROMSHORT(GB_DOWN),
                    MPFROMLONG(TRUE));
                WinSendMsg(hwnd, CD_STARTPLAY, NULL, NULL);
                break;

              case CDSTATUS_PAUSED :
                if ( AnimationOn )
                    WinSendMsg(hwndPlay, GBM_ANIMATE, MPFROMLONG(TRUE),
                        MPFROMLONG(TRUE));
                WinSendMsg(hwndPause, GBM_SETSTATE, MPFROMSHORT(GB_UP),
                    MPFROMLONG(TRUE));
                if ( SeekInPause ) {
                    WinSendMsg(hwnd, CD_STARTPLAY, NULL, NULL);
                    }
                else {
                    bResult = CDResume(DevID);
                    Status = CDSTATUS_PLAYING;
                    if ( ! bResult ) {
                        CDError(hwnd, ERR_DEVICE_RESUME);
                        WinPostMsg(hwnd, WM_COMMAND,
                            MPFROMSHORT(ID_STOP), MPFROM2SHORT(CMDSRC_OTHER, FALSE));
                        }
                    }
                break;
                }
            return NULL;

          case ID_PAUSE :
            switch ( Status ) {
              case CDSTATUS_NO_DEVICE :
              case CDSTATUS_NO_CD :
              case CDSTATUS_NO_AUDIO_CD :
                WinAlarm(HWND_DESKTOP, WA_ERROR);
                return NULL;

              case CDSTATUS_STOPPED :
                if ( SHORT1FROMMP(mp2) != CMDSRC_PUSHBUTTON ) {
                    WinSendMsg(hwndPause, GBM_SETSTATE, MPFROMSHORT(GB_UP),
                        MPFROMLONG(TRUE));
                    }

                break;

              case CDSTATUS_PLAYING :
                if ( AnimationOn )
                    WinSendMsg(hwndPlay, GBM_ANIMATE, MPFROMLONG(FALSE),
                        MPFROMLONG(TRUE));
                WinSendMsg(hwndPause, GBM_SETSTATE, MPFROMSHORT(GB_DOWN),
                    MPFROMLONG(TRUE));
                bResult = CDPause(DevID);
                SeekInPause = FALSE;
                if ( ! bResult ) {
                    Status = CDSTATUS_PAUSED;
                    CDError(hwnd, ERR_DEVICE_PAUSE);
                    WinPostMsg(hwnd, WM_COMMAND,
                        MPFROMSHORT(ID_STOP), MPFROM2SHORT(CMDSRC_OTHER, FALSE));
                    }
                bResult = GetPositionExt(DevID, -1, &Contents, &PlayList, &Position);
                if ( ! bResult ) {
                    Status = CDSTATUS_PAUSED;
                    CDError(hwnd, ERR_DEVICE_POSITION);
                    WinPostMsg(hwnd, WM_COMMAND,
                        MPFROMSHORT(ID_STOP), MPFROM2SHORT(CMDSRC_OTHER, FALSE));
                    }
                WinSendMsg(hwnd, CD_POSITION, NULL, NULL);
                Status = CDSTATUS_PAUSED;
                break;

              case CDSTATUS_PAUSED :
                if ( AnimationOn )
                    WinSendMsg(hwndPlay, GBM_ANIMATE, MPFROMLONG(TRUE),
                        MPFROMLONG(TRUE));
                WinSendMsg(hwndPause, GBM_SETSTATE, MPFROMSHORT(GB_UP),
                    MPFROMLONG(TRUE));
                if ( SeekInPause ) {
                    WinSendMsg(hwnd, CD_STARTPLAY, NULL, NULL);
                    }
                else {
                    bResult = CDResume(DevID);
                    Status = CDSTATUS_PLAYING;
                    if ( ! bResult ) {
                        CDError(hwnd, ERR_DEVICE_RESUME);
                        WinPostMsg(hwnd, WM_COMMAND,
                            MPFROMSHORT(ID_STOP), MPFROM2SHORT(CMDSRC_OTHER, FALSE));
                        }
                    }
                break;
                }
            return NULL;

          case ID_STOP :
            switch ( Status ) {
              case CDSTATUS_NO_DEVICE :
              case CDSTATUS_NO_CD :
              case CDSTATUS_NO_AUDIO_CD :
                WinAlarm(HWND_DESKTOP, WA_ERROR);
                return NULL;

              case CDSTATUS_STOPPED :
                break;

              case CDSTATUS_PAUSED :
                WinSendMsg(hwndPause, GBM_SETSTATE, MPFROMSHORT(GB_UP),
                    MPFROMLONG(TRUE));
              case CDSTATUS_PLAYING :
                if ( AnimationOn )
                    WinSendMsg(hwndPlay, GBM_ANIMATE, MPFROMLONG(FALSE),
                        MPFROMLONG(FALSE));
                WinSendMsg(hwndPlay, GBM_SETSTATE, MPFROMSHORT(GB_UP),
                    MPFROMLONG(TRUE));
                WinSendMsg(hwnd, CD_STOP, NULL, NULL);
                break;
                }

            return NULL;

          case ID_EJECT :
            switch ( Status ) {
              case CDSTATUS_NO_DEVICE :
              case CDSTATUS_NO_CD :
                WinAlarm(HWND_DESKTOP, WA_ERROR);
                return NULL;

              case CDSTATUS_PAUSED :
                WinSendMsg(hwndPause, GBM_SETSTATE, MPFROMSHORT(GB_UP),
                    MPFROMLONG(TRUE));

              case CDSTATUS_PLAYING :
                if ( AnimationOn )
                    WinSendMsg(hwndPlay, GBM_ANIMATE, MPFROMLONG(FALSE),
                        MPFROMLONG(FALSE));
                WinSendMsg(hwndPlay, GBM_SETSTATE, MPFROMSHORT(GB_UP),
                    MPFROMLONG(TRUE));

              case CDSTATUS_STOPPED :
                if ( DriverInfo.CanLock && LockWhilePlay ) {
                    bResult = CDUnlock(DevID);
                    }

              case CDSTATUS_NO_AUDIO_CD :
                bResult = CDEjectImm(DevID);
                CDOptError(bResult, hwnd, ERR_DEVICE_EJECT);
                SetWaitPointer(TRUE);
                if ( Status != CDSTATUS_NO_AUDIO_CD) {
                    WinSendMsg(hwnd, CD_CLEANUP, NULL, NULL);
                    }
                WinSendMsg(hwnd, CD_REMOVED, NULL, NULL);
                }

            return NULL;

          case ID_REPEAT :
            if ( SHORT1FROMMP(mp2) != CMDSRC_PUSHBUTTON ) {
                WinSendMsg(hwndRepeat, GBM_SETSTATE, MPFROMSHORT(GB_HILITE),
                    MPFROMLONG(TRUE));
                }

            WinSendMsg(hwndRepeat, GBM_SETSTATE, MPFROMSHORT(GB_TOGGLE),
                MPFROMLONG(TRUE));
            return NULL;

          case ID_MUTE :
            if ( SHORT1FROMMP(mp2) != CMDSRC_PUSHBUTTON ) {
                WinSendMsg(hwndMute, GBM_SETSTATE, MPFROMSHORT(GB_HILITE),
                    MPFROMLONG(TRUE));
                }

            WinSendMsg(hwndMute, GBM_SETSTATE, MPFROMSHORT(GB_TOGGLE),
                MPFROMLONG(TRUE));
            return NULL;

          case ID_SETTRACK1:
          case ID_SETTRACK2:
          case ID_SETTRACK3:
          case ID_SETTRACK4:
          case ID_SETTRACK5:
          case ID_SETTRACK6:
          case ID_SETTRACK7:
          case ID_SETTRACK8:
          case ID_SETTRACK9:
          case ID_SETTRACK10:
          case ID_SETTRACK11:
          case ID_SETTRACK12:
            if ( Status < CDSTATUS_STOPPED ) {
                WinAlarm(HWND_DESKTOP, WA_ERROR);
                return NULL;
                }

            NextTrack = SHORT1FROMMP(mp1) - ID_SETTRACK1;

            if ( NextTrack < PlayList.TotalTracks ) {
                NextPosition = PlayList.Track[NextTrack].StartInPlayList;
                WinSendMsg(hwnd, CD_SEEK,  MPFROMLONG(NextTrack), MPFROMLONG(NextPosition));
                }
            else {
                WinAlarm(HWND_DESKTOP, WA_ERROR);
                }

            return NULL;

          case ID_HELPINDEX :
            if ( hwndMainHelp != NULL )
                WinSendMsg(hwndMainHelp, HM_HELP_INDEX, NULL, NULL);
            return NULL;

          case ID_HELPEXTENDED :
            if ( hwndMainHelp != NULL )
                WinSendMsg(hwndMainHelp, HM_EXT_HELP, NULL, NULL);
            return NULL;

          case ID_HELPONHELP :
            if ( hwndMainHelp != NULL )
                WinSendMsg(hwndMainHelp, HM_DISPLAY_HELP, NULL, NULL);
            return NULL;

          case ID_HELPKEYS :
            if ( hwndMainHelp != NULL )
                WinSendMsg(hwndMainHelp, HM_KEYS_HELP, NULL, NULL);
            return NULL;

          case ID_ABOUT :
            WinDlgBox(HWND_DESKTOP, hwnd, AboutDlgProc, NULLHANDLE, ID_DLG_ABOUT, NULL);
            return NULL;

          case ID_ENTERREG :
            if ( ! Registered ) {
                WinDlgBox(HWND_DESKTOP, hwnd, RegisterDlgProc, NULLHANDLE, ID_DLG_REG, NULL);
                if ( CDPrfQueryRegistered(&RegID, UserNameText) ) {
                    Registered = TRUE;
                    sprintf(RegIDText, "%8.8X", RegID);
                    WinMessageBox(HWND_DESKTOP, hwnd, RightRegText, ApplTitle, ID_MB_WRONGREG,
                        MB_OK | MB_INFORMATION | MB_SYSTEMMODAL | MB_MOVEABLE);
                    }
                else {
                    WinMessageBox(HWND_DESKTOP, hwnd, WrongRegText, ApplTitle, ID_MB_WRONGREG,
                        MB_OK | MB_INFORMATION | MB_SYSTEMMODAL | MB_MOVEABLE);
                    }
                }

            return NULL;

          default :
            return NULL;
            };
        return NULL;

      case HM_QUERY_KEYS_HELP :
        return MRFROMSHORT(PANEL_MW_KEYBOARD);

      case WM_VSCROLL :
        if ( SHORT1FROMMP(mp1) == ID_TRACKSET_SCROLLBAR ) {
            return TrackSetScroll(&PlayList, mp1, mp2);
            }
        return NULL;

      case WM_CONTROL :
        switch ( SHORT1FROMMP(mp1) ) {
          case ID_REPEAT :
            if ( SHORT2FROMMP(mp1) == GBN_BUTTONDOWN ) {
                AutoRepeat = TRUE;
                } 
            else if ( SHORT2FROMMP(mp1) == GBN_BUTTONUP ) {
                AutoRepeat = FALSE;
                } 
            return NULL;

          case ID_TRACKSET :
            return TrackSetControl(hwnd, &PlayList, mp1, mp2);

          case ID_TITLE_SELECT :
            return TitleSelectControl(hwnd, &PlayList, mp1, mp2);

          case ID_TIME_SLIDER :
            return TimeSliderControl(hwnd, &PlayList, &Contents, mp1, mp2);

          case ID_VOLUME_LEFT :
            return SetLeftVolume(DevID, mp1, mp2);

          case ID_VOLUME_RIGHT:
            return SetRightVolume(DevID, mp1, mp2);

          case ID_MUTE :
            return MuteVolume(DevID, mp1, mp2);

          case ID_CHANNEL_INDEPENDENT:
            return ChannelIndependent(mp1, mp2);

          case ID_CHANNEL_SWAP:
            return ChannelSwap(mp1, mp2);

          default:
            return 0;
            }

      case WM_CHAR :
        if ( (SHORT1FROMMP(mp1) & KC_VIRTUALKEY) ) {
            if ( SHORT2FROMMP(mp2) == VK_CTRL ) {
                return MRFROMLONG(TRUE);
                }
            else if ( SHORT2FROMMP(mp2) == VK_SHIFT ) {
                return MRFROMLONG(TRUE);
                }
            else if ( SHORT2FROMMP(mp2) == VK_ALT ) {
                return MRFROMLONG(TRUE);
                }
            else if ( SHORT2FROMMP(mp2) == VK_F10 &&
                      (SHORT1FROMMP(mp1) & (KC_KEYUP | KC_SHIFT)) && 
                      ! (SHORT1FROMMP(mp1) & (KC_ALT | KC_CTRL)) ) {
                return PopupFromKey(hwnd, mp1, mp2);
                }
            }
        return WinDefDlgProc(hwnd, msg, mp1, mp2);

      case WM_TRACKFRAME :
        if ( ! Minimized ) {
            TrackFrame = TRUE;
            bResult = CDSetAdviseOff(DevID, hwnd);
            AdviseOn = FALSE;
            }
        return WinDefDlgProc(hwnd, msg, mp1, mp2);

        /*
      case WM_BEGINDRAG :
        return WinDefDlgProc(hwnd, msg, mp1, mp2);

      case WM_ENDDRAG :
        return WinDefDlgProc(hwnd, msg, mp1, mp2);
        */

      case WM_ACTIVATE :
        if ( ModalProcessing && SHORT1FROMMP(mp1) ) {
            WinPostMsg(hwnd, INTERNAL_DELAYED_RESETFOCUS, MPFROMHWND(CurrModalOwner), NULL);
            }
        return WinDefDlgProc(hwnd, msg, mp1, mp2);

      case INTERNAL_DELAYED_RESETFOCUS :
        WinSetFocus(HWND_DESKTOP, HWNDFROMMP(mp1));
        return NULL;

      case WM_WINDOWPOSCHANGED :
        if ( InDestroy == TRUE )
            return WinDefDlgProc(hwnd, msg, mp1, mp2);

        PSwp = (PSWP)PVOIDFROMMP(mp1);
        if ( Initialized && SaveWindowPos && (PSwp->fl & (SWP_MOVE)) ) {
            if ( PSwp->fl & (SWP_MINIMIZE | SWP_HIDE) ) {
                CDPrfSaveWindowPos(CDWINDOW_MAIN, 0, 0, 0, 0, WINDOWSTATE_MINIMIZED);
                }
            else {
                CDPrfSaveWindowPos(CDWINDOW_MAIN, PSwp->x, PSwp->y, PSwp->cx, PSwp->cy,
                    WINDOWSTATE_NORMAL);
                }
            }

        if ( TrackFrame ) {
            TrackFrame = FALSE;
            if ( Status >= CDSTATUS_STOPPED ) {
                bResult = CDSetAdviseRate(DevID, hwnd, TimeRefreshRate * 3);
                AdviseOn = TRUE;
                if ( Status == CDSTATUS_PLAYING ) {
                    bResult = GetPositionExt(DevID, -1,
                        &Contents, &PlayList, &Position);

                    WinSendMsg(hwnd, CD_POSITION, NULL, NULL);
                    }
                }
            }

      // case WM_MINMAXFRAME :
        if ( ((PSWP)PVOIDFROMMP(mp1))->fl & (SWP_MINIMIZE | SWP_HIDE) ) {
            MRESULT Tmp;
            Minimized = TRUE;

            WinEnableWindowUpdate(hwnd, FALSE);
            if ( Status >= CDSTATUS_STOPPED ) {
                bResult = CDSetAdviseOff(DevID, hwnd);
                AdviseOn = FALSE;
                }

            WinShowWindow(hwndBackward, FALSE);
            Tmp = WinDefDlgProc(hwnd, msg, mp1, mp2);
            WinEnableWindowUpdate(hwnd, TRUE);
            WinShowWindow(hwnd, TRUE);
            return Tmp;
            }
        else if ( ((PSWP)PVOIDFROMMP(mp1))->fl & SWP_RESTORE ) {
            MRESULT Tmp;
            Minimized = FALSE;
            WinEnableWindowUpdate(hwnd, FALSE);
            if ( Status >= CDSTATUS_STOPPED ) {
                bResult = CDSetAdviseRate(DevID, hwnd, TimeRefreshRate * 3);
                AdviseOn = TRUE;
                if ( Status == CDSTATUS_PLAYING ) {
                    bResult = GetPositionExt(DevID, -1,
                        &Contents, &PlayList, &Position);

                    WinSendMsg(hwnd, CD_POSITION, NULL, NULL);
                    }
                }
            WinShowWindow(hwndBackward, TRUE);
            Tmp = WinDefDlgProc(hwnd, msg, mp1, mp2);
            WinEnableWindowUpdate(hwnd, TRUE);
            return Tmp;
            }
        else {
            return WinDefDlgProc(hwnd, msg, mp1, mp2);
            }

      case WM_CLOSE :
        if ( SaveWindowPos ) {
            // bResult = CDPrfSaveWindowPos(hwnd, CDWINDOW_MAIN);
            }

        WinPostMsg(hwnd, WM_QUIT, 0L, 0L);
        return NULL;

      case WM_DESTROY :
        if ( TitleAccess != NULL ) {
            if ( SavePosition )
                CDPrfSetPosition(TitleAccess, PlayList.CurrTrack, Position.CDPlayed);
            }

        if ( SaveWindowPos ) {
            static SWP Pos;
            if ( WinQueryWindowPos(hwndMainHelp, &Pos) )
                CDPrfSaveWindowPos(CDWINDOW_HELP, Pos.x, Pos.y, Pos.cx, Pos.cy,
                    WINDOWSTATE_NORMAL);
            }
        bResult = WinDestroyHelpInstance(hwndMainHelp);
        bResult = WinDestroyPointer(hptrIcon);
        if ( DlgAccelTable != NULLHANDLE ) {
            bResult = WinDestroyAccelTable(DlgAccelTable);
            }

        if ( DriverInfo.CanLock && LockWhilePlay ) {
            CDUnlock(DevID);
            }

        CDCloseDevice(DevID);
        bResult = CDPrfClose();
        return NULL;

      default:
        return WinDefDlgProc( hwnd, msg, mp1, mp2);
        }
}

MRESULT EXPENTRY AboutDlgProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2)
{
    static char Text1[96];
    static char Text2[64];

    switch ( msg ) {
      case WM_INITDLG:
        if ( Registered ) {
            strcpy(Text1, RegisteredForText);
            strcat(Text1, UserNameText);
            strcpy(Text2, UnderText);
            strcat(Text2, RegIDText);
            WinSetDlgItemText(hwnd, ID_REGUSER, Text1);
            WinSetDlgItemText(hwnd, ID_REGID, Text2);
            }
        return NULL;

      case WM_COMMAND :
        switch (COMMANDMSG(&msg)->cmd) {
          case DID_OK :
          case DID_CANCEL :
            WinDismissDlg(hwnd, TRUE);
            return NULL;
            }

      default :
        return WinDefDlgProc(hwnd, msg, mp1, mp2);
        }
}

MRESULT EXPENTRY RegisterDlgProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2)
{
    static char Text1[96];
    static char Text2[64];
    static ULONG Code;

    switch ( msg ) {
      case WM_INITDLG:
        return NULL;

      case WM_COMMAND :
        switch (COMMANDMSG(&msg)->cmd) {
          case DID_OK :
            WinQueryDlgItemText(hwnd, ID_RG_NAMEENTRY, sizeof(Text1), Text1);
            WinQueryDlgItemText(hwnd, ID_RG_CODEENTRY, sizeof(Text2), Text2);
            if ( sscanf(Text2, "%X", &Code) == 1 &&
                 CDPrfTestRegData(Code, Text1) ) {
                CDPrfSetRegData(Code, Text1);
                WinDismissDlg(hwnd, TRUE);
                }

          case DID_CANCEL :
            WinDismissDlg(hwnd, FALSE);
            return NULL;
            }

      default :
        return WinDefDlgProc(hwnd, msg, mp1, mp2);
        }
}

MRESULT EXPENTRY SettingsDlgProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2)
{
    static ULONG x, y, cx, cy, State;
    static HWND hwndNotebook;
    static ULONG PageID[6];
    static PDLGTEMPLATE DlgData[6];
    static HWND hwndDlgs[6];
    static USHORT Panel[6];
    BOOL bResult;
    APIRET aResult;
    ULONG i;
    MRESULT mResult;
    PSWP PSwp;
    static LONG CXScreen, CYScreen;

    switch ( msg ) {
      case WM_INITDLG :
        SettingsDlgInProcess = TRUE;
        SettingsDlgHidden = FALSE;

        bResult = WinAssociateHelpInstance(hwndMainHelp, hwnd);

        hwndNotebook = WinWindowFromID(hwnd, ID_NOTEBOOK);

        bResult = CDPrfLoadWindowPos(CDWINDOW_OPTIONS, &x, &y, &cx, &cy, &State);
        if ( bResult ) {
            WinSetWindowPos(hwnd, HWND_TOP, x, y, cx, cy, SWP_MOVE | SWP_SIZE);
            }

        PageID[0] = (ULONG)WinSendMsg(hwndNotebook, BKM_INSERTPAGE, NULL,
            MPFROM2SHORT(BKA_AUTOPAGESIZE | BKA_STATUSTEXTON | BKA_MAJOR, BKA_LAST));
        PageID[1] = (ULONG)WinSendMsg(hwndNotebook, BKM_INSERTPAGE, NULL,
            MPFROM2SHORT(BKA_AUTOPAGESIZE | BKA_STATUSTEXTON | BKA_MAJOR, BKA_LAST));
        PageID[2] = (ULONG)WinSendMsg(hwndNotebook, BKM_INSERTPAGE, NULL,
            MPFROM2SHORT(BKA_AUTOPAGESIZE | BKA_STATUSTEXTON | BKA_MAJOR, BKA_LAST));
        PageID[3] = (ULONG)WinSendMsg(hwndNotebook, BKM_INSERTPAGE, NULL,
            MPFROM2SHORT(BKA_AUTOPAGESIZE | BKA_STATUSTEXTON | BKA_MAJOR, BKA_LAST));
        PageID[4] = (ULONG)WinSendMsg(hwndNotebook, BKM_INSERTPAGE, NULL,
            MPFROM2SHORT(BKA_AUTOPAGESIZE | BKA_STATUSTEXTON | BKA_MAJOR, BKA_LAST));
        PageID[5] = (ULONG)WinSendMsg(hwndNotebook, BKM_INSERTPAGE, NULL,
            MPFROM2SHORT(BKA_AUTOPAGESIZE | BKA_STATUSTEXTON | BKA_MAJOR, BKA_LAST));

        CXScreen = WinQuerySysValue(HWND_DESKTOP, SV_CXSCREEN);
        CYScreen = WinQuerySysValue(HWND_DESKTOP, SV_CYSCREEN);
        bResult = (BOOL)WinSendMsg(hwndNotebook, BKM_SETDIMENSIONS,
            MPFROM2SHORT(CXScreen / 7, CYScreen / 20), MPFROMSHORT(BKA_MAJORTAB));
        bResult = (BOOL)WinSendMsg(hwndNotebook, BKM_SETDIMENSIONS,
            MPFROM2SHORT(0, 0), MPFROMSHORT(BKA_MINORTAB));
        bResult = (BOOL)WinSendMsg(hwndNotebook, BKM_SETDIMENSIONS,
            MPFROM2SHORT(CXScreen / 42, CYScreen / 32), MPFROMSHORT(BKA_PAGEBUTTON));
        bResult = (BOOL)WinSendMsg(hwndNotebook, BKM_SETNOTEBOOKCOLORS,
            MPFROMLONG(SYSCLR_DIALOGBACKGROUND), MPFROMSHORT(BKA_BACKGROUNDPAGECOLORINDEX));
        bResult = (BOOL)WinSendMsg(hwndNotebook, BKM_SETNOTEBOOKCOLORS,
            MPFROMLONG(SYSCLR_DIALOGBACKGROUND), MPFROMSHORT(BKA_BACKGROUNDMAJORCOLORINDEX));
        bResult = (BOOL)WinSendMsg(hwndNotebook, BKM_SETNOTEBOOKCOLORS,
            MPFROMLONG(SYSCLR_DIALOGBACKGROUND), MPFROMSHORT(BKA_BACKGROUNDMINORCOLORINDEX));

        bResult = (BOOL)WinSendMsg(hwndNotebook, BKM_SETTABTEXT,
            MPFROMLONG(PageID[0]), MPFROMP(TabDisplay));
        bResult = (BOOL)WinSendMsg(hwndNotebook, BKM_SETTABTEXT,
            MPFROMLONG(PageID[1]), MPFROMP(TabAnimation));
        bResult = (BOOL)WinSendMsg(hwndNotebook, BKM_SETTABTEXT,
            MPFROMLONG(PageID[2]), MPFROMP(TabOutput));
        bResult = (BOOL)WinSendMsg(hwndNotebook, BKM_SETTABTEXT,
            MPFROMLONG(PageID[3]), MPFROMP(TabSave));
        bResult = (BOOL)WinSendMsg(hwndNotebook, BKM_SETTABTEXT,
            MPFROMLONG(PageID[4]), MPFROMP(TabOutputDest));
        bResult = (BOOL)WinSendMsg(hwndNotebook, BKM_SETTABTEXT,
            MPFROMLONG(PageID[5]), MPFROMP(TabDevice));

        aResult = DosGetResource(NULLHANDLE, RT_DIALOG, ID_NBDLG_TIME,
            (PPVOID)&(DlgData[0]));
        aResult = DosGetResource(NULLHANDLE, RT_DIALOG, ID_NBDLG_DISPLAY,
            (PPVOID)&(DlgData[1]));
        aResult = DosGetResource(NULLHANDLE, RT_DIALOG, ID_NBDLG_PLAY,
            (PPVOID)&(DlgData[2]));
        aResult = DosGetResource(NULLHANDLE, RT_DIALOG, ID_NBDLG_SAVE,
            (PPVOID)&(DlgData[3]));
        aResult = DosGetResource(NULLHANDLE, RT_DIALOG, ID_NBDLG_OUTPUT,
            (PPVOID)&(DlgData[4]));
        aResult = DosGetResource(NULLHANDLE, RT_DIALOG, ID_NBDLG_HARDWARE,
            (PPVOID)&(DlgData[5]));

        hwndDlgs[0] = WinCreateDlg(hwndNotebook, hwnd,
            TimeSettingsDlgProc, DlgData[0], NULL);
        hwndDlgs[1] = WinCreateDlg(hwndNotebook, hwnd,
            DisplaySettingsDlgProc, DlgData[1], NULL);
        hwndDlgs[2] = WinCreateDlg(hwndNotebook, hwnd,
            PlaySettingsDlgProc, DlgData[2], NULL);
        hwndDlgs[3] = WinCreateDlg(hwndNotebook, hwnd,
            SaveSettingsDlgProc, DlgData[3], NULL);
        hwndDlgs[4] = WinCreateDlg(hwndNotebook, hwnd,
            OutputSettingsDlgProc, DlgData[4], NULL);
        hwndDlgs[5] = WinCreateDlg(hwndNotebook, hwnd,
            HardwareSettingsDlgProc, DlgData[5], NULL);

        for ( i = 0; i < 6; i++ ) {
            WinSetOwner(hwndDlgs[i], hwndNotebook);
            bResult = (BOOL)WinSendMsg(hwndNotebook, BKM_SETSTATUSLINETEXT,
                MPFROMLONG(PageID[i]), MPFROMP(PageOneOfOne));
            bResult = (BOOL)WinSendMsg(hwndNotebook, BKM_SETPAGEWINDOWHWND,
                MPFROMLONG(PageID[i]), MPFROMP(hwndDlgs[i]));
            }

        Panel[0] = PANEL_SE_TIMEFORMAT;
        Panel[1] = PANEL_SE_ANIMATION;
        Panel[2] = PANEL_SE_PLAY;
        Panel[3] = PANEL_SE_SAVE;
        Panel[4] = PANEL_SE_OUTPUT;
        Panel[5] = PANEL_SE_HARDWARE;

        return NULL;

      case HM_HELPSUBITEM_NOT_FOUND :
        if ( IsHelpButton(SHORT2FROMMP(mp2)) ) {
            WinSendMsg(hwndMainHelp, HM_DISPLAY_HELP, NULL, NULL);
            return MRFROMLONG(TRUE);
            }
        else {
            return MRFROMLONG(FALSE);
            }

      case WM_CONTROL :
        if ( SHORT1FROMMP(mp1) == ID_NOTEBOOK ) {
            if ( SHORT2FROMMP(mp1) == BKN_PAGESELECTED ) {
                PAGESELECTNOTIFY *PageSelect = PVOIDFROMMP(mp2);

                for ( i = 0; i < 6; i++ ) {
                    if ( PageSelect->ulPageIdNew == PageID[i] ) {
                        WinSetFocus(HWND_DESKTOP, hwndDlgs[i]);
                        break;
                        }
                    }
                }
            else if ( SHORT2FROMMP(mp1) == BKN_HELP ) {
                for ( i = 0; i < 6; i++ ) {
                    if ( LONGFROMMP(mp2) == PageID[i] ) {
                        WinSendMsg(hwndMainHelp, HM_DISPLAY_HELP,
                            MPFROMSHORT(Panel[i]),
                            MPFROMSHORT(HM_RESOURCEID));
                        break;
                        }
                    }
                }
            }
        return NULL;

      case WM_COMMAND :
        switch ( SHORT1FROMMP(mp1) ) {
          case ID_HELPINDEX :
            if ( hwndMainHelp != NULL )
                WinSendMsg(hwndMainHelp, HM_HELP_INDEX, NULL, NULL);
            return NULL;

          case ID_HELPEXTENDED :
            if ( hwndMainHelp != NULL )
                WinSendMsg(hwndMainHelp, HM_EXT_HELP, NULL, NULL);
            return NULL;

          case ID_HELPONHELP :
            if ( hwndMainHelp != NULL )
                WinSendMsg(hwndMainHelp, HM_DISPLAY_HELP, NULL, NULL);
            return NULL;

          case ID_HELPKEYS :
            if ( hwndMainHelp != NULL )
                WinSendMsg(hwndMainHelp, HM_KEYS_HELP, NULL, NULL);
            return NULL;
            }
        return NULL;

      case HM_QUERY_KEYS_HELP :
        return MRFROMSHORT(PANEL_SE_KEYBOARD);

      case WM_CLOSE :
        WinSendMsg(hwndMainHelp, HM_DISMISS_WINDOW, NULL, NULL);
        WinSetWindowPos(hwnd, HWND_TOP, 0, 0, 0, 0, SWP_HIDE);
        SettingsDlgHidden = TRUE;
        WinSetFocus(HWND_DESKTOP, hwndDlg);
        return NULL;
 
      case WM_DESTROY :
        return NULL;

      case WM_ACTIVATE :
        if ( ModalProcessing && SHORT1FROMMP(mp1) ) {
            WinPostMsg(hwnd, INTERNAL_DELAYED_RESETFOCUS, MPFROMHWND(CurrModalOwner), NULL);
            }
        return WinDefDlgProc(hwnd, msg, mp1, mp2);

      case INTERNAL_DELAYED_RESETFOCUS :
        WinSetFocus(HWND_DESKTOP, HWNDFROMMP(mp1));
        return NULL;

      case WM_WINDOWPOSCHANGED :
        PSwp = (PSWP)PVOIDFROMMP(mp1);

        if ( SaveWindowPos && SettingsDlgInProcess && (PSwp->fl & (SWP_MOVE | SWP_SIZE)) ) {
            if ( PSwp->fl & (SWP_MINIMIZE | SWP_HIDE) ) {
                // CDPrfSaveWindowPos(CDWINDOW_OPTIONS, PSwp->x, PSwp->y, PSwp->cx, PSwp->cy,
                //    WINDOWSTATE_NORMAL);
                }
            else {
                CDPrfSaveWindowPos(CDWINDOW_OPTIONS, PSwp->x, PSwp->y, PSwp->cx, PSwp->cy,
                    WINDOWSTATE_NORMAL);
                }
            }

        if ( PSwp->fl & (SWP_HIDE | SWP_MINIMIZE) ) {
            WinSendMsg(hwndMainHelp, HM_DISMISS_WINDOW, NULL, NULL);
            SettingsDlgHidden = TRUE;
            // WinSetFocus(HWND_DESKTOP, hwndDlg);
            }
        else if ( PSwp->fl & SWP_SIZE ) {
            bResult = WinSetWindowPos(hwndNotebook, HWND_TOP, 0, 0,
                PSwp->cx
                - 2 * WinQuerySysValue(HWND_DESKTOP, SV_CXSIZEBORDER),
                PSwp->cy
                - 2 * WinQuerySysValue(HWND_DESKTOP, SV_CYSIZEBORDER)
                - WinQuerySysValue(HWND_DESKTOP, SV_CYMENU),
                SWP_SIZE);
            }

        return WinDefDlgProc(hwnd, msg, mp1, mp2);

      default :
        return WinDefDlgProc(hwnd, msg, mp1, mp2);
        }
}

#define INTERNAL_RESETFOCUS             (WM_USER+1)
#define INTERNAL_DELAYED_CONTROL        (WM_USER+2)

MRESULT EXPENTRY TimeSettingsDlgProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2)
{
    ULONG TimeFormat;
    ULONG TimeSeparator;
    ULONG TimeFrequency;
    static char Buffer[16];
    static BOOL InitialBNClick = TRUE;

    switch ( msg ) {
      /*
      case WM_CHAR :
        if ( (SHORT1FROMMP(mp1) & KC_VIRTUALKEY) ) {
            if ( SHORT1FROMMP(mp1) & KC_ALT ) {
                if ( SHORT2FROMMP(mp2) == VK_F4 ) {
                    return NULL;
                    }
                }
            }
        return NULL;
      */

      case WM_INITDLG :
        InitialBNClick = TRUE;
        WinSendDlgItemMsg(hwnd, ID_NB_TIMESEP, EM_SETTEXTLIMIT, MPFROMSHORT(1), NULL);
        WinSendDlgItemMsg(hwnd, ID_NB_TIMEFREQ, EM_SETTEXTLIMIT, MPFROMSHORT(16), NULL);

        /*
        OldTest1WndProc = WinSubclassWindow(WinWindowFromID(hwnd, ID_NB_HHMMSS), Test1WndProc);
        OldTest2WndProc = WinSubclassWindow(WinWindowFromID(hwnd, ID_NB_MMSSFF), Test2WndProc);
        */

        CDPrfGetOption(CDOPT_TIMEFORMAT, &TimeFormat);
        CDPrfGetOption(CDOPT_TIMESEPARATOR, &TimeSeparator);
        CDPrfGetOption(CDOPT_TIMEFREQ, &TimeFrequency);

        if ( TimeFormat == HHMMSS ) {
//            WinSendDlgItemMsg(hwnd, ID_NB_HHMMSS, BM_CLICK, MPFROMLONG(FALSE), NULL);
            WinSendDlgItemMsg(hwnd, ID_NB_HHMMSS, BM_SETCHECK, MPFROMSHORT(1), NULL);
            WinSendDlgItemMsg(hwnd, ID_NB_MMSSFF, BM_SETCHECK, MPFROMSHORT(0), NULL);
            }
        else if ( TimeFormat == MMSSFF ) {
//            WinSendDlgItemMsg(hwnd, ID_NB_MMSSFF, BM_CLICK, MPFROMLONG(FALSE), NULL);
            WinSendDlgItemMsg(hwnd, ID_NB_HHMMSS, BM_SETCHECK, MPFROMSHORT(0), NULL);
            WinSendDlgItemMsg(hwnd, ID_NB_MMSSFF, BM_SETCHECK, MPFROMSHORT(1), NULL);
            }

        Buffer[0] = TimeSeparator;
        Buffer[1] = 1;
        WinSetDlgItemText(hwnd, ID_NB_TIMESEP, Buffer);
        WinSetDlgItemText(hwnd, ID_NB_TIMEFREQ, itoa(TimeFrequency, Buffer, 10));
        WinSendDlgItemMsg(hwnd, ID_NB_TIMESEP, EM_QUERYCHANGED, NULL, NULL);
        WinSendDlgItemMsg(hwnd, ID_NB_TIMEFREQ, EM_QUERYCHANGED, NULL, NULL);
        return NULL;

      case INTERNAL_RESETFOCUS :
        WinSetFocus(HWND_DESKTOP, HWNDFROMMP(mp1));
        return NULL;
 
      case WM_CLOSE :
        WinSendMsg(SettingsDlg, msg, mp1, mp2);
        return NULL;

      case WM_COMMAND :
        return NULL;

      case WM_CONTROL :
        /*
        WinPostMsg(hwnd, INTERNAL_DELAYED_CONTROL, mp1, mp2);
        return NULL;

      case INTERNAL_DELAYED_CONTROL :
        */
        switch ( SHORT1FROMMP(mp1) ) {
          case ID_NB_TIMESEP :
            if ( SHORT2FROMMP(mp1) == EN_KILLFOCUS && 
                 WinSendMsg(HWNDFROMMP(mp2), EM_QUERYCHANGED, NULL, NULL) ) {
                WinQueryWindowText(HWNDFROMMP(mp2), sizeof(Buffer), Buffer);
                TimeSeparator = Buffer[0];
                if ( ! CDPrfSetOption(hwndDlg, CDOPT_TIMESEPARATOR, TimeSeparator) ) {
                    CDPrfGetOption(CDOPT_TIMESEPARATOR, &TimeSeparator);
                    Buffer[0] = TimeSeparator;
                    Buffer[1] = 1;
                    WinSetWindowText(HWNDFROMMP(mp2), Buffer);
                    WinAlarm(HWND_DESKTOP, WA_ERROR);
                    WinPostMsg(hwnd, INTERNAL_RESETFOCUS, mp2, NULL);
                    }
                }
            break;

          case ID_NB_TIMEFREQ :
            if ( SHORT2FROMMP(mp1) == EN_KILLFOCUS &&
                 WinSendMsg(HWNDFROMMP(mp2), EM_QUERYCHANGED, NULL, NULL) ) {
                WinQueryWindowText(HWNDFROMMP(mp2), sizeof(Buffer), Buffer);
                TimeFrequency = atoi(Buffer);
                if ( ! CDPrfSetOption(hwndDlg, CDOPT_TIMEFREQ, TimeFrequency) ) {
                    CDPrfGetOption(CDOPT_TIMEFREQ, &TimeFrequency);
                    WinSetWindowText(HWNDFROMMP(mp2), itoa(TimeFrequency, Buffer, 10));
                    WinAlarm(HWND_DESKTOP, WA_ERROR);
                    WinPostMsg(hwnd, INTERNAL_RESETFOCUS, mp2, NULL);
                    }
                }
            break;

          case ID_NB_HHMMSS :
           if ( SHORT2FROMMP(mp1) == BN_CLICKED ) {
                if ( InitialBNClick ) {
                    InitialBNClick = FALSE;
                    }
                else if ( WinSendMsg(HWNDFROMMP(mp2), BM_QUERYCHECK, NULL, NULL) == 0 ) {
                    if ( CDPrfSetOption(hwndDlg, CDOPT_TIMEFORMAT, HHMMSS) ) {
                        WinSendMsg(HWNDFROMMP(mp2), BM_SETCHECK, MPFROMSHORT(1), NULL);
                        WinSendDlgItemMsg(hwnd, ID_NB_MMSSFF, BM_SETCHECK, MPFROMSHORT(0), NULL);
                        }
                    else {
                        WinAlarm(HWND_DESKTOP, WA_ERROR);
                        }
                    }
                }
            break;

          case ID_NB_MMSSFF :
            if ( SHORT2FROMMP(mp1) == BN_CLICKED ) {
                if ( InitialBNClick ) {
                    InitialBNClick = FALSE;
                    }
                else if ( WinSendMsg(HWNDFROMMP(mp2), BM_QUERYCHECK, NULL, NULL) == 0 ) {
                    if ( CDPrfSetOption(hwndDlg, CDOPT_TIMEFORMAT, MMSSFF) ) {
                        WinSendMsg(HWNDFROMMP(mp2), BM_SETCHECK, MPFROMSHORT(1), NULL);
                        WinSendDlgItemMsg(hwnd, ID_NB_HHMMSS, BM_SETCHECK, MPFROMSHORT(0), NULL);
                        }
                    else {
                        WinAlarm(HWND_DESKTOP, WA_ERROR);
                        }
                    }
                }
            break;
            }

        return NULL;

      default :
        return WinDefDlgProc(hwnd, msg, mp1, mp2);
        }
}

MRESULT EXPENTRY DisplaySettingsDlgProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2)
{
    ULONG Animation;
    ULONG AnimationRate;
    ULONG ListBoxAnimation;
    static char Buffer[16];

    switch ( msg ) {
      case WM_INITDLG :
        WinSendDlgItemMsg(hwnd, ID_NB_ANIMATIONRATE, EM_SETTEXTLIMIT, MPFROMSHORT(12), NULL);

        CDPrfGetOption(CDOPT_ANIMATION, &Animation);
        CDPrfGetOption(CDOPT_ANIMATIONFREQ, &AnimationRate);
        CDPrfGetOption(CDOPT_LISTBOXANIMATION, &ListBoxAnimation);

        WinSendDlgItemMsg(hwnd, ID_NB_ANIMATION, BM_SETCHECK,
            MPFROMSHORT(Animation != 0), NULL);

        WinSetDlgItemText(hwnd, ID_NB_ANIMATIONRATE, itoa(AnimationRate, Buffer, 10));
        WinSendDlgItemMsg(hwnd, ID_NB_ANIMATIONRATE, EM_QUERYCHANGED, NULL, NULL);

        WinSendDlgItemMsg(hwnd, ID_NB_LISTBOXANIMATION, BM_SETCHECK,
            MPFROMSHORT(ListBoxAnimation != 0), NULL);

        return NULL;

      case INTERNAL_RESETFOCUS :
        WinSetFocus(HWND_DESKTOP, HWNDFROMMP(mp1));
        return NULL;

      case WM_COMMAND :
        return NULL;

      case WM_CLOSE :
        WinSendMsg(SettingsDlg, msg, mp1, mp2);
        return NULL;

      case WM_CONTROL :
        /*
        WinPostMsg(hwnd, INTERNAL_DELAYED_CONTROL, mp1, mp2);
        return NULL;

      case INTERNAL_DELAYED_CONTROL :
        */
        switch ( SHORT1FROMMP(mp1) ) {
          case ID_NB_ANIMATIONRATE :
            if ( SHORT2FROMMP(mp1) == EN_KILLFOCUS &&
                 WinSendMsg(HWNDFROMMP(mp2), EM_QUERYCHANGED, NULL, NULL) ) {
                WinQueryWindowText(HWNDFROMMP(mp2), sizeof(Buffer), Buffer);
                AnimationRate = atoi(Buffer);
                if ( ! CDPrfSetOption(hwndDlg, CDOPT_ANIMATIONFREQ, AnimationRate) ) {
                    CDPrfGetOption(CDOPT_ANIMATIONFREQ, &AnimationRate);
                    WinSetWindowText(HWNDFROMMP(mp2), itoa(AnimationRate, Buffer, 10));
                    WinAlarm(HWND_DESKTOP, WA_ERROR);
                    WinPostMsg(hwnd, INTERNAL_RESETFOCUS, mp2, NULL);
                    }
                }
            break;

          case ID_NB_ANIMATION :
            if ( SHORT2FROMMP(mp1) == BN_CLICKED ) {
                Animation = ! WinSendMsg(HWNDFROMMP(mp2), BM_QUERYCHECK, NULL, NULL);
                if ( CDPrfSetOption(hwndDlg, CDOPT_ANIMATION, Animation) ) {
                    WinSendMsg(HWNDFROMMP(mp2), BM_SETCHECK, MPFROMSHORT(Animation), NULL);
                    }
                else {
                    WinAlarm(HWND_DESKTOP, WA_ERROR);
                    }
                }
            break;

          case ID_NB_LISTBOXANIMATION :
            if ( SHORT2FROMMP(mp1) == BN_CLICKED ) {
                ListBoxAnimation = ! WinSendMsg(HWNDFROMMP(mp2), BM_QUERYCHECK, NULL, NULL);
                if ( CDPrfSetOption(hwndDlg, CDOPT_LISTBOXANIMATION, ListBoxAnimation) ) {
                    WinSendMsg(HWNDFROMMP(mp2), BM_SETCHECK, 
                        MPFROMSHORT(ListBoxAnimation), NULL);
                    }
                else {
                    WinAlarm(HWND_DESKTOP, WA_ERROR);
                    }
                }
            break;
            }

        return NULL;

      default :
        return WinDefDlgProc(hwnd, msg, mp1, mp2);
        }
}

MRESULT EXPENTRY PlaySettingsDlgProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2)
{
    ULONG AutoStart;
    ULONG AutoRepeat;
    ULONG BackwardLimit;
    static char Buffer[16];

    switch ( msg ) {
      case WM_INITDLG :
        WinSendDlgItemMsg(hwnd, ID_NB_BACKWARDLIMIT, EM_SETTEXTLIMIT, MPFROMSHORT(8), NULL);

        CDPrfGetOption(CDOPT_AUTOREPEAT, &AutoRepeat);
        CDPrfGetOption(CDOPT_AUTOSTART, &AutoStart);
        CDPrfGetOption(CDOPT_BACKWARDTHRESHOLD, &BackwardLimit);

        if ( AutoRepeat ) {
            WinSendDlgItemMsg(hwnd, ID_NB_AUTOREPEAT, BM_SETCHECK, MPFROMSHORT(1), NULL);
            }
        else {
            WinSendDlgItemMsg(hwnd, ID_NB_AUTOREPEAT, BM_SETCHECK, MPFROMSHORT(0), NULL);
            }

        if ( AutoStart ) {
            WinSendDlgItemMsg(hwnd, ID_NB_AUTOSTART, BM_SETCHECK, MPFROMSHORT(1), NULL);
            }
        else {
            WinSendDlgItemMsg(hwnd, ID_NB_AUTOSTART, BM_SETCHECK, MPFROMSHORT(0), NULL);
            }

        WinSetDlgItemText(hwnd, ID_NB_BACKWARDLIMIT, itoa(BackwardLimit, Buffer, 10));
        WinSendDlgItemMsg(hwnd, ID_NB_BACKWARDLIMIT, EM_QUERYCHANGED, NULL, NULL);
        return NULL;

      case INTERNAL_RESETFOCUS :
        WinSetFocus(HWND_DESKTOP, HWNDFROMMP(mp1));
        return NULL;

      case WM_COMMAND :
        return NULL;

      case WM_CLOSE :
        WinSendMsg(SettingsDlg, msg, mp1, mp2);
        return NULL;

      case WM_CONTROL :
        /*
        WinPostMsg(hwnd, INTERNAL_DELAYED_CONTROL, mp1, mp2);
        return NULL;

      case INTERNAL_DELAYED_CONTROL :
        */
        switch ( SHORT1FROMMP(mp1) ) {
          case ID_NB_BACKWARDLIMIT :
            if ( SHORT2FROMMP(mp1) == EN_KILLFOCUS &&
                 WinSendMsg(HWNDFROMMP(mp2), EM_QUERYCHANGED, NULL, NULL) ) {
                WinQueryWindowText(HWNDFROMMP(mp2), sizeof(Buffer), Buffer);
                BackwardLimit = atoi(Buffer);
                if ( ! CDPrfSetOption(hwndDlg, CDOPT_BACKWARDTHRESHOLD, BackwardLimit) ) {
                    CDPrfGetOption(CDOPT_BACKWARDTHRESHOLD, &BackwardLimit);
                    WinSetWindowText(HWNDFROMMP(mp2), itoa(BackwardLimit, Buffer, 10));
                    WinAlarm(HWND_DESKTOP, WA_ERROR);
                    WinPostMsg(hwnd, INTERNAL_RESETFOCUS, mp2, NULL);
                    }
                }
            break;

          case ID_NB_AUTOREPEAT :
            if ( SHORT2FROMMP(mp1) == BN_CLICKED ) {
                AutoRepeat = ! WinSendMsg(HWNDFROMMP(mp2), BM_QUERYCHECK, NULL, NULL);
                if ( CDPrfSetOption(hwndDlg, CDOPT_AUTOREPEAT, AutoRepeat) ) {
                    WinSendMsg(HWNDFROMMP(mp2), BM_SETCHECK, MPFROMSHORT(AutoRepeat), NULL);
                    }
                else {
                    WinAlarm(HWND_DESKTOP, WA_ERROR);
                    }
                }
            break;

          case ID_NB_AUTOSTART :
            if ( SHORT2FROMMP(mp1) == BN_CLICKED ) {
                AutoStart = ! WinSendMsg(HWNDFROMMP(mp2), BM_QUERYCHECK, NULL, NULL);
                if ( CDPrfSetOption(hwndDlg, CDOPT_AUTOSTART, AutoStart) ) {
                    WinSendMsg(HWNDFROMMP(mp2), BM_SETCHECK, MPFROMSHORT(AutoStart), NULL);
                    }
                else {
                    WinAlarm(HWND_DESKTOP, WA_ERROR);
                    }
                }
            break;
            }

        return NULL;

      default :
        return WinDefDlgProc(hwnd, msg, mp1, mp2);
        }
}

MRESULT EXPENTRY SaveSettingsDlgProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2)
{
    ULONG SaveOption;

    switch ( msg ) {
      case WM_INITDLG :
        CDPrfGetOption(CDOPT_SAVEWINDOWPOS, &SaveOption);
        WinSendDlgItemMsg(hwnd, ID_NB_SAVEWINDOWPOS, BM_SETCHECK, 
            MPFROMSHORT(SaveOption), NULL);

        CDPrfGetOption(CDOPT_SAVEVOLUME, &SaveOption);
        WinSendDlgItemMsg(hwnd, ID_NB_SAVEVOLUME, BM_SETCHECK,
            MPFROMSHORT(SaveOption), NULL);

        CDPrfGetOption(CDOPT_SAVEPOSITION, &SaveOption);
        WinSendDlgItemMsg(hwnd, ID_NB_SAVEPOSITION, BM_SETCHECK,
            MPFROMSHORT(SaveOption), NULL);

        CDPrfGetOption(CDOPT_SAVEMARKERS, &SaveOption);
        WinSendDlgItemMsg(hwnd, ID_NB_SAVEMARKERS, BM_SETCHECK,
            MPFROMSHORT(SaveOption), NULL);
        return NULL;

      case INTERNAL_RESETFOCUS :
        WinSetFocus(HWND_DESKTOP, HWNDFROMMP(mp1));
        return NULL;

      case WM_COMMAND :
        return NULL;

      case WM_CLOSE :
        WinSendMsg(SettingsDlg, msg, mp1, mp2);
        return NULL;

      case WM_CONTROL :
        /*
        WinPostMsg(hwnd, INTERNAL_DELAYED_CONTROL, mp1, mp2);
        return NULL;

      case INTERNAL_DELAYED_CONTROL :
        */
        switch ( SHORT1FROMMP(mp1) ) {
          case ID_NB_SAVEWINDOWPOS :
            if ( SHORT2FROMMP(mp1) == BN_CLICKED ) {
                SaveOption = ! WinSendMsg(HWNDFROMMP(mp2), BM_QUERYCHECK, NULL, NULL);
                if ( CDPrfSetOption(hwndDlg, CDOPT_SAVEWINDOWPOS, SaveOption) ) {
                    WinSendMsg(HWNDFROMMP(mp2), BM_SETCHECK, MPFROMSHORT(SaveOption), NULL);
                    }
                else {
                    WinAlarm(HWND_DESKTOP, WA_ERROR);
                    }
                }
            break;

          case ID_NB_SAVEVOLUME :
            if ( SHORT2FROMMP(mp1) == BN_CLICKED ) {
                SaveOption = ! WinSendMsg(HWNDFROMMP(mp2), BM_QUERYCHECK, NULL, NULL);
                if ( CDPrfSetOption(hwndDlg, CDOPT_SAVEVOLUME, SaveOption) ) {
                    WinSendMsg(HWNDFROMMP(mp2), BM_SETCHECK, MPFROMSHORT(SaveOption), NULL);
                    }
                else {
                    WinAlarm(HWND_DESKTOP, WA_ERROR);
                    }
                }
            break;

          case ID_NB_SAVEPOSITION :
            if ( SHORT2FROMMP(mp1) == BN_CLICKED ) {
                SaveOption = ! WinSendMsg(HWNDFROMMP(mp2), BM_QUERYCHECK, NULL, NULL);
                if ( CDPrfSetOption(hwndDlg, CDOPT_SAVEPOSITION, SaveOption) ) {
                    WinSendMsg(HWNDFROMMP(mp2), BM_SETCHECK, MPFROMSHORT(SaveOption), NULL);
                    }
                else {
                    WinAlarm(HWND_DESKTOP, WA_ERROR);
                    }
                }
            break;

          case ID_NB_SAVEMARKERS :
            if ( SHORT2FROMMP(mp1) == BN_CLICKED ) {
                SaveOption = ! WinSendMsg(HWNDFROMMP(mp2), BM_QUERYCHECK, NULL, NULL);
                if ( CDPrfSetOption(hwndDlg, CDOPT_SAVEMARKERS, SaveOption) ) {
                    WinSendMsg(HWNDFROMMP(mp2), BM_SETCHECK, MPFROMSHORT(SaveOption), NULL);
                    }
                else {
                    WinAlarm(HWND_DESKTOP, WA_ERROR);
                    }
                }
            break;

            }

        return NULL;

      default :
        return WinDefDlgProc(hwnd, msg, mp1, mp2);
        }
}

MRESULT EXPENTRY OutputSettingsDlgProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2)
{
    ULONG Output;

    switch ( msg ) {
      case WM_INITDLG :
        CDPrfGetOption(CDOPT_OUTPUTHEADPHONES, &Output);
        WinSendDlgItemMsg(hwnd, ID_NB_HEADPHONES, BM_SETCHECK, 
            MPFROMSHORT(Output), NULL);

        CDPrfGetOption(CDOPT_OUTPUTSOUNDCARD, &Output);
        WinSendDlgItemMsg(hwnd, ID_NB_SOUNDCARD, BM_SETCHECK, 
            MPFROMSHORT(Output), NULL);

        CDPrfGetOption(CDOPT_OUTPUTEXTAMP, &Output);
        WinSendDlgItemMsg(hwnd, ID_NB_AMPLIFIER, BM_SETCHECK, 
            MPFROMSHORT(Output), NULL);
        return NULL;

      case INTERNAL_RESETFOCUS :
        WinSetFocus(HWND_DESKTOP, HWNDFROMMP(mp1));
        return NULL;

      case WM_COMMAND :
        return NULL;

      case WM_CLOSE :
        WinSendMsg(SettingsDlg, msg, mp1, mp2);
        return NULL;

      case WM_CONTROL :
        /*
        WinPostMsg(hwnd, INTERNAL_DELAYED_CONTROL, mp1, mp2);
        return NULL;

      case INTERNAL_DELAYED_CONTROL :
        */
        switch ( SHORT1FROMMP(mp1) ) {
          case ID_NB_HEADPHONES :
            if ( SHORT2FROMMP(mp1) == BN_CLICKED ) {
                Output = ! WinSendMsg(HWNDFROMMP(mp2), BM_QUERYCHECK, NULL, NULL);
                if ( CDPrfSetOption(hwndDlg, CDOPT_OUTPUTHEADPHONES, Output) ) {
                    WinSendMsg(HWNDFROMMP(mp2), BM_SETCHECK, MPFROMSHORT(Output), NULL);
                    }
                else {
                    WinAlarm(HWND_DESKTOP, WA_ERROR);
                    }
                }
            break;

          case ID_NB_SOUNDCARD :
            if ( SHORT2FROMMP(mp1) == BN_CLICKED ) {
                Output = ! WinSendMsg(HWNDFROMMP(mp2), BM_QUERYCHECK, NULL, NULL);
                if ( CDPrfSetOption(hwndDlg, CDOPT_OUTPUTSOUNDCARD, Output) ) {
                    WinSendMsg(HWNDFROMMP(mp2), BM_SETCHECK, MPFROMSHORT(Output), NULL);
                    }
                else {
                    WinAlarm(HWND_DESKTOP, WA_ERROR);
                    }
                }
            break;

          case ID_NB_AMPLIFIER :
           if ( SHORT2FROMMP(mp1) == BN_CLICKED ) {
                Output = ! WinSendMsg(HWNDFROMMP(mp2), BM_QUERYCHECK, NULL, NULL);
                if ( CDPrfSetOption(hwndDlg, CDOPT_OUTPUTEXTAMP, Output) ) {
                    WinSendMsg(HWNDFROMMP(mp2), BM_SETCHECK, MPFROMSHORT(Output), NULL);
                    }
                else {
                    WinAlarm(HWND_DESKTOP, WA_ERROR);
                    }
                }
            break;
            }

        return NULL;

      default :
        return WinDefDlgProc(hwnd, msg, mp1, mp2);
        }
}

MRESULT EXPENTRY HardwareSettingsDlgProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2)
{
    ULONG LockOption;
    static char Buffer[64];
    int i;

    switch ( msg ) {
      case WM_INITDLG :
        CDPrfGetOption(CDOPT_LOCKWHILEPLAY, &LockOption);
        WinSendDlgItemMsg(hwnd, ID_NB_LOCKEDPLAY, BM_SETCHECK,
            MPFROMSHORT(LockOption), NULL);

        CDPrfGetOption(CDOPT_DEVICENAME, Buffer);
        WinSendDlgItemMsg(hwnd, ID_NB_DEVICENAME, EM_SETTEXTLIMIT, 
            MPFROMSHORT(sizeof(Buffer)-1), NULL);
        WinSetDlgItemText(hwnd, ID_NB_DEVICENAME, Buffer);

        i = 1;
        while ( CDQueryDevName(i, Buffer, sizeof(Buffer)) ) {
            WinSendDlgItemMsg(hwnd, ID_NB_DEVICENAME, LM_INSERTITEM,
                MPFROMSHORT(LIT_SORTASCENDING), Buffer);
            i++;
            }
 
        WinSendDlgItemMsg(hwnd, ID_NB_DEVICENAME, LM_INSERTITEM,
            MPFROMSHORT(LIT_SORTASCENDING), DefaultDeviceName);

        return NULL;

      case INTERNAL_RESETFOCUS :
        WinSetFocus(HWND_DESKTOP, HWNDFROMMP(mp1));
        return NULL;

      case WM_COMMAND :
        return NULL;

      case WM_CLOSE :
        WinSendMsg(SettingsDlg, msg, mp1, mp2);
        return NULL;

      case WM_CONTROL :
        /*
        WinPostMsg(hwnd, INTERNAL_DELAYED_CONTROL, mp1, mp2);
        return NULL;

      case INTERNAL_DELAYED_CONTROL :
        */
        switch ( SHORT1FROMMP(mp1) ) {
          case ID_NB_LOCKEDPLAY :
            if ( SHORT2FROMMP(mp1) == BN_CLICKED ) {
                LockOption = ! WinSendMsg(HWNDFROMMP(mp2), BM_QUERYCHECK, NULL, NULL);
                if ( CDPrfSetOption(hwndDlg, CDOPT_LOCKWHILEPLAY, LockOption) ) {
                    WinSendMsg(HWNDFROMMP(mp2), BM_SETCHECK, MPFROMSHORT(LockOption), NULL);
                    }
                else {
                    WinAlarm(HWND_DESKTOP, WA_ERROR);
                    }
                }
            break;
          case ID_NB_DEVICENAME :
            if ( SHORT2FROMMP(mp1) == CBN_ENTER ) {
                WinQueryWindowText(HWNDFROMMP(mp2), sizeof(Buffer), MPFROMP(Buffer));
                if ( ! CDPrfSetOption(hwndDlg, CDOPT_DEVICENAME, (ULONG)(PVOID)Buffer) ) {
                    CDPrfGetOption(CDOPT_DEVICENAME, Buffer);
                    WinSetWindowText(HWNDFROMMP(mp2), Buffer);
                    WinAlarm(HWND_DESKTOP, WA_ERROR);
                    }
                }
            break;
            }

        return NULL;

      default :
        return WinDefDlgProc(hwnd, msg, mp1, mp2);
        }
}

static BOOL SetProgramPath(char *argv0)
{
    APIRET aResult;
    int i;

    aResult = DosQueryPathInfo(argv0, FIL_QUERYFULLNAME, ProgramPath,
        sizeof(ProgramPath));

    if ( ! aResult ) {
        i = strlen(ProgramPath);
        while ( ProgramPath[i-1] != '\\' ) {
            i--;
            }
        ProgramPath[i] = 0;
        }
    else {
        strcpy(ProgramPath, ".\\");
        }

    return TRUE;
}

static BOOL SetDlgTitle(HWND hwnd, PSZ Title)
{
    char *Buffer;
    BOOL bResult;

    Buffer = malloc(strlen(ApplTitle) + strlen(TitleSep) + strlen(Title) + 1);

    // if ( Title == CDUntitled || Title == CDNone ) {
        strcpy(Buffer, ApplTitle);
        strcat(Buffer, TitleSep);
        strcat(Buffer, Title);
    /*
        }
    else {
        strcpy(Buffer, Title);
        }
    */
    bResult = SetWindowTitle(hwnd, hSwitch, Buffer);
    free(Buffer);
    return bResult;
}

static BOOL StartWatchdog(HWND hwnd)
{
    if ( ! WinTimerStarted ) {
        WinTimerStarted = WinStartTimer(hab, hwnd, 1, 1000);
        }

    return WinTimerStarted;
}

static BOOL StopWatchdog(HWND hwnd)
{
    if ( WinTimerStarted ) {
        WinTimerStarted = ! WinStopTimer(hab, hwnd, 1);
        }

    return ! WinTimerStarted;
}

BOOL InitMousePointers(void)
{
    hptrWait = WinQuerySysPointer(HWND_DESKTOP, SPTR_WAIT, FALSE);

    return hptrWait != NULLHANDLE;
}

BOOL SetWaitPointer(BOOL Set)
{
    static HPOINTER hptrCurr = NULL;

    if ( Set ) {
        hptrCurr = WinQueryPointer(HWND_DESKTOP);
        WinSetPointer(HWND_DESKTOP, hptrWait);
        }
    else {
        if ( hptrCurr != NULL ) {
            WinSetPointer(HWND_DESKTOP, hptrCurr);
            hptrCurr = NULL;
            }
        }

    return TRUE;
}

                                                                         
/*
            {
                PERRINFO ErrInfo;
                ERRORID ErrID;
                WinGetErrorInfo(hab);
                ErrID = WinGetLastError(hab);
                ErrID = WinGetLastError(hab);
            }

*/ 

