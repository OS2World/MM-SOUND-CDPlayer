#if !(defined(_CDCTL_INCLUDED))
#define _CDCTL_INCLUDED

#define TE_SETCURRENT   (WM_USER+1)
#define TE_SETSELECT    (WM_USER+2)
#define TE_SETDISABLED  (WM_USER+3)
#define TE_SELECTTRACK  (WM_USER+4)
#define TE_SELECTCD     (WM_USER+5)

#define PE_SETCD        (WM_USER+1)
#define PE_TITLECHANGED (WM_USER+2)

#define IN_SETCD        (WM_USER+1)
#define IN_SCROLL       (WM_USER+2)

#define CTL_TIMEFORMAT  (WM_USER+10)

MRESULT EXPENTRY TitleEditorDlgProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2);
MRESULT EXPENTRY ProgramEditorDlgProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2);
MRESULT EXPENTRY InfoDlgProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2);

BOOL IsHelpButton(USHORT Id);
BOOL InitButtons(HWND hwndDlg);
BOOL EnableEject(BOOL Enable);
BOOL EnablePlayControls(BOOL Enable);
MRESULT CmdChangeTitles(CDAUDIO_CONTENTS *Contents, PSZ TitleAccess);
MRESULT CmdProgramPlayList(CDAUDIO_CONTENTS *Contents, PSZ TitleAccess);
MRESULT CmdOptions(void);
MRESULT CmdInfo(CDAUDIO_CONTENTS *Contents, PSZ TitleAccess);
MRESULT CmdBackward(HWND hwndDlg, CDAUDIO_PLAYLIST *PlayList, CDAUDIO_POSITION *Position);
MRESULT CmdForward(HWND hwndDlg, CDAUDIO_PLAYLIST *PlayList, CDAUDIO_POSITION *Position);
MRESULT CmdPlay(HWND hwndDlg, CDAUDIO_PLAYLIST *PlayList, CDAUDIO_POSITION *Position);
MRESULT CmdPause(HWND hwndDlg, CDAUDIO_PLAYLIST *PlayList, CDAUDIO_POSITION *Position);
MRESULT CmdStop(HWND hwndDlg, CDAUDIO_PLAYLIST *PlayList, CDAUDIO_POSITION *Position);
MRESULT CmdEject(HWND hwndDlg, CDAUDIO_PLAYLIST *PlayList, CDAUDIO_POSITION *Position);
#endif //!(defined(_CDCTL_INCLUDED))
