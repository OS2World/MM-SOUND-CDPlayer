.********************************************************************
:userdoc.
:title.CD Player documentation
.********************************************************************
.********************************************************************
.********************************************************************
.********************************************************************
.********************************************************************
.********************************************************************
:h1 res=10000 name=PANEL_INTRODUCTION.Introduction
:i1.Introduction
:color fc=black.
:font facename='Tms Rmn' size=28x18.
:artwork align=center name='D:\C\CDPLAYER\HLPINF\CDICON.BMP'.
:p.:lines align=center.:hp2.The CD Player:ehp2.:elines.
:font facename='Tms Rmn' size=18x14.
:p.:lines align=center.:hp2.Version 1.04:ehp2.:elines.
:p.:lines align=center.:hp2.Copyright Michael Bock 1993-94:ehp2.:elines.
:font facename=default size=0x0.
:color fc=default.
.br
.br
:p.:lines align=center.:hp7.Fundamentals:ehp7.:elines.
:p.
The behaviour of the CD Player is very simple. At start, it is tested whether
a CD is inserted in your CDROM drive and whether this CD contains audio tracks.
In this case, all controls and features of the CD Player are directly accessible.
If the inserted CD doesn't contain audio tracks, your only chance is ejecting
the CD (if you don't need it otherwise).
.br
All time the CD Player is active, it will check the CDROM drive. As soon as
a CD is ejected or inserted, the CD Player's display will change to reflect 
the new circumstances.

:p.:lines align=center.:hp7.Extensions:ehp7.:elines.
:p.Beyond simple playback of a CD, the CD Player is able to handle titles of
CDs and tracks including additional notices, and to use a freely programmable
sequence of the desired titles to play. Titles and programm are saved and 
restored automatically, if you insert the same CD again. All information will
be retained, even if you quit the CD Player program, see
":link reftype=hd res=12000.title editor:elink." and
":link reftype=hd res=13000.program editor:elink.".
Additionally, display and behaviour of the CD Player can be changed in the
:link reftype=hd res=15000.settings:elink. in various ways.
:p.:lines align=center.:hp7.Requirements:ehp7.:elines.
:ul.
:li.A PC with OS/2 2.1 installed, included the multimedia extensions. The CD
Player should work with OS/2 2.0 and multimedia extensions too, but this case 
wasn't testet.
:li.An audio-capable CDROM drive, which is supported by the multimedia extensions.
:eul.:lm margin=1.
:p.:lines align=center.:hp7.Restrictions:ehp7.:elines.
:ul.
:li.
In the actual version, it's not possible to use the CD Player along with other 
programs using the audio capabilities of the CDROM drive. For the same reason,
the CD Player cannot be started more than once the same time.
:li.
In the actual version, it's not possible to change a CD's program during playback.
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
.********************************************************************
.********************************************************************
:h1 res=11000 name=PANEL_MAINWINDOW.Main window
:i2 REFID=INDEX_WINDOWS.Main window
:i2 REFID=INDEX_MAINWINDOW.Overview
:p.:lines align=center.:hp7.The main window of the CD Player:ehp7.:elines.
:p.The main window contains a lot of
:link reftype=hd res=11100.displays:elink.
informing you about the state of the CD Player, the inserted CD and the
selected program.
.br
Additionally, it contains all
:link reftype=hd res=11200.controls:elink.,
of the CD Player and buttons to start the
:link reftype=hd res=12000.title editor:elink., the
:link reftype=hd res=13000.program editor:elink., the
:link reftype=hd res=15000.settings:elink. and the
:link reftype=hd res=14000.info window:elink..
:p.Most commands can also be given by using the
:link reftype=hd res=11300.keyboard:elink.- and per
:link reftype=hd res=11400.menu:elink..

.********************************************************************
:h2 res=11100 name=PANEL_MW_DISPLAY.Displays
:i2 REFID=INDEX_MAINWINDOW.Displays
:i2 REFID=INDEX_DISPLAY.in the main window
:p.:lines align=center.:hp7.Displays in the main window:ehp7.:elines.
:ul.
:li.:link reftype=hd res=11110.Time display:elink.
:li.:link reftype=hd res=11120.Program display:elink.
:li.:link reftype=hd res=11130.Volume display:elink.
:li.:link reftype=hd res=11150.Titles display:elink.
:li.:link reftype=hd res=11140.Position display:elink.
:li.:link reftype=hd res=11160.Playback display:elink.
:eul.:lm margin=1.

.********************************************************************
:h3 res=11110 name=PANEL_MW_DISP_TIME.Time display
:i2 REFID=INDEX_TRACKS.display in the main window
:i2 REFID=INDEX_TIME.display in the main window
:p.:lines align=center.:hp7.The time display:ehp7.:elines.
:artwork align=center name='D:\C\CDPLAYER\HLPINF\ENG\DSPTIME.BMP'.
:p.There are five displays in this area&colon.
:ul.
:li.:hp2.The length of the program up to the current position at the top in
:color fc=black.black:color fc=default.:ehp2.
:li.:hp2.The length of the program beyond the current position at the top in
:color fc=red.red:color fc=default.:ehp2.
:li.:hp2.The length of the current track up to the curren position in the middle in
:color fc=black.red:color fc=default.:ehp2.
:li.:hp2.The length of the current track beyond the current position in the middle in
:color fc=red.red:color fc=default.:ehp2.
:li.:hp2.The number of the current track on the CD at bottom in
:color fc=black.black:color fc=default.:ehp2.
:eul.:lm margin=1.
:p.During playback, the time displays are actualised with the
:link reftype=hd res=15140.actualisation rate:elink. you choosed in the
:link reftype=hd res=15000.settings:elink. under the topic
:link reftype=hd res=15100.time format:elink.,
.br
There you can also change the
:link reftype=hd res=15130.separator:elink. for the time display and choose
one of the two display formats&colon.
:link reftype=hd res=15110.Hours/Minutes/Seconds:elink. or
:link reftype=hd res=15120.Minutes/Seconds/Frames:elink..


.********************************************************************
:h3 res=11120 name=PANEL_MW_DISP_PROGRAM.Program display
:i2 REFID=INDEX_PROGRAM.display in the main window
:p.:lines align=center.:hp7.The programm display:ehp7.:elines.
:artwork align=center name='D:\C\CDPLAYER\HLPINF\ENG\DSPPROG.BMP'.
:p.In the program display the track numbers of the selected program are shown.
If not all tracks fit in the display, you can scroll it with scroll bar
right beyond the display. The selected track :hp2.doesn't:ehp2. correspond 
to the current track. Instead you can use it to select another track in the
program, see
":link reftype=hd res=11210.title selection in the program display:elink.".
.br
The program can changed with the program editor, see
":link reftype=hd res=11231.starting the program editor:elink." and
":link reftype=hd res=13000.program editor:elink.".

.********************************************************************
:h3 res=11130 name=PANEL_MW_DISP_VOLUME.Volume display
:i2 REFID=INDEX_VOLUME.display in the main window
:p.:lines align=center.:hp7.The volume display:ehp7.:elines.
:artwork align=center name='D:\C\CDPLAYER\HLPINF\ENG\DSPVOL.BMP'.
:p.The two sliders in the volume display show the current volume of the
two channels. If the slider is at the top of the display, the volume is
maximal. If the slider is at the bottom of the display, the volume is
minimal. You can change the volume with the sliders, see
":link reftype=hd res=11220.changing left volume:elink." and
":link reftype=hd res=11221.changing right volume:elink.".
:p.The symbol on the button at theright bottom of the display shows,
whether the sound is currenty muted. In the picture above, sound is not
muted. If you mute sound, the symbol changes to&colon.
:artwork runin name='D:\C\CDPLAYER\HLPINF\BTNMUTE1.BMP'., see also
":link reftype=hd res=11224.sound off/on:elink.".

.********************************************************************
:h3 res=11150 name=PANEL_MW_DISP_TITLE.Titles display
:i2 REFID=INDEX_TITLE.display in the main window
:p.:lines align=center.:hp7.The titles display:ehp7.:elines.
:p.Right beyond the text "Title&colon." the title of the current track
and it's number on the CD are displayed. This number doesn't correspond to
the position of the track in the program, but helps you identifying the
track, if it has no title yet.
.br
All titles are displayed, if you click on the arrow right beyond the current
title.
.br
You can also choose a new title for playback here, see
":link reftype=hd res=11240.select track by title:elink.".

:p.Der Titel der eingelegten CD wird in der Titelleiste des Main windows
nach dem Text "CD Spieler" angezeigt. Dieser Text wird auch in der globalen
Fensterliste von OS/2 verwendet. Wenn die CD keinen Titel hat
oder keine Audio CD eingelegt, erscheint in der Titelleiste&colon.
:dl break=all tsize=5.
:dt.:hp2.CD Spieler - kein CD-ROM Laufwerk:ehp2.
:dd.Ihr Computer verf�gt �ber kein audiof�higes CD-ROM Laufwerk.
:dt.:hp2.CD Spieler - keine CD:ehp2.
:dd.Es ist keine CD eingelegt.
:dt.:hp2.CD Spieler - keine Audio CD:ehp2.
:dd.Die eingelegte CD enth�lt keine Audiospuren.
:dt.:hp2.CD Spieler - ohne Namen:ehp2.
:dd.Die eingelegte Audio CD hat keinen Namen.
:edl.

:note.
Wenn Sie den CD Spieler �ber ein Programmobjekt gestartet haben, erscheint
der Name des Programmobjekts vor dem Text "CD Spieler - ..." in der globalen
Fensterliste.

.********************************************************************
:h3 res=11140 name=PANEL_MW_DISP_POSITION.Positionsanzeige
:i2 REFID=INDEX_POSITION.display in the main window
:lines align=center.:hp7.Die Positionsanzeige:ehp7.:elines.
:artwork align=center name='D:\C\CDPLAYER\HLPINF\ENG\DSPSLIDE.BMP'.
:p.Die kleinen Markierungen oberhalb der Positionsanzeige stellen die
Startposition der einzelnen Titel im Programm dar. �ber den Markierungen
wird die Spurnummer des jeweiligen Titels angezeigt. Der Schieber steht
immer an der momentanen Position. Es ist auch m�glich mit dem Schieber
die Position direkt zu ver�ndern, siehe
":link reftype=hd res=11250.Position einstellen:elink.".

.********************************************************************
:h3 res=11160 name=PANEL_MW_DISP_CONTROLS.Wiedergabeanzeige
:i2 REFID=INDEX_CDCONTROL.display in the main window
:p.:lines align=center.:hp7.Die Wiedergabeanzeige:ehp7.:elines.
:p.Der Status des CD Spielers l��t sich an den beiden Kn�pfen
:artwork runin name='D:\C\CDPLAYER\HLPINF\BTNPLAY.BMP'. und
:artwork runin name='D:\C\CDPLAYER\HLPINF\BTNPAUSE.BMP'. ablesen.
:ul.
:li.Sind beide Kn�pfe nicht gedr�ckt (wie hier dargestellt), so
ist die Wiedergabe abgebrochen.
:li.Wenn nur der
:artwork runin name='D:\C\CDPLAYER\HLPINF\BTNPLAY.BMP'. Knopf
gedr�ckt ist, l�uft die Wiedergabe. Wenn die
:link reftype=hd res=15200.Animation:elink. angestellt ist,
wandert der Pfeil auf dem Knopf von links nach rechts.
Geschwindigkeit und Status der
:link reftype=hd res=15200.Animation:elink. lassen sich in den
:link reftype=hd res=15000.Einstellungen:elink. unter
:link reftype=hd res=15200.Animation:elink. mit
:link reftype=hd res=15210.Wiedergabeanimation:elink. und
:link reftype=hd res=15220.Animationsrate:elink. �ndern.
:li.Wenn zus�tzlich noch der
:artwork runin name='D:\C\CDPLAYER\HLPINF\BTNPAUSE.BMP'. Knopf
gedr�ckt ist, ist die Wiedergabe unterbrochen.
Auch die
:link reftype=hd res=15200.Animation:elink.
ist dann unterbrochen.
:eul.:lm margin=1.
:p.Beide Kn�pfe lassen sich auch dazu verwenden, die Wiedergabe zu
starten oder zu unterbrechen, siehe
":link reftype=hd res=11262.Wiedergabe starten:elink." und
":link reftype=hd res=11263.Wiedergabe unterbrechen:elink.".


.********************************************************************
:h2 res=11200 name=PANEL_MW_CONTROL.Steuerung
:i2 REFID=INDEX_MAINWINDOW.Steuerung
:i2 REFID=INDEX_CONTROL.im Main window
:p.:lines align=center.:hp7.Kontrollelemente im Main window:ehp7.:elines.
:ul.
:li.:link reftype=hd res=11210.Titelauswahl in der Programmanzeige:elink.
:li.:link reftype=hd res=11220.Lautst�rke links einstellen:elink.
:li.:link reftype=hd res=11221.Lautst�rke rechts einstellen:elink.
:li.:link reftype=hd res=11222.Kan�le unabh�ngig einstellen:elink.
:li.:link reftype=hd res=11223.Kan�le vertauschen:elink.
:li.:link reftype=hd res=11224.Ton aus/an:elink.
:li.:link reftype=hd res=11230.Titeleditor starten:elink.
:li.:link reftype=hd res=11231.Programmeditor starten:elink.
:li.:link reftype=hd res=11232.Einstellungen aufrufen:elink.
:li.:link reftype=hd res=11233.Infofenster anzeigen:elink.
:li.:link reftype=hd res=11240.Titelauswahl nach Titel:elink.
:li.:link reftype=hd res=11250.Position einstellen:elink.
:li.:link reftype=hd res=11260.Titel zur�ck:elink.
:li.:link reftype=hd res=11261.Titel vorw�rts:elink.
:li.:link reftype=hd res=11262.Wiedergabe starten:elink.
:li.:link reftype=hd res=11263.Wiedergabe unterbrechen:elink.
:li.:link reftype=hd res=11264.Wiedergabe stoppen:elink.
:li.:link reftype=hd res=11265.CD auswerfen:elink.
:li.:link reftype=hd res=11266.Automatische Wiederholung einstellen:elink.
:eul.:lm margin=1.

.********************************************************************
:h3 res=11210 name=PANEL_MW_CTRL_PROGRAM.Titelauswahl in der Programmanzeige
:i2 REFID=INDEX_TITLE.aus dem Programm w�hlen
:i2 REFID=INDEX_PROGRAM.Titel ausw�hlen (im Main window)
:p.:lines align=center.:hp7.Titelauswahl in der Programmanzeige:ehp7.:elines.
:artwork align=center name='D:\C\CDPLAYER\HLPINF\ENG\DSPPROG.BMP'.
:p.Wenn Sie einen Titel in der Programmanzeige ausw�hlen, wird der CD Spieler an
die Startposition dieses Titels gesetzt.
Die Auswahl kann durch Doppelklick der linken Maustaste auf einen
Titel oder Dr�cken der Eingabetaste wenn ein Titel angew�hlt ist stattfinden.
.br
Befindet sich der CD Spieler im Wiedergabemodus, wird die Wiedergabe der CD
an der neuen Position unmittelbar fortgesetzt.
.br
Siehe auch ":link reftype=hd res=11120.Programmanzeige:elink.".

.********************************************************************
:h3 res=11220 name=PANEL_MW_CTRL_VOL_LEFT.Lautst�rke links einstellen
:i2 REFID=INDEX_VOLUME.links einstellen
:i2 REFID=INDEX_CHANNELS.Linken Kanal einstellen
:i2 REFID=INDEX_SOUND.links einstellen
:p.:lines align=center.:hp7.Lautst�rke links einstellen:ehp7.:elines.
:artwork align=center name='D:\C\CDPLAYER\HLPINF\BTNVOL.BMP'.
:p.Mit diesem Schieber kann die Lautst�rke des linken Kanals ge�ndert
werden. An der oberen Position des Schiebers hat der linke Kanal die
maximale Lautst�rke.
.br
Wenn die Option
:link reftype=hd res=11222.Kan�le unabh�ngig einstellen:elink.
nicht eingestellt ist, wird die Lautst�rke des rechten Kanals automatisch
auf das gleiche Niveau eingestellt.
.br
Ist in den
:link reftype=hd res=15000.Einstellungen:elink. die
:link reftype=hd res=15400.Speicherung:elink. der
:link reftype=hd res=15420.Lautst�rke:elink. angestellt, so
wird die Lautst�rke gespeichert und bei einem neuen Start
des CD Spielers auf das zuletzt eingestelle Niveau gesetzt.
.br
Siehe auch ":link reftype=hd res=11130.Lautst�rkeanzeige:elink.".

:note.
Es kann sein, da� Ihr CD-ROM Laufwerk die Ver�nderung der Lautst�rke
nicht unterst�tzt. In diesem Fall ist der Schalter deaktiviert.
.br
Eventuell kann die Lautst�rke aber �ber den globalen Lautst�rkeregler
der Multimediaerweiterung von OS/2 oder �ber externe Lautst�rkeregler
an der Soundkarte und am CD-ROM Laufwerk eingestellt werden.

.********************************************************************
:h3 res=11221 name=PANEL_MW_CTRL_VOL_RIGHT.Lautst�rke rechts einstellen
:i2 REFID=INDEX_VOLUME.rechts einstellen
:i2 REFID=INDEX_CHANNELS.Rechten Kanal einstellen
:i2 REFID=INDEX_SOUND.rechts einstellen
:p.:lines align=center.:hp7.Lautst�rke rechts einstellen:ehp7.:elines.
:artwork align=center name='D:\C\CDPLAYER\HLPINF\BTNVOL.BMP'.
:p.Mit diesem Schieber kann die Lautst�rke des rechten Kanals ge�ndert
werden. An der oberen Position des Schiebers hat der rechte Kanal die
maximale Lautst�rke.
.br
Wenn die Option
:link reftype=hd res=11222.Kan�le unabh�ngig einstellen:elink.
nicht eingestellt ist, wird die Lautst�rke des linken Kanals automatisch
auf das gleiche Niveau eingestellt.
.br
Ist in den
:link reftype=hd res=15000.Einstellungen:elink. die
:link reftype=hd res=15400.Speicherung:elink. der
:link reftype=hd res=15420.Lautst�rke:elink. angestellt, so
wird die Lautst�rke gespeichert und bei einem neuen Start
des CD Spielers auf das zuletzt eingestelle Niveau gesetzt.
.br
Siehe auch ":link reftype=hd res=11130.Lautst�rkeanzeige:elink.".

:note.
Es kann sein, da� Ihr CD-ROM Laufwerk die Ver�nderung der Lautst�rke
nicht unterst�tzt. In diesem Fall ist der Schalter deaktiviert.
.br
Eventuell kann die Lautst�rke aber �ber den globalen Lautst�rkeregler
der Multimediaerweiterung von OS/2 oder �ber externe Lautst�rkeregler
an der Soundkarte und am CD-ROM Laufwerk eingestellt werden.

.********************************************************************
:h3 res=11222 name=PANEL_MW_CTRL_VOL_IND.Kan�le unabh�ngig einstellen
:i2 REFID=INDEX_VOLUME.Kan�le unabh�ngig einstellen
:i2 REFID=INDEX_CHANNELS.unabh�ngig einstellen
:p.:lines align=center.:hp7.Option&colon. Kan�le unabh�ngig einstellen:ehp7.:elines.
:p.Mit dem Schalter :hp2.Getrennt:ehp2. kann die Koppelung der Lautst�rke
der beiden Kan�le aufgehoben werden. Ist der Schalter an, kann die Lautst�rke
beider Kan�le getrennt eingestellt werden, siehe auch
":link reftype=hd res=11220.Lautst�rke links einstellen:elink." und
":link reftype=hd res=11221.Lautst�rke rechts einstellen:elink.".
.br
Auch wenn in den
:link reftype=hd res=15000.Einstellungen:elink. die
:link reftype=hd res=15400.Speicherung:elink. der
:link reftype=hd res=15420.Lautst�rke:elink. angestellt ist, wird
dieser Schalter nicht gespeichert. Die Stellung des Schalters beim
Start des CD Spielers ergibt sich aus der gespeicherten Lautst�rke
der beiden Kan�le. Ist f�r beide Kan�le dieselbe Lautst�rke gespeichert
so der Schalter aus, anderenfalls an.
:p.Diese Option kann auf folgende Arten ge�ndert werden&colon.
:ul.
:li.Mit den Schalter :hp2.Getrennt:ehp2.
:eul.:lm margin=1.
:note.
Es kann sein, da� Ihr CD-ROM Laufwerk diese Option nicht unterst�tzt. In diesem Fall
ist der Schalter deaktiviert.


.********************************************************************
:h3 res=11223 name=PANEL_MW_CTRL_VOL_SWAP.Kan�le vertauschen
:i2 REFID=INDEX_VOLUME.Kan�le vertauschen
:i2 REFID=INDEX_CHANNELS.vertauschen
:p.:lines align=center.:hp7.Option&colon. Kan�le vertauschen:ehp7.:elines.
:p.Mit dem Schalter :hp2.Tauschen:ehp2. k�nnen der linke und der rechte
Kanal bei der Ausgabe vertauscht werden.
:p.Diese Option kann auf folgende Arten ge�ndert werden&colon.
:ul.
:li.Mit den Schalter :hp2.Tauschen:ehp2.
:eul.:lm margin=1.
:note.
Es kann sein, da� Ihr CD-ROM Laufwerk diese Option nicht unterst�tzt. In diesem Fall
ist der Schalter deaktiviert.

.********************************************************************
:h3 res=11224 name=PANEL_MW_CTRL_VOL_MUTE.Ton aus/an
:i2 REFID=INDEX_VOLUME.Ton aus/an
:i2 REFID=INDEX_SOUND.ausstellen
:i2 REFID=INDEX_SOUND.anstellen
:p.:lines align=center.:hp7.Option&colon. Ton aus/an:ehp7.:elines.
:p.Mit diesem Schalter k�nnen Sie den Ton kurzfristig aus- und wieder
anstellen, ohne die eingestellte Lautst�rke zu ver�ndern.
.br
Siehe auch ":link reftype=hd res=11130.Lautst�rkeanzeige:elink.".
:p.Diese Option kann auf folgende Arten ge�ndert werden&colon.
:ul.
:li.Mit den Kn�pfen :artwork runin name='D:\C\CDPLAYER\HLPINF\BTNMUTE0.BMP'.
oder :artwork runin name='D:\C\CDPLAYER\HLPINF\BTNMUTE1.BMP'.
:li.Mit der :link reftype=hd res=11300.Tastenkombination:elink. :hp2.Strg+M:ehp2.
:li.Mit dem Befehl :hp2.T:ehp2.:hp7.o:ehp7.:hp2.n aus:ehp2. bzw. :hp7.T:ehp7.:hp2.on an:ehp2. im
:link reftype=hd res=11420.Popupmen�:elink.
:li.Mit dem Befehl :hp2.T:ehp2.:hp7.o:ehp7.:hp2.n aus:ehp2. bzw. :hp7.T:ehp7.:hp2.on an:ehp2. im
:link reftype=hd res=11410.Systemmen�:elink.
:eul.:lm margin=1.
:note.
Es kann sein, das Ihr CD-ROM Laufwerk diese Option nicht unterst�tzt. In diesem Fall
ist der Schalter deaktiviert.

.********************************************************************
:h3 res=11230 name=PANEL_MW_CTRL_TITLEEDITOR.Titeleditor starten
:i2 REFID=INDEX_TITLEEDITOR.starten
:p.:lines align=center.:hp7.Befehl&colon. Titeleditor starten:ehp7.:elines.
:p.Mit diesem Befehl wird der
:link reftype=hd res=12000.Titeleditor:elink. gestartet.
.br
Ist eine Audio CD eingelegt, startet der
:link reftype=hd res=12000.Titeleditor:elink.
im :link reftype=fn refid=changemode.�nderungsmodus:elink. f�r die momentane CD. Ist keine
Audio CD eingelegt, startet der
:link reftype=hd res=12000.Titeleditor:elink.
im :link reftype=fn refid=librarymode.Bibliotheksmodus:elink..
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit dem Knopf :hp7.T:ehp7.:hp2.iteleditor...:ehp2.
:li.Mit dem Befehl :hp7.T:ehp7.:hp2.iteleditor...:ehp2. im
:link reftype=hd res=11420.Popupmen�:elink.
:li.Mit dem Befehl :hp7.T:ehp7.:hp2.iteleditor...:ehp2. im Untermen�
:hp7.F:ehp7.:hp2.enster:ehp2. des :link reftype=hd res=11410.Systemmen�s:elink.
:eul.:lm margin=1.

.********************************************************************
:h3 res=11231 name=PANEL_MW_CTRL_PROGRAMEDITOR.Programmeditor starten
:i2 REFID=INDEX_PROGRAMEDITOR.starten (im Main window)
:p.:lines align=center.:hp7.Befehl&colon. Programmeditor starten:ehp7.:elines.
:p.Mit diesem Befehl wird der
:link reftype=hd res=13000.Programmeditor:elink.
f�r das momentane Programm gestartet.
.br
Wenn keine Audio CD eingelegt ist, ist dieser Befehl deaktiviert. Sie k�nnen
aber den
:link reftype=hd res=13000.Programmeditor:elink. vom
:link reftype=hd res=12000.Titeleditor:elink. aus aufrufen,
um das Programm einer gespeicherten CD zu bearbeiten.
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit dem Knopf :hp7.P:ehp7.:hp2.rogrammeditor...:ehp2.
:li.Mit dem Befehl :hp7.P:ehp7.:hp2.rogrammeditor...:ehp2. im
:link reftype=hd res=11420.Popupmen�:elink.
:li.Mit dem Befehl :hp7.P:ehp7.:hp2.rogrammeditor...:ehp2. im Untermen�
:hp7.F:ehp7.:hp2.enster:ehp2. des :link reftype=hd res=11410.Systemmen�s:elink.
:eul.:lm margin=1.

.********************************************************************
:h3 res=11232 name=PANEL_MW_CTRL_SETTINGS.Einstellungen aufrufen
:i2 REFID=INDEX_SETTINGS.aufrufen
:p.:lines align=center.:hp7.Befehl&colon. Einstellungen aufrufen:ehp7.:elines.
:p.Mit diesem Befehl werden die
:link reftype=hd res=15000.Einstellungen:elink. aufgerufen.
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit dem Knopf :hp7.E:ehp7.:hp2.instellungen...:ehp2.
:li.Mit dem Befehl :hp7.E:ehp7.:hp2.instellungen...:ehp2. im
:link reftype=hd res=11420.Popupmen�:elink.
:li.Mit dem Befehl :hp7.E:ehp7.:hp2.instellungen...:ehp2. im Untermen�
:hp7.F:ehp7.:hp2.enster:ehp2. des :link reftype=hd res=11410.Systemmen�s:elink.
:eul.:lm margin=1.

.********************************************************************
:h3 res=11233 name=PANEL_MW_CTRL_INFO.Infofenster anzeigen
:i2 REFID=INDEX_INFOWINDOW.anzeigen (im Main window)
:p.:lines align=center.:hp7.Befehl&colon. Infofenster anzeigen:ehp7.:elines.
:p.Dieser Befehl zeigt das
:link reftype=hd res=14000.Infofenster:elink.
f�r die momentane eingelegte CD an.
.br
Wenn keine Audio CD eingelegt ist, ist dieser Befehl deaktiviert. Sie k�nnen
aber das
:link reftype=hd res=14000.Infofenster:elink. vom
:link reftype=hd res=12000.Titeleditor:elink. aus f�r
eine gespeicherte CD anzeigen.
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit der :link reftype=hd res=11300.Tastenkombination:elink. :hp2.Strg+I:ehp2.
:li.Mit dem Befehl :hp7.I:ehp7.:hp2.nfofenster...:ehp2. im
:link reftype=hd res=11420.Popupmen�:elink.
:li.Mit dem Befehl :hp7.I:ehp7.:hp2.nfofenster...:ehp2. im Untermen�
:hp7.F:ehp7.:hp2.enster:ehp2. des :link reftype=hd res=11410.Systemmen�s:elink.
:eul.:lm margin=1.

.********************************************************************
:h3 res=11240 name=PANEL_MW_CTRL_TITLE.Titel nach Namen w�hlen
:i2 REFID=INDEX_TITLE.nach Namen w�hlen
:i2 REFID=INDEX_NAMES.f�r Wiedergabe ausw�hlen
:p.:lines align=center.:hp7.Titel nach Namen w�hlen:ehp7.:elines.
:p.Wenn Sie einen Titel in der Titelanzeige ausw�hlen, wird der CD Spieler an
die Startposition dieses Titels gesetzt.
Die Auswahl findet durch die Eingabetaste oder das Anklicken des Titels in der
heruntergeklappten Titelliste statt.
.br
Befindet sich der CD Spieler im Wiedergabemodus, wird die Wiedergabe der CD
an der neuen Position unmittelbar fortgesetzt.
.br
Siehe auch ":link reftype=hd res=11150.Titelanzeige:elink.".

.********************************************************************
:h3 res=11250 name=PANEL_MW_CTRL_POSITION.Position einstellen
:i2 REFID=INDEX_POSITION.einstellen
:p.:lines align=center.:hp7.Position einstellen:ehp7.:elines.
:artwork align=center name='D:\C\CDPLAYER\HLPINF\ENG\DSPSLIDE.BMP'.
:p.Sie k�nnen die Position im Programm genau einstellen, indem Sie den Schieber
auf die gew�schte Stelle setzen.
.br
Befindet sich der CD Spieler im Wiedergabemodus, wird die Wiedergabe der CD
an der neuen Position unmittelbar fortgesetzt.
.br
Siehe auch ":link reftype=hd res=11140.Positionsanzeige:elink.".

.********************************************************************
:h3 res=11260 name=PANEL_MW_CTRL_BACKWARD.Titel zur�ck
:i1.Zur�ck
:i2 REFID=INDEX_TITLE.zur�ck
:i2 REFID=INDEX_CDCONTROL.Titel zur�ck
:p.:lines align=center.:hp7.Befehl&colon. Titel zur�ck:ehp7.:elines.
:p.Wenn die Position im momentanen Titel �ber dem in den
:link reftype=hd res=15000.Einstellungen:elink. unter
:link reftype=hd res=15300.Wiedergabe:elink. angegebenen
:link reftype=hd res=15330.R�cksprunglimit:elink. liegt, wird der CD Spieler
an den Anfang des momentanen Titels gesetzt, anderenfalls an den Anfang des vorherigen
Titels im Programm.
.br
War in diesem Fall der CD Spieler schon am Anfang des Programms positioniert,
setzt der Befehl den CD Spieler an den Start des letzten Titels im Programm.
.br
Befindet sich der CD Spieler im Wiedergabemodus, wird die Wiedergabe der CD
an der neuen Position unmittelbar fortgesetzt.
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit dem Knopf :artwork runin name='D:\C\CDPLAYER\HLPINF\BTNBACK.BMP'.
:li.Mit der :link reftype=hd res=11300.Tastenkombination:elink. :hp2.Strg+B:ehp2.
:li.Mit dem Befehl :hp7.Z:ehp7.:hp2.ur�ck:ehp2. im
:link reftype=hd res=11420.Popupmen�:elink.
:li.Mit dem Befehl :hp7.Z:ehp7.:hp2.ur�ck:ehp2. im Untermen�
:hp7.S:ehp7.:hp2.teuerung:ehp2. des :link reftype=hd res=11410.Systemmen�s:elink.
:eul.:lm margin=1.

.********************************************************************
:h3 res=11261 name=PANEL_MW_CTRL_FORWARD.Titel vorw�rts
:i1.Vorw�rts
:i2 REFID=INDEX_TITLE.vorw�rts
:i2 REFID=INDEX_CDCONTROL.Titel vorw�rts
:p.:lines align=center.:hp7.Befehl&colon. Titel vorw�rts:ehp7.:elines.
:p.Dieser Befehl setzt den CD Spieler an den Start
des n�chsten Titels im Programm.
.br
War der CD Spieler schon im letzten Titel positioniert,
setzt dieser Befehl den CD Spieler an den Anfang des Programms.
.br
Befindet sich der CD Spieler im Wiedergabemodus, wird die Wiedergabe der CD
an der neuen Position unmittelbar fortgesetzt.
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit dem Knopf :artwork runin name='D:\C\CDPLAYER\HLPINF\BTNFOR.BMP'.
:li.Mit der :link reftype=hd res=11300.Tastenkombination:elink. :hp2.Strg+F:ehp2.
:li.Mit dem Befehl :hp7.V:ehp7.:hp2.orw�rts:ehp2. im
:link reftype=hd res=11420.Popupmen�:elink.
:li.Mit dem Befehl :hp7.V:ehp7.:hp2.orw�rts:ehp2. im Untermen�
:hp7.S:ehp7.:hp2.teuerung:ehp2. des :link reftype=hd res=11410.Systemmen�s:elink.
:eul.:lm margin=1.

.********************************************************************
:h3 res=11262 name=PANEL_MW_CTRL_PLAY.Wiedergabe starten
:isyn ROOT=start.Start
:i1 ROOTS='start'.Starten
:i2 REFID=INDEX_CDCONTROL.starten
:p.:lines align=center.:hp7.Befehl&colon. Wiedergabe starten:ehp7.:elines.
:p.Dieser Befehl startet die Wiedergabe der CD an der momentanen Position.
.br
Die Wiedergabe l�uft bis zum Ende des eingestellten Programms. Wenn die Option
:link reftype=hd res=11266."Automatische Wiederholung":elink. aktiviert ist,
wird die Wiedergabe dann vom Beginn des Programms an fortgesetzt, anderenfalls wird
sie beendet.
.br
Siehe auch ":link reftype=hd res=11160.Darstellung der Wiedergabe:elink.".
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit dem Knopf :artwork runin name='D:\C\CDPLAYER\HLPINF\BTNPLAY.BMP'.
:li.Mit der :link reftype=hd res=11300.Tastenkombination:elink. :hp2.Strg+P:ehp2.
:li.Mit dem Befehl :hp2.S:ehp2.:hp7.p:ehp7.:hp2.ielen:ehp2. im
:link reftype=hd res=11420.Popupmen�:elink.
:li.Mit dem Befehl :hp2.S:ehp2.:hp7.p:ehp7.:hp2.ielen:ehp2. im Untermen�
:hp7.S:ehp7.:hp2.teuerung:ehp2. des :link reftype=hd res=11410.Systemmen�s:elink.
:eul.:lm margin=1.

.********************************************************************
:h3 res=11263 name=PANEL_MW_CTRL_PAUSE.Wiedergabe unterbrechen
:isyn ROOT=pause.Unterbrechung
:i1 ROOTS='pause'.Unterbrechen
:i2 REFID=INDEX_CDCONTROL.unterbrechen
:p.:lines align=center.:hp7.Befehl&colon. Wiedergabe unterbrechen:ehp7.:elines.
:p.Befindet sich der CD Spieler im Wiedergabemodus, wird die Wiedergabe unterbrochen.
Wurde die Wiedergabe bereits unterbrochen, wird sie an der
momentanen Position fortgesetzt.
.br
Siehe auch ":link reftype=hd res=11262.Wiedergabe starten:elink." und
":link reftype=hd res=11160.Darstellung der Wiedergabe:elink.".
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit dem Knopf :artwork runin name='D:\C\CDPLAYER\HLPINF\BTNPAUSE.BMP'.
:li.Mit der :link reftype=hd res=11300.Tastenkombination:elink. :hp2.Strg+A:ehp2.
:li.Mit dem Befehl :hp2.Pa:ehp2.:hp7.u:ehp7.:hp2.se:ehp2. im
:link reftype=hd res=11420.Popupmen�:elink.
:li.Mit dem Befehl :hp2.Pa:ehp2.:hp7.u:ehp7.:hp2.se:ehp2. im Untermen�
:hp7.S:ehp7.:hp2.teuerung:ehp2. des :link reftype=hd res=11410.Systemmen�s:elink.
:eul.:lm margin=1.

.********************************************************************
:h3 res=11264 name=PANEL_MW_CTRL_STOP.Wiedergabe stoppen
:isyn ROOT=stop.Stop
:i1 ROOTS='stop'.Stoppen
:i2 REFID=INDEX_CDCONTROL.stoppen
:p.:lines align=center.:hp7.Befehl&colon. Wiedergabe stoppen:ehp7.:elines.
:p.Die Wiedergabe wird gestoppt und der CD Spieler an den Anfang des Programms
gesetzt.
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit dem Knopf :artwork runin name='D:\C\CDPLAYER\HLPINF\BTNSTOP.BMP'.
:li.Mit der :link reftype=hd res=11300.Tastenkombination:elink. :hp2.Strg+S:ehp2.
:li.Mit dem Befehl :hp7.S:ehp7.:hp2.top:ehp2. im
:link reftype=hd res=11420.Popupmen�:elink.
:li.Mit dem Befehl :hp7.S:ehp7.:hp2.top:ehp2. im Untermen�
:hp7.S:ehp7.:hp2.teuerung:ehp2. des :link reftype=hd res=11410.Systemmen�s:elink.
:eul.:lm margin=1.

.********************************************************************
:h3 res=11265 name=PANEL_MW_CTRL_EJECT.CD auswerfen
:isyn ROOT=eject.Auswurf
:i1 ROOTS='eject'.Auswerfen
:i2 REFID=INDEX_CD.auswerfen
:p.:lines align=center.:hp7.Befehl&colon. CD auswerfen:ehp7.:elines.
:p.Dieser Befehl wirft die CD aus.
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit dem Knopf :artwork runin name='D:\C\CDPLAYER\HLPINF\BTNEJECT.BMP'.
:li.Mit der :link reftype=hd res=11300.Tastenkombination:elink. :hp2.Strg+E:ehp2.
:li.Mit dem Befehl :hp7.A:ehp7.:hp2.uswurf:ehp2. im
:link reftype=hd res=11420.Popupmen�:elink.
:li.Mit dem Befehl :hp7.A:ehp7.:hp2.uswurf:ehp2. im Untermen�
:hp7.S:ehp7.:hp2.teuerung:ehp2. des :link reftype=hd res=11410.Systemmen�s:elink.
:eul.:lm margin=1.
:note.
Es kann sein, da� Ihr CD-ROM Laufwerk diesen Befehl nicht unterst�tzt. In diesem Fall
sind der Befehlsknopf und die Men�punkte deaktiviert.

.********************************************************************
:h3 res=11266 name=PANEL_MW_CTRL_REPEAT.Automatische Wiederholung einstellen
:i1.Wiederholung
:i2 REFID=INDEX_CDCONTROL.automatisch wiederholen
:i2 REFID=INDEX_AUTOREPEAT.einstellen (im Main window)
:p.:lines align=center.:hp7.Option&colon. Automatische Wiederholung:ehp7.:elines.
:p.Wenn die automatische Wiederholung aktiviert ist, wird die Wiedergabe bei Erreichen des
Programmendes automatisch vom Anfang des Programms an fortgesetzt, bis sie von Ihnen
unterbrochen wird.
.br
Wird der Knopf :artwork runin name='D:\C\CDPLAYER\HLPINF\BTNAUTO1.BMP'. angezeigt, ist die
automatische Wiederholung aktiviert.
:p.Diese Option kann auf folgende Arten ge�ndert werden&colon.
:ul.
:li.Mit den Kn�pfen :artwork runin name='D:\C\CDPLAYER\HLPINF\BTNAUTO0.BMP'. oder
:artwork runin name='D:\C\CDPLAYER\HLPINF\BTNAUTO1.BMP'.
:li.Mit der :link reftype=hd res=11300.Tastenkombination:elink. :hp2.Strg+R:ehp2.
:li.Mit dem Befehl :hp2.Auto:ehp2.:hp7.w:ehp7.:hp2.iederholung:ehp2. im
:link reftype=hd res=11420.Popupmen�:elink.
:li.Mit dem Befehl :hp2.Auto:ehp2.:hp7.w:ehp7.:hp2.iederholung:ehp2. im Untermen�
:hp7.S:ehp7.:hp2.teuerung:ehp2. des :link reftype=hd res=11410.Systemmen�s:elink.
:eul.:lm margin=1.
:p.Diese Option kann auch in den
:link reftype=hd res=15000.Einstellungen:elink. unter
:link reftype=hd res=15300.Wiedergabe:elink. mit der Option
:link reftype=hd res=15310.Autowiederholung:elink. ge�ndert werden. In diesem Fall
bleibt die Einstellung der Option auch nach Programmende erhalten.

.********************************************************************
:h2 res=11300 name=PANEL_MW_KEYBOARD.Tastatur- und Mausbefehle
:i2 REFID=INDEX_MAINWINDOW.Tastatur- und Mausbefehle
:i2 REFID=INDEX_KEYBOARD.Befehle im Main window
:i2 REFID=INDEX_MOUSE.Befehle im Main window
:p.:lines align=center.:hp7.Tastaturbefehle im Main window:ehp7.:elines.
:dl break=fit tsize=15.
:dthd.:hp3.Taste:ehp3.
:ddhd.:hp3.Befehl:ehp3.
:dt.:hp2.Strg+A:ehp2.
:dd.F�hrt den :link reftype=hd res=11263.Wiedergabe unterbrechen:elink. Befehl aus
:dt.:hp2.Strg+B:ehp2.
:dd.F�hrt den :link reftype=hd res=11260.Titel zur�ck:elink. Befehl aus
:dt.:hp2.Strg+E:ehp2.
:dd.F�hrt den :link reftype=hd res=11265.CD auswerfen:elink. Befehl aus
:dt.:hp2.Strg+F:ehp2.
:dd.F�hrt den :link reftype=hd res=11261.Titel vorw�rts:elink. Befehl aus
:dt.:hp2.Strg+I:ehp2.
:dd.F�hrt den :link reftype=hd res=11233.Infofenster anzeigen:elink. Befehl aus
:dt.:hp2.Strg+M:ehp2.
:dd.F�hrt den :link reftype=hd res=11224.Ton aus/an:elink. Befehl aus
:dt.:hp2.Strg+P:ehp2.
:dd.F�hrt den :link reftype=hd res=11262.Wiedergabe starten:elink. Befehl aus
:dt.:hp2.Strg+R:ehp2.
:dd.F�hrt den :link reftype=hd res=11266.Autowiederholung einstellen:elink. Befehl aus
:dt.:hp2.Strg+S:ehp2.
:dd.F�hrt den :link reftype=hd res=11264.Wiedergabe stoppen:elink. Befehl aus
:dt.:hp2.Strg+F1 - Strg+F12:ehp2.
:dd.Selektiert die entsprechende Spur auf der CD (1-12)
:dt.:hp2.Strg+Alt++:ehp2.
:dd.Setzt die Position eine 1/75 Sekunde nach vorne
:dt.:hp2.Alt++:ehp2.
:dd.Setzt die Position eine 1/5 Sekunde nach vorne
:dt.:hp2.+:ehp2.
:dd.Setzt die Position eine Sekunde nach vorne
:dt.:hp2.Umsch++:ehp2.
:dd.Setzt die Position um 10 Sekunden nach vorne
:dt.:hp2.Strg++:ehp2.
:dd.Setzt die Position eine Minute nach vorne
:dt.:hp2.Umsch+Strg++:ehp2.
:dd.Setzt die Position um 10 Minuten nach vorne
:dt.:hp2.Strg+Alt+-:ehp2.
:dd.Setzt die Position eine 1/75 Sekunde zur�ck
:dt.:hp2.-:ehp2.
:dd.Setzt die Position eine 1/5 Sekunde zur�ck
:dt.:hp2.-:ehp2.
:dd.Setzt die Position eine Sekunde zur�ck
:dt.:hp2.Umsch+-:ehp2.
:dd.Setzt die Position um 10 Sekunden zur�ck
:dt.:hp2.Strg+-:ehp2.
:dd.Setzt die Position eine Minute zur�ck
:dt.:hp2.Umsch+Strg+-:ehp2.
:dd.Setzt die Position um 10 Minuten zur�ck
:dt.:hp2.Umsch+F10:ehp2.
:dd.Aktiviert das :link reftype=hd res=11420.Popupmen�:elink.
:edl.

:p.:lines align=center.:hp7.Mausbefehle im Main window:ehp7.:elines.
:dl break=fit tsize=15.
:dt.:hp2.Klick der rechten Maustaste:ehp2.
:dd.Aktiviert das :link reftype=hd res=11420.Popupmen�:elink.
:dt.:hp2.Klick der mittleren Maustaste:ehp2.
:dd.Startet oder unterbricht die Wiedergabe
:dt.:hp2.Taste Strg und Klick der mittleren Maustaste:ehp2.
:dd.Stoppt die Wiedergabe
:edl.

.********************************************************************
:h2 res=11400 name=PANEL_MW_MENUS.Men�befehle
:i2 REFID=INDEX_MAINWINDOW.Men�befehle
:i2 REFID=INDEX_MENU.im Main window
:p.:lines align=center.:hp7.Men�befehle im Main window:ehp7.:elines.
:p.Die wichtigsten Befehle und Optionen im Main window k�nnen auch �ber
das
:link reftype=hd res=11420.Popupmen�:elink. und das erweiterte
:link reftype=hd res=11410.Systemmen�:elink. gegeben bzw. eingestellt werden.
.br
Das
:link reftype=hd res=11420.Popupmen�:elink. kann mit einfachem Klick der
rechten Maustaste an einer beliebigen Position im Main window oder �ber
die Tastenkombination Umsch+F10 aufgerufen werden.

.********************************************************************
:h3 res=11420 name=PANEL_MW_MENU_POPUP.Popupmen�
:i2 REFID=INDEX_POPUPMENU.im Main window
:p.:lines align=center.:hp7.Das Popupmen� im Main window:ehp7.:elines.
:dl break=fit tsize=15.
:dthd.:hp3.Men�punkt:ehp3.
:ddhd.:hp3.Befehl:ehp3.
:dt.:hp2.:ehp2.:hp7.Z:ehp7.:hp2.ur�ck:ehp2.
:dd.F�hrt den :link reftype=hd res=11260.Titel zur�ck:elink. Befehl aus
:dt.:hp2.:ehp2.:hp7.V:ehp7.:hp2.orw�rts:ehp2.
:dd.F�hrt den :link reftype=hd res=11261.Titel vorw�rts:elink. Befehl aus
:dt.:hp2.S:ehp2.:hp7.p:ehp7.:hp2.ielen:ehp2.
:dd.F�hrt den :link reftype=hd res=11262.Wiedergabe starten:elink. Befehl aus
:dt.:hp2.Pa:ehp2.:hp7.u:ehp7.:hp2.se:ehp2.
:dd.F�hrt den :link reftype=hd res=11263.Wiedergabe unterbrechen:elink. Befehl aus
:dt.:hp2.:ehp2.:hp7.S:ehp7.:hp2.top:ehp2.
:dd.F�hrt den :link reftype=hd res=11264.Wiedergabe stoppen:elink. Befehl aus
:dt.:hp2.:ehp2.:hp7.A:ehp7.:hp2.uswurf:ehp2.
:dd.F�hrt den :link reftype=hd res=11265.CD auswerfen:elink. Befehl aus
:dt.:hp2.Auto:ehp2.:hp7.w:ehp7.:hp2.iederholung:ehp2.
:dd.F�hrt den :link reftype=hd res=11266.Autowiederholung einstellen:elink. Befehl aus
:dt.:hp2.T:ehp2.:hp7.o:ehp7.:hp2.n aus:ehp2.
:dd.F�hrt den :link reftype=hd res=11224.Ton aus:elink. Befehl aus
:dt.:hp2.T:ehp2.:hp7.o:ehp7.:hp2.n an:ehp2.
:dd.F�hrt den :link reftype=hd res=11224.Ton an:elink. Befehl aus
:dt.:hp2.:ehp2.:hp7.T:ehp7.:hp2.iteleditor...:ehp2.
:dd.F�hrt den :link reftype=hd res=11230.Titeleditor starten:elink. Befehl aus
:dt.:hp2.P:ehp2.:hp7.r:ehp7.:hp2.ogrammeditor...:ehp2.
:dd.F�hrt den :link reftype=hd res=11231.Programmeditor starten:elink. Befehl aus
:dt.:hp2.:ehp2.:hp7.E:ehp7.:hp2.instellungen...:ehp2.
:dd.F�hrt den :link reftype=hd res=11232.Einstellungen aufrufen:elink. Befehl aus
:dt.:hp2.:ehp2.:hp7.I:ehp7.:hp2.nfofenster...:ehp2.
:dd.F�hrt den :link reftype=hd res=11233.Infofenster anzeigen:elink. Befehl aus
:dt.:hp2.:ehp2.:hp7.H:ehp7.:hp2.ilfe:ehp2.
:dd.Zeigt das Hilfemen� an.
:dt.:hp2.S:ehp2.:hp7.c:ehp7.:hp2.hliessen:ehp2.
:dd.Beendet das CD Spieler Programm.
:edl.

.********************************************************************
:h3 res=11410 name=PANEL_MW_MENU_SYS.Systemmen�
:i2 REFID=INDEX_SYSMENU.im Main window
:p.:lines align=center.:hp7.Das erweiterte Systemmen� im Main window:ehp7.:elines.
:p.Zus�tzlich zu den normalen Men�punkten des Systemmen�s enth�lt das Systemmen� des
Main windows folgende Men�punkte:
:dl break=fit tsize=15.
:dthd.:hp3.Men�punkt:ehp3.
:ddhd.:hp3.Befehl/Untermen�:ehp3.
:dt.:hp2.:ehp2.:hp7.S:ehp7.:hp2.teuerung:ehp2.
:dd.Untermen� :hp2.Steuerung:ehp2. (s.u.)
:dt.:hp2.:ehp2.:hp7.F:ehp7.:hp2.enster:ehp2.
:dd.Untermen� :hp2.Fenster:ehp2. (s.u.)
:dt.:hp2.T:ehp2.:hp7.o:ehp7.:hp2.n aus:ehp2.
:dd.F�hrt den :link reftype=hd res=11224.Ton aus:elink. Befehl aus
:dt.:hp2.T:ehp2.:hp7.o:ehp7.:hp2.n an:ehp2.
:dd.F�hrt den :link reftype=hd res=11224.Ton an:elink. Befehl aus
:dt.:hp2.:ehp2.:hp7.H:ehp7.:hp2.ilfe:ehp2.
:dd.Zeigt das Hilfemen� an.
:edl.

:p.Untermen� :hp2.Steuerung:ehp2.
:dl break=fit tsize=15.
:dthd.:hp3.Men�punkt:ehp3.
:ddhd.:hp3.Befehl:ehp3.
:dt.:hp2.:ehp2.:hp7.Z:ehp7.:hp2.ur�ck:ehp2.
:dd.F�hrt den :link reftype=hd res=11260.Titel zur�ck:elink. Befehl aus
:dt.:hp2.:ehp2.:hp7.V:ehp7.:hp2.orw�rts:ehp2.
:dd.F�hrt den :link reftype=hd res=11261.Titel vorw�rts:elink. Befehl aus
:dt.:hp2.S:ehp2.:hp7.p:ehp7.:hp2.ielen:ehp2.
:dd.F�hrt den :link reftype=hd res=11262.Wiedergabe starten:elink. Befehl aus
:dt.:hp2.Pa:ehp2.:hp7.u:ehp7.:hp2.se:ehp2.
:dd.F�hrt den :link reftype=hd res=11263.Wiedergabe unterbrechen:elink. Befehl aus
:dt.:hp2.:ehp2.:hp7.S:ehp7.:hp2.top:ehp2.
:dd.F�hrt den :link reftype=hd res=11264.Wiedergabe stoppen:elink. Befehl aus
:dt.:hp2.:ehp2.:hp7.A:ehp7.:hp2.uswurf:ehp2.
:dd.F�hrt den :link reftype=hd res=11265.CD auswerfen:elink. Befehl aus
:dt.:hp2.Auto:ehp2.:hp7.w:ehp7.:hp2.iederholung:ehp2.
:dd.F�hrt den :link reftype=hd res=11266.Autowiederholung einstellen:elink. Befehl aus
:edl.

:p.Untermen� :hp2.Fenster:ehp2.
:dl break=fit tsize=15.
:dthd.:hp3.Men�punkt:ehp3.
:ddhd.:hp3.Befehl:ehp3.
:dt.:hp2.:ehp2.:hp7.T:ehp7.:hp2.iteleditor...:ehp2.
:dd.F�hrt den :link reftype=hd res=11230.Titeleditor starten:elink. Befehl aus
:dt.:hp2.P:ehp2.:hp7.r:ehp7.:hp2.ogrammeditor...:ehp2.
:dd.F�hrt den :link reftype=hd res=11231.Programmeditor starten:elink. Befehl aus
:dt.:hp2.:ehp2.:hp7.E:ehp7.:hp2.instellungen...:ehp2.
:dd.F�hrt den :link reftype=hd res=11232.Einstellungen aufrufen:elink. Befehl aus
:dt.:hp2.:ehp2.:hp7.I:ehp7.:hp2.nfofenster...:ehp2.
:dd.F�hrt den :link reftype=hd res=11233.Infofenster anzeigen:elink. Befehl aus
:edl.
.********************************************************************

.********************************************************************
.********************************************************************
:h1 res=12000 name=PANEL_TITLEEDITOR.Titeleditor
:i2 REFID=INDEX_WINDOWS.Titeleditor
:i2 REFID=INDEX_TITLEEDITOR.�berblick
:i2 REFID=INDEX_TITLE.Editor
:p.:lines align=center.:hp7.Der Titeleditor:ehp7.:elines.
:p.Leider enthalten CD's keine Information �ber den Titel der CD und die
Titel der einzelnen Spuren. Mit dem Titeleditor des CD Spielers ist es aber
leicht m�glich, die fehlende Information selbst einzugeben. Die Titel
werden in der :link reftype=fn refid=library.CD Bibliothek:elink. des CD Spielers
gespeichert, die sich zusammen mit dem CD Spieler auf Ihrer Festplatte befindet.
:p.Der Titeleditor arbeitet in zwei unterschiedlichen Modi. Im
:link reftype=fn refid=librarymode.Bibliotheksmodus:elink.
k�nnen Sie sich die Titel und zus�tzlichen Informationen aller CD's in der
:link reftype=fn refid=library.CD Bibliothek:elink. betrachten und eine CD
f�r die �nderung ausw�hlen, im
:link reftype=fn refid=changemode.�nderungsmodus:elink. k�nnen Sie die Titel
und zus�tzlichen Informationen einer CD bearbeiten.
.br
Wenn der Titeleditor mit dem Befehl
:link reftype=hd res=11230.Titeleditor starten:elink. im
:link reftype=hd res=11000.Hauptfenster:elink. des CD Spielers aufgerufen wird,
befindet er sich im :link reftype=fn refid=changemode.�nderungsmodus:elink.
f�r die eingelegte CD. Sie k�nnen aber jederzeit mit den Kn�pfen
:link reftype=hd res=12260.Bibliothek:elink. (im
:link reftype=fn refid=changemode.�nderungsmodus:elink.) und
:link reftype=hd res=12270.Bearbeiten:elink. (im
:link reftype=fn refid=librarymode.Bibliotheksmodus:elink.)
zwischen den beiden Modi umschalten.
.br
In welchem Modus sich der Titeleditor gerade befindet, k�nnen Sie an
der Titelleiste des Titeleditors erkennen. Im
:link reftype=fn refid=changemode.�nderungsmodus:elink. steht dort
"CD Titeleditor", im
:link reftype=fn refid=librarymode.Bibliotheksmodus:elink.
"CD Titeleditor Bibliothek".

.********************************************************************
:h2 res=12100 name=PANEL_TE_DISPLAY.Anzeigeelemente
:i2 REFID=INDEX_TITLEEDITOR.Anzeigeelemente
:i2 REFID=INDEX_DISPLAY.im Titeleditor
:p.:lines align=center.:hp7.Anzeigen im Titeleditor:ehp7.:elines.
:ul.
:li.:link reftype=hd res=12110.CD Titel:elink.
:li.:link reftype=hd res=12120.Zus�tzliche CD Information:elink.
:li.:link reftype=hd res=12130.Spurnummern:elink.
:li.:link reftype=hd res=12140.Spurtitel:elink.
:li.:link reftype=hd res=12150.Zus�tzliche Spurinformation:elink.
:eul.:lm margin=1.

.********************************************************************
:h3 res=12110 name=PANEL_TE_DISP_CDTITLE.CD Titel
:i2 REFID=INDEX_CD.Titel (im Titeleditor)
:i2 REFID=INDEX_TITLE.der CD (im Titeleditor)
:p.:lines align=center.:hp7.CD Titel:ehp7.:elines.
:p.Das obere Feld in der Box "CD Titel" zeigt den Titel der ausgew�hlten
CD an. Im :link reftype=fn refid=librarymode.Bibliotheksmodus:elink.
k�nnen Sie hier die
:link reftype=hd res=12210.CD ausw�hlen:elink., im
:link reftype=fn refid=changemode.�nderungsmodus:elink. den
:link reftype=hd res=12210.CD Titel �ndern:elink..

.********************************************************************
:h3 res=12120 name=PANEL_TE_DISP_CDINFO.Zus�tzliche CD Information
:i2 REFID=INDEX_CD.Zus�tzl. Information (im Titeleditor)
:i2 REFID=INDEX_ADDINFO.zur CD (im Titeleditor)
:p.:lines align=center.:hp7.Zus�tzliche CD Information:ehp7.:elines.
:p.Das untere Feld in der Box "CD Titel" zeigt die zus�tzliche Information
zu der ausgew�hlten CD an. Im
:link reftype=fn refid=changemode.�nderungsmodus:elink. k�nnen Sie die
:link reftype=hd res=12220.zus�tzliche Information zur CD �ndern:elink..

.********************************************************************
:h3 res=12130 name=PANEL_TE_DISP_SCROLLBAR.Spurnummern
:i2 REFID=INDEX_TRACK.Nummern (im Titeleditor)
:i2 REFID=INDEX_NUMBER.der Spur (im Titeleditor)
:p.:lines align=center.:hp7.Spurnummern:ehp7.:elines.
:p.Die linke Auswahlliste zeigt die Nummern aller Spuren auf der CD an.
Die Nummer der ausgew�hlten Spur ist markiert.
Im :link reftype=fn refid=librarymode.Bibliotheksmodus:elink.
k�nnen Sie hier die zu betrachtene Spur ausw�hlen,
im :link reftype=fn refid=changemode.�nderungsmodus:elink.
die zu ver�ndernde
:link reftype=hd res=12230.Spur ausw�hlen:elink..

.********************************************************************
:h3 res=12140 name=PANEL_TE_DISP_TRACKTITLE.Spurtitel
:i2 REFID=INDEX_TRACK.Titel (im Titeleditor)
:i2 REFID=INDEX_TITLE.der Spur (im Titeleditor)
:p.:lines align=center.:hp7.Spurtitel:ehp7.:elines.
:p.Das obere Feld in der Box "Spurtitel" zeigt den Titel der ausgew�hlten
Spur an. Im
:link reftype=fn refid=librarymode.Bibliotheksmodus:elink.
k�nnen Sie hier die
:link reftype=hd res=12240.Spur ausw�hlen:elink., im
:link reftype=fn refid=changemode.�nderungsmodus:elink. den
:link reftype=hd res=12240.Spurtitel �ndern:elink..

.********************************************************************
:h3 res=12150 name=PANEL_TE_DISP_TRACKINFO.Zus�tzliche Spurinformation
:i2 REFID=INDEX_TRACK.Zus�tzl. Information (im Titeleditor)
:i2 REFID=INDEX_ADDINFO.zur Spur (im Titeleditor)
:p.:lines align=center.:hp7.Zus�tzliche Spurinformation:ehp7.:elines.
:p.Das untere Feld in der Box "Spurtitel" zeigt die zus�tzliche Information
zu der ausgew�hlten Spur an. Im
:link reftype=fn refid=changemode.�nderungsmodus:elink. k�nnen Sie die
:link reftype=hd res=12250.zus�tzliche Information zur Spur �ndern:elink..

.********************************************************************
:h2 res=12200 name=PANEL_TE_CONTROL.Steuerung
:i2 REFID=INDEX_TITLEEDITOR.Steuerung
:i2 REFID=INDEX_CONTROL.im Titeleditor
:p.:lines align=center.:hp7.Steuerung im Titeleditor:ehp7.:elines.
:ul.
:li.:link reftype=hd res=12210.CD Titel �ndern/ausw�hlen:elink.
:li.:link reftype=hd res=12220.Zus�tzliche CD Information �ndern:elink.
:li.:link reftype=hd res=12230.Spurnummer ausw�hlen:elink.
:li.:link reftype=hd res=12240.Spurtitel �ndern/ausw�hlen:elink.
:li.:link reftype=hd res=12250.Zus�tzliche Spurinformation �ndern:elink.
:li.:link reftype=hd res=12260.CD Bibliothek:elink.
:li.:link reftype=hd res=12261.Infofenster anzeigen:elink.
:li.:link reftype=hd res=12262.Programm bearbeiten:elink.
:li.:link reftype=hd res=12263.Titel importieren:elink.
:li.:link reftype=hd res=12270.Ausgew�hlte CD bearbeiten:elink.
:li.:link reftype=hd res=12271.Ausgew�hlte CD l�schen:elink.
:li.:link reftype=hd res=12280.Titeleditor verlassen:elink.
:eul.:lm margin=1.

.********************************************************************
:h3 res=12210 name=PANEL_TE_CTRL_CDTITLE.CD Titel �ndern/ausw�hlen
:i2 REFID=INDEX_CD.Titel �ndern (im Titeleditor)
:i2 REFID=INDEX_TITLE.der CD �ndern (im Titeleditor)
:p.:lines align=center.:hp7.CD Titel �ndern/ausw�hlen:ehp7.:elines.
:p.Im :link reftype=fn refid=changemode.�nderungsmodus:elink.
k�nnen Sie den Titel der CD hier �ndern. Der CD Titel
kann bis zu 100 Zeichen lang sein. Bedenken Sie jedoch, da� sehr lange
Titel nicht vollst�ndig in der
:link reftype=hd res=11150.Titelleiste:elink. des
:link reftype=hd res=11000.Hauptfensters:elink.
angezeigt werden k�nnen.
.br
Jede �nderung des CD Titels wird automatisch gespeichert.
:p.Im :link reftype=fn refid=librarymode.Bibliotheksmodus:elink.
k�nnen Sie hier die zu betrachtene CD ausw�hlen. CD's in der
:link reftype=fn refid=library.CD Bibliothek:elink.,
denen Sie noch keinen Titel gegeben haben, werden unter dem
Titel "ohne Namen" angezeigt.

.********************************************************************
:h3 res=12220 name=PANEL_TE_CTRL_CDINFO.Zus�tzliche CD Information �ndern
:i2 REFID=INDEX_CD.Zus�tzl. Information �ndern (im Titeleditor)
:i2 REFID=INDEX_ADDINFO.zur CD �ndern (im Titeleditor)
:p.:lines align=center.:hp7.Zus�tzliche CD Information �ndern:ehp7.:elines.
:p.Im :link reftype=fn refid=changemode.�nderungsmodus:elink.
k�nnen Sie hier zus�tzliche Informationen zu einer CD eintragen.
Diese Notiz kann bis zu 4000 Zeichen lang sein.
.br
Jede �nderung der zus�tzlichen Informationen wird automatisch gespeichert.
:p.Im :link reftype=fn refid=librarymode.Bibliotheksmodus:elink.
k�nnen Sie die zus�tzlichen Informationen nur betrachten aber nicht
ver�ndern.

.********************************************************************
:h3 res=12230 name=PANEL_TE_CTRL_SCROLLBAR.Spurnummer ausw�hlen
:i2 REFID=INDEX_TRACK.Nummer ausw�hlen (im Titeleditor)
:i2 REFID=INDEX_NUMBER.der Spur ausw�hlen (im Titeleditor)
:p.:lines align=center.:hp7.Spurnummer ausw�hlen:ehp7.:elines.
:p.In dieser Auswahlliste k�nnen Sie den Spurtitel ausw�hlen, den
Sie
:link reftype=hd res=12140.betrachten:elink.
oder
:link reftype=hd res=12240.�ndern:elink.
wollen

.********************************************************************
:h3 res=12240 name=PANEL_TE_CTRL_TRACKTITLE.Spurtitel �ndern/ausw�hlen
:i2 REFID=INDEX_TRACK.Titel �ndern (im Titeleditor)
:i2 REFID=INDEX_TITLE.der Spur �ndern (im Titeleditor)
:p.:lines align=center.:hp7.Spurtitel �ndern/ausw�hlen:ehp7.:elines.
:p.Im :link reftype=fn refid=changemode.�nderungsmodus:elink.
k�nnen Sie hier die Spurtitel der CD �ndern. Jeder Spurtitel
kann bis zu 100 Zeichen lang sein. Bedenken Sie jedoch, da� sehr lange
Titel nicht vollst�ndig in der
:link reftype=hd res=11150.Titelanzeige:elink. des
:link reftype=hd res=11000.Hauptfensters:elink.
angezeigt werden k�nnen.
.br
Jede �nderung eines Spurtitels wird automatisch gespeichert.
:p.Die Nummer des gerade angezeigten Spurtitels ist in den
:link reftype=hd res=12130.Spurnummern:elink. markiert. Dort k�nnen
Sie auch eine andere
:link reftype=hd res=12230.Spurnummer ausw�hlen:elink..
Wenn Sie sich im Eingabefeld f�r den Spurtitel befinden,
k�nnen Sie auch mit folgenden
:link reftype=hd res=12300.Tasten:elink.
eine andere Spur ausw�hlen&colon.
:dl break=fit tsize=15.
:dthd.:hp3.Taste:ehp3.
:ddhd.:hp3.Befehl:ehp3.
:dt.:hp2.Eingabe:ehp2.
:dd.Springt zur n�chsten Spur oder zur ersten Spur, falls Sie die letzte
Spur bearbeiten.
:dt.:hp2.&darrow.:ehp2.
:dd.Springt zur n�chsten Spur.
:dt.:hp2.&uarrow.:ehp2.
:dd.Springt zur vorherigen Spur.
:dt.:hp2.Strg+&darrow.:ehp2.
:dd.Springt zur letzten Spur.
:dt.:hp2.Strg+&uarrow.:ehp2.
:dd.Springt zur ersten Spur.
:edl.
:p.Im :link reftype=fn refid=librarymode.Bibliotheksmodus:elink.
k�nnen Sie sich hier die Spurtitel der ausgew�hlten CD betrachten und
ausw�hlen.

.********************************************************************
:h3 res=12250 name=PANEL_TE_CTRL_TRACKINFO.Zus�tzliche Spurinformation �ndern
:i2 REFID=INDEX_TRACK.Zus�tzl. Information �ndern (im Titeleditor)
:i2 REFID=INDEX_ADDINFO.zur Spur �ndern (im Titeleditor)
:p.:lines align=center.:hp7.Zus�tzliche Spurinformation �ndern:ehp7.:elines.
:p.Im :link reftype=fn refid=changemode.�nderungsmodus:elink.
k�nnen Sie hier zus�tzliche Informationen zu einer Spur eintragen.
Diese Notiz kann bis zu 4000 Zeichen lang sein.
.br
Jede �nderung der zus�tzlichen Informationen wird automatisch gespeichert.
:p.Die Nummer des gerade angezeigten Spurtitels ist in den
:link reftype=hd res=12130.Spurnummern:elink. markiert. Dort k�nnen
Sie auch eine andere
:link reftype=hd res=12230.Spurnummer ausw�hlen:elink..
:p.Im :link reftype=fn refid=librarymode.Bibliotheksmodus:elink.
k�nnen die zus�tzlichen Informationen nur betrachtet aber nicht
ver�ndert werden.

.********************************************************************
:h3 res=12260 name=PANEL_TE_CTRL_LIBRARY.CD Bibliothek
:i2 REFID=INDEX_LIBRARY.aktivieren (im Titeleditor)
:i2 REFID=INDEX_CD.Bibliothek (im Titeleditor)
:p.:lines align=center.:hp7.Befehl&colon. CD Bibliothek:ehp7.:elines.
:p.Mit diesem Befehl setzen Sie den
:link reftype=hd res=12000.Titeleditor:elink.
in den
:link reftype=fn refid=librarymode.Bibliotheksmodus:elink.
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit dem Knopf :hp7.B:ehp7.:hp2.ibliothek:ehp2.
:li.Mit der :link reftype=hd res=12300.Tastenkombination:elink. :hp2.Strg+L:ehp2.
:eul.:lm margin=1.

.********************************************************************
:h3 res=12261 name=PANEL_TE_CTRL_INFO.Infofenster anzeigen
:i2 REFID=INDEX_INFOWINDOW.anzeigen (im Titeleditor)
:p.:lines align=center.:hp7.Befehl&colon. Infofenster anzeigen:ehp7.:elines.
:p.Dieser Befehl zeigt das
:link reftype=hd res=14000.Infofenster:elink.
f�r die ausgew�hlte CD an. Er ist im
:link reftype=fn refid=changemode.�nderungsmodus:elink.
und im
:link reftype=fn refid=librarymode.Bibliotheksmodus:elink.
g�ltig.
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit dem Knopf :hp7.I:ehp7.:hp2.nfo:ehp2.
:li.Mit der :link reftype=hd res=12300.Tastenkombination:elink. :hp2.Strg+I:ehp2.
:eul.:lm margin=1.

.********************************************************************
:h3 res=12262 name=PANEL_TE_CTRL_PROGRAM.Programm bearbeiten
:i2 REFID=INDEX_PROGRAMEDITOR.starten (im Titeleditor)
:p.:lines align=center.:hp7.Befehl&colon. Programm bearbeiten:ehp7.:elines.
:p.Dieser Befehl ruft den
:link reftype=hd res=13000.Programmeditor:elink.
f�r die ausgew�hlte CD auf. Er ist im
:link reftype=fn refid=changemode.�nderungsmodus:elink.
und im
:link reftype=fn refid=librarymode.Bibliotheksmodus:elink.
g�ltig.

:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit dem Knopf :hp7.P:ehp7.:hp2.rogramm:ehp2.
:li.Mit der :link reftype=hd res=12300.Tastenkombination:elink. :hp2.Strg+P:ehp2.
:eul.:lm margin=1.

.********************************************************************
:h3 res=12263 name=PANEL_TE_CTRL_IMPORT.Titel importieren
:isyn ROOT=import.Importieren
:i1 ROOTS='import' ID=INDEX_IMPORT.Import
:p.:lines align=center.:hp7.Befehl&colon. Titel importieren:ehp7.:elines.
:p.Dieser Befehl ist zur Zeit noch ohne Funktion.
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit dem Knopf :hp2.I:ehp2.:hp7.m:ehp7.:hp2.port:ehp2.
:eul.:lm margin=1.

.********************************************************************
:h3 res=12270 name=PANEL_TE_CTRL_CHANGE.Ausgew�hlte CD bearbeiten
:i2 REFID=INDEX_CD.Titel bearbeiten (im Titeleditor)
:p.:lines align=center.:hp7.Befehl&colon. Ausgew�hlte CD bearbeiten:ehp7.:elines.
:p.Mit diesem Befehl setzen Sie den
:link reftype=hd res=12000.Titeleditor:elink.
in den
:link reftype=fn refid=changemode.�nderungsmodus:elink.
f�r die ausgew�hlte CD.
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit dem Knopf :hp7.B:ehp7.:hp2.earbeiten:ehp2.
:li.Mit der :link reftype=hd res=12300.Tastenkombination:elink. :hp2.Strg+L:ehp2.
:eul.:lm margin=1.

.********************************************************************
:h3 res=12271 name=PANEL_TE_CTRL_DELETE.Ausgew�hlte CD l�schen
:i2 REFID=INDEX_CD.Titel l�schen (im Titeleditor)
:i2 REFID=INDEX_LIBRARY.CD l�schen (im Titeleditor)
:i2 REFID=INDEX_TITLE.der CD l�schen (im Titeleditor)
:p.:lines align=center.:hp7.Befehl&colon. Ausgew�hlte CD l�schen:ehp7.:elines.
:p.Dieser Befehl l�scht die ausgew�hlte CD aus der
:link reftype=fn refid=library.CD Bibliothek:elink..
Um sicher zu gehen, m�ssen Sie den Befehl vor der Ausf�hrung noch
best�tigen.
:caution.
Mit dem L�schen der CD gehen auch alle gespeicherten Titel, Informationen
und das gespeicherte Programm verloren!
:ecaution.
:note.
Es ist nicht m�glich, die momentan eingelegte CD v�llig aus der
:link reftype=fn refid=library.CD Bibliothek:elink. zu l�schen.
Es werden zwar alle gespeicherten Titel, Informationen
und das gespeicherte Programm gel�scht, aber die CD wird sofort
wieder mit einem Eintrag "ohne Namen" in der
:link reftype=fn refid=library.CD Bibliothek:elink. eingetragen.
Dieser Eintrag wird sichtbar, sobald Sie den
:link reftype=fn refid=librarymode.Bibliotheksmodus:elink.
erneut aktivieren.
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit dem Knopf :hp7.L:ehp7.:hp2.�schen:ehp2.
:eul.:lm margin=1.


.********************************************************************
:h3 res=12280 name=PANEL_TE_CTRL_QUIT.Titeleditor verlassen
:i2 REFID=INDEX_TITLEEDITOR.verlassen
:p.:lines align=center.:hp7.Befehl&colon. Titeleditor verlassen:ehp7.:elines.
:p.Dieser Befehl beendet den Titeleditor. �nderungen werden automatisch
gespeichert.
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit dem Knopf :hp7.V:ehp7.:hp2.erlassen:ehp2.
:li.Mit der :link reftype=hd res=12300.Tastenkombination:elink. :hp2.Strg+Q:ehp2.
:eul.:lm margin=1.

.********************************************************************
:h2 res=12300 name=PANEL_TE_KEYBOARD.Tastatur- und Mausbefehle
:i2 REFID=INDEX_TITLEEDITOR.Tastatur- und Mausbefehle
:i2 REFID=INDEX_KEYBOARD.Befehle im Titeleditor
:i2 REFID=INDEX_MOUSE.Befehle im Titeleditor
:p.:lines align=center.:hp7.Tastaturbefehle im Titeleditor:ehp7.:elines.
:dl break=fit tsize=15.
:dthd.:hp3.Taste:ehp3.
:ddhd.:hp3.Befehl:ehp3.
:dt.:hp2.Strg+I:ehp2.
:dd.F�hrt den :link reftype=hd res=12261.Infofenster anzeigen:elink. Befehl aus
:dt.:hp2.Strg+L:ehp2.
:dd.F�hrt den :link reftype=hd res=12260.CD Bibliothek:elink. Befehl oder den
:link reftype=hd res=12270.Ausgew�hlte CD bearbeiten:elink. Befehl aus
:dt.:hp2.Strg+P:ehp2.
:dd.F�hrt den :link reftype=hd res=12262.Programm bearbeiten:elink. Befehl aus
:dt.:hp2.Strg+Q:ehp2.
:dd.F�hrt den :link reftype=hd res=12280.Titeleditor verlassen:elink. Befehl aus
:edl.
:p.Wenn Sie sich im Eingabefeld f�r den Spurtitel befinden,
k�nnen Sie auch mit folgenden Tasten arbeiten&colon.
:dl break=fit tsize=15.
:dt.:hp2.Eingabe:ehp2.
:dd.Springt zur n�chsten Spur oder zur ersten Spur, falls Sie die letzte
Spur bearbeiten.
:dt.:hp2.&darrow.:ehp2.
:dd.Springt zur n�chsten Spur.
:dt.:hp2.&uarrow.:ehp2.
:dd.Springt zur vorherigen Spur.
:dt.:hp2.Strg+&darrow.:ehp2.
:dd.Springt zur letzten Spur.
:dt.:hp2.Strg+&uarrow.:ehp2.
:dd.Springt zur ersten Spur.
:edl.
:p.:lines align=center.:hp7.Mausbefehle im Titeleditor:ehp7.:elines.
:p.Im Titeleditor sind keine besonderen Mausbefehle definiert.


.********************************************************************
:h2 res=12400 name=PANEL_TE_MENUS.Men�befehle
:i2 REFID=INDEX_TITLEEDITOR.Men�befehle
:i2 REFID=INDEX_MENU.im Titeleditor
:p.:lines align=center.:hp7.Men�befehle im Titeleditor:ehp7.:elines.
:p.Im Titeleditor sind keine besonderen Men�befehle definiert.

.********************************************************************

.********************************************************************
.********************************************************************
:h1 res=13000 name=PANEL_PLAYLIST.Programmeditor
:i2 REFID=INDEX_WINDOWS.Programmeditor
:i2 REFID=INDEX_PROGRAMEDITOR.�berblick
:i2 REFID=INDEX_PROGRAM.Editor
:p.:lines align=center.:hp7.Der Programmeditor:ehp7.:elines.
:p.Der Programmeditor dient dazu, die Reihenfolge der abzuspielenden
Titel einer CD (das Programm) festzulegen.
.br
Standardm��ig enth�lt das
Programm alle Audiotitel der CD in der Reihenfolge, wie sie auch auf
der CD angeordnet sind. Dieses Programm kann von Ihnen aber f�r jede
CD individuell ge�ndert werden. Die Reihenfolge der Titel kann dabei
v�llig frei gew�hlt werden, und jeder Titel kann auch mehrfach oder
�berhaupt nicht im Programm auftauchen. Die einzigen Einschr�nkungen
f�r das Programm sind, da� es mindestens einen, h�chstens aber 256
Titel enth�lt, und da� das Programms nicht l�nger als 100 Stunden ist.
Diese Bedingungen werden vom Programmeditor automatisch �berwacht.
:p.Der Programmeditor kann vom
:link reftype=hd res=11000.Hauptfenster:elink.
aus mit dem Befehl
:link reftype=hd res=11231.Programmeditor starten:elink.
f�r die eingelegte CD aufgerufen werden. Das vom CD Spieler verwendete
Programm, siehe
":link reftype=hd res=11120.Programmanzeige im Hauptfenster:elink.",
wird aber erst ge�ndert, wenn im Programmeditor der Befehl
:link reftype=hd res=13231.Programm speichern:elink.
ausgef�hrt wird.
.br
Es ist aber auch m�glich, das Programm einer CD aus der
:link reftype=fn refid=library.CD Bibliothek:elink.
des CD Spielers zu �ndern, ohne die CD einzulegen. Dazu wird die CD im
:link reftype=hd res=12000.Titeleditor:elink.
ausgew�hlt und der Programmeditor mit dem Befehl
:link reftype=hd res=12262.Programm bearbeiten:elink.
gestartet.
:p.Mit den
:link reftype=hd res=13100.Anzeigeelementen des Programmeditors:elink.
kann man sich einen �berblick �ber die vorhandenen
:link reftype=hd res=13120.Titel auf der CD:elink.
und das
:link reftype=hd res=13140.momentane gew�hlte Programm:elink.
verschaffen.
.br
Mit der
:link reftype=hd res=13200.Steuerung des Programmeditors:elink.
ist es m�glich, das Programm auf vielf�ltige Art zu ver�ndern.

.********************************************************************
:h2 res=13100 name=PANEL_PE_DISPLAY.Anzeigeelemente
:i2 REFID=INDEX_PROGRAMEDITOR.Anzeigeelemente
:i2 REFID=INDEX_DISPLAY.im Programmeditor
:p.:lines align=center.:hp7.Anzeigen im Programmeditor:ehp7.:elines.
:ul.
:li.:link reftype=hd res=13110.CD Anzeige:elink.
:li.:link reftype=hd res=13120.Titel auf der CD:elink.
:li.:link reftype=hd res=13130.Programmanzeige:elink.
:li.:link reftype=hd res=13140.Titel im Programm:elink.
:eul.:lm margin=1.

.********************************************************************
:h3 res=13110 name=PANEL_PE_DISP_CD.CD Anzeige
:i2 REFID=INDEX_TOTALLENGTH.der CD (im Programmeditor)
:i2 REFID=INDEX_TRACKS.Anzahl auf der CD (im Programmeditor)
:p.:lines align=center.:hp7.CD Anzeige:ehp7.:elines.
:p.In dem Kasten "CD" wird die Gesamtl�nge der CD und die
Gesamtanzahl von Titeln auf der CD angezeigt. Darunter k�nnen
sich auch Nicht-Audiotitel befinden, die nicht ins Programm
�bernommen werden k�nnen.
:note.
Die Darstellung der Gesamtl�nge l��t sich in den
:link reftype=hd res=15000.Einstellungen:elink. unter
:link reftype=hd res=15100.Zeitformat:elink. �ndern.

.********************************************************************
:h3 res=13120 name=PANEL_PE_DISP_CDSELECT.Titel auf der CD
:i2 REFID=INDEX_TITLE.auf der CD ausgew�hlt (im Programmeditor)
:p.:lines align=center.:hp7.Titel auf der CD:ehp7.:elines.
:p.In der linken Auswahlliste werden alle Titel auf der CD angezeigt.
.br
Vor jedem Titel steht die Spurnummer des Titels in Klammern. Die
Spurnummern von Audiotiteln werden in eckigen Klammern angezeigt,
die Spurnummern von Nicht-Audiotiteln werden in runden Klammern angezeigt.
:p.In dieser Auswahlliste k�nnen Titel zum Einf�gen in das Programm
ausgew�hlt werden, siehe
":link reftype=hd res=13210.Titelauswahl auf der CD:elink.",
":link reftype=hd res=13240.Titel am Anfang einf�gen:elink.",
":link reftype=hd res=13241.Titel einf�gen:elink." und
":link reftype=hd res=13242.Titel am Ende einf�gen:elink.".

.********************************************************************
:h3 res=13130 name=PANEL_PE_DISP_PROGRAM.Programmanzeige
:i2 REFID=INDEX_TOTALLENGTH.des Programms (im Programmeditor)
:i2 REFID=INDEX_TRACKS.Anzahl im Programm (im Programmeditor)
:p.:lines align=center.:hp7.Programmanzeige:ehp7.:elines.
:p.In dem Kasten "Programm" wird die Gesamtl�nge des momentanen Programms
und die Gesamtanzahl von Titeln im Programm angezeigt.
:note.
Die Darstellung der Gesamtl�nge l��t sich in den
:link reftype=hd res=15000.Einstellungen:elink. unter
:link reftype=hd res=15100.Zeitformat:elink. �ndern.

.********************************************************************
:h3 res=13140 name=PANEL_PE_DISP_PROGRAMSELECT.Titel im Programm
:i2 REFID=INDEX_TITLE.aus dem Programm ausgew�hlt (im Programmeditor)
:i2 REFID=INDEX_PROGRAM.ausgew�hlte Titel (im Programmeditor)
:p.:lines align=center.:hp7.Titel im Programm:ehp7.:elines.
:p.In der rechten Auswahlliste werden alle Titel im Programm angezeigt.
:p.In dieser Auswahlliste k�nnen auch Titel zum Entfernen aus dem Programm
ausgew�hlt werden, siehe
":link reftype=hd res=13220.Titelauswahl im Programm:elink.".

.********************************************************************
:h2 res=13200 name=PANEL_PE_CONTROL.Steuerung
:i2 REFID=INDEX_PROGRAMEDITOR.Steuerung
:i2 REFID=INDEX_CONTROL.im Programmeditor
:p.:lines align=center.:hp7.Steuerung im Programmeditor:ehp7.:elines.
:ul.
:li.:link reftype=hd res=13210.Titelauswahl auf der CD:elink.
:li.:link reftype=hd res=13220.Titelauswahl im Programm:elink.
:li.:link reftype=hd res=13230.Infofenster anzeigen:elink.
:li.:link reftype=hd res=13231.Programm speichern:elink.
:li.:link reftype=hd res=13232.Programmeditor verlassen:elink.
:li.:link reftype=hd res=13240.Titel am Anfang einf�gen:elink.
:li.:link reftype=hd res=13241.Titel einf�gen:elink.
:li.:link reftype=hd res=13242.Titel am Ende einf�egen:elink.
:li.:link reftype=hd res=13243.Titel entfernen:elink.
:li.:link reftype=hd res=13250.Programm mischen:elink.
:li.:link reftype=hd res=13251.Programm umdrehen:elink.
:li.:link reftype=hd res=13252.Standardprogramm w�hlen:elink.
:eul.:lm margin=1.

.********************************************************************
:h3 res=13210 name=PANEL_PE_CTRL_CDSELECT.Titelauswahl auf der CD
:i2 REFID=INDEX_TITLE.auf der CD ausw�hlen (im Programmeditor)
:p.:lines align=center.:hp7.Titelauswahl auf der CD:ehp7.:elines.
:p.In der linken Auswahlliste k�nnen Titel auf der CD ausgew�hlt
werden, um sie in das Programm einzuf�gen. Die Auswahl von
Nicht-Audiotiteln, siehe
":link reftype=hd res=13120.Titel auf der CD:elink.",
ist zwar m�glich, wird aber von den Befehlen
:link reftype=hd res=13240.Titel am Anfang einf�gen:elink.,
:link reftype=hd res=13241.Titel einf�gen:elink. und
:link reftype=hd res=13242.Titel am Ende einf�gen:elink.
ignoriert.

.********************************************************************
:h3 res=13220 name=PANEL_PE_CTRL_PROGRAMSELECT.Titelauswahl im Programm
:i2 REFID=INDEX_TITLE.aus dem Programm ausgew�hlen (im Programmeditor)
:i2 REFID=INDEX_PROGRAM.Titel ausw�hlen (im Programmeditor)
:p.:lines align=center.:hp7.Titelauswahl im Programm:ehp7.:elines.
:p.In der rechten Auswahlliste k�nnen Titel im Programm ausgew�hlt
werden, um sie aus dem Programm zu entfernen, siehe
":link reftype=hd res=13243.Titel entfernen:elink.". Au�erdem bestimmt
der erste ausgew�hlte Titel die Stelle, an der neue Titel mit dem Befehl
:link reftype=hd res=13241.Titel einf�gen:elink. eingef�gt werden.
:note.
Das Aussehen dieser Auswahlliste beim Einf�gen oder L�schen von Titeln
kann unter
:link reftype=hd res=15000.Einstellungen:elink.
:link reftype=hd res=15200.Animation:elink.
mit der Einstellung
:link reftype=hd res=15230.Listenanimation:elink.
beeinflu�t werden.


.********************************************************************
:h3 res=13230 name=PANEL_PE_CTRL_INFO.Infofenster anzeigen
:i2 REFID=INDEX_INFOWINDOW.anzeigen (im Programmeditor)
:p.:lines align=center.:hp7.Befehl&colon. Infofenster anzeigen:ehp7.:elines.
:p.Dieser Befehl zeigt das
:link reftype=hd res=14000.Infofenster:elink.
f�r die CD an, deren Programm bearbeitet wird.
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit dem Knopf :hp7.I:ehp7.:hp2.nfo:ehp2.
:li.Mit der :link reftype=hd res=13300.Tastenkombination:elink. :hp2.Strg+I:ehp2.
:eul.:lm margin=1.

.********************************************************************
:h3 res=13231 name=PANEL_PE_CTRL_SAVE.Programm speichern
:i2 REFID=INDEX_PROGRAM.speichern (im Programmeditor)
:p.:lines align=center.:hp7.Befehl&colon. Programm speichern:ehp7.:elines.
:p.Mit diesem Befehl wird das Programm f�r die CD gespeichert. Wenn es sich
um die momentan eingelegte CD handelt, so �ndert sich auch das Programm im
:link reftype=hd res=11000.Hauptfenster:elink. entsprechend&colon. die
Wiedergabe wird gestoppt und das neue Programm in der
:link reftype=hd res=11120.Programmanzeige Im Hauptfenster:elink.
dargestellt.
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit dem Knopf :hp7.S:ehp7.:hp2.peichern:ehp2.
:li.Mit der :link reftype=hd res=13300.Tastenkombination:elink. :hp2.Strg+S:ehp2.
:eul.:lm margin=1.

.********************************************************************
:h3 res=13232 name=PANEL_PE_CTRL_QUIT.Programmeditor verlassen
:i2 REFID=INDEX_PROGRAMEDITOR.verlassen
:p.:lines align=center.:hp7.Befehl&colon. Programmeditor verlassen:ehp7.:elines.
:p.Mit diesem Befehl wird der
:link reftype=hd res=13000.Programmeditor:elink.
verlassen.
.br
Wenn das Programm ge�ndert aber noch nicht gespeichert wurde, werden Sie
gefragt, ob Sie das ge�nderte
:link reftype=hd res=13231.Programm speichern:elink.
wollen.
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit dem Knopf :hp7.V:ehp7.:hp2.erlassen:ehp2.
:li.Mit der :link reftype=hd res=13300.Tastenkombination:elink. :hp2.Strg+Q:ehp2.
:eul.:lm margin=1.

.********************************************************************
:h3 res=13240 name=PANEL_PE_CTRL_INSERTBEGIN.Titel am Anfang einf�gen
:i2 REFID=INDEX_PROGRAM.Titel am Anfang einf�gen (im Programmeditor)
:i2 REFID=INDEX_TITLE.am Anfang des Programm einf�gen (im Programmeditor)
:p.:lines align=center.:hp7.Befehl&colon. Titel am Anfang einf�gen:ehp7.:elines.
:p.Dieser Befehl f�gt die in der
:link reftype=hd res=13210.Titelauswahl auf der CD:elink.
angew�hlten Titel am Anfang des Programms ein.
:note.
Es werden nur soviel Titel eingef�gt, da� das Programm nicht mehr als 256
Titel enth�lt und nicht l�nger als 100 Stunden wird. K�nnen deshalb nicht
alle ausgew�hlten Titel eingef�gt werden, werden zuerst die Titel am Anfang
der Auswahl eingef�gt.
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit dem Knopf :hp2.Am :ehp2.:hp7.A:ehp7.:hp2.nfang:ehp2.
:li.Mit der :link reftype=hd res=13300.Tastenkombination:elink. :hp2.Strg+Eingabe:ehp2.
:eul.:lm margin=1.

.********************************************************************
:h3 res=13241 name=PANEL_PE_CTRL_INSERT.Titel einf�gen
:i2 REFID=INDEX_PROGRAM.Titel einf�gen (im Programmeditor)
:i2 REFID=INDEX_TITLE.in das Programm einf�gen (im Programmeditor)
:p.:lines align=center.:hp7.Befehl&colon. Titel einf�gen:ehp7.:elines.
:p.Dieser Befehl f�gt die in der
:link reftype=hd res=13210.Titelauswahl auf der CD:elink.
angew�hlten Titel vor dem ersten in der
:link reftype=hd res=13220.Titelauswahl im Programm:elink.
angew�hlten Titel in das Programm ein. Wenn kein Titel in der
:link reftype=hd res=13220.Titelauswahl im Programm:elink.
angew�hlt ist, werden die Titel am Ende des Programms eingef�gt.
:note.
Es werden nur soviel Titel eingef�gt, da� das Programm nicht mehr als 256
Titel enth�lt und nicht l�nger als 100 Stunden wird. K�nnen deshalb nicht
alle ausgew�hlten Titel eingef�gt werden, werden zuerst die Titel am Anfang
der Auswahl eingef�gt.
:ul.
:li.Mit dem Knopf :hp7.E:ehp7.:hp2.inf�gen:ehp2.
:li.Mit der :link reftype=hd res=13300.Taste:elink. :hp2.Einf�gen:ehp2.
:eul.:lm margin=1.

.********************************************************************
:h3 res=13242 name=PANEL_PE_CTRL_INSERTEND.Titel am Ende einf�gen
:i2 REFID=INDEX_PROGRAM.Titel am Ende einf�gen (im Programmeditor)
:i2 REFID=INDEX_TITLE.am Ende des Programm einf�gen (im Programmeditor)
:p.:lines align=center.:hp7.Befehl&colon. Titel am Ende einf�gen:ehp7.:elines.
:p.Dieser Befehl f�gt die in der
:link reftype=hd res=13210.Titelauswahl auf der CD:elink.
angew�hlten Titel am Ende des Programms ein.
:note.
Es werden nur soviel Titel eingef�gt, da� das Programm nicht mehr als 256
Titel enth�lt und nicht l�nger als 100 Stunden wird. K�nnen deshalb nicht
alle ausgew�hlten Titel eingef�gt werden, werden zuerst die Titel am Anfang
der Auswahl eingef�gt.
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit dem Knopf :hp2.Am E:ehp2.:hp7.n:ehp7.:hp2.de:ehp2.
:li.Mit der :link reftype=hd res=13300.Taste:elink. :hp2.Eingabe:ehp2.
:eul.:lm margin=1.

.********************************************************************
:h3 res=13243 name=PANEL_PE_CTRL_DELETE.Titel entfernen
:i2 REFID=INDEX_PROGRAM.Titel entfernen (im Programmeditor)
:i2 REFID=INDEX_TITLE.aus dem Programm entfernen (im Programmeditor)
:p.:lines align=center.:hp7.Befehl&colon. Titel entfernen:ehp7.:elines.
:p.Dieser Befehl entfernt alle in der
:link reftype=hd res=13220.Titelauswahl im Programm:elink.
angew�hlten Titel aus dem Programm.
:note.
Wenn alle Titel des Programms ausgew�hlt sind, werden alle Titel bis
auf den ersten in der Auswahl entfernt, da das Programm mindestens
einem Titel enhalten mu�.
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit dem Knopf :hp2.Ent:ehp2.:hp7.f:ehp7.:hp2.ernen:ehp2.
:li.Mit der :link reftype=hd res=13300.Tastenkombination:elink. :hp2.Strg+D:ehp2.
:li.Mit der :link reftype=hd res=13300.Taste:elink. :hp2.L�schen:ehp2.
:eul.:lm margin=1.

.********************************************************************
:h3 res=13250 name=PANEL_PE_CTRL_SHUFFLE.Programm mischen
:i2 REFID=INDEX_PROGRAM.mischen (im Programmeditor)
:p.:lines align=center.:hp7.Befehl&colon. Programm mischen:ehp7.:elines.
:p.Dieser Befehl mischt alle Titel im Programm in einer zuf�lligen
Reihenfolge.
:link reftype=hd res=13130.Gesamtl�nge und Anzahl der Titel:elink.
werden dadurch nicht ver�ndert.
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit dem Knopf :hp7.M:ehp7.:hp2.ischen:ehp2.
:li.Mit der :link reftype=hd res=13300.Tastenkombination:elink. :hp2.Strg+U:ehp2.
:eul.:lm margin=1.

.********************************************************************
:h3 res=13251 name=PANEL_PE_CTRL_REVERSE.Programm umdrehen
:i2 REFID=INDEX_PROGRAM.umdrehen (im Programmeditor)
:p.:lines align=center.:hp7.Befehl&colon. Program umdrehen:ehp7.:elines.
:p.Dieser Befehl dreht die Reihenfolge der Titel im Programm um.
:link reftype=hd res=13130.Gesamtl�nge und Anzahl der Titel:elink.
werden dadurch nicht ver�ndert.
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit dem Knopf :hp7.U:ehp7.:hp2.mdrehen:ehp2.
:li.Mit der :link reftype=hd res=13300.Tastenkombination:elink. :hp2.Strg+R:ehp2.
:eul.:lm margin=1.

.********************************************************************
:h3 res=13252 name=PANEL_PE_CTRL_STANDARD.Standardprogramm w�hlen
:i2 REFID=INDEX_PROGRAM.Standardprogramm (im Programmeditor)
:p.:lines align=center.:hp7.Befehl&colon. Standardprogramm w�hlen:ehp7.:elines.
:p.Dieser Befehl stellt das Standardprogramm f�r die CD ein. Das
Standardprogramm besteht aus allen Audiotiteln auf der CD in derselben
Reihenfolge, wie sie auch auf der CD angeordnet sind.
:caution.
Mit der Ausf�hrung dieses Befehls gehen alle individuellen �nderungen am
Programm verloren.
:ecaution.
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit dem Knopf :hp2.S:ehp2.:hp7.t:ehp7.:hp2.andard:ehp2.
:li.Mit der :link reftype=hd res=13300.Tastenkombination:elink. :hp2.Strg+T:ehp2.
:eul.:lm margin=1.

.********************************************************************
:h2 res=13300 name=PANEL_PE_KEYBOARD.Tastatur- und Mausbefehle
:i2 REFID=INDEX_PROGRAMEDITOR.Tastatur- und Mausbefehle
:i2 REFID=INDEX_KEYBOARD.Befehle im Programmeditor
:i2 REFID=INDEX_MOUSE.Befehle im Programmeditor
:p.:lines align=center.:hp7.Tastaturbefehle im Programmeditor:ehp7.:elines.
:dl break=fit tsize=15.
:dthd.:hp3.Taste:ehp3.
:ddhd.:hp3.Befehl:ehp3.
:dt.:hp2.Einf�gen:ehp2.
:dd.F�hrt den :link reftype=hd res=13241.Titel einf�gen:elink. Befehl aus
:dt.:hp2.Eingabe:ehp2.
:dd.F�hrt den :link reftype=hd res=13242.Titel am Ende einf�gen:elink. Befehl aus
:dt.:hp2.Strg+Eingabe:ehp2.
:dd.F�hrt den :link reftype=hd res=13240.Titel am Anfang einf�gen:elink. Befehl aus
:dt.:hp2.L�schen:ehp2.
:dd.F�hrt den :link reftype=hd res=13243.Titel entfernen:elink. Befehl aus
:dt.:hp2.Strg+D:ehp2.
:dd.F�hrt den :link reftype=hd res=13243.Titel entfernen:elink. Befehl aus
:dt.:hp2.Strg+I:ehp2.
:dd.F�hrt den :link reftype=hd res=13230.Infofenster anzeigen:elink. Befehl aus
:dt.:hp2.Strg+Q:ehp2.
:dd.F�hrt den :link reftype=hd res=13232.Programmeditor verlassen:elink. Befehl aus
:dt.:hp2.Strg+R:ehp2.
:dd.F�hrt den :link reftype=hd res=13251.Program umdrehen:elink. Befehl aus
:dt.:hp2.Strg+S:ehp2.
:dd.F�hrt den :link reftype=hd res=13231.Program speichern:elink. Befehl aus
:dt.:hp2.Strg+T:ehp2.
:dd.F�hrt den :link reftype=hd res=13252.Standardprogramm w�hlen:elink. Befehl aus
:dt.:hp2.Strg+U:ehp2.
:dd.F�hrt den :link reftype=hd res=13250.Programm mischen:elink. Befehl aus
:edl.

:p.:lines align=center.:hp7.Mausbefehle im Programmeditor:ehp7.:elines.
:p.Im Programmeditor sind keine besonderen Men�befehle definiert.

.********************************************************************
:h2 res=13400 name=PANEL_PE_MENUS.Men�befehle
:i2 REFID=INDEX_PROGRAMEDITOR.Men�befehle
:i2 REFID=INDEX_MENU.im Programmeditor
:p.:lines align=center.:hp7.Men�befehle im Programmeditor:ehp7.:elines.
:p.Im Programmeditor sind keine besonderen Men�befehle definiert.

.********************************************************************

.********************************************************************
.********************************************************************
:h1 res=14000 name=PANEL_INFO.Infofenster
:i2 REFID=INDEX_WINDOWS.Infofenster
:i2 REFID=INDEX_INFOWINDOW.�berblick
:i2 REFID=INDEX_CD.Infofenster anzeigen
:p.:lines align=center.:hp7.Das Infofenster:ehp7.:elines.
:p.Das Infofenster gibt Ihnen genauere Informationen �ber eine CD.
:p.F�r die eingelegte CD zeigen Sie das Infofenster mit dem Befehl
:link reftype=hd res=11233.Infofenster anzeigen:elink. im
:link reftype=hd res=11000.Hauptfenster:elink. auf.
Es ist aber auch m�glich, das Infofenster f�r eine CD aus der
:link reftype=fn refid=library.CD Bibliothek:elink.
des CD Spielers aufzurufen, ohne die CD einzulegen. Dazu wird die CD im
:link reftype=hd res=12000.Titeleditor:elink.
ausgew�hlt und das Infofenster mit dem Befehl
:link reftype=hd res=12261.Infofenster anzeigen:elink.
angezeigt. Auch im
:link reftype=hd res=13000.Programmeditor:elink.
ist es m�glich das Infofenster f�r die CD, deren Programm gerade
bearbeitet wird, anzuzeigen. Benutzen Sie dazu den Befehl
:link reftype=hd res=13230.Infofenster anzeigen:elink. im
:link reftype=hd res=13000.Programmeditor:elink..

.********************************************************************
:h2 res=14100 name=PANEL_IN_DISPLAY.Anzeigeelemente
:i2 REFID=INDEX_INFOWINDOW.Anzeigeelemente
:i2 REFID=INDEX_DISPLAY.im Infofenster
:p.:lines align=center.:hp7.Die Anzeigen im Infofenster:ehp7.:elines.
:ul.
:li.:link reftype=hd res=14110.Gesamtl�nge der CD:elink.
:li.:link reftype=hd res=14111.Startposition der CD:elink.
:li.:link reftype=hd res=14112.Spuren insgesamt:elink.
:li.:link reftype=hd res=14120.UPC:elink.
:li.:link reftype=hd res=14121.MMPM ID:elink.
:li.:link reftype=hd res=14122.Interne ID:elink.
:li.:link reftype=hd res=14130.Spurnummer:elink.
:li.:link reftype=hd res=14131.Audiospur:elink.
:li.:link reftype=hd res=14132.Kopieren erlaubt:elink.
:li.:link reftype=hd res=14133.Preemphasis:elink.
:li.:link reftype=hd res=14134.Kan�le:elink.
:li.:link reftype=hd res=14135.Startposition der Spur:elink.
:li.:link reftype=hd res=14136.L�nge der Spur:elink.
:eul.:lm margin=1.

.********************************************************************
:h3 res=14110 name=PANEL_IN_DISP_LENGTHCD.Gesamtl�nge der CD
:i2 REFID=INDEX_TOTALLENGTH.der CD (im Infofenster)
:i2 REFID=INDEX_CD.Gesamtl�nge (im Infofenster)
:p.:lines align=center.:hp7.Gesamtl�nge der CD:ehp7.:elines.
:p.Rechts oben neben der Ausschrift "L�nge" wird die Gesamtl�nge der CD
angezeigt. Darunter k�nnen sich auch Nicht-Audiotitel befinden,
die vom CD Spieler nicht abgespielt werden k�nnen.
:note.
Die Darstellung der Gesamtl�nge l��t sich in den
:link reftype=hd res=15000.Einstellungen:elink. unter
:link reftype=hd res=15100.Zeitformat:elink. ver�ndern.

.********************************************************************
:h3 res=14111 name=PANEL_IN_DISP_STARTCD.Startposition der CD
:i2 REFID=INDEX_CD.Startposition (im Infofenster)
:i2 REFID=INDEX_STARTPOSITION.der CD (im Infofenster)
:p.:lines align=center.:hp7.Startposition der CD:ehp7.:elines.
:p.Rechts oben neben der Ausschrift "Start" wird die Startposition
der ersten Audiospur auf der CD angezeigt. Der Bereich vor dieser Position
kann vom CD Spieler nicht abgespielt werden.
:note.
Die Darstellung der Startposition l��t sich in den
:link reftype=hd res=15000.Einstellungen:elink. unter
:link reftype=hd res=15100.Zeitformat:elink. ver�ndern.

.********************************************************************
:h3 res=14112 name=PANEL_IN_DISP_TRACKS.Spuren insgesamt
:i2 REFID=INDEX_TRACKS.Anzahl auf der CD (im Infofenster)
:i2 REFID=INDEX_CD.Spuren insgesamt (im Infofenster)
:p.:lines align=center.:hp7.Spuren insgesamt:ehp7.:elines.
:p.Rechts oben neben der Ausschrift "Spuren" wird die Gesamtanzahl
der Spuren auf der CD angezeigt. Darunter k�nnen sich auch
Nicht-Audiotitel befinden, die vom CD Spieler nicht abgespielt
werden k�nnen.

.********************************************************************
:h3 res=14120 name=PANEL_IN_DISP_UPC.UPC
:i1 ID=INDEX_UPC.UPC
:i2 REFID=INDEX_CD.UPC (im Infofenster)
:p.:lines align=center.:hp7.UPC der CD:ehp7.:elines.
:p.Die :link reftype=fn refid=upc.UPC:elink. besteht aus 16
Dezimalziffern.

.********************************************************************
:h3 res=14121 name=PANEL_IN_DISP_MMPMID.MMPM ID
:i2 REFID=INDEX_ID.von MMPM
:i2 REFID=INDEX_CD.ID von MMPM (im Infofenster)
:p.:lines align=center.:hp7.MMPM ID der CD:ehp7.:elines.
:p.Die Multimediaerweiterung von OS/2 vergibt an jede Audio CD eine ID.
Diese ID besteht aus 16 Hexdezimalziffern.
:note.
Da diese ID nicht unbedingt eindeutig ist, wird sie vom CD Spieler nicht
verwendet.

.********************************************************************
:h3 res=14122 name=PANEL_IN_DISP_INTERNALID.Interne ID
:i2 REFID=INDEX_ID.interne
:i2 REFID=INDEX_CD.interne ID (im Infofenster)
:p.:lines align=center.:hp7.Interne ID der CD:ehp7.:elines.
:p.Der CD Spieler erzeugt f�r jede CD eine interne ID, die zur Verwaltung der
:link reftype=fn refid=library.CD Bibliothek:elink. verwendet wird, siehe auch
":link reftype=hd res=12000.Titeleditor:elink.".
:note.
Diese ID ist f�r jede CD eindeutig. Nur zwei CD's, f�r die die im
:link reftype=hd res=14000.Infofenster:elink.
angezeigten Informationen vollkommen identisch sind, bekommen auch dieselbe ID.
In diesem (allerdings sehr unwahrscheinlichen) Fall ist es f�r den CD
Spieler nicht m�glich, die beiden CD's zu unterscheiden.

.********************************************************************
:h3 res=14130 name=PANEL_IN_DISP_TRACKNUMBER.Spurnummer
:i2 REFID=INDEX_TRACK.Nummer (im Infofenster)
:i2 REFID=INDEX_NUMBER.der Spur (im Infofenster)
:p.:lines align=center.:hp7.Spurnummer:ehp7.:elines.
:p.Die Spurnummer der angezeigten Spur.
:note.
Die Spuren auf einer CD werden von 1 an fortlaufend durchnummeriert. Eine
CD kann maximal 99 Spuren enthalten.

.********************************************************************
:h3 res=14131 name=PANEL_IN_DISP_AUDIOTRACK.Audiospur
:i1 ID=INDEX_AUDIOTRACK.Audiospur
:i2 REFID=INDEX_TRACK.Audiospur (im Infofenster)
:p.:lines align=center.:hp7.Audiospur:ehp7.:elines.
:p.Diese Box ist bei Spuren, die Audioinformationen enthalten
angekreuzt. Nur diese Spuren k�nnen vom CD Spieler abgespielt werden.

.********************************************************************
:h3 res=14132 name=PANEL_IN_DISP_COPYALLOWED.Kopieren erlaubt
:i1 ID=INDEX_COPY.Kopieren erlaubt
:i2 REFID=INDEX_TRACK.Kopieren erlaubt (im Infofenster)
:p.:lines align=center.:hp7.Kopieren der Spur erlaubt:ehp7.:elines.
:p.Diese Box ist bei Spuren angekreuzt, deren digitale Informationen
ohne Verletzung des Urheberrechts kopiert werden d�rfen.

.********************************************************************
:h3 res=14133 name=PANEL_IN_DISP_PREEMPHASIS.Preemphasis
:i1 ID=INDEX_PREEMPHASIS.Preemphasis
:i2 REFID=INDEX_TRACK.Preemphasis (im Infofenster)
:p.:lines align=center.:hp7.Preemphasis der Spur:ehp7.:elines.
:p.Diese Box ist nur bei Spuren angekreuzt, die mit
:link reftype=fn refid=preemphasis.Preemphasis:elink.
aufgenommen wurden.

.********************************************************************
:h3 res=14134 name=PANEL_IN_DISP_CHANNELS.Kan�le
:i2 REFID=INDEX_TRACK.Kan�le (im Infofenster)
:i2 REFID=INDEX_CHANNELS.Anzahl (im Infofenster)
:p.:lines align=center.:hp7.Kan�le der Spur:ehp7.:elines.
:p.Dieser Wert gibt die Anzahl der Audiokan�le einer Spur an. Bei
Audiospuren sind dies normalerweise 2, bei anderen Spuren 0.

.********************************************************************
:h3 res=14135 name=PANEL_IN_DISP_STARTTRACK.Startposition der Spur
:i2 REFID=INDEX_TRACK.Startposition (im Infofenster)
:i2 REFID=INDEX_STARTPOSITION.der Spur (im Infofenster)
:p.:lines align=center.:hp7.Startposition der Spur:ehp7.:elines.
:p.Dieser Wert gibt die Startposition der Spur auf der CD an.
:note.
Die Darstellung der Startposition l��t sich in den
:link reftype=hd res=15000.Einstellungen:elink. unter
:link reftype=hd res=15100.Zeitformat:elink. ver�ndern.

.********************************************************************
:h3 res=14136 name=PANEL_IN_DISP_LENGTHTRACK.L�nge der Spur
:i2 REFID=INDEX_TRACK.L�nge (im Infofenster)
:i2 REFID=INDEX_LENGTH.der Spur (im Infofenster)
:p.:lines align=center.:hp7.L�nge der Spur:ehp7.:elines.
:p.Dieser Wert gibt die L�nge der Spur an.
:note.
Die Darstellung der L�nge l��t sich in den
:link reftype=hd res=15000.Einstellungen:elink. unter
:link reftype=hd res=15100.Zeitformat:elink. ver�ndern.

.********************************************************************
:h2 res=14200 name=PANEL_IN_CONTROL.Steuerung
:i2 REFID=INDEX_INFOWINDOW.Steuerung
:i2 REFID=INDEX_CONTROL.im Infofenster
:p.:lines align=center.:hp7.Steuerung im Infofenster:ehp7.:elines.
:ul.
:li.:link reftype=hd res=14210.Spuranzeige verschieben:elink.
:li.:link reftype=hd res=14220.Infofenster verlassen:elink.
:eul.:lm margin=1.

.********************************************************************
:h3 res=14210 name=PANEL_IN_CTRL_SCROLLBAR.Spuranzeige verschieben
:i2 REFID=INDEX_TRACK.Anzeige verschieben (im Infofenster)
:p.:lines align=center.:hp7.Spuranzeige verschieben:ehp7.:elines.
:p.Wenn die Informationen f�r alle Spuren nicht gleichzeitig angezeigt
werden k�nnen, k�nnen Sie mit dem Schiebebalken rechts neben den
Spurinformationen den Bereich der sichtbaren Spuren verschieben.

.********************************************************************
:h3 res=14220 name=PANEL_IN_CTRL_QUIT.Infofenster verlassen
:i2 REFID=INDEX_INFOWINDOW.verlassen
:p.:lines align=center.:hp7.Infofenster verlassen:ehp7.:elines.
:p.Mit diesem Befehl verlassen Sie das Infofenster.
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit dem Knopf :hp7.V:ehp7.:hp2.erlassen:ehp2.
:li.Mit der :link reftype=hd res=14300.Taste:elink. :hp2.Eingabe:ehp2.
:li.Mit der :link reftype=hd res=14300.Taste:elink. :hp2.Abbrechen:ehp2.
:li.Mit der :link reftype=hd res=14300.Tastenkombination:elink. :hp2.Strg+Q:ehp2.
:eul.:lm margin=1.

.********************************************************************
:h2 res=14300 name=PANEL_IN_KEYBOARD.Tastatur- und Mausbefehle
:i2 REFID=INDEX_INFOWINDOW.Tastatur- und Mausbefehle
:i2 REFID=INDEX_KEYBOARD.Befehle im Infofenster
:i2 REFID=INDEX_MOUSE.Befehle im Infofenster
:p.:lines align=center.:hp7.Tastaturbefehle im Infofenster:ehp7.:elines.
:dl break=fit tsize=15.
:dthd.:hp3.Taste:ehp3.
:ddhd.:hp3.Befehl:ehp3.
:dt.:hp2.Abbrechen:ehp2.
:dd.F�hrt den :link reftype=hd res=14220.Infofenster verlassen:elink. Befehl aus
:dt.:hp2.Eingabe:ehp2.
:dd.F�hrt den :link reftype=hd res=14220.Infofenster verlassen:elink. Befehl aus
:dt.:hp2.Strg+Q:ehp2.
:dd.F�hrt den :link reftype=hd res=14220.Infofenster verlassen:elink. Befehl aus
:edl.
:p.:lines align=center.:hp7.Mausbefehle im Infofenster:ehp7.:elines.
:p.Im Infofenster sind keine besonderen Mausbefehle definiert.

.********************************************************************
:h2 res=14400 name=PANEL_IN_MENUS.Men�befehle
:i2 REFID=INDEX_INFOWINDOW.Men�befehle
:i2 REFID=INDEX_MENU.im Infofenster
:p.:lines align=center.:hp7.Men�befehle im Infofenster:ehp7.:elines.
:p.Im Infofenster sind keine besonderen Men�befehle definiert.

.********************************************************************
.********************************************************************
.********************************************************************
:h1 res=15000 name=PANEL_SETTINGS.Settings
:i2 REFID=INDEX_WINDOWS.Settings
:i2 REFID=INDEX_SETTINGS.Overview
:p.:lines align=center.:hp7.Settings overview:ehp7.:elines.
:p.With the settings you can change view and behaviour of the CD Player.
Each change in the settings is saved automatically and will become instantly 
active. Therefore, it's not necessary (or possible) to explicitly save the 
settings.
.br
The settings are divided in six areas. 
Each area is associated with one page in the settings notebook.
In detail there are the following settings&colon.
:ul.
:li.:link reftype=hd res=15100.Time format:elink.
:li.:link reftype=hd res=15200.Animation:elink.
:li.:link reftype=hd res=15300.Playback:elink.
:li.:link reftype=hd res=15400.Save:elink.
:li.:link reftype=hd res=15500.Output:elink.
:li.:link reftype=hd res=15600.Device:elink.
:eul.:lm margin=1.

.********************************************************************
:h2 res=15100 name=PANEL_SE_TIMEFORMAT.Time format
:i2 REFID=INDEX_SETTINGS.Time format
:i2 REFID=INDEX_TIME.Format
:p.:lines align=center.:hp7.Settings for the time format:ehp7.:elines.
:p.The settings for the time format change the view of the time and
duration displays in various windows of the CD Player.
.br
In detail there are the following settings&colon.
:ul.
:li.:link reftype=hd res=15110.Hours/Minutes/Seconds:elink.
:li.:link reftype=hd res=15120.Minutes/Seconds/Frames:elink.
:li.:link reftype=hd res=15130.Separator:elink.
:li.:link reftype=hd res=15140.Actualisation rate:elink.
:eul.:lm margin=1.

.********************************************************************
:h3 res=15110 name=PANEL_SE_HHMMSS.Hours/Minutes/Seconds
:i2 REFID=INDEX_TIME.Hours/Minutes/Seconds
:p.:lines align=center.:hp7.Hours/Minutes/Seconds:ehp7.:elines.
:p.If this option is selected, all time and duration displays are 
shown in the following format&colon.
:table cols='10 12'.
:row.
:c. :hp5.12:ehp5.&colon.34&colon.56
:c. Hours
:row.
:c. 12:hp5.&colon.:ehp5.34&colon.56
:c. :link reftype=hd res=15130.Separator:elink.
:row.
:c. 12&colon.:hp5.34:ehp5.&colon.56
:c. Minutes
:row.
:c. 12&colon.34:hp5.&colon.:ehp5.56
:c. :link reftype=hd res=15130.Separator:elink.
:row.
:c. 12&colon.34&colon.:hp5.56:ehp5.
:c. Seconds
:etable.

.********************************************************************
:h3 res=15120 name=PANEL_SE_MMSSFF.Minutes/Seconds/Frames
:i2 REFID=INDEX_TIME.Minutes/Seconds/Frames
:p.:lines align=center.:hp7.Minutes/Seconds/Frames:ehp7.:elines.
:p.If this option is selected, all time and duration displays are
shown in the following format&colon.
:table cols='10 12'.
:row.
:c. :hp5.12:ehp5.&colon.34&colon.56
:c. Minutes
:row.
:c. 12:hp5.&colon.:ehp5.34&colon.56
:c. :link reftype=hd res=15130.Separator:elink.
:row.
:c. 12&colon.:hp5.34:ehp5.&colon.56
:c. Seconds
:row.
:c. 12&colon.34:hp5.&colon.:ehp5.56
:c. :link reftype=hd res=15130.Separator:elink.
:row.
:c. 12&colon.34&colon.:hp5.56:ehp5.
:c. :link reftype=fn refid=frames.Frames:elink.
:etable.

.********************************************************************
:h3 res=15130 name=PANEL_SE_TIMESEP.Separator
:i2 REFID=INDEX_TIME.Separator
:i1 ID=INDEX_SEP.Separator
:p.:lines align=center.:hp7.Separator:ehp7.:elines.
:p.The separator divides the components of the time and duration
displays. It must be exactly one character long.
.br
See also
":link reftype=hd res=15110.setting Hours/Minutes/Seconds:elink." und
":link reftype=hd res=15120.setting Minutes/Seconds/Frames:elink.".

.********************************************************************
:h3 res=15140 name=PANEL_SE_TIMEFREQ.Actualisation rate
:i2 REFID=INDEX_TIME.Actualisation rate
:i2 REFID=INDEX_FREQ.of time display
:p.:lines align=center.:hp7.Actualisation rate:ehp7.:elines.
:p.The given actualisation rate determines, how often the
:link reftype=hd res=11110.time:elink. and the
:link reftype=hd res=11140.duration displays in the main window:elink.
become actualised during playback.
.br
If you choose a very high value for the actualisation rate,
it may happen, that the
:link reftype=hd res=11150.title display in the main window:elink.
temporary doesn't match the actual played title.
This has no affect on the
:link reftype=hd res=11200.control:elink. of the CD Player,
because all displays are automatically actualised before a command
is executed.
.br
Choosing a very low value for the actualisation rate can waste up a lot of
processing time and others processes may process slower. Minimizing the 
CD Player will avoid this problem.
.br
Valid values for the actualisation rate lay between 100 and 60000 milliseconds.

.********************************************************************
:h2 res=15200 name=PANEL_SE_ANIMATION.Animation
:i2 REFID=INDEX_SETTINGS.Animation
:p.:lines align=center.:hp7.Animation settings:ehp7.:elines.
:p.The settings for the animation affect the display of the
:link reftype=hd res=11262.playback button:elink.
during playback, see
":link reftype=hd res=11160.playback display in the main window:elink.",
and animation of the selection boxes.
.br
In detail there are the following settings&colon.
:ul.
:li.:link reftype=hd res=15210.Playback animation:elink.
:li.:link reftype=hd res=15230.List animation:elink.
:li.:link reftype=hd res=15220.Animation rate:elink.
:eul.:lm margin=1.

.********************************************************************
:h3 res=15210 name=PANEL_SE_ANIMATION_ONOFF.Playback animation
:i2 REFID=INDEX_ANIMATION.during playback
:p.:lines align=center.:hp7.Playback animation:ehp7.:elines.
:p.If the playback animation is turned on, the arrow on the
:link reftype=hd res=11262.playback button:elink. will turn
around from left to right during playback. The speed of the arrow
can be adjusted with the
:link reftype=hd res=15220.animation rate setting:elink..

.********************************************************************
:h3 res=15230 name=PANEL_SE_LISTBOXANIMATION.List animation
:i2 REFID=INDEX_ANIMATION.of lists
:p.:lines align=center.:hp7.List animation:ehp7.:elines.
:p.If the list animation is turned on, inserting or deleting multiple
entries in a selection box (of the
:link reftype=hd res=13000.program editor:elink.
for example) will be showed each one. Otherwise, the changes will
be displayed all at once.
:caution.
If list animation is turned on, greater changes in selection boxes
(deleting the whole program in the
:link reftype=hd res=13000.program editor:elink. for example) can
take a long time. During this input is blocked.
:ecaution.

.********************************************************************
:h3 res=15220 name=PANEL_SE_ANIMATION_RATE.Animation rate
:i2 REFID=INDEX_ANIMATION.Rate
:p.:lines align=center.:hp7.Animation rate:ehp7.:elines.
:p.The animation rate determines the speed of the arrow on the
:link reftype=hd res=11262.playback button:elink. during playback, if
:link reftype=hd res=15210.playback animation:elink. is turned on.
.br
Valid values for the animation rate lay between 25 and 10000 milliseconds.

.********************************************************************
:h2 res=15300 name=PANEL_SE_PLAY.Wiedergabe
:i2 REFID=INDEX_SETTINGS.Wiedergabe
:i2 REFID=INDEX_CDCONTROL.Einstellungen
:p.:lines align=center.:hp7.Einstellungen Wiedergabe:ehp7.:elines.
:p.Diese Einstellungen �ndern das Verhalten des CD Spielers beim
Erreichen des Programmendes, beim Einlegen einer CD und bei dem Befehl
:link reftype=hd res=11260.Titel zur�ck:elink..
.br
Im einzelnen gibt es folgende Einstellungen&colon.
:ul.
:li.:link reftype=hd res=15310.Automatische Wiederholung:elink.
:li.:link reftype=hd res=15320.Automatischer Start:elink.
:li.:link reftype=hd res=15330.R�cksprunglimit:elink.
:eul.:lm margin=1.

.********************************************************************
:h3 res=15310 name=PANEL_SE_AUTOREPEAT.Automatische Wiederholung
:i2 REFID=INDEX_AUTOREPEAT.einstellen (in den Einstellungen)
:p.:lines align=center.:hp7.Automatische Wiederholung:ehp7.:elines.
:p.Wenn diese Einstellung aktiviert ist, wird die Wiedergabe bei Erreichen des
Programmendes automatisch vom Anfang des Programms an fortgesetzt, bis Sie
von Ihnen unterbrochen wird.
.br
Dieses Verhalten wird normalerweise mit dem Knopf
:link reftype=hd res=11266.Automatische Wiederholung einstellen:elink.
gesteuert, jedoch wird die Einstellung des Knopfes nicht gespeichert,
sondern geht nach dem Beenden des CD Spielers verloren. Beim Neustart
des CD Spieler wird der Knopf dann dieser Einstellung entsprechend
eingestellt.

.********************************************************************
:h3 res=15320 name=PANEL_SE_AUTOSTART.Automatischer Start
:isyn ROOT=autostart.Autostart
:i1 ROOTS='autostart' ID=INDEX_AUTOSTART.Automatischer Start
:i2 REFID=INDEX_CDCONTROL.automatisch starten
:p.:lines align=center.:hp7.Automatischer Start:ehp7.:elines.
:p.Wenn diese Einstellung aktiviert ist, beginnt der CD Spieler
beim Einlegen einer CD automatisch mit der Wiedergabe am
Anfang des f�r die CD gespeicherten Programms oder des Standardprogramms,
falls kein gespeichertes Programm gefunden wurde, siehe auch
":link reftype=hd res=11262.Wiedergabe starten:elink." und
":link reftype=hd res=13000.Programmeditor:elink.".

.********************************************************************
:h3 res=15330 name=PANEL_SE_BACKWARDTHRESHOLD.R�cksprunglimit
:i1 ID=INDEX_BACKWARDLIMIT.R�cksprunglimit
:p.:lines align=center.:hp7.R�cksprunglimit:ehp7.:elines.
:p.Das R�cksprunglimit beeinflusst das Verhalten des Befehls
:link reftype=hd res=11260.Titel zur�ck:elink..
Wenn die Position im momentanen Titel �ber dem hier eingestellten
Wert liegt, wird der CD Spieler an den Anfang des momentanen Titels gesetzt,
anderenfalls an den Anfang des vorherigen Titels im Programm.
.br
Der Wert f�r das R�cksprunglimit wird in Sekunden angegeben. Durch die Angabe
des Werts 0 kann erreicht werden, da� der CD Spieler nur dann auf den
Anfang des vorherigen Titels springt, wenn er sich direkt am Beginn
eines Titels befindet. Durch die Angabe eines sehr hohen Wertes wird erreicht,
da� der CD Spieler immer an den Anfang des vorherigen Titels springt.

.********************************************************************
:h2 res=15400 name=PANEL_SE_SAVE.Speicherung
:i2 REFID=INDEX_SETTINGS.Speicherung
:p.:lines align=center.:hp7.Einstellungen Speicherung:ehp7.:elines.
:p.Die Einstellungen f�r die Speicherung stellen die automatische
Speicherung f�r diverse Werte des CD Spielers ein oder aus.
.br
Im einzelnen gibt es folgende Einstellungen&colon.
:ul.
:li.:link reftype=hd res=15410.Fensterposition:elink.
:li.:link reftype=hd res=15420.Lautst�rke:elink.
:li.:link reftype=hd res=15430.CD Position:elink.
:li.:link reftype=hd res=15430.Marker:elink.
:eul.:lm margin=1.

.********************************************************************
:h3 res=15410 name=PANEL_SE_SAVE_WINDOWS.Fensterposition
:i2 REFID=INDEX_WINDOWS.Automatische Positionsspeicherung
:p.:lines align=center.:hp7.Fensterposition:ehp7.:elines.
:p.Wenn die Speicherung der Fensterpositionen aktiviert ist, werden
Position und Gr��e des
:link reftype=hd res=11000.Hauptfensters:elink., des
:link reftype=hd res=12000.Titeleditors:elink., des
:link reftype=hd res=13000.Programmeditors:elink., des
:link reftype=hd res=14000.Infofensters:elink. und der
:link reftype=hd res=15000.Einstellungen:elink. nach
jeder �nderung gesichert. Einfaches Einstellen dieser Option reicht
nicht aus, um die Fensterpositionen und - gr��en zu sichern. Erst wenn
die Position oder Gr��e eines Fensters nach der Aktivierung dieser Option
ver�ndert wird, werden sie gespeichert.
.br
Unabh�ngig von dieser Einstellung wird beim Start eines Fensters
immer die zuletzt gesicherte Position und Gr��e eingestellt. Das
hei�t Fensterposition und -gr��e werden immer auf den Wert gesetzt,
den sie hatten als die Speicherung der Fensterposition zuletzt
deaktiviert wurde.
:note.
Einige Fenster k�nnen in der Gr��e nicht ver�ndert werden. In
diesem Fall wird nur die Position des Fensters gespeichert.

.********************************************************************
:h3 res=15420 name=PANEL_SE_SAVE_VOLUME.Lautst�rke
:i2 REFID=INDEX_VOLUME.Automatische Speicherung
:p.:lines align=center.:hp7.Lautst�rke:ehp7.:elines.
:p.Wenn die Speicherung der Lautst�rke aktiviert ist, wird die
Lautst�rke nach jeder �nderung gesichert. Siehe auch
":link reftype=hd res=11220.Lautst�rke links einstellen:elink." und
":link reftype=hd res=11221.Lautst�rke rechts einstellen:elink.".
.br
Unabh�ngig von dieser Einstellung wird beim Start des CD Spielers
immer die zuletzt gesicherte Lautst�rke eingestellt. Das hei�t
die Lautst�rke wird immer auf den Wert gestellt, den sie hatte
als die Speicherung der Lautst�rke zuletzt deaktiviert wurde.
:note.
Wenn Ihr CD-ROM Laufwerk das Einstellen der Lautst�rke nicht
unterst�tzt ist diese Einstellung ohne Bedeutung.

.********************************************************************
:h3 res=15430 name=PANEL_SE_SAVE_PLAYLIST.CD Position
:i2 REFID=INDEX_POSITION.Automatische Speicherung
:p.:lines align=center.:hp7.CD Position:ehp7.:elines.
:p.Wenn die Speicherung der CD Position aktiviert ist, wird die
Position auf der CD beim Auswerfen der CD oder beim Verlassen des
CD Spielers gesichert.
Unabh�ngig von dieser Einstellung wird beim Start des CD Spielers
immer die zuletzt gesicherte Position eingestellt. Das hei�t
die Position wird immer auf die Stelle gesetzt, die sie hatte
als die Speicherung der CD Position zuletzt deaktiviert wurde.
:note.
Wenn Sie das Programm der CD im
:link reftype=hd res=13000.Programmeditor:elink. �ndern ohne da�
die CD eingelegt ist, wird die gespeicherte Position gel�scht und
die CD beim n�chsten Einlegen wieder auf die Startposition gesetzt.

.********************************************************************
:h3 res=15440 name=PANEL_SE_SAVE_MARKERS.Marker
:i2 REFID=INDEX_MARKERS.Automatische Speicherung
:p.:lines align=center.:hp7.Marker:ehp7.:elines.
:p.Diese Einstellung ist zur Zeit noch ohne Funktion.

.********************************************************************
:h2 res=15500 name=PANEL_SE_OUTPUT.Ausgabe
:i2 REFID=INDEX_SETTINGS.Ausgabe
:p.:lines align=center.:hp7.Einstellungen Ausgabe:ehp7.:elines.
:p.Die Einstellungen f�r die Ausgabe legen fest, �ber welchen Anschlu�
die Tonausgabe des CD Spielers erfolgt.
.br
Im einzelnen gibt es folgende Einstellungen&colon.
:ul.
:li.:link reftype=hd res=15510.Kopfh�rer:elink.
:li.:link reftype=hd res=15520.Soundkarte:elink.
:li.:link reftype=hd res=15530.Externer Verst�rker:elink.
:eul.:lm margin=1.
:note.
Mindestens ein Anschlu� muss eingestellt sein.

.********************************************************************
:h3 res=15510 name=PANEL_SE_OUTPUT_HEADPHONES.Kopfh�rer
:i1 ID=INDEX_HEADPHONES.Kopfh�rer
:i2 REFID=INDEX_CDCONTROL.am Kopfh�rer
:p.:lines align=center.:hp7.Kopfh�rer:ehp7.:elines.
:p.Wenn diese Einstellung aktiviert ist, erfolgt die Tonausgabe
�ber den angeschlossenen Kopfh�rer.
:note.
Es kann sein, das Ihr CD-ROM Laufwerk diese Einstellung
nicht unterst�tzt. In diesem Fall ist der Schalter deaktiviert.
.br
Die G�ltigkeit dieser Einstellung kann nur bei eingelegter CD
�berpr�ft werden. Wenn Sie die Option ohne eingelegte CD �ndern
und sp�ter eine Fehlermeldung erhalten, deaktivieren sie die
Einstellung.

.********************************************************************
:h3 res=15520 name=PANEL_SE_OUTPUT_SOUNDCARD.Soundkarte
:i1 ID=INDEX_SOUNDCARD.Soundkarte
:i2 REFID=INDEX_CDCONTROL.an der Soundkarte
:p.:lines align=center.:hp7.Soundkarte:ehp7.:elines.
:p.Wenn diese Einstellung aktiviert ist, erfolgt die Tonausgabe
�ber die angeschlossene Soundkarte.
:note.
Es kann sein, das Ihr CD-ROM Laufwerk diese Einstellung
nicht unterst�tzt. In diesem Fall ist der Schalter deaktiviert.
.br
Die G�ltigkeit dieser Einstellung kann nur bei eingelegter CD
�berpr�ft werden. Wenn Sie die Option ohne eingelegte CD �ndern
und sp�ter eine Fehlermeldung erhalten, deaktivieren sie die
Einstellung.
.br
Bei einzelnen Soundkarten kann es zu Problemen bei der Ausgabe kommen
wenn OS/2 versucht, den Ton �ber die Soundkarte wiederzugeben. Wenn Sie
keinen oder nur stark verzerrten Ton h�ren deaktivieren Sie diese
Einstellung.

.********************************************************************
:h3 res=15530 name=PANEL_SE_OUTPUT_AMPLIFIER.Externer Verst�rker
:isyn ROOT=amp.Verst�rker
:i1 ROOTS='amp' ID=INDEX_EXTAMP.Externer Verst�rker
:i2 REFID=INDEX_CDCONTROL.am externen Verst�rker
:p.:lines align=center.:hp7.Externer Verst�rker:ehp7.:elines.
:p.Wenn diese Einstellung aktiviert ist, erfolgt die Tonausgabe
�ber den angeschlossenen externen Verst�rker.
:note.
Es kann sein, das Ihr CD-ROM Laufwerk diese Einstellung
nicht unterst�tzt. In diesem Fall ist der Schalter deaktiviert.
.br
Die G�ltigkeit dieser Einstellung kann nur bei eingelegter CD
�berpr�ft werden. Wenn Sie die Option ohne eingelegte CD �ndern
und sp�ter eine Fehlermeldung erhalten, deaktivieren sie die
Einstellung.


.********************************************************************
:h2 res=15600 name=PANEL_SE_HARDWARE.Ger�t
:i2 REFID=INDEX_SETTINGS.Ger�t
:p.:lines align=center.:hp7.Ger�t:ehp7.:elines.
:p.Mit diesen Einstellungen wird das Verhalten Ihres CD-ROM Laufwerks
beeinflu�t.
.br
Im einzelnen gibt es folgende Einstellungen&colon.
:ul.
:li.:link reftype=hd res=15610.Laufwerk sperren:elink.
:li.:link reftype=hd res=15620.Ger�tename:elink.
:eul.:lm margin=1.

.********************************************************************
:h3 res=15610 name=PANEL_SE_HARDWARE_LOCK.Laufwerk sperren
:i2 REFID=INDEX_DEVICE.sperren
:p.:lines align=center.:hp7.Laufwerk sperren:ehp7.:elines.
:p.Wenn diese Einstellung aktiviert ist, wird der Auswurf des
CD-ROM Laufwerks bei eingelegter CD verriegelt. Die CD kann dann
nur noch �ber den Befehl
:link reftype=hd res=11265.CD auswerfen:elink.
aus dem Laufwerk genommen werden. Andere Programme k�nnen aber die Verriegelung
w�hrend des Betriebs des CD Spielers aufheben.
:note.
Es kann sein, das Ihr CD-ROM Laufwerk diese Einstellung
nicht unterst�tzt. In diesem Fall ist der Schalter deaktiviert.

.********************************************************************
:h3 res=15620 name=PANEL_SE_HARDWARE_NAME.Ger�tename
:i2 REFID=INDEX_DEVICE.Ger�tename
:p.:lines align=center.:hp7.Ger�tename:ehp7.:elines.
:p.Wenn Sie mehrere CD-ROM Laufwerke an Ihren Rechner angeschlossen haben,
k�nnen Sie in dieser Auswahlliste den Namen des CD-ROM Laufwerks ausw�hlen,
das Sie verwenden wollen.

.********************************************************************
:h2 res=15700 name=PANEL_SE_KEYBOARD.Tastatur- und Mausbefehle
:i2 REFID=INDEX_SETTINGS.Tastatur- und Mausbefehle
:i2 REFID=INDEX_KEYBOARD.Befehle in den Einstellungen
:i2 REFID=INDEX_MOUSE.Befehle in den Einstellungen
:p.:lines align=center.:hp7.Tastaturbefehle in den Einstellungen:ehp7.:elines.
:p.In den Einstellungen sind keine besonderen Tastaturbefehle definiert.

:p.:lines align=center.:hp7.Mausbefehle in den Einstellungen:ehp7.:elines.
:p.In den Einstellungen sind keine besonderen Mausbefehle definiert.

.********************************************************************
:h2 res=15800 name=PANEL_SE_MENUS.Men�befehle
:i2 REFID=INDEX_SETTINGS.Men�befehle
:i2 REFID=INDEX_MENU.in den Einstellungen
:p.:lines align=center.:hp7.Men�befehle in den Einstellungen:ehp7.:elines.
:p.In den Einstellungen sind keine besonderen Men�befehle definiert.

.********************************************************************

.********************************************************************
.********************************************************************
:h1 res=16000 name=PANEL_ERRORS.Error messages
:i1 ID=INDEX_ERRORS.Error messages

:h4 res=16001.
:p.:hp8.Error: The CD position advise cannot be activated.:ehp8.
.br
This is a fatal error. The CD Player will be stopped.

:h4 res=16002.
:p.:hp8.Error: The table of contents cannot be read.:ehp8.
.br
Entweder die CD ist fehlerhaft oder es handelt sich nicht um eine Audio CD.
Werfen Sie die CD aus.

:h4 res=16003.
:p.:hp8.Error: The eject order failed.:ehp8.
.br
Versuchen Sie, die CD mit der Auswurftaste am CD-ROM Laufwerk auszuwerden.

:h4 res=16004.
:p.:hp8.Error: The sound cannot be turned off or on.:ehp8.
.br
Eventuell kann der Ton �ber den globalen Lautst�rkeregler
der Multimediaerweiterung von OS/2 oder �ber externe Lautst�rkeregler
an der Soundkarte und am CD-ROM Laufwerk eingestellt werden.

:h4 res=16005.
:p.:hp8.Error: Information about the CD-ROM device cannot be read.:ehp8.
.br
This is a fatal error. The CD Player will be stopped.

:h4 res=16006.
:p.:hp8.Error: The CD-ROM device isn't responding.:ehp8.
.br
This is a fatal error. The CD Player will be stopped.

:h4 res=16007.
:p.:hp8.Error: The pause order failed.:ehp8.
.br
Die CD k�nnte defekt sein. Vermeiden Sie die Stelle auf der CD, an der der
PAUSE-Befehl nicht durchgef�hrt werden konnte.

:h4 res=16008.
:p.:hp8.Error: The play order failed.:ehp8.
.br
Die CD k�nnte defekt sein. Vermeiden Sie die Stelle auf der CD, an der der
PLAY-Befehl nicht durchgef�hrt werden konnte.

:h4 res=16009.
:p.:hp8.Error: The current position of the CD cannot be read.:ehp8.
.br
Die CD k�nnte defekt sein. Vermeiden Sie die momentane Stelle auf der CD.

:h4 res=16010.
:p.:hp8.Error: The output connection isn't available.:ehp8.
.br
Der von Ihnen gew�hlte Ausgabeanschlu� ist in der momentanen
Konfiguration nicht verf�gbar.

:h4 res=16011.
:p.:hp8.Error: The resume order failed.:ehp8.
.br
Die CD k�nnte defekt sein. Vermeiden Sie die Stelle auf der CD, an der der
RESUME-Befehl nicht durchgef�hrt werden konnte.

:h4 res=16012.
:p.:hp8.Error: The volume cannot be changed.:ehp8.
.br
Eventuell kann die Lautst�rke �ber den globalen Lautst�rkeregler
der Multimediaerweiterung von OS/2 oder �ber externe Lautst�rkeregler
an der Soundkarte und am CD-ROM Laufwerk eingestellt werden.

:h4 res=16013.
:p.:hp8.Error: The stop order failed.:ehp8.
.br
This is a fatal error. The CD Player will be stopped.

:h4 res=16014.
:p.:hp8.Error: The help file couldn't be opened. No online-help is available.:ehp8.
.br
Die Hilfedatei 'CDPLAYER.HLP' mu� sich im selben Verzeichnis wie das CD Spieler
Programm 'CDPLAYER.EXE' befinden.

:h4 res=16015.
:p.:hp8.Error: The INI-file couldn't be opened or created.:ehp8.
.br
Beim Versuch, die INI-Datei 'CDPLAYER.INI' zu �ffnen oder neu zu erstellen, ist
ein Dateifehler aufgetreten.
This is a fatal error. The CD Player will be stopped.

:h4 res=16016.
:p.:hp8.Error: The INI-file couldn't be actualised. Your changes will no be saved.:ehp8.
.br
Beim Versuch, die INI-Datei 'CDPLAYER.INI' zu beschreiben, ist
ein Dateifehler aufgetreten.

:h4 res=16017.
:p.:hp8.Error: The timer couldn't be activated.:ehp8.
.br
This is a fatal error. The CD Player will be stopped.

:h4 res=16018.
:p.:hp8.Error: The CD-ROM device cannot play audio CD's.:ehp8.
.br
This is a fatal error. The CD Player will be stopped.

.********************************************************************
.********************************************************************
.********************************************************************
:h1 hide res=17000 name=PANEL_OTHERS.Sonstiges

.********************************************************************
:h1 hide res=17100 name=PANEL_ABOUT.�ber
:p.Dr�cken Sie :hp2.OK:ehp2., um zum CD Spieler zur�ckzukehren.

.********************************************************************
:h1 hide res=17200 name=PANEL_AREYOUSURE.Sind Sie sicher?
:p.Wenn Sie sicher sind, da� Sie die ausgew�hlte CD aus der
:link reftype=fn refid=library.CD Bibliothek:elink.
l�schen wollen, dr�cken Sie den :hp2.OK:ehp2. Knopf,
ansonsten den :hp2.Abbrechen:ehp2. Knopf.
:caution.
Mit dem L�schen der CD gehen auch alle gespeicherten Titel, Informationen
und das gespeicherte Programm verloren!
:ecaution.

.********************************************************************
:h1 hide res=17300 name=PANEL_YESORNO.Ja oder nein?
:p.Das momentane Programm im
:link reftype=hd res=13000.Programmeditor:elink.
ist noch nicht gespeichert.
:sl.
:li.Wenn Sie das momentane Programm speichern wollen, bevor Sie das Programm
der eingelegten CD bearbeiten, dr�cken Sie den :hp2.Ja:ehp2. Knopf.
:li.Wenn Sie das momentane Programm nicht speichern wollen,
dr�cken Sie den :hp2.Nein:ehp2. Knopf.
:li.Wenn Sie das momentane Programm bebehalten wollen und das Programm der
eingelegten CD nicht bearbeiten wollen,
dr�cken Sie den :hp2.Abbrechen:ehp2. Knopf.
:esl.

.********************************************************************
.*                                                                  *
.* Hier sind alle 1-Level Indexeintr�ge abgelegt, die weitere Unter *
.* eintr�ge enthalten.                                              *
.*                                                                  *
.********************************************************************
:h1 hide res=17400 name=PANEL_INDEXSELECT.Indexauswahl
:i1 ID=INDEX_FREQ.Aktualisierung
:i1 ID=INDEX_ANIMATION.Animation
:i1 ID=INDEX_DISPLAY.Anzeigeelemente
.* :i1 ID=INDEX_OUTPUT.Ausgabe
:isyn ROOT=autorepeat.Autowiederholung
:i1 ROOTS='autorepeat' ID=INDEX_AUTOREPEAT.Automatische Wiederholung
:i1 ID=INDEX_LIBRARY.Bibliothek
:i1 ID=INDEX_CD.CD
:i1 ID=INDEX_COPYRIGHT.Copyright
:isyn ROOT=setting.Einstellung
:i1 ROOTS='setting' ID=INDEX_SETTINGS.Einstellungen
:i1 ID=INDEX_WINDOWS.Fenster
:i1 ID=INDEX_DEVICE.Ger�t
:i1 ID=INDEX_TOTALLENGTH.Gesamtl�nge
:i1 ID=INDEX_MAINWINDOW.Hauptfenster
:i1 ID=INDEX_ID.ID
:isyn ROOT=info.Info
:i1 ROOTS='info' ID=INDEX_INFOWINDOW.Infofenster
:isyn ROOT=channel.Kanal
:i1 ROOTS='channel' ID=INDEX_CHANNELS.Kan�le
:i1 ID=INDEX_LENGTH.L�nge
:i1 ID=INDEX_VOLUME.Lautst�rke
:i1 ID=INDEX_MARKERS.Marker
:i1 ID=INDEX_MOUSE.Maus
:isyn ROOT=menus.Men�s
:isyn ROOT=menu.Men�
:i1 ROOTS='menus menu' ID=INDEX_MENU.Men�befehle
:isyn ROOT=name.Name
:i1 ROOTS='name' ID=INDEX_NAMES.Namen
:i1 ID=INDEX_NUMBER.Nummer
:i1 ID=INDEX_POSITION.Position
:i1 ID=INDEX_POPUPMENU.Popupmen�
:i1 ID=INDEX_PROGRAM.Programm
:i1 ID=INDEX_PROGRAMEDITOR.Programmeditor
:isyn ROOT=tracks.Spuren
:i1 ROOTS='tracks' ID=INDEX_TRACK.Spur
:isyn ROOT=standard.Standard
:i1 ROOTS='standard' ID=INDEX_STANDARD.Standardprogram
:i1 ID=INDEX_STARTPOSITION.Startposition
:i1 ID=INDEX_CONTROL.Steuerung
:i1 ID=INDEX_SYSMENU.Systemmen�
:isyn ROOT=keyboard.Tastatur
:i1 ROOTS='keyboard' ID=INDEX_KEYBOARD.Tastaturbefehle
:i1 ID=INDEX_TITLE.Titel
:i1 ID=INDEX_TITLEEDITOR.Titeleditor
:i1 ID=INDEX_SOUND.Ton
:i1 ID=INDEX_CDCONTROL.Wiedergabe
:i1 ID=INDEX_TIME.Zeit
:isyn ROOT=additional.Zus�tzlich
:i1 ROOTS='additional' ID=INDEX_ADDINFO.Zus�tzl. Information

:artwork align=center name='D:\C\CDPLAYER\HLPINF\ICONINFO.BMP'.
:p.Wird unter dem ausgew�hlten Begriff eine Liste mit Begriffen angezeigt,
stehen nur f�r diese Begriffe Hilfetexte zur Verf�gung. Wenn in dem
ausgew�hlten Begriff auf einen anderen Begriff verwiesen wird, kann nur
f�r diesen Begriff ein Hilfetext aufgerufen werden.

.********************************************************************

.********************************************************************
.********************************************************************
:h1 res=18000 name=PANEL_COPYRIGHT.Copyright
:lines align=left.
Copyright (c) Michael Bock 1993-94
All rights reserved.
:elines.

:p.:lines align=center.:hp7.Important notice:ehp7.:elines.
:p.The author disclaims all warranties as to this software, whether
expressed or implied, including without limitation any implied warranties
of merchantability, fitness for a particular purpose, functionality,
data integrity or protection, in so far as permitted by applicable
legislation.

:p.All trademarks are property of their respective owners and appear for
identification purposes only.

:p.:lines align=center.:hp7.Shareware:ehp7.:elines.

:p.Writing this program has taken lots of work. If you continue
using it after a reasonable trial period of 30 days, you have
to pay a small fee to the author.

:p.:hp2.SHAREWARE:ehp2. is :hp2.NOT FREE SOFTWARE:ehp2..
You can, however, test shareware before purchasing it.
You are encouraged to copy and pass on the unregistered shareware
version of this program, if
:ul.
:li.the program is distributed in its original form (complete, unmodified, uninstalled)
:li.the distribution fee does not exceed the equivalent of DM 15.-.
:eul.:lm margin=1.

:p.It is forbidden to distribute the program
:ul.
:li.on cdrom
:li.bundled with books, magazines, etc. (including "bookware").
:eul.:lm margin=1.

:p.:lines align=center.:hp7.Registration:ehp7.:elines.

:p.If you want to continue using the CD Player after 30 days, you have to register.

:p.The registrated version contains no shareware reference. There are no
other limitations in the shareware version.

:p.See ":link reftype=hd res=19000.REGISTER.TXT:elink."
for the registration fee valid for your
country (DM 30.- to DM 50.- depending on the country).

:p.Inquire for more than 2 licenses or for hardware bundling!

:p.Send DM Eurocheques or bank notes to the following address&colon.

:lines align=left.
Michael Bock
Winkler Str. 28
14193 Berlin
Germany
:elines.

:p.Please allow a maximum of 6 weeks for delivery.

:p.Please use the form
":link reftype=hd res=19000.REGISTER.TXT:elink."
included with this program. 

:p.The CD Player is not shipped on disks. Instead, you get an registration
key and a description how to make your shareware version a registrated
version.

:p.:lines align=center.:hp7.Upgrades:ehp7.:elines.

:p.If the user has a modem, upgrades are free. Other registered users
only have to pay the fee of their shareware vendor (usually DM 5).

:p.However, upgrades will cost DM 10 to DM 20, if there are major
enhancements to the program.

:p.01-27-1994

.********************************************************************
:h1 res=19000 name=PANEL_REGISTER.REGISTER.TXT
:p.:lines align=center.:hp7.REGISTER.TXT:ehp7.:elines.
:p.To print the two pages, select them and use 'print' in the menu of the help
window.
:ul.
:li.:link reftype=hd res=19100.Page 1:elink.
:li.:link reftype=hd res=19200.Page 2:elink.
:eul.:lm margin=1.

.********************************************************************
:h2 res=19100 name=PANEL_REG1.CD Player order form - Page 1
:font facename=Courier size=10x10.
:fig.



    ���������������������������������������������Ŀ
    �                                             �
    �                                             �
    �                                             �
    �         Michael Bock                        �
    �         Winkler Str. 28                     �
    �                                             �
    �         14193 Berlin                        �
    �                                             �
    �         Germany                             �
    �                                             �
    �                                             �
    �����������������������������������������������

    Send to&colon.     Name/Company&colon.  _______________________________________
    ��������
                 Address&colon.       _______________________________________

                                _______________________________________

                 Country&colon.       _______________________________________

                 Telephone&colon.     ______________  Fax&colon. __________________

                 Email&colon.         _______________________________________

    # Copies                                                        Amount

    ____ CD Player for OS/2 registration
         Germany&colon. DM 30,-  Europe&colon. DM 35,-  World&colon. DM 50,-        = DM _____,-

                                                                �����������

                                                            TOTAL DM _____,-

    Payment enclosed&colon.

    ( ) Eurocheque # _____________ (in DM only please!)

    ( ) Bank notes (German, Swiss, French, Austrian, British and US currency)

    Please allow a maximum of 6 weeks for delivery.

    Date/Signature: _________________________________________________________

:efig.
:font facename=default size=0x0.

.********************************************************************
:h2 res=19200 name=PANEL_REG2.CD Player order form - Page 2
:font facename=Courier size=10x10.
:fig.



    This CD Player version was obtained...

    ( ) from a BBS - name/phone #&colon. __________________________________________

    ( ) from a shareware vendor - name/city&colon. ________________________________

    ( ) _____________________________________________________________________

    CD Player was tried because of...

    ( ) a report in&colon. ________________________________________________________

    ( ) _____________________________________________________________________


    Suggestions for future improvement&colon.

    _________________________________________________________________________

    _________________________________________________________________________

    _________________________________________________________________________

:efig.
:font facename=default size=0x0.
.********************************************************************

.********************************************************************
.********************************************************************
:h1 hide res=20000.Footnotes

:fn id=frames.
:p.Frames are the smallest measurement on an audio cd.
A frame is the 75th part of a second.
:efn.

:fn id=upc.
:p.:hp4.UPC:ehp4. stands for "universal product code". Not every
cd has an :hp4.UPC:ehp4., and not every cdrom unit can read the
:hp4.UPC:ehp4..
:efn.

:fn id=preemphasis.
:p.:hp4.Preemphasis:ehp4. stands for the special recording of a track.
:efn.

:fn id=librarymode.
:p.While the
:link reftype=hd res=12000.title editor:elink. is in
:hp4.library mode:ehp4., you can view the titles and
the additional information of all cds in your
:link reftype=fn refid=library.cd library:elink., and you can
select one cd to revise it.
:efn.

:fn id=library.
:p.The :hp4.cd library:ehp4. contains the infos and titles of all tracks
which were inserted during use of the CD Player. It is stored along with 
the CD Player on your hard disk.
:efn.

:fn id=changemode.
:p.If the
:link reftype=hd res=12000.title editor:elink.
is in :hp4.change mode:ehp4., you can change the titles
and additional information of the selected cd.
:efn.

.********************************************************************

.********************************************************************
:euserdoc.
