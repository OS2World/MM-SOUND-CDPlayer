#if !(defined(_CDPLAYER_INCLUDED))
#define _CDPLAYER_INCLUDED

MRESULT EXPENTRY MainDlgProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2);
MRESULT EXPENTRY SettingsDlgProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2);
MRESULT EXPENTRY AboutDlgProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2);
MRESULT EXPENTRY RegisterDlgProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2);
MRESULT EXPENTRY SettingsDlgProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2);
MRESULT EXPENTRY TimeSettingsDlgProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2);
MRESULT EXPENTRY DisplaySettingsDlgProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2);
MRESULT EXPENTRY PlaySettingsDlgProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2);
MRESULT EXPENTRY SaveSettingsDlgProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2);
MRESULT EXPENTRY OutputSettingsDlgProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2);
MRESULT EXPENTRY HardwareSettingsDlgProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2);

BOOL InitMousePointers(void);
BOOL SetWaitPointer(BOOL Set);

/* Global Variables and constants */

#define CD_INSERTED     (WM_USER+1)
#define CD_REMOVED      (WM_USER+2)
#define CD_STARTPLAY    (WM_USER+3)
#define CD_STOP         (WM_USER+4)
#define CD_POSITION     (WM_USER+5)
#define CD_SEEK         (WM_USER+6)
#define CD_OPTIONCHANGED (WM_USER+7)
#define CD_CLEANUP      (WM_USER+8)
#define CD_TITLECHANGED (WM_USER+9)
#define CD_INFOCHANGED  (WM_USER+10)
#define CD_PLAYLISTCHANGED (WM_USER+11)
#define CD_NEWDEVICE    (WM_USER+12)
#define CD_DEVICEREMOVED (WM_USER+13)
#define INTERNAL_DELAYED_RESETFOCUS (WM_USER+100)

#endif // !(defined(_CDPLAYER_INCLUDED))
