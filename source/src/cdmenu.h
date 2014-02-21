#if !(defined(_CDMENU_INCLUDED))
#define _CDMENU_INCLUDED

BOOL InitMenus(HWND hwndDlg);
BOOL EnableMenuItemControl(BOOL Enable);
MRESULT PopupFromClick(HWND hwndDlg, MPARAM mp1, MPARAM mp2);
MRESULT PopupFromKey(HWND hwndDlg, MPARAM mp1, MPARAM mp2);

#endif // !(defined(_CDMENU_INCLUDED))
