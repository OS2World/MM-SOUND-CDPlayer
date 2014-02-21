
    CDXTRACT & CDMERGE - Version 1.00 - (C) Michael Bock 1994

    Der Gebrauch dieser Programme ist nur in Verbindung mit dem "CD Spieler
    f�r OS/2" zul�ssig. Alle Einschr�nkungen bez�glich des Gebrauchs der nicht
    registrierten Version des "CD Spielers f�r OS/2" betreffen auch diese Pro-
    gramme.
    Es wird keine Gew�hrleistung f�r die Funktionsf�higkeit und Fehlerfreiheit
    der Programme �bernommen.

    �berblick

    Da die CDPLAYER.INI nicht nur die CD Bibliothek, sondern auch alle anderen
    Einstellungen sowie die (hoffentlich vorhandene :-) Registrierungsinforma-
    tion enth�lt, kann diese Datei normalerweise nicht verwendet werden um die
    eigene CD Bibliothek mit anderen Benutzern des CD Spielers auszutauschen.
    Mit den beiden Rexx-Programmen CDXTRACT und CDMERGE ist es nun trotzdem
    m�glich, die eigene CD Bibliothek weiterzugeben und fremde CD Bibliotheken
    einzubinden.
    Dies ist allerdings nur eine vorl�ufige L�sung, da die n�chste Version des
    CD Spielers diese M�glichkeit direkt bieten wird. Mit CDXTRACT erstellte
    CD Bibliotheken k�nnen aber auch dann weiterhin benutzt werden.
    WICHTIG! Zur Benutzung der beiden Programme mu� die REXX-Unterst�tzung von 
    OS/2 aktiviert sein.

    Installation

    Kopieren sie einfach die beiden Dateien CDXTRACT.CMD und CDMERGE.CMD in 
    das Verzeichnis ihres CD Spielers.

    CDXTRACT

    Mit CDXTRACT kann die CD Bibliothek aus der Datei CDPLAYER.INI extrahiert
    werden. Dabei wird eine neue Datei erstellt, die nur die CD Bibliothek
    enth�lt, nicht aber den �brigen Inhalt der CDPLAYER.INI Datei.
    WARNUNG! Eine bereits vorhandene Datei wird dabei �berschrieben.

    Programmaufruf:

    CDXTRACT <Extrahierte Datei> [Inidatei]
    Extrahierte Datei: Name der Datei, die die extrahierte CD Bibliothek
        aufnimmt. Dieser Parameter mu� angegeben werden.
        WARNUNG! Eine bereits vorhandene Datei dieses Namens wird vor der
        Ausf�hrung des Programms gel�scht.
    Inidatei: Name der Inidatei des CD Spielers. Wenn dieser Parameter
        nicht angegeben wird, nimmt CDXTRACT die Datei CDPLAYER.INI im
        momentanen Verzeichnis.

    Tip: leider sind die notwendigen Rexxroutinen ziemlich langsam. Um den
    Vorgang zu beschleunigen, empfiehlt es sich, die Zieldatei auf einer RAM-
    Disk anzulegen.

    CDMERGE

    Mit CDMERGE kann eine mit CDXTRACT erstellte CD Bibliothek in die Datei
    CDPLAYER.INI des CD Spielers �bernommen werden.
    Es kann vorkommen das einzelne CDs der neuen CD Bibliothek sich auch schon
    in ihrer CD Bibliothek befinden. In diesem Fall fragt CDMERGE nach, ob sie
    den CD Eintrag �berschreiben wollen. Wenn ja, werden alle in der externen
    CD Bibliothek vorhandenen Titel und Infos �bernommen. Eintr�ge, die in der
    externen CD Bibliothek nicht vorhanden sind, sich aber in ihrer CD Biblio-
    thek befinden, werden nicht(!) �berschrieben. Wenn die externe Bibliothek
    z.B. nur die Titel 1-6 definiert, aber nicht die Titel 7-9 und �berhaupt
    keine zus. Informationen, werden ihre Titel 7-9 und ihre zus. Informatio-
    nen beibehalten. Das gleiche gilt f�r die gespeicherte Position und das
    gespeicherte Programm.

    Programmaufruf:

    CDMERGE <Extrahierte Datei> [Inidatei]
    Extrahierte Datei: Name der Datei, die die extrahierte CD Bibliothek
        enth�lt. Dieser Parameter mu� angegeben werden.
    Inidatei: Name der Inidatei des CD Spielers. Wenn dieser Parameter
        nicht angegeben wird, nimmt CDMERGE die Datei CDPLAYER.INI im
        momentanen Verzeichnis.



7.6.94
