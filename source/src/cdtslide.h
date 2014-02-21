#if !(defined(_CDTSLIDE_INCLUDED))
#define _CDTSLIDE_INCLUDED

BOOL InitTimeSlider(HWND hwndDlg);
BOOL EnableTimeSlider(BOOL Enable);
BOOL SetupTimeSlider(CDAUDIO_PLAYLIST *PlayList);
BOOL PosTimeSlider(CDAUDIO_POSITION *Position, CDAUDIO_PLAYLIST *PlayList);
MRESULT TimeSliderControl(HWND hwndDlg, CDAUDIO_PLAYLIST *PlayList,
    CDAUDIO_CONTENTS *Contents, MPARAM mp1, MPARAM mp2);

#endif // !(defined(_CDTSLIDE_INCLUDED))
