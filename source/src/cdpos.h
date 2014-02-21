#if !(defined(_CDPOS_INCLUDED))
#define _CDPOS_INCLUDED

BOOL InitPosition(HWND hwndDlg);
BOOL EnablePosition(BOOL Enable);
BOOL PosPosition(CDAUDIO_POSITION *Position);

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

#endif // !(defined(_CDPOS_INCLUDED))
