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

BUILD_SPEC = PPC32diab
DEBUG_MODE = 1
ifeq ($(DEBUG_MODE),1)
MODE_DIR := Debug
else
MODE_DIR := NonDebug
endif
OBJ_DIR := .
PRJ_ROOT_DIR := C:/WindRiver/FRC2011/LogoBot
WS_ROOT_DIR := C:/WindRiver/FRC2011



#Global Build Macros
PROJECT_TYPE = DKM
DEFINES = 
EXPAND_DBG = 0


#BuildSpec specific Build Macros
VX_CPU_FAMILY = ppc
CPU = PPC32
TOOL_FAMILY = diab
TOOL = diab
TOOL_PATH = 
CC_ARCH_SPEC = -tPPCFH:vxworks63 -Xstmw-slow -DPPC32_fp60x
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
DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
DEBUGFLAGS_Linker = -XO -Xsize-opt
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif


#Project Targets
PROJECT_TARGETS = LogoBot/$(MODE_DIR)/LogoBot.out \
	 LogoBot_partialImage/$(MODE_DIR)/LogoBot_partialImage.o


#Rules

# LogoBot
ifeq ($(DEBUG_MODE),1)
LogoBot/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
LogoBot/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
LogoBot/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
LogoBot/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
LogoBot/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
LogoBot/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
LogoBot/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
LogoBot/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
LogoBot/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -XO -Xsize-opt
LogoBot/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
LogoBot/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
LogoBot/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif
LogoBot/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 
LogoBot/$(MODE_DIR)/% : IDE_LIBRARIES = 
LogoBot/$(MODE_DIR)/% : PROJECT_TYPE = DKM
LogoBot/$(MODE_DIR)/% : DEFINES = 
LogoBot/$(MODE_DIR)/% : EXPAND_DBG = 0
LogoBot/$(MODE_DIR)/% : VX_CPU_FAMILY = ppc
LogoBot/$(MODE_DIR)/% : CPU = PPC32
LogoBot/$(MODE_DIR)/% : TOOL_FAMILY = diab
LogoBot/$(MODE_DIR)/% : TOOL = diab
LogoBot/$(MODE_DIR)/% : TOOL_PATH = 
LogoBot/$(MODE_DIR)/% : CC_ARCH_SPEC = -tPPCFH:vxworks63 -Xstmw-slow -DPPC32_fp60x
LogoBot/$(MODE_DIR)/% : LIBPATH = 
LogoBot/$(MODE_DIR)/% : LIBS = 
LogoBot/$(MODE_DIR)/% : OBJ_DIR := LogoBot/$(MODE_DIR)

OBJECTS_LogoBot = LogoBot_partialImage/$(MODE_DIR)/LogoBot_partialImage.o

LogoBot/$(MODE_DIR)/LogoBot.out : $(OBJECTS_LogoBot)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@";rm -f "$@";ddump -Ng $(OBJECTS_LogoBot) $(IDE_LIBRARIES) | tclsh $(WIND_BASE)/host/resource/hutils/tcl/munch.tcl -c ppc > $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)dcc $(DEBUGFLAGS_Linker) $(CC_ARCH_SPEC) -Xdollar-in-ident -Xforce-declarations $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES)  -o $(OBJ_DIR)/ctdt.o -c $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)dld -tPPCFH:vxworks63 -X -r5 -r4 -o "$@" $(OBJ_DIR)/ctdt.o $(OBJECTS_LogoBot) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS)  $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

LogoBot/$(MODE_DIR)/LogoBot_compile_file : $(FILE) ;

_clean :: LogoBot/$(MODE_DIR)/LogoBot_clean

LogoBot/$(MODE_DIR)/LogoBot_clean : 
	$(TRACE_FLAG)if [ -d "LogoBot" ]; then cd "LogoBot"; rm -rf $(MODE_DIR); fi


# LogoBot_partialImage
ifeq ($(DEBUG_MODE),1)
LogoBot_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
LogoBot_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
LogoBot_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
LogoBot_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
LogoBot_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
LogoBot_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
LogoBot_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
LogoBot_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
LogoBot_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -XO -Xsize-opt
LogoBot_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
LogoBot_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
LogoBot_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif
LogoBot_partialImage/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 
LogoBot_partialImage/$(MODE_DIR)/% : IDE_LIBRARIES = 
LogoBot_partialImage/$(MODE_DIR)/% : PROJECT_TYPE = DKM
LogoBot_partialImage/$(MODE_DIR)/% : DEFINES = 
LogoBot_partialImage/$(MODE_DIR)/% : EXPAND_DBG = 0
LogoBot_partialImage/$(MODE_DIR)/% : VX_CPU_FAMILY = ppc
LogoBot_partialImage/$(MODE_DIR)/% : CPU = PPC32
LogoBot_partialImage/$(MODE_DIR)/% : TOOL_FAMILY = diab
LogoBot_partialImage/$(MODE_DIR)/% : TOOL = diab
LogoBot_partialImage/$(MODE_DIR)/% : TOOL_PATH = 
LogoBot_partialImage/$(MODE_DIR)/% : CC_ARCH_SPEC = -tPPCFH:vxworks63 -Xstmw-slow -DPPC32_fp60x
LogoBot_partialImage/$(MODE_DIR)/% : LIBPATH = 
LogoBot_partialImage/$(MODE_DIR)/% : LIBS = 
LogoBot_partialImage/$(MODE_DIR)/% : OBJ_DIR := LogoBot_partialImage/$(MODE_DIR)

OBJECTS_LogoBot_partialImage =

LogoBot_partialImage/$(MODE_DIR)/LogoBot_partialImage.o : $(OBJECTS_LogoBot_partialImage)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dld -tPPCFH:vxworks63 -X -r5  -o "$@" $(OBJECTS_LogoBot_partialImage) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS)  && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

LogoBot_partialImage/$(MODE_DIR)/LogoBot_partialImage_compile_file : $(FILE) ;

_clean :: LogoBot_partialImage/$(MODE_DIR)/LogoBot_partialImage_clean

LogoBot_partialImage/$(MODE_DIR)/LogoBot_partialImage_clean : 
	$(TRACE_FLAG)if [ -d "LogoBot_partialImage" ]; then cd "LogoBot_partialImage"; rm -rf $(MODE_DIR); fi



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
