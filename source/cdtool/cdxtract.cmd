/* CDXTRACT - Version 1.00 - (C) Michael Bock 1994

   Extrahiert die CD Bibliothek aus der Datei CDPLAYER.INI in eine eigene
   Datei.

   Der Gebrauch dieses Programms ist nur in Verbindung mit dem "CD Spieler
   fÅr OS/2" zulÑssig.  Alle EinschrÑnkungen bezÅglich des Gebrauchs der nicht
   registrierten Version des "CD Spielers fÅr OS/2" betreffen auch dieses Pro-
   gramm.
   Es wird keine GewÑhrleistung fÅr die FunktionsfÑhigkeit und Fehlerfreiheit
   des Programmes Åbernommen.

   Benutzung:
   CDXTRACT <Extrahierte Datei> [Inidatei]
   Extrahierte Datei: Name der Datei, die die extrahierte CD Bibliothek
        aufnimmt. Dieser Parameter mu· angegeben werden.
        WARNUNG! Eine bereits vorhandene Datei dieses Namens wird vor der
        AusfÅhrung des Programms gelîscht.
   Inidatei: Name der Inidatei des CD Spielers. Wenn dieser Parameter
        nicht angegeben wird, nimmt CDXTRACT die Datei CDPLAYER.INI im
        momentanen Verzeichnis.
*/

call RxFuncAdd 'SysLoadFuncs', 'RexxUtil', 'SysLoadFuncs'
call SysLoadFuncs

signal on halt name UserBreak
parse arg CDLibName CDIniName

if CDLibName = '' then
  signal Usage

if CDIniName = '' then
  CDIniName = 'CDPLAYER.INI'

Res = SysIni(CDIniName, 'ALL:', CDAppl)
if Res = 'ERROR:' then
  signal ReadError
if CDAppl.0 = 0 then
  signal ReadError

Res = SysFileDelete(CDLibName)
if Res > 2 then
  signal WriteError

Res = SysIni(CDLibName, 'CDLibrary', 'Version', '1')
if Res = 'ERROR:' then
  signal WriteError

Say 'Extrahiere' CDIniName '->' CDLibName
Say

do i=1 to CDAppl.0
  Res = SysIni(CDIniName, CDAppl.i, 'Contents')
  if Res \= 'ERROR:' then
  do
    Title = SysIni(CDIniName, CDAppl.i, 'CDTitle')
    if Title = 'ERROR:' then
      Title = 'ohne Namen'
    else
      Title = Left(Title, Length(Title)-1)
    say 'Extrahiere' CDAppl.i '-' Left(Title, 50, ' ')
    Res = SysIni(CDIniName, CDAppl.i, 'ALL:', CDContents)
    if Res = 'ERROR:' then
      signal ReadError
    do j=1 to CDContents.0
      say '-' CDContents.j
      CDValue = SysIni(CDIniName, CDAppl.i, CDContents.j)
      if CDValue = 'ERROR:' then
        signal ReadError
      Res = SysIni(CDLibName, CDAppl.i, CDContents.j, CDValue)
      if Res = 'ERROR:' then
        signal WriteError
    end
  end
end

exit 0

UserBreak:
say 'FEHLER:'
say 'Das Programm wurde mit Control-C unterbrochen. Die zuletzt bearbeitete'
say 'CD wurde mîglichweise nicht vollstÑndig extrahiert. Wiederholen Sie die'
say 'Extrahierung im Zweifelsfall.'
exit 2

Usage:
say 'Programmaufruf:'
say 'CDXTRACT <Extrahierte Datei> [Inidatei]'
say 'Extrahierte Datei: Name der Datei, die die extrahierte CD Bibliothek'
say '    aufnimmt. Dieser Parameter mu· angegeben werden.'
say '    WARNUNG! Eine bereits vorhandene Datei dieses Namens wird vor der'
say '    AusfÅhrung des Programms gelîscht.'
say 'Inidatei: Name der Inidatei des CD Spielers. Wenn dieser Parameter'
say '    nicht angegeben wird, nimmt CDXTRACT die Datei CDPLAYER.INI im'
say '    momentanen Verzeichnis.'
exit 1
 
ReadError:
say 'FEHLER:'
say 'Die Datei' CDIniName 'kann nicht gelesen werden'
say 'Entweder die Datei ist nicht vorhanden, oder es handelt sich nicht um'
say 'eine gÅltige CD Bibliothek.'
exit 1

WriteError:
say 'FEHLER:'
say 'Die Datei' CDLibName 'kann nicht erstellt werden oder eine bereits'
say 'vorhandene Datei dieses Namens konnte nicht gelîscht werden.'
exit 1
