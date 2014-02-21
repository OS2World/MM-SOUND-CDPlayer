#if !(defined(_CDLIB_INCLUDED))
#define _CDLIB_INCLUDED

#define CDREC_CONTENTS      0U
#define CDREC_PLAYLIST      1U
#define CDREC_POSITION      2U
#define CDREC_TITLE         3U
#define CDREC_INFO          4U

typedef struct {
    ULONG Type;
    ULONG Size;
    union {
        struct {
            BYTE IDAvailable;
            BYTE UPCAvailable;
            USHORT UPCLength;
            ULONG uID[2];
            CHAR UPC[32];
            MMTIME TotalLength;
            MMTIME StartPosition;
            ULONG TotalTracks;
            struct {
                BYTE IsAudioTrack;
                BYTE CopyPermitted;
                BYTE Preemphasis;
                BYTE Channels;
                MMTIME Length;
                MMTIME Start;
                } Track[MAX_TRACKS];
            } Contents;
        struct {
            ULONG TotalTracks;
            BYTE TrackToPlay[MAX_PLAYLIST];
            } Playlist;
        struct {
            ULONG Track;
            MMTIME Position;
            } Position;
        struct {
            BYTE Track;
            char CH[1];
            } Text;
        };
    } CDLIB_RECORD;

typedef struct _CDLIB_ENTRY {
    struct _CDLIB_ENTRY Next;
    CDLIB_RECORD *Rec;
    } CDLIB_ENTRY;

int CDLReset(FILE *fp);
int CDLInit(FILE *fp);
CDLIB_RECORD *CDLReadRecord(FILE *fp);
int CDLWriteRecord(FILE *fp, CDLIB_RECORD *Rec);
CDLIB_ENTRY *CDLReadEntry(FILE *fp);
int CDLWriteEntry(FILE *fp, CDLIB_ENTRY *Entry);

CDLIB_RECORD *CDRecFromContents(CDAUDIO_CONTENTS *Contents);
CDLIB_RECORD *CDRecFromPlaylist(CDAUDIO_PLAYLIST *Playlist);
CDLIB_RECORD *CDRecPosition(ULONG Track, MMTIME Position);
#define CDRecCDTitle(Title)     CDRecTrackTitle(0, (Title))
#define CDRecCDInfo(Info)       CDRecTrackInfo(0, (Info))
CDLIB_RECORD *CDRecTrackTitle(ULONG Track, char *Title);
CDLIB_RECORD *CDRecTrackInfo(ULONG Track, char *Info);

CDAUDIO_CONTENTS *ContentsFromCDRec(CDLIB_RECORD *Rec);
CDAUDIO_PLAYLIST *PlaylistFromCDRec(CDLIB_RECORD *Rec, CDAUDIO_CONTENTS *Contents);

#endif // !(defined(_CDLIB_INCLUDED))
