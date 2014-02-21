#include "cdglobal.h"
#include "cdplayer.h"
#include "cdtset.h"

static ULONG OldTrack = -1;
static ULONG OldVirtRow = -1;

BOOL InitTrackSet(HWND hwndDlg)
{
    int i,j;

    hwndTrackSet = WinWindowFromID(hwndDlg, ID_TRACKSET);
    hwndTrackSetScrollBar = WinWindowFromID(hwndDlg, ID_TRACKSET_SCROLLBAR);

    for ( i = 0; i < TRACKSET_ROWS; i++ ) {
        for ( j = 0; j < TRACKSET_COLS ; j++ ) {
            WinSendMsg(hwndTrackSet, VM_SETITEMATTR, MPFROM2SHORT(i+1, j+1),
                MPFROM2SHORT(VIA_TEXT | VIA_DROPONABLE | VIA_DRAGGABLE, TRUE));
            }
        }

    return TRUE;
}

BOOL EnableTrackSet(BOOL Enable)
{
    int i,j;

    if ( Enable ) {
        for ( i = 0; i < TRACKSET_ROWS; i++ ) {
            for ( j = 0; j < TRACKSET_COLS ; j++ ) {
                WinSendMsg(hwndTrackSet, VM_SETITEMATTR, MPFROM2SHORT(i+1, j+1),
                    MPFROM2SHORT(VIA_DISABLED, FALSE));
                }
            }
        }
    else {
        for ( i = 0; i < TRACKSET_ROWS; i++ ) {
            for ( j = 0; j < TRACKSET_COLS ; j++ ) {
                WinSendMsg(hwndTrackSet, VM_SETITEMATTR, MPFROM2SHORT(i+1, j+1),
                    MPFROM2SHORT(VIA_DISABLED, TRUE));
                WinSendMsg(hwndTrackSet, VM_SETITEM, MPFROM2SHORT(i+1, j+1), TrackUnknown);
                }
            }

        WinSendMsg(hwndTrackSetScrollBar, SBM_SETTHUMBSIZE, MPFROM2SHORT(1,1), NULL);
        WinSendMsg(hwndTrackSetScrollBar, SBM_SETSCROLLBAR, MPFROMSHORT(0),
            MPFROM2SHORT(0, 0));
        }

    WinEnableWindow(hwndTrackSetScrollBar, Enable);
    return TRUE;
}

BOOL RedrawTrackSet(CDAUDIO_PLAYLIST *PlayList)
{
    int i, j;
    char ConvBuf[8];

    for ( i = 0; i < TRACKSET_ROWS; i++ ) {
        for ( j = 0; j < TRACKSET_COLS ; j++ ) {
            if ( (VirtRowOffset + i) * TRACKSET_COLS + j >= PlayList->TotalTracks ) {
                WinSendMsg(hwndTrackSet, VM_SETITEM, MPFROM2SHORT(i+1, j+1), TrackUnknown);
                }
            else {
                WinSendMsg(hwndTrackSet, VM_SETITEM, MPFROM2SHORT(i+1, j+1),
                    itoa(PlayList->Track[(VirtRowOffset + i) * TRACKSET_COLS + j].ToPlay,
                        ConvBuf, 10));
                }
            }
        }

    return TRUE;
}

BOOL SetupTrackSet(CDAUDIO_PLAYLIST *PlayList)
{
    OldTrack = -1;
    OldVirtRow = -1;

    VirtRows = max((PlayList->TotalTracks + TRACKSET_COLS) / TRACKSET_COLS,
        TRACKSET_ROWS);
    VirtRowOffset = 0;

    WinSendMsg(hwndTrackSetScrollBar, SBM_SETTHUMBSIZE,
        MPFROM2SHORT(TRACKSET_ROWS, VirtRows), NULL);
    WinSendMsg(hwndTrackSetScrollBar, SBM_SETSCROLLBAR, MPFROMSHORT(0),
        MPFROM2SHORT(0, VirtRows - TRACKSET_ROWS));

    RedrawTrackSet(PlayList);

    return TRUE;
}

BOOL PosTrackSet(CDAUDIO_PLAYLIST *PlayList)
{
    /*
    if ( OldTrack != PlayList->CurrTrack ||
         OldVirtRow != VirtRowOffset ) {
        if ( PlayList->CurrTrack / TRACKSET_COLS < VirtRowOffset ||
             PlayList->CurrTrack / TRACKSET_COLS >= VirtRowOffset + TRACKSET_ROWS ) {
            VirtRowOffset = min(PlayList->CurrTrack / TRACKSET_COLS,
                VirtRows - TRACKSET_ROWS);
            RedrawTrackSet();
            WinSendMsg(hwndTrackSetScrollBar, SBM_SETPOS,
                MPFROMSHORT(VirtRowOffset), NULL);
            }

        OldTrack = PlayList->CurrTrack;
        OldVirtRow = VirtRowOffset;

        WinSendMsg(hwndTrackSet, VM_SELECTITEM,
            MPFROM2SHORT(PlayList->CurrTrack / TRACKSET_COLS - VirtRowOffset + 1,
                         (PlayList->CurrTrack % TRACKSET_COLS) + 1), NULL);
        }
    */

    return TRUE;
}

MRESULT TrackSetScroll(CDAUDIO_PLAYLIST *PlayList, MPARAM mp1, MPARAM mp2)
{
    switch ( SHORT2FROMMP(mp2) ) {
      case SB_LINEUP :
        if ( VirtRowOffset > 0) {
            VirtRowOffset--;
            WinSendMsg(hwndTrackSetScrollBar, SBM_SETPOS,
                MPFROMSHORT(VirtRowOffset), NULL);
            RedrawTrackSet(PlayList);
            }
        else if ( TrackSetCurrRow > 1 ) {
            WinSendMsg(hwndTrackSet, VM_SELECTITEM,
                MPFROM2SHORT(TrackSetCurrRow - 1, TrackSetCurrCol), NULL);
            }
        break;

      case SB_LINEDOWN :
        if ( VirtRowOffset + TRACKSET_ROWS < VirtRows) {
            VirtRowOffset++;
            WinSendMsg(hwndTrackSetScrollBar, SBM_SETPOS,
                MPFROMSHORT(VirtRowOffset), NULL);
            RedrawTrackSet(PlayList);
            }
        else if ( TrackSetCurrRow < TRACKSET_ROWS ) {
            WinSendMsg(hwndTrackSet, VM_SELECTITEM,
                MPFROM2SHORT(TrackSetCurrRow + 1, TrackSetCurrCol), NULL);
            }
        break;

      case SB_PAGEUP :
        if ( VirtRowOffset > 0) {
            VirtRowOffset -= min(VirtRowOffset, TRACKSET_ROWS);
            WinSendMsg(hwndTrackSetScrollBar, SBM_SETPOS,
                MPFROMSHORT(VirtRowOffset), NULL);
            RedrawTrackSet(PlayList);
            }
        else if ( TrackSetCurrRow > 1 ) {
            WinSendMsg(hwndTrackSet, VM_SELECTITEM,
                MPFROM2SHORT(1, TrackSetCurrCol), NULL);
            }
        break;

      case SB_PAGEDOWN :
        if ( VirtRowOffset + TRACKSET_ROWS < VirtRows) {
            VirtRowOffset += min(VirtRows - (VirtRowOffset + TRACKSET_ROWS),
                TRACKSET_ROWS);
            WinSendMsg(hwndTrackSetScrollBar, SBM_SETPOS,
                MPFROMSHORT(VirtRowOffset), NULL);
            RedrawTrackSet(PlayList);
            }
        else if ( TrackSetCurrRow < TRACKSET_ROWS ) {
            WinSendMsg(hwndTrackSet, VM_SELECTITEM,
                MPFROM2SHORT(TRACKSET_ROWS, TrackSetCurrCol), NULL);
            }
        break;

      case SB_SLIDERTRACK :
      case SB_SLIDERPOSITION :
        if ( VirtRowOffset != SHORT1FROMMP(mp2) ) {
            VirtRowOffset = SHORT1FROMMP(mp2);
            RedrawTrackSet(PlayList);
            }
        break;
        }

    return NULL;
}

MRESULT TrackSetControl(HWND hwndDlg, CDAUDIO_PLAYLIST *PlayList, MPARAM mp1, MPARAM mp2)
{
    ULONG NextTrack;
    MMTIME NextPosition;

    if ( SHORT2FROMMP(mp1) == VN_SELECT ) {
        TrackSetCurrRow = SHORT1FROMMP(mp2);
        TrackSetCurrCol = SHORT2FROMMP(mp2);
        }
    else if ( SHORT2FROMMP(mp1) == VN_ENTER ) {
        NextTrack = VirtRowOffset * TRACKSET_COLS +
            (SHORT1FROMMP(mp2)-1) * TRACKSET_COLS + (SHORT2FROMMP(mp2)-1);
        if ( NextTrack < PlayList->TotalTracks ) {
            NextPosition = PlayList->Track[NextTrack].StartInPlayList;
            WinSendMsg(hwndDlg, CD_SEEK,  MPFROMLONG(NextTrack), MPFROMLONG(NextPosition));
            }
        else {
            WinAlarm(HWND_DESKTOP, WA_ERROR);
            }
        }

    return NULL;
}

