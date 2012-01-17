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
PRJ_ROOT_DIR := C:/WindRiver/FRC2012/Asbestos2012
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

IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h/wrn/coreip 

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
PROJECT_TARGETS = Asbestos2012/$(MODE_DIR)/Asbestos2012.out \
	 Asbestos2012_partialImage/$(MODE_DIR)/Asbestos2012_partialImage.o


#Rules

# Asbestos2012
ifeq ($(DEBUG_MODE),1)
Asbestos2012/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
Asbestos2012/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
Asbestos2012/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
Asbestos2012/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
Asbestos2012/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
Asbestos2012/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
Asbestos2012/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
Asbestos2012/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
Asbestos2012/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
Asbestos2012/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
Asbestos2012/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
Asbestos2012/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif
Asbestos2012/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h/wrn/coreip 
Asbestos2012/$(MODE_DIR)/% : IDE_LIBRARIES = 
Asbestos2012/$(MODE_DIR)/% : PROJECT_TYPE = DKM
Asbestos2012/$(MODE_DIR)/% : DEFINES = 
Asbestos2012/$(MODE_DIR)/% : EXPAND_DBG = 0
Asbestos2012/$(MODE_DIR)/% : VX_CPU_FAMILY = ppc
Asbestos2012/$(MODE_DIR)/% : CPU = PPC32
Asbestos2012/$(MODE_DIR)/% : TOOL_FAMILY = gnu
Asbestos2012/$(MODE_DIR)/% : TOOL = gnu
Asbestos2012/$(MODE_DIR)/% : TOOL_PATH = 
Asbestos2012/$(MODE_DIR)/% : CC_ARCH_SPEC = -mhard-float -mstrict-align -mno-implicit-fp -DPPC32_fp60x
Asbestos2012/$(MODE_DIR)/% : LIBPATH = 
Asbestos2012/$(MODE_DIR)/% : LIBS = 
Asbestos2012/$(MODE_DIR)/% : OBJ_DIR := Asbestos2012/$(MODE_DIR)

OBJECTS_Asbestos2012 = Asbestos2012_partialImage/$(MODE_DIR)/Asbestos2012_partialImage.o

Asbestos2012/$(MODE_DIR)/Asbestos2012.out : $(OBJECTS_Asbestos2012)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@";rm -f "$@";nmppc $(OBJECTS_Asbestos2012) $(IDE_LIBRARIES) | tclsh $(WIND_BASE)/host/resource/hutils/tcl/munch.tcl -c ppc > $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)ccppc $(DEBUGFLAGS_Linker) $(CC_ARCH_SPEC) -fdollars-in-identifiers -Wall $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES)  -o $(OBJ_DIR)/ctdt.o -c $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)ccppc -r -nostdlib -Wl,-X -T $(WIND_BASE)/target/h/tool/gnu/ldscripts/link.OUT -o "$@" $(OBJ_DIR)/ctdt.o $(OBJECTS_Asbestos2012) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS)  $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

Asbestos2012/$(MODE_DIR)/Asbestos2012_compile_file : $(FILE) ;

_clean :: Asbestos2012/$(MODE_DIR)/Asbestos2012_clean

Asbestos2012/$(MODE_DIR)/Asbestos2012_clean : 
	$(TRACE_FLAG)if [ -d "Asbestos2012" ]; then cd "Asbestos2012"; rm -rf $(MODE_DIR); fi


# Asbestos2012_partialImage
ifeq ($(DEBUG_MODE),1)
Asbestos2012_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
Asbestos2012_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
Asbestos2012_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
Asbestos2012_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
Asbestos2012_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
Asbestos2012_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
Asbestos2012_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
Asbestos2012_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
Asbestos2012_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
Asbestos2012_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
Asbestos2012_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
Asbestos2012_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif
Asbestos2012_partialImage/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h/wrn/coreip 
Asbestos2012_partialImage/$(MODE_DIR)/% : IDE_LIBRARIES = 
Asbestos2012_partialImage/$(MODE_DIR)/% : PROJECT_TYPE = DKM
Asbestos2012_partialImage/$(MODE_DIR)/% : DEFINES = 
Asbestos2012_partialImage/$(MODE_DIR)/% : EXPAND_DBG = 0
Asbestos2012_partialImage/$(MODE_DIR)/% : VX_CPU_FAMILY = ppc
Asbestos2012_partialImage/$(MODE_DIR)/% : CPU = PPC32
Asbestos2012_partialImage/$(MODE_DIR)/% : TOOL_FAMILY = gnu
Asbestos2012_partialImage/$(MODE_DIR)/% : TOOL = gnu
Asbestos2012_partialImage/$(MODE_DIR)/% : TOOL_PATH = 
Asbestos2012_partialImage/$(MODE_DIR)/% : CC_ARCH_SPEC = -mhard-float -mstrict-align -mno-implicit-fp -DPPC32_fp60x
Asbestos2012_partialImage/$(MODE_DIR)/% : LIBPATH = 
Asbestos2012_partialImage/$(MODE_DIR)/% : LIBS = 
Asbestos2012_partialImage/$(MODE_DIR)/% : OBJ_DIR := Asbestos2012_partialImage/$(MODE_DIR)

Asbestos2012_partialImage/$(MODE_DIR)/Objects/Asbestos2012/C1983Drive.o : C:/WindRiver/FRC2012/Asbestos2012/C1983Drive.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


Asbestos2012_partialImage/$(MODE_DIR)/Objects/Asbestos2012/PewPewBot.o : C:/WindRiver/FRC2012/Asbestos2012/PewPewBot.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


OBJECTS_Asbestos2012_partialImage = Asbestos2012_partialImage/$(MODE_DIR)/Objects/Asbestos2012/C1983Drive.o \
	 Asbestos2012_partialImage/$(MODE_DIR)/Objects/Asbestos2012/PewPewBot.o

Asbestos2012_partialImage/$(MODE_DIR)/Asbestos2012_partialImage.o : $(OBJECTS_Asbestos2012_partialImage)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc -r -nostdlib -Wl,-X  -o "$@" $(OBJECTS_Asbestos2012_partialImage) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS)  && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

Asbestos2012_partialImage/$(MODE_DIR)/Asbestos2012_partialImage_compile_file : $(FILE) ;

_clean :: Asbestos2012_partialImage/$(MODE_DIR)/Asbestos2012_partialImage_clean

Asbestos2012_partialImage/$(MODE_DIR)/Asbestos2012_partialImage_clean : 
	$(TRACE_FLAG)if [ -d "Asbestos2012_partialImage" ]; then cd "Asbestos2012_partialImage"; rm -rf $(MODE_DIR); fi

DEP_FILES := Asbestos2012_partialImage/$(MODE_DIR)/Objects/Asbestos2012/C1983Drive.d Asbestos2012_partialImage/$(MODE_DIR)/Objects/Asbestos2012/PewPewBot.d
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
