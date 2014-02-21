.********************************************************************
:h1 res=13000 name=PANEL_PLAYLIST.Programmeditor
:i2 REFID=INDEX_WINDOWS.Programmeditor
:i2 REFID=INDEX_PROGRAMEDITOR.öberblick
:i2 REFID=INDEX_PROGRAM.Editor
:lines align=center.:hp7.Der Programmeditor:ehp7.:elines.
:p.Der Programmeditor dient dazu, die Reihenfolge der abzuspielenden
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
Diese Bedingungen werden vom Programmeditor automatisch Åberwacht.
:p.Der Programmeditor kann vom
:link reftype=hd res=11000.Hauptfenster:elink.
aus mit dem Befehl
:link reftype=hd res=11231.Programmeditor starten:elink.
fÅr die eingelegte CD aufgerufen werden. Das vom CD Spieler verwendete
Programm, siehe
":link reftype=hd res=11120.Programmanzeige im Hauptfenster:elink.",
wird aber erst geÑndert, wenn im Programmeditor der Befehl
:link reftype=hd res=13231.Programm speichern:elink.
ausgefÅhrt wird.
.br
Es ist aber auch mîglich, das Programm einer CD aus der
:link reftype=fn refid=library.CD Bibliothek:elink.
des CD Spielers zu Ñndern, ohne die CD einzulegen. Dazu wird die CD im
:link reftype=hd res=12000.Titeleditor:elink.
ausgewÑhlt und der Programmeditor mit dem Befehl
:link reftype=hd res=12262.Programm bearbeiten:elink.
gestartet.
:p.Mit den
:link reftype=hd res=13100.Anzeigeelementen des Programmeditors:elink.
kann man sich einen öberblick Åber die vorhandenen
:link reftype=hd res=13120.Titel auf der CD:elink.
und das
:link reftype=hd res=13140.momentane gewÑhlte Programm:elink.
verschaffen.
.br
Mit der
:link reftype=hd res=13200.Steuerung des Programmeditors:elink.
ist es mîglich, das Programm auf vielfÑltige Art zu verÑndern.

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
:p.In dem Kasten "CD" wird die GesamtlÑnge der CD und die
Gesamtanzahl von Titeln auf der CD angezeigt. Darunter kînnen
sich auch Nicht-Audiotitel befinden, die nicht ins Programm
Åbernommen werden kînnen.
:note.
Die Darstellung der GesamtlÑnge lÑ·t sich in den
:link reftype=hd res=15000.Einstellungen:elink. unter
:link reftype=hd res=15100.Zeitformat:elink. Ñndern.

.********************************************************************
:h3 res=13120 name=PANEL_PE_DISP_CDSELECT.Titel auf der CD
:i2 REFID=INDEX_TITLE.auf der CD ausgewÑhlt (im Programmeditor)
:lines align=center.:hp7.Titel auf der CD:ehp7.:elines.
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
:h3 res=13130 name=PANEL_PE_DISP_PROGRAM.Programmanzeige
:i2 REFID=INDEX_TOTALLENGTH.des Programms (im Programmeditor)
:i2 REFID=INDEX_TRACKS.Anzahl im Programm (im Programmeditor)
:lines align=center.:hp7.Programmanzeige:ehp7.:elines.
:p.In dem Kasten "Programm" wird die GesamtlÑnge des momentanen Programms
und die Gesamtanzahl von Titeln im Programm angezeigt.
:note.
Die Darstellung der GesamtlÑnge lÑ·t sich in den
:link reftype=hd res=15000.Einstellungen:elink. unter
:link reftype=hd res=15100.Zeitformat:elink. Ñndern.

.********************************************************************
:h3 res=13140 name=PANEL_PE_DISP_PROGRAMSELECT.Titel im Programm
:i2 REFID=INDEX_TITLE.aus dem Programm ausgewÑhlt (im Programmeditor)
:i2 REFID=INDEX_PROGRAM.ausgewÑhlte Titel (im Programmeditor)
:lines align=center.:hp7.Titel im Programm:ehp7.:elines.
:p.In der rechten Auswahlliste werden alle Titel im Programm angezeigt.
:p.In dieser Auswahlliste kînnen auch Titel zum Entfernen aus dem Programm
ausgewÑhlt werden, siehe
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
:li.:link reftype=hd res=13240.Titel am Anfang einfÅgen:elink.
:li.:link reftype=hd res=13241.Titel einfÅgen:elink.
:li.:link reftype=hd res=13242.Titel am Ende einfÅegen:elink.
:li.:link reftype=hd res=13243.Titel entfernen:elink.
:li.:link reftype=hd res=13250.Programm mischen:elink.
:li.:link reftype=hd res=13251.Programm umdrehen:elink.
:li.:link reftype=hd res=13252.Standardprogramm wÑhlen:elink.
:eul.

.********************************************************************
:h3 res=13210 name=PANEL_PE_CTRL_CDSELECT.Titelauswahl auf der CD
:i2 REFID=INDEX_TITLE.auf der CD auswÑhlen (im Programmeditor)
:lines align=center.:hp7.Titelauswahl auf der CD:ehp7.:elines.
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
:h3 res=13220 name=PANEL_PE_CTRL_PROGRAMSELECT.Titelauswahl im Programm
:i2 REFID=INDEX_TITLE.aus dem Programm ausgewÑhlen (im Programmeditor)
:i2 REFID=INDEX_PROGRAM.Titel auswÑhlen (im Programmeditor)
:lines align=center.:hp7.Titelauswahl im Programm:ehp7.:elines.
:p.In der rechten Auswahlliste kînnen Titel im Programm ausgewÑhlt
werden, um sie aus dem Programm zu entfernen, siehe
":link reftype=hd res=13243.Titel entfernen:elink.". Au·erdem bestimmt
der erste ausgewÑhlte Titel die Stelle, an der neue Titel mit dem Befehl
:link reftype=hd res=13241.Titel einfÅgen:elink. eingefÅgt werden.
:note.
Das Aussehen dieser Auswahlliste beim EinfÅgen oder Lîschen von Titeln
kann unter
:link reftype=hd res=15000.Einstellungen:elink.
:link reftype=hd res=15200.Animation:elink.
mit der Einstellung
:link reftype=hd res=15230.Listenanimation:elink.
beeinflu·t werden.


.********************************************************************
:h3 res=13230 name=PANEL_PE_CTRL_INFO.Infofenster anzeigen
:i2 REFID=INDEX_INFOWINDOW.anzeigen (im Programmeditor)
:lines align=center.:hp7.Befehl&colon. Infofenster anzeigen:ehp7.:elines.
:p.Dieser Befehl zeigt das
:link reftype=hd res=14000.Infofenster:elink.
fÅr die CD an, deren Programm bearbeitet wird.
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit dem Knopf :hp7.I:ehp7.:hp2.nfo:ehp2.
:li.Mit der :link reftype=hd res=13300.Tastenkombination:elink. :hp2.Strg+I:ehp2.
:eul.

.********************************************************************
:h3 res=13231 name=PANEL_PE_CTRL_SAVE.Programm speichern
:i2 REFID=INDEX_PROGRAM.speichern (im Programmeditor)
:lines align=center.:hp7.Befehl&colon. Programm speichern:ehp7.:elines.
:p.Mit diesem Befehl wird das Programm fÅr die CD gespeichert. Wenn es sich
um die momentan eingelegte CD handelt, so Ñndert sich auch das Programm im
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
:h3 res=13240 name=PANEL_PE_CTRL_INSERTBEGIN.Titel am Anfang einfÅgen
:i2 REFID=INDEX_PROGRAM.Titel am Anfang einfÅgen (im Programmeditor)
:i2 REFID=INDEX_TITLE.am Anfang des Programm einfÅgen (im Programmeditor)
:lines align=center.:hp7.Befehl&colon. Titel am Anfang einfÅgen:ehp7.:elines.
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
:h3 res=13241 name=PANEL_PE_CTRL_INSERT.Titel einfÅgen
:i2 REFID=INDEX_PROGRAM.Titel einfÅgen (im Programmeditor)
:i2 REFID=INDEX_TITLE.in das Programm einfÅgen (im Programmeditor)
:lines align=center.:hp7.Befehl&colon. Titel einfÅgen:ehp7.:elines.
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
:h3 res=13242 name=PANEL_PE_CTRL_INSERTEND.Titel am Ende einfÅgen
:i2 REFID=INDEX_PROGRAM.Titel am Ende einfÅgen (im Programmeditor)
:i2 REFID=INDEX_TITLE.am Ende des Programm einfÅgen (im Programmeditor)
:lines align=center.:hp7.Befehl&colon. Titel am Ende einfÅgen:ehp7.:elines.
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
:h3 res=13243 name=PANEL_PE_CTRL_DELETE.Titel entfernen
:i2 REFID=INDEX_PROGRAM.Titel entfernen (im Programmeditor)
:i2 REFID=INDEX_TITLE.aus dem Programm entfernen (im Programmeditor)
:lines align=center.:hp7.Befehl&colon. Titel entfernen:ehp7.:elines.
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
:h3 res=13250 name=PANEL_PE_CTRL_SHUFFLE.Programm mischen
:i2 REFID=INDEX_PROGRAM.mischen (im Programmeditor)
:lines align=center.:hp7.Befehl&colon. Programm mischen:ehp7.:elines.
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
:h3 res=13251 name=PANEL_PE_CTRL_REVERSE.Programm umdrehen
:i2 REFID=INDEX_PROGRAM.umdrehen (im Programmeditor)
:lines align=center.:hp7.Befehl&colon. Program umdrehen:ehp7.:elines.
:p.Dieser Befehl dreht die Reihenfolge der Titel im Programm um.
:link reftype=hd res=13130.GesamtlÑnge und Anzahl der Titel:elink.
werden dadurch nicht verÑndert.
:p.Dieser Befehl kann auf folgende Arten gegeben werden&colon.
:ul.
:li.Mit dem Knopf :hp7.U:ehp7.:hp2.mdrehen:ehp2.
:li.Mit der :link reftype=hd res=13300.Tastenkombination:elink. :hp2.Strg+R:ehp2.
:eul.

.********************************************************************
:h3 res=13252 name=PANEL_PE_CTRL_STANDARD.Standardprogramm wÑhlen
:i2 REFID=INDEX_PROGRAM.Standardprogramm (im Programmeditor)
:lines align=center.:hp7.Befehl&colon. Standardprogramm wÑhlen:ehp7.:elines.
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
:h2 res=13300 name=PANEL_PE_KEYBOARD.Tastatur- und Mausbefehle
:i2 REFID=INDEX_PROGRAMEDITOR.Tastatur- und Mausbefehle
:i2 REFID=INDEX_KEYBOARD.Befehle im Programmeditor
:i2 REFID=INDEX_MOUSE.Befehle im Programmeditor
:lines align=center.:hp7.Tastaturbefehle im Programmeditor:ehp7.:elines.
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
:dd.FÅhrt den :link reftype=hd res=13232.Programmeditor verlassen:elink. Befehl aus
:dt.:hp2.Strg+R:ehp2.
:dd.FÅhrt den :link reftype=hd res=13251.Program umdrehen:elink. Befehl aus
:dt.:hp2.Strg+S:ehp2.
:dd.FÅhrt den :link reftype=hd res=13231.Program speichern:elink. Befehl aus
:dt.:hp2.Strg+T:ehp2.
:dd.FÅhrt den :link reftype=hd res=13252.Standardprogramm wÑhlen:elink. Befehl aus
:dt.:hp2.Strg+U:ehp2.
:dd.FÅhrt den :link reftype=hd res=13250.Programm mischen:elink. Befehl aus
:edl.

:p.:lines align=center.:hp7.Mausbefehle im Programmeditor:ehp7.:elines.
:p.Im Programmeditor sind keine besonderen MenÅbefehle definiert.

.********************************************************************
:h2 res=13400 name=PANEL_PE_MENUS.MenÅbefehle
:i2 REFID=INDEX_PROGRAMEDITOR.MenÅbefehle
:i2 REFID=INDEX_MENU.im Programmeditor
:lines align=center.:hp7.MenÅbefehle im Programmeditor:ehp7.:elines.
:p.Im Programmeditor sind keine besonderen MenÅbefehle definiert.

.********************************************************************

