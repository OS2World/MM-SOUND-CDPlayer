
!IFNDEF ROOT_PATH
!ERROR ROOT_PATH not defined
!ENDIF

!IFNDEF VERSION
!ERROR VERSION not defined
!ENDIF

!IF "$(LANGUAGE)" == "DEU"
DEFLANGUAGE = -DLANG_DEU
!ELSE
!IF "$(LANGUAGE)" == "ENG"
DEFLANGUAGE = -DLANG_ENG
!ELSE
!ERROR Invalid or no language defined
!ENDIF
!ENDIF

!IFDEF SHAREWARE
DEFTARGET = -DSHAREWARE=$(SHAREWARE)
TARGET_PATH = $(ROOT_PATH)\RES\$(LANGUAGE)\SHAREWAR
!ENDIF

!IFDEF RELEASE
!IFNDEF USERNAME
!ERROR USERNAME not defined
!ENDIF
!IFNDEF REGID
!ERROR REGID not defined
!ENDIF
DEFTARGET = -DRELEASE=$(RELEASE)
TARGET_PATH = $(ROOT_PATH)\RES\$(LANGUAGE)\RELEASE

MAIN: STARTUP ALL

STARTUP:
  echo #define USERNAME "$(USERNAME)" >username.h
  echo #define REGID "$(REGID)" >>username.h
  -del $(ROOT_PATH)\RES\$(LANGUAGE)\RELEASE\CDPLAYER.RES

!ENDIF

!IFDEF TEST
DEFTARGET = -DTEST=$(TEST)
TARGET_PATH = $(ROOT_PATH)\RES\$(LANGUAGE)\TEST
!ENDIF

!IFDEF DEBUG
DEFTARGET = -DDEBUG=$(DEBUG)
TARGET_PATH = $(ROOT_PATH)\RES\$(LANGUAGE)\DEBUG
!ENDIF

!IFNDEF TARGET_PATH
!ERROR Unknown target
!ENDIF

.SUFFIXES:

.SUFFIXES: .rc .bmp

ALL: $(TARGET_PATH)\CDPLAYER.RES

$(TARGET_PATH)\CDPLAYER.RES:  $(ROOT_PATH)\RES\CDPLAYER.RC \
   $(ROOT_PATH)\SRC\CDID.H \
   $(ROOT_PATH)\SRC\PANEL.H \
   $(ROOT_PATH)\RES\$(LANGUAGE)\LANGUAGE.H \
   $(ROOT_PATH)\RES\CDHELP.RC    \
   $(ROOT_PATH)\RES\CDDLG.DLG    \
   $(ROOT_PATH)\RES\BACK1.BMP    \
   $(ROOT_PATH)\RES\BACK0.BMP    \
   $(ROOT_PATH)\RES\FORWARD0.BMP \
   $(ROOT_PATH)\RES\FORWARD1.BMP \
   $(ROOT_PATH)\RES\PLAY0.BMP    \
   $(ROOT_PATH)\RES\PLAY1.BMP    \
   $(ROOT_PATH)\RES\PAUSE0.BMP   \
   $(ROOT_PATH)\RES\PAUSE1.BMP   \
   $(ROOT_PATH)\RES\STOP1.BMP    \
   $(ROOT_PATH)\RES\STOP0.BMP    \
   $(ROOT_PATH)\RES\EJECT1.BMP   \
   $(ROOT_PATH)\RES\EJECT0.BMP   \
   $(ROOT_PATH)\RES\REPEAT1.BMP  \
   $(ROOT_PATH)\RES\REPEAT0.BMP  \
   $(ROOT_PATH)\RES\NREPEAT1.BMP \
   $(ROOT_PATH)\RES\NREPEAT0.BMP \
   $(ROOT_PATH)\RES\MUTE0.BMP    \
   $(ROOT_PATH)\RES\MUTE2.BMP    \
   $(ROOT_PATH)\RES\MUTE1.BMP    \
   $(ROOT_PATH)\RES\ANIMAT32.BMP \
   $(ROOT_PATH)\RES\ANIMAT00.BMP \
   $(ROOT_PATH)\RES\ANIMAT28.BMP \
   $(ROOT_PATH)\RES\ANIMAT24.BMP \
   $(ROOT_PATH)\RES\ANIMAT20.BMP \
   $(ROOT_PATH)\RES\ANIMAT04.BMP \
   $(ROOT_PATH)\RES\ANIMAT08.BMP \
   $(ROOT_PATH)\RES\ANIMAT12.BMP \
   $(ROOT_PATH)\RES\ANIMAT36.BMP \
   $(ROOT_PATH)\RES\ANIMAT40.BMP \
   $(ROOT_PATH)\RES\ANIMAT44.BMP \
   $(ROOT_PATH)\RES\ANIMAT02.BMP \
   $(ROOT_PATH)\RES\ANIMAT06.BMP \
   $(ROOT_PATH)\RES\ANIMAT10.BMP \
   $(ROOT_PATH)\RES\ANIMAT14.BMP \
   $(ROOT_PATH)\RES\ANIMAT18.BMP \
   $(ROOT_PATH)\RES\ANIMAT22.BMP \
   $(ROOT_PATH)\RES\ANIMAT26.BMP \
   $(ROOT_PATH)\RES\ANIMAT30.BMP \
   $(ROOT_PATH)\RES\ANIMAT34.BMP \
   $(ROOT_PATH)\RES\ANIMAT38.BMP \
   $(ROOT_PATH)\RES\ANIMAT42.BMP \
   $(ROOT_PATH)\RES\ANIMAT46.BMP \
   $(ROOT_PATH)\RES\CDPLAYER.ICO \
   $(ROOT_PATH)\RES\RES.MAK
   CD $(ROOT_PATH)\RES
   echo #define VERSION "$(VERSION)" >version.h
   RC -x -r -i $(ROOT_PATH)\SRC $(DEFLANGUAGE) $(DEFTARGET) $(ROOT_PATH)\RES\CDPLAYER.RC $(TARGET_PATH)\CDPLAYER.RES

