include CommonDefs.mak

BIN_DIR = Bin

OPENNI2_INCLUDE=/home/spin/projects/kinect/openni2/Include
OPENNI2_REDIST=../../../../openni2/Bin/x64-Release
NiTE_REDIST=../../Redist

INC_DIRS = \
	. \
	../Common \
	../../Include \
	../../../External/GL \
	$(OPENNI2_INCLUDE)

SRC_FILES = *.cpp

ifeq ("$(OSTYPE)","Darwin")
	CFLAGS += -DMACOS
	LDFLAGS += -framework OpenGL -framework GLUT
else
	CFLAGS += -DUNIX -DGLX_GLXEXT_LEGACY
	USED_LIBS += glut GL
endif

LIB_DIRS += $(NiTE_REDIST)
LIB_DIRS += $(OPENNI2_REDIST)

USED_LIBS += OpenNI2 NiTE2

EXE_NAME = trackr

CFLAGS += -Wall

include CommonCppMakefile
