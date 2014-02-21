#if !(defined(_CDTSET_INCLUDED))
#define CDTSET_INCLUDED

BOOL InitTrackSet(HWND hwndDlg);
BOOL EnableTrackSet(BOOL Enable);
BOOL RedrawTrackSet(CDAUDIO_PLAYLIST *PlayList);
BOOL SetupTrackSet(CDAUDIO_PLAYLIST *PlayList);
BOOL PosTrackSet(CDAUDIO_PLAYLIST *PlayList);
MRESULT TrackSetScroll(CDAUDIO_PLAYLIST *PlayList, MPARAM mp1, MPARAM mp2);
MRESULT TrackSetControl(HWND hwndDlg, CDAUDIO_PLAYLIST *PlayList, 
    MPARAM mp1, MPARAM mp2);

#endif // !(defined(_CDTSET_INCLUDED))
