// #include <utility.h>
#include "cdglobal.h"
#include "cddevice.h"

static void CDSaveErrStr(ULONG Result);

static char ErrStrBuffer[256];

BOOL CDQueryDevName(ULONG Index, PSZ Name, ULONG NameLen)
{
    MCI_SYSINFO_PARMS Parms;
    ULONG uResult;
 
    Parms.pszReturn = Name;
    Parms.ulRetSize = NameLen;
    Parms.ulNumber = Index;
    Parms.usDeviceType = MCI_DEVTYPE_CD_AUDIO;
    Parms.ulItem = 0;

    uResult = mciSendCommand(0, MCI_SYSINFO, MCI_WAIT | MCI_SYSINFO_NAME, &Parms, 0);

    if ( LOUSHORT(uResult) == MCIERR_SUCCESS )  {
        return TRUE;
        }
    else {
        CDSaveErrStr(uResult);
        return FALSE;
        }
}

BOOL CDSetConnector(USHORT DevID, ULONG Connector, BOOL Enable)
{
    MCI_CONNECTOR_PARMS Mop;
    ULONG uResult;

    Mop.hwndCallback = NULLHANDLE;
    Mop.ulConnectorType = Connector;
    Mop.ulConnectorIndex = 1;

    if ( Enable )
        uResult = mciSendCommand(DevID, MCI_CONNECTOR, MCI_WAIT |
            MCI_ENABLE_CONNECTOR | MCI_CONNECTOR_TYPE , &Mop, 0);
    else
        uResult = mciSendCommand(DevID, MCI_CONNECTOR, MCI_WAIT |
            MCI_DISABLE_CONNECTOR | MCI_CONNECTOR_TYPE , &Mop, 0);

    if ( LOUSHORT(uResult) == MCIERR_SUCCESS ) {
        return TRUE;
        }
    else {
        CDSaveErrStr(uResult);
        return FALSE;
        }
}

BOOL CDOpenDevice(HWND Callback, char *DevName, PUSHORT DevID)
{
    MCI_OPEN_PARMS Mop;
    ULONG uResult;
    char DefDevName[64];

    if ( DevName == NULL ) {
        if ( ! CDQueryDevName(1, DefDevName, sizeof(DefDevName)) )
            return FALSE;

        DevName = DefDevName;
        }

    Mop.hwndCallback = Callback;
    Mop.usDeviceID = 0;
    Mop.usReserved0 = 0;
    Mop.pszDeviceType = DevName;
    Mop.pszElementName = NULL;
    Mop.pszAlias = NULL;

    uResult = mciSendCommand(0, MCI_OPEN, MCI_WAIT, &Mop, 0);
    // MCI_OPEN_SHAREABLE |
    if ( LOUSHORT(uResult) == MCIERR_SUCCESS ) {
        *DevID = Mop.usDeviceID;
        return TRUE;
        }
    else {
        CDSaveErrStr(uResult);
        return FALSE;
        }
}

BOOL CDInitDevice(USHORT DevID, HWND Callback, MMTIME AdviseRate)
{
    MCI_SET_PARMS Parms;
    MCI_POSITION_PARMS Parms2;
    ULONG uResult;

    Parms.hwndCallback = NULL;
    Parms.ulTimeFormat = MCI_FORMAT_MMTIME;
    // Parms.ulAudio = MCI_SET_AUDIO_ALL;
    // Parms.ulLevel = 100;

    uResult = mciSendCommand(DevID, MCI_SET, MCI_WAIT | 
//        MCI_SET_AUDIO | MCI_SET_VOLUME |
        MCI_SET_TIME_FORMAT, &Parms, 0);

    if ( LOUSHORT(uResult) != MCIERR_SUCCESS ) {
        CDSaveErrStr(uResult);
        return FALSE;
        }

    Parms2.hwndCallback = Callback;
    Parms2.ulUnits = AdviseRate;
    Parms2.usUserParm = 0;

    uResult = mciSendCommand(DevID, MCI_SET_POSITION_ADVISE,
        MCI_WAIT | MCI_SET_POSITION_ADVISE_ON, &Parms2, 0);

    if ( LOUSHORT(uResult) != MCIERR_SUCCESS ) {
        CDSaveErrStr(uResult);
        return FALSE;
        }

    return TRUE;
}

/*
BOOL CDReadLong(USHORT DevID, MMTIME From, ULONG Count, void *Buffer, ULONG BufSize)
{
    MCI_CD_READLONG_PARMS Parms;

    Parms.ulFrom = From;
    Parms.usCount = (USHORT)Count;
    Parms.pReturn = Buffer;
    Parms.ulRetSize = BufSize;

    mciSend
}
*/

BOOL CDSetAdviseRate(USHORT DevID, HWND Callback, MMTIME AdviseRate)
{
    MCI_POSITION_PARMS Parms;
    ULONG uResult;

    Parms.hwndCallback = Callback;
    Parms.ulUnits = AdviseRate;
    Parms.usUserParm = 0;

    uResult = mciSendCommand(DevID, MCI_SET_POSITION_ADVISE,
        MCI_WAIT | MCI_SET_POSITION_ADVISE_ON, &Parms, 0);

    if ( LOUSHORT(uResult) != MCIERR_SUCCESS ) {
        CDSaveErrStr(uResult);
        return FALSE;
        }

    return TRUE;
}

BOOL CDSetAdviseOff(USHORT DevID, HWND CallBack)
{
    MCI_POSITION_PARMS Parms;
    ULONG uResult;

    Parms.hwndCallback = CallBack;
    Parms.ulUnits = 0;
    Parms.usUserParm = 0;

    uResult = mciSendCommand(DevID, MCI_SET_POSITION_ADVISE,
        MCI_WAIT | MCI_SET_POSITION_ADVISE_OFF, &Parms, 0);

    if ( LOUSHORT(uResult) != MCIERR_SUCCESS ) {
        CDSaveErrStr(uResult);
        return FALSE;
        }

    return TRUE;
}

BOOL CDSetCuePoint(USHORT DevID, HWND Callback, MMTIME CuePoint)
{
    MCI_CUEPOINT_PARMS Parms;
    ULONG uResult;

    Parms.hwndCallback = Callback;
    Parms.ulCuepoint = CuePoint;
    Parms.usUserParm = 0;

    uResult = mciSendCommand(DevID, MCI_SET_CUEPOINT,
        MCI_WAIT | MCI_SET_CUEPOINT_ON, &Parms, 0);

    if ( LOUSHORT(uResult) != MCIERR_SUCCESS ) {
        CDSaveErrStr(uResult);
        return FALSE;
        }

    return TRUE;
}

BOOL CDSetCuePointOff(USHORT DevID, MMTIME CuePoint)
{
    MCI_CUEPOINT_PARMS Parms;
    ULONG uResult;

    Parms.hwndCallback = NULL;
    Parms.ulCuepoint = CuePoint;
    Parms.usUserParm = 0;

    uResult = mciSendCommand(DevID, MCI_SET_CUEPOINT,
        MCI_WAIT | MCI_SET_CUEPOINT_OFF, &Parms, 0);

    if ( LOUSHORT(uResult) != MCIERR_SUCCESS ) {
        CDSaveErrStr(uResult);
        return FALSE;
        }

    return TRUE;
}


BOOL CDDriverInfo(USHORT DevID, CDAUDIO_DRIVERINFO *DriverInfo)
{
    MCI_GETDEVCAPS_PARMS Parms;
    ULONG uResult;

    Parms.hwndCallback = NULL;
    Parms.ulItem = MCI_GETDEVCAPS_CAN_PLAY;

    uResult = mciSendCommand(DevID, MCI_GETDEVCAPS,
        MCI_GETDEVCAPS_ITEM | MCI_WAIT, &Parms, 0);

    if ( LOUSHORT(uResult) == MCIERR_SUCCESS ) {
        DriverInfo->CanPlayAudio = (Parms.ulReturn != 0);
        }
    else {
        CDSaveErrStr(uResult);
        DriverInfo->CanPlayAudio = FALSE;
        return FALSE;
        }

    Parms.hwndCallback = NULL;
    Parms.ulItem = MCI_GETDEVCAPS_CAN_EJECT;

    uResult = mciSendCommand(DevID, MCI_GETDEVCAPS,
        MCI_GETDEVCAPS_ITEM | MCI_WAIT, &Parms, 0);

    if ( LOUSHORT(uResult) == MCIERR_SUCCESS ) {
        DriverInfo->CanEject = (Parms.ulReturn != 0);
        }
    else {
        CDSaveErrStr(uResult);
        DriverInfo->CanEject = FALSE;
        return FALSE;
        }

    Parms.hwndCallback = NULL;
    Parms.ulItem = MCI_GETDEVCAPS_CAN_LOCKEJECT;

    uResult = mciSendCommand(DevID, MCI_GETDEVCAPS,
        MCI_GETDEVCAPS_ITEM | MCI_WAIT, &Parms, 0);

    if ( LOUSHORT(uResult) == MCIERR_SUCCESS ) {
        DriverInfo->CanLock = (Parms.ulReturn != 0);
        }
    else {
        CDSaveErrStr(uResult);
        DriverInfo->CanLock = FALSE;
        return FALSE;
        }

    Parms.hwndCallback = NULL;
    Parms.ulItem = MCI_GETDEVCAPS_CAN_SETVOLUME;

    uResult = mciSendCommand(DevID, MCI_GETDEVCAPS,
        MCI_GETDEVCAPS_ITEM | MCI_WAIT, &Parms, 0);

    if ( LOUSHORT(uResult) == MCIERR_SUCCESS ) {
        DriverInfo->CanSetVolume = (Parms.ulReturn != 0);
        }
    else {
        CDSaveErrStr(uResult);
        DriverInfo->CanSetVolume = FALSE;
        return FALSE;
        }

    Parms.hwndCallback = NULL;
    Parms.ulItem = MCI_GETDEVCAPS_CAN_STREAM;

    uResult = mciSendCommand(DevID, MCI_GETDEVCAPS,
        MCI_GETDEVCAPS_ITEM | MCI_WAIT, &Parms, 0);

    if ( LOUSHORT(uResult) == MCIERR_SUCCESS ) {
        DriverInfo->CanStream = (Parms.ulReturn != 0);
        }
    else {
        CDSaveErrStr(uResult);
        DriverInfo->CanStream = FALSE;
        return FALSE;
        }

    Parms.hwndCallback = NULL;
    Parms.ulItem = MCI_GETDEVCAPS_CAN_PROCESS_INTERNAL;

    uResult = mciSendCommand(DevID, MCI_GETDEVCAPS,
        MCI_GETDEVCAPS_ITEM | MCI_WAIT, &Parms, 0);

    if ( LOUSHORT(uResult) == MCIERR_SUCCESS ) {
        DriverInfo->CanProcessInternal = (Parms.ulReturn != 0);
        }
    else {
        CDSaveErrStr(uResult);
        DriverInfo->CanProcessInternal = FALSE;
        return FALSE;
        }

    DriverInfo->CanSwapChannels = FALSE;

    return TRUE;
}

BOOL CDGetStatus(USHORT DevID, ULONG *Status)
{
    MCI_STATUS_PARMS Parms;
    ULONG uResult;

    Parms.hwndCallback = NULL;
    Parms.ulItem = MCI_STATUS_MODE;

    uResult = mciSendCommand(DevID, MCI_STATUS,
        MCI_STATUS_ITEM | MCI_WAIT, &Parms, 0);

    if ( LOUSHORT(uResult) == MCIERR_SUCCESS ) {
        *Status = Parms.ulReturn;
        return TRUE;
        }
    else {
        *Status = MCI_MODE_NOT_READY;
        CDSaveErrStr(uResult);
        return FALSE;
        }
}

BOOL CDGetContents(USHORT DevID, CDAUDIO_CONTENTS *Contents)
{
    MCI_INFO_PARMS Parms;
    MCI_STATUS_PARMS Parms2;
    MCI_SET_PARMS Parms3;
    ULONG uResult, i;

    Parms2.hwndCallback = NULL;
    Parms2.ulItem = MCI_STATUS_MEDIA_PRESENT;

    uResult = mciSendCommand(DevID, MCI_STATUS,
        MCI_STATUS_ITEM | MCI_WAIT, &Parms2, 0);

    if ( LOUSHORT(uResult) == MCIERR_SUCCESS ) {
        Contents->AudioCDInserted = (Parms2.ulReturn != 0);
        if ( ! Contents->AudioCDInserted )
            return TRUE;
        }
    else {
        Contents->AudioCDInserted = FALSE;
        CDSaveErrStr(uResult);

        Parms2.hwndCallback = NULL;
        Parms2.ulItem = MCI_STATUS_MODE;

        uResult = mciSendCommand(DevID, MCI_STATUS,
            MCI_STATUS_ITEM | MCI_WAIT, &Parms2, 0);

        if ( LOUSHORT(uResult) == MCIERR_SUCCESS &&
             Parms2.ulReturn != MCI_MODE_NOT_READY )
            return TRUE;
        else
            return FALSE;
        }

    Parms3.hwndCallback = NULL;
    Parms3.ulTimeFormat = MCI_FORMAT_MMTIME;

    uResult = mciSendCommand(DevID, MCI_SET, MCI_WAIT |
        MCI_SET_TIME_FORMAT, &Parms3, 0);

    if ( LOUSHORT(uResult) != MCIERR_SUCCESS ) {
        CDSaveErrStr(uResult);
        return FALSE;
        }

    Parms.hwndCallback = NULL;
    Parms.pszReturn = Contents->cID;
    Parms.ulRetSize = sizeof(Contents->cID);

    uResult = mciSendCommand(DevID, MCI_INFO,
        MCI_CD_INFO_ID | MCI_WAIT, &Parms, 0);

    Contents->IDAvailable = ( LOUSHORT(uResult) == MCIERR_SUCCESS && Parms.ulRetSize > 0);

    Parms.hwndCallback = NULL;
    Parms.pszReturn = Contents->UPC;
    Parms.ulRetSize = sizeof(Contents->UPC);

    uResult = mciSendCommand(DevID, MCI_INFO,
        MCI_CD_INFO_UPC | MCI_WAIT, &Parms, 0);

    Contents->UPCAvailable = ( LOUSHORT(uResult) == MCIERR_SUCCESS && Parms.ulRetSize > 0);
    if ( LOUSHORT(uResult) == MCIERR_SUCCESS ) {
        Contents->UPCLength = Parms.ulRetSize;
        } 
    else {
        Contents->UPCLength = 0;
        }

    Parms2.hwndCallback = NULL;
    Parms2.ulItem = MCI_STATUS_POSITION;

    uResult = mciSendCommand(DevID, MCI_STATUS,
        MCI_STATUS_ITEM | MCI_STATUS_START | MCI_WAIT, &Parms2, 0);

    if ( LOUSHORT(uResult) == MCIERR_SUCCESS ) {
        Contents->StartPosition = Parms2.ulReturn;
        }
    else {
        Contents->StartPosition = 0;
        CDSaveErrStr(uResult);
        return FALSE;
        }

    Parms2.hwndCallback = NULL;
    Parms2.ulItem = MCI_STATUS_LENGTH;

    uResult = mciSendCommand(DevID, MCI_STATUS,
        MCI_STATUS_ITEM | MCI_WAIT, &Parms2, 0);

    if ( LOUSHORT(uResult) == MCIERR_SUCCESS ) {
        Contents->TotalLength = Parms2.ulReturn;
        }
    else {
        Contents->TotalLength = 0;
        CDSaveErrStr(uResult);
        return FALSE;
        }

    /*
    Parms2.hwndCallback = NULL;
    Parms2.ulItem = MCI_STATUS_NUMBER_OF_TRACKS;

    uResult = mciSendCommand(DevID, MCI_STATUS,
        MCI_STATUS_ITEM | MCI_WAIT, &Parms2, 0);

    if ( LOUSHORT(uResult) == MCIERR_SUCCESS ) {
        Contents->TotalTracks = Parms2.ulReturn;
        }
    else {
        Contents->TotalTracks = 0;
        CDSaveErrStr(uResult);
        return FALSE;
        }
    */

    for ( i = 1; i <= 99; i++) {
        Parms2.hwndCallback = NULL;
        Parms2.ulItem = MCI_CD_STATUS_TRACK_TYPE;
        Parms2.ulValue = i;

        uResult = mciSendCommand(DevID, MCI_STATUS,
            MCI_STATUS_ITEM | MCI_WAIT | MCI_TRACK, &Parms2, 0);

        if ( LOUSHORT(uResult) == MCIERR_SUCCESS ) {
            Contents->Track[i-1].IsAudioTrack =
                (Parms2.ulReturn == MCI_CD_TRACK_AUDIO);
            }
        else {
            Contents->TotalTracks = i - 1;
            break;
            }

        Parms2.hwndCallback = NULL;
        Parms2.ulItem = MCI_STATUS_POSITION;
        Parms2.ulValue = i;

        uResult = mciSendCommand(DevID, MCI_STATUS,
            MCI_STATUS_ITEM | MCI_WAIT | MCI_TRACK, &Parms2, 0);

        if ( LOUSHORT(uResult) == MCIERR_SUCCESS ) {
            Contents->Track[i-1].Start = Parms2.ulReturn;
            }
        else {
            Contents->Track[i-1].Start = 0;
            CDSaveErrStr(uResult);
            return FALSE;
            }

        Parms2.hwndCallback = NULL;
        Parms2.ulItem = MCI_STATUS_LENGTH;
        Parms2.ulValue = i;

        uResult = mciSendCommand(DevID, MCI_STATUS,
            MCI_STATUS_ITEM | MCI_WAIT | MCI_TRACK, &Parms2, 0);

        if ( LOUSHORT(uResult) == MCIERR_SUCCESS ) {
            Contents->Track[i-1].Length = Parms2.ulReturn;
            }
        else {
            Contents->Track[i-1].Length = 0;
            CDSaveErrStr(uResult);
            return FALSE;
            }

        Parms2.hwndCallback = NULL;
        Parms2.ulItem = MCI_CD_STATUS_TRACK_COPYPERMITTED;
        Parms2.ulValue = i;

        uResult = mciSendCommand(DevID, MCI_STATUS,
            MCI_STATUS_ITEM | MCI_WAIT | MCI_TRACK, &Parms2, 0);

        if ( LOUSHORT(uResult) == MCIERR_SUCCESS ) {
            Contents->Track[i-1].CopyPermitted =
                (Parms2.ulReturn == MCI_TRUE);
            }
        else {
            Contents->Track[i-1].CopyPermitted = FALSE;
            CDSaveErrStr(uResult);
            return FALSE;
            }

        Parms2.hwndCallback = NULL;
        Parms2.ulItem = MCI_CD_STATUS_TRACK_PREEMPHASIS;
        Parms2.ulValue = i;

        uResult = mciSendCommand(DevID, MCI_STATUS,
            MCI_STATUS_ITEM | MCI_WAIT | MCI_TRACK, &Parms2, 0);

        if ( LOUSHORT(uResult) == MCIERR_SUCCESS ) {
            Contents->Track[i-1].Preemphasis =
                (Parms2.ulReturn == MCI_TRUE);
            }
        else {
            Contents->Track[i-1].Preemphasis = FALSE;
            CDSaveErrStr(uResult);
            return FALSE;
            }

        Parms2.hwndCallback = NULL;
        Parms2.ulItem = MCI_CD_STATUS_TRACK_CHANNELS;
        Parms2.ulValue = i;

        uResult = mciSendCommand(DevID, MCI_STATUS,
            MCI_STATUS_ITEM | MCI_WAIT | MCI_TRACK, &Parms2, 0);

        if ( LOUSHORT(uResult) == MCIERR_SUCCESS ) {
            Contents->Track[i-1].Channels = Parms2.ulReturn;
            }
        else {
            Contents->Track[i-1].Channels = 0;
            CDSaveErrStr(uResult);
            return FALSE;
            }
        }

    return TRUE;
}

BOOL CDGetDefPlayList(CDAUDIO_CONTENTS *Contents, CDAUDIO_PLAYLIST *PlayList)
{
    return CDResetPlayList(Contents, PlayList);
}

BOOL CDResetPlayList(CDAUDIO_CONTENTS *Contents, CDAUDIO_PLAYLIST *PlayList)
{
    ULONG i;

    PlayList->TotalTracks = 0;
    PlayList->TotalLength = 0;
    PlayList->CurrTrack = 0;

    if ( Contents->AudioCDInserted ) {
        for ( i = 0; i < Contents->TotalTracks; i++) {
            if ( Contents->Track[i].IsAudioTrack ) {
                PlayList->Track[PlayList->TotalTracks].ToPlay = i+1;
                PlayList->Track[PlayList->TotalTracks].StartInPlayList = 
                    PlayList->TotalLength;
                PlayList->TotalLength += Contents->Track[i].Length;
                PlayList->TotalTracks++;
                }
            }
        }

    return (PlayList->TotalTracks > 0) && (PlayList->TotalLength > 1000);
}

BOOL CDFlushPlayList(CDAUDIO_PLAYLIST *PlayList)
{
    PlayList->TotalTracks = PlayList->CurrTrack = 0;
    PlayList->TotalLength = 0;

    return TRUE;
}

BOOL CDInsertInPlayList(
    CDAUDIO_CONTENTS *Contents,
    CDAUDIO_PLAYLIST *PlayList, 
    USHORT Entry, 
    USHORT Track)
{
    ULONG i;
    ULONG AddTime;

    if ( PlayList->TotalTracks < MAX_PLAYLIST &&
         Track <= Contents->TotalTracks &&
         Contents->Track[Track-1].IsAudioTrack ) {
        AddTime = Contents->Track[Track-1].Length;

        if ( PlayList->TotalLength + AddTime > MAX_PLAYLIST_LENGTH )
            return FALSE;

        if ( Entry >= PlayList->TotalTracks ) {
            PlayList->Track[PlayList->TotalTracks].ToPlay = Track;
            PlayList->Track[PlayList->TotalTracks].StartInPlayList = 
                PlayList->TotalLength;
            }
        else {
            for ( i = PlayList->TotalTracks; i > Entry; i-- ) {
                PlayList->Track[i].ToPlay = PlayList->Track[i-1].ToPlay;
                PlayList->Track[i].StartInPlayList = 
                    PlayList->Track[i-1].StartInPlayList + AddTime;
                }

            PlayList->Track[Entry].ToPlay = Track;
            }

        PlayList->TotalLength += AddTime;
        PlayList->TotalTracks++;
        return TRUE;
        }
    else {
        return FALSE;
        }
}

BOOL CDDeleteFromPlayList(
    CDAUDIO_CONTENTS *Contents,
    CDAUDIO_PLAYLIST *PlayList, 
    USHORT Entry)
{
    ULONG i;
    ULONG SubTime;

    if ( PlayList->TotalTracks > 1 && Entry < PlayList->TotalTracks ) {
        SubTime = Contents->Track[PlayList->Track[Entry].ToPlay-1].Length;

        for ( i = Entry; i < PlayList->TotalTracks - 1; i++ ) {
            PlayList->Track[i].ToPlay = PlayList->Track[i+1].ToPlay;
            PlayList->Track[i].StartInPlayList = 
                PlayList->Track[i+1].StartInPlayList - SubTime;
            }

        PlayList->TotalLength -= SubTime;
        PlayList->TotalTracks--;
        return TRUE;
        } 
    else {
        return FALSE;
        }
}

BOOL CDGetPosition(
    USHORT DevID, 
    MMTIME ProvideTime,
    CDAUDIO_CONTENTS *Contents,
    CDAUDIO_PLAYLIST *PlayList, 
    CDAUDIO_POSITION *Pos)
{
    MCI_STATUS_PARMS Parms;
    ULONG uResult;

    if ( ProvideTime == (MMTIME)-1 ) {
        Parms.hwndCallback = NULL;
        Parms.ulItem = MCI_STATUS_POSITION_IN_TRACK;

        uResult = mciSendCommand(DevID, MCI_STATUS,
            MCI_STATUS_ITEM | MCI_WAIT, &Parms, 0);
        if ( LOUSHORT(uResult) != MCIERR_SUCCESS ) {
            CDSaveErrStr(uResult);
            return FALSE;
            }
        } 
    else {
        Parms.ulReturn = ProvideTime - 
            Contents->Track[PlayList->Track[PlayList->CurrTrack].ToPlay-1].Start;
        }

    Pos->CurrTrack = PlayList->Track[PlayList->CurrTrack].ToPlay;
    Pos->TrackPlayed = Parms.ulReturn;
    Pos->TrackLeft = Contents->Track[Pos->CurrTrack-1].Length - Parms.ulReturn;
    Pos->CDPlayed = PlayList->Track[PlayList->CurrTrack].StartInPlayList + Parms.ulReturn;
    Pos->CDLeft = PlayList->TotalLength - Pos->CDPlayed;

    return TRUE;
}


BOOL CDGetRawPosition(USHORT DevID, MMTIME *Position)
{
    MCI_STATUS_PARMS Parms;
    ULONG uResult;

    Parms.hwndCallback = NULL;
    Parms.ulItem = MCI_STATUS_POSITION;

    uResult = mciSendCommand(DevID, MCI_STATUS,
        MCI_STATUS_ITEM | MCI_WAIT, &Parms, 0);
    if ( LOUSHORT(uResult) != MCIERR_SUCCESS ) {
        CDSaveErrStr(uResult);
        return FALSE;
        }
 
    *Position = Parms.ulReturn;
    return TRUE;
}


BOOL CDPlay(USHORT DevID, HWND Callback, MMTIME From, MMTIME Length, USHORT User)
{
    MCI_PLAY_PARMS Parms;
    ULONG uResult;

    Parms.hwndCallback = Callback;
    Parms.ulFrom = From;
    Parms.ulTo = From + Length;

    uResult = mciSendCommand(DevID, MCI_PLAY,
        MCI_FROM | MCI_TO | MCI_NOTIFY, &Parms, User);

    if ( LOUSHORT(uResult) == MCIERR_SUCCESS ) {
        return TRUE;
        }
    else {
        CDSaveErrStr(uResult);
        return FALSE;
        }
}

BOOL CDPause(USHORT DevID)
{
    MCI_GENERIC_PARMS Parms;
    ULONG uResult;

    Parms.hwndCallback = NULL;

    uResult = mciSendCommand(DevID, MCI_PAUSE, MCI_WAIT, &Parms, 0);

    if ( LOUSHORT(uResult) == MCIERR_SUCCESS ) {
        return TRUE;
        }
    else {
        CDSaveErrStr(uResult);
        return FALSE;
        }
}

BOOL CDResume(USHORT DevID)
{
    MCI_GENERIC_PARMS Parms;
    ULONG uResult;

    Parms.hwndCallback = NULL;

    uResult = mciSendCommand(DevID, MCI_RESUME, MCI_WAIT, &Parms, 0);

    if ( LOUSHORT(uResult) == MCIERR_SUCCESS ) {
        return TRUE;
        }
    else {
        CDSaveErrStr(uResult);
        return FALSE;
        }
}

BOOL CDStop(USHORT DevID)
{
    MCI_GENERIC_PARMS Parms;
    ULONG uResult;

    Parms.hwndCallback = NULL;

    uResult = mciSendCommand(DevID, MCI_STOP, MCI_WAIT, &Parms, 0);

    if ( LOUSHORT(uResult) == MCIERR_SUCCESS ) {
        return TRUE;
        }
    else {
        CDSaveErrStr(uResult);
        return FALSE;
        }
}

BOOL CDSeek(USHORT DevID, HWND Callback, MMTIME To)
{
    MCI_SEEK_PARMS Parms;
    ULONG uResult;

    Parms.hwndCallback = Callback;
    Parms.ulTo = To;

    uResult = mciSendCommand(DevID, MCI_SEEK, MCI_NOTIFY | MCI_TO, &Parms,
        CD_NOTIFY_SEEK);

    if ( LOUSHORT(uResult) == MCIERR_SUCCESS ) {
        return TRUE;
        }
    else {
        CDSaveErrStr(uResult);
        return FALSE;
        }
}

BOOL CDEject(USHORT DevID, HWND Callback)
{
    MCI_SET_PARMS Parms;
    ULONG uResult;

    Parms.hwndCallback = Callback;

    uResult = mciSendCommand(DevID, MCI_SET, MCI_NOTIFY |
        MCI_SET_DOOR_OPEN, &Parms, CD_NOTIFY_EJECT);

    if ( LOUSHORT(uResult) == MCIERR_SUCCESS ) {
        return TRUE;
        }
    else {
        CDSaveErrStr(uResult);
        return FALSE;
        }
}

BOOL CDSeekImm(USHORT DevID, MMTIME To)
{
    MCI_SEEK_PARMS Parms;
    ULONG uResult;

    Parms.hwndCallback = NULL;
    Parms.ulTo = To;

    uResult = mciSendCommand(DevID, MCI_SEEK, MCI_WAIT | MCI_TO, &Parms, 0);

    if ( LOUSHORT(uResult) == MCIERR_SUCCESS ) {
        return TRUE;
        }
    else {
        CDSaveErrStr(uResult);
        return FALSE;
        }
}

BOOL CDEjectImm(USHORT DevID)
{
    MCI_SET_PARMS Parms;
    ULONG uResult;

    Parms.hwndCallback = NULL;

    uResult = mciSendCommand(DevID, MCI_SET, MCI_WAIT |
        MCI_SET_DOOR_OPEN, &Parms, 0);

    if ( LOUSHORT(uResult) == MCIERR_SUCCESS ) {
        return TRUE;
        }
    else {
        CDSaveErrStr(uResult);
        return FALSE;
        }
}

BOOL CDLock(USHORT DevID)
{
    MCI_SET_PARMS Parms;
    ULONG uResult;

    Parms.hwndCallback = NULL;

    uResult = mciSendCommand(DevID, MCI_SET, MCI_WAIT | MCI_SET_DOOR_LOCK, &Parms, 0);

    if ( LOUSHORT(uResult) == MCIERR_SUCCESS ) {
        return TRUE;
        }
    else {
        CDSaveErrStr(uResult);
        return FALSE;
        }
}

BOOL CDUnlock(USHORT DevID)
{
    MCI_SET_PARMS Parms;
    ULONG uResult;

    Parms.hwndCallback = NULL;

    uResult = mciSendCommand(DevID, MCI_SET, MCI_WAIT | MCI_SET_DOOR_UNLOCK, &Parms, 0);

    if ( LOUSHORT(uResult) == MCIERR_SUCCESS ) {
        return TRUE;
        }
    else {
        CDSaveErrStr(uResult);
        return FALSE;
        }
}

BOOL CDCloseDevice(USHORT DevID)
{
    MCI_GENERIC_PARMS Parms;
    ULONG uResult;

    Parms.hwndCallback = NULL;
    uResult = mciSendCommand(DevID, MCI_CLOSE, MCI_WAIT, &Parms, 0);
    return LOUSHORT(uResult) == MCIERR_SUCCESS;
}

BOOL CDSetVolume(USHORT DevID, ULONG Left, ULONG Right)
{
    MCI_SET_PARMS Parms;
    ULONG uResult;

    if ( Left != (ULONG)-1 && Left == Right ) {
        Parms.hwndCallback = NULL;
        Parms.ulAudio = MCI_SET_AUDIO_ALL;
        Parms.ulLevel = Left;

        uResult = mciSendCommand(DevID, MCI_SET, MCI_WAIT | MCI_SET_AUDIO | MCI_SET_VOLUME,
            &Parms, 0);

        if ( LOUSHORT(uResult) == MCIERR_SUCCESS ) {
            return TRUE;
            }
        else {
            CDSaveErrStr(uResult);
            return FALSE;
            }
        }

    if ( Left != (ULONG)-1 ) {
        Parms.hwndCallback = NULL;
        Parms.ulAudio = MCI_SET_AUDIO_LEFT;
        Parms.ulLevel = Left;

        uResult = mciSendCommand(DevID, MCI_SET, MCI_WAIT | MCI_SET_AUDIO | MCI_SET_VOLUME,
            &Parms, 0);

        if ( LOUSHORT(uResult) != MCIERR_SUCCESS ) {
            CDSaveErrStr(uResult);
            return FALSE;
            }
        }

    if ( Right != (ULONG)-1 ) {
        Parms.hwndCallback = NULL;
        Parms.ulAudio = MCI_SET_AUDIO_RIGHT;
        Parms.ulLevel = Right;

        uResult = mciSendCommand(DevID, MCI_SET, MCI_WAIT | MCI_SET_AUDIO | MCI_SET_VOLUME,
            &Parms, 0);

        if ( LOUSHORT(uResult) != MCIERR_SUCCESS ) {
            CDSaveErrStr(uResult);
            return FALSE;
            }
        }

    return TRUE;
}

BOOL CDQueryVolume(USHORT DevID, ULONG *Left, ULONG *Right)
{
    MCI_STATUS_PARMS Parms;
    ULONG uResult;

    Parms.hwndCallback = NULL;
    Parms.ulItem = MCI_STATUS_VOLUME;

    uResult = mciSendCommand(DevID, MCI_STATUS, MCI_STATUS_ITEM | MCI_WAIT, &Parms, 0);

    if ( LOUSHORT(uResult) == MCIERR_SUCCESS ) {
        *Left = (ULONG)LOUSHORT(Parms.ulReturn);
        *Right = (ULONG)HIUSHORT(Parms.ulReturn);
        return TRUE;
        }
    else {
        CDSaveErrStr(uResult);
        return FALSE;
        }
}

BOOL CDMuteVolume(USHORT DevID, BOOL Mute)
{
    MCI_SET_PARMS Parms;
    ULONG uResult;

    Parms.hwndCallback = NULL;
    Parms.ulAudio = MCI_SET_AUDIO_ALL;

    if ( Mute ) {
        uResult = mciSendCommand(DevID, MCI_SET, MCI_WAIT | MCI_SET_AUDIO | MCI_SET_OFF,
            &Parms, 0);
        }
    else {
        uResult = mciSendCommand(DevID, MCI_SET, MCI_WAIT | MCI_SET_AUDIO | MCI_SET_ON,
            &Parms, 0);
        }

    if ( LOUSHORT(uResult) == MCIERR_SUCCESS ) {
        return TRUE;
        }
    else {
        CDSaveErrStr(uResult);
        return FALSE;
        }
}

/*
BOOL CDQueryTitles(CDAUDIO_CONTENTS *Contents, CDAUDIO_TITLES *Titles)
{
    ULONG i;

    Titles->TotalTitles = Contents->TotalTracks;

    if ( Titles->CDTitle != NULL )
        free(Titles->CDTitle);
    Titles->CDTitle = NULL;

    for ( i = 0; i < 99; i++) {
        if ( Titles->Track[i].Title != NULL )
            free(Titles->Track[i].Title);
        Titles->Track[i].Title = NULL;
        } 

    return TRUE;
}
*/

static void CDSaveErrStr(ULONG Result)
{
    mciGetErrorString(Result, ErrStrBuffer, sizeof(ErrStrBuffer));
}

PSZ CDLastErrStr(void)
{
    return ErrStrBuffer;
}

