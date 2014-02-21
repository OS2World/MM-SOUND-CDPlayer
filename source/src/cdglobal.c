#include "cdglobal.h"

HAB hab;
HMQ hmq;
HWND hwndDlg;
HSWITCH hSwitch;
HPOINTER hptrIcon;

/* Resource Strings */

char ApplTitle[32];
char TitleSep[8];
char CDUntitled[32];
char CDNone[32];
char CDNoAudio[32];
char TimeUnknown[12];
char TrackUnknown[4];
char DeviceErrText[256];
char ApplKillText[256];
char AboutText[32];
char PlayerText[32];
char ControlText[32];
char MuteOffText[32];
char MuteOnText[32];
char SettingsText[32];
char HelpText[32];
char ProgramPath[260];
char IniFileName[32];
char TabDisplay[64];
char TabAnimation[64];
char TabSave[64];
char TabOutput[64];
char TabOutputDest[64];
char TabDevice[64];
char PageOneOfOne[64];
char LibraryText[32];
char ChangeText[32];
char HelpTitle[48];
char ProgramSave[64];
char CDDeleteText[96];
char ImportText[32];
char DeleteText[32];
char NoneText[16];
char SharewareText[512];
char TELibraryText[64]; 
char TEChangeText[64];  
char NoDeviceText[32];
char RegisteredForText[32];
char UnderText[32];
char UserNameText[64];
char RegIDText[16];
char WrongRegText[512];
char RightRegText[512];

/* Settings data: */

ULONG TimeFormat = HHMMSS;
int TimeSeparator = ':';
ULONG TimeRefreshRate = 1000;

BOOL AutoRepeat = FALSE;
BOOL AutoStart = FALSE;

ULONG BackwardThreshold = 2;

BOOL SaveWindowPos = FALSE;
BOOL SaveVolume = FALSE;
BOOL SavePosition = FALSE;
BOOL SaveMarkers = FALSE;

BOOL AnimationOn = TRUE;
ULONG AnimationRate = 25;

BOOL ListBoxAnimation = TRUE;

BOOL OutputHeadphones = TRUE;
BOOL OutputSoundcard = TRUE;
BOOL OutputExtAmp = FALSE;

BOOL LockWhilePlay = FALSE;
char DeviceName[32];
char DefaultDeviceName[] = "CDaudio";

char TrackNumberPrecedence[] = "[ %d ] - ";

/* Main Dialog Control Windows */

HWND hwndTextCD;
HWND hwndCDTimePlayed;
HWND hwndCDTimeLeft;
HWND hwndTextTrack;
HWND hwndTrackTimePlayed;
HWND hwndTrackTimeLeft;
HWND hwndTextCurrTrack;
HWND hwndCurrTrack;
HWND hwndTrackSet;
HWND hwndTrackSetScrollBar;
HWND hwndVolumeLeft;
HWND hwndVolumeRight;
HWND hwndChannelIndependent;
HWND hwndChannelSwap;
HWND hwndMute;
HWND hwndChangeTitles;
HWND hwndProgramTitles;
HWND hwndInfoWindow;
HWND hwndOptions;
HWND hwndTextTitle;
HWND hwndTitleSelect;
HWND hwndTimeSlider;
HWND hwndBackward;
HWND hwndForward;
HWND hwndPlay;
HWND hwndPause;
HWND hwndStop;
HWND hwndEject;
HWND hwndRepeat;
HWND hwndHelp;
HWND hwndMainHelp;

/* Menus & Accelators*/

HWND MainMenu;
HWND ControlMenu;
HWND SettingsMenu;
HWND HelpMenu;
HWND sysSubmenu;
HACCEL DlgAccelTable;

/* Other Dialogs: */

HWND SettingsDlg;
HWND TitleEditorDlg;
HWND ProgramEditorDlg;
HWND InfoDlg;

/* Flags */

BOOL Registered;
BOOL SliderSet;
BOOL Busy;
BOOL TimeSliderDragged;
BOOL SeekInPause;
BOOL WinTimerStarted;
BOOL SettingsDlgInProcess;
BOOL SettingsDlgHidden;
BOOL TitleEditorInProcess;
BOOL TitleEditorHidden;
BOOL ProgramEditorInProcess;
BOOL ProgramEditorHidden;
BOOL InfoInProcess;
BOOL InfoHidden;
// MMTIME CuePointSet;

/* TrackSet Data */
ULONG VirtRows;
ULONG VirtRowOffset;
USHORT TrackSetCurrRow;
USHORT TrackSetCurrCol;

/* Modals */
BOOL ModalProcessing = FALSE;
HWND CurrModalOwner;
USHORT CurrModalID;

BOOL LoadResStrings(HMODULE Module)
{
    LONG Length;
    BOOL bResult = TRUE;

    Length = WinLoadString(hab, Module, IDS_APPL, sizeof(ApplTitle), ApplTitle);
    bResult = bResult && (Length != 0);

    Length = WinLoadString(hab, Module, IDS_TITLE_SEP, sizeof(TitleSep), TitleSep);
    bResult = bResult && (Length != 0);

    Length = WinLoadString(hab, Module, IDS_CDUNTITLED, sizeof(CDUntitled), CDUntitled);
    bResult = bResult && (Length != 0);

    Length = WinLoadString(hab, Module, IDS_CDNONE, sizeof(CDNone), CDNone);
    bResult = bResult && (Length != 0);

    Length = WinLoadString(hab, Module, IDS_CDNOAUDIO, sizeof(CDNoAudio), CDNoAudio);
    bResult = bResult && (Length != 0);

    Length = WinLoadString(hab, Module, IDS_TIME_UNKNOWN, sizeof(TimeUnknown), TimeUnknown);
    bResult = bResult && (Length != 0);

    Length = WinLoadString(hab, Module, IDS_TRACK_UNKNOWN, sizeof(TrackUnknown), TrackUnknown);
    bResult = bResult && (Length != 0);

    Length = WinLoadString(hab, Module, IDS_MMDEVICEERR, sizeof(DeviceErrText), DeviceErrText);
    bResult = bResult && (Length != 0);

    Length = WinLoadString(hab, Module, IDS_APPLKILL, sizeof(ApplKillText), ApplKillText);
    bResult = bResult && (Length != 0);

    Length = WinLoadString(hab, Module, IDS_ABOUTTEXT, sizeof(AboutText), AboutText);
    bResult = bResult && (Length != 0);

    Length = WinLoadString(hab, Module, IDS_PLAYERTEXT, sizeof(PlayerText), PlayerText);
    bResult = bResult && (Length != 0);

    Length = WinLoadString(hab, Module, IDS_CONTROL, sizeof(ControlText), ControlText);
    bResult = bResult && (Length != 0);

    Length = WinLoadString(hab, Module, IDS_MUTEOFF, sizeof(MuteOffText), MuteOffText);
    bResult = bResult && (Length != 0);

    Length = WinLoadString(hab, Module, IDS_MUTEON, sizeof(MuteOnText), MuteOnText);
    bResult = bResult && (Length != 0);

    Length = WinLoadString(hab, Module, IDS_SETTINGS, sizeof(SettingsText), SettingsText);
    bResult = bResult && (Length != 0);

    Length = WinLoadString(hab, Module, IDS_HELP, sizeof(HelpText), HelpText);
    bResult = bResult && (Length != 0);

    Length = WinLoadString(hab, Module, IDS_INIFILE, sizeof(IniFileName), IniFileName);
    bResult = bResult && (Length != 0);

    Length = WinLoadString(hab, Module, IDS_TABDISPLAY, sizeof(TabDisplay), TabDisplay);
    bResult = bResult && (Length != 0);

    Length = WinLoadString(hab, Module, IDS_TABANIMATION, sizeof(TabAnimation), TabAnimation);
    bResult = bResult && (Length != 0);

    Length = WinLoadString(hab, Module, IDS_TABSAVE, sizeof(TabSave), TabSave);
    bResult = bResult && (Length != 0);

    Length = WinLoadString(hab, Module, IDS_TABOUTPUT, sizeof(TabOutput), TabOutput);
    bResult = bResult && (Length != 0);

    Length = WinLoadString(hab, Module, IDS_TABOUTPUTDEST, sizeof(TabOutputDest), TabOutputDest);
    bResult = bResult && (Length != 0);

    Length = WinLoadString(hab, Module, IDS_TABDEVICE, sizeof(TabDevice), TabDevice);
    bResult = bResult && (Length != 0);

    Length = WinLoadString(hab, Module, IDS_PAGEONEOFONE, sizeof(PageOneOfOne), PageOneOfOne);
    bResult = bResult && (Length != 0);

    Length = WinLoadString(hab, Module, IDS_CHANGE, sizeof(ChangeText), ChangeText);
    bResult = bResult && (Length != 0);
                                       
    Length = WinLoadString(hab, Module, IDS_LIBRARY, sizeof(LibraryText), LibraryText);
    bResult = bResult && (Length != 0);

    Length = WinLoadString(hab, Module, IDS_HELPTITLE, sizeof(HelpTitle), HelpTitle);
    bResult = bResult && (Length != 0);

    Length = WinLoadString(hab, Module, IDS_PROGRAMSAVE, sizeof(ProgramSave), ProgramSave);
    bResult = bResult && (Length != 0);

    Length = WinLoadString(hab, Module, IDS_CDDELETE, sizeof(CDDeleteText), CDDeleteText);
    bResult = bResult && (Length != 0);

    Length = WinLoadString(hab, Module, IDS_IMPORT, sizeof(ImportText), ImportText);
    bResult = bResult && (Length != 0);

    Length = WinLoadString(hab, Module, IDS_DELETE, sizeof(DeleteText), DeleteText);
    bResult = bResult && (Length != 0);

    Length = WinLoadString(hab, Module, IDS_NONE, sizeof(NoneText), NoneText);
    bResult = bResult && (Length != 0);

    Length = WinLoadString(hab, Module, IDS_SHAREWARE, sizeof(SharewareText), SharewareText);
    bResult = bResult && (Length != 0);

    Length = WinLoadString(hab, Module, IDS_TELIBRARY, sizeof(TELibraryText), TELibraryText);
    bResult = bResult && (Length != 0);

    Length = WinLoadString(hab, Module, IDS_TECHANGE, sizeof(TEChangeText), TEChangeText);
    bResult = bResult && (Length != 0);

    Length = WinLoadString(hab, Module, IDS_NODEVICE, sizeof(NoDeviceText), NoDeviceText);
    bResult = bResult && (Length != 0);

    Length = WinLoadString(hab, Module, IDS_REGISTEREDFOR, sizeof(RegisteredForText), RegisteredForText);
    bResult = bResult && (Length != 0);

    Length = WinLoadString(hab, Module, IDS_UNDER, sizeof(UnderText), UnderText);
    bResult = bResult && (Length != 0);

    Length = WinLoadString(hab, Module, IDS_REGWRONG, sizeof(WrongRegText), WrongRegText);
    bResult = bResult && (Length != 0);

    Length = WinLoadString(hab, Module, IDS_REGRIGHT, sizeof(RightRegText), RightRegText);
    bResult = bResult && (Length != 0);

    return bResult;
}
