.********************************************************************
:userdoc.
:title.CD Spieler Dokumentation
.********************************************************************
.********************************************************************
.********************************************************************
.********************************************************************

.********************************************************************
.********************************************************************
:h1 res=10000 name=PANEL_INTRODUCTION.Einf�hrung
:i1.Einf�hrung
:color fc=black.
:font facename='Tms Rmn' size=28x18.
:artwork align=center name='D:\C\CDPLAYER\HLPINF\CDICON.BMP'.
:lines align=center.:hp2.Der CD Spieler:ehp2.:elines.
:font facename='Tms Rmn' size=18x14.
:p.:lines align=center.:hp2.Version 1.05b:ehp2.:elines.
:p.:lines align=center.:hp2.Copyright Michael Bock 1993-94:ehp2.:elines.
:font facename=default size=0x0.
:color fc=default.
.br
.br

:p.:lines align=center.:hp7.Grundz�ge:ehp7.:elines.
:p.Das Verhalten des CD Spielers ist im Grunde sehr einfach. Beim Start
wird gepr�ft, ob eine CD im Standard CD-ROM Laufwerk der Multimediaerweiterung
eingelegt ist und Audiospuren enth�lt. Ist dies der Fall, stehen sofort alle
M�glichkeiten der Kontrolle des CD Spielers zur Verf�gung. Enth�lt die eingelegte
CD keine Audiospuren, besteht nur die M�glichkeit sie wieder auszuwerfen (falls
man sie nicht andersweitig ben�tigt).
.br
Solange der CD Spieler aktiv ist, wird das CD-ROM Laufwerk �berwacht. Sobald
eine CD ausgeworfen oder neu eingelegt wird, ver�ndert der CD Spieler sein
Aussehen dementsprechend.

:p.:lines align=center.:hp7.Erweiterte M�glichkeiten:ehp7.:elines.
:p.�ber das simple Abspielen einer CD hinaus ist der CD Spieler in der Lage,
Titel von CD und Spuren sowie zus�tzliche Notizen zu bearbeiten und eine eigene
Reihenfolge der abzuspielenden Titel festzulegen. Titel und Programm werden
gespeichert und werden beim erneuten Einlegen derselben CD wieder geladen.
Diese Informationen bleiben auch nach Verlassen des CD Spielers erhalten,
siehe
":link reftype=hd res=12000.Titeleditor:elink." und
":link reftype=hd res=13000.Programmeditor:elink.".
Zus�tzlich k�nnen Aussehen und Verhalten des CD Spielers in den
:link reftype=hd res=15000.Einstellungen:elink. beeinflu�t werden.

:p.:lines align=center.:hp7.Voraussetzungen:ehp7.:elines.
:ul.
:li.Ein Rechner mit installierten OS/2 2.1 inklusive Multimediaerweiterung. Der
CD Spieler m��te auch mit OS/2 2.0 und Multimediaerweiterung arbeiten, dieser
Fall ist jedoch nicht getestet.
:li.Ein audiof�higes CD-ROM Laufwerk, das von der Multimediaerweiterung unterst�tzt
wird.
:eul.
:p.:lines align=center.:hp7.Einschr�nkungen:ehp7.:elines.
:ul.
:li.In der momentanen Version ist es nicht m�glich den CD Spieler zusammen mit anderen
Programmen zu betreiben, die die Audiom�glichkeiten des CD-ROM Laufwerks ansprechen.
Aus diesem Grund kann der CD Spieler auch nicht mehrfach aufgerufen werden.
:li.In der momentanen Version ist es nicht m�glich ein Programm w�hrend der Wiedergabe
zu �ndern. Sobald das neue Programm gespeichert wird, wird die Wiedergabe gestoppt.
:li.Beenden des CD Spielers beendet auch die Wiedergabe. Dies ist eine prinzipielle
Einschr�nkung der Multimediaerweiterung von OS/2.
:eul.
:p.:lines align=center.:hp7.Entstehungsgeschichte:ehp7.:elines.
:p.Der CD Spieler entstand urspr�nglich aus der Motivation heraus, die
neuen M�glichkeiten des Multimedia Presentationmanagers auszuprobieren.
Das Projekt wurde aber immer gr��er und wuchs bald weit �ber diese
anf�ngliche Spielerei hinaus. Da in dieser Version sehr viel Arbeit
und Zeit steckt, wird sie als Shareware vertrieben, siehe
:link reftype=hd res=18000.Copyright:elink..
.********************************************************************
.********************************************************************
.********************************************************************
:h1 res=11000 name=PANEL_MAINWINDOW.Hauptfenster
:i2 REFID=INDEX_WINDOWS.Hauptfenster
:i2 REFID=INDEX_MAINWINDOW.�berblick
:lines align=center.:hp7.Das Hauptfenster des CD Spielers:ehp7.:elines.
:p.Das Hauptfenster enthalt mehrere
:link reftype=hd res=11100.Anzeigen:elink., die �ber den Status des
CD Spielers, die eingelegte CD und das ausgew�hlte Programm informieren.
.br
Au�erdem enth�lt es alle zur Steuerung des CD Spielers notwendigen
:link reftype=hd res=11200.Kontrollelemente:elink.,
sowie Kn�pfe um
:link reftype=hd res=12000.Titeleditor:elink.,
:link reftype=hd res=13000.Programmeditor:elink.,
:link reftype=hd res=15000.Einstellungen:elink. und das
:link reftype=hd res=14000.Infofenster:elink.
aufzurufen.
:p.Dar�ber hinaus k�nnen die meisten Befehle auch �ber
:link reftype=hd res=11300.Tastatur:elink.- und
:link reftype=hd res=11400.Men�befehle:elink.
gegeben werden.

.********************************************************************
:h2 res=11100 name=PANEL_MW_DISPLAY.Anzeigeelemente
:i2 REFID=INDEX_MAINWINDOW.Anzeigeelemente
:i2 REFID=INDEX_DISPLAY.im Hauptfenster
:lines align=center.:hp7.Anzeigen im Hauptfenster:ehp7.:elines.
:ul.
:li.:link reftype=hd res=11110.Zeitanzeige:elink.
:li.:link reftype=hd res=11120.Programmanzeige:elink.
:li.:link reftype=hd res=11130.Lautst�rkeanzeige:elink.
:li.:link reftype=hd res=11150.Titelanzeige:elink.
:li.:link reftype=hd res=11140.Positionsanzeige:elink.
:li.:link reftype=hd res=11160.Wiedergabeanzeige:elink.
:eul.

.********************************************************************
:h3 res=11110 name=PANEL_MW_DISP_TIME.Zeitanzeige
:i2 REFID=INDEX_TRACKS.Anzeige im Hauptfenster
:i2 REFID=INDEX_TIME.Anzeige im Hauptfenster
:lines align=center.:hp7.Die Zeitanzeige:ehp7.:elines.
:artwork align=center name='D:\C\CDPLAYER\HLPINF\DEU\DSPTIME.BMP'.
:p.Es gibt insgesamt f�nf Anzeigen in diesem Bereich&colon.
:ul.
:li.:hp2.Die L�nge des Programms bis zur momentanen Position oben in
:color fc=black.schwarz:color fc=default.:ehp2.
:li.:hp2.Die L�nge des Programms ab der momentanen Position oben in
:color fc=red.rot:color fc=default.:ehp2.
:li.:hp2.Die L�nge der momentanen Spur bis zur momentanen Position in der Mitte in
:color fc=black.schwarz:color fc=default.:ehp2.
:li.:hp2.Die L�nge der momentanen Spur ab der momentanen Position in der Mitte in
:color fc=red.rot:color fc=default.:ehp2.
:li.:hp2.Die Spurnummer der momentanen Spur auf der CD unten in
:color fc=black.schwarz:color fc=default.:ehp2.
:eul.
:p.W�hrend der Wiedergabe werden die Zeitangaben mit der in den
:link reftype=hd res=15000.Einstellungen:elink. unter
:link reftype=hd res=15100.Zeitformat:elink. gew�hlten
:link reftype=hd res=15140.Aktualisierungsrate:elink. aktualisiert.
.br
Dort l��t sich au�erdem der
:link reftype=hd res=15130.Separator:elink. f�r die Zeitzeige und eines
der Zeitformate
:link reftype=hd res=15110.Stunden/Minuten/Sekunden:elink. und
:link reftype=hd res=15120.Minuten/Sekunden/Frames:elink. w�hlen.


.********************************************************************
:h3 res=11120 name=PANEL_MW_DISP_PROGRAM.Programmanzeige
:i2 REFID=INDEX_PROGRAM.Anzeige im Hauptfenster
:lines align=center.:hp7.Die Programmanzeige:ehp7.:elines.
:artwork align=center name='D:\C\CDPLAYER\HLPINF\DEU\DSPPROG.BMP'.
:p.Im Programmfenster werden die Spurnummern des gew�hlten Programms angezeigt.
Wenn nicht alle Spurnummern in den Ausschnitt passen, kann dieser mit dem Balken
rechts neben dem Ausschnitt verschoben werden. Die selektierte Spurnummer entspricht
:hp2.nicht:ehp2. der momentanen Spur, sondern kann von Ihnen
ver�ndert werden, um eine andere Spur im Programm auszuw�hlen, siehe
":link reftype=hd res=11210.Titelauswahl in der Programmanzeige:elink.".
.br
Das Programm selbst kann mit dem Programmeditor ver�ndert werden, siehe
":link reftype=hd res=11231.Programmeditor starten:elink." und
":link reftype=hd res=13000.Programmeditor:elink.".

.********************************************************************
:h3 res=11130 name=PANEL_MW_DISP_VOLUME.Lautst�rkeanzeige
:i2 REFID=INDEX_VOLUME.Anzeige im Hauptfenster
:lines align=center.:hp7.Die Lautst�rkeanzeige:ehp7.:elines.
:artwork align=center name='D:\C\CDPLAYER\HLPINF\DEU\DSPVOL.BMP'.
:p.Aus der Lautst�rkeanzeige kann man die momentane Lautst�rke der beiden
Kan�le an der Position der Schieber ablesen. Steht ein Schieber ganz
oben, so ist Lautst�rke des entsprechenden Kanals maximal, steht er
ganz unten, ist sie minimal. Mit den Schiebern l��t sich die Lautst�rke
auch ver�ndern, siehe
":link reftype=hd res=11220.Lautst�rke links einstellen:elink." und
":link reftype=hd res=11221.Lautst�rke rechts einstellen:elink.".
:p.An den Symbol auf dem Knopf unten rechts kann man erkennen, ob der Ton
aus- oder eingestellt ist. In der obigen Anzeige ist der Ton eingestellt,
bei ausgestellten Ton �ndert sich der Knopf zu diesem Symbol&colon.
:artwork runin name='D:\C\CDPLAYER\HLPINF\BTNMUTE1.BMP'., siehe auch
":link reftype=hd res=11224.Ton aus/an:elink.".

.********************************************************************
:h3 res=11150 name=PANEL_MW_DISP_TITLE.Titelanzeige
:i2 REFID=INDEX_TITLE.Anzeige im Hauptfenster
:lines align=center.:hp7.Die Titelanzeige:ehp7.:elines.
:p.Rechts neben dem Text "Titel&colon." wird der momentane Titel
im Programm und die Nummer der entsprechenden Spur auf der CD angezeigt.
Diese entspricht nicht der Position des Titels im Programm,
sondern dient nur zur Orientierung, falls die entprechende Spur noch keinen
Titel hat.
.br
Alle Titel k�nnen angezeigt werden, wenn der
nach unten zeigende Pfeil rechts neben dem momentanen Titel mit der
Maus angeklickt wird.
.br
So kann auch ein neuer Titel f�r die Wiedergabe ausgew�hlt werden, siehe
":link reftype=hd res=11240.Titel nach Namen w�hlen:elink.".

:p.Der Titel der eingelegten CD wird in der Titelleiste des Hauptfensters
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
:i2 REFID=INDEX_POSITION.Anzeige im Hauptfenster
:lines align=center.:hp7.Die Positionsanzeige:ehp7.:elines.
:artwork align=center name='D:\C\CDPLAYER\HLPINF\DEU\DSPSLIDE.BMP'.
:p.Die kleinen Markierungen oberhalb der Positionsanzeige stellen die
Startposition der einzelnen Titel im Programm dar. �ber den Markierungen
wird die Spurnummer des jeweiligen Titels angezeigt. Der Schieber steht
immer an der momentanen Position. Es ist auch m�glich mit dem Schieber
die Position direkt zu ver�ndern, siehe
":link reftype=hd res=11250.Position einstellen:elink.".

.********************************************************************
:h3 res=11160 name=PANEL_MW_DISP_CONTROLS.Wiedergabeanzeige
:i2 REFID=INDEX_CDCONTROL.Anzeige im Hauptfenster
:lines align=center.:hp7.Die Wiedergabeanzeige:ehp7.:elines.
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
:eul.
:p.Beide Kn�pfe lassen sich auch dazu verwenden, die Wiedergabe zu
starten oder zu unterbrechen, siehe
":link reftype=hd res=11262.Wiedergabe starten:elink." und
":link reftype=hd res=11263.Wiedergabe unterbrechen:elink.".


.********************************************************************
:h2 res=11200 name=PANEL_MW_CONTROL.Steuerung
:i2 REFID=INDEX_MAINWINDOW.Steuerung
:i2 REFID=INDEX_CONTROL.im Hauptfenster
:lines align=center.:hp7.Kontrollelemente im Hauptfenster:ehp7.:elines.
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
:eul.

.********************************************************************
:h3 res=11210 name=PANEL_MW_CTRL_PROGRAM.Titelauswahl in der Programmanzeige
:i2 REFID=INDEX_TITLE.aus dem Programm w�hlen
:i2 REFID=INDEX_PROGRAM.Titel ausw�hlen (im Hauptfenster)
:lines align=center.:hp7.Titelauswahl in der Programmanzeige:ehp7.:elines.
:artwork align=center name='D:\C\CDPLAYER\HLPINF\DEU\DSPPROG.BMP'.
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
:lines align=center.:hp7.Lautst�rke links einstellen:ehp7.:elines.
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
:lines align=center.:hp7.Lautst�rke rechts einstellen:ehp7.:elines.
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
:lines align=center.:hp7.Option&colon. Kan�le unabh�ngig einstellen:ehp7.:elines.
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
:eul.
:note.
Es kann sein, da� Ihr CD-ROM Laufwerk diese Option nicht unterst�tzt. In diesem Fall
ist der Schalter deaktiviert.


.********************************************************************
:h3 res=11223 name=PANEL_MW_CTRL_VOL_SWAP.Kan�le vertauschen
:i2 REFID=INDEX_VOLUME.Kan�le vertauschen
:i2 REFID=INDEX_CHANNELS.vertauschen
:lines align=center.:hp7.Option&colon. Kan�le vertauschen:ehp7.:elines.
:p.Mit dem Schalter :hp2.Tauschen:ehp2. k�nnen der linke und der rechte
Kanal bei der Ausgabe vertauscht werden.
:p.Diese Option kann auf folgende Arten ge�ndert werden&colon.
:ul.
:li.Mit den Schalter :hp2.Tauschen:ehp2.
:eul.
:note.
Es kann sein, da� Ihr CD-ROM Laufwerk diese Option nicht unterst�tzt. In diesem Fall
ist der Schalter deaktiviert.

.********************************************************************
:h3 res=11224 name=PANEL_MW_CTRL_VOL_MUTE.Ton aus/an
:i2 REFID=INDEX_VOLUME.Ton aus/an
:i2 REFID=INDEX_SOUND.ausstellen
:i2 REFID=INDEX_SOUND.anstellen
:lines align=center.:hp7.Option&colon. Ton aus/an:ehp7.:elines.
:p.Mit diesem Schalter k�nnen Sie den Ton kurzfristig aus- und wieder
anstellen, ohne die eingestellte Lautst�rke zu ver�ndern.
.br
Siehe auch ":link reftype=hd res=11130.Lautst�rkeanzeige:elink.".
:p.Diese Option kann auf folgende Arten ge�ndert werden&colon.
:ul.
:li.Mit den Kn�pfen :artwork runin name='D:\C\CDPLAYER\HLPINF\BTNMUTE0.BMP'.
oder :artwork runin name='D:\C\CDPLAYER\HLPINF\BTNMUTE1.BMP'.
:li.Mit der :link reftype=hd res=11300.Tastenkombination:elink. :hp2.Strg+M:ehp2.
:li.Mit dem Befehl :hp2.T:ehp2.:hp7.o:ehp7.:hp2.n aus:ehp2. bzw. 
:hp2.T:ehp2.:hp7.o:ehp7.:hp2.n an:ehp2. im
:link reftype=hd res=11420.Popupmen�:elink.
:li.Mit dem Befehl :hp2.T:ehp2.:hp7.o:ehp7.:hp2.n aus:ehp2. bzw.
:hp2.T:ehp2.:hp7.o:ehp7.:hp2.n an:ehp2. im
:link reftype=hd res=11410.Systemmen�:elink.
:eul.
:note.
Es kann sein, das Ihr CD-ROM Laufwerk diese Option nicht unterst�tzt. In diesem Fall
ist der Schalter deaktiviert.

.********************************************************************
:h3 res=11230 name=PANEL_MW_CTRL_TITLEEDITOR.Titeleditor starten
:i2 REFID=INDEX_TITLEEDITOR.starten
:lines align=center.:hp7.Befehl&colon. Titeleditor starten:ehp7.:elines.
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
:eul.

.********************************************************************
:h3 res=11231 name=PANEL_MW_CTRL_PROGRAMEDITOR.Programmeditor starten
:i2 REFID=INDEX_PROGRAMEDITOR.starten (im Hauptfenster)
:lines align=center.:hp7.Befehl&colon. Programmeditor starten:ehp7.:elines.
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
:eul.

.********************************************************************
:h3 res=11232 name=PANEL_MW_CTRL_SETTINGS.Einstellungen aufrufen
:i2 REFID=INDEX_SETTINGS.aufrufen
:lines align=center.:hp7.Befehl&colon. Einstellungen aufrufen:ehp7.:elines.
:p.Mit diesem Befehl werden die
:link reftype=hd res=15000.Einstellungen:elink. aufgerufen.
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit dem Knopf :hp7.E:ehp7.:hp2.instellungen...:ehp2.
:li.Mit dem Befehl :hp7.E:ehp7.:hp2.instellungen...:ehp2. im
:link reftype=hd res=11420.Popupmen�:elink.
:li.Mit dem Befehl :hp7.E:ehp7.:hp2.instellungen...:ehp2. im Untermen�
:hp7.F:ehp7.:hp2.enster:ehp2. des :link reftype=hd res=11410.Systemmen�s:elink.
:eul.

.********************************************************************
:h3 res=11233 name=PANEL_MW_CTRL_INFO.Infofenster anzeigen
:i2 REFID=INDEX_INFOWINDOW.anzeigen (im Hauptfenster)
:lines align=center.:hp7.Befehl&colon. Infofenster anzeigen:ehp7.:elines.
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
:eul.

.********************************************************************
:h3 res=11240 name=PANEL_MW_CTRL_TITLE.Titel nach Namen w�hlen
:i2 REFID=INDEX_TITLE.nach Namen w�hlen
:i2 REFID=INDEX_NAMES.f�r Wiedergabe ausw�hlen
:lines align=center.:hp7.Titel nach Namen w�hlen:ehp7.:elines.
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
:lines align=center.:hp7.Position einstellen:ehp7.:elines.
:artwork align=center name='D:\C\CDPLAYER\HLPINF\DEU\DSPSLIDE.BMP'.
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
:lines align=center.:hp7.Befehl&colon. Titel zur�ck:ehp7.:elines.
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
:eul.

.********************************************************************
:h3 res=11261 name=PANEL_MW_CTRL_FORWARD.Titel vorw�rts
:i1.Vorw�rts
:i2 REFID=INDEX_TITLE.vorw�rts
:i2 REFID=INDEX_CDCONTROL.Titel vorw�rts
:lines align=center.:hp7.Befehl&colon. Titel vorw�rts:ehp7.:elines.
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
:eul.

.********************************************************************
:h3 res=11262 name=PANEL_MW_CTRL_PLAY.Wiedergabe starten
:isyn ROOT=start.Start
:i1 ROOTS='start'.Starten
:i2 REFID=INDEX_CDCONTROL.starten
:lines align=center.:hp7.Befehl&colon. Wiedergabe starten:ehp7.:elines.
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
:eul.

.********************************************************************
:h3 res=11263 name=PANEL_MW_CTRL_PAUSE.Wiedergabe unterbrechen
:isyn ROOT=pause.Unterbrechung
:i1 ROOTS='pause'.Unterbrechen
:i2 REFID=INDEX_CDCONTROL.unterbrechen
:lines align=center.:hp7.Befehl&colon. Wiedergabe unterbrechen:ehp7.:elines.
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
:eul.

.********************************************************************
:h3 res=11264 name=PANEL_MW_CTRL_STOP.Wiedergabe stoppen
:isyn ROOT=stop.Stop
:i1 ROOTS='stop'.Stoppen
:i2 REFID=INDEX_CDCONTROL.stoppen
:lines align=center.:hp7.Befehl&colon. Wiedergabe stoppen:ehp7.:elines.
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
:eul.

.********************************************************************
:h3 res=11265 name=PANEL_MW_CTRL_EJECT.CD auswerfen
:isyn ROOT=eject.Auswurf
:i1 ROOTS='eject'.Auswerfen
:i2 REFID=INDEX_CD.auswerfen
:lines align=center.:hp7.Befehl&colon. CD auswerfen:ehp7.:elines.
:p.Dieser Befehl wirft die CD aus.
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit dem Knopf :artwork runin name='D:\C\CDPLAYER\HLPINF\BTNEJECT.BMP'.
:li.Mit der :link reftype=hd res=11300.Tastenkombination:elink. :hp2.Strg+E:ehp2.
:li.Mit dem Befehl :hp7.A:ehp7.:hp2.uswurf:ehp2. im
:link reftype=hd res=11420.Popupmen�:elink.
:li.Mit dem Befehl :hp7.A:ehp7.:hp2.uswurf:ehp2. im Untermen�
:hp7.S:ehp7.:hp2.teuerung:ehp2. des :link reftype=hd res=11410.Systemmen�s:elink.
:eul.
:note.
Es kann sein, da� Ihr CD-ROM Laufwerk diesen Befehl nicht unterst�tzt. In diesem Fall
sind der Befehlsknopf und die Men�punkte deaktiviert.

.********************************************************************
:h3 res=11266 name=PANEL_MW_CTRL_REPEAT.Automatische Wiederholung einstellen
:i1.Wiederholung
:i2 REFID=INDEX_CDCONTROL.automatisch wiederholen
:i2 REFID=INDEX_AUTOREPEAT.einstellen (im Hauptfenster)
:lines align=center.:hp7.Option&colon. Automatische Wiederholung:ehp7.:elines.
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
:eul.
:p.Diese Option kann auch in den
:link reftype=hd res=15000.Einstellungen:elink. unter
:link reftype=hd res=15300.Wiedergabe:elink. mit der Option
:link reftype=hd res=15310.Autowiederholung:elink. ge�ndert werden. In diesem Fall
bleibt die Einstellung der Option auch nach Programmende erhalten.

.********************************************************************
:h2 res=11300 name=PANEL_MW_KEYBOARD.Tastatur- und Mausbefehle
:i2 REFID=INDEX_MAINWINDOW.Tastatur- und Mausbefehle
:i2 REFID=INDEX_KEYBOARD.Befehle im Hauptfenster
:i2 REFID=INDEX_MOUSE.Befehle im Hauptfenster
:lines align=center.:hp7.Tastaturbefehle im Hauptfenster:ehp7.:elines.
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

:p.:lines align=center.:hp7.Mausbefehle im Hauptfenster:ehp7.:elines.
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
:i2 REFID=INDEX_MENU.im Hauptfenster
:lines align=center.:hp7.Men�befehle im Hauptfenster:ehp7.:elines.
:p.Die wichtigsten Befehle und Optionen im Hauptfenster k�nnen auch �ber
das
:link reftype=hd res=11420.Popupmen�:elink. und das erweiterte
:link reftype=hd res=11410.Systemmen�:elink. gegeben bzw. eingestellt werden.
.br
Das
:link reftype=hd res=11420.Popupmen�:elink. kann mit einfachem Klick der
rechten Maustaste an einer beliebigen Position im Hauptfenster oder �ber
die Tastenkombination Umsch+F10 aufgerufen werden.

.********************************************************************
:h3 res=11420 name=PANEL_MW_MENU_POPUP.Popupmen�
:i2 REFID=INDEX_POPUPMENU.im Hauptfenster
:lines align=center.:hp7.Das Popupmen� im Hauptfenster:ehp7.:elines.
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
:i2 REFID=INDEX_SYSMENU.im Hauptfenster
:lines align=center.:hp7.Das erweiterte Systemmen� im Hauptfenster:ehp7.:elines.
:p.Zus�tzlich zu den normalen Men�punkten des Systemmen�s enth�lt das Systemmen� des
Hauptfensters folgende Men�punkte:
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
:lines align=center.:hp7.Der Titeleditor:ehp7.:elines.
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
:lines align=center.:hp7.Anzeigen im Titeleditor:ehp7.:elines.
:ul.
:li.:link reftype=hd res=12110.CD Titel:elink.
:li.:link reftype=hd res=12120.Zus�tzliche CD Information:elink.
:li.:link reftype=hd res=12130.Spurnummern:elink.
:li.:link reftype=hd res=12140.Spurtitel:elink.
:li.:link reftype=hd res=12150.Zus�tzliche Spurinformation:elink.
:eul.

.********************************************************************
:h3 res=12110 name=PANEL_TE_DISP_CDTITLE.CD Titel
:i2 REFID=INDEX_CD.Titel (im Titeleditor)
:i2 REFID=INDEX_TITLE.der CD (im Titeleditor)
:lines align=center.:hp7.CD Titel:ehp7.:elines.
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
:lines align=center.:hp7.Zus�tzliche CD Information:ehp7.:elines.
:p.Das untere Feld in der Box "CD Titel" zeigt die zus�tzliche Information
zu der ausgew�hlten CD an. Im
:link reftype=fn refid=changemode.�nderungsmodus:elink. k�nnen Sie die
:link reftype=hd res=12220.zus�tzliche Information zur CD �ndern:elink..

.********************************************************************
:h3 res=12130 name=PANEL_TE_DISP_SCROLLBAR.Spurnummern
:i2 REFID=INDEX_TRACK.Nummern (im Titeleditor)
:i2 REFID=INDEX_NUMBER.der Spur (im Titeleditor)
:lines align=center.:hp7.Spurnummern:ehp7.:elines.
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
:lines align=center.:hp7.Spurtitel:ehp7.:elines.
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
:lines align=center.:hp7.Zus�tzliche Spurinformation:ehp7.:elines.
:p.Das untere Feld in der Box "Spurtitel" zeigt die zus�tzliche Information
zu der ausgew�hlten Spur an. Im
:link reftype=fn refid=changemode.�nderungsmodus:elink. k�nnen Sie die
:link reftype=hd res=12250.zus�tzliche Information zur Spur �ndern:elink..

.********************************************************************
:h2 res=12200 name=PANEL_TE_CONTROL.Steuerung
:i2 REFID=INDEX_TITLEEDITOR.Steuerung
:i2 REFID=INDEX_CONTROL.im Titeleditor
:lines align=center.:hp7.Steuerung im Titeleditor:ehp7.:elines.
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
:eul.

.********************************************************************
:h3 res=12210 name=PANEL_TE_CTRL_CDTITLE.CD Titel �ndern/ausw�hlen
:i2 REFID=INDEX_CD.Titel �ndern (im Titeleditor)
:i2 REFID=INDEX_TITLE.der CD �ndern (im Titeleditor)
:lines align=center.:hp7.CD Titel �ndern/ausw�hlen:ehp7.:elines.
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
:lines align=center.:hp7.Zus�tzliche CD Information �ndern:ehp7.:elines.
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
:lines align=center.:hp7.Spurnummer ausw�hlen:ehp7.:elines.
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
:lines align=center.:hp7.Spurtitel �ndern/ausw�hlen:ehp7.:elines.
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
:lines align=center.:hp7.Zus�tzliche Spurinformation �ndern:ehp7.:elines.
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
:lines align=center.:hp7.Befehl&colon. CD Bibliothek:ehp7.:elines.
:p.Mit diesem Befehl setzen Sie den
:link reftype=hd res=12000.Titeleditor:elink.
in den
:link reftype=fn refid=librarymode.Bibliotheksmodus:elink.
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit dem Knopf :hp7.B:ehp7.:hp2.ibliothek:ehp2.
:li.Mit der :link reftype=hd res=12300.Tastenkombination:elink. :hp2.Strg+L:ehp2.
:eul.

.********************************************************************
:h3 res=12261 name=PANEL_TE_CTRL_INFO.Infofenster anzeigen
:i2 REFID=INDEX_INFOWINDOW.anzeigen (im Titeleditor)
:lines align=center.:hp7.Befehl&colon. Infofenster anzeigen:ehp7.:elines.
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
:eul.

.********************************************************************
:h3 res=12262 name=PANEL_TE_CTRL_PROGRAM.Programm bearbeiten
:i2 REFID=INDEX_PROGRAMEDITOR.starten (im Titeleditor)
:lines align=center.:hp7.Befehl&colon. Programm bearbeiten:ehp7.:elines.
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
:eul.

.********************************************************************
:h3 res=12263 name=PANEL_TE_CTRL_IMPORT.Titel importieren
:isyn ROOT=import.Importieren
:i1 ROOTS='import' ID=INDEX_IMPORT.Import
:lines align=center.:hp7.Befehl&colon. Titel importieren:ehp7.:elines.
:p.Dieser Befehl ist zur Zeit noch ohne Funktion.
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit dem Knopf :hp2.I:ehp2.:hp7.m:ehp7.:hp2.port:ehp2.
:eul.

.********************************************************************
:h3 res=12270 name=PANEL_TE_CTRL_CHANGE.Ausgew�hlte CD bearbeiten
:i2 REFID=INDEX_CD.Titel bearbeiten (im Titeleditor)
:lines align=center.:hp7.Befehl&colon. Ausgew�hlte CD bearbeiten:ehp7.:elines.
:p.Mit diesem Befehl setzen Sie den
:link reftype=hd res=12000.Titeleditor:elink.
in den
:link reftype=fn refid=changemode.�nderungsmodus:elink.
f�r die ausgew�hlte CD.
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit dem Knopf :hp7.B:ehp7.:hp2.earbeiten:ehp2.
:li.Mit der :link reftype=hd res=12300.Tastenkombination:elink. :hp2.Strg+L:ehp2.
:eul.

.********************************************************************
:h3 res=12271 name=PANEL_TE_CTRL_DELETE.Ausgew�hlte CD l�schen
:i2 REFID=INDEX_CD.Titel l�schen (im Titeleditor)
:i2 REFID=INDEX_LIBRARY.CD l�schen (im Titeleditor)
:i2 REFID=INDEX_TITLE.der CD l�schen (im Titeleditor)
:lines align=center.:hp7.Befehl&colon. Ausgew�hlte CD l�schen:ehp7.:elines.
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
:eul.


.********************************************************************
:h3 res=12280 name=PANEL_TE_CTRL_QUIT.Titeleditor verlassen
:i2 REFID=INDEX_TITLEEDITOR.verlassen
:lines align=center.:hp7.Befehl&colon. Titeleditor verlassen:ehp7.:elines.
:p.Dieser Befehl beendet den Titeleditor. �nderungen werden automatisch
gespeichert.
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit dem Knopf :hp7.V:ehp7.:hp2.erlassen:ehp2.
:li.Mit der :link reftype=hd res=12300.Tastenkombination:elink. :hp2.Strg+Q:ehp2.
:eul.

.********************************************************************
:h2 res=12300 name=PANEL_TE_KEYBOARD.Tastatur- und Mausbefehle
:i2 REFID=INDEX_TITLEEDITOR.Tastatur- und Mausbefehle
:i2 REFID=INDEX_KEYBOARD.Befehle im Titeleditor
:i2 REFID=INDEX_MOUSE.Befehle im Titeleditor
:lines align=center.:hp7.Tastaturbefehle im Titeleditor:ehp7.:elines.
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
:lines align=center.:hp7.Men�befehle im Titeleditor:ehp7.:elines.
:p.Im Titeleditor sind keine besonderen Men�befehle definiert.

.********************************************************************

.********************************************************************
.********************************************************************
:h1 res=13000 name=PANEL_PLAYLIST.Programmeditor
:i2 REFID=INDEX_WINDOWS.Programmeditor
:i2 REFID=INDEX_PROGRAMEDITOR.�berblick
:i2 REFID=INDEX_PROGRAM.Editor
:lines align=center.:hp7.Der Programmeditor:ehp7.:elines.
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
:lines align=center.:hp7.Anzeigen im Programmeditor:ehp7.:elines.
:ul.
:li.:link reftype=hd res=13110.CD Anzeige:elink.
:li.:link reftype=hd res=13120.Titel auf der CD:elink.
:li.:link reftype=hd res=13130.Programmanzeige:elink.
:li.:link reftype=hd res=13140.Titel im Programm:elink.
:eul.

.********************************************************************
:h3 res=13110 name=PANEL_PE_DISP_CD.CD Anzeige
:i2 REFID=INDEX_TOTALLENGTH.der CD (im Programmeditor)
:i2 REFID=INDEX_TRACKS.Anzahl auf der CD (im Programmeditor)
:lines align=center.:hp7.CD Anzeige:ehp7.:elines.
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
:lines align=center.:hp7.Titel auf der CD:ehp7.:elines.
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
:lines align=center.:hp7.Programmanzeige:ehp7.:elines.
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
:lines align=center.:hp7.Titel im Programm:ehp7.:elines.
:p.In der rechten Auswahlliste werden alle Titel im Programm angezeigt.
:p.In dieser Auswahlliste k�nnen auch Titel zum Entfernen aus dem Programm
ausgew�hlt werden, siehe
":link reftype=hd res=13220.Titelauswahl im Programm:elink.".

.********************************************************************
:h2 res=13200 name=PANEL_PE_CONTROL.Steuerung
:i2 REFID=INDEX_PROGRAMEDITOR.Steuerung
:i2 REFID=INDEX_CONTROL.im Programmeditor
:lines align=center.:hp7.Steuerung im Programmeditor:ehp7.:elines.
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
:eul.

.********************************************************************
:h3 res=13210 name=PANEL_PE_CTRL_CDSELECT.Titelauswahl auf der CD
:i2 REFID=INDEX_TITLE.auf der CD ausw�hlen (im Programmeditor)
:lines align=center.:hp7.Titelauswahl auf der CD:ehp7.:elines.
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
:lines align=center.:hp7.Titelauswahl im Programm:ehp7.:elines.
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
:lines align=center.:hp7.Befehl&colon. Infofenster anzeigen:ehp7.:elines.
:p.Dieser Befehl zeigt das
:link reftype=hd res=14000.Infofenster:elink.
f�r die CD an, deren Programm bearbeitet wird.
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit dem Knopf :hp7.I:ehp7.:hp2.nfo:ehp2.
:li.Mit der :link reftype=hd res=13300.Tastenkombination:elink. :hp2.Strg+I:ehp2.
:eul.

.********************************************************************
:h3 res=13231 name=PANEL_PE_CTRL_SAVE.Programm speichern
:i2 REFID=INDEX_PROGRAM.speichern (im Programmeditor)
:lines align=center.:hp7.Befehl&colon. Programm speichern:ehp7.:elines.
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
:eul.

.********************************************************************
:h3 res=13232 name=PANEL_PE_CTRL_QUIT.Programmeditor verlassen
:i2 REFID=INDEX_PROGRAMEDITOR.verlassen
:lines align=center.:hp7.Befehl&colon. Programmeditor verlassen:ehp7.:elines.
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
:eul.

.********************************************************************
:h3 res=13240 name=PANEL_PE_CTRL_INSERTBEGIN.Titel am Anfang einf�gen
:i2 REFID=INDEX_PROGRAM.Titel am Anfang einf�gen (im Programmeditor)
:i2 REFID=INDEX_TITLE.am Anfang des Programm einf�gen (im Programmeditor)
:lines align=center.:hp7.Befehl&colon. Titel am Anfang einf�gen:ehp7.:elines.
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
:eul.

.********************************************************************
:h3 res=13241 name=PANEL_PE_CTRL_INSERT.Titel einf�gen
:i2 REFID=INDEX_PROGRAM.Titel einf�gen (im Programmeditor)
:i2 REFID=INDEX_TITLE.in das Programm einf�gen (im Programmeditor)
:lines align=center.:hp7.Befehl&colon. Titel einf�gen:ehp7.:elines.
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
:eul.

.********************************************************************
:h3 res=13242 name=PANEL_PE_CTRL_INSERTEND.Titel am Ende einf�gen
:i2 REFID=INDEX_PROGRAM.Titel am Ende einf�gen (im Programmeditor)
:i2 REFID=INDEX_TITLE.am Ende des Programm einf�gen (im Programmeditor)
:lines align=center.:hp7.Befehl&colon. Titel am Ende einf�gen:ehp7.:elines.
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
:eul.

.********************************************************************
:h3 res=13243 name=PANEL_PE_CTRL_DELETE.Titel entfernen
:i2 REFID=INDEX_PROGRAM.Titel entfernen (im Programmeditor)
:i2 REFID=INDEX_TITLE.aus dem Programm entfernen (im Programmeditor)
:lines align=center.:hp7.Befehl&colon. Titel entfernen:ehp7.:elines.
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
:eul.

.********************************************************************
:h3 res=13250 name=PANEL_PE_CTRL_SHUFFLE.Programm mischen
:i2 REFID=INDEX_PROGRAM.mischen (im Programmeditor)
:lines align=center.:hp7.Befehl&colon. Programm mischen:ehp7.:elines.
:p.Dieser Befehl mischt alle Titel im Programm in einer zuf�lligen
Reihenfolge.
:link reftype=hd res=13130.Gesamtl�nge und Anzahl der Titel:elink.
werden dadurch nicht ver�ndert.
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit dem Knopf :hp7.M:ehp7.:hp2.ischen:ehp2.
:li.Mit der :link reftype=hd res=13300.Tastenkombination:elink. :hp2.Strg+U:ehp2.
:eul.

.********************************************************************
:h3 res=13251 name=PANEL_PE_CTRL_REVERSE.Programm umdrehen
:i2 REFID=INDEX_PROGRAM.umdrehen (im Programmeditor)
:lines align=center.:hp7.Befehl&colon. Program umdrehen:ehp7.:elines.
:p.Dieser Befehl dreht die Reihenfolge der Titel im Programm um.
:link reftype=hd res=13130.Gesamtl�nge und Anzahl der Titel:elink.
werden dadurch nicht ver�ndert.
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit dem Knopf :hp7.U:ehp7.:hp2.mdrehen:ehp2.
:li.Mit der :link reftype=hd res=13300.Tastenkombination:elink. :hp2.Strg+R:ehp2.
:eul.

.********************************************************************
:h3 res=13252 name=PANEL_PE_CTRL_STANDARD.Standardprogramm w�hlen
:i2 REFID=INDEX_PROGRAM.Standardprogramm (im Programmeditor)
:lines align=center.:hp7.Befehl&colon. Standardprogramm w�hlen:ehp7.:elines.
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
:eul.

.********************************************************************
:h2 res=13300 name=PANEL_PE_KEYBOARD.Tastatur- und Mausbefehle
:i2 REFID=INDEX_PROGRAMEDITOR.Tastatur- und Mausbefehle
:i2 REFID=INDEX_KEYBOARD.Befehle im Programmeditor
:i2 REFID=INDEX_MOUSE.Befehle im Programmeditor
:lines align=center.:hp7.Tastaturbefehle im Programmeditor:ehp7.:elines.
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
:lines align=center.:hp7.Men�befehle im Programmeditor:ehp7.:elines.
:p.Im Programmeditor sind keine besonderen Men�befehle definiert.

.********************************************************************

.********************************************************************
.********************************************************************
:h1 res=14000 name=PANEL_INFO.Infofenster
:i2 REFID=INDEX_WINDOWS.Infofenster
:i2 REFID=INDEX_INFOWINDOW.�berblick
:i2 REFID=INDEX_CD.Infofenster anzeigen
:lines align=center.:hp7.Das Infofenster:ehp7.:elines.
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
:lines align=center.:hp7.Die Anzeigen im Infofenster:ehp7.:elines.
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
:eul.

.********************************************************************
:h3 res=14110 name=PANEL_IN_DISP_LENGTHCD.Gesamtl�nge der CD
:i2 REFID=INDEX_TOTALLENGTH.der CD (im Infofenster)
:i2 REFID=INDEX_CD.Gesamtl�nge (im Infofenster)
:lines align=center.:hp7.Gesamtl�nge der CD:ehp7.:elines.
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
:lines align=center.:hp7.Startposition der CD:ehp7.:elines.
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
:lines align=center.:hp7.Spuren insgesamt:ehp7.:elines.
:p.Rechts oben neben der Ausschrift "Spuren" wird die Gesamtanzahl
der Spuren auf der CD angezeigt. Darunter k�nnen sich auch
Nicht-Audiotitel befinden, die vom CD Spieler nicht abgespielt
werden k�nnen.

.********************************************************************
:h3 res=14120 name=PANEL_IN_DISP_UPC.UPC
:i1 ID=INDEX_UPC.UPC
:i2 REFID=INDEX_CD.UPC (im Infofenster)
:lines align=center.:hp7.UPC der CD:ehp7.:elines.
:p.Die :link reftype=fn refid=upc.UPC:elink. besteht aus 16
Dezimalziffern.

.********************************************************************
:h3 res=14121 name=PANEL_IN_DISP_MMPMID.MMPM ID
:i2 REFID=INDEX_ID.von MMPM
:i2 REFID=INDEX_CD.ID von MMPM (im Infofenster)
:lines align=center.:hp7.MMPM ID der CD:ehp7.:elines.
:p.Die Multimediaerweiterung von OS/2 vergibt an jede Audio CD eine ID.
Diese ID besteht aus 16 Hexdezimalziffern.
:note.
Da diese ID nicht unbedingt eindeutig ist, wird sie vom CD Spieler nicht
verwendet.

.********************************************************************
:h3 res=14122 name=PANEL_IN_DISP_INTERNALID.Interne ID
:i2 REFID=INDEX_ID.interne
:i2 REFID=INDEX_CD.interne ID (im Infofenster)
:lines align=center.:hp7.Interne ID der CD:ehp7.:elines.
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
:lines align=center.:hp7.Spurnummer:ehp7.:elines.
:p.Die Spurnummer der angezeigten Spur.
:note.
Die Spuren auf einer CD werden von 1 an fortlaufend durchnummeriert. Eine
CD kann maximal 99 Spuren enthalten.

.********************************************************************
:h3 res=14131 name=PANEL_IN_DISP_AUDIOTRACK.Audiospur
:i1 ID=INDEX_AUDIOTRACK.Audiospur
:i2 REFID=INDEX_TRACK.Audiospur (im Infofenster)
:lines align=center.:hp7.Audiospur:ehp7.:elines.
:p.Diese Box ist bei Spuren, die Audioinformationen enthalten
angekreuzt. Nur diese Spuren k�nnen vom CD Spieler abgespielt werden.

.********************************************************************
:h3 res=14132 name=PANEL_IN_DISP_COPYALLOWED.Kopieren erlaubt
:i1 ID=INDEX_COPY.Kopieren erlaubt
:i2 REFID=INDEX_TRACK.Kopieren erlaubt (im Infofenster)
:lines align=center.:hp7.Kopieren der Spur erlaubt:ehp7.:elines.
:p.Diese Box ist bei Spuren angekreuzt, deren digitale Informationen
ohne Verletzung des Urheberrechts kopiert werden d�rfen.

.********************************************************************
:h3 res=14133 name=PANEL_IN_DISP_PREEMPHASIS.Preemphasis
:i1 ID=INDEX_PREEMPHASIS.Preemphasis
:i2 REFID=INDEX_TRACK.Preemphasis (im Infofenster)
:lines align=center.:hp7.Preemphasis der Spur:ehp7.:elines.
:p.Diese Box ist nur bei Spuren angekreuzt, die mit
:link reftype=fn refid=preemphasis.Preemphasis:elink.
aufgenommen wurden.

.********************************************************************
:h3 res=14134 name=PANEL_IN_DISP_CHANNELS.Kan�le
:i2 REFID=INDEX_TRACK.Kan�le (im Infofenster)
:i2 REFID=INDEX_CHANNELS.Anzahl (im Infofenster)
:lines align=center.:hp7.Kan�le der Spur:ehp7.:elines.
:p.Dieser Wert gibt die Anzahl der Audiokan�le einer Spur an. Bei
Audiospuren sind dies normalerweise 2, bei anderen Spuren 0.

.********************************************************************
:h3 res=14135 name=PANEL_IN_DISP_STARTTRACK.Startposition der Spur
:i2 REFID=INDEX_TRACK.Startposition (im Infofenster)
:i2 REFID=INDEX_STARTPOSITION.der Spur (im Infofenster)
:lines align=center.:hp7.Startposition der Spur:ehp7.:elines.
:p.Dieser Wert gibt die Startposition der Spur auf der CD an.
:note.
Die Darstellung der Startposition l��t sich in den
:link reftype=hd res=15000.Einstellungen:elink. unter
:link reftype=hd res=15100.Zeitformat:elink. ver�ndern.

.********************************************************************
:h3 res=14136 name=PANEL_IN_DISP_LENGTHTRACK.L�nge der Spur
:i2 REFID=INDEX_TRACK.L�nge (im Infofenster)
:i2 REFID=INDEX_LENGTH.der Spur (im Infofenster)
:lines align=center.:hp7.L�nge der Spur:ehp7.:elines.
:p.Dieser Wert gibt die L�nge der Spur an.
:note.
Die Darstellung der L�nge l��t sich in den
:link reftype=hd res=15000.Einstellungen:elink. unter
:link reftype=hd res=15100.Zeitformat:elink. ver�ndern.

.********************************************************************
:h2 res=14200 name=PANEL_IN_CONTROL.Steuerung
:i2 REFID=INDEX_INFOWINDOW.Steuerung
:i2 REFID=INDEX_CONTROL.im Infofenster
:lines align=center.:hp7.Steuerung im Infofenster:ehp7.:elines.
:ul.
:li.:link reftype=hd res=14210.Spuranzeige verschieben:elink.
:li.:link reftype=hd res=14220.Infofenster verlassen:elink.
:eul.

.********************************************************************
:h3 res=14210 name=PANEL_IN_CTRL_SCROLLBAR.Spuranzeige verschieben
:i2 REFID=INDEX_TRACK.Anzeige verschieben (im Infofenster)
:lines align=center.:hp7.Spuranzeige verschieben:ehp7.:elines.
:p.Wenn die Informationen f�r alle Spuren nicht gleichzeitig angezeigt
werden k�nnen, k�nnen Sie mit dem Schiebebalken rechts neben den
Spurinformationen den Bereich der sichtbaren Spuren verschieben.

.********************************************************************
:h3 res=14220 name=PANEL_IN_CTRL_QUIT.Infofenster verlassen
:i2 REFID=INDEX_INFOWINDOW.verlassen
:lines align=center.:hp7.Infofenster verlassen:ehp7.:elines.
:p.Mit diesem Befehl verlassen Sie das Infofenster.
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit dem Knopf :hp7.V:ehp7.:hp2.erlassen:ehp2.
:li.Mit der :link reftype=hd res=14300.Taste:elink. :hp2.Eingabe:ehp2.
:li.Mit der :link reftype=hd res=14300.Taste:elink. :hp2.Abbrechen:ehp2.
:li.Mit der :link reftype=hd res=14300.Tastenkombination:elink. :hp2.Strg+Q:ehp2.
:eul.

.********************************************************************
:h2 res=14300 name=PANEL_IN_KEYBOARD.Tastatur- und Mausbefehle
:i2 REFID=INDEX_INFOWINDOW.Tastatur- und Mausbefehle
:i2 REFID=INDEX_KEYBOARD.Befehle im Infofenster
:i2 REFID=INDEX_MOUSE.Befehle im Infofenster
:lines align=center.:hp7.Tastaturbefehle im Infofenster:ehp7.:elines.
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
:lines align=center.:hp7.Men�befehle im Infofenster:ehp7.:elines.
:p.Im Infofenster sind keine besonderen Men�befehle definiert.

.********************************************************************
.********************************************************************
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

.********************************************************************
.********************************************************************
:h1 res=16000 name=PANEL_ERRORS.Fehlermeldungen
:i1 ID=INDEX_ERRORS.Fehlermeldungen

:h4 res=16001.
:p.:hp8.Fehler: Die Positionskontrolle kann nicht aktiviert werden.:ehp8.
.br
Dies ist ein fataler Fehler. Der CD Spieler wird beendet.

:h4 res=16002.
:p.:hp8.Fehler: Das Inhaltsverzeichnis der CD kann nicht gelesen werden.:ehp8.
.br
Entweder die CD ist fehlerhaft oder es handelt sich nicht um eine Audio CD.
Werfen Sie die CD aus.

:h4 res=16003.
:p.:hp8.Fehler: Der Auswurfbefehl konnte nicht durchgef�hrt werden.:ehp8.
.br
Versuchen Sie, die CD mit der Auswurftaste am CD-ROM Laufwerk auszuwerden.

:h4 res=16004.
:p.:hp8.Fehler: Der Ton konnte nicht aus- oder angestellt werden.:ehp8.
.br
Eventuell kann der Ton �ber den globalen Lautst�rkeregler
der Multimediaerweiterung von OS/2 oder �ber externe Lautst�rkeregler
an der Soundkarte und am CD-ROM Laufwerk eingestellt werden.

:h4 res=16005.
:p.:hp8.Fehler: Informationen �ber das CD-ROM Laufwerk k�nnen nicht ausgelesen werden.:ehp8.
.br
Dies ist ein fataler Fehler. Der CD Spieler wird beendet.

:h4 res=16006.
:p.:hp8.Fehler: Das CD-ROM Laufwerk kann nicht angesprochen werden.:ehp8.
.br
Dies ist ein fataler Fehler. Der CD Spieler wird beendet.

:h4 res=16007.
:p.:hp8.Fehler: Der PAUSE-Befehl konnte nicht durchgef�hrt werden.:ehp8.
.br
Die CD k�nnte defekt sein. Vermeiden Sie die Stelle auf der CD, an der der
PAUSE-Befehl nicht durchgef�hrt werden konnte.

:h4 res=16008.
:p.:hp8.Fehler: Der PLAY-Befehl konnte nicht durchgef�hrt werden.:ehp8.
.br
Die CD k�nnte defekt sein. Vermeiden Sie die Stelle auf der CD, an der der
PLAY-Befehl nicht durchgef�hrt werden konnte.

:h4 res=16009.
:p.:hp8.Fehler: Die momentane Position auf der CD kann nicht gelesen werden.:ehp8.
.br
Die CD k�nnte defekt sein. Vermeiden Sie die momentane Stelle auf der CD.

:h4 res=16010.
:p.:hp8.Fehler: Der Ausgabeanschlu� ist nicht verf�gbar.:ehp8.
.br
Der von Ihnen gew�hlte Ausgabeanschlu� ist in der momentanen
Konfiguration nicht verf�gbar.

:h4 res=16011.
:p.:hp8.Fehler: Der RESUME-Befehl konnte nicht durchgef�hrt werden.:ehp8.
.br
Die CD k�nnte defekt sein. Vermeiden Sie die Stelle auf der CD, an der der
RESUME-Befehl nicht durchgef�hrt werden konnte.

:h4 res=16012.
:p.:hp8.Fehler: Die Lautst�rke konnte nicht ver�ndert werden.:ehp8.
.br
Eventuell kann die Lautst�rke �ber den globalen Lautst�rkeregler
der Multimediaerweiterung von OS/2 oder �ber externe Lautst�rkeregler
an der Soundkarte und am CD-ROM Laufwerk eingestellt werden.

:h4 res=16013.
:p.:hp8.Fehler: Der STOP-Befehl konnte nicht durchgef�hrt werden.:ehp8.
.br
Dies ist ein fataler Fehler. Der CD Spieler wird beendet.

:h4 res=16014.
:p.:hp8.Fehler: Die Hilfedatei konnte nicht ge�ffnet werden. :ehp8.
.br
Die Hilfedatei 'CDPLAYER.HLP' mu� sich im selben Verzeichnis wie das CD Spieler
Programm 'CDPLAYER.EXE' befinden.

:h4 res=16015.
:p.:hp8.Fehler: Die INI-Datei konnte nicht ge�ffnet oder erstellt werden.:ehp8.
.br
Beim Versuch, die INI-Datei 'CDPLAYER.INI' zu �ffnen oder neu zu erstellen, ist
ein Dateifehler aufgetreten.
Dies ist ein fataler Fehler. Der CD Spieler wird beendet.

:h4 res=16016.
:p.:hp8.Fehler: Die INI-Datei konnte nicht aktualisiert werden. :ehp8.
.br
Beim Versuch, die INI-Datei 'CDPLAYER.INI' zu beschreiben, ist
ein Dateifehler aufgetreten.

:h4 res=16017.
:p.:hp8.Fehler: Es konnte kein Zeitgeber aktiviert werden.:ehp8.
.br
Dies ist ein fataler Fehler. Der CD Spieler wird beendet.

:h4 res=16018.
:p.:hp8.Fehler: Das CD-ROM Laufwerk kann keine Audio CDs abspielen.:ehp8.
.br
Dies ist ein fataler Fehler. Der CD Spieler wird beendet.

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
Alle Rechte vorbehalten.
:elines.

:p.:lines align=center.:hp7.Wichtige Hinweise:ehp7.:elines.
:p.Da absolute Fehlerfreiheit von Software niemals garantiert werden
kann, �bernimmt der Autor keinerlei Haftung f�r unmittelbare oder
Folgesch�den, die durch den Gebrauch dieses Programms entstehen.

:p.Alle Warenzeichen sind Warenzeichen der jeweiligen Inhaber und werden
ohne R�cksicht auf freie Verf�gbarkeit verwendet.

:p.:lines align=center.:hp7.Shareware:ehp7.:elines.

:p.In diesem Programm steckt viel Arbeit. Wer es nach einer
angemessenen Testphase von 30 Tagen weiterhin benutzt, mu�
deshalb einen Betrag an den Autor entrichten.

:p.:hp2.SHAREWARE:ehp2. ist :hp2.KEINE GRATIS-SOFTWARE:ehp2..
Sie k�nnen Shareware allerdings vor dem Kauf testen!
Es ist erlaubt, die Shareware-Version (nicht die Vollversion!) dieses
Programmes zu kopieren und weiterzugeben, falls
:ul.
:li.das Programm im Originalzustand kopiert wird
(komplett, unver�ndert, nicht installiert)
:li.die Kopiergeb�hr DM 15,- nicht �berschreitet
:eul.

:p.Der Autor beh�lt sich rechtliche Schritte bei Verletzung des Copyrights
oder der Lizenzbestimmungen vor.

:p.:lines align=center.:hp7.Registrierung:ehp7.:elines.

:p.Sollten Sie sich nach der Dauer von 30 Tagen daf�r entscheiden, da�
Sie den CD Spieler weiterhin benutzen m�chten, so sind Sie verpflichtet,
sich registrieren zu lassen.

:p.In der registrierten Version erscheint der Sharewarehinweis beim Start
und Ende des CD Spielers nicht mehr. Ansonsten ist die Shareware-Version
in keiner Weise gegen�ber der registrierten Version eingeschr�nkt.

:p.Die Registrierungsgeb�hr betr�gt DM 30,- inkl. Versand und MWSt.
F�r Zahlungen aus dem Ausland siehe ":link reftype=hd res=19000.REGISTER.TXT:elink.".

:p.Preise f�r mehr als 2 Lizenzen oder f�r H�ndler auf Anfrage!

:p.Die Registrierung geschieht durch Einsenden eines Verrechnungsschecks oder von
Bargeld an den Autor (Schecks werden fr�hestens am Versandtag
eingereicht)&colon.

:lines align=left.
Michael Bock
Winkler Str. 28
D-14193 Berlin
:elines.

:p.Sollten Sie den Betrag lieber �berweisen wollen&colon.

:lines align=left.
Michael Bock
Konto 0313312
Deutsche Bank Darmstadt BLZ 508 700 05
:elines.

:p.Der Versand kann (in Ausnahmef�llen) bis zu 6 Wochen dauern, bei Scheck-
oder Barzahlung fallen die Banklaufzeiten weg. Aus dem Ausland bitte nur
D-Mark-Euroschecks oder Bargeld (sonst Bankspesen von ca. 10,- bis 20,-
hinzuf�gen).

:p.Verwenden Sie bitte das beigef�gte Formular
":link reftype=hd res=19000.REGISTER.TXT:elink.", das
Sie ausdrucken und verschicken k�nnen.

:p.Der Autor ist im Fidonet unter 2&colon.2410/121.46 erreichbar.

:p.Die registrierte Version wird nicht in Form von Disketten verschickt.
Anstelle dessen erhalten Sie einen Registrierungscode und eine
Beschreibung, wie sie die Sharewareversion in eine registrierte Version
umwandeln k�nnen.

:p.:lines align=center.:hp7.Updates:ehp7.:elines.

:p.Updates sind f�r registrierte Benutzer bis auf weiteres kostenlos,
wenn das Update via Modem erfolgen kann. Andere registrierte Benutzer
zahlen lediglich die Geb�hr Ihres Shareware-H�ndlers (i.d.R. 5 DM).
:p.Falls das Programm stark erweitert werden sollte, kann der Update
DM 10 bis DM 20 kosten.
:p.01.12.1993

.********************************************************************
:h1 res=19000 name=PANEL_REGISTER.REGISTER.TXT
:lines align=center.:hp7.REGISTER.TXT:ehp7.:elines.
:p.Um die beiden Seiten auszudrucken, w�hlen Sie sie aus und benutzen
den Befehl :hp2.Drucken:ehp2. im Men� :hp2.Funktionen:ehp2. des Hilfefensters.
:ul.
:li.:link reftype=hd res=19100.Seite 1:elink.
:li.:link reftype=hd res=19200.Seite 2:elink.
:eul.

.********************************************************************
:h2 res=19100 name=PANEL_REG1.CD Spieler Bestellformular - Seite 1
:font facename=Courier size=10x10.
:fig.



    ���������������������������������������������Ŀ
    �                                             �
    �                                             �
    �                                             �
    �                                             �
    �         Michael Bock                        �
    �         Winkler Str. 28                     �
    �                                             �
    �         D-14193 Berlin                      �
    �                                             �
    �                                             �
    �                                             �
    �����������������������������������������������

    Absender&colon.     Name/Firma&colon.  _______________________________________
    ���������
                  Stra�e&colon.      _______________________________________

                  PLZ/Ort&colon.     _______________________________________

                  Telefon&colon.     _______________  Fax&colon.  ________________

                  Email&colon.       _______________________________________

                  Fidonet&colon.     _______________________________________

    Anzahl                                                          Betrag

    ____ CD Spieler f�r OS/2 Registrierung
         Deutschland&colon. DM 30,-  Europa&colon. DM 35,-  Welt&colon. DM 50,-   = DM _____,-

    Spenden �����������������������������������������������������> DM _____,-

                                                                �����������

                                                            SUMME DM _____,-
    Zahlung durch Vorkasse&colon.

    (  ) �berweisung auf das Konto 0313312 der Deutschen Bank Darmstadt
         (BLZ 508 700 05) am __. __. 199__ (bitte Datum eintragen)

    (  ) beiliegendes Bargeld/Scheck Nr. _____________  (Vorsicht Diebstahl)

    Der Versand kann (in Ausnahmef�llen) bis zu 6 Wochen dauern, bei Scheck-
    oder Barzahlung fallen die Banklaufzeiten weg. Aus dem Ausland bitte nur
    D-Mark-Euroschecks oder Bargeld (sonst Bankspesen von ca. 10,- bis 20,-
    hinzufuegen).

    Datum/Stempel/Unterschrift: _____________________________________________

:efig.
:font facename=default size=0x0.

.********************************************************************
:h2 res=19200 name=PANEL_REG2.CD Spieler Bestellformular - Seite 2
:font facename=Courier size=10x10.
:fig.



    Die weiteren Angaben sind freiwillig; bitte machen Sie sich trotzdem die
    Muehe und f�llen Sie das Formular komplett aus. Vielen Dank!

    Diese CD Spieler Version wurde kopiert&colon.
    ( ) aus einer Mailbox - Name/Tel&colon. _______________________________________
    ( ) von einem Shareware-H�ndler - Name/Ort: _____________________________
    ( ) _____________________________________________________________________

    CD Spieler wurde getestet aufgrund&colon.
    ( ) eines Testberichtes in&colon. _____________________________________________
    ( ) _____________________________________________________________________


    Sonstiges&colon. ______________________________________________________________

    _________________________________________________________________________


    Verbesserungsvorschl�ge/W�nsche&colon.

    _________________________________________________________________________

    _________________________________________________________________________

:efig.
:font facename=default size=0x0.
.********************************************************************

.********************************************************************
.********************************************************************
:h1 hide res=20000.Fu�noten

:fn id=frames.
:p.Frames sind die kleinste Zeiteinheit auf einer CD.
Jeder Frame ist eine 1/75 Sekunde lang.
:efn.

:fn id=upc.
:p.:hp4.UPC:ehp4. steht f�r "universal productcode". Nicht jede
CD hat eine :hp4.UPC:ehp4., und nicht jedes CD-ROM Laufwerk kann
die :hp4.UPC:ehp4. lesen.
:efn.

:fn id=preemphasis.
:p.:hp4.Preemphasis:ehp4. bedeutet eine besondere Vorverarbeitung
der Spur bei der Aufnahme.
:efn.

:fn id=librarymode.
:p.Wenn sich der
:link reftype=hd res=12000.Titeleditor:elink.
im :hp4.Bibliotheksmodus:ehp4. befindet, k�nnen
Sie sich die Titel und zus�tzlichen Informationen aller CD's in der
:link reftype=fn refid=library.CD Bibliothek:elink. betrachten und eine CD f�r die �nderung ausw�hlen.
:efn.

:fn id=library.
:p.Die :hp4.CD Bibliothek:ehp4. enth�lt Informationen und Titel aller CD's, die
bisher w�hrend des Betriebs des CD Spielers eingelegt waren. Sie ist
zusammen mit dem CD Spieler auf Ihrer Festplatte gespeichert.
:efn.

:fn id=changemode.
:p.Wenn sich der
:link reftype=hd res=12000.Titeleditor:elink.
im :hp4.�nderungsmodus:ehp4. befindet, k�nnen
Sie die Titel und zus�tzlichen Informationen einer ausgew�hlten
CD bearbeiten.
:efn.

.********************************************************************

.********************************************************************
:euserdoc.
