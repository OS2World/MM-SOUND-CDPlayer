#include "cdglobal.h"
#include "cdprf.h"
#include "cdlib.h"

#define CDL_HEADERLENGTH    4

static const char CDLHeader[] = "CDL ";

static const char CDLHeaderText[] = 
    "Diese Datei enth„lt eine bin„re CD Bibliothek";

int CDLReset(FILE *fp)
{
    char Header[CDL_HEADERLENGTH];
    ULONG Version;
    int IgnCH;

    rewind(fp);

    if ( 0 != ftell(fp) )
        return FALSE;

    if ( CDL_HEADERLENGTH != fread(Header, 1, CDL_HEADERLENGTH, fp) )
        return FALSE;

    if ( 0 != memcmp(Header, CDLHeader, CDL_HEADERLENGTH) )
        return FALSE;

    do {
        IgnCH = getc(fp);
        } while ( IgnCH != EOF && IgnCH != 0x1A );

    if ( IgnCH == EOF )
        return FALSE;

    if ( 1 != fread(&Version, sizeof(ULONG), 1, fp) )
        return FALSE;

    if ( Version != 1 )
        return FALSE;

    return TRUE;
}
 
int CDLInit(FILE *fp)
{
    rewind(fp);

    if ( 0 != ftell(fp) )
        return FALSE;

    if ( CDL_HEADERLENGTH != fread(Header, 1, CDL_HEADERLENGTH, fp) )
        return FALSE;

 
}

/*
CDLIB_RECORD *CDLReadRecord(FILE *fp);
int CDLWriteRecord(FILE *fp, CDLIB_RECORD *Rec);
CDLIB_ENTRY *CDLReadEntry(FILE *fp);
int CDLWriteEntry(FILE *fp, CDLIB_ENTRY *Entry);
*/

CDLIB_RECORD *CDRecFromContents(CDAUDIO_CONTENTS *Contents)
{
    ULONG Size, i;
    CDLIB_RECORD *Rec;

    if ( Contents == NULL )
        return NULL;

    Size = 2 * sizeof(ULONG) + sizeof(Rec->Contents) -
        (MAX_TRACKS - Contents->TotalTracks) * sizeof(Rec->Contents.Track[0]);

    Rec = (CDLIB_RECORD *)malloc(Size);

    if ( Rec == NULL )
        return NULL;

    Rec->Type = CDREC_CONTENTS;
    Rec->Size = Size;
    Rec->Contents.IDAvailable = (BYTE)(Contents->IDAvailable != 0);
    Rec->Contents.UPCAvailable = (BYTE)(Contents->UPCAvailable != 0);
    Rec->Contents.UPCLength = (USHORT)Contents->UPCLength;
    Rec->Contents.uID[0] = Contents->uID[0];
    Rec->Contents.uID[1] = Contents->uID[1];
    memcpy(Rec->Contents.UPC, Contents->UPC, sizeof(Rec->Contents.UPC);
    Rec->Contents.TotalLength = Contents->TotalLength;
    Rec->Contents.StartPosition = Contents->StartPosition;
    Rec->Contents.TotalTracks = Contents->TotalTracks;
    for ( i = 0; i < Rec->Contents.TotalTracks; i++) {
        Rec->Contents.Track[i].IsAudioTrack = (BYTE)(Contents->Track[i].IsAudioTrack != 0);
        Rec->Contents.Track[i].CopyPermitted = (BYTE)(Contents->Track[i].CopyPermitted != 0);
        Rec->Contents.Track[i].Preemphasis = (BYTE)(Contents->Track[i].Preemphasis != 0);
        Rec->Contents.Track[i].Channels = (BYTE)Contents->Track[i].Channels;
        Rec->Contents.Track[i].Length = Contents->Track[i].Length;
        Rec->Contents.Track[i].Start = Contents->Track[i].Start;
        }

    return Rec;
}

CDLIB_RECORD *CDRecFromPlaylist(CDAUDIO_PLAYLIST *Playlist)
{
    ULONG Size, i;
    CDLIB_RECORD *Rec;

    if ( Playlist == NULL )
        return NULL;

    Size = 3 * sizeof(ULONG) + sizeof(BYTE) * Playlist->TotalTracks;

    Rec = (CDLIB_RECORD *)malloc(Size);

    if ( Rec == NULL )
        return NULL;

    Rec->Type = CDREC_PLAYLIST;
    Rec->Size = Size;

    Rec->Playlist.TotalTracks = Playlist->TotalTracks;
    for ( i = 0; i < Rec->Playlist.TotalTracks; i++) {
        Rec->Playlist.TrackToPlay[i] = (BYTE)Playlist.Track[i].ToPlay;
        }

    return Rec;
}

CDLIB_RECORD *CDRecPosition(ULONG Track, MMTIME Position)
{
    ULONG Size;
    CDLIB_RECORD *Rec;

    Size = 4 * sizeof(ULONG);

    Rec = (CDLIB_RECORD *)malloc(Size);

    if ( Rec == NULL )
        return NULL;

    Rec->Type = CDREC_POSITION;
    Rec->Size = Size;
    Rec->Position.Track = Track;
    Rec->Position.Position = Position;

    return Rec;

}

CDLIB_RECORD *CDRecTrackTitle(ULONG Track, char *Title)
{
    ULONG Size;
    CDLIB_RECORD *Rec;

    if ( Title == NULL )
        return NULL;

    Size = 2 * sizeof(ULONG) + sizeof(BYTE) + strlen(Title) + 1;

    Rec = (CDLIB_RECORD *)malloc(Size);

    if ( Rec == NULL )
        return NULL;

    Rec->Type = CDREC_TITLE;
    Rec->Size = Size;
    Rec->Text.Track = (BYTE)Track;
    strcpy(Rec->Text.CH, Title);

    return Rec;
}

CDLIB_RECORD *CDRecTrackInfo(ULONG Track, char *Info)
{
    ULONG Size;
    CDLIB_RECORD *Rec;

    if ( Info == NULL )
        return NULL;

    Size = 2 * sizeof(ULONG) + sizeof(BYTE) + strlen(Info) + 1;

    Rec = (CDLIB_RECORD *)malloc(Size);

    if ( Rec == NULL )
        return NULL;

    Rec->Type = CDREC_INFO;
    Rec->Size = Size;
    Rec->Text.Track = (BYTE)Track;
    strcpy(Rec->Text.CH, Info);

    return Rec;
}

