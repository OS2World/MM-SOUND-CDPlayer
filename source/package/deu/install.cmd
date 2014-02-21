/* Installation script for CD Player */

call RxFuncAdd 'SysLoadFuncs', 'REXXUTIL', 'SysLoadFuncs'
call SysLoadFuncs

parse source . . SourcePath
SourcePath = FileSpec("drive", SourcePath)''FileSpec("path", SourcePath)

NeedBytes = 0;

call FileSize(SourcePath'CDPLAYER.EXE')
if Result = 0 then
  call Error 'CDPLAYER.EXE wurde im Installationsverzeichnis nicht gefunden!'
else
  NeedBytes = NeedBytes + Result

call FileSize(SourcePath'CDPLAYER.INF')
if Result = 0 then
  call Error 'CDPLAYER.INF wurde im Installationsverzeichnis nicht gefunden!'
else
  NeedBytes = NeedBytes + Result

call FileSize(SourcePath'CDPLAYER.HLP')
if Result = 0 then
  call Error 'CDPLAYER.HLP wurde im Installationsverzeichnis nicht gefunden!'
else
  NeedBytes = NeedBytes + Result

call FileSize(SourcePath'REGISTER.TXT')
if File.0 = 0 then
  call Error 'REGISTER.TXT wurde im Installationsverzeichnis nicht gefunden!'
else
  NeedBytes = NeedBytes + Result

call FileSize(SourcePath'COPYRGHT.TXT')
if File.0 = 0 then
  call Error 'COPYRGHT.TXT wurde im Installationsverzeichnis nicht gefunden!'
else
  NeedBytes = NeedBytes + Result

parse arg InstPath

call SysCls
say 'ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»'
say 'º                                      º'
say 'º       CD Spieler Installation        º'
say 'º                                      º'
say 'º  Dieses Programm installiert den     º'
say 'º  CD Spieler auf Ihrer Festplatte.    º'
say 'º                                      º'
say 'ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼'
say
if InstPath = '' then
  do
  say 'Geben Sie das vollst„ndige Verzeichnis an,'
  say 'in dem der CD Spieler installiert werden soll:'
  pull InstPath
  end

InstDrive = FileSpec("drive", InstPath)
if InstDrive = '' then 
  call Error 'Sie mssen einen vollst„ndigen Verzeichnispfad angeben'

InstDir = FileSpec("path", InstPath)
if InstDir = '' then
  call Error 'Sie mssen einen vollst„ndigen Verzeichnispfad angeben'

if Right(InstPath, 1) = '.' then
  call Error 'Sie mssen einen vollst„ndigen Verzeichnispfad angeben'

if Right(InstPath, 1) = '\' then
  call Error 'Sie mssen einen vollst„ndigen Verzeichnispfad angeben'

InstName = FileSpec("name", InstName)
if InstName = '' then
  call Error 'Sie mssen einen vollst„ndigen Verzeichnispfad angeben'

DriveInfo = SysDriveInfo(InstDrive)

if DriveInfo = '' then
  call Error 'Das angegebene Laufwerk existiert nicht!'

AvailBytes = SubWord(DriveInfo, 2, 1)
if AvailBytes < NeedBytes then
  call Error 'Auf dem angegebenen Laufwerk ist nicht gengend Platz!'

call SysMkDir InstPath
call SysFileTree InstPath, 'File', 'D'
if File.0 = 0 then
  call Error 'Das Verzeichnis 'InstPath' konnte nicht erstellt werden'

say 'Kopiere die CD Spieler Dateien...'
address cmd '@copy 'SourcePath'CDPLAYER.EXE 'InstPath
address cmd '@copy 'SourcePath'CDPLAYER.HLP 'InstPath
address cmd '@copy 'SourcePath'CDPLAYER.INF 'InstPath
address cmd '@copy 'SourcePath'REGISTER.TXT 'InstPath
address cmd '@copy 'SourcePath'COPYRGHT.TXT 'InstPath
say 'fertig.'

say 'Erstelle die Programmobjekte...'
SetupStr = 'EXENAME='InstPath'\CDPLAYER.EXE;STARTUPDIR='InstPath
res = SysCreateObject('WPProgram', 'Der CD Spieler', '<WP_DESKTOP>', SetupStr)
if res = 0 then
  call Error 'Das Programmobjekt fr den CD Spieler konnte nicht erstellt werden!'

SetupStr = 'EXENAME=VIEW.EXE;STARTUPDIR='InstPath';PARAMETERS=CDPLAYER.INF'
res = SysCreateObject('WPProgram', 'CD Spieler Dokumentation', '<WP_DESKTOP>', SetupStr)
if res = 0 then
  call Error 'Das Dokumentationsobjekt fr die CD Spieler Dokumentation konnte nicht erstellt'

say 'fertig.'

say 'Sie k”nnen den CD Spieler jetzt mit dem Programmobjekt "Der CD Spieler"'
say 'auf Ihrer Arbeitsoberfl„che starten.'
say 'Die CD Spieler Dokumentation k”nnen sie sich mit dem Objekt'
say '"CD Spieler Dokumentation" betrachten.'

address cmd '@cd 'InstPath
exit 0

Error: Procedure 
parse arg ErrString
say 'FEHLER:'
say ErrString
exit 1
return

FileSize: Procedure
parse arg FileName
call SysFileTree FileName, 'File', 'F'
if File.0 = 0 then
  return 0
else
  return SubStr(File.1, 20, 10)
