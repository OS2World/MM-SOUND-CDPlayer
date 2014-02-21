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
:link reftype=hd res=11200.controls:elink.
of the CD Player and buttons to start the
:link reftype=hd res=12000.title editor:elink., the
:link reftype=hd res=13000.program editor:elink., the
:link reftype=hd res=15000.settings:elink. and the
:link reftype=hd res=14000.info window:elink..
:p.Most commands can also be given by using the
:link reftype=hd res=11300.keyboard:elink. and the
:link reftype=hd res=11400.menus:elink..

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
:artwork align=center name='DSPTIME.BMP'.
:p.There are five displays in this area&colon.
:ul.
:li.:hp2.The length of the program up to the current position at the top in
:color fc=black.black:color fc=default.:ehp2.
:li.:hp2.The length of the program beyond the current position at the top in
:color fc=red.red:color fc=default.:ehp2.
:li.:hp2.The length of the current track up to the current position in the middle in
:color fc=black.black:color fc=default.:ehp2.
:li.:hp2.The length of the current track beyond the current position in the middle in
:color fc=red.red:color fc=default.:ehp2.
:li.:hp2.The number of the current track on the CD at the bottom in
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
:artwork align=center name='DSPPROG.BMP'.
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
:artwork align=center name='DSPVOL.BMP'.
:p.The two sliders in the volume display show the current volume of the
two channels. If the slider is at the top of the display, the volume is
maximal. If the slider is at the bottom of the display, the volume is
minimal. You can change the volume with the sliders, see
":link reftype=hd res=11220.changing left volume:elink." and
":link reftype=hd res=11221.changing right volume:elink.".
:p.The symbol on the button at the right bottom of the display shows,
whether the sound is currenty muted. In the picture above, sound is not
muted. If you mute sound, the symbol changes to&colon.
:artwork runin name='BTNMUTE1.BMP'., see also
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

:p.The title of the inserted cd is displayed in the title bar of the
main window following the text "CD Player". The same text is displayed in
the window list of OS/2. If the cd has no title or is no audio cd, the
following is displayed in the title bar&colon.
:dl break=all tsize=5.
:dt.:hp2.CD Player - no CDROM device:ehp2.
:dd.Your computer is not equipped with an audio-capable CDROM device.
:dt.:hp2.CD Player - no CD:ehp2.
:dd.There is no CD inserted.
:dt.:hp2.CD Player - no audio CD:ehp2.
:dd.The inserted CD does not contain audio tracks.
:dt.:hp2.CD Player - unnamed:ehp2.
:dd.The inserted CD has no title.
:edl.

:note.
If you have started the CD Player with a program object on the workplace shell,
the window list will show the name of the program object in front of the text
"CD Player - ...".

.********************************************************************
:h3 res=11140 name=PANEL_MW_DISP_POSITION.Position display
:i2 REFID=INDEX_POSITION.display in the main window
:lines align=center.:hp7.Position display:ehp7.:elines.
:artwork align=center name='DSPSLIDE.BMP'.
:p.The small markers beyond the position display figure the start positions
of the titles in the program. Above a marker the track number of a title
is displayed. The slider is always positioned at the current position.
It's possible to change the position with the slider, see
":link reftype=hd res=11250.changing position:elink.".

.********************************************************************
:h3 res=11160 name=PANEL_MW_DISP_CONTROLS.Playback display
:i2 REFID=INDEX_CDCONTROL.display in the main window
:p.:lines align=center.:hp7.Playback display:ehp7.:elines.
:p.The buttons
:artwork runin name='BTNPLAY.BMP'. and
:artwork runin name='BTNPAUSE.BMP'.
inform you about the current status of the CD Player.
:ul.
:li.If both buttons are not pressed (as displayed above),
playback is stopped.
:li.If only the the button
:artwork runin name='BTNPLAY.BMP'. 
is pressed, playback is active. If
:link reftype=hd res=15200.animation:elink. is turned on,
the arrow moves continously from left to right.
Speed and status of the
:link reftype=hd res=15200.animation:elink. can be changed in the
:link reftype=hd res=15000.settings:elink. under the topic
:link reftype=hd res=15200.animation:elink. with
:link reftype=hd res=15210.playback animation:elink. and
:link reftype=hd res=15220.animation rate:elink..
:li.If also the button
:artwork runin name='BTNPAUSE.BMP'. is pressed,
playback is paused.
The
:link reftype=hd res=15200.animation:elink.
will be paused too.
:eul.:lm margin=1.
:p.Both buttons can be used to start or pause playback,
see
":link reftype=hd res=11262.starting playback:elink." and
":link reftype=hd res=11263.pausing playback:elink.".


.********************************************************************
:h2 res=11200 name=PANEL_MW_CONTROL.Control
:i2 REFID=INDEX_MAINWINDOW.Control
:i2 REFID=INDEX_CONTROL.in the main window
:p.:lines align=center.:hp7.Controls in the main window:ehp7.:elines.
:ul.
:li.:link reftype=hd res=11210.Title selection in the program display:elink.
:li.:link reftype=hd res=11220.Changing volume of the left channel:elink.
:li.:link reftype=hd res=11221.Changing volume of the right channel:elink.
:li.:link reftype=hd res=11222.Changing volume independently:elink.
:li.:link reftype=hd res=11223.Wwap channels:elink.
:li.:link reftype=hd res=11224.Sound off/on:elink.
:li.:link reftype=hd res=11230.Starting the title editor:elink.
:li.:link reftype=hd res=11231.Starting the program editor:elink.
:li.:link reftype=hd res=11232.Starting the settings:elink.
:li.:link reftype=hd res=11233.Starting the info window:elink.
:li.:link reftype=hd res=11240.Title selection by title:elink.
:li.:link reftype=hd res=11250.Setting position:elink.
:li.:link reftype=hd res=11260.Title back:elink.
:li.:link reftype=hd res=11261.Title forward:elink.
:li.:link reftype=hd res=11262.Starting playback:elink.
:li.:link reftype=hd res=11263.Pausing playback:elink.
:li.:link reftype=hd res=11264.Stopping playback:elink.
:li.:link reftype=hd res=11265.Ejecting the CD:elink.
:li.:link reftype=hd res=11266.Setting autorepeat:elink.
:eul.:lm margin=1.

.********************************************************************
:h3 res=11210 name=PANEL_MW_CTRL_PROGRAM.Title selection in the program display
:i2 REFID=INDEX_TITLE.selection in the program display
:i2 REFID=INDEX_PROGRAM.Selecting titles (in the main window)
:p.:lines align=center.:hp7.Title selection in the program display:ehp7.:elines.
:artwork align=center name='DSPPROG.BMP'.
:p.If you select a title in the program display, the CD Player will set the
current position to the start position of the selected title.
The selection can be done with a double-click or by pressing the enter-key.
.br
If playback is active, it will continue at the new position immediately.
.br
See also ":link reftype=hd res=11120.program display:elink.".

.********************************************************************
:h3 res=11220 name=PANEL_MW_CTRL_VOL_LEFT.Changing volume of the left channel
:i2 REFID=INDEX_VOLUME.changing of left channel
:i2 REFID=INDEX_CHANNELS.changing volume of left channel
:i2 REFID=INDEX_SOUND.changing of left channel
:p.:lines align=center.:hp7.Changing volume for the left channel:ehp7.:elines.
:artwork align=center name='BTNVOL.BMP'.
:p.With this slider, you can change the volume of the left channel. At the top
position the volume is maximal.
.br
If the setting
":link reftype=hd res=11222.Changing volume independently:elink."
is not active, the volume of the right channel will be automatically
adjusted to the same value.
.br
In the
:link reftype=hd res=15000.settings:elink. under the topic
:link reftype=hd res=15400.save:elink. you can choose
:link reftype=hd res=15420.volume:elink.. Then the volume will
be saved and restored automatically, if you quit and restart the
CD Player.
.br
See also ":link reftype=hd res=11130.volume display:elink.".

:note.
If your CDROM drive doesn't provide a mechanism to change the volume,
the slider will be deactivated.
.br
Perhaps you can change the volume with the global volume control of OS/2
or with an external volume control at your sound card or your CDROM drive.

.********************************************************************
:h3 res=11221 name=PANEL_MW_CTRL_VOL_RIGHT.Changing volume of the right channel
:i2 REFID=INDEX_VOLUME.changing of right channel
:i2 REFID=INDEX_CHANNELS.changing volume of right channel
:i2 REFID=INDEX_SOUND.changing of right channel
:p.:lines align=center.:hp7.Changing volume for the right channel:ehp7.:elines.
:artwork align=center name='BTNVOL.BMP'.
:p.With this slider, you can change the volume of the right channel. At the top
position the volume is maximal.
.br
If the setting
":link reftype=hd res=11222.Changing volume independently:elink."
is not active, the volume of the left channel will be automatically
adjusted to the same value.
.br
In the
:link reftype=hd res=15000.settings:elink. under the topic
:link reftype=hd res=15400.save:elink. you can choose
:link reftype=hd res=15420.volume:elink.. Then the volume will
be saved and restored automatically, if you quit and restart the
CD Player.
.br
See also ":link reftype=hd res=11130.volume display:elink.".

:note.
If your CDROM drive doesn't provide a mechanism to change the volume,
the slider will be deactivated.
.br
Perhaps you can change the volume with the global volume control of OS/2
or with an external volume control at your sound card or your CDROM drive.


.********************************************************************
:h3 res=11222 name=PANEL_MW_CTRL_VOL_IND.Changing volume independently
:i2 REFID=INDEX_VOLUME.changing volume independently
:i2 REFID=INDEX_CHANNELS.Changing volume independently
:p.:lines align=center.:hp7.Option&colon. changing volume independently:ehp7.:elines.
:p.With the check box :hp2.Independent:ehp2. you can select indepedent control
of volume for both channels. See also
":link reftype=hd res=11220.Changing volume of the left channel:elink." und
":link reftype=hd res=11221.Changing volume of the right channel:elink.".
.br
Even if you select
:link reftype=hd res=15420.volume:elink. in the 
:link reftype=hd res=15000.settings:elink. under the topic
:link reftype=hd res=15400.save:elink., the status of this
box will no become saved. Instead the status of the box is determined
by the saved volume. If the saved volume is different for the two channels,
the option will be turned on, otherwise it will be turned off.
:p.This option may be changed in the following ways&colon.
:ul.
:li.With the check box :hp2.Independent:ehp2.
:eul.:lm margin=1.
:note.
If your CDROM drive does not support this option, the check box is deactivated.


.********************************************************************
:h3 res=11223 name=PANEL_MW_CTRL_VOL_SWAP.Swap channels
:i2 REFID=INDEX_VOLUME.Swap channels
:i2 REFID=INDEX_CHANNELS.swapping
:p.:lines align=center.:hp7.Option&colon. Swap channels:ehp7.:elines.
:p.With the check box :hp2.Swap:ehp2. the left and the right channel
can be swapped.
:p.This option may be changed in the following ways&colon.
:ul.
:li.With the check box :hp2.Swap:ehp2.
:eul.:lm margin=1.
:note.
If your CDROM drive does not support this option, the check box is deactivated.

.********************************************************************
:h3 res=11224 name=PANEL_MW_CTRL_VOL_MUTE.Sound off/on
:i2 REFID=INDEX_VOLUME.Sound off/on
:i2 REFID=INDEX_SOUND.turning off
:i2 REFID=INDEX_SOUND.turning on
:p.:lines align=center.:hp7.Option&colon. Sound off/on:ehp7.:elines.
:p.With this button you can temporarily turn sound off or on without changing
the selected volume.
.br
See also ":link reftype=hd res=11130.volume display:elink.".
:p.This option may be changed in the following ways&colon.
:ul.
:li.With the buttons :artwork runin name='BTNMUTE0.BMP'.
or :artwork runin name='BTNMUTE1.BMP'.
:li.With the :link reftype=hd res=11300.keyboard command:elink. :hp2.Ctrl+M:ehp2.
:li.With the command :hp2.S:ehp2.:hp7.o:ehp7.:hp2.und off:ehp2. respectively 
:hp2.S:ehp2.:hp7.o:ehp7.:hp2.und on:ehp2. in the
:link reftype=hd res=11420.popup menu:elink.
:li.With the command :hp2.S:ehp2.:hp7.o:ehp7.:hp2.und off:ehp2. respectively
:hp2.S:ehp2.:hp7.o:ehp7.:hp2.und on:ehp2. in the
:link reftype=hd res=11410.system menu:elink.
:eul.
:note.
If your CDROM drive does not support this option, the command is deactivated.

.********************************************************************
:h3 res=11230 name=PANEL_MW_CTRL_TITLEEDITOR.Starting the title editor
:i2 REFID=INDEX_TITLEEDITOR.starting
:p.:lines align=center.:hp7.Command&colon. Starting the title editor:ehp7.:elines.
:p.With this command you can start the
:link reftype=hd res=12000.title editor:elink..
.br
Ist eine Audio CD eingelegt, startet der
:link reftype=hd res=12000.Titeleditor:elink.
im :link reftype=fn refid=changemode.énderungsmodus:elink. fÅr die momentane CD. Ist keine
Audio CD eingelegt, startet der
:link reftype=hd res=12000.Titeleditor:elink.
im :link reftype=fn refid=librarymode.Bibliotheksmodus:elink..
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit dem Knopf :hp7.T:ehp7.:hp2.iteleditor...:ehp2.
:li.Mit dem Befehl :hp7.T:ehp7.:hp2.iteleditor...:ehp2. im
:link reftype=hd res=11420.PopupmenÅ:elink.
:li.Mit dem Befehl :hp7.T:ehp7.:hp2.iteleditor...:ehp2. im UntermenÅ
:hp7.F:ehp7.:hp2.enster:ehp2. des :link reftype=hd res=11410.SystemmenÅs:elink.
:eul.:lm margin=1.

.********************************************************************
:h3 res=11231 name=PANEL_MW_CTRL_PROGRAMEDITOR.Programmeditor starten
:i2 REFID=INDEX_PROGRAMEDITOR.starten (im Main window)
:p.:lines align=center.:hp7.Befehl&colon. Programmeditor starten:ehp7.:elines.
:p.Mit diesem Befehl wird der
:link reftype=hd res=13000.Programmeditor:elink.
fÅr das momentane Programm gestartet.
.br
Wenn keine Audio CD eingelegt ist, ist dieser Befehl deaktiviert. Sie kînnen
aber den
:link reftype=hd res=13000.Programmeditor:elink. vom
:link reftype=hd res=12000.Titeleditor:elink. aus aufrufen,
um das Programm einer gespeicherten CD zu bearbeiten.
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit dem Knopf :hp7.P:ehp7.:hp2.rogrammeditor...:ehp2.
:li.Mit dem Befehl :hp7.P:ehp7.:hp2.rogrammeditor...:ehp2. im
:link reftype=hd res=11420.PopupmenÅ:elink.
:li.Mit dem Befehl :hp7.P:ehp7.:hp2.rogrammeditor...:ehp2. im UntermenÅ
:hp7.F:ehp7.:hp2.enster:ehp2. des :link reftype=hd res=11410.SystemmenÅs:elink.
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
:link reftype=hd res=11420.PopupmenÅ:elink.
:li.Mit dem Befehl :hp7.E:ehp7.:hp2.instellungen...:ehp2. im UntermenÅ
:hp7.F:ehp7.:hp2.enster:ehp2. des :link reftype=hd res=11410.SystemmenÅs:elink.
:eul.:lm margin=1.

.********************************************************************
:h3 res=11233 name=PANEL_MW_CTRL_INFO.Infofenster anzeigen
:i2 REFID=INDEX_INFOWINDOW.anzeigen (im Main window)
:p.:lines align=center.:hp7.Befehl&colon. Infofenster anzeigen:ehp7.:elines.
:p.Dieser Befehl zeigt das
:link reftype=hd res=14000.Infofenster:elink.
fÅr die momentane eingelegte CD an.
.br
Wenn keine Audio CD eingelegt ist, ist dieser Befehl deaktiviert. Sie kînnen
aber das
:link reftype=hd res=14000.Infofenster:elink. vom
:link reftype=hd res=12000.Titeleditor:elink. aus fÅr
eine gespeicherte CD anzeigen.
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit der :link reftype=hd res=11300.Tastenkombination:elink. :hp2.Strg+I:ehp2.
:li.Mit dem Befehl :hp7.I:ehp7.:hp2.nfofenster...:ehp2. im
:link reftype=hd res=11420.PopupmenÅ:elink.
:li.Mit dem Befehl :hp7.I:ehp7.:hp2.nfofenster...:ehp2. im UntermenÅ
:hp7.F:ehp7.:hp2.enster:ehp2. des :link reftype=hd res=11410.SystemmenÅs:elink.
:eul.:lm margin=1.

.********************************************************************
:h3 res=11240 name=PANEL_MW_CTRL_TITLE.Titel nach Namen wÑhlen
:i2 REFID=INDEX_TITLE.nach Namen wÑhlen
:i2 REFID=INDEX_NAMES.fÅr Wiedergabe auswÑhlen
:p.:lines align=center.:hp7.Titel nach Namen wÑhlen:ehp7.:elines.
:p.Wenn Sie einen Titel in der Titelanzeige auswÑhlen, wird der CD Spieler an
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
:artwork align=center name='DSPSLIDE.BMP'.
:p.Sie kînnen die Position im Programm genau einstellen, indem Sie den Schieber
auf die gewÅschte Stelle setzen.
.br
Befindet sich der CD Spieler im Wiedergabemodus, wird die Wiedergabe der CD
an der neuen Position unmittelbar fortgesetzt.
.br
Siehe auch ":link reftype=hd res=11140.Positionsanzeige:elink.".

.********************************************************************
:h3 res=11260 name=PANEL_MW_CTRL_BACKWARD.Titel zurÅck
:i1.ZurÅck
:i2 REFID=INDEX_TITLE.zurÅck
:i2 REFID=INDEX_CDCONTROL.Titel zurÅck
:p.:lines align=center.:hp7.Befehl&colon. Titel zurÅck:ehp7.:elines.
:p.Wenn die Position im momentanen Titel Åber dem in den
:link reftype=hd res=15000.Einstellungen:elink. unter
:link reftype=hd res=15300.Wiedergabe:elink. angegebenen
:link reftype=hd res=15330.RÅcksprunglimit:elink. liegt, wird der CD Spieler
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
:li.Mit dem Knopf :artwork runin name='BTNBACK.BMP'.
:li.Mit der :link reftype=hd res=11300.Tastenkombination:elink. :hp2.Strg+B:ehp2.
:li.Mit dem Befehl :hp7.Z:ehp7.:hp2.urÅck:ehp2. im
:link reftype=hd res=11420.PopupmenÅ:elink.
:li.Mit dem Befehl :hp7.Z:ehp7.:hp2.urÅck:ehp2. im UntermenÅ
:hp7.S:ehp7.:hp2.teuerung:ehp2. des :link reftype=hd res=11410.SystemmenÅs:elink.
:eul.:lm margin=1.

.********************************************************************
:h3 res=11261 name=PANEL_MW_CTRL_FORWARD.Titel vorwÑrts
:i1.VorwÑrts
:i2 REFID=INDEX_TITLE.vorwÑrts
:i2 REFID=INDEX_CDCONTROL.Titel vorwÑrts
:p.:lines align=center.:hp7.Befehl&colon. Titel vorwÑrts:ehp7.:elines.
:p.Dieser Befehl setzt den CD Spieler an den Start
des nÑchsten Titels im Programm.
.br
War der CD Spieler schon im letzten Titel positioniert,
setzt dieser Befehl den CD Spieler an den Anfang des Programms.
.br
Befindet sich der CD Spieler im Wiedergabemodus, wird die Wiedergabe der CD
an der neuen Position unmittelbar fortgesetzt.
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit dem Knopf :artwork runin name='BTNFOR.BMP'.
:li.Mit der :link reftype=hd res=11300.Tastenkombination:elink. :hp2.Strg+F:ehp2.
:li.Mit dem Befehl :hp7.V:ehp7.:hp2.orwÑrts:ehp2. im
:link reftype=hd res=11420.PopupmenÅ:elink.
:li.Mit dem Befehl :hp7.V:ehp7.:hp2.orwÑrts:ehp2. im UntermenÅ
:hp7.S:ehp7.:hp2.teuerung:ehp2. des :link reftype=hd res=11410.SystemmenÅs:elink.
:eul.:lm margin=1.

.********************************************************************
:h3 res=11262 name=PANEL_MW_CTRL_PLAY.Wiedergabe starten
:isyn ROOT=start.Start
:i1 ROOTS='start'.Starten
:i2 REFID=INDEX_CDCONTROL.starten
:p.:lines align=center.:hp7.Befehl&colon. Wiedergabe starten:ehp7.:elines.
:p.Dieser Befehl startet die Wiedergabe der CD an der momentanen Position.
.br
Die Wiedergabe lÑuft bis zum Ende des eingestellten Programms. Wenn die Option
:link reftype=hd res=11266."Automatische Wiederholung":elink. aktiviert ist,
wird die Wiedergabe dann vom Beginn des Programms an fortgesetzt, anderenfalls wird
sie beendet.
.br
Siehe auch ":link reftype=hd res=11160.Darstellung der Wiedergabe:elink.".
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit dem Knopf :artwork runin name='BTNPLAY.BMP'.
:li.Mit der :link reftype=hd res=11300.Tastenkombination:elink. :hp2.Strg+P:ehp2.
:li.Mit dem Befehl :hp2.S:ehp2.:hp7.p:ehp7.:hp2.ielen:ehp2. im
:link reftype=hd res=11420.PopupmenÅ:elink.
:li.Mit dem Befehl :hp2.S:ehp2.:hp7.p:ehp7.:hp2.ielen:ehp2. im UntermenÅ
:hp7.S:ehp7.:hp2.teuerung:ehp2. des :link reftype=hd res=11410.SystemmenÅs:elink.
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
:li.Mit dem Knopf :artwork runin name='BTNPAUSE.BMP'.
:li.Mit der :link reftype=hd res=11300.Tastenkombination:elink. :hp2.Strg+A:ehp2.
:li.Mit dem Befehl :hp2.Pa:ehp2.:hp7.u:ehp7.:hp2.se:ehp2. im
:link reftype=hd res=11420.PopupmenÅ:elink.
:li.Mit dem Befehl :hp2.Pa:ehp2.:hp7.u:ehp7.:hp2.se:ehp2. im UntermenÅ
:hp7.S:ehp7.:hp2.teuerung:ehp2. des :link reftype=hd res=11410.SystemmenÅs:elink.
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
:li.Mit dem Knopf :artwork runin name='BTNSTOP.BMP'.
:li.Mit der :link reftype=hd res=11300.Tastenkombination:elink. :hp2.Strg+S:ehp2.
:li.Mit dem Befehl :hp7.S:ehp7.:hp2.top:ehp2. im
:link reftype=hd res=11420.PopupmenÅ:elink.
:li.Mit dem Befehl :hp7.S:ehp7.:hp2.top:ehp2. im UntermenÅ
:hp7.S:ehp7.:hp2.teuerung:ehp2. des :link reftype=hd res=11410.SystemmenÅs:elink.
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
:li.Mit dem Knopf :artwork runin name='BTNEJECT.BMP'.
:li.Mit der :link reftype=hd res=11300.Tastenkombination:elink. :hp2.Strg+E:ehp2.
:li.Mit dem Befehl :hp7.A:ehp7.:hp2.uswurf:ehp2. im
:link reftype=hd res=11420.PopupmenÅ:elink.
:li.Mit dem Befehl :hp7.A:ehp7.:hp2.uswurf:ehp2. im UntermenÅ
:hp7.S:ehp7.:hp2.teuerung:ehp2. des :link reftype=hd res=11410.SystemmenÅs:elink.
:eul.:lm margin=1.
:note.
Es kann sein, da· Ihr CD-ROM Laufwerk diesen Befehl nicht unterstÅtzt. In diesem Fall
sind der Befehlsknopf und die MenÅpunkte deaktiviert.

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
Wird der Knopf :artwork runin name='BTNAUTO1.BMP'. angezeigt, ist die
automatische Wiederholung aktiviert.
:p.Diese Option kann auf folgende Arten geÑndert werden&colon.
:ul.
:li.Mit den Knîpfen :artwork runin name='BTNAUTO0.BMP'. oder
:artwork runin name='BTNAUTO1.BMP'.
:li.Mit der :link reftype=hd res=11300.Tastenkombination:elink. :hp2.Strg+R:ehp2.
:li.Mit dem Befehl :hp2.Auto:ehp2.:hp7.w:ehp7.:hp2.iederholung:ehp2. im
:link reftype=hd res=11420.PopupmenÅ:elink.
:li.Mit dem Befehl :hp2.Auto:ehp2.:hp7.w:ehp7.:hp2.iederholung:ehp2. im UntermenÅ
:hp7.S:ehp7.:hp2.teuerung:ehp2. des :link reftype=hd res=11410.SystemmenÅs:elink.
:eul.:lm margin=1.
:p.Diese Option kann auch in den
:link reftype=hd res=15000.Einstellungen:elink. unter
:link reftype=hd res=15300.Wiedergabe:elink. mit der Option
:link reftype=hd res=15310.Autowiederholung:elink. geÑndert werden. In diesem Fall
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
:dd.FÅhrt den :link reftype=hd res=11263.Wiedergabe unterbrechen:elink. Befehl aus
:dt.:hp2.Strg+B:ehp2.
:dd.FÅhrt den :link reftype=hd res=11260.Titel zurÅck:elink. Befehl aus
:dt.:hp2.Strg+E:ehp2.
:dd.FÅhrt den :link reftype=hd res=11265.CD auswerfen:elink. Befehl aus
:dt.:hp2.Strg+F:ehp2.
:dd.FÅhrt den :link reftype=hd res=11261.Titel vorwÑrts:elink. Befehl aus
:dt.:hp2.Strg+I:ehp2.
:dd.FÅhrt den :link reftype=hd res=11233.Infofenster anzeigen:elink. Befehl aus
:dt.:hp2.Strg+M:ehp2.
:dd.FÅhrt den :link reftype=hd res=11224.Ton aus/an:elink. Befehl aus
:dt.:hp2.Strg+P:ehp2.
:dd.FÅhrt den :link reftype=hd res=11262.Wiedergabe starten:elink. Befehl aus
:dt.:hp2.Strg+R:ehp2.
:dd.FÅhrt den :link reftype=hd res=11266.Autowiederholung einstellen:elink. Befehl aus
:dt.:hp2.Strg+S:ehp2.
:dd.FÅhrt den :link reftype=hd res=11264.Wiedergabe stoppen:elink. Befehl aus
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
:dd.Setzt die Position eine 1/75 Sekunde zurÅck
:dt.:hp2.-:ehp2.
:dd.Setzt die Position eine 1/5 Sekunde zurÅck
:dt.:hp2.-:ehp2.
:dd.Setzt die Position eine Sekunde zurÅck
:dt.:hp2.Umsch+-:ehp2.
:dd.Setzt die Position um 10 Sekunden zurÅck
:dt.:hp2.Strg+-:ehp2.
:dd.Setzt die Position eine Minute zurÅck
:dt.:hp2.Umsch+Strg+-:ehp2.
:dd.Setzt die Position um 10 Minuten zurÅck
:dt.:hp2.Umsch+F10:ehp2.
:dd.Aktiviert das :link reftype=hd res=11420.PopupmenÅ:elink.
:edl.

:p.:lines align=center.:hp7.Mausbefehle im Main window:ehp7.:elines.
:dl break=fit tsize=15.
:dt.:hp2.Klick der rechten Maustaste:ehp2.
:dd.Aktiviert das :link reftype=hd res=11420.PopupmenÅ:elink.
:dt.:hp2.Klick der mittleren Maustaste:ehp2.
:dd.Startet oder unterbricht die Wiedergabe
:dt.:hp2.Taste Strg und Klick der mittleren Maustaste:ehp2.
:dd.Stoppt die Wiedergabe
:edl.

.********************************************************************
:h2 res=11400 name=PANEL_MW_MENUS.MenÅbefehle
:i2 REFID=INDEX_MAINWINDOW.MenÅbefehle
:i2 REFID=INDEX_MENU.im Main window
:p.:lines align=center.:hp7.MenÅbefehle im Main window:ehp7.:elines.
:p.Die wichtigsten Befehle und Optionen im Main window kînnen auch Åber
das
:link reftype=hd res=11420.PopupmenÅ:elink. und das erweiterte
:link reftype=hd res=11410.SystemmenÅ:elink. gegeben bzw. eingestellt werden.
.br
Das
:link reftype=hd res=11420.PopupmenÅ:elink. kann mit einfachem Klick der
rechten Maustaste an einer beliebigen Position im Main window oder Åber
die Tastenkombination Umsch+F10 aufgerufen werden.

.********************************************************************
:h3 res=11420 name=PANEL_MW_MENU_POPUP.PopupmenÅ
:i2 REFID=INDEX_POPUPMENU.im Main window
:p.:lines align=center.:hp7.Das PopupmenÅ im Main window:ehp7.:elines.
:dl break=fit tsize=15.
:dthd.:hp3.MenÅpunkt:ehp3.
:ddhd.:hp3.Befehl:ehp3.
:dt.:hp2.:ehp2.:hp7.Z:ehp7.:hp2.urÅck:ehp2.
:dd.FÅhrt den :link reftype=hd res=11260.Titel zurÅck:elink. Befehl aus
:dt.:hp2.:ehp2.:hp7.V:ehp7.:hp2.orwÑrts:ehp2.
:dd.FÅhrt den :link reftype=hd res=11261.Titel vorwÑrts:elink. Befehl aus
:dt.:hp2.S:ehp2.:hp7.p:ehp7.:hp2.ielen:ehp2.
:dd.FÅhrt den :link reftype=hd res=11262.Wiedergabe starten:elink. Befehl aus
:dt.:hp2.Pa:ehp2.:hp7.u:ehp7.:hp2.se:ehp2.
:dd.FÅhrt den :link reftype=hd res=11263.Wiedergabe unterbrechen:elink. Befehl aus
:dt.:hp2.:ehp2.:hp7.S:ehp7.:hp2.top:ehp2.
:dd.FÅhrt den :link reftype=hd res=11264.Wiedergabe stoppen:elink. Befehl aus
:dt.:hp2.:ehp2.:hp7.A:ehp7.:hp2.uswurf:ehp2.
:dd.FÅhrt den :link reftype=hd res=11265.CD auswerfen:elink. Befehl aus
:dt.:hp2.Auto:ehp2.:hp7.w:ehp7.:hp2.iederholung:ehp2.
:dd.FÅhrt den :link reftype=hd res=11266.Autowiederholung einstellen:elink. Befehl aus
:dt.:hp2.T:ehp2.:hp7.o:ehp7.:hp2.n aus:ehp2.
:dd.FÅhrt den :link reftype=hd res=11224.Ton aus:elink. Befehl aus
:dt.:hp2.T:ehp2.:hp7.o:ehp7.:hp2.n an:ehp2.
:dd.FÅhrt den :link reftype=hd res=11224.Ton an:elink. Befehl aus
:dt.:hp2.:ehp2.:hp7.T:ehp7.:hp2.iteleditor...:ehp2.
:dd.FÅhrt den :link reftype=hd res=11230.Titeleditor starten:elink. Befehl aus
:dt.:hp2.P:ehp2.:hp7.r:ehp7.:hp2.ogrammeditor...:ehp2.
:dd.FÅhrt den :link reftype=hd res=11231.Programmeditor starten:elink. Befehl aus
:dt.:hp2.:ehp2.:hp7.E:ehp7.:hp2.instellungen...:ehp2.
:dd.FÅhrt den :link reftype=hd res=11232.Einstellungen aufrufen:elink. Befehl aus
:dt.:hp2.:ehp2.:hp7.I:ehp7.:hp2.nfofenster...:ehp2.
:dd.FÅhrt den :link reftype=hd res=11233.Infofenster anzeigen:elink. Befehl aus
:dt.:hp2.:ehp2.:hp7.H:ehp7.:hp2.ilfe:ehp2.
:dd.Zeigt das HilfemenÅ an.
:dt.:hp2.S:ehp2.:hp7.c:ehp7.:hp2.hliessen:ehp2.
:dd.Beendet das CD Spieler Programm.
:edl.

.********************************************************************
:h3 res=11410 name=PANEL_MW_MENU_SYS.SystemmenÅ
:i2 REFID=INDEX_SYSMENU.im Main window
:p.:lines align=center.:hp7.Das erweiterte SystemmenÅ im Main window:ehp7.:elines.
:p.ZusÑtzlich zu den normalen MenÅpunkten des SystemmenÅs enthÑlt das SystemmenÅ des
Main windows folgende MenÅpunkte:
:dl break=fit tsize=15.
:dthd.:hp3.MenÅpunkt:ehp3.
:ddhd.:hp3.Befehl/UntermenÅ:ehp3.
:dt.:hp2.:ehp2.:hp7.S:ehp7.:hp2.teuerung:ehp2.
:dd.UntermenÅ :hp2.Steuerung:ehp2. (s.u.)
:dt.:hp2.:ehp2.:hp7.F:ehp7.:hp2.enster:ehp2.
:dd.UntermenÅ :hp2.Fenster:ehp2. (s.u.)
:dt.:hp2.T:ehp2.:hp7.o:ehp7.:hp2.n aus:ehp2.
:dd.FÅhrt den :link reftype=hd res=11224.Ton aus:elink. Befehl aus
:dt.:hp2.T:ehp2.:hp7.o:ehp7.:hp2.n an:ehp2.
:dd.FÅhrt den :link reftype=hd res=11224.Ton an:elink. Befehl aus
:dt.:hp2.:ehp2.:hp7.H:ehp7.:hp2.ilfe:ehp2.
:dd.Zeigt das HilfemenÅ an.
:edl.

:p.UntermenÅ :hp2.Steuerung:ehp2.
:dl break=fit tsize=15.
:dthd.:hp3.MenÅpunkt:ehp3.
:ddhd.:hp3.Befehl:ehp3.
:dt.:hp2.:ehp2.:hp7.Z:ehp7.:hp2.urÅck:ehp2.
:dd.FÅhrt den :link reftype=hd res=11260.Titel zurÅck:elink. Befehl aus
:dt.:hp2.:ehp2.:hp7.V:ehp7.:hp2.orwÑrts:ehp2.
:dd.FÅhrt den :link reftype=hd res=11261.Titel vorwÑrts:elink. Befehl aus
:dt.:hp2.S:ehp2.:hp7.p:ehp7.:hp2.ielen:ehp2.
:dd.FÅhrt den :link reftype=hd res=11262.Wiedergabe starten:elink. Befehl aus
:dt.:hp2.Pa:ehp2.:hp7.u:ehp7.:hp2.se:ehp2.
:dd.FÅhrt den :link reftype=hd res=11263.Wiedergabe unterbrechen:elink. Befehl aus
:dt.:hp2.:ehp2.:hp7.S:ehp7.:hp2.top:ehp2.
:dd.FÅhrt den :link reftype=hd res=11264.Wiedergabe stoppen:elink. Befehl aus
:dt.:hp2.:ehp2.:hp7.A:ehp7.:hp2.uswurf:ehp2.
:dd.FÅhrt den :link reftype=hd res=11265.CD auswerfen:elink. Befehl aus
:dt.:hp2.Auto:ehp2.:hp7.w:ehp7.:hp2.iederholung:ehp2.
:dd.FÅhrt den :link reftype=hd res=11266.Autowiederholung einstellen:elink. Befehl aus
:edl.

:p.UntermenÅ :hp2.Fenster:ehp2.
:dl break=fit tsize=15.
:dthd.:hp3.MenÅpunkt:ehp3.
:ddhd.:hp3.Befehl:ehp3.
:dt.:hp2.:ehp2.:hp7.T:ehp7.:hp2.iteleditor...:ehp2.
:dd.FÅhrt den :link reftype=hd res=11230.Titeleditor starten:elink. Befehl aus
:dt.:hp2.P:ehp2.:hp7.r:ehp7.:hp2.ogrammeditor...:ehp2.
:dd.FÅhrt den :link reftype=hd res=11231.Programmeditor starten:elink. Befehl aus
:dt.:hp2.:ehp2.:hp7.E:ehp7.:hp2.instellungen...:ehp2.
:dd.FÅhrt den :link reftype=hd res=11232.Einstellungen aufrufen:elink. Befehl aus
:dt.:hp2.:ehp2.:hp7.I:ehp7.:hp2.nfofenster...:ehp2.
:dd.FÅhrt den :link reftype=hd res=11233.Infofenster anzeigen:elink. Befehl aus
:edl.
.********************************************************************

