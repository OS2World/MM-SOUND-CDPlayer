#if !(defined(_CDWINDOW_INCLUDED))
#define _CDWINDOW_INCLUDED

#define CD_NOTIFY_PLAY      1
#define CD_NOTIFY_SEEK      2
#define CD_NOTIFY_EJECT     3

BOOL CDQueryDevName(ULONG Index, PSZ Name, ULONG NameLen);
BOOL CDSetConnector(USHORT DevID, ULONG Connector, BOOL Enable);
BOOL CDOpenDevice(HWND Callback, PSZ DevName, PUSHORT DevID);
BOOL CDInitDevice(USHORT DevID, HWND Callback, MMTIME AdviseRate);
BOOL CDSetAdviseOff(USHORT DevID, HWND Callback);
BOOL CDSetAdviseRate(USHORT DevID, HWND Callback, MMTIME AdviseRate);
BOOL CDSetCuePoint(USHORT DevID, HWND Callback, MMTIME CuePoint);
BOOL CDSetCuePointOff(USHORT DevID, MMTIME CuePoint);
BOOL CDDriverInfo(USHORT DevID, CDAUDIO_DRIVERINFO *DriverInfo);
BOOL CDGetStatus(USHORT DevID, ULONG *Status);
BOOL CDGetContents(USHORT DevID, CDAUDIO_CONTENTS *Contents);
BOOL CDGetDefPlayList(CDAUDIO_CONTENTS *Contents, CDAUDIO_PLAYLIST *PlayList);
BOOL CDResetPlayList(CDAUDIO_CONTENTS *Contents, CDAUDIO_PLAYLIST *PlayList);
BOOL CDFlushPlayList(CDAUDIO_PLAYLIST *PlayList);
BOOL CDInsertInPlayList(CDAUDIO_CONTENTS *Contents, CDAUDIO_PLAYLIST *PlayList, 
    USHORT Entry, USHORT Track);
BOOL CDDeleteFromPlayList(CDAUDIO_CONTENTS *Contents, CDAUDIO_PLAYLIST *PlayList, 
    USHORT Entry);
BOOL CDGetPosition(USHORT DevID, MMTIME ProvideTime, CDAUDIO_CONTENTS *Contents,
    CDAUDIO_PLAYLIST *PlayList, CDAUDIO_POSITION *Pos);
BOOL CDGetRawPosition(USHORT DevID, MMTIME *Position);
BOOL CDPlay(USHORT DevID, HWND Callback, MMTIME From, MMTIME Length, USHORT User);
BOOL CDPause(USHORT DevID);
BOOL CDResume(USHORT DevID);
BOOL CDStop(USHORT DevID);
BOOL CDSeek(USHORT DevID, HWND Callback, MMTIME To);
BOOL CDEject(USHORT DevID, HWND Callback);
BOOL CDSeekImm(USHORT DevID, MMTIME To);
BOOL CDEjectImm(USHORT DevID);
BOOL CDLock(USHORT DevID);
BOOL CDUnlock(USHORT DevID);
BOOL CDSetVolume(USHORT DevID, ULONG Left, ULONG Right);
BOOL CDQueryVolume(USHORT DevID, ULONG *Left, ULONG *Right);
BOOL CDMuteVolume(USHORT DevID, BOOL Mute);
BOOL CDCloseDevice(USHORT DevID);
PSZ CDLastErrStr(void);
// BOOL CDQueryTitles(CDAUDIO_CONTENTS *Contents, CDAUDIO_TITLES *Titles);

#endif // !(defined(_CDWINDOW_INCLUDED))
