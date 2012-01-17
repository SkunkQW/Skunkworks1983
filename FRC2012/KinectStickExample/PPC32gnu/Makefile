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

BUILD_SPEC = PPC32gnu
DEBUG_MODE = 1
ifeq ($(DEBUG_MODE),1)
MODE_DIR := Debug
else
MODE_DIR := NonDebug
endif
OBJ_DIR := .
PRJ_ROOT_DIR := C:/WindRiver/FRC2012/KinectStickExample
WS_ROOT_DIR := C:/WindRiver/FRC2012



#Global Build Macros
PROJECT_TYPE = DKM
DEFINES = 
EXPAND_DBG = 0


#BuildSpec specific Build Macros
VX_CPU_FAMILY = ppc
CPU = PPC32
TOOL_FAMILY = gnu
TOOL = gnu
TOOL_PATH = 
CC_ARCH_SPEC = -mhard-float -mstrict-align -mno-implicit-fp -DPPC32_fp60x
LIBPATH = 
LIBS = 

IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 

IDE_LIBRARIES = 



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
PROJECT_TARGETS = KinectStickExample/$(MODE_DIR)/KinectStickExample.out \
	 KinectStickExample_partialImage/$(MODE_DIR)/KinectStickExample_partialImage.o


#Rules

# KinectStickExample
ifeq ($(DEBUG_MODE),1)
KinectStickExample/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
KinectStickExample/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
KinectStickExample/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
KinectStickExample/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
KinectStickExample/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
KinectStickExample/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
KinectStickExample/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
KinectStickExample/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
KinectStickExample/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
KinectStickExample/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
KinectStickExample/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
KinectStickExample/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif
KinectStickExample/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 
KinectStickExample/$(MODE_DIR)/% : IDE_LIBRARIES = 
KinectStickExample/$(MODE_DIR)/% : PROJECT_TYPE = DKM
KinectStickExample/$(MODE_DIR)/% : DEFINES = 
KinectStickExample/$(MODE_DIR)/% : EXPAND_DBG = 0
KinectStickExample/$(MODE_DIR)/% : VX_CPU_FAMILY = ppc
KinectStickExample/$(MODE_DIR)/% : CPU = PPC32
KinectStickExample/$(MODE_DIR)/% : TOOL_FAMILY = gnu
KinectStickExample/$(MODE_DIR)/% : TOOL = gnu
KinectStickExample/$(MODE_DIR)/% : TOOL_PATH = 
KinectStickExample/$(MODE_DIR)/% : CC_ARCH_SPEC = -mhard-float -mstrict-align -mno-implicit-fp -DPPC32_fp60x
KinectStickExample/$(MODE_DIR)/% : LIBPATH = 
KinectStickExample/$(MODE_DIR)/% : LIBS = 
KinectStickExample/$(MODE_DIR)/% : OBJ_DIR := KinectStickExample/$(MODE_DIR)

OBJECTS_KinectStickExample = KinectStickExample_partialImage/$(MODE_DIR)/KinectStickExample_partialImage.o

KinectStickExample/$(MODE_DIR)/KinectStickExample.out : $(OBJECTS_KinectStickExample)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@";rm -f "$@";nmppc $(OBJECTS_KinectStickExample) $(IDE_LIBRARIES) | tclsh $(WIND_BASE)/host/resource/hutils/tcl/munch.tcl -c ppc > $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)ccppc $(DEBUGFLAGS_Linker) $(CC_ARCH_SPEC) -fdollars-in-identifiers -Wall $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES)  -o $(OBJ_DIR)/ctdt.o -c $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)ccppc -r -nostdlib -Wl,-X -T $(WIND_BASE)/target/h/tool/gnu/ldscripts/link.OUT -o "$@" $(OBJ_DIR)/ctdt.o $(OBJECTS_KinectStickExample) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS)  $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

KinectStickExample/$(MODE_DIR)/KinectStickExample_compile_file : $(FILE) ;

_clean :: KinectStickExample/$(MODE_DIR)/KinectStickExample_clean

KinectStickExample/$(MODE_DIR)/KinectStickExample_clean : 
	$(TRACE_FLAG)if [ -d "KinectStickExample" ]; then cd "KinectStickExample"; rm -rf $(MODE_DIR); fi


# KinectStickExample_partialImage
ifeq ($(DEBUG_MODE),1)
KinectStickExample_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
KinectStickExample_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
KinectStickExample_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
KinectStickExample_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
KinectStickExample_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
KinectStickExample_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
KinectStickExample_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
KinectStickExample_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
KinectStickExample_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
KinectStickExample_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
KinectStickExample_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
KinectStickExample_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif
KinectStickExample_partialImage/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 
KinectStickExample_partialImage/$(MODE_DIR)/% : IDE_LIBRARIES = 
KinectStickExample_partialImage/$(MODE_DIR)/% : PROJECT_TYPE = DKM
KinectStickExample_partialImage/$(MODE_DIR)/% : DEFINES = 
KinectStickExample_partialImage/$(MODE_DIR)/% : EXPAND_DBG = 0
KinectStickExample_partialImage/$(MODE_DIR)/% : VX_CPU_FAMILY = ppc
KinectStickExample_partialImage/$(MODE_DIR)/% : CPU = PPC32
KinectStickExample_partialImage/$(MODE_DIR)/% : TOOL_FAMILY = gnu
KinectStickExample_partialImage/$(MODE_DIR)/% : TOOL = gnu
KinectStickExample_partialImage/$(MODE_DIR)/% : TOOL_PATH = 
KinectStickExample_partialImage/$(MODE_DIR)/% : CC_ARCH_SPEC = -mhard-float -mstrict-align -mno-implicit-fp -DPPC32_fp60x
KinectStickExample_partialImage/$(MODE_DIR)/% : LIBPATH = 
KinectStickExample_partialImage/$(MODE_DIR)/% : LIBS = 
KinectStickExample_partialImage/$(MODE_DIR)/% : OBJ_DIR := KinectStickExample_partialImage/$(MODE_DIR)

KinectStickExample_partialImage/$(MODE_DIR)/Objects/KinectStickExample/MyRobot.o : C:/WindRiver/FRC2012/KinectStickExample/MyRobot.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


OBJECTS_KinectStickExample_partialImage = KinectStickExample_partialImage/$(MODE_DIR)/Objects/KinectStickExample/MyRobot.o

KinectStickExample_partialImage/$(MODE_DIR)/KinectStickExample_partialImage.o : $(OBJECTS_KinectStickExample_partialImage)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc -r -nostdlib -Wl,-X  -o "$@" $(OBJECTS_KinectStickExample_partialImage) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS)  && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

KinectStickExample_partialImage/$(MODE_DIR)/KinectStickExample_partialImage_compile_file : $(FILE) ;

_clean :: KinectStickExample_partialImage/$(MODE_DIR)/KinectStickExample_partialImage_clean

KinectStickExample_partialImage/$(MODE_DIR)/KinectStickExample_partialImage_clean : 
	$(TRACE_FLAG)if [ -d "KinectStickExample_partialImage" ]; then cd "KinectStickExample_partialImage"; rm -rf $(MODE_DIR); fi

DEP_FILES := KinectStickExample_partialImage/$(MODE_DIR)/Objects/KinectStickExample/MyRobot.d
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
