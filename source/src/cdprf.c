#include "cdglobal.h"
#include "cdctl.h"
#include "cddevice.h"
#include "cdplayer.h"
#include "reg.h"
#include "cdprf.h"

static BOOL GetNumericOption(PSZ Appl, PSZ Key, int *Value);
static BOOL GetBoolOption(PSZ Appl, PSZ Key, BOOL *Value);
static BOOL GetStrOption(PSZ Appl, PSZ Key, char *Value, ULONG MaxLength);
static BOOL GetCharOption(PSZ Appl, PSZ Key, int *Value);
static BOOL SetNumericOption(PSZ Appl, PSZ Key, int Value);
static BOOL SetBoolOption(PSZ Appl, PSZ Key, BOOL Value);
static BOOL SetStrOption(PSZ Appl, PSZ Key, char *Value);
static BOOL SetCharOption(PSZ Appl, PSZ Key, int Value);
static PSZ MakeCDAppl(CDAUDIO_CONTENTS *Contents);
static PSZ AppendIndex(PSZ Key, ULONG Index);
static PSZ StripBlancs(PSZ String);

static HINI CDProfile = 0x12345678;

static char OptionsAppl[] = "Options";
static OPTION_DESC OptionDesc[] = {
    { "TimeFormat", OPTION_NUMERIC, HHMMSS, MMSSFF, HHMMSS, NULL },
    { "TimeSeparator", OPTION_CHAR, ' ', 0xFF, ':', NULL },
    { "TimeFrequency", OPTION_NUMERIC, 100, 60000, 1000, NULL },
    { "Animation", OPTION_BOOLEAN, FALSE, TRUE, TRUE, NULL },
    { "AnimationFrequency", OPTION_NUMERIC, 25, 10000, 25, NULL },
    { "ListBoxAnimation", OPTION_BOOLEAN, FALSE, TRUE, FALSE, NULL },
    { "AutoRepeat", OPTION_BOOLEAN, FALSE, TRUE, FALSE, NULL },
    { "AutoStart", OPTION_BOOLEAN, FALSE, TRUE, FALSE, NULL },
    { "BackwardThreshold", OPTION_NUMERIC, 0, 99999999, 2, NULL },
    { "SaveWindowPos", OPTION_BOOLEAN, FALSE, TRUE, FALSE, NULL },
    { "SaveVolume", OPTION_BOOLEAN, FALSE, TRUE, FALSE, NULL },
    { "SavePosition", OPTION_BOOLEAN, FALSE, TRUE, FALSE, NULL },
    { "SaveMarkers", OPTION_BOOLEAN, FALSE, TRUE, FALSE, NULL },
    { "OutputHeadphones", OPTION_BOOLEAN, FALSE, TRUE, TRUE, NULL },
    { "OutputSoundcard", OPTION_BOOLEAN, FALSE, TRUE, FALSE, NULL },
    { "OutputExtAmplifier", OPTION_BOOLEAN, FALSE, TRUE, FALSE, NULL },
    { "LockWhilePlaying", OPTION_BOOLEAN, FALSE, TRUE, FALSE, NULL },
    { "DeviceName", OPTION_STRING, 1, 31, 0, "CDaudio" }
    };

static char *WindowPosAppl[] = {
    "MainWindow",
    "OptionsWindow",
    "PlayListWindow",
    "TitlesWindow",
    "InfoWindow",
    "HelpWindow",
    };

static char xKey[] = "x";
static char yKey[] = "y";
static char cxKey[] = "cx";
static char cyKey[] = "cy";
static char StateKey[] = "State";

static char VolumeAppl[] = "Volume";
static char VolumeLeftKey[] = "Left";
static char VolumeRightKey[] = "Right";

static char RegAppl[] = "RegData";
static char RegIDKey[] = "ID";
static char RegUserKey[] = "Name";

static char ContentsKey[] = "Contents";
static char PlayListKey[] = "Playlist";
static char CDTitleKey[] = "CDTitle";
static char CDInfoKey[] = "CDInfo";
static char TrackTitleKey[] = "Track";
static char TrackInfoKey[] = "TrackInfo";
static char PositionKey[] = "Position";

BOOL CDPrfOpen(PSZ IniPath, PSZ IniName)
{
    char TmpBuffer[260];
    COUNTRYCODE cc;
    COUNTRYINFO ci;
    ULONG ciLen;
    APIRET aRes;

    cc.country = cc.codepage = 0;
    aRes = DosQueryCtryInfo(sizeof(COUNTRYINFO), &cc, &ci, &aRes);
    if ( aRes == 0) {
        OptionDesc[CDOPT_TIMESEPARATOR].DefValue = ci.szTimeSeparator[0];
        }

    if ( IniPath != NULL )
        strcpy(TmpBuffer, IniPath);
    else
        TmpBuffer[0] = 0;

    strcat(TmpBuffer, IniName);

    CDProfile = PrfOpenProfile(hab, TmpBuffer);

    return CDProfile != NULLHANDLE;
}

BOOL CDPrfInitOptions(void)
{
    CDPrfGetOption(CDOPT_TIMEFORMAT, &TimeFormat);
    CDPrfGetOption(CDOPT_TIMESEPARATOR, &TimeSeparator);
    CDPrfGetOption(CDOPT_TIMEFREQ, &TimeRefreshRate);
    CDPrfGetOption(CDOPT_ANIMATION, &AnimationOn);
    CDPrfGetOption(CDOPT_ANIMATIONFREQ, &AnimationRate);
    CDPrfGetOption(CDOPT_LISTBOXANIMATION, &ListBoxAnimation);
    CDPrfGetOption(CDOPT_AUTOREPEAT, &AutoRepeat);
    CDPrfGetOption(CDOPT_AUTOSTART, &AutoStart);
    CDPrfGetOption(CDOPT_BACKWARDTHRESHOLD, &BackwardThreshold);
    CDPrfGetOption(CDOPT_SAVEWINDOWPOS, &SaveWindowPos);
    CDPrfGetOption(CDOPT_SAVEVOLUME, &SaveVolume);
    CDPrfGetOption(CDOPT_SAVEPOSITION, &SavePosition);
    CDPrfGetOption(CDOPT_SAVEMARKERS, &SaveMarkers);
    CDPrfGetOption(CDOPT_OUTPUTHEADPHONES, &OutputHeadphones);
    CDPrfGetOption(CDOPT_OUTPUTSOUNDCARD, &OutputSoundcard);
    CDPrfGetOption(CDOPT_OUTPUTEXTAMP, &OutputExtAmp);
    CDPrfGetOption(CDOPT_LOCKWHILEPLAY, &LockWhilePlay);
    CDPrfGetOption(CDOPT_DEVICENAME, DeviceName);

    return TRUE;
}

BOOL CDPrfSaveVolume(ULONG Left, ULONG Right)
{
    if ( ! SetNumericOption(VolumeAppl, VolumeLeftKey, (int)Left) )
        return FALSE;
    if ( ! SetNumericOption(VolumeAppl, VolumeRightKey, (int)Right) )
        return FALSE;

    return TRUE;
}
 

BOOL CDPrfLoadVolume(ULONG *Left, ULONG *Right)
{
    if ( ! GetNumericOption(VolumeAppl, VolumeLeftKey, (int *)Left) || *Left > 100 ) {
        return FALSE;
        }

    if ( ! GetNumericOption(VolumeAppl, VolumeRightKey, (int *)Right) || *Right > 100 ) {
        return FALSE;
        }

    return TRUE;
}

BOOL CDPrfSaveWindowPos(ULONG Window, ULONG x, ULONG y, ULONG cx, ULONG cy, ULONG State)
{
    if ( ! SetNumericOption(WindowPosAppl[Window], StateKey, (int)State) )
            return FALSE;

    if ( State == WINDOWSTATE_NORMAL ) {
        if ( ! SetNumericOption(WindowPosAppl[Window], xKey, (int)x) )
            return FALSE;

        if ( ! SetNumericOption(WindowPosAppl[Window], yKey, (int)y) )
            return FALSE;

        if ( ! SetNumericOption(WindowPosAppl[Window], cxKey, (int)cx) )
            return FALSE;

        if ( ! SetNumericOption(WindowPosAppl[Window], cyKey, (int)cy) )
            return FALSE;

        }

    return TRUE;
}

BOOL CDPrfLoadWindowPos(ULONG Window, ULONG *x, ULONG *y, ULONG *cx, ULONG *cy, ULONG *State)
{
    if ( ! GetNumericOption(WindowPosAppl[Window], StateKey, (int *)State) ||
          *State > WINDOWSTATE_HIDDEN )
        return FALSE;

    if ( ! GetNumericOption(WindowPosAppl[Window], xKey, (int *)x) || *x > 4096 )
        return FALSE;
 
    if ( ! GetNumericOption(WindowPosAppl[Window], yKey, (int *)y) || *y > 4096 )
        return FALSE;
 
    if ( ! GetNumericOption(WindowPosAppl[Window], cxKey, (int *)cx) || *cx > 4096 )
        return FALSE;
 
    if ( ! GetNumericOption(WindowPosAppl[Window], cyKey, (int *)cy) || *cy > 4096 )
        return FALSE;
 
    return TRUE;
}

BOOL CDPrfGetOption(CDOPTION Option, VOID *Value)
{
    if ( Option < 0 || Option >= CDOPT_MAX )
        return FALSE;

    switch ( OptionDesc[Option].Type ) {
      case OPTION_NUMERIC :
        if ( ! GetNumericOption(OptionsAppl, OptionDesc[Option].Key, (int *)Value) ||
             *(int *)Value < OptionDesc[Option].MinValue ||
             *(int *)Value > OptionDesc[Option].MaxValue ) {
            *(int *)Value = OptionDesc[Option].DefValue;
            }
        break;

      case OPTION_BOOLEAN :
        if ( ! GetBoolOption(OptionsAppl, OptionDesc[Option].Key, (BOOL *)Value) ) {
            *(BOOL *)Value = OptionDesc[Option].DefValue;
            }
        break;

      case OPTION_STRING :
        if ( ! GetStrOption(OptionsAppl, OptionDesc[Option].Key, 
                (PSZ)Value, OptionDesc[Option].MaxLength) ||
             strlen((PSZ)Value) < OptionDesc[Option].MinLength ||
             strlen((PSZ)Value) > OptionDesc[Option].MaxLength ) {
            strcpy((PSZ)Value, OptionDesc[Option].DefString);
            }
        break;

      case OPTION_CHAR :
        if ( ! GetCharOption(OptionsAppl, OptionDesc[Option].Key, (int *)Value) ||
             *(int *)Value < OptionDesc[Option].MinValue ||
             *(int *)Value > OptionDesc[Option].MaxValue ) {
            *(int *)Value = OptionDesc[Option].DefValue;
            }
        break;
        } /* endswitch */

    return TRUE;
}

BOOL CDPrfSetOption(HWND hwndDlg, CDOPTION Option, ULONG Value)
{
    BOOL bResult = FALSE;

    if ( Option < 0 || Option >= CDOPT_MAX )
        return FALSE;

    switch ( OptionDesc[Option].Type ) {
      case OPTION_NUMERIC :
      case OPTION_CHAR :
        if ( (int)Value < OptionDesc[Option].MinValue ||
             (int)Value > OptionDesc[Option].MaxValue )
            return FALSE;
        break;

      case OPTION_BOOLEAN :
        Value = (Value != FALSE);
        break;

      case OPTION_STRING :
        if ( strlen((PSZ)Value) < OptionDesc[Option].MinLength ||
             strlen((PSZ)Value) > OptionDesc[Option].MaxLength )
            return FALSE;
        break;

      default:
        bResult = FALSE;
        }

    bResult = LONGFROMMR(WinSendMsg(hwndDlg, CD_OPTIONCHANGED, 
        MPFROMLONG(Option), MPFROMLONG(Value)));
    if ( ! bResult )
        return FALSE;

    switch ( OptionDesc[Option].Type ) {
      case OPTION_NUMERIC :
        bResult = SetNumericOption(OptionsAppl, OptionDesc[Option].Key, (int)Value);
        break;

      case OPTION_BOOLEAN :
        bResult = SetBoolOption(OptionsAppl, OptionDesc[Option].Key, (BOOL)Value);
        break;

      case OPTION_STRING :
        bResult = SetStrOption(OptionsAppl, OptionDesc[Option].Key, (PSZ)Value);
        break;

      case OPTION_CHAR :
        bResult = SetCharOption(OptionsAppl, OptionDesc[Option].Key, (int)Value);
        break;
        }

    return bResult;
}

BOOL CDPrfClose(void)
{
    if ( CDProfile != NULLHANDLE )
        return PrfCloseProfile(CDProfile);
    else
        return FALSE;
}

PSZ CDPrfQueryAccess(CDAUDIO_CONTENTS *Contents)
{
    PSZ CDAppl;
    ULONG DataLen;
    int CDApplLen, CurrApplLen, MaxIndex = 1, CurrIndex;
    PSZ ApplNames, CurrAppl;
    BOOL Found = FALSE;
    CDAUDIO_CONTENTS FoundContents;
    BOOL bResult;

    CDAppl = MakeCDAppl(Contents);
    if ( CDAppl == NULL )
        return FALSE;

    CDApplLen = strlen(CDAppl);

    bResult = PrfQueryProfileSize(CDProfile, NULL, NULL, &DataLen);
    if ( ! bResult ) {
        free(CDAppl);
        return NULL;
        }

    if ( DataLen == 0 ) {
        strcat(CDAppl, "1");
        bResult = PrfWriteProfileData(CDProfile, CDAppl, ContentsKey,
            Contents, CONTENTS_SIZE(*Contents));
        if ( bResult) {
            return CDAppl;
            }
        else {
            free(CDAppl);
            return NULL;
            }
        }

    ApplNames = malloc(DataLen);
    if ( ApplNames == NULL ) {
        free(CDAppl);
        return NULL;
        }

    bResult = PrfQueryProfileData(CDProfile, NULL, NULL, ApplNames, &DataLen);
    if ( ! bResult ) {
        free(CDAppl);
        return NULL;
        }

    CurrAppl = ApplNames;

    while ( (CurrApplLen = strlen(CurrAppl)) > 0 ) {
        if ( CurrApplLen > CDApplLen && ! strncmp(CurrAppl, CDAppl, CDApplLen) ) {
            DataLen = sizeof(CDAUDIO_CONTENTS);
            FoundContents.TotalTracks = 0;
            bResult = PrfQueryProfileData(CDProfile, CurrAppl, ContentsKey,
                &FoundContents, &DataLen);

            if ( bResult &&
                 DataLen == CONTENTS_SIZE(FoundContents) &&
                 FoundContents.TotalTracks == Contents->TotalTracks &&
                 ! memcmp(&(FoundContents.TotalTracks), 
                          &(Contents->TotalTracks), 
                          CONTENTS_SIZE(FoundContents) - 
                                ((BYTE *)&(FoundContents.TotalTracks) - (BYTE *)&FoundContents)) ) {

                Found = TRUE;
                break;
                }
            else {
                CurrIndex = atoi(CurrAppl+CDApplLen);
                if ( CurrIndex > MaxIndex )
                    MaxIndex = CurrIndex + 1;
                } /* endif */
            }
 
        CurrAppl += CurrApplLen+1;
        }

    if ( Found ) {
        strcpy(CDAppl, CurrAppl);

        if ( memcmp(&FoundContents, Contents,
                    ((BYTE *)&(FoundContents.TotalTracks) - (BYTE *)&FoundContents)) ) {
            bResult = PrfWriteProfileData(CDProfile, CDAppl, ContentsKey,
                Contents, CONTENTS_SIZE(*Contents));
            free(ApplNames);
            if ( bResult) {
                return CDAppl;
                }
            else {
                free(CDAppl);
                return NULL;
                }
            }

        free(ApplNames);
        return CDAppl;
        }
    else {
        free(ApplNames);
        itoa(MaxIndex, CDAppl+CDApplLen, 10);
        bResult = PrfWriteProfileData(CDProfile, CDAppl, ContentsKey,
            Contents, CONTENTS_SIZE(*Contents));
        if ( bResult) {
            return CDAppl;
            } 
        else {
            free(CDAppl);
            return NULL;
            }
        }
}

PSZ CDPrfQueryAccessByTitle(PSZ CDTitle, BOOL Repeat, PSZ FoundCDTitle, ULONG BufLen)
{
    static char NullAppl[] = "\0\0";
    static PSZ ApplNames = NullAppl;
    static PSZ CurrAppl = NullAppl;
    ULONG DataLen;
    int CurrApplLen;
    BOOL bResult, Found = FALSE;
    static char TitleBuffer[MAX_TITLE_LENGTH];
    char TestContents[2];

    if ( ! Repeat ) {
        bResult = PrfQueryProfileSize(CDProfile, NULL, NULL, &DataLen);
        if ( ! bResult ) {
            return NULL;
            }

        if ( DataLen == 0 ) {
            CurrAppl = ApplNames = NullAppl;
            return NULL;
            }

        ApplNames = malloc(DataLen);
        if ( ApplNames == NULL ) {
            CurrAppl = ApplNames = NullAppl;
            return NULL;
            }

        bResult = PrfQueryProfileData(CDProfile, NULL, NULL, ApplNames, &DataLen);
        if ( ! bResult ) {
            free(ApplNames);
            CurrAppl = ApplNames = NullAppl;
            return NULL;
            }

        CurrAppl = ApplNames;
        }

     while ( (CurrApplLen = strlen(CurrAppl)) > 0 ) {
        DataLen = 1;
        bResult = PrfQueryProfileData(CDProfile, CurrAppl, ContentsKey,
            &TestContents, &DataLen);

        if ( bResult ) {
            bResult = PrfQueryProfileString(CDProfile, CurrAppl, CDTitleKey, NULL,
                TitleBuffer, sizeof(TitleBuffer));

            if ( bResult &&
                 (CDTitle == NULL || ! strcmp(CDTitle, TitleBuffer)) ) {
                Found = TRUE;
                if ( CDTitle == NULL && FoundCDTitle != NULL ) {
                    strncpy(FoundCDTitle, TitleBuffer, BufLen);
                    FoundCDTitle[BufLen-1] = 0;
                    }
                break;
                }
            else if ( CDTitle == NULL || ! strcmp(CDTitle, CDUntitled) ) {
                Found = TRUE;
                if ( CDTitle == NULL && FoundCDTitle != NULL ) {
                    strncpy(FoundCDTitle, CDUntitled, BufLen);
                    FoundCDTitle[BufLen-1] = 0;
                    }
                break;
                }
            }

        CurrAppl += CurrApplLen+1;
        }

    if ( Found ) {
        CurrAppl += CurrApplLen+1;
        return strdup(CurrAppl - CurrApplLen - 1);
        }
    else {
        free(ApplNames);
        CurrAppl = ApplNames = NullAppl;
        return NULL;
        }
}

BOOL CDPrfReleaseAccess(PSZ AccessStr)
{
    free(AccessStr);

    return TRUE;
}

PSZ CDPrfCopyAccess(PSZ AccessStr)
{
    return strdup(AccessStr);
}

BOOL CDPrfDeleteAccess(PSZ AccessStr)
{
    BOOL bResult;
    MRESULT ActTest;
    ULONG i;
    static CDAUDIO_CONTENTS Contents;
    CDTITLE_CHANGE Change;

    bResult = CDPrfQueryContents(AccessStr, &Contents);
    if ( bResult ) {
        Change.Track = 0;
        Change.Title = NULL;

        ActTest = WinSendMsg(hwndDlg, CD_TITLECHANGED, MPFROMP(AccessStr),
            MPFROMP(&Change));

        if ( ProgramEditorInProcess )
            WinSendMsg(ProgramEditorDlg, PE_TITLECHANGED, MPFROMP(AccessStr),
                MPFROMP(&Change));

        for ( i = 1; i <= Contents.TotalTracks; i++ ) {
            Change.Track = i;
            Change.Title = NULL;

            WinSendMsg(hwndDlg, CD_TITLECHANGED, MPFROMP(AccessStr), MPFROMP(&Change));
            if ( ProgramEditorInProcess )
                WinSendMsg(ProgramEditorDlg, PE_TITLECHANGED, MPFROMP(AccessStr), 
                    MPFROMP(&Change));
            }
        }
 
    bResult = PrfWriteProfileData(CDProfile, AccessStr, NULL, NULL, 0);
 
    if ( LONGFROMMR(ActTest) )
        bResult = CDPrfSetContents(AccessStr, &Contents);

    free(AccessStr);

    return bResult;
}

BOOL CDPrfQueryCDTitle(PSZ AccessStr, PSZ Title, ULONG BufLen)
{
    BOOL bResult;

    if ( Title == NULL )
        return FALSE;

    bResult = PrfQueryProfileString(CDProfile, AccessStr, CDTitleKey, NULL,
        Title, BufLen);

    if ( ! bResult && BufLen > 0 )
        Title[0] = 0;

    return bResult;
}

BOOL CDPrfSetCDTitle(PSZ AccessStr, PSZ Title)
{
    BOOL bResult;
    CDTITLE_CHANGE Change;

    Title = StripBlancs(Title);

    bResult = PrfWriteProfileString(CDProfile, AccessStr, CDTitleKey, Title);

    if ( bResult ) {
        Change.Track = 0;
        Change.Title = Title;
        WinSendMsg(hwndDlg, CD_TITLECHANGED, MPFROMP(AccessStr), MPFROMP(&Change));
        if ( ProgramEditorInProcess )
            WinSendMsg(ProgramEditorDlg, PE_TITLECHANGED, MPFROMP(AccessStr), MPFROMP(&Change));
        }

    return bResult;
}

BOOL CDPrfQueryCDInfo(PSZ AccessStr, PSZ Info, ULONG BufLen)
{
    BOOL bResult;

    if ( Info == NULL )
        return FALSE;

    bResult = PrfQueryProfileString(CDProfile, AccessStr, CDInfoKey, NULL,
        Info, BufLen);

    if ( ! bResult && BufLen > 0 )
        Info[0] = 0;

    return bResult;
}

BOOL CDPrfSetCDInfo(PSZ AccessStr, PSZ Info)
{
    BOOL bResult;
    CDINFO_CHANGE Change;

    Info = StripBlancs(Info);

    bResult = PrfWriteProfileString(CDProfile, AccessStr, CDInfoKey, Info);

    if ( bResult ) {
        Change.Track = 0;
        Change.Info = Info;
        WinSendMsg(hwndDlg, CD_INFOCHANGED, MPFROMP(AccessStr), MPFROMP(&Change));
        }

    return bResult;
}


BOOL CDPrfQueryTrackTitle(PSZ AccessStr, PSZ Title, ULONG BufLen, LONG Index)
{
    BOOL bResult;

    if ( Index < 1 || Index > MAX_TRACKS )
        return FALSE;

    if ( Title == NULL )
        return FALSE;

    bResult = PrfQueryProfileString(CDProfile, AccessStr, 
        AppendIndex(TrackTitleKey, Index), NULL, Title, BufLen);

    if ( ! bResult && BufLen > 0 )
        Title[0] = 0;

    return bResult;
}

BOOL CDPrfSetTrackTitle(PSZ AccessStr, PSZ Title, LONG Index)
{
    BOOL bResult;
    CDTITLE_CHANGE Change;

    if ( Index < 1 || Index > MAX_TRACKS )
        return FALSE;

    Title = StripBlancs(Title);

    bResult = PrfWriteProfileString(CDProfile, AccessStr,
        AppendIndex(TrackTitleKey, Index), Title);

    if ( bResult ) {
        Change.Track = Index;
        Change.Title = Title;
        WinSendMsg(hwndDlg, CD_TITLECHANGED, MPFROMP(AccessStr), MPFROMP(&Change));
        if ( ProgramEditorInProcess )
            WinSendMsg(ProgramEditorDlg, PE_TITLECHANGED, MPFROMP(AccessStr), MPFROMP(&Change));
        }

    return bResult;
}

BOOL CDPrfQueryTrackInfo(PSZ AccessStr, PSZ Info, ULONG BufLen, LONG Index)
{
    BOOL bResult;

    if ( Index < 1 || Index > MAX_TRACKS )
        return FALSE;

    if ( Info == NULL )
        return FALSE;

    bResult = PrfQueryProfileString(CDProfile, AccessStr,  
        AppendIndex(TrackInfoKey, Index), NULL, Info, BufLen);

    if ( ! bResult && BufLen > 0 ) {
        Info[0] = 0;
        }

    return bResult;
}

BOOL CDPrfSetTrackInfo(PSZ AccessStr, PSZ Info, LONG Index)
{
    BOOL bResult;
    CDINFO_CHANGE Change;

    if ( Index < 1 || Index > MAX_TRACKS )
        return FALSE;

    Info = StripBlancs(Info);

    bResult = PrfWriteProfileString(CDProfile, AccessStr, 
        AppendIndex(TrackInfoKey, Index), Info);

    if ( bResult ) {
        Change.Track = Index;
        Change.Info = Info;
        WinSendMsg(hwndDlg, CD_INFOCHANGED, MPFROMP(AccessStr), MPFROMP(&Change));
        }

    return bResult;
}

BOOL CDPrfQueryPlayList(PSZ AccessStr, CDAUDIO_PLAYLIST *PlayList)
{
    BOOL bResult;
    ULONG DataLen;

    DataLen = sizeof(CDAUDIO_PLAYLIST);
    bResult = PrfQueryProfileData(CDProfile, AccessStr, PlayListKey,
                PlayList, &DataLen);

    return bResult && DataLen == PLAYLIST_SIZE(*PlayList);
}

BOOL CDPrfSetPlayList(PSZ AccessStr, CDAUDIO_PLAYLIST *PlayList)
{
    BOOL bResult;

    bResult = PrfWriteProfileData(CDProfile, AccessStr, PlayListKey,
                PlayList, PLAYLIST_SIZE(*PlayList));
 
    if ( bResult ) {
        PrfWriteProfileData(CDProfile, AccessStr, PositionKey, NULL, 0);

        WinSendMsg(hwndDlg, CD_PLAYLISTCHANGED, MPFROMP(AccessStr), MPFROMP(PlayList));
        }

    return bResult;
}

BOOL CDPrfQueryContents(PSZ AccessStr, CDAUDIO_CONTENTS *Contents)
{
    BOOL bResult;
    ULONG DataLen;

    DataLen = sizeof(CDAUDIO_CONTENTS);
    bResult = PrfQueryProfileData(CDProfile, AccessStr, ContentsKey,
                Contents, &DataLen);

    return bResult && DataLen == CONTENTS_SIZE(*Contents);
}

BOOL CDPrfSetContents(PSZ AccessStr, CDAUDIO_CONTENTS *Contents)
{
    BOOL bResult;

    bResult = PrfWriteProfileData(CDProfile, AccessStr, ContentsKey,
                Contents, CONTENTS_SIZE(*Contents));

    return bResult;
}

BOOL CDPrfQueryPosition(PSZ AccessStr, ULONG *Track, MMTIME *Position)
{
    BOOL bResult;
    ULONG DataLen;
    CDPLAYLIST_POSITION Pos;

    DataLen = sizeof(CDPLAYLIST_POSITION);
    bResult = PrfQueryProfileData(CDProfile, AccessStr, PositionKey,
                &Pos, &DataLen);

    if ( bResult && DataLen == sizeof(CDPLAYLIST_POSITION) ) {
        *Track = Pos.Track;
        *Position = Pos.Position;
        return TRUE;
        }
    else {
        return FALSE;
        }
}

BOOL CDPrfSetPosition(PSZ AccessStr, ULONG Track, MMTIME Position)
{
    BOOL bResult;
    CDPLAYLIST_POSITION Pos;

    Pos.Track = Track;
    Pos.Position = Position;
    bResult = PrfWriteProfileData(CDProfile, AccessStr, PositionKey,
                &Pos, sizeof(CDPLAYLIST_POSITION));

    return bResult;
}

BOOL CDPrfTestRegData(ULONG RegID, PSZ UserName)
{
    ULONG NameSum, NameLen, i; 

    if ( RegID == 0 )
        return FALSE;

    NameSum = NameLen = strlen(UserName);

    for ( i = 0; i < NameLen; i++) {
        NameSum += _rotl((ULONG)UserName[i], i);
        }

    NameSum ^= REG_XOR;
    NameSum %= REG_INCR;

    RegID ^= REG_XOR;
    RegID -= REG_BASE + NameSum;
    RegID %= REG_INCR;

    return RegID == 0;
}

BOOL CDPrfSetRegData(ULONG RegID, PSZ UserName)
{
    if ( ! CDPrfTestRegData(RegID, UserName) )
        return FALSE;

    if ( ! PrfWriteProfileData(CDProfile, RegAppl, RegIDKey, &RegID, sizeof(ULONG)) )
        return FALSE;

    if ( ! PrfWriteProfileString(CDProfile, RegAppl, RegUserKey, UserName) )
        return FALSE;

    return TRUE;
}

BOOL CDPrfQueryRegistered(PULONG RegID, PSZ UserName)
{
    ULONG RegIDLen, UserNameLen;

    RegIDLen = sizeof(ULONG);
    
    if ( ! PrfQueryProfileData(CDProfile, RegAppl, RegIDKey, RegID, &RegIDLen) ||
          RegIDLen != sizeof(ULONG) ) {
 
        PrfWriteProfileData(CDProfile, RegAppl, NULL, NULL, 0);
        return FALSE;
        }

    UserNameLen = PrfQueryProfileString(CDProfile, RegAppl, RegUserKey, NULL, UserName, 64);
    if ( UserNameLen == 0 ) {
        PrfWriteProfileData(CDProfile, RegAppl, NULL, NULL, 0);
        return FALSE;
        }

    if ( ! CDPrfTestRegData(*RegID, UserName) ) {
        PrfWriteProfileData(CDProfile, RegAppl, NULL, NULL, 0);
        return FALSE;
        }

    return TRUE;
}

/*
BOOL CDPrfQueryTitles(PSZ AccessStr, ULONG MaxTitles, CDAUDIO_TITLES *Titles)
{
    ULONG i;

    if ( Titles->AccessStr != NULL )
        free(Titles->AccessStr);
    if ( Titles->CDTitle != NULL )
        free(Titles->CDTitle);
    if ( Titles->CDInfo != NULL )
        free(Titles->CDInfo);

    for ( i = 0; i < MAX_TRACKS; i++ ) {
        if ( Titles->Track[i].Title != NULL)
            free(Titles->Track[i].Title);
        if ( Titles->Track[i].Info != NULL)
            free(Titles->Track[i].Info);
        }

    Titles->TotalTitles = MaxTitles;
    Titles->AccessStr = AccessStr;
 
    Titles->CDTitle = CDPrfQueryCDTitle(AccessStr);
    Titles->CDInfo = CDPrfQueryCDInfo(AccessStr);

    for ( i = 0; i < MaxTitles; i++ ) {
        Titles->Track[i].Title = CDPrfQueryTrackTitle(AccessStr, i+1);
        Titles->Track[i].Info = CDPrfQueryTrackInfo(AccessStr, i+1);
        }

    return TRUE;
}

BOOL CDPrfSetTitles(PSZ AccessStr, CDAUDIO_TITLES *Titles)
{
    ULONG i;

    CDPrfSetCDTitle(AccessStr, Titles->CDTitle);
    CDPrfSetCDInfo(AccessStr, Titles->CDInfo);

    for ( i = 0; i < Titles->TotalTitles; i++ ) {
        CDPrfSetTrackTitle(AccessStr, Titles->Track[i].Title,i+1);
        CDPrfSetTrackInfo(AccessStr, Titles->Track[i].Info,i+1);
        }

    return TRUE;
}
*/

static BOOL GetNumericOption(PSZ Appl, PSZ Key, int *Value)
{
    char Buffer[128];
    char Dummy[2];
    int Scanned;

    if ( PrfQueryProfileString(CDProfile, Appl, Key, NULL, Buffer,
            sizeof(Buffer)) ) {
        if ( sscanf(Buffer, " %i %c", Value, Dummy) == 1 )
            return TRUE;
        }

    return FALSE;
}

static BOOL GetBoolOption(PSZ Appl, PSZ Key, BOOL *Value)
{
    char Buffer[128];
    char OptBuf[11];
    char Dummy[2];
    int Scanned;

    if ( PrfQueryProfileString(CDProfile, Appl, Key, NULL, Buffer,
            sizeof(Buffer)) ) {
        if ( sscanf(Buffer, " %i %c", Value, Dummy) == 1 &&
             ( *Value == TRUE || *Value == FALSE ) ) {
            return TRUE;
            }
        else if ( sscanf(Buffer, " %10s %c", OptBuf, Dummy) == 1 ) {
            if ( stricmp(OptBuf, "ON") == 0 ||
                 stricmp(OptBuf, "TRUE") == 0 ) {
                *Value = TRUE;
                return TRUE;
                }

            if ( stricmp(OptBuf, "OFF") == 0 ||
                 stricmp(OptBuf, "FALSE") == 0 ) {
                *Value = FALSE;
                return TRUE;
                }
            }
        }

    return FALSE;
}

static BOOL GetStrOption(PSZ Appl, PSZ Key, char *Value, ULONG MaxLength)
{
    return PrfQueryProfileString(CDProfile, Appl, Key, NULL, Value,
            MaxLength);
}

static BOOL GetCharOption(PSZ Appl, PSZ Key, int *Value)
{
    ULONG ReadLength = 4;
    BOOL bResult;
    char Buffer[4];

    bResult = PrfQueryProfileData(CDProfile, Appl, Key, Buffer, &ReadLength);

    if ( ReadLength == 1 ||
         (ReadLength == 2 && Buffer[1] == 0) ) {
        *Value = Buffer[0];
        return TRUE;
        }

    return FALSE;
}

static BOOL SetNumericOption(PSZ Appl, PSZ Key, int Value)
{
    char Buffer[16];

    return PrfWriteProfileString(CDProfile, Appl, Key, itoa(Value, Buffer, 10));
}

static BOOL SetBoolOption(PSZ Appl, PSZ Key, BOOL Value)
{
    if ( Value )
        return PrfWriteProfileString(CDProfile, Appl, Key, "1");
    else
        return PrfWriteProfileString(CDProfile, Appl, Key, "0");
}

static BOOL SetStrOption(PSZ Appl, PSZ Key, char *Value)
{
    return PrfWriteProfileString(CDProfile, Appl, Key, Value);
}

static BOOL SetCharOption(PSZ Appl, PSZ Key, int Value)
{
    char Buffer[2];

    Buffer[0] = Value;
    Buffer[1] = 0;

    return PrfWriteProfileString(CDProfile, Appl, Key, Buffer);
}

static PSZ MakeCDAppl(CDAUDIO_CONTENTS *Contents)
{
    ULONG Id = 0, i;
    PSZ Buf = malloc(32);

    if ( Buf == NULL )
        return FALSE;

    for ( i = 0; i < Contents->TotalTracks; i++) {
        Id ^= (Contents->Track[i].Start) ^ (Contents->Track[i].Length << 8);
        }

    Id ^= Contents->TotalTracks;

    sprintf(Buf, "X%8.8x.", Id);
    return Buf;
}

static PSZ AppendIndex(PSZ Key, ULONG Index)
{
    static char Buffer[32];

    strcpy(Buffer, Key);
    // strcat(Buffer, ".");
    itoa(Index, Buffer + strlen(Buffer), 10);

    return Buffer;
}

static PSZ StripBlancs(PSZ String)
{
    int StrLen;

    if ( String == NULL )
        return String;

    StrLen = strlen(String);

    while ( StrLen > 0 ) {
        if ( String[StrLen-1] == ' ' || String[StrLen-1] == '\t' ||
             String[StrLen-1] == '\n' || String[StrLen-1] == '\r' )
            StrLen--;
        else
            break;
        }

    if ( StrLen > 0 ) {
        String[StrLen] = 0;
        return String;
        }
    else
        return NULL;
}


