#if !(defined(_CDTITLE_INCLUDED))
#define _CDTITLE_INCLUDED

BOOL InitTitleSelect(HWND hwndDlg);
BOOL EnableTitleSelect(BOOL Enable);
BOOL SetupTitleSelect(CDAUDIO_PLAYLIST *PlayList, PSZ TitleAccess);
BOOL PosTitleSelect(CDAUDIO_PLAYLIST *PlayList);
BOOL ChangeTitle(CDAUDIO_PLAYLIST *PlayList, ULONG Track, PSZ Title);
MRESULT TitleSelectControl(HWND hwndDlg, CDAUDIO_PLAYLIST *PlayList,
    MPARAM mp1, MPARAM mp2);

_Inline PSZ GetTrackStr(ULONG Track, PSZ Title)
{
    static char Buffer[MAX_TITLE_LENGTH+10];

    sprintf(Buffer, "[ %d ]", Track);
    if ( Title != NULL ) {
        strcat(Buffer, " - ");
        strcat(Buffer, Title);
        }

    return Buffer;
}

_Inline PSZ GetTrackStrNoAudio(ULONG Track, PSZ Title)
{
    static char Buffer[MAX_TITLE_LENGTH+10];

    sprintf(Buffer, "( %d )", Track);
    if ( Title != NULL ) {
        strcat(Buffer, " - ");
        strcat(Buffer, Title);
        }

    return Buffer;
}

#endif // !(defined(_CDTITLE_INCLUDED))
