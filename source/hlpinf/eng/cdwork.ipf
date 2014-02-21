.********************************************************************
:userdoc.
:title.CD Player documentation
.********************************************************************
.imd panel.h
.********************************************************************
.imd language.h
.********************************************************************
.im phrases.ipf
.********************************************************************
.nameit symbol=ERROR text='Error:'
.nameit symbol=FATAL_ERROR text='This is a fatal error. The CD Player will be terminated.'
.nameit symbol=ERROR_MSGS text='Error messages'
.********************************************************************
.im intro.ipf
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
a disc is inserted in your CD-ROM drive and whether this disc contains audio tracks.
In this case, all controls and features of the CD Player are directly accessible.
If the inserted disc doesn't contain audio tracks, your only choice is ejecting
the disc (if you don't need it otherwise).
.br
All time the CD Player is active, it will check the CD-ROM drive. As soon as
a disc is ejected or inserted, the CD Player's display will change to reflect
the new circumstances.

:p.:lines align=center.:hp7.Extensions:ehp7.:elines.
:p.Beyond simple playback of an audio disc, the CD Player is able to handle titles of
discs and tracks including additional notices, and to use a freely programmable
sequence of the desired titles to play. Titles and program are saved and
restored automatically, if you insert the same disc again. All information will
be retained, even if you quit the CD Player program, see
":link reftype=hd res=12000.title editor:elink." and
":link reftype=hd res=13000.program editor:elink.".
Additionally, display and behaviour of the CD Player can be changed in the
:link reftype=hd res=15000.settings:elink. in various ways.
:p.:lines align=center.:hp7.Requirements:ehp7.:elines.
:ul.
:li.A PC with OS/2 2.1 installed, including the multimedia extensions. The CD
Player should work with OS/2 2.0 and multimedia extensions too, but this environment
was not testet.
:li.An audio-capable CD-ROM drive, which is supported by the multimedia extensions.
:eul.:lm margin=1.
:p.:lines align=center.:hp7.Restrictions:ehp7.:elines.
:ul.
:lm margin=0.:li.
In the actual version, it's not possible to use the CD Player along with other
programs using the audio capabilities of the CD-ROM drive. For the same reason,
the CD Player cannot be started more than once the same time.
:li.
In the actual version, it's not possible to change a disc's program during playback.
Saving the new program will stop playback.
:li.
Ending the CD Player will end playback. This is a restriction caused by the
multimedia extensions of OS/2.
:eul.:lm margin=1.
:p.:lines align=center.:hp7.History:ehp7.:elines.
:p.Originally the intention to develop the CD Player was the necessity to try out
the new facilities of the multimedia presentation manager. But the project tended
to grow and grow more, and soon it became a serious software project. There has been
much work to build this version, so I decided to distribute it as shareware, see
:link reftype=hd res=18000.Copyright:elink..
.********************************************************************
.im mainw.ipf
.********************************************************************
.********************************************************************
:h1 res=11000 name=PANEL_MAINWINDOW.Main window
:i2 REFID=INDEX_WINDOWS.Main window
:i2 REFID=INDEX_MAINWINDOW.Overview
:lines align=center.:hp7.The main window of the CD Player:ehp7.:elines.
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
:lines align=center.:hp7.Displays in the main window:ehp7.:elines.
:ul.
:li.:link reftype=hd res=11110.Time display:elink.
:li.:link reftype=hd res=11120.Program display:elink.
:li.:link reftype=hd res=11130.Volume display:elink.
:li.:link reftype=hd res=11150.Titles display:elink.
:li.:link reftype=hd res=11140.Position display:elink.
:li.:link reftype=hd res=11160.Playback display:elink.
:eul.

.********************************************************************
:h3 res=11110 name=PANEL_MW_DISP_TIME.Time display
:i2 REFID=INDEX_TRACKS.display in the main window
:i2 REFID=INDEX_TIME.display in the main window
:lines align=center.:hp7.Time display:ehp7.:elines.
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
:link reftype=hd res=15110.Hours/minutes/seconds:elink. or
:link reftype=hd res=15120.Minutes/seconds/frames:elink..

.********************************************************************
:h3 res=11120 name=PANEL_MW_DISP_PROGRAM.Program display
:i2 REFID=INDEX_PROGRAM.display in the main window
:lines align=center.:hp7.Program display:ehp7.:elines.
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
:lines align=center.:hp7.Volume display:ehp7.:elines.
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
:h3 res=11150 name=PANEL_MW_DISP_TITLE.Title display
:i2 REFID=INDEX_TITLE.display in the main window
:lines align=center.:hp7.Title display:ehp7.:elines.
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
:lines align=center.:hp7.Playback display:ehp7.:elines.
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
:h2 res=11200 name=PANEL_MW_CONTROL.Controls
:i2 REFID=INDEX_MAINWINDOW.controls
:i2 REFID=INDEX_CONTROL.in the main window
:lines align=center.:hp7.Controls in the main window:ehp7.:elines.
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
:i2 REFID=INDEX_TITLE.select from program
:i2 REFID=INDEX_PROGRAM.select titles (in the main window)
:lines align=center.:hp7.Title selection in the program display:ehp7.:elines.
:artwork align=center name='DSPPROG.BMP'.
:p.If you select a title in the program display, the CD Player will set the
current position to the start position of the selected title.
The selection can be done with a double-click or by pressing the enter-key.
.br
If playback is active, it will continue at the new position immediately.
.br
See also ":link reftype=hd res=11120.program display:elink.".

.********************************************************************
:h3 res=11220 name=PANEL_MW_CTRL_VOL_LEFT.Setting left channel's volume
:i2 REFID=INDEX_VOLUME.setting left channel
:i2 REFID=INDEX_CHANNELS.setting left channel
:i2 REFID=INDEX_SOUND.setting left channel
:lines align=center.:hp7.Setting left channel's volume:ehp7.:elines.
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
:h3 res=11221 name=PANEL_MW_CTRL_VOL_RIGHT.Setting right channel's volume
:i2 REFID=INDEX_VOLUME.setting right channel
:i2 REFID=INDEX_CHANNELS.setting right channel
:i2 REFID=INDEX_SOUND.setting right channel
:lines align=center.:hp7.Setting right channel's channel:ehp7.:elines.
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
:h3 res=11222 name=PANEL_MW_CTRL_VOL_IND.Setting channel volume independently
:i2 REFID=INDEX_VOLUME.setting channels independently
:i2 REFID=INDEX_CHANNELS.setting independently
:lines align=center.:hp7.Option&colon. Setting channel volume independently:ehp7.:elines.
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
:i2 REFID=INDEX_VOLUME.swap channels
:i2 REFID=INDEX_CHANNELS.swapping
:lines align=center.:hp7.Option&colon. swap channels:ehp7.:elines.
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
:i2 REFID=INDEX_VOLUME.sound off/on
:i2 REFID=INDEX_SOUND.turning off
:i2 REFID=INDEX_SOUND.turning on
:lines align=center.:hp7.Option&colon. sound off/on:ehp7.:elines.
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
:lines align=center.:hp7.Command&colon. starting the title editor:ehp7.:elines.
:p.Mit diesem Befehl wird der
:link reftype=hd res=12000.title editor:elink. gestartet.
.br
Ist eine Audio CD eingelegt, startet der
:link reftype=hd res=12000.title editor:elink.
im :link reftype=fn refid=changemode.énderungsmodus:elink. fÅr die momentane CD. Ist keine
Audio CD eingelegt, startet der
:link reftype=hd res=12000.title editor:elink.
im :link reftype=fn refid=librarymode.Bibliotheksmodus:elink..
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit dem Knopf :hp7.T:ehp7.:hp2.iteleditor...:ehp2.
:li.Mit dem Befehl :hp7.T:ehp7.:hp2.iteleditor...:ehp2. im
:link reftype=hd res=11420.PopupmenÅ:elink.
:li.Mit dem Befehl :hp7.T:ehp7.:hp2.iteleditor...:ehp2. im UntermenÅ
:hp7.F:ehp7.:hp2.enster:ehp2. des :link reftype=hd res=11410.SystemmenÅs:elink.
:eul.

.********************************************************************
:h3 res=11231 name=PANEL_MW_CTRL_PROGRAMEDITOR.Starting the program editor
:i2 REFID=INDEX_PROGRAMEDITOR.starting (in the main window)
:lines align=center.:hp7.Command&colon. starting the program editor:ehp7.:elines.
:p.Mit diesem Befehl wird der
:link reftype=hd res=13000.program editor:elink.
fÅr das momentane Programm gestartet.
.br
Wenn keine Audio CD eingelegt ist, ist dieser Befehl deaktiviert. Sie kînnen
aber den
:link reftype=hd res=13000.program editor:elink. vom
:link reftype=hd res=12000.title editor:elink. aus aufrufen,
um das Programm einer gespeicherten CD zu bearbeiten.
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit dem Knopf :hp7.P:ehp7.:hp2.rogrammeditor...:ehp2.
:li.Mit dem Befehl :hp7.P:ehp7.:hp2.rogrammeditor...:ehp2. im
:link reftype=hd res=11420.PopupmenÅ:elink.
:li.Mit dem Befehl :hp7.P:ehp7.:hp2.rogrammeditor...:ehp2. im UntermenÅ
:hp7.F:ehp7.:hp2.enster:ehp2. des :link reftype=hd res=11410.SystemmenÅs:elink.
:eul.

.********************************************************************
:h3 res=11232 name=PANEL_MW_CTRL_SETTINGS.Starting the settings
:i2 REFID=INDEX_SETTINGS.starting
:lines align=center.:hp7.Command&colon. starting the settings:ehp7.:elines.
:p.Mit diesem Befehl werden die
:link reftype=hd res=15000.settings:elink. aufgerufen.
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit dem Knopf :hp7.E:ehp7.:hp2.instellungen...:ehp2.
:li.Mit dem Befehl :hp7.E:ehp7.:hp2.instellungen...:ehp2. im
:link reftype=hd res=11420.PopupmenÅ:elink.
:li.Mit dem Befehl :hp7.E:ehp7.:hp2.instellungen...:ehp2. im UntermenÅ
:hp7.F:ehp7.:hp2.enster:ehp2. des :link reftype=hd res=11410.SystemmenÅs:elink.
:eul.

.********************************************************************
:h3 res=11233 name=PANEL_MW_CTRL_INFO.Display info window
:i2 REFID=INDEX_INFOWINDOW.displaying (in the main window)
:lines align=center.:hp7.Command&colon. display info window:ehp7.:elines.
:p.Dieser Befehl zeigt das
:link reftype=hd res=14000.Infofenster:elink.
fÅr die momentane eingelegte CD an.
.br
Wenn keine Audio CD eingelegt ist, ist dieser Befehl deaktiviert. Sie kînnen
aber das
:link reftype=hd res=14000.Infofenster:elink. vom
:link reftype=hd res=12000.title editor:elink. aus fÅr
eine gespeicherte CD anzeigen.
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit der :link reftype=hd res=11300.Tastenkombination:elink. :hp2.Strg+I:ehp2.
:li.Mit dem Befehl :hp7.I:ehp7.:hp2.nfofenster...:ehp2. im
:link reftype=hd res=11420.PopupmenÅ:elink.
:li.Mit dem Befehl :hp7.I:ehp7.:hp2.nfofenster...:ehp2. im UntermenÅ
:hp7.F:ehp7.:hp2.enster:ehp2. des :link reftype=hd res=11410.SystemmenÅs:elink.
:eul.

.********************************************************************
:h3 res=11240 name=PANEL_MW_CTRL_TITLE.Selecting titles by name
:i2 REFID=INDEX_TITLE.selecting by name
:i2 REFID=INDEX_NAMES.select for playback
:lines align=center.:hp7.Selecting titles by name:ehp7.:elines.
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
:h3 res=11250 name=PANEL_MW_CTRL_POSITION.Selecting the position
:i2 REFID=INDEX_POSITION.selecting
:lines align=center.:hp7.Selecting the position:ehp7.:elines.
:artwork align=center name='DSPSLIDE.BMP'.
:p.Sie kînnen die Position im Programm genau einstellen, indem Sie den Schieber
auf die gewÅschte Stelle setzen.
.br
Befindet sich der CD Spieler im Wiedergabemodus, wird die Wiedergabe der CD
an der neuen Position unmittelbar fortgesetzt.
.br
Siehe auch ":link reftype=hd res=11140.Positionsanzeige:elink.".

.********************************************************************
:h3 res=11260 name=PANEL_MW_CTRL_BACKWARD.Title backward
:i1.Backward
:i2 REFID=INDEX_TITLE.backward
:i2 REFID=INDEX_CDCONTROL.title backward
:lines align=center.:hp7.Command&colon. title backward:ehp7.:elines.
:p.Wenn die Position im momentanen Titel Åber dem in den
:link reftype=hd res=15000.settings:elink. unter
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
:eul.

.********************************************************************
:h3 res=11261 name=PANEL_MW_CTRL_FORWARD.Title forward
:i1.Forward
:i2 REFID=INDEX_TITLE.forward
:i2 REFID=INDEX_CDCONTROL.title forward
:lines align=center.:hp7.Command&colon. title forward:ehp7.:elines.
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
:eul.

.********************************************************************
:h3 res=11262 name=PANEL_MW_CTRL_PLAY.Starting playback
:isyn ROOT=start.Start
:i1 ROOTS='start'.Starting
:i2 REFID=INDEX_CDCONTROL.starting playback
:lines align=center.:hp7.Command&colon. starting playback:ehp7.:elines.
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
:eul.

.********************************************************************
:h3 res=11263 name=PANEL_MW_CTRL_PAUSE.Pausing playback
:isyn ROOT=pause.Pause
:i1 ROOTS='pause'.Pausing
:i2 REFID=INDEX_CDCONTROL.pausing playback
:lines align=center.:hp7.Command&colon. pausing playback:ehp7.:elines.
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
:eul.

.********************************************************************
:h3 res=11264 name=PANEL_MW_CTRL_STOP.Stopping playback
:isyn ROOT=stop.Stop
:i1 ROOTS='stop'.Stopping
:i2 REFID=INDEX_CDCONTROL.stopping playback
:lines align=center.:hp7.Command&colon. stopping playback:ehp7.:elines.
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
:eul.

.********************************************************************
:h3 res=11265 name=PANEL_MW_CTRL_EJECT.Ejecting disc
:isyn ROOT=eject.Eject
:i1 ROOTS='eject'.Ejecting
:i2 REFID=INDEX_CD.ejecting disc
:lines align=center.:hp7.Command&colon. ejecting disc:ehp7.:elines.
:p.Dieser Befehl wirft die CD aus.
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit dem Knopf :artwork runin name='BTNEJECT.BMP'.
:li.Mit der :link reftype=hd res=11300.Tastenkombination:elink. :hp2.Strg+E:ehp2.
:li.Mit dem Befehl :hp7.A:ehp7.:hp2.uswurf:ehp2. im
:link reftype=hd res=11420.PopupmenÅ:elink.
:li.Mit dem Befehl :hp7.A:ehp7.:hp2.uswurf:ehp2. im UntermenÅ
:hp7.S:ehp7.:hp2.teuerung:ehp2. des :link reftype=hd res=11410.SystemmenÅs:elink.
:eul.
:note.
Es kann sein, da· Ihr CD-ROM Laufwerk diesen Befehl nicht unterstÅtzt. In diesem Fall
sind der Befehlsknopf und die MenÅpunkte deaktiviert.

.********************************************************************
:h3 res=11266 name=PANEL_MW_CTRL_REPEAT.Controlling the automatic repitition
:i1.Repitition
:i2 REFID=INDEX_CDCONTROL.automatic repitition
:i2 REFID=INDEX_AUTOREPEAT.controlling (in the main window)
:lines align=center.:hp7.Option&colon. controlling the automatic repitition:ehp7.:elines.
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
:eul.
:p.Diese Option kann auch in den
:link reftype=hd res=15000.settings:elink. unter
:link reftype=hd res=15300.Wiedergabe:elink. mit der Option
:link reftype=hd res=15310.Autowiederholung:elink. geÑndert werden. In diesem Fall
bleibt die Einstellung der Option auch nach Programmende erhalten.

.********************************************************************
:h2 res=11300 name=PANEL_MW_KEYBOARD.Keyboard and mouse shortcuts
:i2 REFID=INDEX_MAINWINDOW.Keyboard and mouse shortcuts
:i2 REFID=INDEX_KEYBOARD.shortcuts in the main window
:i2 REFID=INDEX_MOUSE.shortcuts in the main window
:lines align=center.:hp7.Keyboard shortcuts in the main window:ehp7.:elines.
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

:p.:lines align=center.:hp7.Mouse shortcuts in the main window:ehp7.:elines.
:dl break=fit tsize=15.
:dt.:hp2.Klick der rechten Maustaste:ehp2.
:dd.Aktiviert das :link reftype=hd res=11420.PopupmenÅ:elink.
:dt.:hp2.Klick der mittleren Maustaste:ehp2.
:dd.Startet oder unterbricht die Wiedergabe
:dt.:hp2.Taste Strg und Klick der mittleren Maustaste:ehp2.
:dd.Stoppt die Wiedergabe
:edl.

.********************************************************************
:h2 res=11400 name=PANEL_MW_MENUS.Menu commands
:i2 REFID=INDEX_MAINWINDOW.menu commands
:i2 REFID=INDEX_MENU.in the main window
:lines align=center.:hp7.Menu commands in the main window:ehp7.:elines.
:p.Die wichtigsten Befehle und Optionen im Hauptfenster kînnen auch Åber
das
:link reftype=hd res=11420.PopupmenÅ:elink. und das erweiterte
:link reftype=hd res=11410.SystemmenÅ:elink. gegeben bzw. eingestellt werden.
.br
Das
:link reftype=hd res=11420.PopupmenÅ:elink. kann mit einfachem Klick der
rechten Maustaste an einer beliebigen Position im Hauptfenster oder Åber
die Tastenkombination Umsch+F10 aufgerufen werden.

.********************************************************************
:h3 res=11420 name=PANEL_MW_MENU_POPUP.Popup menu
:i2 REFID=INDEX_POPUPMENU.in the main window
:lines align=center.:hp7.The popup menu in the main window:ehp7.:elines.
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
:dd.FÅhrt den :link reftype=hd res=11230.title editor starten:elink. Befehl aus
:dt.:hp2.P:ehp2.:hp7.r:ehp7.:hp2.ogrammeditor...:ehp2.
:dd.FÅhrt den :link reftype=hd res=11231.program editor starten:elink. Befehl aus
:dt.:hp2.:ehp2.:hp7.E:ehp7.:hp2.instellungen...:ehp2.
:dd.FÅhrt den :link reftype=hd res=11232.settings aufrufen:elink. Befehl aus
:dt.:hp2.:ehp2.:hp7.I:ehp7.:hp2.nfofenster...:ehp2.
:dd.FÅhrt den :link reftype=hd res=11233.Infofenster anzeigen:elink. Befehl aus
:dt.:hp2.:ehp2.:hp7.H:ehp7.:hp2.ilfe:ehp2.
:dd.Zeigt das HilfemenÅ an.
:dt.:hp2.S:ehp2.:hp7.c:ehp7.:hp2.hliessen:ehp2.
:dd.Beendet das CD Spieler Programm.
:edl.

.********************************************************************
:h3 res=11410 name=PANEL_MW_MENU_SYS.System menu
:i2 REFID=INDEX_SYSMENU.in the main window
:lines align=center.:hp7.The extended system menu in the main window:ehp7.:elines.
:p.ZusÑtzlich zu den normalen MenÅpunkten des SystemmenÅs enthÑlt das SystemmenÅ des
Hauptfensters folgende MenÅpunkte:
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
:dd.FÅhrt den :link reftype=hd res=11230.title editor starten:elink. Befehl aus
:dt.:hp2.P:ehp2.:hp7.r:ehp7.:hp2.ogrammeditor...:ehp2.
:dd.FÅhrt den :link reftype=hd res=11231.program editor starten:elink. Befehl aus
:dt.:hp2.:ehp2.:hp7.E:ehp7.:hp2.instellungen...:ehp2.
:dd.FÅhrt den :link reftype=hd res=11232.settings aufrufen:elink. Befehl aus
:dt.:hp2.:ehp2.:hp7.I:ehp7.:hp2.nfofenster...:ehp2.
:dd.FÅhrt den :link reftype=hd res=11233.Infofenster anzeigen:elink. Befehl aus
:edl.
.********************************************************************

.im title.ipf
.********************************************************************
.********************************************************************
:h1 res=12000 name=PANEL_TITLEEDITOR.Title editor
:i2 REFID=INDEX_WINDOWS.title editor
:i2 REFID=INDEX_TITLEEDITOR.Overview
:i2 REFID=INDEX_TITLE.editor
:lines align=center.:hp7.The title editor:ehp7.:elines.
:p.Leider enthalten CD's keine Information Åber den Titel der CD und die
Titel der einzelnen Spuren. Mit dem title editor des CD Spielers ist es aber
leicht mîglich, die fehlende Information selbst einzugeben. Die Titel
werden in der :link reftype=fn refid=library.CD Bibliothek:elink. des CD Spielers
gespeichert, die sich zusammen mit dem CD Spieler auf Ihrer Festplatte befindet.
:p.Der title editor arbeitet in zwei unterschiedlichen Modi. Im
:link reftype=fn refid=librarymode.Bibliotheksmodus:elink.
kînnen Sie sich die Titel und zusÑtzlichen Informationen aller CD's in der
:link reftype=fn refid=library.CD Bibliothek:elink. betrachten und eine CD
fÅr die énderung auswÑhlen, im
:link reftype=fn refid=changemode.énderungsmodus:elink. kînnen Sie die Titel
und zusÑtzlichen Informationen einer CD bearbeiten.
.br
Wenn der title editor mit dem Befehl
:link reftype=hd res=11230.title editor starten:elink. im
:link reftype=hd res=11000.main window:elink. des CD Spielers aufgerufen wird,
befindet er sich im :link reftype=fn refid=changemode.énderungsmodus:elink.
fÅr die eingelegte CD. Sie kînnen aber jederzeit mit den Knîpfen
:link reftype=hd res=12260.Bibliothek:elink. (im
:link reftype=fn refid=changemode.énderungsmodus:elink.) und
:link reftype=hd res=12270.Bearbeiten:elink. (im
:link reftype=fn refid=librarymode.Bibliotheksmodus:elink.)
zwischen den beiden Modi umschalten.
.br
In welchem Modus sich der title editor gerade befindet, kînnen Sie an
der Titelleiste des title editors erkennen. Im
:link reftype=fn refid=changemode.énderungsmodus:elink. steht dort
"CD title editor", im
:link reftype=fn refid=librarymode.Bibliotheksmodus:elink.
"CD title editor Bibliothek".

.********************************************************************
:h2 res=12100 name=PANEL_TE_DISPLAY.Displays
:i2 REFID=INDEX_TITLEEDITOR.displays
:i2 REFID=INDEX_DISPLAY.in the title editor
:lines align=center.:hp7.Displays in the title editor:ehp7.:elines.
:ul.
:li.:link reftype=hd res=12110.CD Titel:elink.
:li.:link reftype=hd res=12120.ZusÑtzliche CD Information:elink.
:li.:link reftype=hd res=12130.Spurnummern:elink.
:li.:link reftype=hd res=12140.Spurtitel:elink.
:li.:link reftype=hd res=12150.ZusÑtzliche Spurinformation:elink.
:eul.

.********************************************************************
:h3 res=12110 name=PANEL_TE_DISP_CDTITLE.CD title
:i2 REFID=INDEX_CD.Title (in the title editor)
:i2 REFID=INDEX_TITLE.of the CD (in the title editor)
:lines align=center.:hp7.CD title:ehp7.:elines.
:p.Das obere Feld in der Box "CD Titel" zeigt den Titel der ausgewÑhlten
CD an. Im :link reftype=fn refid=librarymode.Bibliotheksmodus:elink.
kînnen Sie hier die
:link reftype=hd res=12210.CD auswÑhlen:elink., im
:link reftype=fn refid=changemode.énderungsmodus:elink. den
:link reftype=hd res=12210.CD Titel Ñndern:elink..

.********************************************************************
:h3 res=12120 name=PANEL_TE_DISP_CDINFO.Additional CD information
:i2 REFID=INDEX_CD.additional information (in the title eeditor)
:i2 REFID=INDEX_ADDINFO.anout the CD (in the Title editor)
:lines align=center.:hp7.Additional CD information:ehp7.:elines.
:p.Das untere Feld in der Box "CD Titel" zeigt die zusÑtzliche Information
zu der ausgewÑhlten CD an. Im
:link reftype=fn refid=changemode.énderungsmodus:elink. kînnen Sie die
:link reftype=hd res=12220.zusÑtzliche Information zur CD Ñndern:elink..

.********************************************************************
:h3 res=12130 name=PANEL_TE_DISP_SCROLLBAR.Track numbers
:i2 REFID=INDEX_TRACK.numbers (in the title editor)
:i2 REFID=INDEX_NUMBER.of a track (in the title editor)
:lines align=center.:hp7.Track numbers:ehp7.:elines.
:p.Die linke Auswahlliste zeigt die Nummern aller Spuren auf der CD an.
Die Nummer der ausgewÑhlten Spur ist markiert.
Im :link reftype=fn refid=librarymode.Bibliotheksmodus:elink.
kînnen Sie hier die zu betrachtene Spur auswÑhlen,
im :link reftype=fn refid=changemode.énderungsmodus:elink.
die zu verÑndernde
:link reftype=hd res=12230.Spur auswÑhlen:elink..

.********************************************************************
:h3 res=12140 name=PANEL_TE_DISP_TRACKTITLE.Track title
:i2 REFID=INDEX_TRACK.title (in the title editor)
:i2 REFID=INDEX_TITLE.of a track (in the title editor)
:lines align=center.:hp7.Spurtitel:ehp7.:elines.
:p.Das obere Feld in der Box "Spurtitel" zeigt den Titel der ausgewÑhlten
Spur an. Im
:link reftype=fn refid=librarymode.Bibliotheksmodus:elink.
kînnen Sie hier die
:link reftype=hd res=12240.Spur auswÑhlen:elink., im
:link reftype=fn refid=changemode.énderungsmodus:elink. den
:link reftype=hd res=12240.Spurtitel Ñndern:elink..

.********************************************************************
:h3 res=12150 name=PANEL_TE_DISP_TRACKINFO.Additional track information
:i2 REFID=INDEX_TRACK.additional information (in the title editor)
:i2 REFID=INDEX_ADDINFO.about a track (in the title editor)
:lines align=center.:hp7.Additional track information:ehp7.:elines.
:p.Das untere Feld in der Box "Spurtitel" zeigt die zusÑtzliche Information
zu der ausgewÑhlten Spur an. Im
:link reftype=fn refid=changemode.énderungsmodus:elink. kînnen Sie die
:link reftype=hd res=12250.zusÑtzliche Information zur Spur Ñndern:elink..

.********************************************************************
:h2 res=12200 name=PANEL_TE_CONTROL.Controls
:i2 REFID=INDEX_TITLEEDITOR.controls
:i2 REFID=INDEX_CONTROL.in the title editor
:lines align=center.:hp7.Controls in the title editor:ehp7.:elines.
:ul.
:li.:link reftype=hd res=12210.CD Titel Ñndern/auswÑhlen:elink.
:li.:link reftype=hd res=12220.ZusÑtzliche CD Information Ñndern:elink.
:li.:link reftype=hd res=12230.Spurnummer auswÑhlen:elink.
:li.:link reftype=hd res=12240.Spurtitel Ñndern/auswÑhlen:elink.
:li.:link reftype=hd res=12250.ZusÑtzliche Spurinformation Ñndern:elink.
:li.:link reftype=hd res=12260.CD Bibliothek:elink.
:li.:link reftype=hd res=12261.Infofenster anzeigen:elink.
:li.:link reftype=hd res=12262.Programm bearbeiten:elink.
:li.:link reftype=hd res=12263.Titel importieren:elink.
:li.:link reftype=hd res=12270.AusgewÑhlte CD bearbeiten:elink.
:li.:link reftype=hd res=12271.AusgewÑhlte CD lîschen:elink.
:li.:link reftype=hd res=12280.title editor verlassen:elink.
:eul.

.********************************************************************
:h3 res=12210 name=PANEL_TE_CTRL_CDTITLE.Selecting/changing CD titles
:i2 REFID=INDEX_CD.selecting/changing (in the title editor)
:i2 REFID=INDEX_TITLE.selecting/changing of a CD (in the title editor)
:lines align=center.:hp7.Selecting/changing CD titles:ehp7.:elines.
:p.Im :link reftype=fn refid=changemode.énderungsmodus:elink.
kînnen Sie den Titel der CD hier Ñndern. Der CD Titel
kann bis zu 100 Zeichen lang sein. Bedenken Sie jedoch, da· sehr lange
Titel nicht vollstÑndig in der
:link reftype=hd res=11150.Titelleiste:elink. des
:link reftype=hd res=11000.main window:elink.
angezeigt werden kînnen.
.br
Jede énderung des CD Titels wird automatisch gespeichert.
:p.Im :link reftype=fn refid=librarymode.Bibliotheksmodus:elink.
kînnen Sie hier die zu betrachtene CD auswÑhlen. CD's in der
:link reftype=fn refid=library.CD Bibliothek:elink.,
denen Sie noch keinen Titel gegeben haben, werden unter dem
Titel "ohne Namen" angezeigt.

.********************************************************************
:h3 res=12220 name=PANEL_TE_CTRL_CDINFO.Changing additional CD information
:i2 REFID=INDEX_CD.changing additional information (in the title editor)
:i2 REFID=INDEX_ADDINFO.changing of a CD (in the title editor)
:lines align=center.:hp7.Changing additional CD information:ehp7.:elines.
:p.Im :link reftype=fn refid=changemode.énderungsmodus:elink.
kînnen Sie hier zusÑtzliche Informationen zu einer CD eintragen.
Diese Notiz kann bis zu 4000 Zeichen lang sein.
.br
Jede énderung der zusÑtzlichen Informationen wird automatisch gespeichert.
:p.Im :link reftype=fn refid=librarymode.Bibliotheksmodus:elink.
kînnen Sie die zusÑtzlichen Informationen nur betrachten aber nicht
verÑndern.

.********************************************************************
:h3 res=12230 name=PANEL_TE_CTRL_SCROLLBAR.Selecting track numbers
:i2 REFID=INDEX_TRACK.selecting number (in the title editor)
:i2 REFID=INDEX_NUMBER.selecting track number (in the title editor)
:lines align=center.:hp7.Selecting track numbers:ehp7.:elines.
:p.In dieser Auswahlliste kînnen Sie den Spurtitel auswÑhlen, den
Sie
:link reftype=hd res=12140.betrachten:elink.
oder
:link reftype=hd res=12240.Ñndern:elink.
wollen

.********************************************************************
:h3 res=12240 name=PANEL_TE_CTRL_TRACKTITLE.Selecting/changing track titles
:i2 REFID=INDEX_TRACK.selecting/changing title (in the title editor)
:i2 REFID=INDEX_TITLE.selecting/changing track title (in the title editor)
:lines align=center.:hp7.Selecting/changing track titles:ehp7.:elines.
:p.Im :link reftype=fn refid=changemode.énderungsmodus:elink.
kînnen Sie hier die Spurtitel der CD Ñndern. Jeder Spurtitel
kann bis zu 100 Zeichen lang sein. Bedenken Sie jedoch, da· sehr lange
Titel nicht vollstÑndig in der
:link reftype=hd res=11150.Titelanzeige:elink. des
:link reftype=hd res=11000.main window:elink.
angezeigt werden kînnen.
.br
Jede énderung eines Spurtitels wird automatisch gespeichert.
:p.Die Nummer des gerade angezeigten Spurtitels ist in den
:link reftype=hd res=12130.Spurnummern:elink. markiert. Dort kînnen
Sie auch eine andere
:link reftype=hd res=12230.Spurnummer auswÑhlen:elink..
Wenn Sie sich im Eingabefeld fÅr den Spurtitel befinden,
kînnen Sie auch mit folgenden
:link reftype=hd res=12300.Tasten:elink.
eine andere Spur auswÑhlen&colon.
:dl break=fit tsize=15.
:dthd.:hp3.Taste:ehp3.
:ddhd.:hp3.Befehl:ehp3.
:dt.:hp2.Eingabe:ehp2.
:dd.Springt zur nÑchsten Spur oder zur ersten Spur, falls Sie die letzte
Spur bearbeiten.
:dt.:hp2.&darrow.:ehp2.
:dd.Springt zur nÑchsten Spur.
:dt.:hp2.&uarrow.:ehp2.
:dd.Springt zur vorherigen Spur.
:dt.:hp2.Strg+&darrow.:ehp2.
:dd.Springt zur letzten Spur.
:dt.:hp2.Strg+&uarrow.:ehp2.
:dd.Springt zur ersten Spur.
:edl.
:p.Im :link reftype=fn refid=librarymode.Bibliotheksmodus:elink.
kînnen Sie sich hier die Spurtitel der ausgewÑhlten CD betrachten und
auswÑhlen.

.********************************************************************
:h3 res=12250 name=PANEL_TE_CTRL_TRACKINFO.Changing additional track information
:i2 REFID=INDEX_TRACK.changing additional information (in the title editor)
:i2 REFID=INDEX_ADDINFO.changing additional track information (in the title editor)
:lines align=center.:hp7.Changing additional track information:ehp7.:elines.
:p.Im :link reftype=fn refid=changemode.énderungsmodus:elink.
kînnen Sie hier zusÑtzliche Informationen zu einer Spur eintragen.
Diese Notiz kann bis zu 4000 Zeichen lang sein.
.br
Jede énderung der zusÑtzlichen Informationen wird automatisch gespeichert.
:p.Die Nummer des gerade angezeigten Spurtitels ist in den
:link reftype=hd res=12130.Spurnummern:elink. markiert. Dort kînnen
Sie auch eine andere
:link reftype=hd res=12230.Spurnummer auswÑhlen:elink..
:p.Im :link reftype=fn refid=librarymode.Bibliotheksmodus:elink.
kînnen die zusÑtzlichen Informationen nur betrachtet aber nicht
verÑndert werden.

.********************************************************************
:h3 res=12260 name=PANEL_TE_CTRL_LIBRARY.CD library
:i2 REFID=INDEX_LIBRARY.activate (in the title editor)
:i2 REFID=INDEX_CD.library (in the title editor)
:lines align=center.:hp7.Command&colon. CD library:ehp7.:elines.
:p.Mit diesem Befehl setzen Sie den
:link reftype=hd res=12000.title editor:elink.
in den
:link reftype=fn refid=librarymode.Bibliotheksmodus:elink.
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit dem Knopf :hp7.B:ehp7.:hp2.ibliothek:ehp2.
:li.Mit der :link reftype=hd res=12300.Tastenkombination:elink. :hp2.Strg+L:ehp2.
:eul.

.********************************************************************
:h3 res=12261 name=PANEL_TE_CTRL_INFO.Display info window
:i2 REFID=INDEX_INFOWINDOW.display (in the title editor)
:lines align=center.:hp7.Command&colon. display info window:ehp7.:elines.
:p.Dieser Befehl zeigt das
:link reftype=hd res=14000.Infofenster:elink.
fÅr die ausgewÑhlte CD an. Er ist im
:link reftype=fn refid=changemode.énderungsmodus:elink.
und im
:link reftype=fn refid=librarymode.Bibliotheksmodus:elink.
gÅltig.
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit dem Knopf :hp7.I:ehp7.:hp2.nfo:ehp2.
:li.Mit der :link reftype=hd res=12300.Tastenkombination:elink. :hp2.Strg+I:ehp2.
:eul.

.********************************************************************
:h3 res=12262 name=PANEL_TE_CTRL_PROGRAM.Starting the program editor
:i2 REFID=INDEX_PROGRAMEDITOR.starting (in the title editor)
:lines align=center.:hp7.Command&colon. Starting the program editor:ehp7.:elines.
:p.Dieser Befehl ruft den
:link reftype=hd res=13000.program editor:elink.
fÅr die ausgewÑhlte CD auf. Er ist im
:link reftype=fn refid=changemode.énderungsmodus:elink.
und im
:link reftype=fn refid=librarymode.Bibliotheksmodus:elink.
gÅltig.

:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit dem Knopf :hp7.P:ehp7.:hp2.rogramm:ehp2.
:li.Mit der :link reftype=hd res=12300.Tastenkombination:elink. :hp2.Strg+P:ehp2.
:eul.

.********************************************************************
:h3 res=12263 name=PANEL_TE_CTRL_IMPORT.Import titles
:isyn ROOT=import.import
:i1 ROOTS='import' ID=INDEX_IMPORT.Import
:lines align=center.:hp7.Command&colon. import titles:ehp7.:elines.
:p.Dieser Befehl ist zur Zeit noch ohne Funktion.
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit dem Knopf :hp2.I:ehp2.:hp7.m:ehp7.:hp2.port:ehp2.
:eul.

.********************************************************************
:h3 res=12270 name=PANEL_TE_CTRL_CHANGE.Change selected CD
:i2 REFID=INDEX_CD.change titles (in the title editor)
:lines align=center.:hp7.Command&colon. change selected CD:ehp7.:elines.
:p.Mit diesem Befehl setzen Sie den
:link reftype=hd res=12000.title editor:elink.
in den
:link reftype=fn refid=changemode.énderungsmodus:elink.
fÅr die ausgewÑhlte CD.
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit dem Knopf :hp7.B:ehp7.:hp2.earbeiten:ehp2.
:li.Mit der :link reftype=hd res=12300.Tastenkombination:elink. :hp2.Strg+L:ehp2.
:eul.

.********************************************************************
:h3 res=12271 name=PANEL_TE_CTRL_DELETE.Delete selected CD
:i2 REFID=INDEX_CD.delete titles (in the title editor)
:i2 REFID=INDEX_LIBRARY.delete CD (in the title editor)
:i2 REFID=INDEX_TITLE.deleted titles of a CD (in the title editor)
:lines align=center.:hp7.Command&colon. Delete selected CD:ehp7.:elines.
:p.Dieser Befehl lîscht die ausgewÑhlte CD aus der
:link reftype=fn refid=library.CD Bibliothek:elink..
Um sicher zu gehen, mÅssen Sie den Befehl vor der AusfÅhrung noch
bestÑtigen.
:caution.
Mit dem Lîschen der CD gehen auch alle gespeicherten Titel, Informationen
und das gespeicherte Programm verloren!
:ecaution.
:note.
Es ist nicht mîglich, die momentan eingelegte CD vîllig aus der
:link reftype=fn refid=library.CD Bibliothek:elink. zu lîschen.
Es werden zwar alle gespeicherten Titel, Informationen
und das gespeicherte Programm gelîscht, aber die CD wird sofort
wieder mit einem Eintrag "ohne Namen" in der
:link reftype=fn refid=library.CD Bibliothek:elink. eingetragen.
Dieser Eintrag wird sichtbar, sobald Sie den
:link reftype=fn refid=librarymode.Bibliotheksmodus:elink.
erneut aktivieren.
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit dem Knopf :hp7.L:ehp7.:hp2.îschen:ehp2.
:eul.


.********************************************************************
:h3 res=12280 name=PANEL_TE_CTRL_QUIT.Quit title editor
:i2 REFID=INDEX_TITLEEDITOR.quit
:lines align=center.:hp7.Command&colon. quit title editor:ehp7.:elines.
:p.Dieser Befehl beendet den title editor. énderungen werden automatisch
gespeichert.
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit dem Knopf :hp7.V:ehp7.:hp2.erlassen:ehp2.
:li.Mit der :link reftype=hd res=12300.Tastenkombination:elink. :hp2.Strg+Q:ehp2.
:eul.

.********************************************************************
:h2 res=12300 name=PANEL_TE_KEYBOARD.Keyboard and mouse shortcuts
:i2 REFID=INDEX_TITLEEDITOR.keyboard and mouse shortcuts
:i2 REFID=INDEX_KEYBOARD.shortcuts in the title editor
:i2 REFID=INDEX_MOUSE.shortcuts in the title editor
:lines align=center.:hp7.Keyboard and mouse shortcuts in the title editor:ehp7.:elines.
:dl break=fit tsize=15.
:dthd.:hp3.Taste:ehp3.
:ddhd.:hp3.Befehl:ehp3.
:dt.:hp2.Strg+I:ehp2.
:dd.FÅhrt den :link reftype=hd res=12261.Infofenster anzeigen:elink. Befehl aus
:dt.:hp2.Strg+L:ehp2.
:dd.FÅhrt den :link reftype=hd res=12260.CD Bibliothek:elink. Befehl oder den
:link reftype=hd res=12270.AusgewÑhlte CD bearbeiten:elink. Befehl aus
:dt.:hp2.Strg+P:ehp2.
:dd.FÅhrt den :link reftype=hd res=12262.Programm bearbeiten:elink. Befehl aus
:dt.:hp2.Strg+Q:ehp2.
:dd.FÅhrt den :link reftype=hd res=12280.title editor verlassen:elink. Befehl aus
:edl.
:p.Wenn Sie sich im Eingabefeld fÅr den Spurtitel befinden,
kînnen Sie auch mit folgenden Tasten arbeiten&colon.
:dl break=fit tsize=15.
:dt.:hp2.Eingabe:ehp2.
:dd.Springt zur nÑchsten Spur oder zur ersten Spur, falls Sie die letzte
Spur bearbeiten.
:dt.:hp2.&darrow.:ehp2.
:dd.Springt zur nÑchsten Spur.
:dt.:hp2.&uarrow.:ehp2.
:dd.Springt zur vorherigen Spur.
:dt.:hp2.Strg+&darrow.:ehp2.
:dd.Springt zur letzten Spur.
:dt.:hp2.Strg+&uarrow.:ehp2.
:dd.Springt zur ersten Spur.
:edl.
:p.:lines align=center.:hp7.Mausbefehle im title editor:ehp7.:elines.
:p.Im title editor sind keine besonderen Mausbefehle definiert.


.********************************************************************
:h2 res=12400 name=PANEL_TE_MENUS.Menu commands
:i2 REFID=INDEX_TITLEEDITOR.menu commands
:i2 REFID=INDEX_MENU.in the title editor
:lines align=center.:hp7.Menu commands in the editor:ehp7.:elines.
:p.Im title editor sind keine besonderen MenÅbefehle definiert.

.********************************************************************

.im program.ipf
.********************************************************************
.********************************************************************
:h1 res=13000 name=PANEL_PLAYLIST.Program editor
:i2 REFID=INDEX_WINDOWS.program editor
:i2 REFID=INDEX_PROGRAMEDITOR.overview
:i2 REFID=INDEX_PROGRAM.editor
:lines align=center.:hp7.The program editor:ehp7.:elines.
:p.Der program editor dient dazu, die Reihenfolge der abzuspielenden
Titel einer CD (das Programm) festzulegen.
.br
StandardmÑ·ig enthÑlt das
Programm alle Audiotitel der CD in der Reihenfolge, wie sie auch auf
der CD angeordnet sind. Dieses Programm kann von Ihnen aber fÅr jede
CD individuell geÑndert werden. Die Reihenfolge der Titel kann dabei
vîllig frei gewÑhlt werden, und jeder Titel kann auch mehrfach oder
Åberhaupt nicht im Programm auftauchen. Die einzigen EinschrÑnkungen
fÅr das Programm sind, da· es mindestens einen, hîchstens aber 256
Titel enthÑlt, und da· das Programms nicht lÑnger als 100 Stunden ist.
Diese Bedingungen werden vom program editor automatisch Åberwacht.
:p.Der program editor kann vom
:link reftype=hd res=11000.main window:elink.
aus mit dem Befehl
:link reftype=hd res=11231.program editor starten:elink.
fÅr die eingelegte CD aufgerufen werden. Das vom CD Spieler verwendete
Programm, siehe
":link reftype=hd res=11120.Programmanzeige im main window:elink.",
wird aber erst geÑndert, wenn im program editor der Befehl
:link reftype=hd res=13231.Programm speichern:elink.
ausgefÅhrt wird.
.br
Es ist aber auch mîglich, das Programm einer CD aus der
:link reftype=fn refid=library.CD Bibliothek:elink.
des CD Spielers zu Ñndern, ohne die CD einzulegen. Dazu wird die CD im
:link reftype=hd res=12000.title editor:elink.
ausgewÑhlt und der program editor mit dem Befehl
:link reftype=hd res=12262.Programm bearbeiten:elink.
gestartet.
:p.Mit den
:link reftype=hd res=13100.Anzeigeelementen des program editors:elink.
kann man sich einen öberblick Åber die vorhandenen
:link reftype=hd res=13120.Titel auf der CD:elink.
und das
:link reftype=hd res=13140.momentane gewÑhlte Programm:elink.
verschaffen.
.br
Mit der
:link reftype=hd res=13200.Steuerung des program editors:elink.
ist es mîglich, das Programm auf vielfÑltige Art zu verÑndern.

.********************************************************************
:h2 res=13100 name=PANEL_PE_DISPLAY.Displays
:i2 REFID=INDEX_PROGRAMEDITOR.displays
:i2 REFID=INDEX_DISPLAY.in the program editor
:lines align=center.:hp7.Displays in the program editor:ehp7.:elines.
:ul.
:li.:link reftype=hd res=13110.CD Anzeige:elink.
:li.:link reftype=hd res=13120.Titel auf der CD:elink.
:li.:link reftype=hd res=13130.Programmanzeige:elink.
:li.:link reftype=hd res=13140.Titel im Programm:elink.
:eul.

.********************************************************************
:h3 res=13110 name=PANEL_PE_DISP_CD.CD display
:i2 REFID=INDEX_TOTALLENGTH.of the CD (in the program editor)
:i2 REFID=INDEX_TRACKS.on the CD (in the program editor)
:lines align=center.:hp7.CD display:ehp7.:elines.
:p.In dem Kasten "CD" wird die GesamtlÑnge der CD und die
Gesamtanzahl von Titeln auf der CD angezeigt. Darunter kînnen
sich auch Nicht-Audiotitel befinden, die nicht ins Programm
Åbernommen werden kînnen.
:note.
Die Darstellung der GesamtlÑnge lÑ·t sich in den
:link reftype=hd res=15000.settings:elink. unter
:link reftype=hd res=15100.Zeitformat:elink. Ñndern.

.********************************************************************
:h3 res=13120 name=PANEL_PE_DISP_CDSELECT.Titles on the CD
:i2 REFID=INDEX_TITLE.on the CD (in the program editor)
:lines align=center.:hp7.Titles on the CD:ehp7.:elines.
:p.In der linken Auswahlliste werden alle Titel auf der CD angezeigt.
.br
Vor jedem Titel steht die Spurnummer des Titels in Klammern. Die
Spurnummern von Audiotiteln werden in eckigen Klammern angezeigt,
die Spurnummern von Nicht-Audiotiteln werden in runden Klammern angezeigt.
:p.In dieser Auswahlliste kînnen Titel zum EinfÅgen in das Programm
ausgewÑhlt werden, siehe
":link reftype=hd res=13210.Titelauswahl auf der CD:elink.",
":link reftype=hd res=13240.Titel am Anfang einfÅgen:elink.",
":link reftype=hd res=13241.Titel einfÅgen:elink." und
":link reftype=hd res=13242.Titel am Ende einfÅgen:elink.".

.********************************************************************
:h3 res=13130 name=PANEL_PE_DISP_PROGRAM.Program display
:i2 REFID=INDEX_TOTALLENGTH.of the program (in the program editor)
:i2 REFID=INDEX_TRACKS.in the program (in the program editor)
:lines align=center.:hp7.Program display:ehp7.:elines.
:p.In dem Kasten "Programm" wird die GesamtlÑnge des momentanen Programms
und die Gesamtanzahl von Titeln im Programm angezeigt.
:note.
Die Darstellung der GesamtlÑnge lÑ·t sich in den
:link reftype=hd res=15000.settings:elink. unter
:link reftype=hd res=15100.Zeitformat:elink. Ñndern.

.********************************************************************
:h3 res=13140 name=PANEL_PE_DISP_PROGRAMSELECT.Titles in the program
:i2 REFID=INDEX_TITLE.in the program (in the program editor)
:i2 REFID=INDEX_PROGRAM.selected titles (in the program editor)
:lines align=center.:hp7.Titles in the program:ehp7.:elines.
:p.In der rechten Auswahlliste werden alle Titel im Programm angezeigt.
:p.In dieser Auswahlliste kînnen auch Titel zum Entfernen aus dem Programm
ausgewÑhlt werden, siehe
":link reftype=hd res=13220.Titelauswahl im Programm:elink.".

.********************************************************************
:h2 res=13200 name=PANEL_PE_CONTROL.Controls
:i2 REFID=INDEX_PROGRAMEDITOR.controls
:i2 REFID=INDEX_CONTROL.in the program editor
:lines align=center.:hp7.Controls in the program editor:ehp7.:elines.
:ul.
:li.:link reftype=hd res=13210.Titelauswahl auf der CD:elink.
:li.:link reftype=hd res=13220.Titelauswahl im Programm:elink.
:li.:link reftype=hd res=13230.Infofenster anzeigen:elink.
:li.:link reftype=hd res=13231.Programm speichern:elink.
:li.:link reftype=hd res=13232.program editor verlassen:elink.
:li.:link reftype=hd res=13240.Titel am Anfang einfÅgen:elink.
:li.:link reftype=hd res=13241.Titel einfÅgen:elink.
:li.:link reftype=hd res=13242.Titel am Ende einfÅegen:elink.
:li.:link reftype=hd res=13243.Titel entfernen:elink.
:li.:link reftype=hd res=13250.Programm mischen:elink.
:li.:link reftype=hd res=13251.Programm umdrehen:elink.
:li.:link reftype=hd res=13252.Standardprogramm wÑhlen:elink.
:eul.

.********************************************************************
:h3 res=13210 name=PANEL_PE_CTRL_CDSELECT.Title selection on the CD
:i2 REFID=INDEX_TITLE.selecting on the CD (in the program editor)
:lines align=center.:hp7.Title selection on the CD:ehp7.:elines.
:p.In der linken Auswahlliste kînnen Titel auf der CD ausgewÑhlt
werden, um sie in das Programm einzufÅgen. Die Auswahl von
Nicht-Audiotiteln, siehe
":link reftype=hd res=13120.Titel auf der CD:elink.",
ist zwar mîglich, wird aber von den Befehlen
:link reftype=hd res=13240.Titel am Anfang einfÅgen:elink.,
:link reftype=hd res=13241.Titel einfÅgen:elink. und
:link reftype=hd res=13242.Titel am Ende einfÅgen:elink.
ignoriert.

.********************************************************************
:h3 res=13220 name=PANEL_PE_CTRL_PROGRAMSELECT.Title selection in the program
:i2 REFID=INDEX_TITLE.selecting in the program (in the program editor)
:i2 REFID=INDEX_PROGRAM.selecting titles (in the program editor)
:lines align=center.:hp7.Title selection in the program:ehp7.:elines.
:p.In der rechten Auswahlliste kînnen Titel im Programm ausgewÑhlt
werden, um sie aus dem Programm zu entfernen, siehe
":link reftype=hd res=13243.Titel entfernen:elink.". Au·erdem bestimmt
der erste ausgewÑhlte Titel die Stelle, an der neue Titel mit dem Befehl
:link reftype=hd res=13241.Titel einfÅgen:elink. eingefÅgt werden.
:note.
Das Aussehen dieser Auswahlliste beim EinfÅgen oder Lîschen von Titeln
kann unter
:link reftype=hd res=15000.settings:elink.
:link reftype=hd res=15200.Animation:elink.
mit der Einstellung
:link reftype=hd res=15230.Listenanimation:elink.
beeinflu·t werden.


.********************************************************************
:h3 res=13230 name=PANEL_PE_CTRL_INFO.Display info window
:i2 REFID=INDEX_INFOWINDOW.display (in the program editor)
:lines align=center.:hp7.Command&colon. display info window:ehp7.:elines.
:p.Dieser Befehl zeigt das
:link reftype=hd res=14000.Infofenster:elink.
fÅr die CD an, deren Programm bearbeitet wird.
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit dem Knopf :hp7.I:ehp7.:hp2.nfo:ehp2.
:li.Mit der :link reftype=hd res=13300.Tastenkombination:elink. :hp2.Strg+I:ehp2.
:eul.

.********************************************************************
:h3 res=13231 name=PANEL_PE_CTRL_SAVE.Save program
:i2 REFID=INDEX_PROGRAM.saving (in the program editor)
:lines align=center.:hp7.Command&colon. save program:ehp7.:elines.
:p.Mit diesem Befehl wird das Programm fÅr die CD gespeichert. Wenn es sich
um die momentan eingelegte CD handelt, so Ñndert sich auch das Programm im
:link reftype=hd res=11000.main window:elink. entsprechend&colon. die
Wiedergabe wird gestoppt und das neue Programm in der
:link reftype=hd res=11120.Programmanzeige Im main window:elink.
dargestellt.
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit dem Knopf :hp7.S:ehp7.:hp2.peichern:ehp2.
:li.Mit der :link reftype=hd res=13300.Tastenkombination:elink. :hp2.Strg+S:ehp2.
:eul.

.********************************************************************
:h3 res=13232 name=PANEL_PE_CTRL_QUIT.Quit program editor
:i2 REFID=INDEX_PROGRAMEDITOR.quit
:lines align=center.:hp7.Command&colon. quit program editor:ehp7.:elines.
:p.Mit diesem Befehl wird der
:link reftype=hd res=13000.program editor:elink.
verlassen.
.br
Wenn das Programm geÑndert aber noch nicht gespeichert wurde, werden Sie
gefragt, ob Sie das geÑnderte
:link reftype=hd res=13231.Programm speichern:elink.
wollen.
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit dem Knopf :hp7.V:ehp7.:hp2.erlassen:ehp2.
:li.Mit der :link reftype=hd res=13300.Tastenkombination:elink. :hp2.Strg+Q:ehp2.
:eul.

.********************************************************************
:h3 res=13240 name=PANEL_PE_CTRL_INSERTBEGIN.Insert titles at begin
:i2 REFID=INDEX_PROGRAM.inserting titles at begin (in the program editor)
:i2 REFID=INDEX_TITLE.inserting at begin of the program (in the program editor)
:lines align=center.:hp7.Command&colon. insert titles at begin:ehp7.:elines.
:p.Dieser Befehl fÅgt die in der
:link reftype=hd res=13210.Titelauswahl auf der CD:elink.
angewÑhlten Titel am Anfang des Programms ein.
:note.
Es werden nur soviel Titel eingefÅgt, da· das Programm nicht mehr als 256
Titel enthÑlt und nicht lÑnger als 100 Stunden wird. Kînnen deshalb nicht
alle ausgewÑhlten Titel eingefÅgt werden, werden zuerst die Titel am Anfang
der Auswahl eingefÅgt.
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit dem Knopf :hp2.Am :ehp2.:hp7.A:ehp7.:hp2.nfang:ehp2.
:li.Mit der :link reftype=hd res=13300.Tastenkombination:elink. :hp2.Strg+Eingabe:ehp2.
:eul.

.********************************************************************
:h3 res=13241 name=PANEL_PE_CTRL_INSERT.Insert titles
:i2 REFID=INDEX_PROGRAM.inserting titles (in the program editor)
:i2 REFID=INDEX_TITLE.inserting in the program (in the program editor)
:lines align=center.:hp7.Command&colon. insert titles:ehp7.:elines.
:p.Dieser Befehl fÅgt die in der
:link reftype=hd res=13210.Titelauswahl auf der CD:elink.
angewÑhlten Titel vor dem ersten in der
:link reftype=hd res=13220.Titelauswahl im Programm:elink.
angewÑhlten Titel in das Programm ein. Wenn kein Titel in der
:link reftype=hd res=13220.Titelauswahl im Programm:elink.
angewÑhlt ist, werden die Titel am Ende des Programms eingefÅgt.
:note.
Es werden nur soviel Titel eingefÅgt, da· das Programm nicht mehr als 256
Titel enthÑlt und nicht lÑnger als 100 Stunden wird. Kînnen deshalb nicht
alle ausgewÑhlten Titel eingefÅgt werden, werden zuerst die Titel am Anfang
der Auswahl eingefÅgt.
:ul.
:li.Mit dem Knopf :hp7.E:ehp7.:hp2.infÅgen:ehp2.
:li.Mit der :link reftype=hd res=13300.Taste:elink. :hp2.EinfÅgen:ehp2.
:eul.

.********************************************************************
:h3 res=13242 name=PANEL_PE_CTRL_INSERTEND.Insert titles at end
:i2 REFID=INDEX_PROGRAM.inserting titles at end (in the program editor)
:i2 REFID=INDEX_TITLE.inserting at the end of the program (in the program editor)
:lines align=center.:hp7.Command&colon. insert titles at end:ehp7.:elines.
:p.Dieser Befehl fÅgt die in der
:link reftype=hd res=13210.Titelauswahl auf der CD:elink.
angewÑhlten Titel am Ende des Programms ein.
:note.
Es werden nur soviel Titel eingefÅgt, da· das Programm nicht mehr als 256
Titel enthÑlt und nicht lÑnger als 100 Stunden wird. Kînnen deshalb nicht
alle ausgewÑhlten Titel eingefÅgt werden, werden zuerst die Titel am Anfang
der Auswahl eingefÅgt.
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit dem Knopf :hp2.Am E:ehp2.:hp7.n:ehp7.:hp2.de:ehp2.
:li.Mit der :link reftype=hd res=13300.Taste:elink. :hp2.Eingabe:ehp2.
:eul.

.********************************************************************
:h3 res=13243 name=PANEL_PE_CTRL_DELETE.Delete titles
:i2 REFID=INDEX_PROGRAM.deleting titles (in the program editor)
:i2 REFID=INDEX_TITLE.deleting from the program (in the program editor)
:lines align=center.:hp7.Command&colon. delete titles:ehp7.:elines.
:p.Dieser Befehl entfernt alle in der
:link reftype=hd res=13220.Titelauswahl im Programm:elink.
angewÑhlten Titel aus dem Programm.
:note.
Wenn alle Titel des Programms ausgewÑhlt sind, werden alle Titel bis
auf den ersten in der Auswahl entfernt, da das Programm mindestens
einem Titel enhalten mu·.
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit dem Knopf :hp2.Ent:ehp2.:hp7.f:ehp7.:hp2.ernen:ehp2.
:li.Mit der :link reftype=hd res=13300.Tastenkombination:elink. :hp2.Strg+D:ehp2.
:li.Mit der :link reftype=hd res=13300.Taste:elink. :hp2.Lîschen:ehp2.
:eul.

.********************************************************************
:h3 res=13250 name=PANEL_PE_CTRL_SHUFFLE.Mix program
:i2 REFID=INDEX_PROGRAM.mixing (in the program editor)
:lines align=center.:hp7.Command&colon. mix program:ehp7.:elines.
:p.Dieser Befehl mischt alle Titel im Programm in einer zufÑlligen
Reihenfolge.
:link reftype=hd res=13130.GesamtlÑnge und Anzahl der Titel:elink.
werden dadurch nicht verÑndert.
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit dem Knopf :hp7.M:ehp7.:hp2.ischen:ehp2.
:li.Mit der :link reftype=hd res=13300.Tastenkombination:elink. :hp2.Strg+U:ehp2.
:eul.

.********************************************************************
:h3 res=13251 name=PANEL_PE_CTRL_REVERSE.Reverse program
:i2 REFID=INDEX_PROGRAM.reversing (in the program editor)
:lines align=center.:hp7.Command&colon. reverse program:ehp7.:elines.
:p.Dieser Befehl dreht die Reihenfolge der Titel im Programm um.
:link reftype=hd res=13130.GesamtlÑnge und Anzahl der Titel:elink.
werden dadurch nicht verÑndert.
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit dem Knopf :hp7.U:ehp7.:hp2.mdrehen:ehp2.
:li.Mit der :link reftype=hd res=13300.Tastenkombination:elink. :hp2.Strg+R:ehp2.
:eul.

.********************************************************************
:h3 res=13252 name=PANEL_PE_CTRL_STANDARD.Standard program
:i2 REFID=INDEX_PROGRAM.standard (in the program editor)
:lines align=center.:hp7.Command&colon. standard program:ehp7.:elines.
:p.Dieser Befehl stellt das Standardprogramm fÅr die CD ein. Das
Standardprogramm besteht aus allen Audiotiteln auf der CD in derselben
Reihenfolge, wie sie auch auf der CD angeordnet sind.
:caution.
Mit der AusfÅhrung dieses Befehls gehen alle individuellen énderungen am
Programm verloren.
:ecaution.
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit dem Knopf :hp2.S:ehp2.:hp7.t:ehp7.:hp2.andard:ehp2.
:li.Mit der :link reftype=hd res=13300.Tastenkombination:elink. :hp2.Strg+T:ehp2.
:eul.

.********************************************************************
:h2 res=13300 name=PANEL_PE_KEYBOARD.Keyboard and mouse shortcuts
:i2 REFID=INDEX_PROGRAMEDITOR.keyboard and mouse shortcuts
:i2 REFID=INDEX_KEYBOARD.shortcuts in the program editor
:i2 REFID=INDEX_MOUSE.shortcuts in the program editor
:lines align=center.:hp7.Keyboard and mouse shortcuts in the program editor:ehp7.:elines.
:dl break=fit tsize=15.
:dthd.:hp3.Taste:ehp3.
:ddhd.:hp3.Befehl:ehp3.
:dt.:hp2.EinfÅgen:ehp2.
:dd.FÅhrt den :link reftype=hd res=13241.Titel einfÅgen:elink. Befehl aus
:dt.:hp2.Eingabe:ehp2.
:dd.FÅhrt den :link reftype=hd res=13242.Titel am Ende einfÅgen:elink. Befehl aus
:dt.:hp2.Strg+Eingabe:ehp2.
:dd.FÅhrt den :link reftype=hd res=13240.Titel am Anfang einfÅgen:elink. Befehl aus
:dt.:hp2.Lîschen:ehp2.
:dd.FÅhrt den :link reftype=hd res=13243.Titel entfernen:elink. Befehl aus
:dt.:hp2.Strg+D:ehp2.
:dd.FÅhrt den :link reftype=hd res=13243.Titel entfernen:elink. Befehl aus
:dt.:hp2.Strg+I:ehp2.
:dd.FÅhrt den :link reftype=hd res=13230.Infofenster anzeigen:elink. Befehl aus
:dt.:hp2.Strg+Q:ehp2.
:dd.FÅhrt den :link reftype=hd res=13232.program editor verlassen:elink. Befehl aus
:dt.:hp2.Strg+R:ehp2.
:dd.FÅhrt den :link reftype=hd res=13251.Program umdrehen:elink. Befehl aus
:dt.:hp2.Strg+S:ehp2.
:dd.FÅhrt den :link reftype=hd res=13231.Program speichern:elink. Befehl aus
:dt.:hp2.Strg+T:ehp2.
:dd.FÅhrt den :link reftype=hd res=13252.Standardprogramm wÑhlen:elink. Befehl aus
:dt.:hp2.Strg+U:ehp2.
:dd.FÅhrt den :link reftype=hd res=13250.Programm mischen:elink. Befehl aus
:edl.

:p.:lines align=center.:hp7.Mausbefehle im program editor:ehp7.:elines.
:p.Im program editor sind keine besonderen MenÅbefehle definiert.

.********************************************************************
:h2 res=13400 name=PANEL_PE_MENUS.Menu commands
:i2 REFID=INDEX_PROGRAMEDITOR.menu commands
:i2 REFID=INDEX_MENU.in the program editor
:lines align=center.:hp7.Menu commands in the program editor:ehp7.:elines.
:p.Im program editor sind keine besonderen MenÅbefehle definiert.

.********************************************************************

.im info.ipf
.********************************************************************
.********************************************************************
:h1 res=14000 name=PANEL_INFO.Info window
:i2 REFID=INDEX_WINDOWS.info window
:i2 REFID=INDEX_INFOWINDOW.overview
:i2 REFID=INDEX_CD.info window
:lines align=center.:hp7.The info window:ehp7.:elines.
:p.Das Infofenster gibt Ihnen genauere Informationen Åber eine CD.
:p.FÅr die eingelegte CD zeigen Sie das Infofenster mit dem Befehl
:link reftype=hd res=11233.Infofenster anzeigen:elink. im
:link reftype=hd res=11000.main window:elink. auf.
Es ist aber auch mîglich, das Infofenster fÅr eine CD aus der
:link reftype=fn refid=library.CD Bibliothek:elink.
des CD Spielers aufzurufen, ohne die CD einzulegen. Dazu wird die CD im
:link reftype=hd res=12000.title editor:elink.
ausgewÑhlt und das Infofenster mit dem Befehl
:link reftype=hd res=12261.Infofenster anzeigen:elink.
angezeigt. Auch im
:link reftype=hd res=13000.program editor:elink.
ist es mîglich das Infofenster fÅr die CD, deren Programm gerade
bearbeitet wird, anzuzeigen. Benutzen Sie dazu den Befehl
:link reftype=hd res=13230.Infofenster anzeigen:elink. im
:link reftype=hd res=13000.program editor:elink..

.********************************************************************
:h2 res=14100 name=PANEL_IN_DISPLAY.Displays
:i2 REFID=INDEX_INFOWINDOW.displays
:i2 REFID=INDEX_DISPLAY.in the info window
:lines align=center.:hp7.Displays in the info window:ehp7.:elines.
:ul.
:li.:link reftype=hd res=14110.GesamtlÑnge der CD:elink.
:li.:link reftype=hd res=14111.Startposition der CD:elink.
:li.:link reftype=hd res=14112.Spuren insgesamt:elink.
:li.:link reftype=hd res=14120.UPC:elink.
:li.:link reftype=hd res=14121.MMPM ID:elink.
:li.:link reftype=hd res=14122.Interne ID:elink.
:li.:link reftype=hd res=14130.Spurnummer:elink.
:li.:link reftype=hd res=14131.Audiospur:elink.
:li.:link reftype=hd res=14132.Kopieren erlaubt:elink.
:li.:link reftype=hd res=14133.Preemphasis:elink.
:li.:link reftype=hd res=14134.KanÑle:elink.
:li.:link reftype=hd res=14135.Startposition der Spur:elink.
:li.:link reftype=hd res=14136.LÑnge der Spur:elink.
:eul.

.********************************************************************
:h3 res=14110 name=PANEL_IN_DISP_LENGTHCD.Total length of the CD
:i2 REFID=INDEX_TOTALLENGTH.of the CD (in the info window)
:i2 REFID=INDEX_CD.total length (in the info window)
:lines align=center.:hp7.Total length of the CD:ehp7.:elines.
:p.Rechts oben neben der Ausschrift "LÑnge" wird die GesamtlÑnge der CD
angezeigt. Darunter kînnen sich auch Nicht-Audiotitel befinden,
die vom CD Spieler nicht abgespielt werden kînnen.
:note.
Die Darstellung der GesamtlÑnge lÑ·t sich in den
:link reftype=hd res=15000.settings:elink. unter
:link reftype=hd res=15100.Zeitformat:elink. verÑndern.

.********************************************************************
:h3 res=14111 name=PANEL_IN_DISP_STARTCD.Start position of the CD
:i2 REFID=INDEX_CD.start position (in the info window)
:i2 REFID=INDEX_STARTPOSITION.of the CD (in the info window)
:lines align=center.:hp7.Start position of the CD:ehp7.:elines.
:p.Rechts oben neben der Ausschrift "Start" wird die Startposition
der ersten Audiospur auf der CD angezeigt. Der Bereich vor dieser Position
kann vom CD Spieler nicht abgespielt werden.
:note.
Die Darstellung der Startposition lÑ·t sich in den
:link reftype=hd res=15000.settings:elink. unter
:link reftype=hd res=15100.Zeitformat:elink. verÑndern.

.********************************************************************
:h3 res=14112 name=PANEL_IN_DISP_TRACKS.Total tracks
:i2 REFID=INDEX_TRACKS.on the CD (in the info window)
:i2 REFID=INDEX_CD.total tracks (in the info window)
:lines align=center.:hp7.Total tracks:ehp7.:elines.
:p.Rechts oben neben der Ausschrift "Spuren" wird die Gesamtanzahl
der Spuren auf der CD angezeigt. Darunter kînnen sich auch
Nicht-Audiotitel befinden, die vom CD Spieler nicht abgespielt
werden kînnen.

.********************************************************************
:h3 res=14120 name=PANEL_IN_DISP_UPC.UPC
:i1 ID=INDEX_UPC.UPC
:i2 REFID=INDEX_CD.UPC (in the info window)
:lines align=center.:hp7.UPC of the CD:ehp7.:elines.
:p.Die :link reftype=fn refid=upc.UPC:elink. besteht aus 16
Dezimalziffern.

.********************************************************************
:h3 res=14121 name=PANEL_IN_DISP_MMPMID.MMPM ID
:i2 REFID=INDEX_ID.of MMPM
:i2 REFID=INDEX_CD.ID of MMPM (in the info window)
:lines align=center.:hp7.MMPM ID of the CD:ehp7.:elines.
:p.Die Multimediaerweiterung von OS/2 vergibt an jede Audio CD eine ID.
Diese ID besteht aus 16 Hexdezimalziffern.
:note.
Da diese ID nicht unbedingt eindeutig ist, wird sie vom CD Spieler nicht
verwendet.

.********************************************************************
:h3 res=14122 name=PANEL_IN_DISP_INTERNALID.Internal ID
:i2 REFID=INDEX_ID.internal
:i2 REFID=INDEX_CD.internal ID (in the info window)
:lines align=center.:hp7.Internal ID of the CD:ehp7.:elines.
:p.Der CD Spieler erzeugt fÅr jede CD eine interne ID, die zur Verwaltung der
:link reftype=fn refid=library.CD Bibliothek:elink. verwendet wird, siehe auch
":link reftype=hd res=12000.title editor:elink.".
:note.
Diese ID ist fÅr jede CD eindeutig. Nur zwei CD's, fÅr die die im
:link reftype=hd res=14000.Infofenster:elink.
angezeigten Informationen vollkommen identisch sind, bekommen auch dieselbe ID.
In diesem (allerdings sehr unwahrscheinlichen) Fall ist es fÅr den CD
Spieler nicht mîglich, die beiden CD's zu unterscheiden.

.********************************************************************
:h3 res=14130 name=PANEL_IN_DISP_TRACKNUMBER.Track number
:i2 REFID=INDEX_TRACK.number (in the info window)
:i2 REFID=INDEX_NUMBER.of the track (in the info window)
:lines align=center.:hp7.Track number:ehp7.:elines.
:p.Die Spurnummer der angezeigten Spur.
:note.
Die Spuren auf einer CD werden von 1 an fortlaufend durchnummeriert. Eine
CD kann maximal 99 Spuren enthalten.

.********************************************************************
:h3 res=14131 name=PANEL_IN_DISP_AUDIOTRACK.Audio track
:i1 ID=INDEX_AUDIOTRACK.Audio track
:i2 REFID=INDEX_TRACK.audio track (in the info window)
:lines align=center.:hp7.Audio track:ehp7.:elines.
:p.Diese Box ist bei Spuren, die Audioinformationen enthalten
angekreuzt. Nur diese Spuren kînnen vom CD Spieler abgespielt werden.

.********************************************************************
:h3 res=14132 name=PANEL_IN_DISP_COPYALLOWED.Copy allowed
:i1 ID=INDEX_COPY.allowed
:i2 REFID=INDEX_TRACK.copy allowed (in the info window)
:lines align=center.:hp7.Track copy allowed:ehp7.:elines.
:p.Diese Box ist bei Spuren angekreuzt, deren digitale Informationen
ohne Verletzung des Urheberrechts kopiert werden dÅrfen.

.********************************************************************
:h3 res=14133 name=PANEL_IN_DISP_PREEMPHASIS.Preemphasis
:i1 ID=INDEX_PREEMPHASIS.Preemphasis
:i2 REFID=INDEX_TRACK.preemphasis (in the info window)
:lines align=center.:hp7.Preemphasis of the track:ehp7.:elines.
:p.Diese Box ist nur bei Spuren angekreuzt, die mit
:link reftype=fn refid=preemphasis.Preemphasis:elink.
aufgenommen wurden.

.********************************************************************
:h3 res=14134 name=PANEL_IN_DISP_CHANNELS.Channels
:i2 REFID=INDEX_TRACK.channels (in the info window)
:i2 REFID=INDEX_CHANNELS.number (in the info window)
:lines align=center.:hp7.Track channels:ehp7.:elines.
:p.Dieser Wert gibt die Anzahl der AudiokanÑle einer Spur an. Bei
Audiospuren sind dies normalerweise 2, bei anderen Spuren 0.

.********************************************************************
:h3 res=14135 name=PANEL_IN_DISP_STARTTRACK.Start position of track
:i2 REFID=INDEX_TRACK.start position (in the info window)
:i2 REFID=INDEX_STARTPOSITION.of track (in the info window)
:lines align=center.:hp7.Start position of track:ehp7.:elines.
:p.Dieser Wert gibt die Startposition der Spur auf der CD an.
:note.
Die Darstellung der Startposition lÑ·t sich in den
:link reftype=hd res=15000.settings:elink. unter
:link reftype=hd res=15100.Zeitformat:elink. verÑndern.

.********************************************************************
:h3 res=14136 name=PANEL_IN_DISP_LENGTHTRACK.Length of track
:i2 REFID=INDEX_TRACK.length (in the info window)
:i2 REFID=INDEX_LENGTH.of track (in the info window)
:lines align=center.:hp7.Length of track:ehp7.:elines.
:p.Dieser Wert gibt die LÑnge der Spur an.
:note.
Die Darstellung der LÑnge lÑ·t sich in den
:link reftype=hd res=15000.settings:elink. unter
:link reftype=hd res=15100.Zeitformat:elink. verÑndern.

.********************************************************************
:h2 res=14200 name=PANEL_IN_CONTROL.Controls
:i2 REFID=INDEX_INFOWINDOW.controls
:i2 REFID=INDEX_CONTROL.in the info window
:lines align=center.:hp7.Controls in the info window:ehp7.:elines.
:ul.
:li.:link reftype=hd res=14210.Spuranzeige verschieben:elink.
:li.:link reftype=hd res=14220.Infofenster verlassen:elink.
:eul.

.********************************************************************
:h3 res=14210 name=PANEL_IN_CTRL_SCROLLBAR.Scroll track display
:i2 REFID=INDEX_TRACK.scroll display (in the info window)
:lines align=center.:hp7.Srcoll track display:ehp7.:elines.
:p.Wenn die Informationen fÅr alle Spuren nicht gleichzeitig angezeigt
werden kînnen, kînnen Sie mit dem Schiebebalken rechts neben den
Spurinformationen den Bereich der sichtbaren Spuren verschieben.

.********************************************************************
:h3 res=14220 name=PANEL_IN_CTRL_QUIT.Close info window
:i2 REFID=INDEX_INFOWINDOW.close
:lines align=center.:hp7.Close info window:ehp7.:elines.
:p.Mit diesem Befehl verlassen Sie das Infofenster.
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit dem Knopf :hp7.V:ehp7.:hp2.erlassen:ehp2.
:li.Mit der :link reftype=hd res=14300.Taste:elink. :hp2.Eingabe:ehp2.
:li.Mit der :link reftype=hd res=14300.Taste:elink. :hp2.Abbrechen:ehp2.
:li.Mit der :link reftype=hd res=14300.Tastenkombination:elink. :hp2.Strg+Q:ehp2.
:eul.

.********************************************************************
:h2 res=14300 name=PANEL_IN_KEYBOARD.Keyboard and mouse shortcuts
:i2 REFID=INDEX_INFOWINDOW.Keyboard and mouse shortcuts
:i2 REFID=INDEX_KEYBOARD.shortcuts in the info window
:i2 REFID=INDEX_MOUSE.shortcuts in the info window
:lines align=center.:hp7.Keyboard shortcuts in the info window:ehp7.:elines.
:dl break=fit tsize=15.
:dthd.:hp3.Taste:ehp3.
:ddhd.:hp3.Befehl:ehp3.
:dt.:hp2.Abbrechen:ehp2.
:dd.FÅhrt den :link reftype=hd res=14220.Infofenster verlassen:elink. Befehl aus
:dt.:hp2.Eingabe:ehp2.
:dd.FÅhrt den :link reftype=hd res=14220.Infofenster verlassen:elink. Befehl aus
:dt.:hp2.Strg+Q:ehp2.
:dd.FÅhrt den :link reftype=hd res=14220.Infofenster verlassen:elink. Befehl aus
:edl.
:p.:lines align=center.:hp7.Mouse shortcuts in the info window:ehp7.:elines.
:p.Im Infofenster sind keine besonderen Mausbefehle definiert.

.********************************************************************
:h2 res=14400 name=PANEL_IN_MENUS.Menu commands
:i2 REFID=INDEX_INFOWINDOW.menu commands
:i2 REFID=INDEX_MENU.of info window
:lines align=center.:hp7.Menu commands in the info window:ehp7.:elines.
:p.Im Infofenster sind keine besonderen MenÅbefehle definiert.

.********************************************************************
.im settings.ipf
.********************************************************************
.********************************************************************
:h1 res=15000 name=PANEL_SETTINGS.Settings
:i2 REFID=INDEX_WINDOWS.settings
:i2 REFID=INDEX_SETTINGS.overview
:lines align=center.:hp7.Settings overview:ehp7.:elines.
:p.Mit den settings kînnen Sie Aussehen und Verhalten des CD Spielers
Ñndern. Jede énderung in den settings wird sofort umgesetzt
und gespeichert. Daher ist es nicht nîtig (und mîglich), die settings
explizit zu sichern.
.br
Die settings sind in sechs Bereiche aufgeteilt, von denen jeweils
einer mit dem Notizbuch im Einstellungsfenster bearbeitet werden kann.
Im einzelnen gibt es folgende Bereiche&colon.
:ul.
:li.:link reftype=hd res=15100.Zeitformat:elink.
:li.:link reftype=hd res=15200.Animation:elink.
:li.:link reftype=hd res=15300.Wiedergabe:elink.
:li.:link reftype=hd res=15400.Speicherung:elink.
:li.:link reftype=hd res=15500.Ausgabe:elink.
:li.:link reftype=hd res=15600.GerÑt:elink.
:eul.

.********************************************************************
:h2 res=15100 name=PANEL_SE_TIMEFORMAT.Time format
:i2 REFID=INDEX_SETTINGS.time format
:i2 REFID=INDEX_TIME.format
:lines align=center.:hp7.Time format settings:ehp7.:elines.
:p.Die settings im Bereich Zeitformat Ñndern das Aussehen
von Zeit- und ZeitlÑngenangaben in den Fenstern des CD Spielers.
.br
Im einzelnen gibt es folgende settings&colon.
:ul.
:li.:link reftype=hd res=15110.Stunden/Minuten/Sekunden:elink.
:li.:link reftype=hd res=15120.Minuten/Sekunden/Frames:elink.
:li.:link reftype=hd res=15130.Separator:elink.
:li.:link reftype=hd res=15140.Aktualisierungsrate:elink.
:eul.

.********************************************************************
:h3 res=15110 name=PANEL_SE_HHMMSS.Hours/minutes/seconds
:i2 REFID=INDEX_TIME.hours/minutes/seconds
:lines align=center.:hp7.Hours/minutes/seconds:ehp7.:elines.
:p.Wenn diese settings angewÑhlt ist, werden alle Zeitangaben im folgenden
Format dargestellt&colon.
:table cols='10 12'.
:row.
:c. :hp5.12:ehp5.&colon.34&colon.56
:c. Stunden
:row.
:c. 12:hp5.&colon.:ehp5.34&colon.56
:c. :link reftype=hd res=15130.Separator:elink.
:row.
:c. 12&colon.:hp5.34:ehp5.&colon.56
:c. Minuten
:row.
:c. 12&colon.34:hp5.&colon.:ehp5.56
:c. :link reftype=hd res=15130.Separator:elink.
:row.
:c. 12&colon.34&colon.:hp5.56:ehp5.
:c. Sekunden
:etable.

.********************************************************************
:h3 res=15120 name=PANEL_SE_MMSSFF.Minutes/seconds/frames
:i2 REFID=INDEX_TIME.minutes/seconds/frames
:lines align=center.:hp7.Minutes/seconds/frames:ehp7.:elines.
:p.Wenn diese settings angewÑhlt ist, werden alle Zeitangaben im folgenden
Format dargestellt&colon.
:table cols='10 12'.
:row.
:c. :hp5.12:ehp5.&colon.34&colon.56
:c. Minuten
:row.
:c. 12:hp5.&colon.:ehp5.34&colon.56
:c. :link reftype=hd res=15130.Separator:elink.
:row.
:c. 12&colon.:hp5.34:ehp5.&colon.56
:c. Sekunden
:row.
:c. 12&colon.34:hp5.&colon.:ehp5.56
:c. :link reftype=hd res=15130.Separator:elink.
:row.
:c. 12&colon.34&colon.:hp5.56:ehp5.
:c. :link reftype=fn refid=frames.Frames:elink.
:etable.

.********************************************************************
:h3 res=15130 name=PANEL_SE_TIMESEP.Separator
:i2 REFID=INDEX_TIME.separator
:i1 ID=INDEX_SEP.Separator
:lines align=center.:hp7.Separator:ehp7.:elines.
:p.Der eingebene Separator ist das Trennzeichen zwischen den einzelnen
Werten einer Zeitangabe. Er mu· genau ein Zeichen lang sein.
.br
Siehe auch
":link reftype=hd res=15110.Einstellung Stunden/Minuten/Sekunden:elink." und
":link reftype=hd res=15120.Einstellung Minuten/Sekunden/Frames:elink.".

.********************************************************************
:h3 res=15140 name=PANEL_SE_TIMEFREQ.Actualisation rate
:i2 REFID=INDEX_TIME.actualisation rate
:i2 REFID=INDEX_FREQ.of the time display
:lines align=center.:hp7.Actualisation rate:ehp7.:elines.
:p.Die eingegebene Aktualisierungsrate bestimmt, wie hÑufig die
:link reftype=hd res=11110.Zeitanzeigen:elink. und die
:link reftype=hd res=11140.Positionsanzeige im main window:elink.
wÑhrend der Wiedergabe aktualisiert werden.
.br
Bei einem sehr hohen Wert fÅr die Aktualisierungsrate
kann es passieren, da· die
:link reftype=hd res=11150.Titelanzeige im main window:elink.
zeitweilig nicht mit dem tatsÑchlich gespielten Titel Åbereinstimmt.
Dies hat jedoch keinen Einflu· auf die
:link reftype=hd res=11200.Steuerung:elink.,
da vor der AusfÅhrung eines Befehls
alle Displays im main window automatisch aktualisiert werden.
.br
Bei einem sehr niedrigen Wert fÅr die Aktualisierungsrate
kann es passieren, da· der CD Spieler sehr viel Rechnerzeit
verbraucht und andere Programme auf dem Rechner langsamer laufen.
Dieses Problem wird behoben, indem das main window des CD Spielers
minimiert wird.
.br
Der Wert fÅr die Aktualisierungsrate wird in Millisekunden
angegeben und mu· zwischen 100 und 60000 liegen.

.********************************************************************
:h2 res=15200 name=PANEL_SE_ANIMATION.Animation
:i2 REFID=INDEX_SETTINGS.animation
:lines align=center.:hp7.Animation settings:ehp7.:elines.
:p.Die settings der Animation Ñndern das Aussehen des
:link reftype=hd res=11262.Wiedergabeknopfs:elink.
wÑhrend der Wiedergabe, siehe
":link reftype=hd res=11160.Wiedergabeanzeige im main window:elink.",
und die Animation von Auswahllisten.
.br
Im einzelnen gibt es folgende settings&colon.
:ul.
:li.:link reftype=hd res=15210.Wiedergabeanimation:elink.
:li.:link reftype=hd res=15230.Listenanimation:elink.
:li.:link reftype=hd res=15220.Animationsrate:elink.
:eul.

.********************************************************************
:h3 res=15210 name=PANEL_SE_ANIMATION_ONOFF.Playback animation
:i2 REFID=INDEX_ANIMATION.of playback
:lines align=center.:hp7.Playback animation:ehp7.:elines.
:p.Wenn die Wiedergabeanimation anstellt ist, lÑuft der Pfeil auf dem
:link reftype=hd res=11262.Wiedergabeknopf:elink. wÑhrend
der Wiedergabe von links nach rechts. Die Geschwindigkeit des
Pfeils kann mit der
:link reftype=hd res=15220.Einstellung Animationsrate:elink.
beeinflusst werden.

.********************************************************************
:h3 res=15230 name=PANEL_SE_LISTBOXANIMATION.List animation
:i2 REFID=INDEX_ANIMATION.of lists
:lines align=center.:hp7.List animation:ehp7.:elines.
:p.Wenn die Listenanimation eingestellt ist, wird beim EinfÅgen
oder Lîschen mehrerer EintrÑge in einer Auswahlliste (z.B. im
:link reftype=hd res=13000.program editor:elink.) jede énderung
einzeln dargestellt. Andernfalls wird die Auswahlliste erst nach
der vollstÑndigen énderung neu dargestellt.
:caution.
Bei eingestellter Listenanimation kînnen grî·ere énderungen an
Auswahllisten (z.B. das Lîschen des gesamten Programms im
:link reftype=hd res=13000.program editor:elink.) eine lÑngere
Zeit in Anspruch nehmen, wÑhrend der der Rechner nicht auf Eingaben
reagiert.
:ecaution.

.********************************************************************
:h3 res=15220 name=PANEL_SE_ANIMATION_RATE.Animation speed
:i2 REFID=INDEX_ANIMATION.speed
:lines align=center.:hp7.Animation speed:ehp7.:elines.
:p.Die Animationsrate bestimmt, wie schnell bei eingestellter
:link reftype=hd res=15210.Animation:elink. sich der Pfeil auf dem
:link reftype=hd res=11262.Wiedergabeknopf:elink. wÑhrend
der Wiedergabe bewegt.
.br
Der Wert fÅr die Animationsrate wird in Millisekunden
angegeben und mu· zwischen 25 und 10000 liegen.

.********************************************************************
:h2 res=15300 name=PANEL_SE_PLAY.Playback
:i2 REFID=INDEX_SETTINGS.playback
:i2 REFID=INDEX_CDCONTROL.settings
:lines align=center.:hp7.Playback settings:ehp7.:elines.
:p.Diese settings Ñndern das Verhalten des CD Spielers beim
Erreichen des Programmendes, beim Einlegen einer CD und bei dem Befehl
:link reftype=hd res=11260.Titel zurÅck:elink..
.br
Im einzelnen gibt es folgende settings&colon.
:ul.
:li.:link reftype=hd res=15310.Automatische Wiederholung:elink.
:li.:link reftype=hd res=15320.Automatischer Start:elink.
:li.:link reftype=hd res=15330.RÅcksprunglimit:elink.
:eul.

.********************************************************************
:h3 res=15310 name=PANEL_SE_AUTOREPEAT.Automatic repitition
:i2 REFID=INDEX_AUTOREPEAT.setup (in the settings)
:lines align=center.:hp7.Automatic repitition:ehp7.:elines.
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
:h3 res=15320 name=PANEL_SE_AUTOSTART.Automatic start
:isyn ROOT=autostart.Autostart
:i1 ROOTS='autostart' ID=INDEX_AUTOSTART.Automatic start
:i2 REFID=INDEX_CDCONTROL.automatic start
:lines align=center.:hp7.Automatic start:ehp7.:elines.
:p.Wenn diese Einstellung aktiviert ist, beginnt der CD Spieler
beim Einlegen einer CD automatisch mit der Wiedergabe am
Anfang des fÅr die CD gespeicherten Programms oder des Standardprogramms,
falls kein gespeichertes Programm gefunden wurde, siehe auch
":link reftype=hd res=11262.Wiedergabe starten:elink." und
":link reftype=hd res=13000.program editor:elink.".

.********************************************************************
:h3 res=15330 name=PANEL_SE_BACKWARDTHRESHOLD.Backward threshold
:i1 ID=INDEX_BACKWARDLIMIT.Backward threshold
:lines align=center.:hp7.Backward threshold:ehp7.:elines.
:p.Das RÅcksprunglimit beeinflusst das Verhalten des Befehls
:link reftype=hd res=11260.Titel zurÅck:elink..
Wenn die Position im momentanen Titel Åber dem hier eingestellten
Wert liegt, wird der CD Spieler an den Anfang des momentanen Titels gesetzt,
anderenfalls an den Anfang des vorherigen Titels im Programm.
.br
Der Wert fÅr das RÅcksprunglimit wird in Sekunden angegeben. Durch die Angabe
des Werts 0 kann erreicht werden, da· der CD Spieler nur dann auf den
Anfang des vorherigen Titels springt, wenn er sich direkt am Beginn
eines Titels befindet. Durch die Angabe eines sehr hohen Wertes wird erreicht,
da· der CD Spieler immer an den Anfang des vorherigen Titels springt.

.********************************************************************
:h2 res=15400 name=PANEL_SE_SAVE.Save
:i2 REFID=INDEX_SETTINGS.save
:lines align=center.:hp7.Save settings:ehp7.:elines.
:p.Die settings fÅr die Speicherung stellen die automatische
Speicherung fÅr diverse Werte des CD Spielers ein oder aus.
.br
Im einzelnen gibt es folgende settings&colon.
:ul.
:li.:link reftype=hd res=15410.Fensterposition:elink.
:li.:link reftype=hd res=15420.LautstÑrke:elink.
:li.:link reftype=hd res=15430.CD Position:elink.
:li.:link reftype=hd res=15430.Marker:elink.
:eul.

.********************************************************************
:h3 res=15410 name=PANEL_SE_SAVE_WINDOWS.Window position
:i2 REFID=INDEX_WINDOWS.automatic position save
:lines align=center.:hp7.Window position:ehp7.:elines.
:p.Wenn die Speicherung der Fensterpositionen aktiviert ist, werden
Position und Grî·e des
:link reftype=hd res=11000.main windows:elink., des
:link reftype=hd res=12000.title editors:elink., des
:link reftype=hd res=13000.program editors:elink., des
:link reftype=hd res=14000.Infofensters:elink. und der
:link reftype=hd res=15000.settings:elink. nach
jeder énderung gesichert. Einfaches Einstellen dieser Option reicht
nicht aus, um die Fensterpositionen und - grî·en zu sichern. Erst wenn
die Position oder Grî·e eines Fensters nach der Aktivierung dieser Option
verÑndert wird, werden sie gespeichert.
.br
UnabhÑngig von dieser Einstellung wird beim Start eines Fensters
immer die zuletzt gesicherte Position und Grî·e eingestellt. Das
hei·t Fensterposition und -grî·e werden immer auf den Wert gesetzt,
den sie hatten als die Speicherung der Fensterposition zuletzt
deaktiviert wurde.
:note.
Einige Fenster kînnen in der Grî·e nicht verÑndert werden. In
diesem Fall wird nur die Position des Fensters gespeichert.

.********************************************************************
:h3 res=15420 name=PANEL_SE_SAVE_VOLUME.Volume
:i2 REFID=INDEX_VOLUME.automatic save
:lines align=center.:hp7.Volume:ehp7.:elines.
:p.Wenn die Speicherung der LautstÑrke aktiviert ist, wird die
LautstÑrke nach jeder énderung gesichert. Siehe auch
":link reftype=hd res=11220.LautstÑrke links einstellen:elink." und
":link reftype=hd res=11221.LautstÑrke rechts einstellen:elink.".
.br
UnabhÑngig von dieser Einstellung wird beim Start des CD Spielers
immer die zuletzt gesicherte LautstÑrke eingestellt. Das hei·t
die LautstÑrke wird immer auf den Wert gestellt, den sie hatte
als die Speicherung der LautstÑrke zuletzt deaktiviert wurde.
:note.
Wenn Ihr CD-ROM Laufwerk das Einstellen der LautstÑrke nicht
unterstÅtzt ist diese Einstellung ohne Bedeutung.

.********************************************************************
:h3 res=15430 name=PANEL_SE_SAVE_PLAYLIST.CD position
:i2 REFID=INDEX_POSITION.automatic save
:lines align=center.:hp7.CD position:ehp7.:elines.
:p.Wenn die Speicherung der CD Position aktiviert ist, wird die
Position auf der CD beim Auswerfen der CD oder beim Verlassen des
CD Spielers gesichert.
UnabhÑngig von dieser Einstellung wird beim Start des CD Spielers
immer die zuletzt gesicherte Position eingestellt. Das hei·t
die Position wird immer auf die Stelle gesetzt, die sie hatte
als die Speicherung der CD Position zuletzt deaktiviert wurde.
:note.
Wenn Sie das Programm der CD im
:link reftype=hd res=13000.program editor:elink. Ñndern ohne da·
die CD eingelegt ist, wird die gespeicherte Position gelîscht und
die CD beim nÑchsten Einlegen wieder auf die Startposition gesetzt.

.********************************************************************
:h3 res=15440 name=PANEL_SE_SAVE_MARKERS.Markers
:i2 REFID=INDEX_MARKERS.automatic saving
:lines align=center.:hp7.Markers:ehp7.:elines.
:p.Diese Einstellung ist zur Zeit noch ohne Funktion.

.********************************************************************
:h2 res=15500 name=PANEL_SE_OUTPUT.Output
:i2 REFID=INDEX_SETTINGS.output
:lines align=center.:hp7.Output settings:ehp7.:elines.
:p.Die settings fÅr die Ausgabe legen fest, Åber welchen Anschlu·
die Tonausgabe des CD Spielers erfolgt.
.br
Im einzelnen gibt es folgende settings&colon.
:ul.
:li.:link reftype=hd res=15510.Kopfhîrer:elink.
:li.:link reftype=hd res=15520.Soundkarte:elink.
:li.:link reftype=hd res=15530.Externer VerstÑrker:elink.
:eul.
:note.
Mindestens ein Anschlu· muss eingestellt sein.

.********************************************************************
:h3 res=15510 name=PANEL_SE_OUTPUT_HEADPHONES.Headphones
:i1 ID=INDEX_HEADPHONES.Headphones
:i2 REFID=INDEX_CDCONTROL.at the headphones
:lines align=center.:hp7.Headphones:ehp7.:elines.
:p.Wenn diese Einstellung aktiviert ist, erfolgt die Tonausgabe
Åber den angeschlossenen Kopfhîrer.
:note.
Es kann sein, das Ihr CD-ROM Laufwerk diese Einstellung
nicht unterstÅtzt. In diesem Fall ist der Schalter deaktiviert.
.br
Die GÅltigkeit dieser Einstellung kann nur bei eingelegter CD
ÅberprÅft werden. Wenn Sie die Option ohne eingelegte CD Ñndern
und spÑter eine Fehlermeldung erhalten, deaktivieren sie die
Einstellung.

.********************************************************************
:h3 res=15520 name=PANEL_SE_OUTPUT_SOUNDCARD.Soundcard
:i1 ID=INDEX_SOUNDCARD.Soundcard
:i2 REFID=INDEX_CDCONTROL.at the soundcard
:lines align=center.:hp7.Soundcard:ehp7.:elines.
:p.Wenn diese Einstellung aktiviert ist, erfolgt die Tonausgabe
Åber die angeschlossene Soundkarte.
:note.
Es kann sein, das Ihr CD-ROM Laufwerk diese Einstellung
nicht unterstÅtzt. In diesem Fall ist der Schalter deaktiviert.
.br
Die GÅltigkeit dieser Einstellung kann nur bei eingelegter CD
ÅberprÅft werden. Wenn Sie die Option ohne eingelegte CD Ñndern
und spÑter eine Fehlermeldung erhalten, deaktivieren sie die
Einstellung.
.br
Bei einzelnen Soundkarten kann es zu Problemen bei der Ausgabe kommen
wenn OS/2 versucht, den Ton Åber die Soundkarte wiederzugeben. Wenn Sie
keinen oder nur stark verzerrten Ton hîren deaktivieren Sie diese
Einstellung.

.********************************************************************
:h3 res=15530 name=PANEL_SE_OUTPUT_AMPLIFIER.External amplifier
:isyn ROOT=amp.Amplifier
:i1 ROOTS='amp' ID=INDEX_EXTAMP.Extarnal amplifier
:i2 REFID=INDEX_CDCONTROL.at the external amplifier
:lines align=center.:hp7.External amplifier:ehp7.:elines.
:p.Wenn diese Einstellung aktiviert ist, erfolgt die Tonausgabe
Åber den angeschlossenen externen VerstÑrker.
:note.
Es kann sein, das Ihr CD-ROM Laufwerk diese Einstellung
nicht unterstÅtzt. In diesem Fall ist der Schalter deaktiviert.
.br
Die GÅltigkeit dieser Einstellung kann nur bei eingelegter CD
ÅberprÅft werden. Wenn Sie die Option ohne eingelegte CD Ñndern
und spÑter eine Fehlermeldung erhalten, deaktivieren sie die
Einstellung.


.********************************************************************
:h2 res=15600 name=PANEL_SE_HARDWARE.Device
:i2 REFID=INDEX_SETTINGS.device
:lines align=center.:hp7.Device settings:ehp7.:elines.
:p.Mit diesen settings wird das Verhalten Ihres CD-ROM Laufwerks
beeinflu·t.
.br
Im einzelnen gibt es folgende settings&colon.
:ul.
:li.:link reftype=hd res=15610.Laufwerk sperren:elink.
:li.:link reftype=hd res=15620.GerÑtename:elink.
:eul.

.********************************************************************
:h3 res=15610 name=PANEL_SE_HARDWARE_LOCK.Lock drive
:i2 REFID=INDEX_DEVICE.locking
:lines align=center.:hp7.Lock drive:ehp7.:elines.
:p.Wenn diese Einstellung aktiviert ist, wird der Auswurf des
CD-ROM Laufwerks bei eingelegter CD verriegelt. Die CD kann dann
nur noch Åber den Befehl
:link reftype=hd res=11265.CD auswerfen:elink.
aus dem Laufwerk genommen werden. Andere Programme kînnen aber die Verriegelung
wÑhrend des Betriebs des CD Spielers aufheben.
:note.
Es kann sein, das Ihr CD-ROM Laufwerk diese Einstellung
nicht unterstÅtzt. In diesem Fall ist der Schalter deaktiviert.

.********************************************************************
:h3 res=15620 name=PANEL_SE_HARDWARE_NAME.Name
:i2 REFID=INDEX_DEVICE.name
:lines align=center.:hp7.Device name:ehp7.:elines.
:p.Wenn Sie mehrere CD-ROM Laufwerke an Ihren Rechner angeschlossen haben,
kînnen Sie in dieser Auswahlliste den Namen des CD-ROM Laufwerks auswÑhlen,
das Sie verwenden wollen.

.********************************************************************
:h2 res=15700 name=PANEL_SE_KEYBOARD.Keyboard and mouse shortcuts
:i2 REFID=INDEX_SETTINGS.Keyboard and mouse shortcuts
:i2 REFID=INDEX_KEYBOARD.shortcuts in the settings
:i2 REFID=INDEX_MOUSE.shortcuts in the settings
:lines align=center.:hp7.Keyboard shortcuts in the settings:ehp7.:elines.
:p.In den settings sind keine besonderen Tastaturbefehle definiert.

:p.:lines align=center.:hp7.Mouse shortcuts in the settings:ehp7.:elines.
:p.In den settings sind keine besonderen Mausbefehle definiert.

.********************************************************************
:h2 res=15800 name=PANEL_SE_MENUS.Menu commands
:i2 REFID=INDEX_SETTINGS.menu commands
:i2 REFID=INDEX_MENU.in the settings
:lines align=center.:hp7.Menu commands in the settings:ehp7.:elines.
:p.In den settings sind keine besonderen MenÅbefehle definiert.

.********************************************************************

.im errors.ipf
.********************************************************************
.********************************************************************
:h1 res=16000 name=PANEL_ERRORS.&ERROR_MSGS.
:i1 ID=INDEX_ERRORS.&ERROR_MSGS.

:h4 res=16001.
:p.:hp8.&ERROR. &LS_ERR_DEVICE_ADVISE.:ehp8.
.br
&FATAL_ERROR.

:h4 res=16002.
:p.:hp8.&ERROR. &LS_ERR_DEVICE_CONTENTS.:ehp8.
.br
Entweder die CD ist fehlerhaft oder es handelt sich nicht um eine Audio CD.
Werfen Sie die CD aus.

:h4 res=16003.
:p.:hp8.&ERROR. &LS_ERR_DEVICE_EJECT.:ehp8.
.br
Versuchen Sie, die CD mit der Auswurftaste am CD-ROM Laufwerk auszuwerden.

:h4 res=16004.
:p.:hp8.&ERROR. &LS_ERR_DEVICE_MUTEVOLUME.:ehp8.
.br
Eventuell kann der Ton Åber den globalen LautstÑrkeregler
der Multimediaerweiterung von OS/2 oder Åber externe LautstÑrkeregler
an der Soundkarte und am CD-ROM Laufwerk eingestellt werden.

:h4 res=16005.
:p.:hp8.&ERROR. &LS_ERR_DEVICE_INFO.:ehp8.
.br
&FATAL_ERROR.

:h4 res=16006.
:p.:hp8.&ERROR. &LS_ERR_DEVICE_OPEN.:ehp8.
.br
&FATAL_ERROR.

:h4 res=16007.
:p.:hp8.&ERROR. &LS_ERR_DEVICE_PAUSE.:ehp8.
.br
Die CD kînnte defekt sein. Vermeiden Sie die Stelle auf der CD, an der der
PAUSE-Befehl nicht durchgefÅhrt werden konnte.

:h4 res=16008.
:p.:hp8.&ERROR. &LS_ERR_DEVICE_PLAY.:ehp8.
.br
Die CD kînnte defekt sein. Vermeiden Sie die Stelle auf der CD, an der der
PLAY-Befehl nicht durchgefÅhrt werden konnte.

:h4 res=16009.
:p.:hp8.&ERROR. &LS_ERR_DEVICE_POSITION.:ehp8.
.br
Die CD kînnte defekt sein. Vermeiden Sie die momentane Stelle auf der CD.

:h4 res=16010.
:p.:hp8.&ERROR. &LS_ERR_DEVICE_CONNECTOR.:ehp8.
.br
Der von Ihnen gewÑhlte Ausgabeanschlu· ist in der momentanen
Konfiguration nicht verfÅgbar.

:h4 res=16011.
:p.:hp8.&ERROR. &LS_ERR_DEVICE_RESUME.:ehp8.
.br
Die CD kînnte defekt sein. Vermeiden Sie die Stelle auf der CD, an der der
RESUME-Befehl nicht durchgefÅhrt werden konnte.

:h4 res=16012.
:p.:hp8.&ERROR. &LS_ERR_DEVICE_SETVOLUME.:ehp8.
.br
Eventuell kann die LautstÑrke Åber den globalen LautstÑrkeregler
der Multimediaerweiterung von OS/2 oder Åber externe LautstÑrkeregler
an der Soundkarte und am CD-ROM Laufwerk eingestellt werden.

:h4 res=16013.
:p.:hp8.&ERROR. &LS_ERR_DEVICE_STOP.:ehp8.
.br
&FATAL_ERROR.

:h4 res=16014.
:p.:hp8.&ERROR. &LS_ERR_HELP_OPEN.:ehp8.
.br
Die Hilfedatei 'CDPLAYER.HLP' mu· sich im selben Verzeichnis wie das CD Spieler
Programm 'CDPLAYER.EXE' befinden.

:h4 res=16015.
:p.:hp8.&ERROR. &LS_ERR_PROFILE_OPEN.:ehp8.
.br
Beim Versuch, die INI-Datei 'CDPLAYER.INI' zu îffnen oder neu zu erstellen, ist
ein Dateifehler aufgetreten.
&FATAL_ERROR.

:h4 res=16016.
:p.:hp8.&ERROR. &LS_ERR_PROFILE_WRITE.:ehp8.
.br
Beim Versuch, die INI-Datei 'CDPLAYER.INI' zu beschreiben, ist
ein Dateifehler aufgetreten.

:h4 res=16017.
:p.:hp8.&ERROR. &LS_ERR_WATCHDOG.:ehp8.
.br
&FATAL_ERROR.

:h4 res=16018.
:p.:hp8.&ERROR. &LS_ERR_NOAUDIO.:ehp8.
.br
&FATAL_ERROR.

.********************************************************************
.im index.ipf
.********************************************************************
.********************************************************************
:h1 hide res=17000 name=PANEL_OTHERS.Others

.********************************************************************
:h1 hide res=17100 name=PANEL_ABOUT.About
:p.DrÅcken Sie :hp2.OK:ehp2., um zum CD Spieler zurÅckzukehren.

.********************************************************************
:h1 hide res=17200 name=PANEL_AREYOUSURE.Are you sure?
:p.Wenn Sie sicher sind, da· Sie die ausgewÑhlte CD aus der
:link reftype=fn refid=library.CD Bibliothek:elink.
lîschen wollen, drÅcken Sie den :hp2.OK:ehp2. Knopf,
ansonsten den :hp2.Abbrechen:ehp2. Knopf.
:caution.
Mit dem Lîschen der CD gehen auch alle gespeicherten Titel, Informationen
und das gespeicherte Programm verloren!
:ecaution.

.********************************************************************
:h1 hide res=17300 name=PANEL_YESORNO.Yes or no?
:p.Das momentane Programm im
:link reftype=hd res=13000.program editor:elink.
ist noch nicht gespeichert.
:sl.
:li.Wenn Sie das momentane Programm speichern wollen, bevor Sie das Programm
der eingelegten CD bearbeiten, drÅcken Sie den :hp2.Ja:ehp2. Knopf.
:li.Wenn Sie das momentane Programm nicht speichern wollen,
drÅcken Sie den :hp2.Nein:ehp2. Knopf.
:li.Wenn Sie das momentane Programm bebehalten wollen und das Programm der
eingelegten CD nicht bearbeiten wollen,
drÅcken Sie den :hp2.Abbrechen:ehp2. Knopf.
:esl.

.********************************************************************
.*                                                                  *
.* Hier sind alle 1-Level IndexeintrÑge abgelegt, die weitere Unter *
.* eintrÑge enthalten.                                              *
.*                                                                  *
.********************************************************************
:h1 hide res=17400 name=PANEL_INDEXSELECT.Index selection
:i1 ID=INDEX_FREQ.Actualisation
:i1 ID=INDEX_ANIMATION.Animation
:i1 ID=INDEX_DISPLAY.Displays
.* :i1 ID=INDEX_OUTPUT.Output
:isyn ROOT=autorepeat.Autorepeat
:i1 ROOTS='autorepeat' ID=INDEX_AUTOREPEAT.Automatic repitition
:i1 ID=INDEX_LIBRARY.Library
:i1 ID=INDEX_CD.CD
:i1 ID=INDEX_COPYRIGHT.Copyright
:isyn ROOT=setting.Setting
:i1 ROOTS='setting' ID=INDEX_SETTINGS.Settings
:i1 ID=INDEX_WINDOWS.Windows
:i1 ID=INDEX_DEVICE.Device
:i1 ID=INDEX_TOTALLENGTH.Total length
:i1 ID=INDEX_MAINWINDOW.Main window
:i1 ID=INDEX_ID.ID
:isyn ROOT=info.Info
:i1 ROOTS='info' ID=INDEX_INFOWINDOW.Info window
:isyn ROOT=channel.Channel
:i1 ROOTS='channel' ID=INDEX_CHANNELS.Channels
:i1 ID=INDEX_LENGTH.Length
:i1 ID=INDEX_VOLUME.Volume
:i1 ID=INDEX_MARKERS.Markers
:i1 ID=INDEX_MOUSE.Mouse
:isyn ROOT=menus.Menus
:isyn ROOT=menu.Menu
:i1 ROOTS='menus menu' ID=INDEX_MENU.Menu commands
:isyn ROOT=name.Name
:i1 ROOTS='name' ID=INDEX_NAMES.Names
:i1 ID=INDEX_NUMBER.Number
:i1 ID=INDEX_POSITION.Position
:i1 ID=INDEX_POPUPMENU.Popup menu
:i1 ID=INDEX_PROGRAM.Program
:i1 ID=INDEX_PROGRAMEDITOR.Program editor
:isyn ROOT=tracks.Tracks
:i1 ROOTS='tracks' ID=INDEX_TRACK.Track
:isyn ROOT=standard.Standard
:i1 ROOTS='standard' ID=INDEX_STANDARD.Standard program
:i1 ID=INDEX_STARTPOSITION.Start position
:i1 ID=INDEX_CONTROL.Controls
:i1 ID=INDEX_SYSMENU.System menu
:isyn ROOT=keyboard.Keyboard
:i1 ROOTS='keyboard' ID=INDEX_KEYBOARD.Keyboard commands
:i1 ID=INDEX_TITLE.Title
:i1 ID=INDEX_TITLEEDITOR.Title editor
:i1 ID=INDEX_SOUND.Sound
:i1 ID=INDEX_CDCONTROL.Playback
:i1 ID=INDEX_TIME.Time
:isyn ROOT=additional.Additional
:i1 ROOTS='additional' ID=INDEX_ADDINFO.Additional information

:artwork align=center name='ICONINFO.BMP'.
:p.Wird unter dem ausgewÑhlten Begriff eine Liste mit Begriffen angezeigt,
stehen nur fÅr diese Begriffe Hilfetexte zur VerfÅgung. Wenn in dem
ausgewÑhlten Begriff auf einen anderen Begriff verwiesen wird, kann nur
fÅr diesen Begriff ein Hilfetext aufgerufen werden.

.********************************************************************

.im copyrght.ipf
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



    ⁄ƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒø
    ≥                                             ≥
    ≥                                             ≥
    ≥                                             ≥
    ≥         Michael Bock                        ≥
    ≥         Winkler Str. 28                     ≥
    ≥                                             ≥
    ≥         14193 Berlin                        ≥
    ≥                                             ≥
    ≥         Germany                             ≥
    ≥                                             ≥
    ≥                                             ≥
    ¿ƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒƒŸ

    Send to&colon.     Name/Company&colon.  _______________________________________
    ÕÕÕÕÕÕÕÕ
                 Address&colon.       _______________________________________

                                _______________________________________

                 Country&colon.       _______________________________________

                 Telephone&colon.     ______________  Fax&colon. __________________

                 Email&colon.         _______________________________________

    # Copies                                                        Amount

    ____ CD Player for OS/2 registration
         Germany&colon. DM 30,-  Europe&colon. DM 35,-  World&colon. DM 50,-        = DM _____,-

                                                                ÕÕÕÕÕÕÕÕÕÕÕ

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


    Suggestions for future improvements&colon.

    _________________________________________________________________________

    _________________________________________________________________________

    _________________________________________________________________________

:efig.
:font facename=default size=0x0.
.********************************************************************

.im footnote.ipf
.********************************************************************
.********************************************************************
:h1 hide res=20000.Footnotes

:fn id=frames.
:p.Frames are the smallest measurement on an audio disc.
A frame is the 75th part of a second.
:efn.

:fn id=upc.
:p.:hp4.UPC:ehp4. stands for "universal product code". Not every
audio disc has an :hp4.UPC:ehp4., and not every CD-ROM drive can read the
:hp4.UPC:ehp4..
:efn.

:fn id=preemphasis.
:p.:hp4.Preemphasis:ehp4. stands for the special recording of a track.
:efn.

:fn id=librarymode.
:p.While the
:link reftype=hd res=12000.title editor:elink. is in
:hp4.library mode:ehp4., you can view the titles and
the additional information of all discs in your
:link reftype=fn refid=library.CD library:elink., and you can
select one disc for revision.
:efn.

:fn id=library.
:p.The :hp4.CD library:ehp4. contains the infos and titles of all tracks
which were inserted during use of the CD Player. It is stored along with
the CD Player on your hard disk.
:efn.

:fn id=changemode.
:p.While the
:link reftype=hd res=12000.title editor:elink.
is in :hp4.change mode:ehp4., you can change the titles
and additional information of the selected disc.
:efn.

.********************************************************************
:euserdoc.
