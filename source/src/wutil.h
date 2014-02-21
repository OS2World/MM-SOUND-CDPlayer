#if !(defined(_WUTIL_INCLUDED))
#define _WUTIL_INCLUDED

BOOL SetWindowTitle(HWND hwnd, HSWITCH hSwitch, PSZ Title);
HSWITCH MakeMainWindow(HWND hwnd, PSZ Title, HPOINTER Icon);
BOOL TrackFrameRestricted(HWND Frame, ULONG fs, POINTL *MinSize, POINTL *MaxSize);

#endif // !(defined(_WUTIL_INCLUDED))
