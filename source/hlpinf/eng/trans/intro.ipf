.********************************************************************
:h1 res=10000 name=PANEL_INTRODUCTION.Introduction
:i1.Introduction
:color fc=black.
:font facename='Tms Rmn' size=28x18.
:artwork align=center name='CDICON.BMP'.
:p.:lines align=center.:hp2.The CD Player:ehp2.:elines.
:font facename='Tms Rmn' size=18x14.
:p.:lines align=center.:hp2.Version &VERSION.:ehp2.:elines.
:p.:lines align=center.:hp2.Copyright Michael Bock 1993-94:ehp2.:elines.
:font facename=default size=0x0.
:color fc=default.
.br
.br
:p.:lines align=center.:hp7.Fundamentals:ehp7.:elines.
:p.
The behaviour of the CD Player is very simple. At start, it is tested whether
a cd is inserted in your cdrom drive and whether this cd contains audio tracks.
In this case, all controls and features of the CD Player are directly accessible.
If the inserted cd doesn't contain audio tracks, your only chance is ejecting
the cd (if you don't need it otherwise).
.br
All time the CD Player is active, it will check the cdrom drive. As soon as
a cd is ejected or inserted, the CD Player's display will change to reflect
the new circumstances.

:p.:lines align=center.:hp7.Extensions:ehp7.:elines.
:p.Beyond simple playback of a cd, the CD Player is able to handle titles of
cds and tracks including additional notices, and to use a free programmable
sequence of the desired titles to play. Titles and program are saved and 
restored automatically, if you insert the same cd again. All information will
be retained, even if you quit the CD Player program, see
":link reftype=hd res=12000.title editor:elink." and
":link reftype=hd res=13000.program editor:elink.".
Additionally, display and behaviour of the CD Player can be changed in the
:link reftype=hd res=15000.settings:elink. in various ways.
:p.:lines align=center.:hp7.Requirements:ehp7.:elines.
:ul.
:li.A PC with OS/2 2.1 installed, including the multimedia extensions. The CD
Player should work with OS/2 2.0 and multimedia extensions too, but this environment
is not testet.
:li.An audio-capable cdrom drive, which is supported by the multimedia extensions.
:eul.:lm margin=1.
:p.:lines align=center.:hp7.Restrictions:ehp7.:elines.
:ul.
:lm margin=0.:li.
In the actual version, it's not possible to use the CD Player along with other 
programs using the audio capabilities of the cdrom drive. For the same reason,
the CD Player cannot be started more than once the same time.
:li.
In the actual version, it's not possible to change a cd's program during playback.
Saving a new program will stop playback.
:li.
Ending the CD Player will end playback. This is a restriction caused by the
multimedia extensions of OS/2.
:eul.:lm margin=1.
:p.:lines align=center.:hp7.History:ehp7.:elines.
:p.Originally the intention to develop the CD Player was the necessity to try out
the new facilities of the multimedia presentation manager. But the project tended
to grow and grow, and soon it became a serious software project. There has been
much work to build this version, so I decided to distribute it as shareware, see
:link reftype=hd res=18000.Copyright:elink..
.********************************************************************
