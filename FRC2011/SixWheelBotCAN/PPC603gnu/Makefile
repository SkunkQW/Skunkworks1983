# Wind River Workbench generated Makefile.
# Do not edit!!!
#
# The file ".wrmakefile" is the template used by the Wind River Workbench to
# generate the makefiles of this project. Add user-specific build targets and
# make rules only(!) in this project's ".wrmakefile" file. These will then be
# automatically dumped into the makefiles.

WIND_HOME := $(subst \,/,$(WIND_HOME))
WIND_BASE := $(subst \,/,$(WIND_BASE))
WIND_USR := $(subst \,/,$(WIND_USR))

all : pre_build main_all post_build

_clean ::
	@echo "make: removing targets and objects of `pwd`"

TRACE=0
TRACEON=$(TRACE:0=@)
TRACE_FLAG=$(TRACEON:1=)

MAKEFILE := Makefile

FLEXIBLE_BUILD := 1

BUILD_SPEC = PPC603gnu
DEBUG_MODE = 1
ifeq ($(DEBUG_MODE),1)
MODE_DIR := Debug
else
MODE_DIR := NonDebug
endif
OBJ_DIR := .
PRJ_ROOT_DIR := C:/WindRiver/FRC2011/SixWheelBotCAN
WS_ROOT_DIR := C:/WindRiver/FRC2011



#Global Build Macros
PROJECT_TYPE = DKM
DEFINES = 
EXPAND_DBG = 0


#BuildSpec specific Build Macros
VX_CPU_FAMILY = ppc
CPU = PPC603
TOOL_FAMILY = gnu
TOOL = gnu
TOOL_PATH = 
CC_ARCH_SPEC = -mcpu=603 -mstrict-align -mno-implicit-fp -mlongcall
LIBPATH = 
LIBS = 

IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h/wrn/coreip 

IDE_LIBRARIES = $(WIND_BASE)/target/lib/WPILib.a 



#BuildTool flags
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
DEBUGFLAGS_C++-Compiler = -g
DEBUGFLAGS_Linker = -g
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif


#Project Targets
PROJECT_TARGETS = SixWheelBot_partialImage/$(MODE_DIR)/SixWheelBot_partialImage.o \
	 SixWheelBot/$(MODE_DIR)/SixWheelBot.out


#Rules

# SixWheelBot_partialImage
ifeq ($(DEBUG_MODE),1)
SixWheelBot_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
SixWheelBot_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
SixWheelBot_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
SixWheelBot_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
SixWheelBot_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
SixWheelBot_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
SixWheelBot_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
SixWheelBot_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
SixWheelBot_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
SixWheelBot_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
SixWheelBot_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
SixWheelBot_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif
SixWheelBot_partialImage/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h/wrn/coreip 
SixWheelBot_partialImage/$(MODE_DIR)/% : IDE_LIBRARIES = $(WIND_BASE)/target/lib/WPILib.a 
SixWheelBot_partialImage/$(MODE_DIR)/% : PROJECT_TYPE = DKM
SixWheelBot_partialImage/$(MODE_DIR)/% : DEFINES = 
SixWheelBot_partialImage/$(MODE_DIR)/% : EXPAND_DBG = 0
SixWheelBot_partialImage/$(MODE_DIR)/% : VX_CPU_FAMILY = ppc
SixWheelBot_partialImage/$(MODE_DIR)/% : CPU = PPC603
SixWheelBot_partialImage/$(MODE_DIR)/% : TOOL_FAMILY = gnu
SixWheelBot_partialImage/$(MODE_DIR)/% : TOOL = gnu
SixWheelBot_partialImage/$(MODE_DIR)/% : TOOL_PATH = 
SixWheelBot_partialImage/$(MODE_DIR)/% : CC_ARCH_SPEC = -mcpu=603 -mstrict-align -mno-implicit-fp -mlongcall
SixWheelBot_partialImage/$(MODE_DIR)/% : LIBPATH = 
SixWheelBot_partialImage/$(MODE_DIR)/% : LIBS = 
SixWheelBot_partialImage/$(MODE_DIR)/% : OBJ_DIR := SixWheelBot_partialImage/$(MODE_DIR)

SixWheelBot_partialImage/$(MODE_DIR)/Objects/SixWheelBot/1983Lift.o : C:/WindRiver/FRC2011/SixWheelBot/1983Lift.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


SixWheelBot_partialImage/$(MODE_DIR)/Objects/SixWheelBot/1983PIDController.o : C:/WindRiver/FRC2011/SixWheelBot/1983PIDController.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


SixWheelBot_partialImage/$(MODE_DIR)/Objects/SixWheelBot/1983RobotDrive.o : C:/WindRiver/FRC2011/SixWheelBot/1983RobotDrive.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


SixWheelBot_partialImage/$(MODE_DIR)/Objects/SixWheelBot/DashboardDataFormat.o : C:/WindRiver/FRC2011/SixWheelBot/DashboardDataFormat.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


SixWheelBot_partialImage/$(MODE_DIR)/Objects/SixWheelBot/EncoderTest.o : C:/WindRiver/FRC2011/SixWheelBot/EncoderTest.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


SixWheelBot_partialImage/$(MODE_DIR)/Objects/SixWheelBot/MyRobot\ encoder\ tests.o : C:/WindRiver/FRC2011/SixWheelBot/MyRobot\ encoder\ tests.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


SixWheelBot_partialImage/$(MODE_DIR)/Objects/SixWheelBot/MyRobot\ lift\ 36-tooth.o : C:/WindRiver/FRC2011/SixWheelBot/MyRobot\ lift\ 36-tooth.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


SixWheelBot_partialImage/$(MODE_DIR)/Objects/SixWheelBot/MyRobot\ lift.o : C:/WindRiver/FRC2011/SixWheelBot/MyRobot\ lift.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


SixWheelBot_partialImage/$(MODE_DIR)/Objects/SixWheelBot/MyRobot\ motor\ test.o : C:/WindRiver/FRC2011/SixWheelBot/MyRobot\ motor\ test.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


SixWheelBot_partialImage/$(MODE_DIR)/Objects/SixWheelBot/MyRobot\ tank.o : C:/WindRiver/FRC2011/SixWheelBot/MyRobot\ tank.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


SixWheelBot_partialImage/$(MODE_DIR)/Objects/SixWheelBot/MyRobot.o : C:/WindRiver/FRC2011/SixWheelBot/MyRobot.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


SixWheelBot_partialImage/$(MODE_DIR)/Objects/SixWheelBot/TankPIDOutput.o : C:/WindRiver/FRC2011/SixWheelBot/TankPIDOutput.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


SixWheelBot_partialImage/$(MODE_DIR)/Objects/SixWheelBot/Timer\ test.o : C:/WindRiver/FRC2011/SixWheelBot/Timer\ test.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


OBJECTS_SixWheelBot_partialImage = SixWheelBot_partialImage/$(MODE_DIR)/Objects/SixWheelBot/1983Lift.o \
	 SixWheelBot_partialImage/$(MODE_DIR)/Objects/SixWheelBot/1983PIDController.o \
	 SixWheelBot_partialImage/$(MODE_DIR)/Objects/SixWheelBot/1983RobotDrive.o \
	 SixWheelBot_partialImage/$(MODE_DIR)/Objects/SixWheelBot/DashboardDataFormat.o \
	 SixWheelBot_partialImage/$(MODE_DIR)/Objects/SixWheelBot/EncoderTest.o \
	 SixWheelBot_partialImage/$(MODE_DIR)/Objects/SixWheelBot/MyRobot\ encoder\ tests.o \
	 SixWheelBot_partialImage/$(MODE_DIR)/Objects/SixWheelBot/MyRobot\ lift\ 36-tooth.o \
	 SixWheelBot_partialImage/$(MODE_DIR)/Objects/SixWheelBot/MyRobot\ lift.o \
	 SixWheelBot_partialImage/$(MODE_DIR)/Objects/SixWheelBot/MyRobot\ motor\ test.o \
	 SixWheelBot_partialImage/$(MODE_DIR)/Objects/SixWheelBot/MyRobot\ tank.o \
	 SixWheelBot_partialImage/$(MODE_DIR)/Objects/SixWheelBot/MyRobot.o \
	 SixWheelBot_partialImage/$(MODE_DIR)/Objects/SixWheelBot/TankPIDOutput.o \
	 SixWheelBot_partialImage/$(MODE_DIR)/Objects/SixWheelBot/Timer\ test.o

SixWheelBot_partialImage/$(MODE_DIR)/SixWheelBot_partialImage.o : $(OBJECTS_SixWheelBot_partialImage)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc -r -nostdlib -Wl,-X  -o "$@" $(OBJECTS_SixWheelBot_partialImage) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS)  && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

SixWheelBot_partialImage/$(MODE_DIR)/SixWheelBot_partialImage_compile_file : $(FILE) ;

_clean :: SixWheelBot_partialImage/$(MODE_DIR)/SixWheelBot_partialImage_clean

SixWheelBot_partialImage/$(MODE_DIR)/SixWheelBot_partialImage_clean : 
	$(TRACE_FLAG)if [ -d "SixWheelBot_partialImage" ]; then cd "SixWheelBot_partialImage"; rm -rf $(MODE_DIR); fi


# SixWheelBot
ifeq ($(DEBUG_MODE),1)
SixWheelBot/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
SixWheelBot/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
SixWheelBot/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
SixWheelBot/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
SixWheelBot/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
SixWheelBot/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
SixWheelBot/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
SixWheelBot/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
SixWheelBot/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
SixWheelBot/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
SixWheelBot/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
SixWheelBot/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif
SixWheelBot/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h/wrn/coreip 
SixWheelBot/$(MODE_DIR)/% : IDE_LIBRARIES = $(WIND_BASE)/target/lib/WPILib.a 
SixWheelBot/$(MODE_DIR)/% : PROJECT_TYPE = DKM
SixWheelBot/$(MODE_DIR)/% : DEFINES = 
SixWheelBot/$(MODE_DIR)/% : EXPAND_DBG = 0
SixWheelBot/$(MODE_DIR)/% : VX_CPU_FAMILY = ppc
SixWheelBot/$(MODE_DIR)/% : CPU = PPC603
SixWheelBot/$(MODE_DIR)/% : TOOL_FAMILY = gnu
SixWheelBot/$(MODE_DIR)/% : TOOL = gnu
SixWheelBot/$(MODE_DIR)/% : TOOL_PATH = 
SixWheelBot/$(MODE_DIR)/% : CC_ARCH_SPEC = -mcpu=603 -mstrict-align -mno-implicit-fp -mlongcall
SixWheelBot/$(MODE_DIR)/% : LIBPATH = 
SixWheelBot/$(MODE_DIR)/% : LIBS = 
SixWheelBot/$(MODE_DIR)/% : OBJ_DIR := SixWheelBot/$(MODE_DIR)

SixWheelBot/$(MODE_DIR)/Objects/SixWheelBot/1983Lift.o : C:/WindRiver/FRC2011/SixWheelBot/1983Lift.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


SixWheelBot/$(MODE_DIR)/Objects/SixWheelBot/1983PIDController.o : C:/WindRiver/FRC2011/SixWheelBot/1983PIDController.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


SixWheelBot/$(MODE_DIR)/Objects/SixWheelBot/1983RobotDrive.o : C:/WindRiver/FRC2011/SixWheelBot/1983RobotDrive.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


SixWheelBot/$(MODE_DIR)/Objects/SixWheelBot/DashboardDataFormat.o : C:/WindRiver/FRC2011/SixWheelBot/DashboardDataFormat.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


SixWheelBot/$(MODE_DIR)/Objects/SixWheelBot/EncoderTest.o : C:/WindRiver/FRC2011/SixWheelBot/EncoderTest.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


SixWheelBot/$(MODE_DIR)/Objects/SixWheelBot/MyRobot\ encoder\ tests.o : C:/WindRiver/FRC2011/SixWheelBot/MyRobot\ encoder\ tests.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


SixWheelBot/$(MODE_DIR)/Objects/SixWheelBot/MyRobot\ lift\ 36-tooth.o : C:/WindRiver/FRC2011/SixWheelBot/MyRobot\ lift\ 36-tooth.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


SixWheelBot/$(MODE_DIR)/Objects/SixWheelBot/MyRobot\ lift.o : C:/WindRiver/FRC2011/SixWheelBot/MyRobot\ lift.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


SixWheelBot/$(MODE_DIR)/Objects/SixWheelBot/MyRobot\ motor\ test.o : C:/WindRiver/FRC2011/SixWheelBot/MyRobot\ motor\ test.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


SixWheelBot/$(MODE_DIR)/Objects/SixWheelBot/MyRobot\ tank.o : C:/WindRiver/FRC2011/SixWheelBot/MyRobot\ tank.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


SixWheelBot/$(MODE_DIR)/Objects/SixWheelBot/MyRobot.o : C:/WindRiver/FRC2011/SixWheelBot/MyRobot.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


SixWheelBot/$(MODE_DIR)/Objects/SixWheelBot/TankPIDOutput.o : C:/WindRiver/FRC2011/SixWheelBot/TankPIDOutput.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


SixWheelBot/$(MODE_DIR)/Objects/SixWheelBot/Timer\ test.o : C:/WindRiver/FRC2011/SixWheelBot/Timer\ test.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


OBJECTS_SixWheelBot = SixWheelBot/$(MODE_DIR)/Objects/SixWheelBot/1983Lift.o \
	 SixWheelBot/$(MODE_DIR)/Objects/SixWheelBot/1983PIDController.o \
	 SixWheelBot/$(MODE_DIR)/Objects/SixWheelBot/1983RobotDrive.o \
	 SixWheelBot/$(MODE_DIR)/Objects/SixWheelBot/DashboardDataFormat.o \
	 SixWheelBot/$(MODE_DIR)/Objects/SixWheelBot/EncoderTest.o \
	 SixWheelBot/$(MODE_DIR)/Objects/SixWheelBot/MyRobot\ encoder\ tests.o \
	 SixWheelBot/$(MODE_DIR)/Objects/SixWheelBot/MyRobot\ lift\ 36-tooth.o \
	 SixWheelBot/$(MODE_DIR)/Objects/SixWheelBot/MyRobot\ lift.o \
	 SixWheelBot/$(MODE_DIR)/Objects/SixWheelBot/MyRobot\ motor\ test.o \
	 SixWheelBot/$(MODE_DIR)/Objects/SixWheelBot/MyRobot\ tank.o \
	 SixWheelBot/$(MODE_DIR)/Objects/SixWheelBot/MyRobot.o \
	 SixWheelBot/$(MODE_DIR)/Objects/SixWheelBot/TankPIDOutput.o \
	 SixWheelBot/$(MODE_DIR)/Objects/SixWheelBot/Timer\ test.o

SixWheelBot/$(MODE_DIR)/SixWheelBot.out : $(OBJECTS_SixWheelBot)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@";rm -f "$@";nmppc $(OBJECTS_SixWheelBot) $(IDE_LIBRARIES) | tclsh $(WIND_BASE)/host/resource/hutils/tcl/munch.tcl -c ppc > $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)ccppc $(DEBUGFLAGS_Linker) $(CC_ARCH_SPEC) -fdollars-in-identifiers -Wall $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES)  -o $(OBJ_DIR)/ctdt.o -c $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)ccppc -r -nostdlib -Wl,-X -T $(WIND_BASE)/target/h/tool/gnu/ldscripts/link.OUT -o "$@" $(OBJ_DIR)/ctdt.o $(OBJECTS_SixWheelBot) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS)  $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

SixWheelBot/$(MODE_DIR)/SixWheelBot_compile_file : $(FILE) ;

_clean :: SixWheelBot/$(MODE_DIR)/SixWheelBot_clean

SixWheelBot/$(MODE_DIR)/SixWheelBot_clean : 
	$(TRACE_FLAG)if [ -d "SixWheelBot" ]; then cd "SixWheelBot"; rm -rf $(MODE_DIR); fi

DEP_FILES := SixWheelBot_partialImage/$(MODE_DIR)/Objects/SixWheelBot/1983Lift.d SixWheelBot_partialImage/$(MODE_DIR)/Objects/SixWheelBot/1983PIDController.d SixWheelBot_partialImage/$(MODE_DIR)/Objects/SixWheelBot/1983RobotDrive.d \
	 SixWheelBot_partialImage/$(MODE_DIR)/Objects/SixWheelBot/DashboardDataFormat.d SixWheelBot_partialImage/$(MODE_DIR)/Objects/SixWheelBot/EncoderTest.d SixWheelBot_partialImage/$(MODE_DIR)/Objects/SixWheelBot/MyRobot\ encoder\ tests.d \
	 SixWheelBot_partialImage/$(MODE_DIR)/Objects/SixWheelBot/MyRobot\ lift\ 36-tooth.d SixWheelBot_partialImage/$(MODE_DIR)/Objects/SixWheelBot/MyRobot\ lift.d SixWheelBot_partialImage/$(MODE_DIR)/Objects/SixWheelBot/MyRobot\ motor\ test.d \
	 SixWheelBot_partialImage/$(MODE_DIR)/Objects/SixWheelBot/MyRobot\ tank.d SixWheelBot_partialImage/$(MODE_DIR)/Objects/SixWheelBot/MyRobot.d SixWheelBot_partialImage/$(MODE_DIR)/Objects/SixWheelBot/TankPIDOutput.d \
	 SixWheelBot_partialImage/$(MODE_DIR)/Objects/SixWheelBot/Timer\ test.d SixWheelBot/$(MODE_DIR)/Objects/SixWheelBot/1983Lift.d SixWheelBot/$(MODE_DIR)/Objects/SixWheelBot/1983PIDController.d \
	 SixWheelBot/$(MODE_DIR)/Objects/SixWheelBot/1983RobotDrive.d SixWheelBot/$(MODE_DIR)/Objects/SixWheelBot/DashboardDataFormat.d SixWheelBot/$(MODE_DIR)/Objects/SixWheelBot/EncoderTest.d \
	 SixWheelBot/$(MODE_DIR)/Objects/SixWheelBot/MyRobot\ encoder\ tests.d SixWheelBot/$(MODE_DIR)/Objects/SixWheelBot/MyRobot\ lift\ 36-tooth.d SixWheelBot/$(MODE_DIR)/Objects/SixWheelBot/MyRobot\ lift.d \
	 SixWheelBot/$(MODE_DIR)/Objects/SixWheelBot/MyRobot\ motor\ test.d SixWheelBot/$(MODE_DIR)/Objects/SixWheelBot/MyRobot\ tank.d SixWheelBot/$(MODE_DIR)/Objects/SixWheelBot/MyRobot.d \
	 SixWheelBot/$(MODE_DIR)/Objects/SixWheelBot/TankPIDOutput.d SixWheelBot/$(MODE_DIR)/Objects/SixWheelBot/Timer\ test.d
-include $(DEP_FILES)



-include $(PRJ_ROOT_DIR)/*.makefile

-include *.makefile

main_all : external_build $(PROJECT_TARGETS)
	@echo "make: built targets of `pwd`"

# entry point for extending the build
external_build ::
	@echo ""

# main entry point for pre processing prior to the build
pre_build :: $(PRE_BUILD_STEP) generate_sources
	@echo ""

# entry point for generating sources prior to the build
generate_sources ::
	@echo ""

# main entry point for post processing after the build
post_build :: $(POST_BUILD_STEP) deploy_output
	@echo ""

# entry point for deploying output after the build
deploy_output ::
	@echo ""

clean :: external_clean $(CLEAN_STEP) _clean

# entry point for extending the build clean
external_clean ::
	@echo ""
