.********************************************************************
:h1 res=11000 name=PANEL_MAINWINDOW.Hauptfenster
:i2 REFID=INDEX_WINDOWS.Hauptfenster
:i2 REFID=INDEX_MAINWINDOW.šberblick
:lines align=center.:hp7.Das Hauptfenster des CD Spielers:ehp7.:elines.
:p.Das Hauptfenster enthalt mehrere
:link reftype=hd res=11100.Anzeigen:elink., die ber den Status des
CD Spielers, die eingelegte CD und das ausgew„hlte Programm informieren.
.br
Auáerdem enth„lt es alle zur Steuerung des CD Spielers notwendigen
:link reftype=hd res=11200.Kontrollelemente:elink.,
sowie Kn”pfe um
:link reftype=hd res=12000.Titeleditor:elink.,
:link reftype=hd res=13000.Programmeditor:elink.,
:link reftype=hd res=15000.Einstellungen:elink. und das
:link reftype=hd res=14000.Infofenster:elink.
aufzurufen.
:p.Darber hinaus k”nnen die meisten Befehle auch ber
:link reftype=hd res=11300.Tastatur:elink.- und
:link reftype=hd res=11400.Menbefehle:elink.
gegeben werden.

.********************************************************************
:h2 res=11100 name=PANEL_MW_DISPLAY.Anzeigeelemente
:i2 REFID=INDEX_MAINWINDOW.Anzeigeelemente
:i2 REFID=INDEX_DISPLAY.im Hauptfenster
:lines align=center.:hp7.Anzeigen im Hauptfenster:ehp7.:elines.
:ul.
:li.:link reftype=hd res=11110.Zeitanzeige:elink.
:li.:link reftype=hd res=11120.Programmanzeige:elink.
:li.:link reftype=hd res=11130.Lautst„rkeanzeige:elink.
:li.:link reftype=hd res=11150.Titelanzeige:elink.
:li.:link reftype=hd res=11140.Positionsanzeige:elink.
:li.:link reftype=hd res=11160.Wiedergabeanzeige:elink.
:eul.

.********************************************************************
:h3 res=11110 name=PANEL_MW_DISP_TIME.Zeitanzeige
:i2 REFID=INDEX_TRACKS.Anzeige im Hauptfenster
:i2 REFID=INDEX_TIME.Anzeige im Hauptfenster
:lines align=center.:hp7.Die Zeitanzeige:ehp7.:elines.
:artwork align=center name='DSPTIME.BMP'.
:p.Es gibt insgesamt fnf Anzeigen in diesem Bereich&colon.
:ul.
:li.:hp2.Die L„nge des Programms bis zur momentanen Position oben in
:color fc=black.schwarz:color fc=default.:ehp2.
:li.:hp2.Die L„nge des Programms ab der momentanen Position oben in
:color fc=red.rot:color fc=default.:ehp2.
:li.:hp2.Die L„nge der momentanen Spur bis zur momentanen Position in der Mitte in
:color fc=black.schwarz:color fc=default.:ehp2.
:li.:hp2.Die L„nge der momentanen Spur ab der momentanen Position in der Mitte in
:color fc=red.rot:color fc=default.:ehp2.
:li.:hp2.Die Spurnummer der momentanen Spur auf der CD unten in
:color fc=black.schwarz:color fc=default.:ehp2.
:eul.
:p.W„hrend der Wiedergabe werden die Zeitangaben mit der in den
:link reftype=hd res=15000.Einstellungen:elink. unter
:link reftype=hd res=15100.Zeitformat:elink. gew„hlten
:link reftype=hd res=15140.Aktualisierungsrate:elink. aktualisiert.
.br
Dort l„át sich auáerdem der
:link reftype=hd res=15130.Separator:elink. fr die Zeitzeige und eines
der Zeitformate
:link reftype=hd res=15110.Stunden/Minuten/Sekunden:elink. und
:link reftype=hd res=15120.Minuten/Sekunden/Frames:elink. w„hlen.


.********************************************************************
:h3 res=11120 name=PANEL_MW_DISP_PROGRAM.Programmanzeige
:i2 REFID=INDEX_PROGRAM.Anzeige im Hauptfenster
:lines align=center.:hp7.Die Programmanzeige:ehp7.:elines.
:artwork align=center name='DSPPROG.BMP'.
:p.Im Programmfenster werden die Spurnummern des gew„hlten Programms angezeigt.
Wenn nicht alle Spurnummern in den Ausschnitt passen, kann dieser mit dem Balken
rechts neben dem Ausschnitt verschoben werden. Die selektierte Spurnummer entspricht
:hp2.nicht:ehp2. der momentanen Spur, sondern kann von Ihnen
ver„ndert werden, um eine andere Spur im Programm auszuw„hlen, siehe
":link reftype=hd res=11210.Titelauswahl in der Programmanzeige:elink.".
.br
Das Programm selbst kann mit dem Programmeditor ver„ndert werden, siehe
":link reftype=hd res=11231.Programmeditor starten:elink." und
":link reftype=hd res=13000.Programmeditor:elink.".

.********************************************************************
:h3 res=11130 name=PANEL_MW_DISP_VOLUME.Lautst„rkeanzeige
:i2 REFID=INDEX_VOLUME.Anzeige im Hauptfenster
:lines align=center.:hp7.Die Lautst„rkeanzeige:ehp7.:elines.
:artwork align=center name='DSPVOL.BMP'.
:p.Aus der Lautst„rkeanzeige kann man die momentane Lautst„rke der beiden
Kan„le an der Position der Schieber ablesen. Steht ein Schieber ganz
oben, so ist Lautst„rke des entsprechenden Kanals maximal, steht er
ganz unten, ist sie minimal. Mit den Schiebern l„át sich die Lautst„rke
auch ver„ndern, siehe
":link reftype=hd res=11220.Lautst„rke links einstellen:elink." und
":link reftype=hd res=11221.Lautst„rke rechts einstellen:elink.".
:p.An den Symbol auf dem Knopf unten rechts kann man erkennen, ob der Ton
aus- oder eingestellt ist. In der obigen Anzeige ist der Ton eingestellt,
bei ausgestellten Ton „ndert sich der Knopf zu diesem Symbol&colon.
:artwork runin name='BTNMUTE1.BMP'., siehe auch
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
Alle Titel k”nnen angezeigt werden, wenn der
nach unten zeigende Pfeil rechts neben dem momentanen Titel mit der
Maus angeklickt wird.
.br
So kann auch ein neuer Titel fr die Wiedergabe ausgew„hlt werden, siehe
":link reftype=hd res=11240.Titel nach Namen w„hlen:elink.".

:p.Der Titel der eingelegten CD wird in der Titelleiste des Hauptfensters
nach dem Text "CD Spieler" angezeigt. Dieser Text wird auch in der globalen
Fensterliste von OS/2 verwendet. Wenn die CD keinen Titel hat
oder keine Audio CD eingelegt, erscheint in der Titelleiste&colon.
:dl break=all tsize=5.
:dt.:hp2.CD Spieler - kein CD-ROM Laufwerk:ehp2.
:dd.Ihr Computer verfgt ber kein audiof„higes CD-ROM Laufwerk.
:dt.:hp2.CD Spieler - keine CD:ehp2.
:dd.Es ist keine CD eingelegt.
:dt.:hp2.CD Spieler - keine Audio CD:ehp2.
:dd.Die eingelegte CD enth„lt keine Audiospuren.
:dt.:hp2.CD Spieler - ohne Namen:ehp2.
:dd.Die eingelegte Audio CD hat keinen Namen.
:edl.

:note.
Wenn Sie den CD Spieler ber ein Programmobjekt gestartet haben, erscheint
der Name des Programmobjekts vor dem Text "CD Spieler - ..." in der globalen
Fensterliste.

.********************************************************************
:h3 res=11140 name=PANEL_MW_DISP_POSITION.Positionsanzeige
:i2 REFID=INDEX_POSITION.Anzeige im Hauptfenster
:lines align=center.:hp7.Die Positionsanzeige:ehp7.:elines.
:artwork align=center name='DSPSLIDE.BMP'.
:p.Die kleinen Markierungen oberhalb der Positionsanzeige stellen die
Startposition der einzelnen Titel im Programm dar. šber den Markierungen
wird die Spurnummer des jeweiligen Titels angezeigt. Der Schieber steht
immer an der momentanen Position. Es ist auch m”glich mit dem Schieber
die Position direkt zu ver„ndern, siehe
":link reftype=hd res=11250.Position einstellen:elink.".

.********************************************************************
:h3 res=11160 name=PANEL_MW_DISP_CONTROLS.Wiedergabeanzeige
:i2 REFID=INDEX_CDCONTROL.Anzeige im Hauptfenster
:lines align=center.:hp7.Die Wiedergabeanzeige:ehp7.:elines.
:p.Der Status des CD Spielers l„át sich an den beiden Kn”pfen
:artwork runin name='BTNPLAY.BMP'. und
:artwork runin name='BTNPAUSE.BMP'. ablesen.
:ul.
:li.Sind beide Kn”pfe nicht gedrckt (wie hier dargestellt), so
ist die Wiedergabe abgebrochen.
:li.Wenn nur der
:artwork runin name='BTNPLAY.BMP'. Knopf
gedrckt ist, l„uft die Wiedergabe. Wenn die
:link reftype=hd res=15200.Animation:elink. angestellt ist,
wandert der Pfeil auf dem Knopf von links nach rechts.
Geschwindigkeit und Status der
:link reftype=hd res=15200.Animation:elink. lassen sich in den
:link reftype=hd res=15000.Einstellungen:elink. unter
:link reftype=hd res=15200.Animation:elink. mit
:link reftype=hd res=15210.Wiedergabeanimation:elink. und
:link reftype=hd res=15220.Animationsrate:elink. „ndern.
:li.Wenn zus„tzlich noch der
:artwork runin name='BTNPAUSE.BMP'. Knopf
gedrckt ist, ist die Wiedergabe unterbrochen.
Auch die
:link reftype=hd res=15200.Animation:elink.
ist dann unterbrochen.
:eul.
:p.Beide Kn”pfe lassen sich auch dazu verwenden, die Wiedergabe zu
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
:li.:link reftype=hd res=11220.Lautst„rke links einstellen:elink.
:li.:link reftype=hd res=11221.Lautst„rke rechts einstellen:elink.
:li.:link reftype=hd res=11222.Kan„le unabh„ngig einstellen:elink.
:li.:link reftype=hd res=11223.Kan„le vertauschen:elink.
:li.:link reftype=hd res=11224.Ton aus/an:elink.
:li.:link reftype=hd res=11230.Titeleditor starten:elink.
:li.:link reftype=hd res=11231.Programmeditor starten:elink.
:li.:link reftype=hd res=11232.Einstellungen aufrufen:elink.
:li.:link reftype=hd res=11233.Infofenster anzeigen:elink.
:li.:link reftype=hd res=11240.Titelauswahl nach Titel:elink.
:li.:link reftype=hd res=11250.Position einstellen:elink.
:li.:link reftype=hd res=11260.Titel zurck:elink.
:li.:link reftype=hd res=11261.Titel vorw„rts:elink.
:li.:link reftype=hd res=11262.Wiedergabe starten:elink.
:li.:link reftype=hd res=11263.Wiedergabe unterbrechen:elink.
:li.:link reftype=hd res=11264.Wiedergabe stoppen:elink.
:li.:link reftype=hd res=11265.CD auswerfen:elink.
:li.:link reftype=hd res=11266.Automatische Wiederholung einstellen:elink.
:eul.

.********************************************************************
:h3 res=11210 name=PANEL_MW_CTRL_PROGRAM.Titelauswahl in der Programmanzeige
:i2 REFID=INDEX_TITLE.aus dem Programm w„hlen
:i2 REFID=INDEX_PROGRAM.Titel ausw„hlen (im Hauptfenster)
:lines align=center.:hp7.Titelauswahl in der Programmanzeige:ehp7.:elines.
:artwork align=center name='DSPPROG.BMP'.
:p.Wenn Sie einen Titel in der Programmanzeige ausw„hlen, wird der CD Spieler an
die Startposition dieses Titels gesetzt.
Die Auswahl kann durch Doppelklick der linken Maustaste auf einen
Titel oder Drcken der Eingabetaste wenn ein Titel angew„hlt ist stattfinden.
.br
Befindet sich der CD Spieler im Wiedergabemodus, wird die Wiedergabe der CD
an der neuen Position unmittelbar fortgesetzt.
.br
Siehe auch ":link reftype=hd res=11120.Programmanzeige:elink.".

.********************************************************************
:h3 res=11220 name=PANEL_MW_CTRL_VOL_LEFT.Lautst„rke links einstellen
:i2 REFID=INDEX_VOLUME.links einstellen
:i2 REFID=INDEX_CHANNELS.Linken Kanal einstellen
:i2 REFID=INDEX_SOUND.links einstellen
:lines align=center.:hp7.Lautst„rke links einstellen:ehp7.:elines.
:artwork align=center name='BTNVOL.BMP'.
:p.Mit diesem Schieber kann die Lautst„rke des linken Kanals ge„ndert
werden. An der oberen Position des Schiebers hat der linke Kanal die
maximale Lautst„rke.
.br
Wenn die Option
:link reftype=hd res=11222.Kan„le unabh„ngig einstellen:elink.
nicht eingestellt ist, wird die Lautst„rke des rechten Kanals automatisch
auf das gleiche Niveau eingestellt.
.br
Ist in den
:link reftype=hd res=15000.Einstellungen:elink. die
:link reftype=hd res=15400.Speicherung:elink. der
:link reftype=hd res=15420.Lautst„rke:elink. angestellt, so
wird die Lautst„rke gespeichert und bei einem neuen Start
des CD Spielers auf das zuletzt eingestelle Niveau gesetzt.
.br
Siehe auch ":link reftype=hd res=11130.Lautst„rkeanzeige:elink.".

:note.
Es kann sein, daá Ihr CD-ROM Laufwerk die Ver„nderung der Lautst„rke
nicht untersttzt. In diesem Fall ist der Schalter deaktiviert.
.br
Eventuell kann die Lautst„rke aber ber den globalen Lautst„rkeregler
der Multimediaerweiterung von OS/2 oder ber externe Lautst„rkeregler
an der Soundkarte und am CD-ROM Laufwerk eingestellt werden.

.********************************************************************
:h3 res=11221 name=PANEL_MW_CTRL_VOL_RIGHT.Lautst„rke rechts einstellen
:i2 REFID=INDEX_VOLUME.rechts einstellen
:i2 REFID=INDEX_CHANNELS.Rechten Kanal einstellen
:i2 REFID=INDEX_SOUND.rechts einstellen
:lines align=center.:hp7.Lautst„rke rechts einstellen:ehp7.:elines.
:artwork align=center name='BTNVOL.BMP'.
:p.Mit diesem Schieber kann die Lautst„rke des rechten Kanals ge„ndert
werden. An der oberen Position des Schiebers hat der rechte Kanal die
maximale Lautst„rke.
.br
Wenn die Option
:link reftype=hd res=11222.Kan„le unabh„ngig einstellen:elink.
nicht eingestellt ist, wird die Lautst„rke des linken Kanals automatisch
auf das gleiche Niveau eingestellt.
.br
Ist in den
:link reftype=hd res=15000.Einstellungen:elink. die
:link reftype=hd res=15400.Speicherung:elink. der
:link reftype=hd res=15420.Lautst„rke:elink. angestellt, so
wird die Lautst„rke gespeichert und bei einem neuen Start
des CD Spielers auf das zuletzt eingestelle Niveau gesetzt.
.br
Siehe auch ":link reftype=hd res=11130.Lautst„rkeanzeige:elink.".

:note.
Es kann sein, daá Ihr CD-ROM Laufwerk die Ver„nderung der Lautst„rke
nicht untersttzt. In diesem Fall ist der Schalter deaktiviert.
.br
Eventuell kann die Lautst„rke aber ber den globalen Lautst„rkeregler
der Multimediaerweiterung von OS/2 oder ber externe Lautst„rkeregler
an der Soundkarte und am CD-ROM Laufwerk eingestellt werden.

.********************************************************************
:h3 res=11222 name=PANEL_MW_CTRL_VOL_IND.Kan„le unabh„ngig einstellen
:i2 REFID=INDEX_VOLUME.Kan„le unabh„ngig einstellen
:i2 REFID=INDEX_CHANNELS.unabh„ngig einstellen
:lines align=center.:hp7.Option&colon. Kan„le unabh„ngig einstellen:ehp7.:elines.
:p.Mit dem Schalter :hp2.Getrennt:ehp2. kann die Koppelung der Lautst„rke
der beiden Kan„le aufgehoben werden. Ist der Schalter an, kann die Lautst„rke
beider Kan„le getrennt eingestellt werden, siehe auch
":link reftype=hd res=11220.Lautst„rke links einstellen:elink." und
":link reftype=hd res=11221.Lautst„rke rechts einstellen:elink.".
.br
Auch wenn in den
:link reftype=hd res=15000.Einstellungen:elink. die
:link reftype=hd res=15400.Speicherung:elink. der
:link reftype=hd res=15420.Lautst„rke:elink. angestellt ist, wird
dieser Schalter nicht gespeichert. Die Stellung des Schalters beim
Start des CD Spielers ergibt sich aus der gespeicherten Lautst„rke
der beiden Kan„le. Ist fr beide Kan„le dieselbe Lautst„rke gespeichert
so der Schalter aus, anderenfalls an.
:p.Diese Option kann auf folgende Arten ge„ndert werden&colon.
:ul.
:li.Mit den Schalter :hp2.Getrennt:ehp2.
:eul.
:note.
Es kann sein, daá Ihr CD-ROM Laufwerk diese Option nicht untersttzt. In diesem Fall
ist der Schalter deaktiviert.


.********************************************************************
:h3 res=11223 name=PANEL_MW_CTRL_VOL_SWAP.Kan„le vertauschen
:i2 REFID=INDEX_VOLUME.Kan„le vertauschen
:i2 REFID=INDEX_CHANNELS.vertauschen
:lines align=center.:hp7.Option&colon. Kan„le vertauschen:ehp7.:elines.
:p.Mit dem Schalter :hp2.Tauschen:ehp2. k”nnen der linke und der rechte
Kanal bei der Ausgabe vertauscht werden.
:p.Diese Option kann auf folgende Arten ge„ndert werden&colon.
:ul.
:li.Mit den Schalter :hp2.Tauschen:ehp2.
:eul.
:note.
Es kann sein, daá Ihr CD-ROM Laufwerk diese Option nicht untersttzt. In diesem Fall
ist der Schalter deaktiviert.

.********************************************************************
:h3 res=11224 name=PANEL_MW_CTRL_VOL_MUTE.Ton aus/an
:i2 REFID=INDEX_VOLUME.Ton aus/an
:i2 REFID=INDEX_SOUND.ausstellen
:i2 REFID=INDEX_SOUND.anstellen
:lines align=center.:hp7.Option&colon. Ton aus/an:ehp7.:elines.
:p.Mit diesem Schalter k”nnen Sie den Ton kurzfristig aus- und wieder
anstellen, ohne die eingestellte Lautst„rke zu ver„ndern.
.br
Siehe auch ":link reftype=hd res=11130.Lautst„rkeanzeige:elink.".
:p.Diese Option kann auf folgende Arten ge„ndert werden&colon.
:ul.
:li.Mit den Kn”pfen :artwork runin name='BTNMUTE0.BMP'.
oder :artwork runin name='BTNMUTE1.BMP'.
:li.Mit der :link reftype=hd res=11300.Tastenkombination:elink. :hp2.Strg+M:ehp2.
:li.Mit dem Befehl :hp2.T:ehp2.:hp7.o:ehp7.:hp2.n aus:ehp2. bzw. 
:hp2.T:ehp2.:hp7.o:ehp7.:hp2.n an:ehp2. im
:link reftype=hd res=11420.Popupmen:elink.
:li.Mit dem Befehl :hp2.T:ehp2.:hp7.o:ehp7.:hp2.n aus:ehp2. bzw.
:hp2.T:ehp2.:hp7.o:ehp7.:hp2.n an:ehp2. im
:link reftype=hd res=11410.Systemmen:elink.
:eul.
:note.
Es kann sein, das Ihr CD-ROM Laufwerk diese Option nicht untersttzt. In diesem Fall
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
im :link reftype=fn refid=changemode.nderungsmodus:elink. fr die momentane CD. Ist keine
Audio CD eingelegt, startet der
:link reftype=hd res=12000.Titeleditor:elink.
im :link reftype=fn refid=librarymode.Bibliotheksmodus:elink..
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit dem Knopf :hp7.T:ehp7.:hp2.iteleditor...:ehp2.
:li.Mit dem Befehl :hp7.T:ehp7.:hp2.iteleditor...:ehp2. im
:link reftype=hd res=11420.Popupmen:elink.
:li.Mit dem Befehl :hp7.T:ehp7.:hp2.iteleditor...:ehp2. im Untermen
:hp7.F:ehp7.:hp2.enster:ehp2. des :link reftype=hd res=11410.Systemmens:elink.
:eul.

.********************************************************************
:h3 res=11231 name=PANEL_MW_CTRL_PROGRAMEDITOR.Programmeditor starten
:i2 REFID=INDEX_PROGRAMEDITOR.starten (im Hauptfenster)
:lines align=center.:hp7.Befehl&colon. Programmeditor starten:ehp7.:elines.
:p.Mit diesem Befehl wird der
:link reftype=hd res=13000.Programmeditor:elink.
fr das momentane Programm gestartet.
.br
Wenn keine Audio CD eingelegt ist, ist dieser Befehl deaktiviert. Sie k”nnen
aber den
:link reftype=hd res=13000.Programmeditor:elink. vom
:link reftype=hd res=12000.Titeleditor:elink. aus aufrufen,
um das Programm einer gespeicherten CD zu bearbeiten.
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit dem Knopf :hp7.P:ehp7.:hp2.rogrammeditor...:ehp2.
:li.Mit dem Befehl :hp7.P:ehp7.:hp2.rogrammeditor...:ehp2. im
:link reftype=hd res=11420.Popupmen:elink.
:li.Mit dem Befehl :hp7.P:ehp7.:hp2.rogrammeditor...:ehp2. im Untermen
:hp7.F:ehp7.:hp2.enster:ehp2. des :link reftype=hd res=11410.Systemmens:elink.
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
:link reftype=hd res=11420.Popupmen:elink.
:li.Mit dem Befehl :hp7.E:ehp7.:hp2.instellungen...:ehp2. im Untermen
:hp7.F:ehp7.:hp2.enster:ehp2. des :link reftype=hd res=11410.Systemmens:elink.
:eul.

.********************************************************************
:h3 res=11233 name=PANEL_MW_CTRL_INFO.Infofenster anzeigen
:i2 REFID=INDEX_INFOWINDOW.anzeigen (im Hauptfenster)
:lines align=center.:hp7.Befehl&colon. Infofenster anzeigen:ehp7.:elines.
:p.Dieser Befehl zeigt das
:link reftype=hd res=14000.Infofenster:elink.
fr die momentane eingelegte CD an.
.br
Wenn keine Audio CD eingelegt ist, ist dieser Befehl deaktiviert. Sie k”nnen
aber das
:link reftype=hd res=14000.Infofenster:elink. vom
:link reftype=hd res=12000.Titeleditor:elink. aus fr
eine gespeicherte CD anzeigen.
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit der :link reftype=hd res=11300.Tastenkombination:elink. :hp2.Strg+I:ehp2.
:li.Mit dem Befehl :hp7.I:ehp7.:hp2.nfofenster...:ehp2. im
:link reftype=hd res=11420.Popupmen:elink.
:li.Mit dem Befehl :hp7.I:ehp7.:hp2.nfofenster...:ehp2. im Untermen
:hp7.F:ehp7.:hp2.enster:ehp2. des :link reftype=hd res=11410.Systemmens:elink.
:eul.

.********************************************************************
:h3 res=11240 name=PANEL_MW_CTRL_TITLE.Titel nach Namen w„hlen
:i2 REFID=INDEX_TITLE.nach Namen w„hlen
:i2 REFID=INDEX_NAMES.fr Wiedergabe ausw„hlen
:lines align=center.:hp7.Titel nach Namen w„hlen:ehp7.:elines.
:p.Wenn Sie einen Titel in der Titelanzeige ausw„hlen, wird der CD Spieler an
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
:artwork align=center name='DSPSLIDE.BMP'.
:p.Sie k”nnen die Position im Programm genau einstellen, indem Sie den Schieber
auf die gewschte Stelle setzen.
.br
Befindet sich der CD Spieler im Wiedergabemodus, wird die Wiedergabe der CD
an der neuen Position unmittelbar fortgesetzt.
.br
Siehe auch ":link reftype=hd res=11140.Positionsanzeige:elink.".

.********************************************************************
:h3 res=11260 name=PANEL_MW_CTRL_BACKWARD.Titel zurck
:i1.Zurck
:i2 REFID=INDEX_TITLE.zurck
:i2 REFID=INDEX_CDCONTROL.Titel zurck
:lines align=center.:hp7.Befehl&colon. Titel zurck:ehp7.:elines.
:p.Wenn die Position im momentanen Titel ber dem in den
:link reftype=hd res=15000.Einstellungen:elink. unter
:link reftype=hd res=15300.Wiedergabe:elink. angegebenen
:link reftype=hd res=15330.Rcksprunglimit:elink. liegt, wird der CD Spieler
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
:li.Mit dem Befehl :hp7.Z:ehp7.:hp2.urck:ehp2. im
:link reftype=hd res=11420.Popupmen:elink.
:li.Mit dem Befehl :hp7.Z:ehp7.:hp2.urck:ehp2. im Untermen
:hp7.S:ehp7.:hp2.teuerung:ehp2. des :link reftype=hd res=11410.Systemmens:elink.
:eul.

.********************************************************************
:h3 res=11261 name=PANEL_MW_CTRL_FORWARD.Titel vorw„rts
:i1.Vorw„rts
:i2 REFID=INDEX_TITLE.vorw„rts
:i2 REFID=INDEX_CDCONTROL.Titel vorw„rts
:lines align=center.:hp7.Befehl&colon. Titel vorw„rts:ehp7.:elines.
:p.Dieser Befehl setzt den CD Spieler an den Start
des n„chsten Titels im Programm.
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
:li.Mit dem Befehl :hp7.V:ehp7.:hp2.orw„rts:ehp2. im
:link reftype=hd res=11420.Popupmen:elink.
:li.Mit dem Befehl :hp7.V:ehp7.:hp2.orw„rts:ehp2. im Untermen
:hp7.S:ehp7.:hp2.teuerung:ehp2. des :link reftype=hd res=11410.Systemmens:elink.
:eul.

.********************************************************************
:h3 res=11262 name=PANEL_MW_CTRL_PLAY.Wiedergabe starten
:isyn ROOT=start.Start
:i1 ROOTS='start'.Starten
:i2 REFID=INDEX_CDCONTROL.starten
:lines align=center.:hp7.Befehl&colon. Wiedergabe starten:ehp7.:elines.
:p.Dieser Befehl startet die Wiedergabe der CD an der momentanen Position.
.br
Die Wiedergabe l„uft bis zum Ende des eingestellten Programms. Wenn die Option
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
:link reftype=hd res=11420.Popupmen:elink.
:li.Mit dem Befehl :hp2.S:ehp2.:hp7.p:ehp7.:hp2.ielen:ehp2. im Untermen
:hp7.S:ehp7.:hp2.teuerung:ehp2. des :link reftype=hd res=11410.Systemmens:elink.
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
:li.Mit dem Knopf :artwork runin name='BTNPAUSE.BMP'.
:li.Mit der :link reftype=hd res=11300.Tastenkombination:elink. :hp2.Strg+A:ehp2.
:li.Mit dem Befehl :hp2.Pa:ehp2.:hp7.u:ehp7.:hp2.se:ehp2. im
:link reftype=hd res=11420.Popupmen:elink.
:li.Mit dem Befehl :hp2.Pa:ehp2.:hp7.u:ehp7.:hp2.se:ehp2. im Untermen
:hp7.S:ehp7.:hp2.teuerung:ehp2. des :link reftype=hd res=11410.Systemmens:elink.
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
:li.Mit dem Knopf :artwork runin name='BTNSTOP.BMP'.
:li.Mit der :link reftype=hd res=11300.Tastenkombination:elink. :hp2.Strg+S:ehp2.
:li.Mit dem Befehl :hp7.S:ehp7.:hp2.top:ehp2. im
:link reftype=hd res=11420.Popupmen:elink.
:li.Mit dem Befehl :hp7.S:ehp7.:hp2.top:ehp2. im Untermen
:hp7.S:ehp7.:hp2.teuerung:ehp2. des :link reftype=hd res=11410.Systemmens:elink.
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
:li.Mit dem Knopf :artwork runin name='BTNEJECT.BMP'.
:li.Mit der :link reftype=hd res=11300.Tastenkombination:elink. :hp2.Strg+E:ehp2.
:li.Mit dem Befehl :hp7.A:ehp7.:hp2.uswurf:ehp2. im
:link reftype=hd res=11420.Popupmen:elink.
:li.Mit dem Befehl :hp7.A:ehp7.:hp2.uswurf:ehp2. im Untermen
:hp7.S:ehp7.:hp2.teuerung:ehp2. des :link reftype=hd res=11410.Systemmens:elink.
:eul.
:note.
Es kann sein, daá Ihr CD-ROM Laufwerk diesen Befehl nicht untersttzt. In diesem Fall
sind der Befehlsknopf und die Menpunkte deaktiviert.

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
Wird der Knopf :artwork runin name='BTNAUTO1.BMP'. angezeigt, ist die
automatische Wiederholung aktiviert.
:p.Diese Option kann auf folgende Arten ge„ndert werden&colon.
:ul.
:li.Mit den Kn”pfen :artwork runin name='BTNAUTO0.BMP'. oder
:artwork runin name='BTNAUTO1.BMP'.
:li.Mit der :link reftype=hd res=11300.Tastenkombination:elink. :hp2.Strg+R:ehp2.
:li.Mit dem Befehl :hp2.Auto:ehp2.:hp7.w:ehp7.:hp2.iederholung:ehp2. im
:link reftype=hd res=11420.Popupmen:elink.
:li.Mit dem Befehl :hp2.Auto:ehp2.:hp7.w:ehp7.:hp2.iederholung:ehp2. im Untermen
:hp7.S:ehp7.:hp2.teuerung:ehp2. des :link reftype=hd res=11410.Systemmens:elink.
:eul.
:p.Diese Option kann auch in den
:link reftype=hd res=15000.Einstellungen:elink. unter
:link reftype=hd res=15300.Wiedergabe:elink. mit der Option
:link reftype=hd res=15310.Autowiederholung:elink. ge„ndert werden. In diesem Fall
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
:dd.Fhrt den :link reftype=hd res=11263.Wiedergabe unterbrechen:elink. Befehl aus
:dt.:hp2.Strg+B:ehp2.
:dd.Fhrt den :link reftype=hd res=11260.Titel zurck:elink. Befehl aus
:dt.:hp2.Strg+E:ehp2.
:dd.Fhrt den :link reftype=hd res=11265.CD auswerfen:elink. Befehl aus
:dt.:hp2.Strg+F:ehp2.
:dd.Fhrt den :link reftype=hd res=11261.Titel vorw„rts:elink. Befehl aus
:dt.:hp2.Strg+I:ehp2.
:dd.Fhrt den :link reftype=hd res=11233.Infofenster anzeigen:elink. Befehl aus
:dt.:hp2.Strg+M:ehp2.
:dd.Fhrt den :link reftype=hd res=11224.Ton aus/an:elink. Befehl aus
:dt.:hp2.Strg+P:ehp2.
:dd.Fhrt den :link reftype=hd res=11262.Wiedergabe starten:elink. Befehl aus
:dt.:hp2.Strg+R:ehp2.
:dd.Fhrt den :link reftype=hd res=11266.Autowiederholung einstellen:elink. Befehl aus
:dt.:hp2.Strg+S:ehp2.
:dd.Fhrt den :link reftype=hd res=11264.Wiedergabe stoppen:elink. Befehl aus
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
:dd.Setzt die Position eine 1/75 Sekunde zurck
:dt.:hp2.-:ehp2.
:dd.Setzt die Position eine 1/5 Sekunde zurck
:dt.:hp2.-:ehp2.
:dd.Setzt die Position eine Sekunde zurck
:dt.:hp2.Umsch+-:ehp2.
:dd.Setzt die Position um 10 Sekunden zurck
:dt.:hp2.Strg+-:ehp2.
:dd.Setzt die Position eine Minute zurck
:dt.:hp2.Umsch+Strg+-:ehp2.
:dd.Setzt die Position um 10 Minuten zurck
:dt.:hp2.Umsch+F10:ehp2.
:dd.Aktiviert das :link reftype=hd res=11420.Popupmen:elink.
:edl.

:p.:lines align=center.:hp7.Mausbefehle im Hauptfenster:ehp7.:elines.
:dl break=fit tsize=15.
:dt.:hp2.Klick der rechten Maustaste:ehp2.
:dd.Aktiviert das :link reftype=hd res=11420.Popupmen:elink.
:dt.:hp2.Klick der mittleren Maustaste:ehp2.
:dd.Startet oder unterbricht die Wiedergabe
:dt.:hp2.Taste Strg und Klick der mittleren Maustaste:ehp2.
:dd.Stoppt die Wiedergabe
:edl.

.********************************************************************
:h2 res=11400 name=PANEL_MW_MENUS.Menbefehle
:i2 REFID=INDEX_MAINWINDOW.Menbefehle
:i2 REFID=INDEX_MENU.im Hauptfenster
:lines align=center.:hp7.Menbefehle im Hauptfenster:ehp7.:elines.
:p.Die wichtigsten Befehle und Optionen im Hauptfenster k”nnen auch ber
das
:link reftype=hd res=11420.Popupmen:elink. und das erweiterte
:link reftype=hd res=11410.Systemmen:elink. gegeben bzw. eingestellt werden.
.br
Das
:link reftype=hd res=11420.Popupmen:elink. kann mit einfachem Klick der
rechten Maustaste an einer beliebigen Position im Hauptfenster oder ber
die Tastenkombination Umsch+F10 aufgerufen werden.

.********************************************************************
:h3 res=11420 name=PANEL_MW_MENU_POPUP.Popupmen
:i2 REFID=INDEX_POPUPMENU.im Hauptfenster
:lines align=center.:hp7.Das Popupmen im Hauptfenster:ehp7.:elines.
:dl break=fit tsize=15.
:dthd.:hp3.Menpunkt:ehp3.
:ddhd.:hp3.Befehl:ehp3.
:dt.:hp2.:ehp2.:hp7.Z:ehp7.:hp2.urck:ehp2.
:dd.Fhrt den :link reftype=hd res=11260.Titel zurck:elink. Befehl aus
:dt.:hp2.:ehp2.:hp7.V:ehp7.:hp2.orw„rts:ehp2.
:dd.Fhrt den :link reftype=hd res=11261.Titel vorw„rts:elink. Befehl aus
:dt.:hp2.S:ehp2.:hp7.p:ehp7.:hp2.ielen:ehp2.
:dd.Fhrt den :link reftype=hd res=11262.Wiedergabe starten:elink. Befehl aus
:dt.:hp2.Pa:ehp2.:hp7.u:ehp7.:hp2.se:ehp2.
:dd.Fhrt den :link reftype=hd res=11263.Wiedergabe unterbrechen:elink. Befehl aus
:dt.:hp2.:ehp2.:hp7.S:ehp7.:hp2.top:ehp2.
:dd.Fhrt den :link reftype=hd res=11264.Wiedergabe stoppen:elink. Befehl aus
:dt.:hp2.:ehp2.:hp7.A:ehp7.:hp2.uswurf:ehp2.
:dd.Fhrt den :link reftype=hd res=11265.CD auswerfen:elink. Befehl aus
:dt.:hp2.Auto:ehp2.:hp7.w:ehp7.:hp2.iederholung:ehp2.
:dd.Fhrt den :link reftype=hd res=11266.Autowiederholung einstellen:elink. Befehl aus
:dt.:hp2.T:ehp2.:hp7.o:ehp7.:hp2.n aus:ehp2.
:dd.Fhrt den :link reftype=hd res=11224.Ton aus:elink. Befehl aus
:dt.:hp2.T:ehp2.:hp7.o:ehp7.:hp2.n an:ehp2.
:dd.Fhrt den :link reftype=hd res=11224.Ton an:elink. Befehl aus
:dt.:hp2.:ehp2.:hp7.T:ehp7.:hp2.iteleditor...:ehp2.
:dd.Fhrt den :link reftype=hd res=11230.Titeleditor starten:elink. Befehl aus
:dt.:hp2.P:ehp2.:hp7.r:ehp7.:hp2.ogrammeditor...:ehp2.
:dd.Fhrt den :link reftype=hd res=11231.Programmeditor starten:elink. Befehl aus
:dt.:hp2.:ehp2.:hp7.E:ehp7.:hp2.instellungen...:ehp2.
:dd.Fhrt den :link reftype=hd res=11232.Einstellungen aufrufen:elink. Befehl aus
:dt.:hp2.:ehp2.:hp7.I:ehp7.:hp2.nfofenster...:ehp2.
:dd.Fhrt den :link reftype=hd res=11233.Infofenster anzeigen:elink. Befehl aus
:dt.:hp2.:ehp2.:hp7.H:ehp7.:hp2.ilfe:ehp2.
:dd.Zeigt das Hilfemen an.
:dt.:hp2.S:ehp2.:hp7.c:ehp7.:hp2.hliessen:ehp2.
:dd.Beendet das CD Spieler Programm.
:edl.

.********************************************************************
:h3 res=11410 name=PANEL_MW_MENU_SYS.Systemmen
:i2 REFID=INDEX_SYSMENU.im Hauptfenster
:lines align=center.:hp7.Das erweiterte Systemmen im Hauptfenster:ehp7.:elines.
:p.Zus„tzlich zu den normalen Menpunkten des Systemmens enth„lt das Systemmen des
Hauptfensters folgende Menpunkte:
:dl break=fit tsize=15.
:dthd.:hp3.Menpunkt:ehp3.
:ddhd.:hp3.Befehl/Untermen:ehp3.
:dt.:hp2.:ehp2.:hp7.S:ehp7.:hp2.teuerung:ehp2.
:dd.Untermen :hp2.Steuerung:ehp2. (s.u.)
:dt.:hp2.:ehp2.:hp7.F:ehp7.:hp2.enster:ehp2.
:dd.Untermen :hp2.Fenster:ehp2. (s.u.)
:dt.:hp2.T:ehp2.:hp7.o:ehp7.:hp2.n aus:ehp2.
:dd.Fhrt den :link reftype=hd res=11224.Ton aus:elink. Befehl aus
:dt.:hp2.T:ehp2.:hp7.o:ehp7.:hp2.n an:ehp2.
:dd.Fhrt den :link reftype=hd res=11224.Ton an:elink. Befehl aus
:dt.:hp2.:ehp2.:hp7.H:ehp7.:hp2.ilfe:ehp2.
:dd.Zeigt das Hilfemen an.
:edl.

:p.Untermen :hp2.Steuerung:ehp2.
:dl break=fit tsize=15.
:dthd.:hp3.Menpunkt:ehp3.
:ddhd.:hp3.Befehl:ehp3.
:dt.:hp2.:ehp2.:hp7.Z:ehp7.:hp2.urck:ehp2.
:dd.Fhrt den :link reftype=hd res=11260.Titel zurck:elink. Befehl aus
:dt.:hp2.:ehp2.:hp7.V:ehp7.:hp2.orw„rts:ehp2.
:dd.Fhrt den :link reftype=hd res=11261.Titel vorw„rts:elink. Befehl aus
:dt.:hp2.S:ehp2.:hp7.p:ehp7.:hp2.ielen:ehp2.
:dd.Fhrt den :link reftype=hd res=11262.Wiedergabe starten:elink. Befehl aus
:dt.:hp2.Pa:ehp2.:hp7.u:ehp7.:hp2.se:ehp2.
:dd.Fhrt den :link reftype=hd res=11263.Wiedergabe unterbrechen:elink. Befehl aus
:dt.:hp2.:ehp2.:hp7.S:ehp7.:hp2.top:ehp2.
:dd.Fhrt den :link reftype=hd res=11264.Wiedergabe stoppen:elink. Befehl aus
:dt.:hp2.:ehp2.:hp7.A:ehp7.:hp2.uswurf:ehp2.
:dd.Fhrt den :link reftype=hd res=11265.CD auswerfen:elink. Befehl aus
:dt.:hp2.Auto:ehp2.:hp7.w:ehp7.:hp2.iederholung:ehp2.
:dd.Fhrt den :link reftype=hd res=11266.Autowiederholung einstellen:elink. Befehl aus
:edl.

:p.Untermen :hp2.Fenster:ehp2.
:dl break=fit tsize=15.
:dthd.:hp3.Menpunkt:ehp3.
:ddhd.:hp3.Befehl:ehp3.
:dt.:hp2.:ehp2.:hp7.T:ehp7.:hp2.iteleditor...:ehp2.
:dd.Fhrt den :link reftype=hd res=11230.Titeleditor starten:elink. Befehl aus
:dt.:hp2.P:ehp2.:hp7.r:ehp7.:hp2.ogrammeditor...:ehp2.
:dd.Fhrt den :link reftype=hd res=11231.Programmeditor starten:elink. Befehl aus
:dt.:hp2.:ehp2.:hp7.E:ehp7.:hp2.instellungen...:ehp2.
:dd.Fhrt den :link reftype=hd res=11232.Einstellungen aufrufen:elink. Befehl aus
:dt.:hp2.:ehp2.:hp7.I:ehp7.:hp2.nfofenster...:ehp2.
:dd.Fhrt den :link reftype=hd res=11233.Infofenster anzeigen:elink. Befehl aus
:edl.
.********************************************************************

