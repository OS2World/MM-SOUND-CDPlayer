#include "cdglobal.h"
#include "cdmenu.h"

BOOL InitMenus(HWND hwndDlg)
{
    MENUITEM miSep = { MIT_END, MIS_SEPARATOR, 0, 0, NULL, 0 };
    MENUITEM miInsert = { MIT_END, MIS_TEXT, 0, ID_ABOUT, NULL, 0 };
    MENUITEM miItem;
    ULONG ulStyle;
    HWND hwndSysmenu;
    MENUITEM miSysmenu;
    SHORT idSysmenu;
    BOOL bResult;

    MainMenu = WinLoadMenu(HWND_DESKTOP, NULLHANDLE, ID_MAIN_MENU);
    ControlMenu = WinLoadMenu(hwndDlg, NULLHANDLE, ID_CONTROL_MENU);
    SettingsMenu = WinLoadMenu(hwndDlg, NULLHANDLE, ID_SETTINGS_MENU);
    HelpMenu = WinLoadMenu(hwndDlg, NULLHANDLE, ID_HELP_MENU);

    WinSendMsg(MainMenu, MM_QUERYITEM, MPFROM2SHORT(ID_HELP_MENU, TRUE),
        MPFROMP(&miItem));
 
    ulStyle = WinQueryWindowULong(miItem.hwndSubMenu, QWL_STYLE);
    ulStyle |= MS_CONDITIONALCASCADE;
    WinSetWindowULong(miItem.hwndSubMenu, QWL_STYLE, ulStyle);

    WinSendMsg(miItem.hwndSubMenu, MM_SETDEFAULTITEMID, 
        MPFROM2SHORT(ID_HELPEXTENDED, FALSE), NULL);
 
    WinSendMsg(miItem.hwndSubMenu, MM_SETITEMATTR,
        MPFROM2SHORT(ID_HELPEXTENDED, FALSE), MPFROM2SHORT(MIA_CHECKED, MIA_CHECKED));

    ulStyle = WinQueryWindowULong(HelpMenu, QWL_STYLE);
    ulStyle |= MS_CONDITIONALCASCADE;
    WinSetWindowULong(HelpMenu, QWL_STYLE, ulStyle);

    WinSendMsg(HelpMenu, MM_SETDEFAULTITEMID,
        MPFROM2SHORT(ID_HELPEXTENDED, FALSE), NULL);

    WinSendMsg(HelpMenu, MM_SETITEMATTR,
        MPFROM2SHORT(ID_HELPEXTENDED, FALSE), MPFROM2SHORT(MIA_CHECKED, MIA_CHECKED));

    hwndSysmenu = WinWindowFromID(hwndDlg, FID_SYSMENU);
    idSysmenu = SHORT1FROMMR(WinSendMsg(hwndSysmenu,
        MM_ITEMIDFROMPOSITION, MPFROMSHORT(0), NULL));
    WinSendMsg(hwndSysmenu, MM_QUERYITEM, MPFROM2SHORT(idSysmenu, FALSE),
        MPFROMP(&miSysmenu));
    sysSubmenu = miSysmenu.hwndSubMenu;

    WinSendMsg(sysSubmenu, MM_INSERTITEM, MPFROMP(&miSep), NULL);

    miInsert.hwndSubMenu = ControlMenu;
    miInsert.id = ID_CONTROL_MENU;
    WinSendMsg(sysSubmenu, MM_INSERTITEM, MPFROMP(&miInsert), MPFROMP(ControlText));

    miInsert.hwndSubMenu = SettingsMenu;
    miInsert.id = ID_SETTINGS_MENU;
    WinSendMsg(sysSubmenu, MM_INSERTITEM, MPFROMP(&miInsert), MPFROMP(SettingsText));

    miInsert.hwndSubMenu = NULL;
    miInsert.id = ID_MUTE;
    WinSendMsg(sysSubmenu, MM_INSERTITEM, MPFROMP(&miInsert), MPFROMP(MuteOffText));

    WinSendMsg(sysSubmenu, MM_INSERTITEM, MPFROMP(&miSep), NULL);

    miInsert.hwndSubMenu = HelpMenu;
    miInsert.id = ID_HELP_MENU;
    WinSendMsg(sysSubmenu, MM_INSERTITEM, MPFROMP(&miInsert), MPFROMP(HelpText));

    miInsert.hwndSubMenu = NULL;
    miInsert.id = ID_ABOUT;
    WinSendMsg(sysSubmenu, MM_INSERTITEM, MPFROMP(&miInsert), MPFROMP(AboutText));

    DlgAccelTable = WinLoadAccelTable(hab, NULLHANDLE, ID_DLG_MAIN);
    if ( DlgAccelTable != NULLHANDLE ) {
        bResult = WinSetAccelTable(hab, DlgAccelTable, hwndDlg);
        }

    return TRUE;
}

BOOL EnableMenuItemControl(BOOL Enable)
{
    USHORT ItemFlag = (Enable ? 0 : MIA_DISABLED);

    WinSendMsg(MainMenu, MM_SETITEMATTR, MPFROM2SHORT(ID_CONTROL_MENU, FALSE),
        MPFROM2SHORT(MIA_DISABLED, ItemFlag));

    return TRUE;
}

MRESULT PopupFromClick(HWND hwndDlg, MPARAM mp1, MPARAM mp2)
{
    BOOL bResult;

    bResult = WinPopupMenu(hwndDlg, hwndDlg, MainMenu, SHORT1FROMMP(mp1),
        SHORT2FROMMP(mp1), 0,
        PU_HCONSTRAIN | PU_VCONSTRAIN | PU_KEYBOARD | PU_MOUSEBUTTON1);
    return MRFROMLONG(TRUE);
}

MRESULT PopupFromKey(HWND hwndDlg, MPARAM mp1, MPARAM mp2)
{
    RECTL WindowPos;
    BOOL bResult;

    WinQueryWindowRect(hwndDlg, &WindowPos);
    bResult = WinPopupMenu(hwndDlg, hwndDlg, MainMenu, WindowPos.xRight / 2,
        WindowPos.yTop / 2, 0,
        PU_HCONSTRAIN | PU_VCONSTRAIN | PU_KEYBOARD | PU_MOUSEBUTTON1);
    return MRFROMLONG(TRUE);
}

