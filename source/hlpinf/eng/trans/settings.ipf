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
:p.Diese Einstellungen Ñndern das Verhalten des CD Spielers beim
Erreichen des Programmendes, beim Einlegen einer CD und bei dem Befehl
:link reftype=hd res=11260.Titel zurÅck:elink..
.br
Im einzelnen gibt es folgende Einstellungen&colon.
:ul.
:li.:link reftype=hd res=15310.Automatische Wiederholung:elink.
:li.:link reftype=hd res=15320.Automatischer Start:elink.
:li.:link reftype=hd res=15330.RÅcksprunglimit:elink.
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
Anfang des fÅr die CD gespeicherten Programms oder des Standardprogramms,
falls kein gespeichertes Programm gefunden wurde, siehe auch
":link reftype=hd res=11262.Wiedergabe starten:elink." und
":link reftype=hd res=13000.Programmeditor:elink.".

.********************************************************************
:h3 res=15330 name=PANEL_SE_BACKWARDTHRESHOLD.RÅcksprunglimit
:i1 ID=INDEX_BACKWARDLIMIT.RÅcksprunglimit
:p.:lines align=center.:hp7.RÅcksprunglimit:ehp7.:elines.
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
:h2 res=15400 name=PANEL_SE_SAVE.Speicherung
:i2 REFID=INDEX_SETTINGS.Speicherung
:p.:lines align=center.:hp7.Einstellungen Speicherung:ehp7.:elines.
:p.Die Einstellungen fÅr die Speicherung stellen die automatische
Speicherung fÅr diverse Werte des CD Spielers ein oder aus.
.br
Im einzelnen gibt es folgende Einstellungen&colon.
:ul.
:li.:link reftype=hd res=15410.Fensterposition:elink.
:li.:link reftype=hd res=15420.LautstÑrke:elink.
:li.:link reftype=hd res=15430.CD Position:elink.
:li.:link reftype=hd res=15430.Marker:elink.
:eul.:lm margin=1.

.********************************************************************
:h3 res=15410 name=PANEL_SE_SAVE_WINDOWS.Fensterposition
:i2 REFID=INDEX_WINDOWS.Automatische Positionsspeicherung
:p.:lines align=center.:hp7.Fensterposition:ehp7.:elines.
:p.Wenn die Speicherung der Fensterpositionen aktiviert ist, werden
Position und Grî·e des
:link reftype=hd res=11000.Hauptfensters:elink., des
:link reftype=hd res=12000.Titeleditors:elink., des
:link reftype=hd res=13000.Programmeditors:elink., des
:link reftype=hd res=14000.Infofensters:elink. und der
:link reftype=hd res=15000.Einstellungen:elink. nach
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
:h3 res=15420 name=PANEL_SE_SAVE_VOLUME.LautstÑrke
:i2 REFID=INDEX_VOLUME.Automatische Speicherung
:p.:lines align=center.:hp7.LautstÑrke:ehp7.:elines.
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
:h3 res=15430 name=PANEL_SE_SAVE_PLAYLIST.CD Position
:i2 REFID=INDEX_POSITION.Automatische Speicherung
:p.:lines align=center.:hp7.CD Position:ehp7.:elines.
:p.Wenn die Speicherung der CD Position aktiviert ist, wird die
Position auf der CD beim Auswerfen der CD oder beim Verlassen des
CD Spielers gesichert.
UnabhÑngig von dieser Einstellung wird beim Start des CD Spielers
immer die zuletzt gesicherte Position eingestellt. Das hei·t
die Position wird immer auf die Stelle gesetzt, die sie hatte
als die Speicherung der CD Position zuletzt deaktiviert wurde.
:note.
Wenn Sie das Programm der CD im
:link reftype=hd res=13000.Programmeditor:elink. Ñndern ohne da·
die CD eingelegt ist, wird die gespeicherte Position gelîscht und
die CD beim nÑchsten Einlegen wieder auf die Startposition gesetzt.

.********************************************************************
:h3 res=15440 name=PANEL_SE_SAVE_MARKERS.Marker
:i2 REFID=INDEX_MARKERS.Automatische Speicherung
:p.:lines align=center.:hp7.Marker:ehp7.:elines.
:p.Diese Einstellung ist zur Zeit noch ohne Funktion.

.********************************************************************
:h2 res=15500 name=PANEL_SE_OUTPUT.Output
:i2 REFID=INDEX_SETTINGS.Output
:p.:lines align=center.:hp7.Output settings:ehp7.:elines.
:p.The settings for the output determine, which connectors will be used
for the sound output of the CD-ROM device.
.br
In detail, there are the following settings&colon.
:ul.
:li.:link reftype=hd res=15510.Headphones:elink.
:li.:link reftype=hd res=15520.Soundcard:elink.
:li.:link reftype=hd res=15530.External amplifier:elink.
:eul.:lm margin=1.
:note.
At least one output connector must be activated.

.********************************************************************
:h3 res=15510 name=PANEL_SE_OUTPUT_HEADPHONES.Headphones
:i1 ID=INDEX_HEADPHONES.Headphones
:i2 REFID=INDEX_CDCONTROL.at the headphones
:p.:lines align=center.:hp7.Headphones:ehp7.:elines.
:p.If this setting is activated, output will occur at the connected
headphones.
:note.
If your CD-ROM device does not support this option, the button is deactived.
.br
The availability of this setting can be tested with an inserted CD only.
If you have activated this setting without an inserted CD and get an
error message later, deactivate it.

.********************************************************************
:h3 res=15520 name=PANEL_SE_OUTPUT_SOUNDCARD.Soundcard
:i1 ID=INDEX_SOUNDCARD.Soundcard
:i2 REFID=INDEX_CDCONTROL.at the soundcard
:p.:lines align=center.:hp7.Soundcard:ehp7.:elines.
:p.If this setting is activated, output will occur at the connected
soundcard.
:note.
If your CD-ROM device does not support this option, the button is deactived.
.br
The availability of this setting can be tested with an inserted CD only.
If you have activated this setting without an inserted CD and get an
error message later, deactivate it.
.br
Some soundcards have problems with output from CD. If you don't any hear any
sound, or sound is distorted, deactive this setting.

.********************************************************************
:h3 res=15530 name=PANEL_SE_OUTPUT_AMPLIFIER.External amplifier
:isyn ROOT=amp.amplifier
:i1 ROOTS='amp' ID=INDEX_EXTAMP.External amplifier
:i2 REFID=INDEX_CDCONTROL.at the external amplifier
:p.:lines align=center.:hp7.External amplifier:ehp7.:elines.
:p.If this setting is activated, output will occur at the
external amplifier.
:note.
If your CD-ROM device does not support this option, the button is deactived.
.br
The availability of this setting can be tested with an inserted CD only.
If you have activated this setting without an inserted CD and get an
error message later, deactivate it.


.********************************************************************
:h2 res=15600 name=PANEL_SE_HARDWARE.Device
:i2 REFID=INDEX_SETTINGS.device
:p.:lines align=center.:hp7.Device settings:ehp7.:elines.
:p.With this buttons you can control the behaviour of your CD-ROM device.
.br
In detail, there are the following settings&colon.
:ul.
:li.:link reftype=hd res=15610.Lock device:elink.
:li.:link reftype=hd res=15620.Device name:elink.
:eul.:lm margin=1.

.********************************************************************
:h3 res=15610 name=PANEL_SE_HARDWARE_LOCK.Lock device
:i2 REFID=INDEX_DEVICE.locking
:p.:lines align=center.:hp7.Lock device:ehp7.:elines.
:p.If this setting is activated, the eject button of your CD-ROM device
is locked. The only way to eject a CD in this case is the command
:link reftype=hd res=11265.CD ejecting:elink..
Other programs may suspend the lock during use of the CD Player.
:note.
If your CD-ROM device does not support this option, the button is deactived.

.********************************************************************
:h3 res=15620 name=PANEL_SE_HARDWARE_NAME.Device name
:i2 REFID=INDEX_DEVICE.Device name
:p.:lines align=center.:hp7.Device name:ehp7.:elines.
:p.If you have multiple CD-ROM devices installed in your computer, you
may select the desired CD-ROM to use by it's name in this selection box.

.********************************************************************
:h2 res=15700 name=PANEL_SE_KEYBOARD.Keyboard and mouse commands
:i2 REFID=INDEX_SETTINGS.Keyboard and mouse commands
:i2 REFID=INDEX_KEYBOARD.commands in the settings
:i2 REFID=INDEX_MOUSE.commands in the settings
:p.:lines align=center.:hp7.Keyboard commands in the settings:ehp7.:elines.
:p.There are no special keyboard commands defined in the settings.

:p.:lines align=center.:hp7.Mouse commands in the settings:ehp7.:elines.
:p.There are no special mouse commands defined in the settings.

.********************************************************************
:h2 res=15800 name=PANEL_SE_MENUS.Menu commands
:i2 REFID=INDEX_SETTINGS.Menu commands
:i2 REFID=INDEX_MENU.in the settings
:p.:lines align=center.:hp7.Menu commands in the settings:ehp7.:elines.
:p.There are no special menu commands defined in the settings.

.********************************************************************

