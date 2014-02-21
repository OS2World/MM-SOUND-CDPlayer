#if !(defined(_CDGLOBAL_INCLUDED))
#define _CDGLOBAL_INCLUDED

#if !(defined(DEBUG))
#if !(defined(TEST))
#if !(defined(SHAREWARE))
#if !(defined(RELEASE))
#error No target (DEBUG, TEST, SHAREWARE or RELEASE) defined
#endif
#endif
#endif
#endif

#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define INCL_PM
#define INCL_BASE
#define INCL_OS2MM
#define INCL_MCIOS2
#define INCL_SW
#include <os2.h>
#include <os2me.h>
#include "cdid.h"

#define MAX_TRACKS          99
#define MAX_PLAYLIST        256
#define MAX_MARKERS         100
#define MAX_PLAYLIST_LENGTH (3000*60*60*100 - 3000)

BOOL LoadResStrings(HMODULE Module);

/* Common types */

typedef enum {
    CDSTATUS_NO_DEVICE,
    CDSTATUS_NO_CD,
    CDSTATUS_NO_AUDIO_CD,
    CDSTATUS_STOPPED,
    CDSTATUS_PLAYING,
    CDSTATUS_PAUSED
    } CDAUDIO_STATUS;

typedef struct {
    ULONG CurrTrack;
    MMTIME CDPlayed;
    MMTIME CDLeft;
    MMTIME TrackPlayed;
    MMTIME TrackLeft;
    } CDAUDIO_POSITION;

typedef struct {
    BOOL AudioCDInserted;
    BOOL IDAvailable;
    BOOL UPCAvailable;
    union {
        CHAR cID[8];
        ULONG uID[2];
        };
    ULONG UPCLength;
    CHAR UPC[32];
    ULONG TotalTracks;
    MMTIME TotalLength;
    MMTIME StartPosition;
    struct {
        BOOL IsAudioTrack;
        BOOL CopyPermitted;
        BOOL Preemphasis;
        ULONG Channels;
        MMTIME Length;
        MMTIME Start;
        } Track[MAX_TRACKS];
    } CDAUDIO_CONTENTS;

typedef struct {
    BOOL CanPlayAudio;
    BOOL CanEject;
    BOOL CanLock;
    BOOL CanSetVolume;
    BOOL CanSwapChannels;
    BOOL CanStream;
    BOOL CanProcessInternal;
    } CDAUDIO_DRIVERINFO;

typedef struct {
    ULONG TotalTracks;
    MMTIME TotalLength;
    ULONG CurrTrack;
    struct {
        ULONG ToPlay;
        MMTIME StartInPlayList;
        } Track[MAX_PLAYLIST];
    } CDAUDIO_PLAYLIST;

/*
typedef struct {
    ULONG TotalTitles;
    PSZ AccessStr;
    PSZ CDTitle;
    PSZ CDInfo;
    struct {
        PSZ Title;
        PSZ Info;
        } Track[MAX_TRACKS];
    } CDAUDIO_TITLES;
*/

typedef struct {
    USHORT VolLeft;         /* Set to -1 for unchange */
    USHORT VolRight;        /* Set to -1 for unchange */
    } CDAUDIO_VOLUME;

#define CONTENTS_SIZE(Contents) \
    (sizeof(CDAUDIO_CONTENTS) - \
     (MAX_TRACKS - (Contents).TotalTracks) * sizeof((Contents).Track[0]))
#define PLAYLIST_SIZE(PlayList) \
    (sizeof(CDAUDIO_PLAYLIST) - \
     (MAX_PLAYLIST - (PlayList).TotalTracks) * sizeof((PlayList).Track[0]))

/* Globals */

extern HAB hab;
extern HMQ hmq;
extern HWND hwndDlg;
extern HSWITCH hSwitch;
extern HPOINTER hptrIcon;

/* Resource Strings */

extern char ApplTitle[32];
extern char TitleSep[8];
extern char CDUntitled[32];
extern char CDNone[32];
extern char CDNoAudio[32];
extern char TimeUnknown[12];
extern char TrackUnknown[4];
extern char DeviceErrText[256];
extern char ApplKillText[256];
extern char AboutText[32];
extern char PlayerText[32];
extern char ControlText[32];
extern char MuteOffText[32];
extern char MuteOnText[32];
extern char SettingsText[32];
extern char HelpText[32];
extern char ProgramPath[260];
extern char IniFileName[32];
extern char TabDisplay[64];
extern char TabAnimation[64];
extern char TabSave[64];
extern char TabOutput[64];
extern char TabOutputDest[64];
extern char TabDevice[64];
extern char PageOneOfOne[64];
extern char LibraryText[32];
extern char ChangeText[32];
extern char HelpTitle[48];
extern char ProgramSave[64];
extern char CDDeleteText[96];
extern char ImportText[32];
extern char DeleteText[32];
extern char NoneText[16];
extern char SharewareText[512];
extern char TELibraryText[64];
extern char TEChangeText[64];
extern char NoDeviceText[32];
extern char RegisteredForText[32];
extern char UnderText[32];
extern char UserNameText[64];
extern char RegIDText[16];
extern char WrongRegText[512];
extern char RightRegText[512];

/* Settings data: */

#define HHMMSS      0
#define MMSSFF      1

/*
#define CDOUTPUT_HEADPHONES     0
#define CDOUTPUT_SOUNDCARD      1
#define CDOUTPUT_AMPLIFIER      2
*/

extern ULONG TimeFormat;
extern int TimeSeparator;

extern ULONG TimeRefreshRate;

extern BOOL AutoRepeat;
extern BOOL AutoStart;

extern ULONG BackwardThreshold;

extern BOOL SaveWindowPos;
extern BOOL SaveVolume;
extern BOOL SavePosition;
extern BOOL SaveMarkers;

extern BOOL AnimationOn;
extern ULONG AnimationRate;

extern BOOL ListBoxAnimation;

extern BOOL OutputHeadphones;
extern BOOL OutputSoundcard;
extern BOOL OutputExtAmp;

extern BOOL LockWhilePlay;
extern char DeviceName[32];
extern char DefaultDeviceName[];

extern char TrackNumberPrecedence[];

/* Main Dialog Control Windows */

extern HWND hwndTextCD;
extern HWND hwndCDTimePlayed;
extern HWND hwndCDTimeLeft;
extern HWND hwndTextTrack;
extern HWND hwndTrackTimePlayed;
extern HWND hwndTrackTimeLeft;
extern HWND hwndTextCurrTrack;
extern HWND hwndCurrTrack;
extern HWND hwndTrackSet;
extern HWND hwndTrackSetScrollBar;
extern HWND hwndVolumeLeft;
extern HWND hwndVolumeRight;
extern HWND hwndChannelIndependent;
extern HWND hwndChannelSwap;
extern HWND hwndMute;
extern HWND hwndChangeTitles;
extern HWND hwndProgramTitles;
extern HWND hwndInfoWindow;
extern HWND hwndOptions;
extern HWND hwndTextTitle;
extern HWND hwndTitleSelect;
extern HWND hwndTimeSlider;
extern HWND hwndBackward;
extern HWND hwndForward;
extern HWND hwndPlay;
extern HWND hwndPause;
extern HWND hwndStop;
extern HWND hwndEject;
extern HWND hwndRepeat;
extern HWND hwndHelp;
extern HWND hwndMainHelp;

/* Menus & Accelators*/

extern HWND MainMenu;
extern HWND ControlMenu;
extern HWND SettingsMenu;
extern HWND HelpMenu;
extern HWND sysSubmenu;
extern HACCEL DlgAccelTable;

/* Other Dialogs: */

extern HWND SettingsDlg;
extern HWND TitleEditorDlg;
extern HWND ProgramEditorDlg;
extern HWND InfoDlg;

/* Flags */

extern BOOL Registered;
extern BOOL SliderSet;
extern BOOL Busy;
extern BOOL TimeSliderDragged;
extern BOOL SeekInPause;
extern BOOL WinTimerStarted;
extern BOOL SettingsDlgInProcess;
extern BOOL SettingsDlgHidden;
extern BOOL TitleEditorInProcess;
extern BOOL TitleEditorHidden;
extern BOOL ProgramEditorInProcess;
extern BOOL ProgramEditorHidden;
extern BOOL InfoInProcess;
extern BOOL InfoHidden;

/* TrackSet Data */
extern ULONG VirtRows;
extern ULONG VirtRowOffset;
extern USHORT TrackSetCurrRow;
extern USHORT TrackSetCurrCol;

extern BOOL ModalProcessing;
extern HWND CurrModalOwner;
extern USHORT CurrModalID;

#define strdup strdup2

_Inline char *strdup2(char *Str)
{
    char *NewStr = malloc(strlen(Str)+1);
    strcpy(NewStr, Str);
    return NewStr;
}

#endif
