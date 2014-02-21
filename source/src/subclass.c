#include "cdglobal.h"
#include "cdplayer.h"
#include "subclass.h"

/* New Control functions: */

MRESULT EXPENTRY TextCDWndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2);
MRESULT EXPENTRY CDTimePlayedWndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2);
MRESULT EXPENTRY CDTimeLeftWndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2);
MRESULT EXPENTRY TextTrackWndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2);
MRESULT EXPENTRY TrackTimePlayedWndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2);
MRESULT EXPENTRY TrackTimeLeftWndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2);
MRESULT EXPENTRY TextCurrTrackWndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2);
MRESULT EXPENTRY CurrTrackWndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2);
MRESULT EXPENTRY TrackSetWndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2);
MRESULT EXPENTRY TrackSetScrollBarWndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2);
MRESULT EXPENTRY VolumeLeftWndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2);
MRESULT EXPENTRY VolumeRightWndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2);
MRESULT EXPENTRY ChannelIndependentWndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2);
MRESULT EXPENTRY ChannelSwapWndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2);
MRESULT EXPENTRY MuteWndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2);
MRESULT EXPENTRY ChangeTitlesWndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2);
MRESULT EXPENTRY ProgramTitlesWndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2);
MRESULT EXPENTRY InfoWindowWndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2);
MRESULT EXPENTRY OptionsWndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2);
MRESULT EXPENTRY TextTitleWndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2);
MRESULT EXPENTRY TitleSelectWndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2);
MRESULT EXPENTRY TimeSliderWndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2);
MRESULT EXPENTRY ForwardWndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2);
MRESULT EXPENTRY BackwardWndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2);
MRESULT EXPENTRY PlayWndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2);
MRESULT EXPENTRY PauseWndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2);
MRESULT EXPENTRY StopWndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2);
MRESULT EXPENTRY EjectWndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2);
MRESULT EXPENTRY RepeatWndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2);
MRESULT EXPENTRY HelpWndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2);

/* Old Control functions: */

PFNWP OldTextCDWndProc;
PFNWP OldCDTimePlayedWndProc;
PFNWP OldCDTimeLeftWndProc;
PFNWP OldTextTrackWndProc;
PFNWP OldTrackTimePlayedWndProc;
PFNWP OldTrackTimeLeftWndProc;
PFNWP OldTextCurrTrackWndProc;
PFNWP OldCurrTrackWndProc;
PFNWP OldTrackSetWndProc;
PFNWP OldTrackSetScrollBarWndProc;
PFNWP OldVolumeLeftWndProc;
PFNWP OldVolumeRightWndProc;
PFNWP OldChannelIndependentWndProc;
PFNWP OldChannelSwapWndProc;
PFNWP OldMuteWndProc;
PFNWP OldChangeTitlesWndProc;
PFNWP OldProgramTitlesWndProc;
PFNWP OldInfoWindowWndProc;
PFNWP OldOptionsWndProc;
PFNWP OldTextTitleWndProc;
PFNWP OldTitleSelectWndProc;
PFNWP OldTimeSliderWndProc;
PFNWP OldForwardWndProc;
PFNWP OldBackwardWndProc;
PFNWP OldPlayWndProc;
PFNWP OldPauseWndProc;
PFNWP OldStopWndProc;
PFNWP OldEjectWndProc;
PFNWP OldRepeatWndProc;
PFNWP OldHelpWndProc;

BOOL InitSubclasses(void)
{
    OldTextCDWndProc = WinSubclassWindow(hwndTextCD, TextCDWndProc);
    OldCDTimePlayedWndProc = WinSubclassWindow(hwndCDTimePlayed, CDTimePlayedWndProc);
    OldCDTimeLeftWndProc = WinSubclassWindow(hwndCDTimeLeft, CDTimeLeftWndProc);
    OldTextTrackWndProc = WinSubclassWindow(hwndTextTrack, TextTrackWndProc);
    OldTrackTimePlayedWndProc = WinSubclassWindow(hwndTrackTimePlayed, TrackTimePlayedWndProc);
    OldTrackTimeLeftWndProc = WinSubclassWindow(hwndTrackTimeLeft, TrackTimeLeftWndProc);
    OldTextCurrTrackWndProc = WinSubclassWindow(hwndTextCurrTrack, TextCurrTrackWndProc);
    OldCurrTrackWndProc = WinSubclassWindow(hwndCurrTrack, CurrTrackWndProc);

    OldTrackSetWndProc = WinSubclassWindow(hwndTrackSet, TrackSetWndProc);
    OldTrackSetScrollBarWndProc = WinSubclassWindow(hwndTrackSetScrollBar,
        TrackSetScrollBarWndProc);

    OldVolumeLeftWndProc = WinSubclassWindow(hwndVolumeLeft, VolumeLeftWndProc);
    OldVolumeRightWndProc = WinSubclassWindow(hwndVolumeRight, VolumeRightWndProc);
    OldChannelIndependentWndProc = WinSubclassWindow(hwndChannelIndependent, ChannelIndependentWndProc);
    OldChannelSwapWndProc = WinSubclassWindow(hwndChannelSwap, ChannelSwapWndProc);
    OldMuteWndProc = WinSubclassWindow(hwndMute, MuteWndProc);

    OldChangeTitlesWndProc = WinSubclassWindow(hwndChangeTitles, ChangeTitlesWndProc);
    OldProgramTitlesWndProc = WinSubclassWindow(hwndProgramTitles, ProgramTitlesWndProc);
    OldInfoWindowWndProc = WinSubclassWindow(hwndInfoWindow, InfoWindowWndProc);
    OldOptionsWndProc = WinSubclassWindow(hwndOptions, OptionsWndProc);

    OldTextTitleWndProc = WinSubclassWindow(hwndTextTitle, TextTitleWndProc);
    OldTitleSelectWndProc = WinSubclassWindow(hwndTitleSelect, TitleSelectWndProc);
    OldTimeSliderWndProc = WinSubclassWindow(hwndTimeSlider, TimeSliderWndProc);

    OldBackwardWndProc = WinSubclassWindow(hwndBackward, BackwardWndProc);
    OldForwardWndProc = WinSubclassWindow(hwndForward, ForwardWndProc);
    OldPlayWndProc = WinSubclassWindow(hwndPlay, PlayWndProc);
    OldPauseWndProc = WinSubclassWindow(hwndPause, PauseWndProc);
    OldStopWndProc = WinSubclassWindow(hwndStop, StopWndProc);
    OldEjectWndProc = WinSubclassWindow(hwndEject, EjectWndProc);
    OldRepeatWndProc = WinSubclassWindow(hwndRepeat, RepeatWndProc);
    OldHelpWndProc = WinSubclassWindow(hwndHelp, HelpWndProc);

    return TRUE;
}


MRESULT EXPENTRY TextCDWndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2)
{
    POINTL Point;

    switch ( msg ) {
      case WM_BUTTON2CLICK :
      case WM_BUTTON2DBLCLK :
      case WM_BUTTON3CLICK :
      case WM_BUTTON3DBLCLK :
        Point.x = SHORT1FROMMP(mp1);
        Point.y = SHORT2FROMMP(mp1);
        WinMapWindowPoints(hwnd, hwndDlg, &Point, 1);
        return WinSendMsg(hwndDlg, msg, MPFROM2SHORT(Point.x, Point.y), mp2);
        }

    return OldTextCDWndProc(hwnd, msg, mp1, mp2);
}

MRESULT EXPENTRY CDTimePlayedWndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2)
{
    POINTL Point;

    switch ( msg ) {
      case WM_BUTTON2CLICK :
      case WM_BUTTON2DBLCLK :
      case WM_BUTTON3CLICK :
      case WM_BUTTON3DBLCLK :
        Point.x = SHORT1FROMMP(mp1);
        Point.y = SHORT2FROMMP(mp1);
        WinMapWindowPoints(hwnd, hwndDlg, &Point, 1);
        return WinSendMsg(hwndDlg, msg, MPFROM2SHORT(Point.x, Point.y), mp2);
        }

    return OldCDTimePlayedWndProc(hwnd, msg, mp1, mp2);
}

MRESULT EXPENTRY CDTimeLeftWndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2)
{
    POINTL Point;

    switch ( msg ) {
      case WM_BUTTON2CLICK :
      case WM_BUTTON2DBLCLK :
      case WM_BUTTON3CLICK :
      case WM_BUTTON3DBLCLK :
        Point.x = SHORT1FROMMP(mp1);
        Point.y = SHORT2FROMMP(mp1);
        WinMapWindowPoints(hwnd, hwndDlg, &Point, 1);
        return WinSendMsg(hwndDlg, msg, MPFROM2SHORT(Point.x, Point.y), mp2);
        }

    return OldCDTimeLeftWndProc(hwnd, msg, mp1, mp2);
}

MRESULT EXPENTRY TextTrackWndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2)
{
    POINTL Point;

    switch ( msg ) {
      case WM_BUTTON2CLICK :
      case WM_BUTTON2DBLCLK :
      case WM_BUTTON3CLICK :
      case WM_BUTTON3DBLCLK :
        Point.x = SHORT1FROMMP(mp1);
        Point.y = SHORT2FROMMP(mp1);
        WinMapWindowPoints(hwnd, hwndDlg, &Point, 1);
        return WinSendMsg(hwndDlg, msg, MPFROM2SHORT(Point.x, Point.y), mp2);
        }

    return OldTextTrackWndProc(hwnd, msg, mp1, mp2);
}

MRESULT EXPENTRY TrackTimePlayedWndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2)
{
    POINTL Point;

    switch ( msg ) {
      case WM_BUTTON2CLICK :
      case WM_BUTTON2DBLCLK :
      case WM_BUTTON3CLICK :
      case WM_BUTTON3DBLCLK :
        Point.x = SHORT1FROMMP(mp1);
        Point.y = SHORT2FROMMP(mp1);
        WinMapWindowPoints(hwnd, hwndDlg, &Point, 1);
        return WinSendMsg(hwndDlg, msg, MPFROM2SHORT(Point.x, Point.y), mp2);
        }

    return OldTrackTimePlayedWndProc(hwnd, msg, mp1, mp2);
}

MRESULT EXPENTRY TrackTimeLeftWndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2)
{
    POINTL Point;

    switch ( msg ) {
      case WM_BUTTON2CLICK :
      case WM_BUTTON2DBLCLK :
      case WM_BUTTON3CLICK :
      case WM_BUTTON3DBLCLK :
        Point.x = SHORT1FROMMP(mp1);
        Point.y = SHORT2FROMMP(mp1);
        WinMapWindowPoints(hwnd, hwndDlg, &Point, 1);
        return WinSendMsg(hwndDlg, msg, MPFROM2SHORT(Point.x, Point.y), mp2);
        }

    return OldTrackTimeLeftWndProc(hwnd, msg, mp1, mp2);
}

MRESULT EXPENTRY TextCurrTrackWndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2)
{
    POINTL Point;

    switch ( msg ) {
      case WM_BUTTON2CLICK :
      case WM_BUTTON2DBLCLK :
      case WM_BUTTON3CLICK :
      case WM_BUTTON3DBLCLK :
        Point.x = SHORT1FROMMP(mp1);
        Point.y = SHORT2FROMMP(mp1);
        WinMapWindowPoints(hwnd, hwndDlg, &Point, 1);
        return WinSendMsg(hwndDlg, msg, MPFROM2SHORT(Point.x, Point.y), mp2);
        }

    return OldTextCurrTrackWndProc(hwnd, msg, mp1, mp2);
}

MRESULT EXPENTRY CurrTrackWndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2)
{
    POINTL Point;

    switch ( msg ) {
      case WM_BUTTON2CLICK :
      case WM_BUTTON2DBLCLK :
      case WM_BUTTON3CLICK :
      case WM_BUTTON3DBLCLK :
        Point.x = SHORT1FROMMP(mp1);
        Point.y = SHORT2FROMMP(mp1);
        WinMapWindowPoints(hwnd, hwndDlg, &Point, 1);
        return WinSendMsg(hwndDlg, msg, MPFROM2SHORT(Point.x, Point.y), mp2);
        }

    return OldCurrTrackWndProc(hwnd, msg, mp1, mp2);
}


MRESULT EXPENTRY TrackSetWndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2)
{
    POINTL Point;

    switch ( msg ) {
      case WM_BUTTON2CLICK :
      case WM_BUTTON2DBLCLK :
      case WM_BUTTON3CLICK :
      case WM_BUTTON3DBLCLK :
        Point.x = SHORT1FROMMP(mp1);
        Point.y = SHORT2FROMMP(mp1);
        WinMapWindowPoints(hwnd, hwndDlg, &Point, 1);
        return WinSendMsg(hwndDlg, msg, MPFROM2SHORT(Point.x, Point.y), mp2);

      case WM_CHAR :
        if ( (SHORT1FROMMP(mp1) & KC_VIRTUALKEY) &&
             ! (SHORT1FROMMP(mp1) & KC_KEYUP) ) {
            switch ( SHORT2FROMMP(mp2) ) {
              case VK_DOWN :
                if ( TrackSetCurrRow == TRACKSET_ROWS ) {
                    WinSendMsg(hwndDlg, WM_VSCROLL, MPFROMSHORT(ID_TRACKSET_SCROLLBAR),
                        MPFROM2SHORT(0, SB_LINEDOWN));
                    return MRFROMLONG(TRUE);
                    }
                break;

              case VK_UP :
                if ( TrackSetCurrRow == 1 ) {
                    WinSendMsg(hwndDlg, WM_VSCROLL, MPFROMSHORT(ID_TRACKSET_SCROLLBAR),
                        MPFROM2SHORT(0, SB_LINEUP));
                    return MRFROMLONG(TRUE);
                    }
                break;

              case VK_PAGEDOWN :
                if ( VirtRowOffset < VirtRows - TRACKSET_ROWS ) {
                    WinSendMsg(hwndDlg, WM_VSCROLL, MPFROMSHORT(ID_TRACKSET_SCROLLBAR),
                        MPFROM2SHORT(0, SB_PAGEDOWN));
                    return MRFROMLONG(TRUE);
                    }
                break;

              case VK_PAGEUP :
                if ( VirtRowOffset > 0 ) {
                    WinSendMsg(hwndDlg, WM_VSCROLL, MPFROMSHORT(ID_TRACKSET_SCROLLBAR),
                        MPFROM2SHORT(0, SB_PAGEUP));
                    return MRFROMLONG(TRUE);
                    }
                break;

              case VK_LEFT :
                if ( TrackSetCurrCol == 1 ) {
                    if ( TrackSetCurrRow == 1 ) {
                        if ( VirtRowOffset > 0 ) {
                            WinSendMsg(hwndDlg, WM_VSCROLL, MPFROMSHORT(ID_TRACKSET_SCROLLBAR),
                                MPFROM2SHORT(0, SB_LINEUP));
                            WinSendMsg(hwndTrackSet, VM_SELECTITEM,
                                MPFROM2SHORT(1, TRACKSET_COLS), NULL);
                            }
                        }
                    else {
                        WinSendMsg(hwndTrackSet, VM_SELECTITEM,
                            MPFROM2SHORT(TrackSetCurrRow - 1, TRACKSET_COLS), NULL);
                        }
                    return MRFROMLONG(TRUE);
                    }
                break;

              case VK_RIGHT :
                if ( TrackSetCurrCol == TRACKSET_COLS ) {
                    if ( TrackSetCurrRow == TRACKSET_ROWS ) {
                        if ( VirtRowOffset < VirtRows - TRACKSET_ROWS ) {
                            WinSendMsg(hwndDlg, WM_VSCROLL, MPFROMSHORT(ID_TRACKSET_SCROLLBAR),
                                MPFROM2SHORT(0, SB_LINEDOWN));
                            WinSendMsg(hwndTrackSet, VM_SELECTITEM,
                                MPFROM2SHORT(TRACKSET_ROWS, 1), NULL);
                            }
                        }
                    else {
                        WinSendMsg(hwndTrackSet, VM_SELECTITEM,
                            MPFROM2SHORT(TrackSetCurrRow + 1, 1), NULL);
                        }
                    return MRFROMLONG(TRUE);
                    }
                break;

                } /* endswitch */
            }
        }

    return OldTrackSetWndProc(hwnd, msg, mp1, mp2);
}

MRESULT EXPENTRY TrackSetScrollBarWndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2)
{
    POINTL Point;

    switch ( msg ) {
      case WM_BUTTON2CLICK :
      case WM_BUTTON2DBLCLK :
      case WM_BUTTON3CLICK :
      case WM_BUTTON3DBLCLK :
        Point.x = SHORT1FROMMP(mp1);
        Point.y = SHORT2FROMMP(mp1);
        WinMapWindowPoints(hwnd, hwndDlg, &Point, 1);
        return WinSendMsg(hwndDlg, msg, MPFROM2SHORT(Point.x, Point.y), mp2);

      case WM_BUTTON2DOWN :
      case WM_BUTTON2UP :
        return MRFROMLONG(TRUE);

      case WM_CHAR :
        if ( (SHORT1FROMMP(mp1) & KC_VIRTUALKEY) &&
             ! (SHORT1FROMMP(mp1) & KC_KEYUP) ) {
            switch ( SHORT2FROMMP(mp2) ) {
              case VK_LEFT :
              case VK_RIGHT :
              case VK_HOME :
              case VK_END :
                return WinSendMsg(hwndTrackSet, msg, mp1, mp2);
                } /* endswitch */
            }
        }

    return OldTrackSetScrollBarWndProc(hwnd, msg, mp1, mp2);
}

MRESULT EXPENTRY VolumeLeftWndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2)
{
    POINTL Point;

    switch ( msg ) {
      case WM_BUTTON2CLICK :
      case WM_BUTTON2DBLCLK :
      case WM_BUTTON3CLICK :
      case WM_BUTTON3DBLCLK :
        Point.x = SHORT1FROMMP(mp1);
        Point.y = SHORT2FROMMP(mp1);
        WinMapWindowPoints(hwnd, hwndDlg, &Point, 1);
        return WinSendMsg(hwndDlg, msg, MPFROM2SHORT(Point.x, Point.y), mp2);
      case WM_BUTTON2DOWN :
      case WM_BUTTON2UP :
        return MRFROMLONG(TRUE);
        }

    return OldVolumeLeftWndProc(hwnd, msg, mp1, mp2);
}

MRESULT EXPENTRY VolumeRightWndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2)
{
    POINTL Point;

    switch ( msg ) {
      case WM_BUTTON2CLICK :
      case WM_BUTTON2DBLCLK :
      case WM_BUTTON3CLICK :
      case WM_BUTTON3DBLCLK :
        Point.x = SHORT1FROMMP(mp1);
        Point.y = SHORT2FROMMP(mp1);
        WinMapWindowPoints(hwnd, hwndDlg, &Point, 1);
        return WinSendMsg(hwndDlg, msg, MPFROM2SHORT(Point.x, Point.y), mp2);
      case WM_BUTTON2DOWN :
      case WM_BUTTON2UP :
        return MRFROMLONG(TRUE);
        }

    return OldVolumeRightWndProc(hwnd, msg, mp1, mp2);
}

MRESULT EXPENTRY ChannelIndependentWndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2)
{
    POINTL Point;

    switch ( msg ) {
      case WM_BUTTON2CLICK :
      case WM_BUTTON2DBLCLK :
      case WM_BUTTON3CLICK :
      case WM_BUTTON3DBLCLK :
        Point.x = SHORT1FROMMP(mp1);
        Point.y = SHORT2FROMMP(mp1);
        WinMapWindowPoints(hwnd, hwndDlg, &Point, 1);
        return WinSendMsg(hwndDlg, msg, MPFROM2SHORT(Point.x, Point.y), mp2);
      case WM_CHAR :
        if ( (SHORT1FROMMP(mp1) & KC_VIRTUALKEY) ) {
            if ( SHORT2FROMMP(mp2) == VK_F10 &&
                 (SHORT1FROMMP(mp1) & (KC_SHIFT)) ) {
                return WinSendMsg(hwndDlg, msg, mp1, mp2);
                }
            }
        }

    return OldChannelIndependentWndProc(hwnd, msg, mp1, mp2);
}

MRESULT EXPENTRY ChannelSwapWndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2)
{
    POINTL Point;

    switch ( msg ) {
      case WM_BUTTON2CLICK :
      case WM_BUTTON2DBLCLK :
      case WM_BUTTON3CLICK :
      case WM_BUTTON3DBLCLK :
        Point.x = SHORT1FROMMP(mp1);
        Point.y = SHORT2FROMMP(mp1);
        WinMapWindowPoints(hwnd, hwndDlg, &Point, 1);
        return WinSendMsg(hwndDlg, msg, MPFROM2SHORT(Point.x, Point.y), mp2);
      case WM_CHAR :
        if ( (SHORT1FROMMP(mp1) & KC_VIRTUALKEY) ) {
            if ( SHORT2FROMMP(mp2) == VK_F10 &&
                 (SHORT1FROMMP(mp1) & (KC_SHIFT)) ) {
                return WinSendMsg(hwndDlg, msg, mp1, mp2);
                }
            }
        }

    return OldChannelSwapWndProc(hwnd, msg, mp1, mp2);
}


MRESULT EXPENTRY MuteWndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2)
{
    POINTL Point;

    switch ( msg ) {
      case WM_BUTTON2CLICK :
      case WM_BUTTON2DBLCLK :
      case WM_BUTTON3CLICK :
      case WM_BUTTON3DBLCLK :
        Point.x = SHORT1FROMMP(mp1);
        Point.y = SHORT2FROMMP(mp1);
        WinMapWindowPoints(hwnd, hwndDlg, &Point, 1);
        return WinSendMsg(hwndDlg, msg, MPFROM2SHORT(Point.x, Point.y), mp2);
        }

    return OldMuteWndProc(hwnd, msg, mp1, mp2);
}

MRESULT EXPENTRY ChangeTitlesWndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2)
{
    POINTL Point;

    switch ( msg ) {
      case WM_BUTTON2CLICK :
      case WM_BUTTON2DBLCLK :
      case WM_BUTTON3CLICK :
      case WM_BUTTON3DBLCLK :
        Point.x = SHORT1FROMMP(mp1);
        Point.y = SHORT2FROMMP(mp1);
        WinMapWindowPoints(hwnd, hwndDlg, &Point, 1);
        return WinSendMsg(hwndDlg, msg, MPFROM2SHORT(Point.x, Point.y), mp2);
      case WM_CHAR :
        if ( (SHORT1FROMMP(mp1) & KC_VIRTUALKEY) ) {
            if ( SHORT2FROMMP(mp2) == VK_F10 &&
                 (SHORT1FROMMP(mp1) & (KC_SHIFT)) ) {
                return WinSendMsg(hwndDlg, msg, mp1, mp2);
                }
            }
        }

    return OldChangeTitlesWndProc(hwnd, msg, mp1, mp2);
}

MRESULT EXPENTRY ProgramTitlesWndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2)
{
    POINTL Point;

    switch ( msg ) {
      case WM_BUTTON2CLICK :
      case WM_BUTTON2DBLCLK :
      case WM_BUTTON3CLICK :
      case WM_BUTTON3DBLCLK :
        Point.x = SHORT1FROMMP(mp1);
        Point.y = SHORT2FROMMP(mp1);
        WinMapWindowPoints(hwnd, hwndDlg, &Point, 1);
        return WinSendMsg(hwndDlg, msg, MPFROM2SHORT(Point.x, Point.y), mp2);
      case WM_CHAR :
        if ( (SHORT1FROMMP(mp1) & KC_VIRTUALKEY) ) {
            if ( SHORT2FROMMP(mp2) == VK_F10 &&
                 (SHORT1FROMMP(mp1) & (KC_SHIFT)) ) {
                return WinSendMsg(hwndDlg, msg, mp1, mp2);
                }
            }
        }

    return OldProgramTitlesWndProc(hwnd, msg, mp1, mp2);
}

MRESULT EXPENTRY InfoWindowWndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2)
{
    POINTL Point;

    switch ( msg ) {
      case WM_BUTTON2CLICK :
      case WM_BUTTON2DBLCLK :
      case WM_BUTTON3CLICK :
      case WM_BUTTON3DBLCLK :
        Point.x = SHORT1FROMMP(mp1);
        Point.y = SHORT2FROMMP(mp1);
        WinMapWindowPoints(hwnd, hwndDlg, &Point, 1);
        return WinSendMsg(hwndDlg, msg, MPFROM2SHORT(Point.x, Point.y), mp2);
      case WM_CHAR :
        if ( (SHORT1FROMMP(mp1) & KC_VIRTUALKEY) ) {
            if ( SHORT2FROMMP(mp2) == VK_F10 &&
                 (SHORT1FROMMP(mp1) & (KC_SHIFT)) ) {
                return WinSendMsg(hwndDlg, msg, mp1, mp2);
                }
            }
        }

    return OldInfoWindowWndProc(hwnd, msg, mp1, mp2);
}

MRESULT EXPENTRY OptionsWndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2)
{
    POINTL Point;

    switch ( msg ) {
      case WM_BUTTON2CLICK :
      case WM_BUTTON2DBLCLK :
      case WM_BUTTON3CLICK :
      case WM_BUTTON3DBLCLK :
        Point.x = SHORT1FROMMP(mp1);
        Point.y = SHORT2FROMMP(mp1);
        WinMapWindowPoints(hwnd, hwndDlg, &Point, 1);
        return WinSendMsg(hwndDlg, msg, MPFROM2SHORT(Point.x, Point.y), mp2);
      case WM_CHAR :
        if ( (SHORT1FROMMP(mp1) & KC_VIRTUALKEY) ) {
            if ( SHORT2FROMMP(mp2) == VK_F10 &&
                 (SHORT1FROMMP(mp1) & (KC_SHIFT)) ) {
                return WinSendMsg(hwndDlg, msg, mp1, mp2);
                }
            }
        }

    return OldOptionsWndProc(hwnd, msg, mp1, mp2);
}

MRESULT EXPENTRY TextTitleWndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2)
{
    POINTL Point;

    switch ( msg ) {
      case WM_BUTTON2CLICK :
      case WM_BUTTON2DBLCLK :
      case WM_BUTTON3CLICK :
      case WM_BUTTON3DBLCLK :
        Point.x = SHORT1FROMMP(mp1);
        Point.y = SHORT2FROMMP(mp1);
        WinMapWindowPoints(hwnd, hwndDlg, &Point, 1);
        return WinSendMsg(hwndDlg, msg, MPFROM2SHORT(Point.x, Point.y), mp2);
        }

    return OldTextTitleWndProc(hwnd, msg, mp1, mp2);
}

MRESULT EXPENTRY TitleSelectWndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2)
{
    POINTL Point;

    switch ( msg ) {
      case WM_BUTTON2CLICK :
      case WM_BUTTON2DBLCLK :
      case WM_BUTTON3CLICK :
      case WM_BUTTON3DBLCLK :
        Point.x = SHORT1FROMMP(mp1);
        Point.y = SHORT2FROMMP(mp1);
        WinMapWindowPoints(hwnd, hwndDlg, &Point, 1);
        return WinSendMsg(hwndDlg, msg, MPFROM2SHORT(Point.x, Point.y), mp2);
        }

    return OldTitleSelectWndProc(hwnd, msg, mp1, mp2);
}

MRESULT EXPENTRY TimeSliderWndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2)
{
    POINTL Point;

    switch ( msg ) {
      case WM_BUTTON2CLICK :
      case WM_BUTTON2DBLCLK :
      case WM_BUTTON3CLICK :
      case WM_BUTTON3DBLCLK :
        Point.x = SHORT1FROMMP(mp1);
        Point.y = SHORT2FROMMP(mp1);
        WinMapWindowPoints(hwnd, hwndDlg, &Point, 1);
        return WinSendMsg(hwndDlg, msg, MPFROM2SHORT(Point.x, Point.y), mp2);
      case WM_BUTTON2DOWN :
      case WM_BUTTON2UP :
        return MRFROMLONG(TRUE);
        }

    return OldTimeSliderWndProc(hwnd, msg, mp1, mp2);
}


MRESULT EXPENTRY BackwardWndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2)
{
    POINTL Point;

    switch ( msg ) {
      case WM_BUTTON2CLICK :
      case WM_BUTTON2DBLCLK :
      case WM_BUTTON3CLICK :
      case WM_BUTTON3DBLCLK :
        Point.x = SHORT1FROMMP(mp1);
        Point.y = SHORT2FROMMP(mp1);
        WinMapWindowPoints(hwnd, hwndDlg, &Point, 1);
        return WinSendMsg(hwndDlg, msg, MPFROM2SHORT(Point.x, Point.y), mp2);
        }

    return OldBackwardWndProc(hwnd, msg, mp1, mp2);
}

MRESULT EXPENTRY ForwardWndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2)
{
    POINTL Point;

    switch ( msg ) {
      case WM_BUTTON2CLICK :
      case WM_BUTTON2DBLCLK :
      case WM_BUTTON3CLICK :
      case WM_BUTTON3DBLCLK :
        Point.x = SHORT1FROMMP(mp1);
        Point.y = SHORT2FROMMP(mp1);
        WinMapWindowPoints(hwnd, hwndDlg, &Point, 1);
        return WinSendMsg(hwndDlg, msg, MPFROM2SHORT(Point.x, Point.y), mp2);
        }

    return OldForwardWndProc(hwnd, msg, mp1, mp2);
}

MRESULT EXPENTRY PlayWndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2)
{
    POINTL Point;

    switch ( msg ) {
      case WM_BUTTON2CLICK :
      case WM_BUTTON2DBLCLK :
      case WM_BUTTON3CLICK :
      case WM_BUTTON3DBLCLK :
        Point.x = SHORT1FROMMP(mp1);
        Point.y = SHORT2FROMMP(mp1);
        WinMapWindowPoints(hwnd, hwndDlg, &Point, 1);
        return WinSendMsg(hwndDlg, msg, MPFROM2SHORT(Point.x, Point.y), mp2);
        }

    return OldPlayWndProc(hwnd, msg, mp1, mp2);
}

MRESULT EXPENTRY PauseWndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2)
{
    POINTL Point;

    switch ( msg ) {
      case WM_BUTTON2CLICK :
      case WM_BUTTON2DBLCLK :
      case WM_BUTTON3CLICK :
      case WM_BUTTON3DBLCLK :
        Point.x = SHORT1FROMMP(mp1);
        Point.y = SHORT2FROMMP(mp1);
        WinMapWindowPoints(hwnd, hwndDlg, &Point, 1);
        return WinSendMsg(hwndDlg, msg, MPFROM2SHORT(Point.x, Point.y), mp2);
        }

    return OldPauseWndProc(hwnd, msg, mp1, mp2);
}

MRESULT EXPENTRY StopWndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2)
{
    POINTL Point;

    switch ( msg ) {
      case WM_BUTTON2CLICK :
      case WM_BUTTON2DBLCLK :
      case WM_BUTTON3CLICK :
      case WM_BUTTON3DBLCLK :
        Point.x = SHORT1FROMMP(mp1);
        Point.y = SHORT2FROMMP(mp1);
        WinMapWindowPoints(hwnd, hwndDlg, &Point, 1);
        return WinSendMsg(hwndDlg, msg, MPFROM2SHORT(Point.x, Point.y), mp2);
        }

    return OldStopWndProc(hwnd, msg, mp1, mp2);
}

MRESULT EXPENTRY EjectWndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2)
{
    POINTL Point;
    MRESULT mResult;

    switch ( msg ) {
      case WM_BUTTON2CLICK :
      case WM_BUTTON2DBLCLK :
      case WM_BUTTON3CLICK :
      case WM_BUTTON3DBLCLK :
        Point.x = SHORT1FROMMP(mp1);
        Point.y = SHORT2FROMMP(mp1);
        WinMapWindowPoints(hwnd, hwndDlg, &Point, 1);
        return WinSendMsg(hwndDlg, msg, MPFROM2SHORT(Point.x, Point.y), mp2);
      case WM_HITTEST :
        mResult = OldEjectWndProc(hwnd, msg, mp1, mp2);
        return mResult;
        }

    return OldEjectWndProc(hwnd, msg, mp1, mp2);
}

MRESULT EXPENTRY RepeatWndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2)
{
    POINTL Point;

    switch ( msg ) {
      case WM_BUTTON2CLICK :
      case WM_BUTTON2DBLCLK :
      case WM_BUTTON3CLICK :
      case WM_BUTTON3DBLCLK :
        Point.x = SHORT1FROMMP(mp1);
        Point.y = SHORT2FROMMP(mp1);
        WinMapWindowPoints(hwnd, hwndDlg, &Point, 1);
        return WinSendMsg(hwndDlg, msg, MPFROM2SHORT(Point.x, Point.y), mp2);
        }

    return OldRepeatWndProc(hwnd, msg, mp1, mp2);
}

MRESULT EXPENTRY HelpWndProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2)
{
    POINTL Point;

    switch ( msg ) {
      case WM_BUTTON2CLICK :
      case WM_BUTTON2DBLCLK :
      case WM_BUTTON3CLICK :
      case WM_BUTTON3DBLCLK :
        Point.x = SHORT1FROMMP(mp1);
        Point.y = SHORT2FROMMP(mp1);
        WinMapWindowPoints(hwnd, hwndDlg, &Point, 1);
        return WinSendMsg(hwndDlg, msg, MPFROM2SHORT(Point.x, Point.y), mp2);
      case WM_CHAR :
        if ( (SHORT1FROMMP(mp1) & KC_VIRTUALKEY) ) {
            if ( SHORT2FROMMP(mp2) == VK_F10 &&
                 (SHORT1FROMMP(mp1) & (KC_SHIFT)) ) {
                return WinSendMsg(hwndDlg, msg, mp1, mp2);
                }
            }
        }

    return OldHelpWndProc(hwnd, msg, mp1, mp2);
}

