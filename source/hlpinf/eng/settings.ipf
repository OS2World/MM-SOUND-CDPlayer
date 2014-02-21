.********************************************************************
:h1 res=15000 name=PANEL_SETTINGS.Einstellungen
:i2 REFID=INDEX_WINDOWS.Einstellungen
:i2 REFID=INDEX_SETTINGS.�berblick
:lines align=center.:hp7.Einstellungen �berblick:ehp7.:elines.
:p.Mit den Einstellungen k�nnen Sie Aussehen und Verhalten des CD Spielers
�ndern. Jede �nderung in den Einstellungen wird sofort umgesetzt
und gespeichert. Daher ist es nicht n�tig (und m�glich), die Einstellungen
explizit zu sichern.
.br
Die Einstellungen sind in sechs Bereiche aufgeteilt, von denen jeweils
einer mit dem Notizbuch im Einstellungsfenster bearbeitet werden kann.
Im einzelnen gibt es folgende Bereiche&colon.
:ul.
:li.:link reftype=hd res=15100.Zeitformat:elink.
:li.:link reftype=hd res=15200.Animation:elink.
:li.:link reftype=hd res=15300.Wiedergabe:elink.
:li.:link reftype=hd res=15400.Speicherung:elink.
:li.:link reftype=hd res=15500.Ausgabe:elink.
:li.:link reftype=hd res=15600.Ger�t:elink.
:eul.

.********************************************************************
:h2 res=15100 name=PANEL_SE_TIMEFORMAT.Zeitformat
:i2 REFID=INDEX_SETTINGS.Zeitformat
:i2 REFID=INDEX_TIME.Format
:lines align=center.:hp7.Einstellungen Zeitformat:ehp7.:elines.
:p.Die Einstellungen im Bereich Zeitformat �ndern das Aussehen
von Zeit- und Zeitl�ngenangaben in den Fenstern des CD Spielers.
.br
Im einzelnen gibt es folgende Einstellungen&colon.
:ul.
:li.:link reftype=hd res=15110.Stunden/Minuten/Sekunden:elink.
:li.:link reftype=hd res=15120.Minuten/Sekunden/Frames:elink.
:li.:link reftype=hd res=15130.Separator:elink.
:li.:link reftype=hd res=15140.Aktualisierungsrate:elink.
:eul.

.********************************************************************
:h3 res=15110 name=PANEL_SE_HHMMSS.Stunden/Minuten/Sekunden
:i2 REFID=INDEX_TIME.Stunden/Minuten/Sekunden
:lines align=center.:hp7.Stunden/Minuten/Sekunden:ehp7.:elines.
:p.Wenn diese Einstellungen angew�hlt ist, werden alle Zeitangaben im folgenden
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
:h3 res=15120 name=PANEL_SE_MMSSFF.Minuten/Sekunden/Frames
:i2 REFID=INDEX_TIME.Minuten/Sekunden/Frames
:lines align=center.:hp7.Minuten/Sekunden/Frames:ehp7.:elines.
:p.Wenn diese Einstellungen angew�hlt ist, werden alle Zeitangaben im folgenden
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
:i2 REFID=INDEX_TIME.Separator
:i1 ID=INDEX_SEP.Separator
:lines align=center.:hp7.Separator:ehp7.:elines.
:p.Der eingebene Separator ist das Trennzeichen zwischen den einzelnen
Werten einer Zeitangabe. Er mu� genau ein Zeichen lang sein.
.br
Siehe auch
":link reftype=hd res=15110.Einstellung Stunden/Minuten/Sekunden:elink." und
":link reftype=hd res=15120.Einstellung Minuten/Sekunden/Frames:elink.".

.********************************************************************
:h3 res=15140 name=PANEL_SE_TIMEFREQ.Aktualisierungsrate
:i2 REFID=INDEX_TIME.Aktualisierungsrate
:i2 REFID=INDEX_FREQ.der Zeitangabe
:lines align=center.:hp7.Aktualisierungsrate:ehp7.:elines.
:p.Die eingegebene Aktualisierungsrate bestimmt, wie h�ufig die
:link reftype=hd res=11110.Zeitanzeigen:elink. und die
:link reftype=hd res=11140.Positionsanzeige im Hauptfenster:elink.
w�hrend der Wiedergabe aktualisiert werden.
.br
Bei einem sehr hohen Wert f�r die Aktualisierungsrate
kann es passieren, da� die
:link reftype=hd res=11150.Titelanzeige im Hauptfenster:elink.
zeitweilig nicht mit dem tats�chlich gespielten Titel �bereinstimmt.
Dies hat jedoch keinen Einflu� auf die
:link reftype=hd res=11200.Steuerung:elink.,
da vor der Ausf�hrung eines Befehls
alle Anzeigen im Hauptfenster automatisch aktualisiert werden.
.br
Bei einem sehr niedrigen Wert f�r die Aktualisierungsrate
kann es passieren, da� der CD Spieler sehr viel Rechnerzeit
verbraucht und andere Programme auf dem Rechner langsamer laufen.
Dieses Problem wird behoben, indem das Hauptfenster des CD Spielers
minimiert wird.
.br
Der Wert f�r die Aktualisierungsrate wird in Millisekunden
angegeben und mu� zwischen 100 und 60000 liegen.

.********************************************************************
:h2 res=15200 name=PANEL_SE_ANIMATION.Animation
:i2 REFID=INDEX_SETTINGS.Animation
:lines align=center.:hp7.Einstellungen Animation:ehp7.:elines.
:p.Die Einstellungen der Animation �ndern das Aussehen des
:link reftype=hd res=11262.Wiedergabeknopfs:elink.
w�hrend der Wiedergabe, siehe
":link reftype=hd res=11160.Wiedergabeanzeige im Hauptfenster:elink.",
und die Animation von Auswahllisten.
.br
Im einzelnen gibt es folgende Einstellungen&colon.
:ul.
:li.:link reftype=hd res=15210.Wiedergabeanimation:elink.
:li.:link reftype=hd res=15230.Listenanimation:elink.
:li.:link reftype=hd res=15220.Animationsrate:elink.
:eul.

.********************************************************************
:h3 res=15210 name=PANEL_SE_ANIMATION_ONOFF.Wiedergabeanimation
:i2 REFID=INDEX_ANIMATION.der Wiedergabe
:lines align=center.:hp7.Wiedergabeanimation:ehp7.:elines.
:p.Wenn die Wiedergabeanimation anstellt ist, l�uft der Pfeil auf dem
:link reftype=hd res=11262.Wiedergabeknopf:elink. w�hrend
der Wiedergabe von links nach rechts. Die Geschwindigkeit des
Pfeils kann mit der
:link reftype=hd res=15220.Einstellung Animationsrate:elink.
beeinflusst werden.

.********************************************************************
:h3 res=15230 name=PANEL_SE_LISTBOXANIMATION.Listenanimation
:i2 REFID=INDEX_ANIMATION.von Listen
:lines align=center.:hp7.Listenanimation:ehp7.:elines.
:p.Wenn die Listenanimation eingestellt ist, wird beim Einf�gen
oder L�schen mehrerer Eintr�ge in einer Auswahlliste (z.B. im
:link reftype=hd res=13000.Programmeditor:elink.) jede �nderung
einzeln dargestellt. Andernfalls wird die Auswahlliste erst nach
der vollst�ndigen �nderung neu dargestellt.
:caution.
Bei eingestellter Listenanimation k�nnen gr��ere �nderungen an
Auswahllisten (z.B. das L�schen des gesamten Programms im
:link reftype=hd res=13000.Programmeditor:elink.) eine l�ngere
Zeit in Anspruch nehmen, w�hrend der der Rechner nicht auf Eingaben
reagiert.
:ecaution.

.********************************************************************
:h3 res=15220 name=PANEL_SE_ANIMATION_RATE.Animationsrate
:i2 REFID=INDEX_ANIMATION.Rate
:lines align=center.:hp7.Animationsrate:ehp7.:elines.
:p.Die Animationsrate bestimmt, wie schnell bei eingestellter
:link reftype=hd res=15210.Animation:elink. sich der Pfeil auf dem
:link reftype=hd res=11262.Wiedergabeknopf:elink. w�hrend
der Wiedergabe bewegt.
.br
Der Wert f�r die Animationsrate wird in Millisekunden
angegeben und mu� zwischen 25 und 10000 liegen.

.********************************************************************
:h2 res=15300 name=PANEL_SE_PLAY.Wiedergabe
:i2 REFID=INDEX_SETTINGS.Wiedergabe
:i2 REFID=INDEX_CDCONTROL.Einstellungen
:lines align=center.:hp7.Einstellungen Wiedergabe:ehp7.:elines.
:p.Diese Einstellungen �ndern das Verhalten des CD Spielers beim
Erreichen des Programmendes, beim Einlegen einer CD und bei dem Befehl
:link reftype=hd res=11260.Titel zur�ck:elink..
.br
Im einzelnen gibt es folgende Einstellungen&colon.
:ul.
:li.:link reftype=hd res=15310.Automatische Wiederholung:elink.
:li.:link reftype=hd res=15320.Automatischer Start:elink.
:li.:link reftype=hd res=15330.R�cksprunglimit:elink.
:eul.

.********************************************************************
:h3 res=15310 name=PANEL_SE_AUTOREPEAT.Automatische Wiederholung
:i2 REFID=INDEX_AUTOREPEAT.einstellen (in den Einstellungen)
:lines align=center.:hp7.Automatische Wiederholung:ehp7.:elines.
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
:lines align=center.:hp7.Automatischer Start:ehp7.:elines.
:p.Wenn diese Einstellung aktiviert ist, beginnt der CD Spieler
beim Einlegen einer CD automatisch mit der Wiedergabe am
Anfang des f�r die CD gespeicherten Programms oder des Standardprogramms,
falls kein gespeichertes Programm gefunden wurde, siehe auch
":link reftype=hd res=11262.Wiedergabe starten:elink." und
":link reftype=hd res=13000.Programmeditor:elink.".

.********************************************************************
:h3 res=15330 name=PANEL_SE_BACKWARDTHRESHOLD.R�cksprunglimit
:i1 ID=INDEX_BACKWARDLIMIT.R�cksprunglimit
:lines align=center.:hp7.R�cksprunglimit:ehp7.:elines.
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
:lines align=center.:hp7.Einstellungen Speicherung:ehp7.:elines.
:p.Die Einstellungen f�r die Speicherung stellen die automatische
Speicherung f�r diverse Werte des CD Spielers ein oder aus.
.br
Im einzelnen gibt es folgende Einstellungen&colon.
:ul.
:li.:link reftype=hd res=15410.Fensterposition:elink.
:li.:link reftype=hd res=15420.Lautst�rke:elink.
:li.:link reftype=hd res=15430.CD Position:elink.
:li.:link reftype=hd res=15430.Marker:elink.
:eul.

.********************************************************************
:h3 res=15410 name=PANEL_SE_SAVE_WINDOWS.Fensterposition
:i2 REFID=INDEX_WINDOWS.Automatische Positionsspeicherung
:lines align=center.:hp7.Fensterposition:ehp7.:elines.
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
:lines align=center.:hp7.Lautst�rke:ehp7.:elines.
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
:lines align=center.:hp7.CD Position:ehp7.:elines.
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
:lines align=center.:hp7.Marker:ehp7.:elines.
:p.Diese Einstellung ist zur Zeit noch ohne Funktion.

.********************************************************************
:h2 res=15500 name=PANEL_SE_OUTPUT.Ausgabe
:i2 REFID=INDEX_SETTINGS.Ausgabe
:lines align=center.:hp7.Einstellungen Ausgabe:ehp7.:elines.
:p.Die Einstellungen f�r die Ausgabe legen fest, �ber welchen Anschlu�
die Tonausgabe des CD Spielers erfolgt.
.br
Im einzelnen gibt es folgende Einstellungen&colon.
:ul.
:li.:link reftype=hd res=15510.Kopfh�rer:elink.
:li.:link reftype=hd res=15520.Soundkarte:elink.
:li.:link reftype=hd res=15530.Externer Verst�rker:elink.
:eul.
:note.
Mindestens ein Anschlu� muss eingestellt sein.

.********************************************************************
:h3 res=15510 name=PANEL_SE_OUTPUT_HEADPHONES.Kopfh�rer
:i1 ID=INDEX_HEADPHONES.Kopfh�rer
:i2 REFID=INDEX_CDCONTROL.am Kopfh�rer
:lines align=center.:hp7.Kopfh�rer:ehp7.:elines.
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
:lines align=center.:hp7.Soundkarte:ehp7.:elines.
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
:lines align=center.:hp7.Externer Verst�rker:ehp7.:elines.
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
:lines align=center.:hp7.Ger�t:ehp7.:elines.
:p.Mit diesen Einstellungen wird das Verhalten Ihres CD-ROM Laufwerks
beeinflu�t.
.br
Im einzelnen gibt es folgende Einstellungen&colon.
:ul.
:li.:link reftype=hd res=15610.Laufwerk sperren:elink.
:li.:link reftype=hd res=15620.Ger�tename:elink.
:eul.

.********************************************************************
:h3 res=15610 name=PANEL_SE_HARDWARE_LOCK.Laufwerk sperren
:i2 REFID=INDEX_DEVICE.sperren
:lines align=center.:hp7.Laufwerk sperren:ehp7.:elines.
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
:lines align=center.:hp7.Ger�tename:ehp7.:elines.
:p.Wenn Sie mehrere CD-ROM Laufwerke an Ihren Rechner angeschlossen haben,
k�nnen Sie in dieser Auswahlliste den Namen des CD-ROM Laufwerks ausw�hlen,
das Sie verwenden wollen.

.********************************************************************
:h2 res=15700 name=PANEL_SE_KEYBOARD.Tastatur- und Mausbefehle
:i2 REFID=INDEX_SETTINGS.Tastatur- und Mausbefehle
:i2 REFID=INDEX_KEYBOARD.Befehle in den Einstellungen
:i2 REFID=INDEX_MOUSE.Befehle in den Einstellungen
:lines align=center.:hp7.Tastaturbefehle in den Einstellungen:ehp7.:elines.
:p.In den Einstellungen sind keine besonderen Tastaturbefehle definiert.

:p.:lines align=center.:hp7.Mausbefehle in den Einstellungen:ehp7.:elines.
:p.In den Einstellungen sind keine besonderen Mausbefehle definiert.

.********************************************************************
:h2 res=15800 name=PANEL_SE_MENUS.Men�befehle
:i2 REFID=INDEX_SETTINGS.Men�befehle
:i2 REFID=INDEX_MENU.in den Einstellungen
:lines align=center.:hp7.Men�befehle in den Einstellungen:ehp7.:elines.
:p.In den Einstellungen sind keine besonderen Men�befehle definiert.

.********************************************************************

