
!IFNDEF ROOT_PATH
!ERROR ROOT_PATH not defined
!ENDIF

!IFDEF SHAREWARE
DEFTARGET = -DSHAREWARE=$(SHAREWARE)
TARGET_PATH = $(ROOT_PATH)\OBJ\SHAREWAR
C_OPTIONS = /Su4 /Ss /Q /Wproret /Fi /Si /O /G4 /Gi /Oi /Gm
!ENDIF

!IFDEF RELEASE
DEFTARGET = -DRELEASE=$(RELEASE)
TARGET_PATH = $(ROOT_PATH)\OBJ\RELEASE
C_OPTIONS = /Su4 /Ss /Q /Wproret /Fi /Si /O /G4 /Gi /Oi /Gm
!ENDIF

!IFDEF TEST
DEFTARGET = -DTEST=$(TEST)
TARGET_PATH = $(ROOT_PATH)\OBJ\TEST
C_OPTIONS = /Su4 /Ss /Q /Wproret /Fi /Si /O /G4 /Gi /Oi /Gm
!ENDIF

!IFDEF DEBUG
DEFTARGET = -DDEBUG=$(DEBUG)
TARGET_PATH = $(ROOT_PATH)\OBJ\DEBUG
C_OPTIONS = /Su4 /Ss /Q /Wproret /Fi /Si /Ti /Op- /G4 /Tm /Gm
!ENDIF

!IFDEF LISTING
C_OPTIONS = $(C_OPTIONS) /Ls /Lx /La /Li
!ENDIF

!IFNDEF TARGET_PATH
!ERROR Unknown target
!ENDIF

.SUFFIXES:

.SUFFIXES: .c

!IFDEF LISTING
{$(ROOT_PATH)\SRC}.c{$(TARGET_PATH)}.obj:
   CD $(ROOT_PATH)\SRC
   ICC.EXE /C $(DEFTARGET) $(C_OPTIONS) /Fo$@ /Fl$(ROOT_PATH)\LST\$*.lst %s
!ELSE
{$(ROOT_PATH)\SRC}.c{$(TARGET_PATH)}.obj:
   CD $(ROOT_PATH)\SRC
   ICC.EXE /C $(DEFTARGET) $(C_OPTIONS) /Fo$@ %s
!ENDIF

ALL:   $(TARGET_PATH)\CDCTL.OBJ \
  $(TARGET_PATH)\CDDEVICE.OBJ \
  $(TARGET_PATH)\CDGLOBAL.OBJ \
  $(TARGET_PATH)\CDMENU.OBJ \
  $(TARGET_PATH)\CDMSG.OBJ \
  $(TARGET_PATH)\CDPLAYER.OBJ \
  $(TARGET_PATH)\CDPOS.OBJ \
  $(TARGET_PATH)\CDPRF.OBJ \
  $(TARGET_PATH)\CDTITLE.OBJ \
  $(TARGET_PATH)\CDTSET.OBJ \
  $(TARGET_PATH)\CDTSLIDE.OBJ \
  $(TARGET_PATH)\CDVOLUME.OBJ \
  $(TARGET_PATH)\SUBCLASS.OBJ \
  $(TARGET_PATH)\WUTIL.OBJ

$(TARGET_PATH)\CDCTL.OBJ:  $(ROOT_PATH)\SRC\CDCTL.C  \
   $(ROOT_PATH)\SRC\cdglobal.h  \
     $(ROOT_PATH)\SRC\cdid.h  \
       $(ROOT_PATH)\SRC\panel.h  \
   $(ROOT_PATH)\SRC\cddevice.h  \
   $(ROOT_PATH)\SRC\cdmsg.h  \
   $(ROOT_PATH)\SRC\cdplayer.h  \
   $(ROOT_PATH)\SRC\cdpos.h  \
   $(ROOT_PATH)\SRC\cdprf.h  \
   $(ROOT_PATH)\SRC\cdtitle.h  \
   $(ROOT_PATH)\SRC\cdctl.h  \
   $(ROOT_PATH)\SRC\wutil.h  \
   $(ROOT_PATH)\OBJ\OBJ.MAK


$(TARGET_PATH)\CDDEVICE.OBJ:  $(ROOT_PATH)\SRC\CDDEVICE.C  \
   $(ROOT_PATH)\SRC\cdglobal.h  \
     $(ROOT_PATH)\SRC\cdid.h  \
       $(ROOT_PATH)\SRC\panel.h  \
   $(ROOT_PATH)\SRC\cddevice.h  \
   $(ROOT_PATH)\OBJ\OBJ.MAK


$(TARGET_PATH)\CDGLOBAL.OBJ:  $(ROOT_PATH)\SRC\CDGLOBAL.C  \
   $(ROOT_PATH)\SRC\cdglobal.h  \
     $(ROOT_PATH)\SRC\cdid.h  \
       $(ROOT_PATH)\SRC\panel.h  \
   $(ROOT_PATH)\OBJ\OBJ.MAK


$(TARGET_PATH)\CDMENU.OBJ:  $(ROOT_PATH)\SRC\CDMENU.C  \
   $(ROOT_PATH)\SRC\cdglobal.h  \
     $(ROOT_PATH)\SRC\cdid.h  \
       $(ROOT_PATH)\SRC\panel.h  \
   $(ROOT_PATH)\SRC\cdmenu.h  \
   $(ROOT_PATH)\OBJ\OBJ.MAK


$(TARGET_PATH)\CDMSG.OBJ:  $(ROOT_PATH)\SRC\CDMSG.C  \
   $(ROOT_PATH)\SRC\cdglobal.h  \
     $(ROOT_PATH)\SRC\cdid.h  \
       $(ROOT_PATH)\SRC\panel.h  \
   $(ROOT_PATH)\SRC\cddevice.h  \
   $(ROOT_PATH)\SRC\cdmsg.h  \
   $(ROOT_PATH)\OBJ\OBJ.MAK


$(TARGET_PATH)\CDPLAYER.OBJ:  $(ROOT_PATH)\SRC\CDPLAYER.C  \
   $(ROOT_PATH)\SRC\cdglobal.h  \
     $(ROOT_PATH)\SRC\cdid.h  \
       $(ROOT_PATH)\SRC\panel.h  \
   $(ROOT_PATH)\SRC\cdctl.h  \
   $(ROOT_PATH)\SRC\cddevice.h  \
   $(ROOT_PATH)\SRC\cdmenu.h  \
   $(ROOT_PATH)\SRC\cdmsg.h  \
   $(ROOT_PATH)\SRC\cdpos.h  \
   $(ROOT_PATH)\SRC\cdprf.h  \
   $(ROOT_PATH)\SRC\cdtset.h  \
   $(ROOT_PATH)\SRC\cdtslide.h  \
   $(ROOT_PATH)\SRC\cdtitle.h  \
   $(ROOT_PATH)\SRC\cdvolume.h  \
   $(ROOT_PATH)\SRC\subclass.h  \
   $(ROOT_PATH)\SRC\wutil.h  \
   $(ROOT_PATH)\SRC\cdplayer.h  \
   $(ROOT_PATH)\OBJ\OBJ.MAK

$(TARGET_PATH)\CDPOS.OBJ:  $(ROOT_PATH)\SRC\CDPOS.C  \
   $(ROOT_PATH)\SRC\cdglobal.h  \
     $(ROOT_PATH)\SRC\cdid.h  \
       $(ROOT_PATH)\SRC\panel.h  \
   $(ROOT_PATH)\SRC\cdpos.h  \
   $(ROOT_PATH)\OBJ\OBJ.MAK


$(TARGET_PATH)\CDPRF.OBJ:  $(ROOT_PATH)\SRC\CDPRF.C  \
   $(ROOT_PATH)\SRC\cdglobal.h  \
     $(ROOT_PATH)\SRC\cdid.h  \
       $(ROOT_PATH)\SRC\panel.h  \
   $(ROOT_PATH)\SRC\cdctl.h  \
   $(ROOT_PATH)\SRC\cddevice.h  \
   $(ROOT_PATH)\SRC\cdplayer.h  \
   $(ROOT_PATH)\SRC\reg.h  \
   $(ROOT_PATH)\SRC\cdprf.h  \
   $(ROOT_PATH)\OBJ\OBJ.MAK


$(TARGET_PATH)\CDTITLE.OBJ:  $(ROOT_PATH)\SRC\CDTITLE.C  \
   $(ROOT_PATH)\SRC\cdglobal.h  \
     $(ROOT_PATH)\SRC\cdid.h  \
       $(ROOT_PATH)\SRC\panel.h  \
   $(ROOT_PATH)\SRC\cdplayer.h  \
   $(ROOT_PATH)\SRC\cdprf.h  \
   $(ROOT_PATH)\SRC\cdtitle.h  \
   $(ROOT_PATH)\OBJ\OBJ.MAK


$(TARGET_PATH)\CDTSET.OBJ:  $(ROOT_PATH)\SRC\CDTSET.C  \
   $(ROOT_PATH)\SRC\cdglobal.h  \
     $(ROOT_PATH)\SRC\cdid.h  \
       $(ROOT_PATH)\SRC\panel.h  \
   $(ROOT_PATH)\SRC\cdplayer.h  \
   $(ROOT_PATH)\SRC\cdtset.h  \
   $(ROOT_PATH)\OBJ\OBJ.MAK


$(TARGET_PATH)\CDTSLIDE.OBJ:  $(ROOT_PATH)\SRC\CDTSLIDE.C  \
   $(ROOT_PATH)\SRC\cdglobal.h  \
     $(ROOT_PATH)\SRC\cdid.h  \
       $(ROOT_PATH)\SRC\panel.h  \
   $(ROOT_PATH)\SRC\cdplayer.h  \
   $(ROOT_PATH)\SRC\cdtslide.h  \
   $(ROOT_PATH)\OBJ\OBJ.MAK


$(TARGET_PATH)\CDVOLUME.OBJ:  $(ROOT_PATH)\SRC\CDVOLUME.C  \
   $(ROOT_PATH)\SRC\cdglobal.h  \
     $(ROOT_PATH)\SRC\cdid.h  \
       $(ROOT_PATH)\SRC\panel.h  \
   $(ROOT_PATH)\SRC\cddevice.h  \
   $(ROOT_PATH)\SRC\cdmsg.h  \
   $(ROOT_PATH)\SRC\cdprf.h  \
   $(ROOT_PATH)\SRC\cdvolume.h  \
   $(ROOT_PATH)\OBJ\OBJ.MAK


$(TARGET_PATH)\SUBCLASS.OBJ:  $(ROOT_PATH)\SRC\SUBCLASS.C  \
   $(ROOT_PATH)\SRC\cdglobal.h  \
     $(ROOT_PATH)\SRC\cdid.h  \
       $(ROOT_PATH)\SRC\panel.h  \
   $(ROOT_PATH)\SRC\cdplayer.h  \
   $(ROOT_PATH)\SRC\subclass.h  \
   $(ROOT_PATH)\OBJ\OBJ.MAK


$(TARGET_PATH)\WUTIL.OBJ:  $(ROOT_PATH)\SRC\WUTIL.C  \
   $(ROOT_PATH)\SRC\cdglobal.h  \
     $(ROOT_PATH)\SRC\cdid.h  \
       $(ROOT_PATH)\SRC\panel.h  \
   $(ROOT_PATH)\SRC\wutil.h  \
   $(ROOT_PATH)\OBJ\OBJ.MAK
