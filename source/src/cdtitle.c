#include "cdglobal.h"
#include "cdplayer.h"
#include "cdprf.h"
#include "cdtitle.h"

static ULONG OldTrack = -1;
// static ULONG TitleDataLen = 0;

BOOL InitTitleSelect(HWND hwndDlg)
{
    hwndTextTitle = WinWindowFromID(hwndDlg, ID_TEXT_TITLE);
    hwndTitleSelect = WinWindowFromID(hwndDlg, ID_TITLE_SELECT);

    return TRUE;
}

BOOL EnableTitleSelect(BOOL Enable)
{
    if ( ! Enable ) {
        WinSetWindowText(hwndTitleSelect, "");
        }

    OldTrack = -1;

    WinSendMsg(hwndTitleSelect, CBM_SHOWLIST, MPFROMSHORT(FALSE), NULL);
    WinEnableWindow(hwndTitleSelect, Enable);
    return TRUE;
}

BOOL SetupTitleSelect(CDAUDIO_PLAYLIST *PlayList, PSZ TitleAccess)
{
    int i;
    PSZ TrackStr;
    static char Buffer[MAX_TITLE_LENGTH];

    if ( CDPrfQueryTrackTitle(TitleAccess, Buffer, sizeof(Buffer), PlayList->Track[0].ToPlay) )
        TrackStr = GetTrackStr(PlayList->Track[0].ToPlay, Buffer);
    else
        TrackStr = GetTrackStr(PlayList->Track[0].ToPlay, NULL);

    WinSendMsg(hwndTitleSelect, LM_DELETEALL, NULL, NULL);
    // TitleDataLen = 0;

    OldTrack = -1;
    WinSetWindowText(hwndTitleSelect, TrackStr);
    WinSendMsg(hwndTitleSelect, LM_INSERTITEM, MPFROMSHORT(0), TrackStr);
    // TitleDataLen += strlen(TrackStr);

    for ( i = 1; i < PlayList->TotalTracks; i++) {
        if ( CDPrfQueryTrackTitle(TitleAccess, Buffer, sizeof(Buffer), PlayList->Track[i].ToPlay) )
            TrackStr = GetTrackStr(PlayList->Track[i].ToPlay, Buffer);
        else
            TrackStr = GetTrackStr(PlayList->Track[i].ToPlay, NULL);

        WinSendMsg(hwndTitleSelect, LM_INSERTITEM, MPFROMSHORT(i), TrackStr);
        // TitleDataLen += strlen(TrackStr);
        }

    return TRUE;
}

BOOL PosTitleSelect(CDAUDIO_PLAYLIST *PlayList)
{
    if ( PlayList->CurrTrack != OldTrack ) {
        OldTrack = PlayList->CurrTrack;
        WinSendMsg(hwndTitleSelect, LM_SELECTITEM,
            MPFROMSHORT(PlayList->CurrTrack), MPFROMSHORT(TRUE));
//        WinSendMsg(hwndTitleSelect, EM_SETSEL, MPFROM2SHORT(0, 0), NULL);
        }

    return TRUE;
}

BOOL ChangeTitle(CDAUDIO_PLAYLIST *PlayList, ULONG Track, PSZ Title)
{
    ULONG i;
    PSZ TrackStr;
    // ULONG Style;
    // BOOL bResult;

    TrackStr = GetTrackStr(Track, Title);

    if ( PlayList->Track[PlayList->CurrTrack].ToPlay == Track )
        WinSetWindowText(hwndTitleSelect, TrackStr);

    // Style = WinQueryWindowULong(hwndTitleSelect, QWL_STYLE);
    // bResult = WinSetWindowULong(hwndTitleSelect, QWL_STYLE,
    //     Style & ~LS_HORZSCROLL);

    for ( i = 0; i < PlayList->TotalTracks; i++ ) {
        if ( PlayList->Track[i].ToPlay == Track ) {
            // TitleDataLen -= SHORT1FROMMR(WinSendMsg(hwndTitleSelect, LM_QUERYITEMTEXTLENGTH,
            //     MPFROMSHORT(i), NULL));
            WinSendMsg(hwndTitleSelect, LM_SETITEMTEXT, MPFROMSHORT(i), TrackStr);
            // TitleDataLen += strlen(TrackStr);
            }
        }

    // bResult = WinSetWindowULong(hwndTitleSelect, QWL_STYLE, Style);

    return TRUE;
}

MRESULT TitleSelectControl(HWND hwndDlg, CDAUDIO_PLAYLIST *PlayList, 
    MPARAM mp1, MPARAM mp2)
{
    ULONG NextTrack;
    MMTIME NextPosition;

    if ( SHORT2FROMMP(mp1) == CBN_ENTER ) {
        NextTrack = LONGFROMMR(WinSendMsg(hwndTitleSelect, LM_QUERYSELECTION,
            MPFROMSHORT(LIT_FIRST), NULL));

        NextPosition = PlayList->Track[NextTrack].StartInPlayList;
        // WinSendMsg(hwndTitleSelect, EM_SETSEL, MPFROM2SHORT(0, 0), NULL);
        WinSendMsg(hwndDlg, CD_SEEK,  MPFROMLONG(NextTrack), MPFROMLONG(NextPosition));
        }
//    else if ( SHORT2FROMMP(mp1) == EN_SETFOCUS ) {
//        WinSendMsg(hwndTitleSelect, EM_SETSEL, MPFROM2SHORT(0, 0), NULL);
//        }
    return NULL;
}
