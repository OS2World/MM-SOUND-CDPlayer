.********************************************************************
:h1 res=14000 name=PANEL_INFO.Infofenster
:i2 REFID=INDEX_WINDOWS.Infofenster
:i2 REFID=INDEX_INFOWINDOW.öberblick
:i2 REFID=INDEX_CD.Infofenster anzeigen
:lines align=center.:hp7.Das Infofenster:ehp7.:elines.
:p.Das Infofenster gibt Ihnen genauere Informationen Åber eine CD.
:p.FÅr die eingelegte CD zeigen Sie das Infofenster mit dem Befehl
:link reftype=hd res=11233.Infofenster anzeigen:elink. im
:link reftype=hd res=11000.Hauptfenster:elink. auf.
Es ist aber auch mîglich, das Infofenster fÅr eine CD aus der
:link reftype=fn refid=library.CD Bibliothek:elink.
des CD Spielers aufzurufen, ohne die CD einzulegen. Dazu wird die CD im
:link reftype=hd res=12000.Titeleditor:elink.
ausgewÑhlt und das Infofenster mit dem Befehl
:link reftype=hd res=12261.Infofenster anzeigen:elink.
angezeigt. Auch im
:link reftype=hd res=13000.Programmeditor:elink.
ist es mîglich das Infofenster fÅr die CD, deren Programm gerade
bearbeitet wird, anzuzeigen. Benutzen Sie dazu den Befehl
:link reftype=hd res=13230.Infofenster anzeigen:elink. im
:link reftype=hd res=13000.Programmeditor:elink..

.********************************************************************
:h2 res=14100 name=PANEL_IN_DISPLAY.Anzeigeelemente
:i2 REFID=INDEX_INFOWINDOW.Anzeigeelemente
:i2 REFID=INDEX_DISPLAY.im Infofenster
:lines align=center.:hp7.Die Anzeigen im Infofenster:ehp7.:elines.
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
:h3 res=14110 name=PANEL_IN_DISP_LENGTHCD.GesamtlÑnge der CD
:i2 REFID=INDEX_TOTALLENGTH.der CD (im Infofenster)
:i2 REFID=INDEX_CD.GesamtlÑnge (im Infofenster)
:lines align=center.:hp7.GesamtlÑnge der CD:ehp7.:elines.
:p.Rechts oben neben der Ausschrift "LÑnge" wird die GesamtlÑnge der CD
angezeigt. Darunter kînnen sich auch Nicht-Audiotitel befinden,
die vom CD Spieler nicht abgespielt werden kînnen.
:note.
Die Darstellung der GesamtlÑnge lÑ·t sich in den
:link reftype=hd res=15000.Einstellungen:elink. unter
:link reftype=hd res=15100.Zeitformat:elink. verÑndern.

.********************************************************************
:h3 res=14111 name=PANEL_IN_DISP_STARTCD.Startposition der CD
:i2 REFID=INDEX_CD.Startposition (im Infofenster)
:i2 REFID=INDEX_STARTPOSITION.der CD (im Infofenster)
:lines align=center.:hp7.Startposition der CD:ehp7.:elines.
:p.Rechts oben neben der Ausschrift "Start" wird die Startposition
der ersten Audiospur auf der CD angezeigt. Der Bereich vor dieser Position
kann vom CD Spieler nicht abgespielt werden.
:note.
Die Darstellung der Startposition lÑ·t sich in den
:link reftype=hd res=15000.Einstellungen:elink. unter
:link reftype=hd res=15100.Zeitformat:elink. verÑndern.

.********************************************************************
:h3 res=14112 name=PANEL_IN_DISP_TRACKS.Spuren insgesamt
:i2 REFID=INDEX_TRACKS.Anzahl auf der CD (im Infofenster)
:i2 REFID=INDEX_CD.Spuren insgesamt (im Infofenster)
:lines align=center.:hp7.Spuren insgesamt:ehp7.:elines.
:p.Rechts oben neben der Ausschrift "Spuren" wird die Gesamtanzahl
der Spuren auf der CD angezeigt. Darunter kînnen sich auch
Nicht-Audiotitel befinden, die vom CD Spieler nicht abgespielt
werden kînnen.

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
:p.Der CD Spieler erzeugt fÅr jede CD eine interne ID, die zur Verwaltung der
:link reftype=fn refid=library.CD Bibliothek:elink. verwendet wird, siehe auch
":link reftype=hd res=12000.Titeleditor:elink.".
:note.
Diese ID ist fÅr jede CD eindeutig. Nur zwei CD's, fÅr die die im
:link reftype=hd res=14000.Infofenster:elink.
angezeigten Informationen vollkommen identisch sind, bekommen auch dieselbe ID.
In diesem (allerdings sehr unwahrscheinlichen) Fall ist es fÅr den CD
Spieler nicht mîglich, die beiden CD's zu unterscheiden.

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
angekreuzt. Nur diese Spuren kînnen vom CD Spieler abgespielt werden.

.********************************************************************
:h3 res=14132 name=PANEL_IN_DISP_COPYALLOWED.Kopieren erlaubt
:i1 ID=INDEX_COPY.Kopieren erlaubt
:i2 REFID=INDEX_TRACK.Kopieren erlaubt (im Infofenster)
:lines align=center.:hp7.Kopieren der Spur erlaubt:ehp7.:elines.
:p.Diese Box ist bei Spuren angekreuzt, deren digitale Informationen
ohne Verletzung des Urheberrechts kopiert werden dÅrfen.

.********************************************************************
:h3 res=14133 name=PANEL_IN_DISP_PREEMPHASIS.Preemphasis
:i1 ID=INDEX_PREEMPHASIS.Preemphasis
:i2 REFID=INDEX_TRACK.Preemphasis (im Infofenster)
:lines align=center.:hp7.Preemphasis der Spur:ehp7.:elines.
:p.Diese Box ist nur bei Spuren angekreuzt, die mit
:link reftype=fn refid=preemphasis.Preemphasis:elink.
aufgenommen wurden.

.********************************************************************
:h3 res=14134 name=PANEL_IN_DISP_CHANNELS.KanÑle
:i2 REFID=INDEX_TRACK.KanÑle (im Infofenster)
:i2 REFID=INDEX_CHANNELS.Anzahl (im Infofenster)
:lines align=center.:hp7.KanÑle der Spur:ehp7.:elines.
:p.Dieser Wert gibt die Anzahl der AudiokanÑle einer Spur an. Bei
Audiospuren sind dies normalerweise 2, bei anderen Spuren 0.

.********************************************************************
:h3 res=14135 name=PANEL_IN_DISP_STARTTRACK.Startposition der Spur
:i2 REFID=INDEX_TRACK.Startposition (im Infofenster)
:i2 REFID=INDEX_STARTPOSITION.der Spur (im Infofenster)
:lines align=center.:hp7.Startposition der Spur:ehp7.:elines.
:p.Dieser Wert gibt die Startposition der Spur auf der CD an.
:note.
Die Darstellung der Startposition lÑ·t sich in den
:link reftype=hd res=15000.Einstellungen:elink. unter
:link reftype=hd res=15100.Zeitformat:elink. verÑndern.

.********************************************************************
:h3 res=14136 name=PANEL_IN_DISP_LENGTHTRACK.LÑnge der Spur
:i2 REFID=INDEX_TRACK.LÑnge (im Infofenster)
:i2 REFID=INDEX_LENGTH.der Spur (im Infofenster)
:lines align=center.:hp7.LÑnge der Spur:ehp7.:elines.
:p.Dieser Wert gibt die LÑnge der Spur an.
:note.
Die Darstellung der LÑnge lÑ·t sich in den
:link reftype=hd res=15000.Einstellungen:elink. unter
:link reftype=hd res=15100.Zeitformat:elink. verÑndern.

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
:p.Wenn die Informationen fÅr alle Spuren nicht gleichzeitig angezeigt
werden kînnen, kînnen Sie mit dem Schiebebalken rechts neben den
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
:dd.FÅhrt den :link reftype=hd res=14220.Infofenster verlassen:elink. Befehl aus
:dt.:hp2.Eingabe:ehp2.
:dd.FÅhrt den :link reftype=hd res=14220.Infofenster verlassen:elink. Befehl aus
:dt.:hp2.Strg+Q:ehp2.
:dd.FÅhrt den :link reftype=hd res=14220.Infofenster verlassen:elink. Befehl aus
:edl.
:p.:lines align=center.:hp7.Mausbefehle im Infofenster:ehp7.:elines.
:p.Im Infofenster sind keine besonderen Mausbefehle definiert.

.********************************************************************
:h2 res=14400 name=PANEL_IN_MENUS.MenÅbefehle
:i2 REFID=INDEX_INFOWINDOW.MenÅbefehle
:i2 REFID=INDEX_MENU.im Infofenster
:lines align=center.:hp7.MenÅbefehle im Infofenster:ehp7.:elines.
:p.Im Infofenster sind keine besonderen MenÅbefehle definiert.

.********************************************************************
