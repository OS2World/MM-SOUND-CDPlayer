
    CDXTRACT & CDMERGE - Version 1.00 - (C) Michael Bock 1994

    Der Gebrauch dieser Programme ist nur in Verbindung mit dem "CD Spieler
    fÅr OS/2" zulÑssig. Alle EinschrÑnkungen bezÅglich des Gebrauchs der nicht
    registrierten Version des "CD Spielers fÅr OS/2" betreffen auch diese Pro-
    gramme.
    Es wird keine GewÑhrleistung fÅr die FunktionsfÑhigkeit und Fehlerfreiheit
    der Programme Åbernommen.

    öberblick

    Da die CDPLAYER.INI nicht nur die CD Bibliothek, sondern auch alle anderen
    Einstellungen sowie die (hoffentlich vorhandene :-) Registrierungsinforma-
    tion enthÑlt, kann diese Datei normalerweise nicht verwendet werden um die
    eigene CD Bibliothek mit anderen Benutzern des CD Spielers auszutauschen.
    Mit den beiden Rexx-Programmen CDXTRACT und CDMERGE ist es nun trotzdem
    mîglich, die eigene CD Bibliothek weiterzugeben und fremde CD Bibliotheken
    einzubinden.
    Dies ist allerdings nur eine vorlÑufige Lîsung, da die nÑchste Version des
    CD Spielers diese Mîglichkeit direkt bieten wird. Mit CDXTRACT erstellte
    CD Bibliotheken kînnen aber auch dann weiterhin benutzt werden.
    WICHTIG! Zur Benutzung der beiden Programme mu· die REXX-UnterstÅtzung von 
    OS/2 aktiviert sein.

    Installation

    Kopieren sie einfach die beiden Dateien CDXTRACT.CMD und CDMERGE.CMD in 
    das Verzeichnis ihres CD Spielers.

    CDXTRACT

    Mit CDXTRACT kann die CD Bibliothek aus der Datei CDPLAYER.INI extrahiert
    werden. Dabei wird eine neue Datei erstellt, die nur die CD Bibliothek
    enthÑlt, nicht aber den Åbrigen Inhalt der CDPLAYER.INI Datei.
    WARNUNG! Eine bereits vorhandene Datei wird dabei Åberschrieben.

    Programmaufruf:

    CDXTRACT <Extrahierte Datei> [Inidatei]
    Extrahierte Datei: Name der Datei, die die extrahierte CD Bibliothek
        aufnimmt. Dieser Parameter mu· angegeben werden.
        WARNUNG! Eine bereits vorhandene Datei dieses Namens wird vor der
        AusfÅhrung des Programms gelîscht.
    Inidatei: Name der Inidatei des CD Spielers. Wenn dieser Parameter
        nicht angegeben wird, nimmt CDXTRACT die Datei CDPLAYER.INI im
        momentanen Verzeichnis.

    Tip: leider sind die notwendigen Rexxroutinen ziemlich langsam. Um den
    Vorgang zu beschleunigen, empfiehlt es sich, die Zieldatei auf einer RAM-
    Disk anzulegen.

    CDMERGE

    Mit CDMERGE kann eine mit CDXTRACT erstellte CD Bibliothek in die Datei
    CDPLAYER.INI des CD Spielers Åbernommen werden.
    Es kann vorkommen das einzelne CDs der neuen CD Bibliothek sich auch schon
    in ihrer CD Bibliothek befinden. In diesem Fall fragt CDMERGE nach, ob sie
    den CD Eintrag Åberschreiben wollen. Wenn ja, werden alle in der externen
    CD Bibliothek vorhandenen Titel und Infos Åbernommen. EintrÑge, die in der
    externen CD Bibliothek nicht vorhanden sind, sich aber in ihrer CD Biblio-
    thek befinden, werden nicht(!) Åberschrieben. Wenn die externe Bibliothek
    z.B. nur die Titel 1-6 definiert, aber nicht die Titel 7-9 und Åberhaupt
    keine zus. Informationen, werden ihre Titel 7-9 und ihre zus. Informatio-
    nen beibehalten. Das gleiche gilt fÅr die gespeicherte Position und das
    gespeicherte Programm.

    Programmaufruf:

    CDMERGE <Extrahierte Datei> [Inidatei]
    Extrahierte Datei: Name der Datei, die die extrahierte CD Bibliothek
        enthÑlt. Dieser Parameter mu· angegeben werden.
    Inidatei: Name der Inidatei des CD Spielers. Wenn dieser Parameter
        nicht angegeben wird, nimmt CDMERGE die Datei CDPLAYER.INI im
        momentanen Verzeichnis.



7.6.94
