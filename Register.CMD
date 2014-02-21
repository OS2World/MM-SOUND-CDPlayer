/* Register CDPlayer */

IF Stream('CDPLAYER.EXE','C','QUERY EXISTS')='' THEN DO
   SAY 'Error: file CDPLAYER.EXE not found in' Directory()
   EXIT
END

CALL RxFuncAdd 'SysIni','RexxUtil','SysIni'

IF SysIni('CDPLAYER.INI','RegData','ID',X2C('A2FEC6F100'))<>'' THEN DO
   SAY 'Error: cannot set value for key "ID" in file CDPLAYER.INI'
   EXIT
END
IF SysIni('CDPLAYER.INI','RegData','Name','CDPlayer'||D2C(0))<>'' THEN DO
   CALL SysIni 'CDPLAYER.INI','RegData','DELETE:'
   SAY 'Error: cannot set velue for key "Name" in file CDPLAYER.INI' 
   EXIT   
END
SAY 'CDPlayer is registered.'

EXIT
