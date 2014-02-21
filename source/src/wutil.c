#include "cdglobal.h"
#include "wutil.h"

/*
struct {
    ULONG Entries;
    SWENTRY Entry[100];
    } SWBlock;
*/

BOOL SetWindowTitle(HWND hwnd, HSWITCH hswitch, PSZ Title)
{
    SWCNTRL swcntrl;
    ULONG uResult; // , c, i;

    WinSetWindowText(hwnd, Title);

    uResult = WinQuerySwitchEntry(hswitch, &swcntrl);

    if ( uResult == 0 ) {
        strncpy(swcntrl.szSwtitle, Title, MAXNAMEL);
        swcntrl.szSwtitle[MAXNAMEL] = 0;
        swcntrl.bProgType = PROG_PM;
        uResult = WinChangeSwitchEntry(hswitch, &swcntrl);

/*
        SWBlock.Entries = 100;

        c = WinQuerySwitchList(hab, (PSWBLOCK)&SWBlock, sizeof(SWBlock));
        fprintf(stderr, "----\n");
        for ( i = 0; i < c; i++ )
            fprintf(stderr, "%s\n", SWBlock.Entry[i].swctl.szSwtitle);
*/

        return uResult == 0;
        }
    else {
        return FALSE;
        }
}

HSWITCH MakeMainWindow(HWND hwnd, PSZ Title, HPOINTER Icon)
{
    HSWITCH hswitch;
    SWCNTRL swcntrl;
    ULONG uResult; //, i;

    /*
    WinQueryWindowProcess(hwnd, (PPID)&swcntrl.idProcess, NULL);
    hswitch = WinQuerySwitchHandle(hwnd, swcntrl.idProcess);

    if ( hswitch != NULLHANDLE ) {
        uResult = WinQuerySwitchEntry(hswitch, &swcntrl);
        if ( uResult == 0 ) {
            // fprintf(stderr, "%u\n", swcntrl.hprog);
            swcntrl.hwndIcon = Icon;
            strncpy(swcntrl.szSwtitle, Title, MAXNAMEL);
            swcntrl.szSwtitle[MAXNAMEL] = 0;
            swcntrl.bProgType = PROG_PM;
            uResult = WinChangeSwitchEntry(hswitch, &swcntrl);
 
            WinSetActiveWindow(HWND_DESKTOP, hwnd);
            WinSetFocus(HWND_DESKTOP, hwnd);
            return hswitch;
            }
        }
    */

    swcntrl.hwnd = hwnd;
    swcntrl.hwndIcon = Icon;
    swcntrl.hprog = NULLHANDLE;
    // WinQueryWindowProcess(hwnd, (PPID)&swcntrl.idProcess, NULL);
    swcntrl.idProcess = 0;
    swcntrl.idSession = 0;
    swcntrl.uchVisibility = SWL_VISIBLE;
    swcntrl.fbJump = SWL_JUMPABLE;
    strncpy(swcntrl.szSwtitle, Title, MAXNAMEL);
    swcntrl.szSwtitle[MAXNAMEL] = 0;
    // swcntrl.szSwtitle[0] = 0;
    swcntrl.bProgType = 0; // PROG_PM;
    hswitch = WinCreateSwitchEntry(WinQueryAnchorBlock(hwnd), &swcntrl);
    // fprintf(stderr, "%u\n", hswitch);

    WinSetWindowText(hwnd, Title);

    WinSendMsg(hwnd, WM_SETICON, MPFROMP(Icon), 0);
    WinSetWindowULong(hwnd, QWL_STYLE,
        FS_ICON | WinQueryWindowULong(hwnd, QWL_STYLE));
    WinSendMsg(hwnd, WM_UPDATEFRAME, 0, 0);

    // WinSetActiveWindow(HWND_DESKTOP, hwnd);
    // WinSetFocus(HWND_DESKTOP, hwnd);

    /*
    SWBlock.Entries = 100;

    uResult = WinQuerySwitchList(hab, (PSWBLOCK)&SWBlock, sizeof(SWBlock));
    fprintf(stderr, "----\n");
    for ( i = 0; i < uResult; i++ )
        fprintf(stderr, "%s\n", SWBlock.Entry[i].swctl.szSwtitle);
    */

    return hswitch;
}

BOOL TrackFrameRestricted(HWND Frame, ULONG fs, POINTL *MinSize, POINTL *MaxSize)
{
    TRACKINFO TrackInfo;
    SWP WindowPos;

    TrackInfo.cxBorder =
        WinQuerySysValue(HWND_DESKTOP, SV_CXSIZEBORDER);

    TrackInfo.cyBorder =
        WinQuerySysValue(HWND_DESKTOP, SV_CYSIZEBORDER);

    TrackInfo.cxGrid =
    TrackInfo.cyGrid = 1;

    TrackInfo.cxKeyboard =
    TrackInfo.cyKeyboard = 8;

    if ( ! WinQueryWindowPos(Frame, &WindowPos) )
        return FALSE;

    TrackInfo.rclTrack.xLeft = WindowPos.x;
    TrackInfo.rclTrack.yBottom = WindowPos.y;
    TrackInfo.rclTrack.xRight = WindowPos.x + WindowPos.cx;
    TrackInfo.rclTrack.yTop = WindowPos.y + WindowPos.cy;

    WinQueryWindowRect(HWND_DESKTOP, &(TrackInfo.rclBoundary));

    if ( MinSize != NULL ) {
        TrackInfo.ptlMinTrackSize.x = MinSize->x;
        TrackInfo.ptlMinTrackSize.y = MinSize->y;
        }
    else {
        TrackInfo.ptlMinTrackSize.x = TrackInfo.cxBorder * 2;
        TrackInfo.ptlMinTrackSize.y = TrackInfo.cyBorder * 2;
        }

    if ( MaxSize != NULL ) {
        TrackInfo.ptlMaxTrackSize.x = MinSize->x;
        TrackInfo.ptlMaxTrackSize.y = MinSize->y;
        }
    else {
        TrackInfo.ptlMaxTrackSize.x = 32767;
        TrackInfo.ptlMaxTrackSize.y = 32767;
        }

    TrackInfo.fs = fs;

    if ( ! WinTrackRect(HWND_DESKTOP, NULLHANDLE, &TrackInfo) )
        return FALSE;

    if ( ! WinSetWindowPos(Frame, HWND_TOP, TrackInfo.rclTrack.xLeft, 
            TrackInfo.rclTrack.yBottom, 
            TrackInfo.rclTrack.xRight - TrackInfo.rclTrack.xLeft, 
            TrackInfo.rclTrack.yTop - TrackInfo.rclTrack.yBottom, 
            SWP_ACTIVATE | SWP_MOVE | SWP_SIZE) )
        return FALSE;

    return TRUE;
}

