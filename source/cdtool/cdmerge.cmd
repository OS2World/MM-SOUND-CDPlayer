/* CDMERGE - Version 1.00 - (C) Michael Bock 1994

   FÅgt die CD Bibliothek aus einer mit CDXTRACT erstellten Datei in die
   CDPLAYER.INI Datei ein.

   Der Gebrauch dieses Programms ist nur in Verbindung mit dem "CD Spieler
   fÅr OS/2" zulÑssig.  Alle EinschrÑnkungen bezÅglich des Gebrauchs der nicht
   registrierten Version des "CD Spielers fÅr OS/2" betreffen auch dieses Pro-
   gramm. 
   Es wird keine GewÑhrleistung fÅr die FunktionsfÑhigkeit und Fehlerfreiheit 
   des Programmes Åbernommen.

   Benutzung:
   CDMERGE <Extrahierte Datei> [Inidatei]
   Extrahierte Datei: Name der Datei, die die extrahierte CD Bibliothek
        enthÑlt. Dieser Parameter mu· angegeben werden.
   Inidatei: Name der Inidatei des CD Spielers. Wenn dieser Parameter
        nicht angegeben wird, nimmt CDMERGE die Datei CDPLAYER.INI im
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

Res = SysIni(CDLibName, 'CDLibrary', 'Version')
if Res \= 1 then
  signal ReadError

Res = SysIni(CDLibName, 'ALL:', CDAppl)
if Res = 'ERROR:' then
  signal ReadError

Res = SysIni(CDIniName, 'ALL:', CDOldAppl)
if Res = 'ERROR:' then
  signal WriteError

Say 'Importiere' CDLibName '->' CDIniName
Say

do i=1 to CDAppl.0
  Cont = SysIni(CDLibName, CDAppl.i, 'Contents')
  if Cont \= 'ERROR:' then
  do
    Title = SysIni(CDLibName, CDAppl.i, 'CDTitle')
    if Title = 'ERROR:' then
      Title = 'ohne Namen'
    else
      Title = Left(Title, Length(Title)-1)
    say 'Importiere' CDAppl.i '-' Left(Title, 50, ' ')

    Skip = 0
    FixedIndex = 0
    MaxIndex = 1
    do j=1 to CDOldAppl.0
      if Left(CDAppl.i, 10) = Left(CDOldAppl.j, 10) then
      do
        OldCont = SysIni(CDIniName, CDOldAppl.j, 'Contents')
        if (OldCont \= 'ERROR:') & (Length(Cont) = Length(OldCont)) & (SubStr(Cont, 57) = SubStr(OldCont, 57)) then
        do
          say 'Die momentane CD befindet sich schon in Ihrer CD Bibliothek'
          say 'öberschreiben (J/N) ?'
          Key = ' '
          do while (Key \= 'J') & (Key \= 'j') & (Key \= 'N') & (Key \= 'n')
            call Beep 440, 250
            Key = SysGetKey('NOECHO')
          end
          if (Key = 'N') | (Key = 'n') then
            Skip = 1
          else
            FixedIndex = SubStr(CDOldAppl.j, 11)
        end
        else
        do
          MaxIndex = Max(MaxIndex, SubStr(CDOldAppl.j, 11) + 1)
        end 
      end
    end

    if FixedIndex \= 0 then
      MaxIndex = FixedIndex

    if \ Skip then
    do
      CurrAppl = Left(CDAppl.i, 10)''MaxIndex
      Res = SysIni(CDLibName, CDAppl.i, 'ALL:', CDContents)
      if Res = 'ERROR:' then
        signal ReadError
      do j=1 to CDContents.0
        say '-' CDContents.j
        CDValue = SysIni(CDLibName, CDAppl.i, CDContents.j)
        if CDValue = 'ERROR:' then
          signal ReadError
        Res = SysIni(CDIniName, CurrAppl, CDContents.j, CDValue)
        if Res = 'ERROR:' then
          signal WriteError
      end
    end
  end
end
exit 0

UserBreak:
say 'FEHLER:'
say 'Das Programm wurde mit Control-C unterbrochen. Die zuletzt bearbeitete'
say 'CD wurde mîglichweise nicht vollstÑndig Åbertragen. Wiederholen Sie den'
say 'Vorgang im Zweifelsfall.'
exit 2

Usage:
say 'Programmaufruf:'
say 'CDMERGE <Extrahierte Datei> [Inidatei]'
say 'Extrahierte Datei: Name der Datei, die die extrahierte CD Bibliothek'
say '    enthÑlt. Dieser Parameter mu· angegeben werden.'
say 'Inidatei: Name der Inidatei des CD Spielers. Wenn dieser Parameter'
say '    nicht angegeben wird, nimmt CDMERGE die Datei CDPLAYER.INI im'
say '    momentanen Verzeichnis.'
exit 1
 
ReadError:
say 'FEHLER:'
say 'Die Datei' CDLibName 'kann nicht gelesen werden'
say 'Entweder die Datei ist nicht vorhanden, oder es handelt sich nicht um'
say 'eine gÅltige CD Bibliothek.'
exit 1

WriteError:
say 'FEHLER:'
say 'Die Datei' CDIniName 'kann nicht gefunden werden oder die Datei konnte'
say 'nicht beschrieben werden.'
exit 1
