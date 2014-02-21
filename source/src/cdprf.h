#if !(defined(_CDPRF_INCLUDED))
#define _CDPRF_INCLUDED

#define MAX_TITLE_LENGTH    101
#define MAX_INFO_LENGTH     4001

typedef enum {
    CDOPT_TIMEFORMAT,
    CDOPT_TIMESEPARATOR,
    CDOPT_TIMEFREQ,
    CDOPT_ANIMATION,
    CDOPT_ANIMATIONFREQ,
    CDOPT_LISTBOXANIMATION,
    CDOPT_AUTOREPEAT,
    CDOPT_AUTOSTART,
    CDOPT_BACKWARDTHRESHOLD,
    CDOPT_SAVEWINDOWPOS,
    CDOPT_SAVEVOLUME,
    CDOPT_SAVEPOSITION,
    CDOPT_SAVEMARKERS,
    CDOPT_OUTPUTHEADPHONES,
    CDOPT_OUTPUTSOUNDCARD,
    CDOPT_OUTPUTEXTAMP,
    CDOPT_LOCKWHILEPLAY,
    CDOPT_DEVICENAME,
    CDOPT_MAX
    } CDOPTION;

enum {
    CDWINDOW_MAIN,
    CDWINDOW_OPTIONS,
    CDWINDOW_PLAYLIST,
    CDWINDOW_TITLES,
    CDWINDOW_INFO,
    CDWINDOW_HELP
    };

typedef struct {
    PSZ Key;
    enum {
        OPTION_NUMERIC,
        OPTION_BOOLEAN,
        OPTION_STRING,
        OPTION_CHAR
        } Type;
    union {
        int MinValue;
        int MinLength;
        };
    union {
        int MaxValue;
        int MaxLength;
        };
    int DefValue;
    PSZ DefString;
    } OPTION_DESC;

typedef struct {
    ULONG Track;
    PSZ Title;
    } CDTITLE_CHANGE;

typedef struct {
    ULONG Track;
    PSZ Info;
    } CDINFO_CHANGE;

typedef struct {
    ULONG Track;
    MMTIME Position;
    } CDPLAYLIST_POSITION;

#define WINDOWSTATE_NORMAL      0
#define WINDOWSTATE_MINIMIZED   1
#define WINDOWSTATE_HIDDEN      2

BOOL CDPrfOpen(PSZ IniPath, PSZ IniName);
BOOL CDPrfInitOptions(void);
BOOL CDPrfSaveVolume(ULONG Left, ULONG Right);
BOOL CDPrfLoadVolume(ULONG *Left, ULONG *Right);
BOOL CDPrfSaveWindowPos(ULONG Window, ULONG x, ULONG y, ULONG cx, ULONG cy, ULONG State);
BOOL CDPrfLoadWindowPos(ULONG Window, ULONG *x, ULONG *y, ULONG *cx, ULONG *cy, ULONG *State);
BOOL CDPrfClose(void);
BOOL CDPrfGetOption(CDOPTION Option, VOID *Value);
BOOL CDPrfSetOption(HWND hwndDlg, CDOPTION Option, ULONG Value);

PSZ CDPrfQueryAccess(CDAUDIO_CONTENTS *Contents);
PSZ CDPrfQueryAccessByTitle(PSZ CDTitle, BOOL Repeat, PSZ FoundCDTitle, ULONG BufLen);
BOOL CDPrfReleaseAccess(PSZ AccessStr);
PSZ CDPrfCopyAccess(PSZ AccessStr);
BOOL CDPrfDeleteAccess(PSZ AccessStr);

BOOL CDPrfQueryCDTitle(PSZ AccessStr, PSZ Title, ULONG BufLen);
BOOL CDPrfSetCDTitle(PSZ AccessStr, PSZ Title);

BOOL CDPrfQueryCDInfo(PSZ AccessStr, PSZ Info, ULONG BufLen);
BOOL CDPrfSetCDInfo(PSZ AccessStr, PSZ Info);

BOOL CDPrfQueryTrackTitle(PSZ AccessStr, PSZ Title, ULONG BufLen, LONG Index);
BOOL CDPrfSetTrackTitle(PSZ AccessStr, PSZ Title, LONG Index);

BOOL CDPrfQueryTrackInfo(PSZ AccessStr, PSZ Info, ULONG BufLen, LONG Index);
BOOL CDPrfSetTrackInfo(PSZ AccessStr, PSZ Info, LONG Index);

BOOL CDPrfQueryPlayList(PSZ AccessStr, CDAUDIO_PLAYLIST *PlayList);
BOOL CDPrfSetPlayList(PSZ AccessStr, CDAUDIO_PLAYLIST *PlayList);

BOOL CDPrfQueryContents(PSZ AccessStr, CDAUDIO_CONTENTS *Contents);
BOOL CDPrfSetContents(PSZ AccessStr, CDAUDIO_CONTENTS *Contents);

BOOL CDPrfQueryPosition(PSZ AccessStr, ULONG *Track, MMTIME *Position);
BOOL CDPrfSetPosition(PSZ AccessStr, ULONG Track, MMTIME Position);

/*
BOOL CDPrfQueryTitles(PSZ AccessStr, ULONG MaxTitles, CDAUDIO_TITLES *Titles);
BOOL CDPrfSetTitles(PSZ AccessStr, CDAUDIO_TITLES *Titles);
*/

BOOL CDPrfTestRegData(ULONG RegID, PSZ UserName);
BOOL CDPrfSetRegData(ULONG RegID, PSZ UserName);
BOOL CDPrfQueryRegistered(PULONG RegID, PSZ UserName);

#endif // !(defined(_CDPRF_INCLUDED))
