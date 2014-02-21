/* Installation script for CD Player */

call RxFuncAdd 'SysLoadFuncs', 'REXXUTIL', 'SysLoadFuncs'
call SysLoadFuncs

parse source . . SourcePath
SourcePath = FileSpec("drive", SourcePath)''FileSpec("path", SourcePath)

NeedBytes = 0;

call FileSize(SourcePath'CDPLAYER.EXE')
if Result = 0 then
  call Error 'CDPLAYER.EXE not found in the installation directory!'
else
  NeedBytes = NeedBytes + Result

call FileSize(SourcePath'CDPLAYER.INF')
if Result = 0 then
  call Error 'CDPLAYER.INF not found in the installation directory!'
else
  NeedBytes = NeedBytes + Result

call FileSize(SourcePath'CDPLAYER.HLP')
if Result = 0 then
  call Error 'CDPLAYER.HLP not found in the installation directory!'
else
  NeedBytes = NeedBytes + Result

call FileSize(SourcePath'REGISTER.TXT')
if File.0 = 0 then
  call Error 'REGISTER.TXT not found in the installation directory!'
else
  NeedBytes = NeedBytes + Result

call FileSize(SourcePath'COPYRGHT.TXT')
if File.0 = 0 then
  call Error 'COPYRGHT.TXT not found in the installation directory!'
else
  NeedBytes = NeedBytes + Result

parse arg InstPath

call SysCls
say 'ษออออออออออออออออออออออออออออออออออออออป'
say 'บ                                      บ'
say 'บ       CD Player Installation         บ'
say 'บ                                      บ'
say 'บ     This programm installs the       บ'
say 'บ     CD Player on your harddisk.      บ'
say 'บ                                      บ'
say 'ศออออออออออออออออออออออออออออออออออออออผ'
say
if InstPath = '' then
  do
  say 'Enter the complete path where the'
  say 'CD Player should be installed:'
  pull InstPath
  end

InstDrive = FileSpec("drive", InstPath)
if InstDrive = '' then 
  call Error 'You must enter a complete pathname'

InstDir = FileSpec("path", InstPath)
if InstDir = '' then
  call Error 'You must enter a complete pathname'

if Right(InstPath, 1) = '.' then
  call Error 'You must enter a complete pathname'

if Right(InstPath, 1) = '\' then
  call Error 'You must enter a complete pathname'

InstName = FileSpec("name", InstName)
if InstName = '' then
  call Error 'You must enter a complete pathname'

DriveInfo = SysDriveInfo(InstDrive)

if DriveInfo = '' then
  call Error 'The drive does not exist!'

AvailBytes = SubWord(DriveInfo, 2, 1)
if AvailBytes < NeedBytes then
  call Error 'There is not enough free space on this drive!'

call SysMkDir InstPath
call SysFileTree InstPath, 'File', 'D'
if File.0 = 0 then
  call Error 'The directory 'InstPath' cannot be created'

say 'Copying the CD Player files...'
address cmd '@copy 'SourcePath'CDPLAYER.EXE 'InstPath
address cmd '@copy 'SourcePath'CDPLAYER.HLP 'InstPath
address cmd '@copy 'SourcePath'CDPLAYER.INF 'InstPath
address cmd '@copy 'SourcePath'REGISTER.TXT 'InstPath
address cmd '@copy 'SourcePath'COPYRGHT.TXT 'InstPath
say 'done.'

say 'Creating the program objects...'
SetupStr = 'EXENAME='InstPath'\CDPLAYER.EXE;STARTUPDIR='InstPath
res = SysCreateObject('WPProgram', 'The CD Player', '<WP_DESKTOP>', SetupStr)
if res = 0 then
  call Error 'The programm object for the CD Player cannot be created!'

SetupStr = 'EXENAME=VIEW.EXE;STARTUPDIR='InstPath';PARAMETERS=CDPLAYER.INF'
res = SysCreateObject('WPProgram', 'CD Player Documentation', '<WP_DESKTOP>', SetupStr)
if res = 0 then
  call Error 'The object for the CD Player documentation cannot be created'

say 'ready.'

say 'You can start the CD Player with the programm object "The CD Player"'
say 'on your workplace.'
say 'The CD Player dokumentation can be viewed with the object'
say '"CD Player Documentation".'

address cmd '@cd 'InstPath
exit 0

Error: Procedure 
parse arg ErrString
say 'ERROR:'
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
