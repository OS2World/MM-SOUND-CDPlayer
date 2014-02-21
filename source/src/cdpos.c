#include "cdglobal.h"
#include "cdpos.h"

static CDAUDIO_POSITION NullPos = {0, 0, 0, 0, 0};
static ULONG OldTrack = -1;

/*
_Inline PSZ GetTimeStr(MMTIME CDTime)
{
    static char Buffer[32];
    ULONG Val1, Val2, Val3;

    if ( TimeFormat == HHMMSS ) {
        CDTime += 1500;
        Val1 = CDTime / (3000 * 60 * 60);
        Val2 = (CDTime / (3000 * 60)) % 60;
        Val3 = (CDTime / 3000) % 60;
        sprintf(Buffer, "%2.2d%c%2.2d%c%2.2d",
            Val1,
            TimeSeparator,
            Val2,
            TimeSeparator,
            Val3);
        }
    else if ( TimeFormat == MMSSFF ) {
        CDTime += 20;
        Val1 = CDTime / (3000 * 60);
        Val2 = (CDTime / 3000) % 60;
        Val3 = CDTime / (3000 / 75) % 75;
        sprintf(Buffer, "%2.2d%c%2.2d%c%2.2d",
            Val1,
            TimeSeparator,
            Val2,
            TimeSeparator,
            Val3);
        }

    return Buffer;
}

_Inline PSZ GetUnknownTimeStr(void)
{
    static char Buf[32];

    sprintf(Buf, "%s%c%s%c%s",
       TimeUnknown,
       TimeSeparator,
       TimeUnknown,
       TimeSeparator,
       TimeUnknown);

    return Buf;
}
*/

BOOL InitPosition(HWND hwndDlg)
{
    hwndTextCD = WinWindowFromID(hwndDlg, ID_TEXT_CD);
    hwndCDTimePlayed = WinWindowFromID(hwndDlg, ID_CD_TIMEPLAYED);
    hwndCDTimeLeft = WinWindowFromID(hwndDlg, ID_CD_TIMELEFT);
    hwndTextTrack = WinWindowFromID(hwndDlg, ID_TEXT_TRACK);
    hwndTrackTimePlayed = WinWindowFromID(hwndDlg, ID_TRACK_TIMEPLAYED);
    hwndTrackTimeLeft = WinWindowFromID(hwndDlg, ID_TRACK_TIMELEFT);
    hwndTextCurrTrack = WinWindowFromID(hwndDlg, ID_TEXT_CURRTRACK);
    hwndCurrTrack = WinWindowFromID(hwndDlg, ID_CURRTRACK);

    return TRUE;
}

BOOL EnablePosition(BOOL Enable)
{
    if ( Enable ) {
        PosPosition(&NullPos);
        }
    else {
        WinSetWindowText(hwndCDTimePlayed, GetUnknownTimeStr());
        WinSetWindowText(hwndCDTimeLeft, GetUnknownTimeStr());
        WinSetWindowText(hwndTrackTimePlayed, GetUnknownTimeStr());
        WinSetWindowText(hwndTrackTimeLeft, GetUnknownTimeStr());
        WinSetWindowText(hwndCurrTrack, TrackUnknown);
        }

    OldTrack = -1;
    return TRUE;
}

BOOL PosPosition(CDAUDIO_POSITION *Position)
{
    char Buffer[8];

    WinSetWindowText(hwndCDTimePlayed, GetTimeStr(Position->CDPlayed));
    WinSetWindowText(hwndCDTimeLeft, GetTimeStr(Position->CDLeft));
    WinSetWindowText(hwndTrackTimePlayed, GetTimeStr(Position->TrackPlayed));
    WinSetWindowText(hwndTrackTimeLeft, GetTimeStr(Position->TrackLeft));

    if ( Position->CurrTrack != OldTrack ) {
        OldTrack = Position->CurrTrack;
        WinSetWindowText(hwndCurrTrack, itoa(Position->CurrTrack, Buffer, 10));
        }

    return TRUE;
}

