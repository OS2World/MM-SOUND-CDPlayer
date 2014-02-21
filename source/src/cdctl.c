#include "cdglobal.h"
#include "cddevice.h"
#include "cdmsg.h"
#include "cdplayer.h"
#include "cdpos.h"
#include "cdprf.h"
#include "cdtitle.h"
#include "cdctl.h"
#include "wutil.h"

typedef struct {
    USHORT cb;
    ULONG msg;
    CDAUDIO_CONTENTS *Contents;
    PSZ TitleAccess;
    } DLGSTARTDATA;

// PFNWP OldTEEntryCDWndProc;
PFNWP OldTEEntryTrackWndProc;
PFNWP OldBGBoxProc;
PFNWP OldFGBoxProc;
MRESULT EXPENTRY TEEntryTrackWndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2);
MRESULT EXPENTRY FGBoxProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2);
MRESULT EXPENTRY BGBoxProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2);

BOOL IsHelpButton(USHORT Id)
{
    switch ( Id ) {
      case ID_HELP_MENU :
      case ID_HELPINDEX :
      case ID_HELPEXTENDED :
      case ID_HELPONHELP :
      case ID_HELPKEYS :
      case ID_HELP :
      case ID_NB_HELP1 :
      case ID_NB_HELP2 :
      case ID_NB_HELP3 :
      case ID_NB_HELP4 :
      case ID_NB_HELP5 :
      case ID_NB_HELP6 :
      case ID_TE_HELP :
      case ID_PE_HELP :
      case ID_IN_HELP :
        return TRUE;
      default :
        return FALSE;
        }
}

BOOL InitButtons(HWND hwndDlg)
{
    hwndChangeTitles = WinWindowFromID(hwndDlg, ID_CHANGE_TITLES);
    hwndProgramTitles = WinWindowFromID(hwndDlg, ID_PROGRAM_TITLES);
    hwndInfoWindow = WinWindowFromID(hwndDlg, ID_INFO);
    hwndOptions = WinWindowFromID(hwndDlg, ID_OPTIONS);

    hwndBackward = WinWindowFromID(hwndDlg, ID_BACKWARD);
    hwndForward = WinWindowFromID(hwndDlg, ID_FORWARD);
    hwndPlay = WinWindowFromID(hwndDlg, ID_PLAY);
    hwndPause = WinWindowFromID(hwndDlg, ID_PAUSE);
    hwndStop = WinWindowFromID(hwndDlg, ID_STOP);
    hwndEject = WinWindowFromID(hwndDlg, ID_EJECT);
    hwndRepeat = WinWindowFromID(hwndDlg, ID_REPEAT);
    hwndHelp = WinWindowFromID(hwndDlg, ID_HELP);

    WinSendMsg(hwndBackward, GBM_SETBITMAPINDEX, MPFROMSHORT(GB_DISABLE),
        MPFROMSHORT(1));

    WinSendMsg(hwndForward, GBM_SETBITMAPINDEX, MPFROMSHORT(GB_DISABLE),
        MPFROMSHORT(1));

    WinSendMsg(hwndPlay, GBM_SETBITMAPINDEX, MPFROMSHORT(GB_DISABLE),
        MPFROMSHORT(PLAY_ANIMATIONS+1));

    WinSendMsg(hwndPlay, GBM_SETBITMAPINDEX, MPFROMSHORT(GB_ANIMATIONBEGIN),
        MPFROMSHORT(1));

    WinSendMsg(hwndPlay, GBM_SETBITMAPINDEX, MPFROMSHORT(GB_ANIMATIONEND),
        MPFROMSHORT(PLAY_ANIMATIONS));

    WinSendMsg(hwndPlay, GBM_SETANIMATIONRATE, MPFROMLONG(AnimationRate), NULL);

    WinSendMsg(hwndPause, GBM_SETBITMAPINDEX, MPFROMSHORT(GB_DISABLE),
        MPFROMSHORT(1));

    WinSendMsg(hwndStop, GBM_SETBITMAPINDEX, MPFROMSHORT(GB_DISABLE),
        MPFROMSHORT(1));

    WinSendMsg(hwndEject, GBM_SETBITMAPINDEX, MPFROMSHORT(GB_DISABLE),
        MPFROMSHORT(1));

    WinSendMsg(hwndRepeat, GBM_SETBITMAPINDEX, MPFROMSHORT(GB_DISABLE),
        MPFROMSHORT(1));
    WinSendMsg(hwndRepeat, GBM_SETBITMAPINDEX, MPFROMSHORT(GB_DOWN),
        MPFROMSHORT(2));
 
    if ( AutoRepeat ) {
        WinSendMsg(hwndRepeat, GBM_SETSTATE, MPFROMSHORT(GB_DOWN),
            MPFROMLONG(TRUE));
        }

    return TRUE;
}

BOOL EnableEject(BOOL Enable)
{
    USHORT ItemFlag = (Enable ? 0 : MIA_DISABLED);

    WinEnableWindow(hwndEject, Enable);
    WinSendMsg(MainMenu, MM_SETITEMATTR, MPFROM2SHORT(ID_EJECT, FALSE),
        MPFROM2SHORT(MIA_DISABLED, ItemFlag));
    WinSendMsg(ControlMenu, MM_SETITEMATTR, MPFROM2SHORT(ID_EJECT, FALSE),
        MPFROM2SHORT(MIA_DISABLED, ItemFlag));

    return TRUE;
}

BOOL EnablePlayControls(BOOL Enable)
{
    USHORT MenuFlag = (Enable ? 0 : MIA_DISABLED);

    /*
    if ( ! Enable && TitleEditorInProcess ) {
        WinSendMsg(TitleEditorDlg, TE_SETSELECT, NULL, NULL);
        }
    */

    WinEnableWindow(hwndProgramTitles, Enable);
    WinEnableWindow(hwndInfoWindow, Enable);
    WinEnableWindow(hwndBackward, Enable);
    WinEnableWindow(hwndForward, Enable);
    WinEnableWindow(hwndPlay, Enable);
    WinEnableWindow(hwndPause, Enable);
    WinEnableWindow(hwndStop, Enable);
    WinEnableWindow(hwndRepeat, Enable);

    WinSendMsg(MainMenu, MM_SETITEMATTR, MPFROM2SHORT(ID_PROGRAM_TITLES, FALSE),
        MPFROM2SHORT(MIA_DISABLED, MenuFlag));
    WinSendMsg(MainMenu, MM_SETITEMATTR, MPFROM2SHORT(ID_INFO, FALSE),
        MPFROM2SHORT(MIA_DISABLED, MenuFlag));
    WinSendMsg(MainMenu, MM_SETITEMATTR, MPFROM2SHORT(ID_BACKWARD, FALSE),
        MPFROM2SHORT(MIA_DISABLED, MenuFlag));
    WinSendMsg(MainMenu, MM_SETITEMATTR, MPFROM2SHORT(ID_FORWARD, FALSE),
        MPFROM2SHORT(MIA_DISABLED, MenuFlag));
    WinSendMsg(MainMenu, MM_SETITEMATTR, MPFROM2SHORT(ID_PLAY, FALSE),
        MPFROM2SHORT(MIA_DISABLED, MenuFlag));
    WinSendMsg(MainMenu, MM_SETITEMATTR, MPFROM2SHORT(ID_PAUSE, FALSE),
        MPFROM2SHORT(MIA_DISABLED, MenuFlag));
    WinSendMsg(MainMenu, MM_SETITEMATTR, MPFROM2SHORT(ID_STOP, FALSE),
        MPFROM2SHORT(MIA_DISABLED, MenuFlag));
    WinSendMsg(MainMenu, MM_SETITEMATTR, MPFROM2SHORT(ID_REPEAT, FALSE),
        MPFROM2SHORT(MIA_DISABLED, MenuFlag));

    WinSendMsg(SettingsMenu, MM_SETITEMATTR, MPFROM2SHORT(ID_PROGRAM_TITLES, FALSE),
        MPFROM2SHORT(MIA_DISABLED, MenuFlag));
    WinSendMsg(SettingsMenu, MM_SETITEMATTR, MPFROM2SHORT(ID_INFO, FALSE),
        MPFROM2SHORT(MIA_DISABLED, MenuFlag));
    WinSendMsg(ControlMenu, MM_SETITEMATTR, MPFROM2SHORT(ID_BACKWARD, FALSE),
        MPFROM2SHORT(MIA_DISABLED, MenuFlag));
    WinSendMsg(ControlMenu, MM_SETITEMATTR, MPFROM2SHORT(ID_FORWARD, FALSE),
        MPFROM2SHORT(MIA_DISABLED, MenuFlag));
    WinSendMsg(ControlMenu, MM_SETITEMATTR, MPFROM2SHORT(ID_PLAY, FALSE),
        MPFROM2SHORT(MIA_DISABLED, MenuFlag));
    WinSendMsg(ControlMenu, MM_SETITEMATTR, MPFROM2SHORT(ID_PAUSE, FALSE),
        MPFROM2SHORT(MIA_DISABLED, MenuFlag));
    WinSendMsg(ControlMenu, MM_SETITEMATTR, MPFROM2SHORT(ID_STOP, FALSE),
        MPFROM2SHORT(MIA_DISABLED, MenuFlag));
    WinSendMsg(ControlMenu, MM_SETITEMATTR, MPFROM2SHORT(ID_REPEAT, FALSE),
        MPFROM2SHORT(MIA_DISABLED, MenuFlag));

    return TRUE;
}

MRESULT CmdChangeTitles(CDAUDIO_CONTENTS *Contents, PSZ TitleAccess)
{
    DLGSTARTDATA StartData;

    if ( TitleEditorInProcess ) {
        if ( Contents != NULL || TitleAccess != NULL )
            WinSendMsg(TitleEditorDlg, TE_SETCURRENT, MPFROMP(Contents), MPFROMP(TitleAccess));
        else
            WinSendMsg(TitleEditorDlg, TE_SETSELECT, NULL, NULL);

        if ( TitleEditorHidden ) {
            WinSetWindowPos(TitleEditorDlg, HWND_TOP, 0, 0, 0, 0, SWP_SHOW | SWP_ACTIVATE);
            TitleEditorHidden = FALSE;
            }
        else {
            WinSetActiveWindow(HWND_DESKTOP, TitleEditorDlg);
            }
        }
    else {
        StartData.cb = sizeof(DLGSTARTDATA);
        if ( Contents != NULL || TitleAccess != NULL ) {
            StartData.msg = TE_SETCURRENT;
            StartData.Contents = Contents;
            StartData.TitleAccess = TitleAccess;
            }
        else {
            StartData.msg = TE_SETSELECT;
            StartData.Contents = NULL;
            StartData.TitleAccess = NULL;
            }

        TitleEditorDlg = WinLoadDlg(HWND_DESKTOP, HWND_DESKTOP,
            TitleEditorDlgProc, 0, ID_DLG_TITLEEDITOR, &StartData);
        }


    return NULL;
}

MRESULT CmdProgramPlayList(CDAUDIO_CONTENTS *Contents, PSZ TitleAccess)
{
    DLGSTARTDATA StartData;

    if ( ProgramEditorInProcess ) {
        WinSendMsg(ProgramEditorDlg, PE_SETCD, MPFROMP(Contents), MPFROMP(TitleAccess));

        if ( ProgramEditorHidden ) {
            WinSetWindowPos(ProgramEditorDlg, HWND_TOP, 0, 0, 0, 0, SWP_SHOW | SWP_ACTIVATE);
            ProgramEditorHidden = FALSE;
            }
        else {
            WinSetActiveWindow(HWND_DESKTOP, ProgramEditorDlg);
            }
        }
    else {
        StartData.cb = sizeof(DLGSTARTDATA);
        StartData.msg = PE_SETCD;
        StartData.Contents = Contents;
        StartData.TitleAccess = TitleAccess;

        ProgramEditorDlg = WinLoadDlg(HWND_DESKTOP, HWND_DESKTOP,
            ProgramEditorDlgProc, 0, ID_DLG_PROGRAMEDITOR, &StartData);
        }

    return NULL;
}

MRESULT CmdOptions(void)
{
    if ( SettingsDlgInProcess ) { 
        if ( SettingsDlgHidden ) { 
            WinSetWindowPos(SettingsDlg, HWND_TOP, 0, 0, 0, 0, SWP_SHOW | SWP_ACTIVATE);
            SettingsDlgHidden = FALSE;
            }
        else {
            WinSetActiveWindow(HWND_DESKTOP, SettingsDlg);
            }
        }
    else {
        SettingsDlg = WinLoadDlg(HWND_DESKTOP, HWND_DESKTOP,
            SettingsDlgProc, 0, ID_DLG_SETTINGS, NULL);
        }
    return NULL;
}

MRESULT CmdInfo(CDAUDIO_CONTENTS *Contents, PSZ TitleAccess)
{
    DLGSTARTDATA StartData;

    if ( InfoInProcess ) {
        WinSendMsg(InfoDlg, IN_SETCD, MPFROMP(Contents), MPFROMP(TitleAccess));

        if ( InfoHidden ) {
            WinSetWindowPos(InfoDlg, HWND_TOP, 0, 0, 0, 0, SWP_SHOW | SWP_ACTIVATE);
            InfoHidden = FALSE;
            }
        else {
            WinSetActiveWindow(HWND_DESKTOP, InfoDlg);
            }
        }
    else {
        StartData.cb = sizeof(DLGSTARTDATA);
        StartData.msg = IN_SETCD;
        StartData.Contents = Contents;
        StartData.TitleAccess = TitleAccess;
        InfoDlg = WinLoadDlg(HWND_DESKTOP, HWND_DESKTOP,
            InfoDlgProc, 0, ID_DLG_INFO, &StartData);
        }

    return NULL;
}

MRESULT EXPENTRY TitleEditorDlgProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2)
{
    static HWND hwndTEScrollbar;
    static HWND hwndTEGroupCD;
    static HWND hwndTEEntryCD;
    static HWND hwndTESelectCD;
    static HWND hwndTEInfoCD;
    static HWND hwndTEGroupTrack;
    static HWND hwndTESelectTrack;
    static HWND hwndTEEntryTrack;
    static HWND hwndTEInfoTrack;
    static HWND hwndTELibrary;
    static HWND hwndTEInfo;
    static HWND hwndTEProgram;
    static HWND hwndTEDelete;
    static HWND hwndTEQuit;
    static HWND hwndTEHelp;
    static ULONG xDiff, yDiff, xSplit, ySplit, EntryH;
    static ULONG HelpWidth;
    static ULONG Dummy;
    static ULONG x, y, cx, cy, State;
    static POINTL MinSize;
    // static ULONG cxMin, cyMin;
    BOOL bResult, NewInd;
    ULONG i;
    static ULONG cxBorder, cyBorder;
    MRESULT mResult;
    static SWP swp[15];
    PSWP PSwp;
    // static CDAUDIO_TITLES CurrTitles;
    static PSZ CurrTitleAccess;
    static CDAUDIO_CONTENTS CurrContents;
    static BOOL LibrarySelect, TitlesFilled, Select, InEntryFocus;
    static char Buffer[MAX_INFO_LENGTH];
    static ULONG CurrSelectedTrack;
    static ULONG CurrSelectedCD;
    static IPT InsertPoint;
    static ULONG Exported;
    static HACCEL TEDlgAccelTable;
    // static HACCEL TEEntryAccelTable;
    static DLGSTARTDATA *StartData;
    // static ULONG BackColor;

    switch ( msg ) {
      case WM_INITDLG :
        TitleEditorInProcess = TRUE;
        TitleEditorHidden = FALSE; 
 
        LibrarySelect = FALSE;
        Select = FALSE;
        InEntryFocus = FALSE;
        CurrTitleAccess = NULL;

        bResult = WinAssociateHelpInstance(hwndMainHelp, hwnd);

        hwndTEScrollbar = WinWindowFromID(hwnd, ID_TE_SCROLLBAR);
        hwndTEGroupCD = WinWindowFromID(hwnd, ID_TE_GROUP_CD);
        hwndTEEntryCD = WinWindowFromID(hwnd, ID_TE_ENTRY_CD);
        hwndTESelectCD = WinWindowFromID(hwnd, ID_TE_SELECT_CD);
        hwndTEInfoCD = WinWindowFromID(hwnd, ID_TE_INFO_CD);
        hwndTEGroupTrack = WinWindowFromID(hwnd, ID_TE_GROUP_TRACK);
        hwndTESelectTrack = WinWindowFromID(hwnd, ID_TE_SELECT_TRACK);
        hwndTEEntryTrack = WinWindowFromID(hwnd, ID_TE_ENTRY_TRACK);
        hwndTEInfoTrack = WinWindowFromID(hwnd, ID_TE_INFO_TRACK);
        hwndTELibrary = WinWindowFromID(hwnd, ID_TE_LIBRARY);
        hwndTEInfo = WinWindowFromID(hwnd, ID_TE_INFO);
        hwndTEProgram = WinWindowFromID(hwnd, ID_TE_PROGRAM);
        hwndTEDelete = WinWindowFromID(hwnd, ID_TE_DELETE);
        hwndTEQuit = WinWindowFromID(hwnd, ID_TE_QUIT);
        hwndTEHelp = WinWindowFromID(hwnd, ID_TE_HELP);

        TEDlgAccelTable = WinLoadAccelTable(hab, NULLHANDLE, ID_DLG_TITLEEDITOR);
        if ( TEDlgAccelTable != NULLHANDLE ) {
            bResult = WinSetAccelTable(hab, TEDlgAccelTable, hwnd);
            }

        /*
        TEEntryAccelTable = WinLoadAccelTable(hab, NULLHANDLE, ID_TE_ENTRY_TRACK);
        if ( TEEntryAccelTable != NULLHANDLE ) {
            bResult = WinSetAccelTable(hab, TEEntryAccelTable, hwndTEEntryTrack);
            }
        */

        // OldTEEntryCDWndProc = WinSubclassWindow(hwndTEEntryTrack, TEEntryTrackWndProc);
        OldTEEntryTrackWndProc = WinSubclassWindow(hwndTEEntryTrack, TEEntryTrackWndProc);

        WinSendMsg(hwndTEEntryCD, EM_SETTEXTLIMIT,
            MPFROMSHORT(MAX_TITLE_LENGTH-1), NULL);

        WinSendMsg(hwndTESelectCD, EM_SETTEXTLIMIT,
            MPFROMSHORT(MAX_TITLE_LENGTH-1), NULL);

        WinSendMsg(hwndTEEntryTrack, EM_SETTEXTLIMIT,
            MPFROMSHORT(MAX_TITLE_LENGTH-1), NULL);

        WinSendMsg(hwndTESelectTrack, EM_SETTEXTLIMIT,
            MPFROMSHORT(MAX_TITLE_LENGTH-1), NULL);

        // BackColor = WinQuerySysColor(HWND_DESKTOP, SYSCLR_ENTRYFIELD, 0);

        // WinSendMsg(hwndTEInfoCD, MLM_SETBACKCOLOR,
        //     MPFROMLONG(BackColor), NULL);
        WinSendMsg(hwndTEInfoCD, MLM_SETTEXTLIMIT,
            MPFROMLONG(MAX_INFO_LENGTH-1), NULL);
        WinSendMsg(hwndTEInfoCD, MLM_FORMAT,
            MPFROMSHORT(MLFIE_CFTEXT), NULL);
        WinSendMsg(hwndTEInfoCD, MLM_SETIMPORTEXPORT,
            MPFROMP(Buffer), MPFROMLONG(sizeof(Buffer)));

        // WinSendMsg(hwndTEInfoTrack, MLM_SETBACKCOLOR,
        //    MPFROMLONG(BackColor), NULL);
        WinSendMsg(hwndTEInfoTrack, MLM_SETTEXTLIMIT,
            MPFROMLONG(MAX_INFO_LENGTH-1), NULL);
        WinSendMsg(hwndTEInfoTrack, MLM_FORMAT,
            MPFROMSHORT(MLFIE_CFTEXT), NULL);
        WinSendMsg(hwndTEInfoTrack, MLM_SETIMPORTEXPORT,
            MPFROMP(Buffer), MPFROMLONG(sizeof(Buffer)));

        bResult = WinQueryWindowPos(hwndTEScrollbar, swp+0);
        bResult = WinQueryWindowPos(hwndTEGroupCD, swp+1);
        bResult = WinQueryWindowPos(hwndTEEntryCD, swp+2);
        bResult = WinQueryWindowPos(hwndTESelectCD, swp+3);
        bResult = WinQueryWindowPos(hwndTEInfoCD, swp+4);
        bResult = WinQueryWindowPos(hwndTEGroupTrack, swp+5);
        bResult = WinQueryWindowPos(hwndTEEntryTrack, swp+6);
        bResult = WinQueryWindowPos(hwndTESelectTrack, swp+7);
        bResult = WinQueryWindowPos(hwndTEInfoTrack, swp+8);
        bResult = WinQueryWindowPos(hwndTELibrary, swp+9);
        bResult = WinQueryWindowPos(hwndTEInfo, swp+10);
        bResult = WinQueryWindowPos(hwndTEProgram, swp+11);
        bResult = WinQueryWindowPos(hwndTEDelete, swp+12);
        bResult = WinQueryWindowPos(hwndTEQuit, swp+13);
        bResult = WinQueryWindowPos(hwndTEHelp, swp+14);

        for ( i = 0; i < 15; i++ ) {
            swp[i].fl = SWP_SIZE | SWP_MOVE | SWP_NOADJUST;
            swp[i].hwndInsertBehind = HWND_TOP;
            }

        cxBorder = WinQuerySysValue(HWND_DESKTOP, SV_CXSIZEBORDER);
        cyBorder = WinQuerySysValue(HWND_DESKTOP, SV_CYSIZEBORDER);

        xDiff = swp[9].x - cxBorder;
        yDiff = swp[9].y - cyBorder;
        xSplit = swp[0].cx + 2 * xDiff;
        ySplit = swp[0].y - cyBorder;
        EntryH = swp[2].cy;

        MinSize.x = 2 * cxBorder + swp[13].x + swp[13].cx + swp[14].cx + 2 * xDiff;
            // (swp[13].x - swp[12].x - swp[12].cx);
        MinSize.y = 2 * cyBorder + ySplit + 6 * EntryH + 8 * yDiff +
            WinQuerySysValue(HWND_DESKTOP, SV_CYTITLEBAR);

        bResult = CDPrfLoadWindowPos(CDWINDOW_TITLES, &x, &y, &cx, &cy, &State);
        if ( bResult ) {
            WinSetWindowPos(hwnd, HWND_TOP, x, y, cx, cy, SWP_MOVE | SWP_SIZE);
            }

        StartData = PVOIDFROMMP(mp2);
        if ( StartData != NULL )
            WinSendMsg(hwnd, StartData->msg, MPFROMP(StartData->Contents),
                MPFROMP(StartData->TitleAccess));

        return NULL;

      case HM_HELPSUBITEM_NOT_FOUND :
        if ( SHORT2FROMMP(mp2) == ID_TE_LIBRARY ) {
            if ( LibrarySelect )
                WinSendMsg(hwndMainHelp, HM_DISPLAY_HELP,
                    MPFROMSHORT(PANEL_TE_CTRL_CHANGE),
                    MPFROMSHORT(HM_RESOURCEID));
            else
                WinSendMsg(hwndMainHelp, HM_DISPLAY_HELP,
                    MPFROMSHORT(PANEL_TE_CTRL_LIBRARY),
                    MPFROMSHORT(HM_RESOURCEID));
            return MRFROMLONG(TRUE);
            }
        else if ( SHORT2FROMMP(mp2) == ID_TE_DELETE ) {
            if ( LibrarySelect )
                WinSendMsg(hwndMainHelp, HM_DISPLAY_HELP,
                    MPFROMSHORT(PANEL_TE_CTRL_DELETE),
                    MPFROMSHORT(HM_RESOURCEID));
            else
                WinSendMsg(hwndMainHelp, HM_DISPLAY_HELP,
                    MPFROMSHORT(PANEL_TE_CTRL_IMPORT),
                    MPFROMSHORT(HM_RESOURCEID));
            return MRFROMLONG(TRUE);
            }
        else if ( IsHelpButton(SHORT2FROMMP(mp2)) ) {
            WinSendMsg(hwndMainHelp, HM_DISPLAY_HELP, NULL, NULL);
            return MRFROMLONG(TRUE);
            }
        else {
            return MRFROMLONG(FALSE);
            }

      case TE_SETSELECT :
        // TitlesFilled = TRUE;
        if ( ! LibrarySelect ) {
            WinSetWindowText(hwnd, TELibraryText);

            if ( CurrTitleAccess != NULL )
                CDPrfReleaseAccess(CurrTitleAccess);
 
            WinShowWindow(hwndTEEntryCD, FALSE);
            WinShowWindow(hwndTESelectCD, TRUE);
            WinShowWindow(hwndTEEntryTrack, FALSE);
            WinShowWindow(hwndTESelectTrack, TRUE);
            WinSendMsg(hwndTEInfoCD, MLM_SETREADONLY, MPFROMSHORT(TRUE), NULL);
            WinSendMsg(hwndTEInfoTrack, MLM_SETREADONLY, MPFROMSHORT(TRUE), NULL);
            WinSetWindowText(hwndTELibrary, ChangeText);
            WinSetWindowText(hwndTEDelete, DeleteText);
            // WinEnableWindow(hwndTEDelete, TRUE);
            LibrarySelect = TRUE;
            }
            
        WinSendMsg(hwndTESelectCD, LM_DELETEALL, NULL, NULL);
        CurrTitleAccess = CDPrfQueryAccessByTitle(NULL, FALSE, Buffer, sizeof(Buffer));

        if ( CurrTitleAccess != NULL ) {
            while ( CurrTitleAccess != NULL ) {
                Dummy = SHORT1FROMMR(WinSendMsg(hwndTESelectCD, LM_INSERTITEM,
                    MPFROMSHORT(LIT_SORTASCENDING), Buffer));
 
                WinSendMsg(hwndTESelectCD, LM_SETITEMHANDLE, MPFROMSHORT(Dummy),
                    MPFROMP(CurrTitleAccess));
 
                CurrTitleAccess = CDPrfQueryAccessByTitle(NULL, TRUE, Buffer, sizeof(Buffer));
                }

            CurrSelectedCD = -1;
            WinSendMsg(hwnd, TE_SELECTCD, MPFROMLONG(0), NULL);
            }
        else {
            CurrSelectedCD = 0;
            WinSendMsg(hwnd, TE_SELECTCD, MPFROMLONG(-1), NULL);
            }
        return NULL;

      case TE_SETCURRENT :
        NewInd = FALSE;

        if ( PVOIDFROMMP(mp1) != NULL ) {
            if ( CurrTitleAccess != NULL ) {
                NewInd = (strcmp(CurrTitleAccess, PVOIDFROMMP(mp2)) != 0);
                CDPrfReleaseAccess(CurrTitleAccess);
                }
            else {
                NewInd = TRUE;
                }

            CurrTitleAccess = CDPrfCopyAccess((PSZ)PVOIDFROMMP(mp2));

            memcpy(&CurrContents, PVOIDFROMMP(mp1),
                CONTENTS_SIZE(*(CDAUDIO_CONTENTS *)PVOIDFROMMP(mp1)));
            }

        if ( LibrarySelect ) {
            WinSetWindowText(hwnd, TEChangeText);
            if ( CurrSelectedCD == (ULONG)-1 ) {
                // WinEnableWindow(hwndTEScrollbar, TRUE);
                // WinEnableWindow(hwndTEInfoCD, TRUE);
                // WinEnableWindow(hwndTESelectTrack, TRUE);
                // WinEnableWindow(hwndTEInfoTrack, TRUE);
                WinEnableWindow(hwndTELibrary, TRUE);
                WinEnableWindow(hwndTEInfo, TRUE);
                WinEnableWindow(hwndTEProgram, TRUE);
                WinEnableWindow(hwndTEDelete, TRUE);
                }

            CurrTitleAccess = CDPrfCopyAccess(CurrTitleAccess);
            Dummy = SHORT1FROMMR(WinSendMsg(hwndTESelectCD, LM_QUERYITEMCOUNT, NULL, NULL));
            for ( i = 0; i < Dummy; i++ ) {
                CDPrfReleaseAccess((PSZ)PVOIDFROMMR(WinSendMsg(hwndTESelectCD,
                    LM_QUERYITEMHANDLE, MPFROMSHORT(i), NULL)));
                }

            WinShowWindow(hwndTESelectCD, FALSE);
            WinShowWindow(hwndTESelectTrack, FALSE);
            WinSendMsg(hwndTEInfoCD, MLM_SETREADONLY, MPFROMSHORT(FALSE), NULL);
            WinSendMsg(hwndTEInfoTrack, MLM_SETREADONLY, MPFROMSHORT(FALSE), NULL);
            WinSetWindowText(hwndTELibrary, LibraryText);
            WinSetWindowText(hwndTEDelete, ImportText);
            // WinEnableWindow(hwndTEDelete, FALSE);
            LibrarySelect = FALSE;
            }

        if ( NewInd ) {
            WinSendMsg(hwndTEInfoCD, MLM_DELETE, MPFROMLONG(0),
                MPFROMLONG(sizeof(Buffer)));

            bResult = CDPrfQueryCDInfo(CurrTitleAccess, Buffer, sizeof(Buffer));
            if ( bResult ) {
                InsertPoint = 0;
                WinSendMsg(hwndTEInfoCD, MLM_IMPORT, MPFROMP(&InsertPoint),
                    MPFROMLONG(strlen(Buffer)));
                }

            WinSendMsg(hwndTEScrollbar, LM_DELETEALL, NULL, NULL);

            if ( ! ListBoxAnimation )
                WinEnableWindowUpdate(hwndTEScrollbar, FALSE);

            for ( i = 0; i < CurrContents.TotalTracks; i++ ) {
                WinSendMsg(hwndTEScrollbar, LM_INSERTITEM, MPFROMSHORT(i),
                    MPFROMP(itoa(i+1, Buffer, 10)));
                }

            if ( ! ListBoxAnimation )
                WinEnableWindowUpdate(hwndTEScrollbar, TRUE);
            }

        CDPrfQueryCDTitle(CurrTitleAccess, Buffer, sizeof(Buffer));
        WinSetWindowText(hwndTEEntryCD, Buffer);
        WinSendMsg(hwndTEEntryCD, EM_QUERYCHANGED, NULL, NULL);
        WinSendMsg(hwndTEInfoCD, MLM_SETCHANGED, MPFROMSHORT(FALSE), NULL);

        if ( NewInd ) {
            WinSendMsg(hwnd, TE_SELECTTRACK, MPFROMLONG(1), NULL);
            }
        else {
            CDPrfQueryTrackTitle(CurrTitleAccess, Buffer, sizeof(Buffer), CurrSelectedTrack);
            WinSetWindowText(hwndTEEntryTrack, Buffer);
            }
            
        WinShowWindow(hwndTEEntryCD, TRUE);
        WinShowWindow(hwndTEEntryTrack, TRUE);
        return NULL;

      case TE_SELECTCD :
        Select = TRUE;

        if ( LONGFROMMP(mp1) != (ULONG)-1 ) {
            if ( CurrSelectedCD == (ULONG)-1 ) {
                // WinEnableWindow(hwndTEScrollbar, TRUE);
                // WinEnableWindow(hwndTEInfoCD, TRUE);
                // WinEnableWindow(hwndTESelectTrack, TRUE);
                // WinEnableWindow(hwndTEInfoTrack, TRUE);
                WinEnableWindow(hwndTELibrary, TRUE);
                WinEnableWindow(hwndTEInfo, TRUE);
                WinEnableWindow(hwndTEProgram, TRUE);
                WinEnableWindow(hwndTEDelete, TRUE);
                }

            CurrSelectedCD = LONGFROMMP(mp1);
            WinSendMsg(hwndTESelectCD, LM_SELECTITEM,
                MPFROMSHORT(CurrSelectedCD), MPFROMLONG(TRUE));
 
            CurrTitleAccess = (PSZ)PVOIDFROMMR(WinSendMsg(hwndTESelectCD, LM_QUERYITEMHANDLE,
                MPFROMSHORT(CurrSelectedCD), NULL));
 
            CDPrfQueryContents(CurrTitleAccess, &CurrContents);
 
            WinSendMsg(hwndTEInfoCD, MLM_DELETE, MPFROMLONG(0),
                MPFROMLONG(sizeof(Buffer)));
 
            bResult = CDPrfQueryCDInfo(CurrTitleAccess, Buffer, sizeof(Buffer));
            if ( bResult ) {
                InsertPoint = 0;
                WinSendMsg(hwndTEInfoCD, MLM_IMPORT, MPFROMP(&InsertPoint),
                    MPFROMLONG(strlen(Buffer)));
                }
 
            if ( ! ListBoxAnimation )
                WinEnableWindowUpdate(hwndTEScrollbar, FALSE);
 
            WinSendMsg(hwndTEScrollbar, LM_DELETEALL, NULL, NULL);
            WinSendMsg(hwndTESelectTrack, LM_DELETEALL, NULL, NULL);
 
            for ( i = 0; i < CurrContents.TotalTracks; i++ ) {
                WinSendMsg(hwndTEScrollbar, LM_INSERTITEM, MPFROMSHORT(i),
                    MPFROMP(itoa(i+1, Buffer, 10)));
                CDPrfQueryTrackTitle(CurrTitleAccess, Buffer, sizeof(Buffer), i+1);
                WinSendMsg(hwndTESelectTrack, LM_INSERTITEM, MPFROMSHORT(i), Buffer);
                }
 
            if ( ! ListBoxAnimation )
                WinEnableWindowUpdate(hwndTEScrollbar, TRUE);
            WinSendMsg(hwnd, TE_SELECTTRACK, MPFROMLONG(1), NULL);
            }
        else {
            if ( CurrSelectedCD != (ULONG)-1 ) {
                // WinEnableWindow(hwndTEScrollbar, FALSE);
                // WinEnableWindow(hwndTEInfoCD, FALSE);
                // WinEnableWindow(hwndTESelectTrack, FALSE);
                // WinEnableWindow(hwndTEInfoTrack, FALSE);
                WinEnableWindow(hwndTELibrary, FALSE);
                WinEnableWindow(hwndTEInfo, FALSE);
                WinEnableWindow(hwndTEProgram, FALSE);
                WinEnableWindow(hwndTEDelete, FALSE);
                }

            CurrSelectedCD = LONGFROMMP(mp1);
            WinSendMsg(hwndTESelectCD, LM_SELECTITEM,
                MPFROMSHORT(LIT_NONE), MPFROMLONG(TRUE));

            CurrTitleAccess = NULL;

            WinSendMsg(hwndTEInfoCD, MLM_DELETE, MPFROMLONG(0),
                MPFROMLONG(sizeof(Buffer)));
            WinSendMsg(hwndTEScrollbar, LM_DELETEALL, NULL, NULL);
            WinSetWindowText(hwndTESelectTrack, "");
            WinSendMsg(hwndTESelectTrack, LM_DELETEALL, NULL, NULL);
            WinSendMsg(hwndTEInfoTrack, MLM_DELETE, MPFROMLONG(0),
                MPFROMLONG(sizeof(Buffer)));
            }
        Select = FALSE;
        return NULL;

      case TE_SELECTTRACK :
        Select = TRUE;
        CurrSelectedTrack = LONGFROMMP(mp1);
                
        if ( CurrSelectedTrack < 1 )
            CurrSelectedTrack = 1;
        else if ( CurrSelectedTrack > CurrContents.TotalTracks )
            CurrSelectedTrack = CurrContents.TotalTracks;

        WinSendMsg(hwndTEScrollbar, LM_SELECTITEM,
            MPFROMSHORT(CurrSelectedTrack-1), MPFROMLONG(TRUE));

        if ( LibrarySelect ) {
            WinSendMsg(hwndTESelectTrack, LM_SELECTITEM,
                MPFROMSHORT(CurrSelectedTrack-1), MPFROMLONG(TRUE));
            }
        else {
            CDPrfQueryTrackTitle(CurrTitleAccess, Buffer, sizeof(Buffer), CurrSelectedTrack);
            WinSetWindowText(hwndTEEntryTrack, Buffer);
            }

        WinSendMsg(hwndTEInfoTrack, MLM_DELETE, MPFROMLONG(0),
            MPFROMLONG(sizeof(Buffer)));
        bResult = CDPrfQueryTrackInfo(CurrTitleAccess, Buffer, sizeof(Buffer), 
            CurrSelectedTrack);
        if ( bResult ) {
            InsertPoint = 0;
            WinSendMsg(hwndTEInfoTrack, MLM_IMPORT, MPFROMP(&InsertPoint),
                MPFROMLONG(strlen(Buffer)));
            }

        if ( ! LibrarySelect ) {
            WinSendMsg(hwndTEEntryTrack, EM_QUERYCHANGED, NULL, NULL);
            WinSendMsg(hwndTEInfoTrack, MLM_SETCHANGED, MPFROMSHORT(FALSE), NULL);
            }

        Select = FALSE;
        return NULL;

      case WM_CONTROL :
        switch ( SHORT1FROMMP(mp1) ) {
          case ID_TE_ENTRY_CD :
            if ( ! LibrarySelect && SHORT2FROMMP(mp1) == EN_KILLFOCUS &&
                 WinSendMsg(hwndTEEntryCD, EM_QUERYCHANGED, NULL, NULL) ) {
                SetWaitPointer(TRUE);
                WinQueryWindowText(hwndTEEntryCD, sizeof(Buffer), Buffer);
                CDPrfSetCDTitle(CurrTitleAccess, Buffer);
                SetWaitPointer(FALSE);
                }
            break;

          case ID_TE_INFO_CD :
            if ( ! LibrarySelect && SHORT2FROMMP(mp1) == MLN_KILLFOCUS &&
                 WinSendMsg(hwndTEInfoCD, MLM_QUERYCHANGED, NULL, NULL) ) {
                SetWaitPointer(TRUE);
                WinSendMsg(hwndTEInfoCD, MLM_SETCHANGED, MPFROMSHORT(FALSE), NULL);
                InsertPoint = 0;
                Exported = sizeof(Buffer);
                Dummy = LONGFROMMR(WinSendMsg(hwndTEInfoCD, MLM_EXPORT, MPFROMP(&InsertPoint),
                    MPFROMP(&Exported)));
                Buffer[Dummy] = 0;
                CDPrfSetCDInfo(CurrTitleAccess, Buffer);
                SetWaitPointer(FALSE);
                }
            break;

          case ID_TE_ENTRY_TRACK :
            if ( ! LibrarySelect && SHORT2FROMMP(mp1) == EN_KILLFOCUS &&
                 WinSendMsg(hwndTEEntryTrack, EM_QUERYCHANGED, NULL, NULL) ) {
                SetWaitPointer(TRUE);
                WinQueryWindowText(hwndTEEntryTrack, sizeof(Buffer), Buffer);
                CDPrfSetTrackTitle(CurrTitleAccess, Buffer, CurrSelectedTrack);
                SetWaitPointer(FALSE);
                }
            break;

          case ID_TE_INFO_TRACK :
            if ( ! LibrarySelect && SHORT2FROMMP(mp1) == MLN_KILLFOCUS &&
                 WinSendMsg(hwndTEInfoTrack, MLM_QUERYCHANGED, NULL, NULL) ) {
                SetWaitPointer(TRUE);
                WinSendMsg(hwndTEInfoTrack, MLM_SETCHANGED, MPFROMSHORT(FALSE), NULL);
                InsertPoint = 0;
                Exported = sizeof(Buffer);
                Dummy = LONGFROMMR(WinSendMsg(hwndTEInfoTrack, MLM_EXPORT, MPFROMP(&InsertPoint),
                    MPFROMP(&Exported)));
                Buffer[Dummy] = 0;
                CDPrfSetTrackInfo(CurrTitleAccess, Buffer, CurrSelectedTrack);
                SetWaitPointer(FALSE);
                }
            break;

          case ID_TE_SCROLLBAR :
            if ( SHORT2FROMMP(mp1) == LN_SELECT && ! Select ) {
                WinSendMsg(hwnd, TE_SELECTTRACK, MPFROMSHORT(
                    SHORT1FROMMR(WinSendMsg(hwndTEScrollbar,
                    LM_QUERYSELECTION, MPFROMSHORT(LIT_FIRST), NULL)) + 1), NULL);
                }
            else if ( SHORT2FROMMP(mp1) == LN_ENTER && ! Select && ! LibrarySelect ) {
                WinSetFocus(HWND_DESKTOP, hwndTEEntryTrack);
                }
            break;

          case ID_TE_SELECT_TRACK :
            if ( SHORT2FROMMP(mp1) == CBN_LBSELECT && ! Select ) {
                WinSendMsg(hwnd, TE_SELECTTRACK, MPFROMSHORT(
                    SHORT1FROMMR(WinSendMsg(hwndTESelectTrack,
                    LM_QUERYSELECTION, MPFROMSHORT(LIT_FIRST), NULL)) + 1), NULL);
                }
            break;

          case ID_TE_SELECT_CD :
            if ( SHORT2FROMMP(mp1) == CBN_LBSELECT && ! Select ) {
                WinSendMsg(hwnd, TE_SELECTCD, MPFROMSHORT(
                    SHORT1FROMMR(WinSendMsg(hwndTESelectCD,
                    LM_QUERYSELECTION, MPFROMSHORT(LIT_FIRST), NULL))), NULL);
                }
            break;
            }
        return NULL;

      case WM_COMMAND :
        switch ( SHORT1FROMMP(mp1) ) {
          case ID_TE_LIBRARY :
            if ( LibrarySelect && CurrSelectedCD != (ULONG)-1 )
                WinSendMsg(hwnd, TE_SETCURRENT, NULL, NULL);
            else
                WinSendMsg(hwnd, TE_SETSELECT, NULL, NULL);
            break;

          case ID_TE_QUIT :
            WinSendMsg(hwndMainHelp, HM_DISMISS_WINDOW, NULL, NULL);
            WinSetWindowPos(hwnd, HWND_TOP, 0, 0, 0, 0, SWP_HIDE);
            TitleEditorHidden = TRUE;
            WinSetFocus(HWND_DESKTOP, hwndDlg);
            break;

          case ID_TE_INFO_TRACK :
            if ( ! LibrarySelect ) {
                SetWaitPointer(TRUE);
                if ( WinSendMsg(hwndTEEntryTrack, EM_QUERYCHANGED, NULL, NULL) ) {
                    WinQueryWindowText(hwndTEEntryTrack, sizeof(Buffer), Buffer);
                    CDPrfSetTrackTitle(CurrTitleAccess, Buffer, CurrSelectedTrack);
                    }
                
                if ( WinSendMsg(hwndTEInfoTrack, MLM_QUERYCHANGED, NULL, NULL) ) {
                    WinSendMsg(hwndTEInfoTrack, MLM_SETCHANGED, MPFROMSHORT(FALSE), NULL);
                    InsertPoint = 0;
                    Exported = sizeof(Buffer);
                    Dummy = LONGFROMMR(WinSendMsg(hwndTEInfoTrack, MLM_EXPORT, MPFROMP(&InsertPoint),
                        MPFROMP(&Exported)));
                    Buffer[Dummy] = 0;
                    CDPrfSetTrackInfo(CurrTitleAccess, Buffer, CurrSelectedTrack);
                    }

                WinSendMsg(hwnd, TE_SELECTTRACK, MPFROMLONG(CurrSelectedTrack+1), NULL);
                SetWaitPointer(FALSE);
                }

            break;

          case ID_TE_UP :
            if ( ! LibrarySelect ) {
                SetWaitPointer(TRUE);
                if ( WinSendMsg(hwndTEEntryTrack, EM_QUERYCHANGED, NULL, NULL) ) {
                    WinQueryWindowText(hwndTEEntryTrack, sizeof(Buffer), Buffer);
                    CDPrfSetTrackTitle(CurrTitleAccess, Buffer, CurrSelectedTrack);
                    }

                if ( WinSendMsg(hwndTEInfoTrack, MLM_QUERYCHANGED, NULL, NULL) ) {
                    WinSendMsg(hwndTEInfoTrack, MLM_SETCHANGED, MPFROMSHORT(FALSE), NULL);
                    InsertPoint = 0;
                    Exported = sizeof(Buffer);
                    Dummy = LONGFROMMR(WinSendMsg(hwndTEInfoTrack, MLM_EXPORT, MPFROMP(&InsertPoint),
                        MPFROMP(&Exported)));
                    Buffer[Dummy] = 0;
                    CDPrfSetTrackInfo(CurrTitleAccess, Buffer, CurrSelectedTrack);
                    }

                WinSendMsg(hwnd, TE_SELECTTRACK, MPFROMLONG(CurrSelectedTrack-1), NULL);
                SetWaitPointer(FALSE);
                }
            break;

          case ID_TE_DOWN :
            if ( ! LibrarySelect ) {
                SetWaitPointer(TRUE);
                if ( WinSendMsg(hwndTEEntryTrack, EM_QUERYCHANGED, NULL, NULL) ) {
                    WinQueryWindowText(hwndTEEntryTrack, sizeof(Buffer), Buffer);
                    CDPrfSetTrackTitle(CurrTitleAccess, Buffer, CurrSelectedTrack);
                    }

                if ( WinSendMsg(hwndTEInfoTrack, MLM_QUERYCHANGED, NULL, NULL) ) {
                    WinSendMsg(hwndTEInfoTrack, MLM_SETCHANGED, MPFROMSHORT(FALSE), NULL);
                    InsertPoint = 0;
                    Exported = sizeof(Buffer);
                    Dummy = LONGFROMMR(WinSendMsg(hwndTEInfoTrack, MLM_EXPORT, MPFROMP(&InsertPoint),
                        MPFROMP(&Exported)));
                    Buffer[Dummy] = 0;
                    CDPrfSetTrackInfo(CurrTitleAccess, Buffer, CurrSelectedTrack);
                    }

                WinSendMsg(hwnd, TE_SELECTTRACK, MPFROMLONG(CurrSelectedTrack+1), NULL);
                SetWaitPointer(FALSE);
                }
            break;

          case ID_TE_HOME :
            if ( ! LibrarySelect ) {
                SetWaitPointer(TRUE);
                if ( WinSendMsg(hwndTEEntryTrack, EM_QUERYCHANGED, NULL, NULL) ) {
                    WinQueryWindowText(hwndTEEntryTrack, sizeof(Buffer), Buffer);
                    CDPrfSetTrackTitle(CurrTitleAccess, Buffer, CurrSelectedTrack);
                    }

                if ( WinSendMsg(hwndTEInfoTrack, MLM_QUERYCHANGED, NULL, NULL) ) {
                    WinSendMsg(hwndTEInfoTrack, MLM_SETCHANGED, MPFROMSHORT(FALSE), NULL);
                    InsertPoint = 0;
                    Exported = sizeof(Buffer);
                    Dummy = LONGFROMMR(WinSendMsg(hwndTEInfoTrack, MLM_EXPORT, MPFROMP(&InsertPoint),
                        MPFROMP(&Exported)));
                    Buffer[Dummy] = 0;
                    CDPrfSetTrackInfo(CurrTitleAccess, Buffer, CurrSelectedTrack);
                    }

                WinSendMsg(hwnd, TE_SELECTTRACK, MPFROMLONG(1), NULL);
                SetWaitPointer(FALSE);
                }
            break;

          case ID_TE_END :
            if ( ! LibrarySelect ) {
                SetWaitPointer(TRUE);
                if ( WinSendMsg(hwndTEEntryTrack, EM_QUERYCHANGED, NULL, NULL) ) {
                    WinQueryWindowText(hwndTEEntryTrack, sizeof(Buffer), Buffer);
                    CDPrfSetTrackTitle(CurrTitleAccess, Buffer, CurrSelectedTrack);
                    }

                if ( WinSendMsg(hwndTEInfoTrack, MLM_QUERYCHANGED, NULL, NULL) ) {
                    WinSendMsg(hwndTEInfoTrack, MLM_SETCHANGED, MPFROMSHORT(FALSE), NULL);
                    InsertPoint = 0;
                    Exported = sizeof(Buffer);
                    Dummy = LONGFROMMR(WinSendMsg(hwndTEInfoTrack, MLM_EXPORT, MPFROMP(&InsertPoint),
                        MPFROMP(&Exported)));
                    Buffer[Dummy] = 0;
                    CDPrfSetTrackInfo(CurrTitleAccess, Buffer, CurrSelectedTrack);
                    }

                WinSendMsg(hwnd, TE_SELECTTRACK, MPFROMLONG(CurrContents.TotalTracks), NULL);
                SetWaitPointer(FALSE);
                }
            break;

          case ID_TE_INFO :
            if ( ! LibrarySelect || CurrSelectedCD != (ULONG)-1 )
                CmdInfo(&CurrContents, CurrTitleAccess);
            break;

          case ID_TE_PROGRAM :
            if ( ! LibrarySelect || CurrSelectedCD != (ULONG)-1 ) {
                CmdProgramPlayList(&CurrContents, CurrTitleAccess);
                }
            break;

          case ID_TE_DELETE :
            if ( LibrarySelect && CurrSelectedCD != (ULONG)-1 ) {
                if ( AreYouSure(hwnd, CDDeleteText) ) {
                    SetWaitPointer(TRUE);
                    WinSetWindowText(hwndTESelectCD, "");
                    WinSendMsg(hwndTESelectCD, LM_DELETEITEM, MPFROMSHORT(CurrSelectedCD),
                        NULL);
                    CDPrfDeleteAccess(CurrTitleAccess);
                    WinSendMsg(hwnd, TE_SELECTCD, MPFROMLONG(-1), NULL);
                    SetWaitPointer(FALSE);
                    }
                }
            else if ( ! LibrarySelect ) {
                /*
                static FILEDLG FileDlg;
                FileDlg.cbSize = sizeof(FILEDLG);
                FileDlg.fl = FDS_SAVEAS_DIALOG | FDS_HELPBUTTON | FDS_PRELOAD_VOLINFO;
                FileDlg.ulUser = 0;
                FileDlg.pszTitle = "CD Bibliothek exportieren";
                FileDlg.pszOKButton = NULL;
                FileDlg.pfnDlgProc = NULL;
                FileDlg.pszIType = NULL;
                FileDlg.papszITypeList = NULL;
                FileDlg.pszIDrive = 0;
                FileDlg.papszIDriveList = NULL;
                FileDlg.hMod = NULLHANDLE;
                strcpy(FileDlg.szFullFile, "*.CDL");
                FileDlg.papszFQFilename = NULL;
                FileDlg.ulFQFCount = 0;
                FileDlg.usDlgId = 0;
                FileDlg.x = 0;
                FileDlg.y = 0;
                FileDlg.sEAType = 0;
                bResult = (BOOL)WinFileDlg(hwnd, hwnd, &FileDlg);
                */
                }
            break;

          case ID_TE_ENTER :
            if ( ! LibrarySelect ) {
                SetWaitPointer(TRUE);
                if ( WinSendMsg(hwndTEEntryTrack, EM_QUERYCHANGED, NULL, NULL) ) {
                    WinQueryWindowText(hwndTEEntryTrack, sizeof(Buffer), Buffer);
                    CDPrfSetTrackTitle(CurrTitleAccess, Buffer, CurrSelectedTrack);
                    }

                if ( WinSendMsg(hwndTEInfoTrack, MLM_QUERYCHANGED, NULL, NULL) ) {
                    WinSendMsg(hwndTEInfoTrack, MLM_SETCHANGED, MPFROMSHORT(FALSE), NULL);
                    InsertPoint = 0;
                    Exported = sizeof(Buffer);
                    Dummy = LONGFROMMR(WinSendMsg(hwndTEInfoTrack, MLM_EXPORT, MPFROMP(&InsertPoint),
                        MPFROMP(&Exported)));
                    Buffer[Dummy] = 0;
                    CDPrfSetTrackInfo(CurrTitleAccess, Buffer, CurrSelectedTrack);
                    }

                if ( CurrSelectedTrack < CurrContents.TotalTracks )
                    WinSendMsg(hwnd, TE_SELECTTRACK, MPFROMLONG(CurrSelectedTrack+1), NULL);
                else
                    WinSendMsg(hwnd, TE_SELECTTRACK, MPFROMLONG(1), NULL);
                SetWaitPointer(FALSE);
                }
            break;

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
        return MRFROMSHORT(PANEL_TE_KEYBOARD);

      case WM_CLOSE :
        WinSendMsg(hwndMainHelp, HM_DISMISS_WINDOW, NULL, NULL);
        WinSetWindowPos(hwnd, HWND_TOP, 0, 0, 0, 0, SWP_HIDE);
        TitleEditorHidden = TRUE;
        WinSetFocus(HWND_DESKTOP, hwndDlg);
        return NULL;

      case WM_DESTROY :
        if ( TEDlgAccelTable != NULLHANDLE ) {
            bResult = WinDestroyAccelTable(TEDlgAccelTable);
            }
        /*
        if ( TEEntryAccelTable != NULLHANDLE ) {
            bResult = WinDestroyAccelTable(TEEntryAccelTable);
            }
        */
        return NULL;

      case WM_ADJUSTWINDOWPOS :
        PSwp = (PSWP)PVOIDFROMMP(mp1); 
        if ( PSwp->fl & SWP_SIZE) {
            PSwp->cx = max(PSwp->cx, MinSize.x);
            PSwp->cy = max(PSwp->cy, MinSize.y);
            }
        return WinDefDlgProc(hwnd, msg, mp1, mp2);

      case WM_TRACKFRAME :
        return MRFROMLONG(TrackFrameRestricted(hwnd, LONGFROMMP(mp1), &MinSize, NULL));

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
        // WinEnableWindowUpdate(hwnd, FALSE);
        if ( PSwp->fl & SWP_SIZE ) {
            WinEnableWindowUpdate(hwndTEScrollbar, FALSE);
            WinEnableWindowUpdate(hwndTEGroupCD, FALSE);
            if ( LibrarySelect ) {
                WinEnableWindowUpdate(hwndTESelectCD, FALSE);
                WinEnableWindowUpdate(hwndTESelectTrack, FALSE);
                }
            else {
                WinEnableWindowUpdate(hwndTEEntryCD, FALSE);
                WinEnableWindowUpdate(hwndTEEntryTrack, FALSE);
                }
            WinEnableWindowUpdate(hwndTEInfoCD, FALSE);
            WinEnableWindowUpdate(hwndTEGroupTrack, FALSE);
            WinEnableWindowUpdate(hwndTEInfoTrack, FALSE);
            WinEnableWindowUpdate(hwndTELibrary, FALSE);
            WinEnableWindowUpdate(hwndTEInfo, FALSE);
            WinEnableWindowUpdate(hwndTEDelete, FALSE);
            WinEnableWindowUpdate(hwndTEQuit, FALSE);
            WinEnableWindowUpdate(hwndTEHelp, FALSE);
            }
        mResult = WinDefDlgProc(hwnd, msg, mp1, mp2);

        if ( SaveWindowPos && TitleEditorInProcess && (PSwp->fl & (SWP_MOVE | SWP_SIZE)) ) {
            if ( PSwp->fl & (SWP_MINIMIZE | SWP_HIDE) ) {
                }
            else {
                CDPrfSaveWindowPos(CDWINDOW_TITLES, PSwp->x, PSwp->y, PSwp->cx, PSwp->cy,
                    WINDOWSTATE_NORMAL);
                }
            }

        if ( PSwp->fl & (SWP_HIDE | SWP_MINIMIZE) ) {
            WinSendMsg(hwndMainHelp, HM_DISMISS_WINDOW, NULL, NULL);
            TitleEditorHidden = TRUE;
            WinSetFocus(HWND_DESKTOP, hwndDlg);
            }
        else if ( PSwp->fl & SWP_SIZE ) { 
            cxBorder = WinQuerySysValue(HWND_DESKTOP, SV_CXSIZEBORDER);
            cyBorder = WinQuerySysValue(HWND_DESKTOP, SV_CYSIZEBORDER);

            cx = PSwp->cx - 2 * cxBorder;
            cy = PSwp->cy - 2 * cyBorder
                          - WinQuerySysValue(HWND_DESKTOP, SV_CYMENU),

            swp[0].x = cxBorder + xDiff;
            swp[0].y = cyBorder + ySplit;
            swp[0].cx = xSplit - 2 * xDiff;
            swp[0].cy = cy - ySplit - yDiff;

            swp[1].x = cxBorder + xSplit;
            swp[1].y = cyBorder + ySplit + (cy - ySplit) / 2;
            swp[1].cx = cx - xSplit - xDiff;
            swp[1].cy = (cy - ySplit) / 2;

            swp[2].x = cxBorder + xSplit + xDiff;
            swp[2].y = cyBorder + cy - 2 * yDiff - EntryH;
            swp[2].cx = cx - xSplit - 3 * xDiff;
            swp[2].cy = EntryH;

            swp[3].x = cxBorder + xSplit + xDiff;
            swp[3].y = cyBorder + ySplit + (cy - ySplit) / 2; // + yDiff;
            swp[3].cx = cx - xSplit - 3 * xDiff;
            swp[3].cy = (cy - ySplit) / 2 - 2 * yDiff;

            swp[4].x = cxBorder + xSplit + xDiff;
            swp[4].y = cyBorder + ySplit + (cy - ySplit) / 2 + yDiff;
            swp[4].cx = cx - xSplit - 3 * xDiff;
            swp[4].cy = (cy - ySplit) / 2 - 4 * yDiff - EntryH;
 
            swp[5].x = cxBorder + xSplit;
            swp[5].y = cyBorder + ySplit;
            swp[5].cx = cx - xSplit - xDiff;
            swp[5].cy = (cy - ySplit) / 2;

            swp[6].x = cxBorder + xSplit + xDiff;
            swp[6].y = cyBorder + ySplit + (cy - ySplit) / 2 - 2 * yDiff - EntryH;
            swp[6].cx = cx - xSplit - 3 * xDiff;
            swp[6].cy = EntryH;

            swp[7].x = cxBorder + xSplit + xDiff;
            swp[7].y = cyBorder + ySplit; // + yDiff;
            swp[7].cx = cx - xSplit - 3 * xDiff;
            swp[7].cy = (cy - ySplit) / 2 - 2 * yDiff;

            swp[8].x = cxBorder + xSplit + xDiff;
            swp[8].y = cyBorder + ySplit + yDiff;
            swp[8].cx = cx - xSplit - 3 * xDiff;
            swp[8].cy = (cy - ySplit) / 2 - 4 * yDiff - EntryH;
 
            swp[14].x = cxBorder + cx - swp[14].cx - xDiff;

            // bResult = WinEnableWindowUpdate(hwnd, FALSE);
            bResult = WinSetMultWindowPos(hab, swp, 15);
            // bResult = WinEnableWindowUpdate(hwnd, TRUE);
            // bResult = WinShowWindow(hwnd, TRUE);

            WinEnableWindowUpdate(hwndTEScrollbar, TRUE);
            WinEnableWindowUpdate(hwndTEGroupCD, TRUE);
            if ( LibrarySelect ) {
                WinEnableWindowUpdate(hwndTESelectCD, TRUE);
                WinEnableWindowUpdate(hwndTESelectTrack, TRUE);
                }
            else {
                WinEnableWindowUpdate(hwndTEEntryCD, TRUE);
                WinEnableWindowUpdate(hwndTEEntryTrack, TRUE);
                }

            WinEnableWindowUpdate(hwndTEInfoCD, TRUE);
            WinEnableWindowUpdate(hwndTEGroupTrack, TRUE);
            WinEnableWindowUpdate(hwndTEInfoTrack, TRUE);
            WinEnableWindowUpdate(hwndTELibrary, TRUE);
            WinEnableWindowUpdate(hwndTEInfo, TRUE);
            WinEnableWindowUpdate(hwndTEDelete, TRUE);
            WinEnableWindowUpdate(hwndTEQuit, TRUE);
            WinEnableWindowUpdate(hwndTEHelp, TRUE);
            }

        // WinEnableWindowUpdate(hwnd, TRUE);
        return mResult;

      default :
        return WinDefDlgProc(hwnd, msg, mp1, mp2);
        }
}

/*
MRESULT EXPENTRY TEEntryCDWndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2)
{
    switch ( msg ) {
      case WM_CHAR :
        if ( (SHORT1FROMMP(mp1) & KC_VIRTUALKEY) &&
             ! (SHORT1FROMMP(mp1) & KC_KEYUP) ) {
            switch ( SHORT2FROMMP(mp2) ) {
              case VK_ENTER :
              case VK_NEWLINE :
                if ( ! (SHORT1FROMMP(mp1) & KC_ALT) ) {
                    WinSendMsg(TitleEditorDlg, WM_COMMAND,
                       MPFROMSHORT(ID_TE_ENTER), MPFROM2SHORT(CMDSRC_OTHER, FALSE));

                    return MPFROMLONG(TRUE);
                    }
                break;
                }
            }
        break;
        }

    return OldTEEntryCDWndProc(hwnd, msg, mp1, mp2);
}
*/

MRESULT EXPENTRY TEEntryTrackWndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2)
{
    switch ( msg ) {
      case WM_CHAR :
        if ( (SHORT1FROMMP(mp1) & KC_VIRTUALKEY) &&
             ! (SHORT1FROMMP(mp1) & KC_KEYUP) ) {
            switch ( SHORT2FROMMP(mp2) ) {
              case VK_DOWN :
                if ( ! (SHORT1FROMMP(mp1) & (KC_ALT | KC_SHIFT)) ) {
                    if ( (SHORT1FROMMP(mp1) & (KC_CTRL)) ) {
                        WinSendMsg(TitleEditorDlg, WM_COMMAND, 
                            MPFROMSHORT(ID_TE_END), MPFROM2SHORT(CMDSRC_OTHER, FALSE));
                        }
                    else {
                        WinSendMsg(TitleEditorDlg, WM_COMMAND,
                            MPFROMSHORT(ID_TE_DOWN), MPFROM2SHORT(CMDSRC_OTHER, FALSE));
                        }

                    return MPFROMLONG(TRUE);
                    }
                break;
 
              case VK_UP :
                if ( ! (SHORT1FROMMP(mp1) & (KC_ALT | KC_SHIFT)) ) {
                    if ( (SHORT1FROMMP(mp1) & (KC_CTRL)) ) {
                        WinSendMsg(TitleEditorDlg, WM_COMMAND,
                            MPFROMSHORT(ID_TE_HOME), MPFROM2SHORT(CMDSRC_OTHER, FALSE));
                        }
                    else {
                        WinSendMsg(TitleEditorDlg, WM_COMMAND,
                            MPFROMSHORT(ID_TE_UP), MPFROM2SHORT(CMDSRC_OTHER, FALSE));
                        }

                    return MPFROMLONG(TRUE);
                    }
                break;

              case VK_ENTER :
              case VK_NEWLINE :
                if ( ! (SHORT1FROMMP(mp1) & KC_ALT) ) {
                    WinSendMsg(TitleEditorDlg, WM_COMMAND,
                       MPFROMSHORT(ID_TE_ENTER), MPFROM2SHORT(CMDSRC_OTHER, FALSE));

                    return MPFROMLONG(TRUE);
                    }
                break;
                }
            }
        break;
        }

    return OldTEEntryTrackWndProc(hwnd, msg, mp1, mp2);
}

MRESULT EXPENTRY ProgramEditorDlgProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2)
{
    static HWND hwndPECDLength;
    static HWND hwndPECDTracks;
    static HWND hwndPECDSelect;
    static HWND hwndPEPlayListLength;
    static HWND hwndPEPlayListTracks;
    static HWND hwndPEPlayListSelect;
    static HWND hwndPEInfo;
    static HWND hwndPEInsertBegin;
    static HWND hwndPEInsert;
    static HWND hwndPEInsertEnd;
    static HWND hwndPEDelete;
    static HWND hwndPESave;
    static HWND hwndPEQuit;
    static HWND hwndPE[30];
    static SWP WindowPos[30];
    static SWP NewWindowPos[30];
    static ULONG x, y, cx, cy, State;
    static HACCEL PEDlgAccelTable;
    static PSZ CurrTitleAccess;
    static CDAUDIO_CONTENTS CurrContents;
    static CDAUDIO_PLAYLIST CurrPlayList;
    static char Buffer[MAX_TITLE_LENGTH];
    static BOOL NoEntry;
    BOOL bResult;
    ULONG i;
    ULONG Track, InsertTrack;
    static USHORT ItemsToDelete[MAX_PLAYLIST];
    static BOOL Changed;
    MMTIME Length;
    MRESULT mResult;
    PSWP PSwp;
    static DLGSTARTDATA *StartData;
    static RECTL OriSize;
    LONG xDiff, yDiff;
    static POINTL MinSize;
    // static ULONG Style;

    switch ( msg ) {
      case WM_INITDLG :
        ProgramEditorInProcess = TRUE;
        ProgramEditorHidden = FALSE;
        Changed = FALSE;
        NoEntry = FALSE;

        bResult = WinAssociateHelpInstance(hwndMainHelp, hwnd);

        PEDlgAccelTable = WinLoadAccelTable(hab, NULLHANDLE, ID_DLG_PROGRAMEDITOR);
        if ( PEDlgAccelTable != NULLHANDLE ) {
            bResult = WinSetAccelTable(hab, PEDlgAccelTable, hwnd);
            }

        hwndPECDLength = WinWindowFromID(hwnd, ID_PE_CD_LENGTH);
        hwndPECDTracks = WinWindowFromID(hwnd, ID_PE_CD_TRACKS);
        hwndPECDSelect = WinWindowFromID(hwnd, ID_PE_CD_SELECT);

        hwndPEPlayListLength = WinWindowFromID(hwnd, ID_PE_PLAYLIST_LENGTH);
        hwndPEPlayListTracks = WinWindowFromID(hwnd, ID_PE_PLAYLIST_TRACKS);
        hwndPEPlayListSelect = WinWindowFromID(hwnd, ID_PE_PLAYLIST_SELECT);

        hwndPEInfo = WinWindowFromID(hwnd, ID_PE_INFO);
        hwndPEInsertBegin = WinWindowFromID(hwnd, ID_PE_INSERT_BEGIN);
        hwndPEInsert = WinWindowFromID(hwnd, ID_PE_INSERT);
        hwndPEInsertEnd = WinWindowFromID(hwnd, ID_PE_INSERT_END);
        hwndPEDelete = WinWindowFromID(hwnd, ID_PE_DELETE);
        hwndPESave = WinWindowFromID(hwnd, ID_PE_SAVE);
        hwndPEQuit = WinWindowFromID(hwnd, ID_PE_QUIT);

        WinQueryWindowRect(hwnd, &OriSize);

        for ( i = 0; i < 30; i++ ) {
            hwndPE[i] = WinWindowFromID(hwnd, ID_DLG_PROGRAMEDITOR+1+i);
            WinQueryWindowPos(hwndPE[i], WindowPos+i);
            NewWindowPos[i] = WindowPos[i];
            NewWindowPos[i].fl = SWP_SIZE | SWP_MOVE | SWP_NOADJUST;
            NewWindowPos[i].hwndInsertBehind = HWND_TOP;
            }

        MinSize.x = OriSize.xRight -
         2 * (WindowPos[3].x - (WindowPos[2].x + WindowPos[2].cx));
          /*
         2 * (WindowPos[1].cx -
              ((WindowPos[2].cx +
               (WindowPos[2].x - WindowPos[1].y)) +
              ((WindowPos[3].cx +
               (WindowPos[1].x + WindowPos[1].cx) -
               (WindowPos[3].x + WindowPos[3].cx)));
         */
        MinSize.y = OriSize.yTop;

        srand(time(NULL));

        bResult = CDPrfLoadWindowPos(CDWINDOW_PLAYLIST, &x, &y, &cx, &cy, &State);
        if ( bResult ) {
            WinSetWindowPos(hwnd, HWND_TOP, x, y, cx, cy, SWP_MOVE | SWP_SIZE);
            }

        StartData = PVOIDFROMMP(mp2);
        if ( StartData != NULL )
            WinSendMsg(hwnd, StartData->msg, MPFROMP(StartData->Contents),
                MPFROMP(StartData->TitleAccess));

        return NULL;

      case HM_HELPSUBITEM_NOT_FOUND :
        if ( IsHelpButton(SHORT2FROMMP(mp2)) ) {
            WinSendMsg(hwndMainHelp, HM_DISPLAY_HELP, NULL, NULL);
            return MRFROMLONG(TRUE);
            }
        else {
            return MRFROMLONG(FALSE);
            }

      case PE_TITLECHANGED :
        if ( CurrTitleAccess != NULL && ! strcmp(PVOIDFROMMP(mp1), CurrTitleAccess) ) {
            CDTITLE_CHANGE *Change = (CDTITLE_CHANGE *)PVOIDFROMMP(mp2);

            if ( Change->Track > 0 ) {
                if ( CurrContents.Track[Change->Track-1].IsAudioTrack ) {
                    WinSendMsg(hwndPECDSelect, LM_SETITEMTEXT, MPFROMSHORT(Change->Track-1),
                        MPFROMP(GetTrackStr(Change->Track, Change->Title)));
                    }
                else {
                    WinSendMsg(hwndPECDSelect, LM_SETITEMTEXT, MPFROMSHORT(Change->Track-1),
                        MPFROMP(GetTrackStrNoAudio(Change->Track, Change->Title)));
                    }

                for ( i = 0; i < CurrPlayList.TotalTracks; i++ ) {
                    if ( CurrPlayList.Track[i].ToPlay == Change->Track )
                        WinSendMsg(hwndPEPlayListSelect, LM_SETITEMTEXT, MPFROMSHORT(i),
                            MPFROMP(GetTrackStr(Change->Track, Change->Title)));
                    }
                }

            return MRFROMLONG(TRUE);
            }
        return NULL;

      case PE_SETCD :               
        if ( NoEntry ) {
            WinAlarm(HWND_DESKTOP, WA_ERROR);
            return NULL;
            }

        NoEntry = TRUE;

        if ( CurrTitleAccess != NULL && strcmp(CurrTitleAccess, (PSZ)PVOIDFROMMP(mp2)) ) {
            if ( Changed ) {
                USHORT Answer = YesOrNo(hwnd, ProgramSave);
 
                if ( Answer == MBID_YES ) {
                    bResult = CDPrfSetPlayList(CurrTitleAccess, &CurrPlayList);
                    }
                else if ( Answer == MBID_CANCEL ) {
                    NoEntry = FALSE;
                    return NULL;
                    }
                }

            CDPrfReleaseAccess(CurrTitleAccess);
            }
            
        if ( CurrTitleAccess != NULL && ! strcmp(CurrTitleAccess, (PSZ)PVOIDFROMMP(mp2)) ) {
            NoEntry = FALSE;
            return NULL;
            }

        SetWaitPointer(TRUE);
        Changed = FALSE;
        CurrTitleAccess = CDPrfCopyAccess((PSZ)PVOIDFROMMP(mp2));
        memcpy(&CurrContents, PVOIDFROMMP(mp1), sizeof(CDAUDIO_CONTENTS));
 
        if ( ! CDPrfQueryPlayList(CurrTitleAccess, &CurrPlayList) )
             CDGetDefPlayList(&CurrContents, &CurrPlayList);

        Length = 0;
        Track = 0;
        
        if ( ! ListBoxAnimation )
            WinEnableWindowUpdate(hwndPECDSelect, FALSE);
        WinSendMsg(hwndPECDSelect, LM_DELETEALL, NULL, NULL);
        for ( i = 0; i < CurrContents.TotalTracks; i++) {
            Length += CurrContents.Track[i].Length;
            Track++;
            if ( CurrContents.Track[i].IsAudioTrack ) {
                if ( CDPrfQueryTrackTitle(CurrTitleAccess, Buffer, sizeof(Buffer), i+1) )
                    WinSendMsg(hwndPECDSelect, LM_INSERTITEM, MPFROMSHORT(LIT_END),
                        MPFROMP(GetTrackStr(i+1, Buffer)));
                else
                    WinSendMsg(hwndPECDSelect, LM_INSERTITEM, MPFROMSHORT(LIT_END),
                        MPFROMP(GetTrackStr(i+1, NULL)));
                }
            else {
                if ( CDPrfQueryTrackTitle(CurrTitleAccess, Buffer, sizeof(Buffer), i+1) )
                    WinSendMsg(hwndPECDSelect, LM_INSERTITEM, MPFROMSHORT(LIT_END),
                        MPFROMP(GetTrackStrNoAudio(i+1, Buffer)));
                else
                    WinSendMsg(hwndPECDSelect, LM_INSERTITEM, MPFROMSHORT(LIT_END),
                        MPFROMP(GetTrackStrNoAudio(i+1, NULL)));
                }
            }

        WinSendMsg(hwndPECDSelect, LM_SELECTITEM, MPFROMSHORT(LIT_NONE), NULL);
        if ( ! ListBoxAnimation )
            WinEnableWindowUpdate(hwndPECDSelect, TRUE);

        WinSetWindowText(hwndPECDLength, GetTimeStr(Length));
        WinSetWindowText(hwndPECDTracks, itoa(Track, Buffer, 10));

        if ( ! ListBoxAnimation )
            WinEnableWindowUpdate(hwndPEPlayListSelect, FALSE);
        WinSendMsg(hwndPEPlayListSelect, LM_DELETEALL, NULL, NULL);
        for ( i = 0; i < CurrPlayList.TotalTracks; i++) {
            if ( CDPrfQueryTrackTitle(CurrTitleAccess, Buffer, sizeof(Buffer), 
                    CurrPlayList.Track[i].ToPlay) )
                WinSendMsg(hwndPEPlayListSelect, LM_INSERTITEM, MPFROMSHORT(LIT_END),
                    MPFROMP(GetTrackStr(CurrPlayList.Track[i].ToPlay, Buffer)));
            else
                WinSendMsg(hwndPEPlayListSelect, LM_INSERTITEM, MPFROMSHORT(LIT_END),
                    MPFROMP(GetTrackStr(CurrPlayList.Track[i].ToPlay, NULL)));
            }

        WinSendMsg(hwndPEPlayListSelect, LM_SELECTITEM, MPFROMSHORT(LIT_NONE), NULL);
        if ( ! ListBoxAnimation )
            WinEnableWindowUpdate(hwndPEPlayListSelect, TRUE);

        WinSetWindowText(hwndPEPlayListLength, GetTimeStr(CurrPlayList.TotalLength));
        WinSetWindowText(hwndPEPlayListTracks, itoa(CurrPlayList.TotalTracks, Buffer, 10));

        WinEnableWindow(hwndPEInsertBegin, FALSE);
        WinEnableWindow(hwndPEInsert, FALSE);
        WinEnableWindow(hwndPEInsertEnd, FALSE);
        WinEnableWindow(hwndPEDelete, FALSE);
        SetWaitPointer(FALSE);
        NoEntry = FALSE;
        return NULL;

      case CTL_TIMEFORMAT :
        Length = 0;

        for ( i = 0; i < CurrContents.TotalTracks; i++) {
            Length += CurrContents.Track[i].Length;
            }

        WinSetWindowText(hwndPECDLength, GetTimeStr(Length));
        WinSetWindowText(hwndPEPlayListLength, GetTimeStr(CurrPlayList.TotalLength));
        return NULL;

      case WM_COMMAND :
        switch ( SHORT1FROMMP(mp1) ) {
          case ID_PE_INFO :
            CmdInfo(&CurrContents, CurrTitleAccess);
            break;

          case ID_PE_INSERT_BEGIN :
            SetWaitPointer(TRUE);
            Track = LIT_FIRST;
            InsertTrack = 0;
            if ( ! ListBoxAnimation )
                WinEnableWindowUpdate(hwndPEPlayListSelect, FALSE);

            while ( ( Track = LONGFROMMR(WinSendMsg(hwndPECDSelect, LM_QUERYSELECTION,
                        MPFROMSHORT(Track), NULL)) ) != (ULONG)LIT_NONE ) {
                if ( ! CDInsertInPlayList(&CurrContents, &CurrPlayList, InsertTrack, Track+1) ) {
                    WinAlarm(HWND_DESKTOP, WA_ERROR);
                    break;
                    }

                Changed = TRUE;

                if ( ListBoxAnimation ) {
                    WinSetWindowText(hwndPEPlayListLength, GetTimeStr(CurrPlayList.TotalLength));
                    WinSetWindowText(hwndPEPlayListTracks, itoa(CurrPlayList.TotalTracks, Buffer, 10));
                    }

                if ( CDPrfQueryTrackTitle(CurrTitleAccess, Buffer, sizeof(Buffer), Track+1) )
                    WinSendMsg(hwndPEPlayListSelect, LM_INSERTITEM, MPFROMSHORT(InsertTrack),
                        MPFROMP(GetTrackStr(Track+1, Buffer)));
                else
                    WinSendMsg(hwndPEPlayListSelect, LM_INSERTITEM, MPFROMSHORT(InsertTrack),
                        MPFROMP(GetTrackStr(Track+1, NULL)));
                InsertTrack++;
                }

            if ( ! ListBoxAnimation ) {
                WinEnableWindowUpdate(hwndPEPlayListSelect, TRUE);
                WinSetWindowText(hwndPEPlayListLength, GetTimeStr(CurrPlayList.TotalLength));
                WinSetWindowText(hwndPEPlayListTracks, itoa(CurrPlayList.TotalTracks, Buffer, 10));
                }

            SetWaitPointer(FALSE);
            break;

          case ID_PE_INSERT :
            SetWaitPointer(TRUE);
            Track = LIT_FIRST;
            InsertTrack = LONGFROMMR(WinSendMsg(hwndPEPlayListSelect, LM_QUERYSELECTION,
                MPFROMSHORT(LIT_FIRST), NULL));

            if ( ! ListBoxAnimation )
                WinEnableWindowUpdate(hwndPEPlayListSelect, FALSE);

            if ( InsertTrack == (ULONG)LIT_NONE ) {
                while ( ( Track = LONGFROMMR(WinSendMsg(hwndPECDSelect, LM_QUERYSELECTION,
                            MPFROMSHORT(Track), NULL)) ) != (ULONG)LIT_NONE ) {
                    if ( ! CDInsertInPlayList(&CurrContents, &CurrPlayList, MAX_PLAYLIST, 
                            Track+1) ) {
                        WinAlarm(HWND_DESKTOP, WA_ERROR);
                        break;
                        }

                    Changed = TRUE;

                    if ( ListBoxAnimation ) {
                        WinSetWindowText(hwndPEPlayListLength, GetTimeStr(CurrPlayList.TotalLength));
                        WinSetWindowText(hwndPEPlayListTracks, itoa(CurrPlayList.TotalTracks, Buffer, 10));
                        }

                    if ( CDPrfQueryTrackTitle(CurrTitleAccess, Buffer, sizeof(Buffer), Track+1) )
                        WinSendMsg(hwndPEPlayListSelect, LM_INSERTITEM, MPFROMSHORT(LIT_END),
                            MPFROMP(GetTrackStr(Track+1, Buffer)));
                    else
                        WinSendMsg(hwndPEPlayListSelect, LM_INSERTITEM, MPFROMSHORT(LIT_END),
                            MPFROMP(GetTrackStr(Track+1, NULL)));
                    }
                }
            else {
                while ( ( Track = LONGFROMMR(WinSendMsg(hwndPECDSelect, LM_QUERYSELECTION,
                            MPFROMSHORT(Track), NULL)) ) != (ULONG)LIT_NONE ) {
                    if ( ! CDInsertInPlayList(&CurrContents, &CurrPlayList, InsertTrack, 
                            Track+1) ) {
                        WinAlarm(HWND_DESKTOP, WA_ERROR);
                        break;
                        }

                    Changed = TRUE;

                    if ( ListBoxAnimation ) {
                        WinSetWindowText(hwndPEPlayListLength, GetTimeStr(CurrPlayList.TotalLength));
                        WinSetWindowText(hwndPEPlayListTracks, itoa(CurrPlayList.TotalTracks, Buffer, 10));
                        }

                    if ( CDPrfQueryTrackTitle(CurrTitleAccess, Buffer, sizeof(Buffer), Track+1) )
                        WinSendMsg(hwndPEPlayListSelect, LM_INSERTITEM, MPFROMSHORT(InsertTrack),
                            MPFROMP(GetTrackStr(Track+1, Buffer)));
                    else
                        WinSendMsg(hwndPEPlayListSelect, LM_INSERTITEM, MPFROMSHORT(InsertTrack),
                            MPFROMP(GetTrackStr(Track+1, NULL)));
                    InsertTrack++;
                    }
                }

            if ( ! ListBoxAnimation ) {
                WinEnableWindowUpdate(hwndPEPlayListSelect, TRUE);
                WinSetWindowText(hwndPEPlayListLength, GetTimeStr(CurrPlayList.TotalLength));
                WinSetWindowText(hwndPEPlayListTracks, itoa(CurrPlayList.TotalTracks, Buffer, 10));
                }

            SetWaitPointer(FALSE);
            break;

          case ID_PE_INSERT_END :
            SetWaitPointer(TRUE);
            Track = LIT_FIRST;

            if ( ! ListBoxAnimation )
                WinEnableWindowUpdate(hwndPEPlayListSelect, FALSE);

            while ( ( Track = LONGFROMMR(WinSendMsg(hwndPECDSelect, LM_QUERYSELECTION,
                        MPFROMSHORT(Track), NULL)) ) != (ULONG)LIT_NONE ) {
                if ( ! CDInsertInPlayList(&CurrContents, &CurrPlayList, MAX_PLAYLIST, Track+1) ) {
                    WinAlarm(HWND_DESKTOP, WA_ERROR);
                    break;
                    }

                Changed = TRUE;

                if ( ListBoxAnimation ) {
                    WinSetWindowText(hwndPEPlayListLength, GetTimeStr(CurrPlayList.TotalLength));
                    WinSetWindowText(hwndPEPlayListTracks, itoa(CurrPlayList.TotalTracks, Buffer, 10));
                    }

                if ( CDPrfQueryTrackTitle(CurrTitleAccess, Buffer, sizeof(Buffer), Track+1) )
                    WinSendMsg(hwndPEPlayListSelect, LM_INSERTITEM, MPFROMSHORT(LIT_END),
                        MPFROMP(GetTrackStr(Track+1, Buffer)));
                else
                    WinSendMsg(hwndPEPlayListSelect, LM_INSERTITEM, MPFROMSHORT(LIT_END),
                        MPFROMP(GetTrackStr(Track+1, NULL)));
                }

            if ( ! ListBoxAnimation ) {
                WinEnableWindowUpdate(hwndPEPlayListSelect, TRUE);
                WinSetWindowText(hwndPEPlayListLength, GetTimeStr(CurrPlayList.TotalLength));
                WinSetWindowText(hwndPEPlayListTracks, itoa(CurrPlayList.TotalTracks, Buffer, 10));
                }

            SetWaitPointer(FALSE);
            break;

          case ID_PE_DELETE :
            SetWaitPointer(TRUE);
            Track = LIT_FIRST;
            InsertTrack = 0;
            while ( ( Track = LONGFROMMR(WinSendMsg(hwndPEPlayListSelect, LM_QUERYSELECTION, 
                        MPFROMSHORT(Track), NULL)) ) != (ULONG)LIT_NONE ) {
                ItemsToDelete[InsertTrack++] = Track;
                }

            // This is a (potential) Bugfix for OS/2 grrr!
            // Style = WinQueryWindowULong(hwndPEPlayListSelect, QWL_STYLE);
            // bResult = WinSetWindowULong(hwndPEPlayListSelect, QWL_STYLE,
            //     Style & ~LS_HORZSCROLL);

            if ( ! ListBoxAnimation )
                WinEnableWindowUpdate(hwndPEPlayListSelect, FALSE);

            // WinSendMsg(hwndPEPlayListSelect, LM_SELECTITEM, MPFROMSHORT(LIT_NONE), NULL);
            while ( InsertTrack > 0 ) {
                if ( ! CDDeleteFromPlayList(&CurrContents, &CurrPlayList, 
                        ItemsToDelete[InsertTrack-1]) ) {
                    WinAlarm(HWND_DESKTOP, WA_ERROR);
                    break;
                    }

                Changed = TRUE;

                if ( ListBoxAnimation ) {
                    WinSetWindowText(hwndPEPlayListLength, GetTimeStr(CurrPlayList.TotalLength));
                    WinSetWindowText(hwndPEPlayListTracks, itoa(CurrPlayList.TotalTracks, Buffer, 10));
                    }

                WinSendMsg(hwndPEPlayListSelect, LM_DELETEITEM, 
                    MPFROMSHORT(ItemsToDelete[InsertTrack-1]), NULL);
                InsertTrack--;
                }

            if ( ! ListBoxAnimation ) {
                WinEnableWindowUpdate(hwndPEPlayListSelect, TRUE);
                WinSetWindowText(hwndPEPlayListLength, GetTimeStr(CurrPlayList.TotalLength));
                WinSetWindowText(hwndPEPlayListTracks, itoa(CurrPlayList.TotalTracks, Buffer, 10));
                }

            // This is a (potential) Bugfix for OS/2 grrr!
            // bResult = WinSetWindowULong(hwndPEPlayListSelect, QWL_STYLE, Style);

            if ( LONGFROMMR(WinSendMsg(hwndPEPlayListSelect, LM_QUERYSELECTION,
                        MPFROMSHORT(LIT_FIRST), NULL)) == (ULONG)LIT_NONE ) {
                WinEnableWindow(hwndPEDelete, FALSE);
                }

            SetWaitPointer(FALSE);
            break;

          case ID_PE_SAVE :
            bResult = CDPrfSetPlayList(CurrTitleAccess, &CurrPlayList);
            if ( bResult )
                Changed = FALSE;
            break;

          case ID_PE_QUIT :
            if ( CurrTitleAccess != NULL ) {
                if ( Changed ) {
                    USHORT Answer = YesOrNo(hwnd, ProgramSave);
 
                    if ( Answer == MBID_YES ) {
                        bResult = CDPrfSetPlayList(CurrTitleAccess, &CurrPlayList);
                        Changed = ! bResult;
                        }
                    else if ( Answer == MBID_CANCEL )
                        return NULL;
                    }
                }

            WinSendMsg(hwndMainHelp, HM_DISMISS_WINDOW, NULL, NULL);
            WinSetWindowPos(hwnd, HWND_TOP, 0, 0, 0, 0, SWP_HIDE);
            ProgramEditorHidden = TRUE;
            WinSetFocus(HWND_DESKTOP, hwndDlg);
            break;

          case ID_PE_SHUFFLE :
            SetWaitPointer(TRUE);
            InsertTrack = CurrPlayList.TotalTracks;
            for ( i = 0; i < InsertTrack; i++ )
                ItemsToDelete[i] = CurrPlayList.Track[i].ToPlay;

            CDFlushPlayList(&CurrPlayList);
            Changed = TRUE;

            if ( ! ListBoxAnimation )
                WinEnableWindowUpdate(hwndPEPlayListSelect, FALSE);
            WinSendMsg(hwndPEPlayListSelect, LM_DELETEALL, NULL, NULL);
            for ( i = 0; i < InsertTrack ; i++ ) {
                Track = i + (rand() % (InsertTrack - i));
                if ( ! CDInsertInPlayList(&CurrContents, &CurrPlayList, MAX_PLAYLIST,
                        ItemsToDelete[Track]) ) {
                    WinAlarm(HWND_DESKTOP, WA_ERROR);
                    break;
                    }

                if ( CDPrfQueryTrackTitle(CurrTitleAccess, Buffer, sizeof(Buffer),
                        ItemsToDelete[Track]) )
                    WinSendMsg(hwndPEPlayListSelect, LM_INSERTITEM, MPFROMSHORT(LIT_END),
                        MPFROMP(GetTrackStr(ItemsToDelete[Track], Buffer)));
                else
                    WinSendMsg(hwndPEPlayListSelect, LM_INSERTITEM, MPFROMSHORT(LIT_END),
                        MPFROMP(GetTrackStr(ItemsToDelete[Track], NULL)));

                ItemsToDelete[Track] = ItemsToDelete[i];
                }

            // WinSendMsg(hwndPEPlayListSelect, LM_SELECTITEM, MPFROMSHORT(LIT_NONE), NULL);
            if ( ! ListBoxAnimation )
                WinEnableWindowUpdate(hwndPEPlayListSelect, TRUE);

            WinEnableWindow(hwndPEDelete, FALSE);
            WinSetWindowText(hwndPEPlayListLength, GetTimeStr(CurrPlayList.TotalLength));
            WinSetWindowText(hwndPEPlayListTracks, itoa(CurrPlayList.TotalTracks, Buffer, 10));
            SetWaitPointer(FALSE);
            break;

          case ID_PE_REVERSE :
            SetWaitPointer(TRUE);
            InsertTrack = CurrPlayList.TotalTracks;
            for ( i = 0; i < InsertTrack; i++ )
                ItemsToDelete[i] = CurrPlayList.Track[i].ToPlay;

            CDFlushPlayList(&CurrPlayList);
            Changed = TRUE;

            if ( ! ListBoxAnimation )
                WinEnableWindowUpdate(hwndPEPlayListSelect, FALSE);

            WinSendMsg(hwndPEPlayListSelect, LM_DELETEALL, NULL, NULL);
            for ( i = InsertTrack; i > 0 ; i-- ) {
                if ( ! CDInsertInPlayList(&CurrContents, &CurrPlayList, MAX_PLAYLIST,
                        ItemsToDelete[i-1]) ) {
                    WinAlarm(HWND_DESKTOP, WA_ERROR);
                    break;
                    }

                if ( CDPrfQueryTrackTitle(CurrTitleAccess, Buffer, sizeof(Buffer),
                        ItemsToDelete[i-1]) )
                    WinSendMsg(hwndPEPlayListSelect, LM_INSERTITEM, MPFROMSHORT(LIT_END),
                        MPFROMP(GetTrackStr(ItemsToDelete[i-1], Buffer)));
                else
                    WinSendMsg(hwndPEPlayListSelect, LM_INSERTITEM, MPFROMSHORT(LIT_END),
                        MPFROMP(GetTrackStr(ItemsToDelete[i-1], NULL)));
                }

            // WinSendMsg(hwndPEPlayListSelect, LM_SELECTITEM, MPFROMSHORT(LIT_NONE), NULL);
            if ( ! ListBoxAnimation )
                WinEnableWindowUpdate(hwndPEPlayListSelect, TRUE);

            WinEnableWindow(hwndPEDelete, FALSE);
            WinSetWindowText(hwndPEPlayListLength, GetTimeStr(CurrPlayList.TotalLength));
            WinSetWindowText(hwndPEPlayListTracks, itoa(CurrPlayList.TotalTracks, Buffer, 10));
            SetWaitPointer(FALSE);
            break;

          case ID_PE_STANDARD :
            SetWaitPointer(TRUE);
            CDGetDefPlayList(&CurrContents, &CurrPlayList);
            Changed = TRUE;

            if ( ! ListBoxAnimation )
                WinEnableWindowUpdate(hwndPEPlayListSelect, FALSE);

            WinSendMsg(hwndPEPlayListSelect, LM_DELETEALL, NULL, NULL);
            for ( i = 0; i < CurrPlayList.TotalTracks; i++) {
                if ( CDPrfQueryTrackTitle(CurrTitleAccess, Buffer, sizeof(Buffer),
                        CurrPlayList.Track[i].ToPlay) )
                    WinSendMsg(hwndPEPlayListSelect, LM_INSERTITEM, MPFROMSHORT(LIT_END),
                        MPFROMP(GetTrackStr(CurrPlayList.Track[i].ToPlay, Buffer)));
                else
                    WinSendMsg(hwndPEPlayListSelect, LM_INSERTITEM, MPFROMSHORT(LIT_END),
                        MPFROMP(GetTrackStr(CurrPlayList.Track[i].ToPlay, NULL)));
                }
 
            if ( ! ListBoxAnimation )
                WinEnableWindowUpdate(hwndPEPlayListSelect, TRUE);
            // WinSendMsg(hwndPEPlayListSelect, LM_SELECTITEM, MPFROMSHORT(LIT_NONE), NULL);

            WinEnableWindow(hwndPEDelete, FALSE);
            WinSetWindowText(hwndPEPlayListLength, GetTimeStr(CurrPlayList.TotalLength));
            WinSetWindowText(hwndPEPlayListTracks, itoa(CurrPlayList.TotalTracks, Buffer, 10));
            SetWaitPointer(FALSE);
            break;

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
        return MRFROMSHORT(PANEL_PE_KEYBOARD);

      case WM_CONTROL :
        switch ( SHORT1FROMMP(mp1) ) {
          case ID_PE_CD_SELECT :
            if ( SHORT2FROMMP(mp1) == LN_SELECT ) {
                Track = LONGFROMMR(WinSendMsg(hwndPECDSelect, LM_QUERYSELECTION,
                    MPFROMSHORT(LIT_FIRST), NULL));
                    
                WinEnableWindow(hwndPEInsertBegin, Track != (ULONG)LIT_NONE );
                WinEnableWindow(hwndPEInsert, Track != (ULONG)LIT_NONE );
                WinEnableWindow(hwndPEInsertEnd, Track != (ULONG)LIT_NONE );
                }

            break;

          case ID_PE_PLAYLIST_SELECT :
            if ( SHORT2FROMMP(mp1) == LN_SELECT ) {
                Track = LONGFROMMR(WinSendMsg(hwndPEPlayListSelect, LM_QUERYSELECTION,
                    MPFROMSHORT(LIT_FIRST), NULL));

                WinEnableWindow(hwndPEDelete, Track != (ULONG)LIT_NONE );
                }
            break;
            }
 
        return NULL;

      case WM_CLOSE :
        if ( Changed ) {
            USHORT Answer = YesOrNo(hwnd, ProgramSave);

            if ( Answer == MBID_YES ) {
                bResult = CDPrfSetPlayList(CurrTitleAccess, &CurrPlayList);
                Changed = ! bResult;
                }
            else if ( Answer == MBID_CANCEL )
                return NULL;
            }

        WinSendMsg(hwndMainHelp, HM_DISMISS_WINDOW, NULL, NULL);
        WinSetWindowPos(hwnd, HWND_TOP, 0, 0, 0, 0, SWP_HIDE);
        ProgramEditorHidden = TRUE;
        WinSetFocus(HWND_DESKTOP, hwndDlg);
        return NULL;

      case WM_DESTROY :
        if ( PEDlgAccelTable != NULLHANDLE ) {
            bResult = WinDestroyAccelTable(PEDlgAccelTable);
            }
        return NULL;

      case WM_ACTIVATE :
        if ( ModalProcessing && SHORT1FROMMP(mp1) ) {
            WinPostMsg(hwnd, INTERNAL_DELAYED_RESETFOCUS, MPFROMHWND(CurrModalOwner), NULL);
            }
        return WinDefDlgProc(hwnd, msg, mp1, mp2);

      case INTERNAL_DELAYED_RESETFOCUS :
        WinSetFocus(HWND_DESKTOP, HWNDFROMMP(mp1));
        return NULL;

        /*
      case WM_WINDOWPOSCHANGED :
        if ( SaveWindowPos && ProgramEditorInProcess && (PSwp->fl & (SWP_MOVE | SWP_SIZE)) ) {
            if ( PSwp->fl & (SWP_MINIMIZE | SWP_HIDE) ) {
                }
            else {
                CDPrfSaveWindowPos(CDWINDOW_PLAYLIST, PSwp->x, PSwp->y, PSwp->cx, PSwp->cy,
                    WINDOWSTATE_NORMAL);
                }
            }

        if ( PSwp->fl & (SWP_HIDE | SWP_MINIMIZE) ) {
            WinSendMsg(hwndMainHelp, HM_DISMISS_WINDOW, NULL, NULL);
            ProgramEditorHidden = TRUE;
            WinSetFocus(HWND_DESKTOP, hwndDlg);
            }

        return WinDefDlgProc(hwnd, msg, mp1, mp2);
        */

      case WM_ADJUSTWINDOWPOS :
        PSwp = (PSWP)PVOIDFROMMP(mp1);
        if ( PSwp->fl & SWP_SIZE) {
            PSwp->cx = max(PSwp->cx, MinSize.x);
            PSwp->cy = max(PSwp->cy, MinSize.y);
            }
        return WinDefDlgProc(hwnd, msg, mp1, mp2);

      case WM_TRACKFRAME :
        return MRFROMLONG(TrackFrameRestricted(hwnd, LONGFROMMP(mp1), &MinSize, NULL));

      case WM_WINDOWPOSCHANGED :
        PSwp = (PSWP)PVOIDFROMMP(mp1);
        if ( PSwp->fl & SWP_SIZE ) {
            for ( i = 0; i < 30; i++ )
                WinEnableWindowUpdate(hwndPE[i], FALSE);
            }
        mResult = WinDefDlgProc(hwnd, msg, mp1, mp2);

        if ( SaveWindowPos && ProgramEditorInProcess && (PSwp->fl & (SWP_MOVE | SWP_SIZE)) ) {
            if ( PSwp->fl & (SWP_MINIMIZE | SWP_HIDE) ) {
                }
            else {
                CDPrfSaveWindowPos(CDWINDOW_PLAYLIST, PSwp->x, PSwp->y, PSwp->cx, PSwp->cy,
                    WINDOWSTATE_NORMAL);
                }
            }

        if ( PSwp->fl & (SWP_HIDE | SWP_MINIMIZE) ) {
            WinSendMsg(hwndMainHelp, HM_DISMISS_WINDOW, NULL, NULL);
            ProgramEditorHidden = TRUE;
            WinSetFocus(HWND_DESKTOP, hwndDlg);
            }
        else if ( PSwp->fl & SWP_SIZE ) {
            xDiff = PSwp->cx - OriSize.xRight;
            yDiff = PSwp->cy - OriSize.yTop;

            NewWindowPos[0].cx = WindowPos[0].cx + xDiff / 2;
            NewWindowPos[0].cy = WindowPos[0].cy + yDiff;
                           
            NewWindowPos[1].cx = WindowPos[1].cx + xDiff / 2;
            NewWindowPos[1].y = WindowPos[1].y + yDiff;
                           
            NewWindowPos[2].y = WindowPos[2].y + yDiff;
                           
            NewWindowPos[3].x = WindowPos[3].x + xDiff / 2;
            NewWindowPos[3].y = WindowPos[3].y + yDiff;
                           
            NewWindowPos[4].y = WindowPos[4].y + yDiff;
                           
            NewWindowPos[5].x = WindowPos[5].x + xDiff / 2;
            NewWindowPos[5].y = WindowPos[5].y + yDiff;
                           
            NewWindowPos[6].cx = WindowPos[6].cx + xDiff / 2;
            NewWindowPos[6].cy = WindowPos[6].cy + yDiff;
              
            for ( i = 7; i < 23; i++)
                NewWindowPos[i].x = WindowPos[i].x + xDiff / 2;

            NewWindowPos[7].cy = WindowPos[7].cy + yDiff;

            NewWindowPos[8].y = WindowPos[8].y + 8 * (yDiff / 11) +
                min(yDiff % 11, 8);
            NewWindowPos[8].cy = WindowPos[8].cy + 3 * (yDiff / 11) +
                max((yDiff % 11) - 8, 0);

            NewWindowPos[9].y = WindowPos[9].y + 10 * (yDiff / 11) + 
                (yDiff % 11);
            NewWindowPos[9].cy = WindowPos[9].cy + yDiff / 11;

            NewWindowPos[10].y = WindowPos[10].y + 9 * (yDiff / 11) + 
                min(yDiff % 11, 9);
            NewWindowPos[10].cy = WindowPos[10].cy + yDiff / 11 + 
                ((yDiff % 11) > 9);

            NewWindowPos[11].y = WindowPos[11].y + 8 * (yDiff / 11) +
                min(yDiff % 11, 8);
            NewWindowPos[11].cy = WindowPos[11].cy + yDiff / 11 +
                ((yDiff % 11) > 8);

            NewWindowPos[12].y = WindowPos[12].y + 4 * (yDiff / 11) +
                min(yDiff % 11, 4);
            NewWindowPos[12].cy = WindowPos[12].cy + 4 * (yDiff / 11) +
                min(max((yDiff % 11) - 4, 0), 4);

            NewWindowPos[13].y = WindowPos[13].y + 7 * (yDiff / 11) +
                min(yDiff % 11, 7);
            NewWindowPos[13].cy = WindowPos[13].cy + yDiff / 11 +
                ((yDiff % 11) > 7);

            NewWindowPos[14].y = WindowPos[14].y + 6 * (yDiff / 11) +
                min(yDiff % 11, 6);
            NewWindowPos[14].cy = WindowPos[14].cy + yDiff / 11 +
                ((yDiff % 11) > 6);

            NewWindowPos[15].y = WindowPos[15].y + 5 * (yDiff / 11) +
                min(yDiff % 11, 5);
            NewWindowPos[15].cy = WindowPos[15].cy + yDiff / 11 +
                ((yDiff % 11) > 5);

            NewWindowPos[16].y = WindowPos[16].y + 4 * (yDiff / 11) +
                min(yDiff % 11, 4);
            NewWindowPos[16].cy = WindowPos[16].cy + yDiff / 11 +
                ((yDiff % 11) > 4);

            NewWindowPos[17].y = WindowPos[17].y + (yDiff / 11) +
                min(yDiff % 11, 1);
            NewWindowPos[17].cy = WindowPos[17].cy + 3 * (yDiff / 11) +
                min(max((yDiff % 11) - 1, 0), 3);

            NewWindowPos[18].y = WindowPos[18].y + 3 * (yDiff / 11) +
                min(yDiff % 11, 3);
            NewWindowPos[18].cy = WindowPos[18].cy + yDiff / 11 +
                ((yDiff % 11) > 3);

            NewWindowPos[19].y = WindowPos[19].y + 2 * (yDiff / 11) +
                min(yDiff % 11, 2);
            NewWindowPos[19].cy = WindowPos[19].cy + yDiff / 11 +
                ((yDiff % 11) > 2);

            NewWindowPos[20].y = WindowPos[20].y + (yDiff / 11) +
                min(yDiff % 11, 1);
            NewWindowPos[20].cy = WindowPos[20].cy + yDiff / 11 +
                ((yDiff % 11) > 1);

            NewWindowPos[21].cy = WindowPos[21].cy + (yDiff / 11) +
                ((yDiff % 11) > 0);

            NewWindowPos[22].cy = WindowPos[22].cy + yDiff / 11 +
                ((yDiff % 11) > 0);
 
            NewWindowPos[23].x = WindowPos[23].x + xDiff / 2;
            NewWindowPos[23].cx = WindowPos[23].cx + xDiff / 2 + (xDiff & 1);
            NewWindowPos[23].cy = WindowPos[23].cy + yDiff;

            NewWindowPos[24].x = WindowPos[24].x + xDiff / 2;
            NewWindowPos[24].cx = WindowPos[24].cx + xDiff / 2 + (xDiff & 1);
            NewWindowPos[24].y = WindowPos[24].y + yDiff;

            NewWindowPos[25].x = WindowPos[25].x + xDiff / 2;
            NewWindowPos[25].y = WindowPos[25].y + yDiff;

            NewWindowPos[26].x = WindowPos[26].x + xDiff;
            NewWindowPos[26].y = WindowPos[26].y + yDiff;

            NewWindowPos[27].x = WindowPos[27].x + xDiff / 2;
            NewWindowPos[27].y = WindowPos[27].y + yDiff;

            NewWindowPos[28].x = WindowPos[28].x + xDiff;
            NewWindowPos[28].y = WindowPos[28].y + yDiff;

            NewWindowPos[29].x = WindowPos[29].x + xDiff / 2;
            NewWindowPos[29].cx = WindowPos[29].cx + xDiff / 2 + (xDiff & 1);
            NewWindowPos[29].cy = WindowPos[29].cy + yDiff;

            bResult = WinSetMultWindowPos(hab, NewWindowPos, 30);

            for ( i = 0; i < 30; i++ )
                WinEnableWindowUpdate(hwndPE[i], TRUE);
            }

        // WinEnableWindowUpdate(hwnd, TRUE);
        return mResult;

      default :
        return WinDefDlgProc(hwnd, msg, mp1, mp2);
        }
}


MRESULT EXPENTRY InfoDlgProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2)
{
    static HWND hwndINScrollbar;
    static HWND hwndINQuit;
    static ULONG x, y, cx, cy, State;
    static HACCEL InfoDlgAccelTable;
    static char Buffer[64];
    static PSZ CurrTitleAccess;
    static CDAUDIO_CONTENTS CurrContents;
    static DLGSTARTDATA *StartData;
    BOOL bResult;
    ULONG i;
    static ULONG Offset;
    PSWP PSwp;

    switch ( msg ) {
      case WM_INITDLG :
        InfoInProcess = TRUE;
        InfoHidden = FALSE;

        OldFGBoxProc = WinSubclassWindow(WinWindowFromID(hwnd, ID_IN_FG_TRACKLENGTH),
            FGBoxProc);
        OldBGBoxProc = WinSubclassWindow(WinWindowFromID(hwnd, ID_IN_BG_TRACKLENGTH),
            BGBoxProc);

        WinSubclassWindow(WinWindowFromID(hwnd, ID_IN_FG_TRACKSTART), FGBoxProc);
        WinSubclassWindow(WinWindowFromID(hwnd, ID_IN_BG_TRACKSTART), BGBoxProc);

        WinSubclassWindow(WinWindowFromID(hwnd, ID_IN_FG_CHANNELS), FGBoxProc);
        WinSubclassWindow(WinWindowFromID(hwnd, ID_IN_BG_CHANNELS), BGBoxProc);

        WinSubclassWindow(WinWindowFromID(hwnd, ID_IN_FG_PREEMPHASIS), FGBoxProc);
        WinSubclassWindow(WinWindowFromID(hwnd, ID_IN_BG_PREEMPHASIS), BGBoxProc);

        WinSubclassWindow(WinWindowFromID(hwnd, ID_IN_FG_COPYALLOWED), FGBoxProc);
        WinSubclassWindow(WinWindowFromID(hwnd, ID_IN_BG_COPYALLOWED ), BGBoxProc);

        WinSubclassWindow(WinWindowFromID(hwnd, ID_IN_FG_ISAUDIOTRACK), FGBoxProc);
        WinSubclassWindow(WinWindowFromID(hwnd, ID_IN_BG_ISAUDIOTRACK), BGBoxProc);

        WinSubclassWindow(WinWindowFromID(hwnd, ID_IN_FG_TRACK), FGBoxProc);
        WinSubclassWindow(WinWindowFromID(hwnd, ID_IN_BG_TRACK), BGBoxProc);

        bResult = WinAssociateHelpInstance(hwndMainHelp, hwnd);

        InfoDlgAccelTable = WinLoadAccelTable(hab, NULLHANDLE, ID_DLG_INFO);
        if ( InfoDlgAccelTable != NULLHANDLE ) {
            bResult = WinSetAccelTable(hab, InfoDlgAccelTable, hwnd);
            }

        hwndINScrollbar = WinWindowFromID(hwnd, ID_IN_SCROLLBAR);
        hwndINQuit = WinWindowFromID(hwnd, ID_IN_QUIT);

        bResult = CDPrfLoadWindowPos(CDWINDOW_INFO, &x, &y, &cx, &cy, &State);
        if ( bResult ) {
            WinSetWindowPos(hwnd, HWND_TOP, x, y, cx, cy, SWP_MOVE);
            }

        StartData = PVOIDFROMMP(mp2);
        if ( StartData != NULL )
            WinSendMsg(hwnd, StartData->msg, MPFROMP(StartData->Contents),
                MPFROMP(StartData->TitleAccess));
        return NULL;

      case HM_HELPSUBITEM_NOT_FOUND :
        if ( IsHelpButton(SHORT2FROMMP(mp2)) ) {
            WinSendMsg(hwndMainHelp, HM_DISPLAY_HELP, NULL, NULL);
            return MRFROMLONG(TRUE);
            }
        else {
            return MRFROMLONG(FALSE);
            }

      case IN_SETCD :
        if ( CurrTitleAccess != NULL && 
             0 == strcmp(CurrTitleAccess,(PSZ)PVOIDFROMMP(mp2)) ) {
            return NULL;
            }

        SetWaitPointer(TRUE);

        if ( CurrTitleAccess != NULL ) {
            if ( CurrContents.TotalTracks < INFO_TRACKS ) {
                for ( i = CurrContents.TotalTracks; i < INFO_TRACKS; i++) {
                    WinShowWindow(WinWindowFromID(hwnd, ID_IN_TRACK+i), TRUE);
                    WinShowWindow(WinWindowFromID(hwnd, ID_IN_ISAUDIOTRACK+i), TRUE);
                    WinShowWindow(WinWindowFromID(hwnd, ID_IN_COPYALLOWED+i), TRUE);
                    WinShowWindow(WinWindowFromID(hwnd, ID_IN_PREEMPHASIS+i), TRUE);
                    WinShowWindow(WinWindowFromID(hwnd, ID_IN_CHANNELS+i), TRUE);
                    WinShowWindow(WinWindowFromID(hwnd, ID_IN_TRACKSTART+i), TRUE);
                    WinShowWindow(WinWindowFromID(hwnd, ID_IN_TRACKLENGTH+i), TRUE);
                    }
                }

            CDPrfReleaseAccess(CurrTitleAccess);
            }

        memcpy(&CurrContents, PVOIDFROMMP(mp1), sizeof(CDAUDIO_CONTENTS));
        CurrTitleAccess = CDPrfCopyAccess((PSZ)PVOIDFROMMP(mp2));
 
        WinSetDlgItemText(hwnd, ID_IN_CDLENGTH, GetTimeStr(CurrContents.TotalLength));
        WinSetDlgItemText(hwnd, ID_IN_CDSTART, GetTimeStr(CurrContents.StartPosition));
        WinSetDlgItemText(hwnd, ID_IN_CDTRACKS, itoa(CurrContents.TotalTracks, Buffer, 10));
 
        if ( CurrContents.UPCAvailable ) {
            for ( i = 0; i < 8; i++ ) {
                Buffer[i*2] = (CurrContents.UPC[i] & 0x0F) + '0';
                Buffer[i*2+1] = (CurrContents.UPC[i] >> 4) + '0';
                }
            Buffer[16] = 0;
            WinSetDlgItemText(hwnd, ID_IN_UPC, Buffer);
            }
        else {
            WinSetDlgItemText(hwnd, ID_IN_UPC, NoneText);
            }

        if ( CurrContents.IDAvailable ) {
            sprintf(Buffer, "%8.8x%8.8x", CurrContents.uID[1], CurrContents.uID[0]);
            WinSetDlgItemText(hwnd, ID_IN_MMPMID, Buffer);
            }
        else {
            WinSetDlgItemText(hwnd, ID_IN_MMPMID, NoneText);
            }

        WinSetDlgItemText(hwnd, ID_IN_INTERNALID, CurrTitleAccess);

        if ( CurrContents.TotalTracks > INFO_TRACKS ) {
            WinSendMsg(hwndINScrollbar, SBM_SETTHUMBSIZE,
                MPFROM2SHORT(INFO_TRACKS, CurrContents.TotalTracks), NULL);
            WinSendMsg(hwndINScrollbar, SBM_SETSCROLLBAR, MPFROMSHORT(0),
                MPFROM2SHORT(0, CurrContents.TotalTracks - INFO_TRACKS));
                    
            WinSendMsg(hwnd, IN_SCROLL, NULL, NULL);
            }
        else {
            WinSendMsg(hwndINScrollbar, SBM_SETTHUMBSIZE,
                MPFROM2SHORT(INFO_TRACKS, INFO_TRACKS), NULL);
            WinSendMsg(hwndINScrollbar, SBM_SETSCROLLBAR, MPFROMSHORT(0),
                MPFROM2SHORT(0, 0));

            WinSendMsg(hwnd, IN_SCROLL, NULL, NULL);

            for ( i = CurrContents.TotalTracks; i < INFO_TRACKS; i++) {
                WinShowWindow(WinWindowFromID(hwnd, ID_IN_TRACK+i), FALSE);
                WinShowWindow(WinWindowFromID(hwnd, ID_IN_ISAUDIOTRACK+i), FALSE);
                WinShowWindow(WinWindowFromID(hwnd, ID_IN_COPYALLOWED+i), FALSE);
                WinShowWindow(WinWindowFromID(hwnd, ID_IN_PREEMPHASIS+i), FALSE);
                WinShowWindow(WinWindowFromID(hwnd, ID_IN_CHANNELS+i), FALSE);
                WinShowWindow(WinWindowFromID(hwnd, ID_IN_TRACKSTART+i), FALSE);
                WinShowWindow(WinWindowFromID(hwnd, ID_IN_TRACKLENGTH+i), FALSE);
                }
            }

        Offset = 0;
        SetWaitPointer(FALSE);
        // WinSetFocus(HWND_DESKTOP, hwndINScrollbar);
        return NULL;

      case IN_SCROLL :
        for ( i = 0; i < min(CurrContents.TotalTracks - Offset, INFO_TRACKS); i++) {            
            WinSetDlgItemText(hwnd, ID_IN_TRACK + i, itoa(i + Offset + 1, Buffer, 10));
            WinSendDlgItemMsg(hwnd, ID_IN_ISAUDIOTRACK + i, BM_SETCHECK,
                MPFROMSHORT(CurrContents.Track[i+Offset].IsAudioTrack > 0), NULL);
            WinSendDlgItemMsg(hwnd, ID_IN_COPYALLOWED + i, BM_SETCHECK,
                MPFROMSHORT(CurrContents.Track[i+Offset].CopyPermitted > 0), NULL);
            WinSendDlgItemMsg(hwnd, ID_IN_PREEMPHASIS + i, BM_SETCHECK,
                MPFROMSHORT(CurrContents.Track[i+Offset].Preemphasis > 0), NULL);
            WinSetDlgItemText(hwnd, ID_IN_CHANNELS + i, 
                itoa(CurrContents.Track[i+Offset].Channels, Buffer, 10));
            WinSetDlgItemText(hwnd, ID_IN_TRACKSTART + i,
                GetTimeStr(CurrContents.Track[i+Offset].Start));
            WinSetDlgItemText(hwnd, ID_IN_TRACKLENGTH + i,
                GetTimeStr(CurrContents.Track[i+Offset].Length));
            }
        return NULL;

      case CTL_TIMEFORMAT :
        WinSetDlgItemText(hwnd, ID_IN_CDLENGTH, GetTimeStr(CurrContents.TotalLength));
        WinSetDlgItemText(hwnd, ID_IN_CDSTART, GetTimeStr(CurrContents.StartPosition));

        for ( i = 0; i < min(CurrContents.TotalTracks - Offset, INFO_TRACKS); i++) {
            WinSetDlgItemText(hwnd, ID_IN_TRACKSTART + i,
                GetTimeStr(CurrContents.Track[i+Offset].Start));
            WinSetDlgItemText(hwnd, ID_IN_TRACKLENGTH + i,
                GetTimeStr(CurrContents.Track[i+Offset].Length));
            }
        return NULL;

      case WM_VSCROLL :
        if ( SHORT1FROMMP(mp1) == ID_IN_SCROLLBAR ) {
            switch ( SHORT2FROMMP(mp2) ) {
              case SB_LINEUP :
                if ( Offset > 0) {
                    Offset--;
                    WinSendMsg(hwndINScrollbar, SBM_SETPOS,
                        MPFROMSHORT(Offset), NULL);
                    WinSendMsg(hwnd, IN_SCROLL, NULL, NULL);
                    }
                break;

              case SB_LINEDOWN :
                if ( Offset + INFO_TRACKS < CurrContents.TotalTracks ) {
                    Offset++;
                    WinSendMsg(hwndINScrollbar, SBM_SETPOS,
                        MPFROMSHORT(Offset), NULL);
                    WinSendMsg(hwnd, IN_SCROLL, NULL, NULL);
                    }
                break;

              case SB_PAGEUP :
                if ( Offset > 0) {
                    Offset -= min(Offset, INFO_TRACKS);

                    WinSendMsg(hwndINScrollbar, SBM_SETPOS,
                        MPFROMSHORT(Offset), NULL);
                    WinSendMsg(hwnd, IN_SCROLL, NULL, NULL);
                    }
                break;

              case SB_PAGEDOWN :
                if ( Offset + INFO_TRACKS < CurrContents.TotalTracks ) {
                    Offset += min(CurrContents.TotalTracks - (Offset + INFO_TRACKS),
                        INFO_TRACKS);

                    WinSendMsg(hwndINScrollbar, SBM_SETPOS,
                        MPFROMSHORT(Offset), NULL);
                    WinSendMsg(hwnd, IN_SCROLL, NULL, NULL);
                    }
                break;

            case SB_SLIDERPOSITION :
                if ( Offset != SHORT1FROMMP(mp2) ) {
                    Offset = SHORT1FROMMP(mp2);

                    WinSendMsg(hwndINScrollbar, SBM_SETPOS,
                        MPFROMSHORT(Offset), NULL);
                    WinSendMsg(hwnd, IN_SCROLL, NULL, NULL);
                    }
                break;

            case SB_SLIDERTRACK :
                if ( Offset != SHORT1FROMMP(mp2) ) {
                    Offset = SHORT1FROMMP(mp2);

//                    WinSendMsg(hwndINScrollbar, SBM_SETPOS,
//                        MPFROMSHORT(Offset), NULL);
                    WinSendMsg(hwnd, IN_SCROLL, NULL, NULL);
                    }
                break;
                }
            }
        return NULL;

      case WM_COMMAND :
        switch ( SHORT1FROMMP(mp1) ) {
          case ID_IN_QUIT :
            WinSendMsg(hwndMainHelp, HM_DISMISS_WINDOW, NULL, NULL);
            WinSetWindowPos(hwnd, HWND_TOP, 0, 0, 0, 0, SWP_HIDE);
            InfoHidden = TRUE;
            WinSetFocus(HWND_DESKTOP, hwndDlg);
            break;

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
        return MRFROMSHORT(PANEL_IN_KEYBOARD);

      case WM_CLOSE :
        WinSendMsg(hwndMainHelp, HM_DISMISS_WINDOW, NULL, NULL);
        WinSetWindowPos(hwnd, HWND_TOP, 0, 0, 0, 0, SWP_HIDE);
        InfoHidden = TRUE;
        WinSetFocus(HWND_DESKTOP, hwndDlg);
        return NULL;

      case WM_DESTROY :
        if ( InfoDlgAccelTable != NULLHANDLE ) {
            bResult = WinDestroyAccelTable(InfoDlgAccelTable);
            }
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

        if ( SaveWindowPos && InfoInProcess && (PSwp->fl & (SWP_MOVE | SWP_SIZE)) ) {
            if ( PSwp->fl & (SWP_MINIMIZE | SWP_HIDE) ) {
                }
            else {
                CDPrfSaveWindowPos(CDWINDOW_INFO, PSwp->x, PSwp->y, PSwp->cx, PSwp->cy,
                    WINDOWSTATE_NORMAL);
                }
            }

        if ( PSwp->fl & (SWP_HIDE | SWP_MINIMIZE) ) {
            WinSendMsg(hwndMainHelp, HM_DISMISS_WINDOW, NULL, NULL);
            InfoHidden = TRUE;
            WinSetFocus(HWND_DESKTOP, hwndDlg);
            }

        return WinDefDlgProc(hwnd, msg, mp1, mp2);

      default :
        return WinDefDlgProc(hwnd, msg, mp1, mp2);
        }
}

MRESULT EXPENTRY FGBoxProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2)
{
    HPS hps;
    RECTL Rect;
    LONG Color;
    LONG lPSid;

    switch ( msg ) {
      case WM_PAINT :
        hps = WinBeginPaint(hwnd, NULL, NULL);
        lPSid = GpiSavePS(hps);
        GpiResetPS(hps, GRES_ATTRS);
        GpiCreateLogColorTable(hps, 0L, LCOLF_RGB, 0L, 0L, NULL);
        WinQueryWindowRect(hwnd, &Rect);
        Color = WinQuerySysColor(HWND_DESKTOP, SYSCLR_WINDOWSTATICTEXT, 0);
        WinDrawBorder(hps, &Rect, 1, 1, Color, 0, 0);
        GpiRestorePS(hps, lPSid);
        WinEndPaint(hps);
        return NULL;
        }

    return OldFGBoxProc(hwnd, msg, mp1, mp2);
}

MRESULT EXPENTRY BGBoxProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2)
{
    HPS hps;
    RECTL Rect;
    LONG Color;
    LONG lPSid;

    switch ( msg ) {
      case WM_PAINT :
        hps = WinBeginPaint(hwnd, NULL, NULL);
        lPSid = GpiSavePS(hps);
        GpiResetPS(hps, GRES_ATTRS);
        GpiCreateLogColorTable(hps, 0L, LCOLF_RGB, 0L, 0L, NULL);
        WinQueryWindowRect(hwnd, &Rect);
        Color = WinQuerySysColor(HWND_DESKTOP, SYSCLR_DIALOGBACKGROUND, 0);
        WinDrawBorder(hps, &Rect, 1, 1, Color, 0, 0);
        GpiRestorePS(hps, lPSid);
        WinEndPaint(hps);
        return NULL;
        }

    return OldBGBoxProc(hwnd, msg, mp1, mp2);
}

