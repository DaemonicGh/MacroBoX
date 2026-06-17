# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rprieur <rprieur@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/24 19:51:36 by rprieur           #+#    #+#              #
#    Updated: 2026/02/21 00:14:39 by rprieur          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# V5.3

# ***** PROJECT ***************

NAMES						:=	libmbx.so libmbx.a

app_files					:=	\
	exit init/app init/values init/window										\
	loop/loop loop/start_end													\

drawing_files				:=	\
	clear rect region subregion_scaled line render text							\
	pixel/get pixel/get_raw pixel/get_unsafe									\
	pixel/set pixel/set_raw pixel/set_unsafe pixel/tools						\
	color/average color/blend color/math color/new								\
	color/vec4/create color/vec4/blend											\

handlers_files				:=	\
	image screen settings viewport window window_extras							\
	allocator/alloc allocator/extras allocator/free								\
	region/atlas region/create region/create_ext region/extras region/pipeline	\

inputs_files				:=	\
	btn check cursor events keyboard press										\
	events/keyboard events/mouse events/window									\

utils_files					:=	\
	random time																	\
	math/clamp math/dist_to_range math/easing math/easing_special math/fract	\
	math/is_integer math/lerp math/minmax math/move_towards math/sign			\
	math/trunc math/wrap														\
	vector/clamp vector/sign vector/len_clamp vector/len_move_towards			\

libmbx.so_files				:=	\
	$(addprefix app/,		$(app_files))			\
	$(addprefix drawing/,	$(drawing_files))		\
	$(addprefix handlers/,	$(handlers_files))		\
	$(addprefix inputs/,	$(inputs_files))		\
	$(addprefix utils/,		$(utils_files))			\
	_private/time _private/write_utils

libmbx.a_files				:=	$(libmbx.so_files)

common_files				:=	$(shell $(MAKE) -pC lib/VecLibC | sed -n 's/^common_files :=//p')

INCLUDE_DIRECTORIES			:=	include \
	lib/MacroLibX/includes lib/VecLibC/include

LOCAL_LIBRARIES				:=	MacroLibX/libmlx.so VecLibC/libvec.so
NO_REBUILD_LIBRARIES		:=	MacroLibX/libmlx.so
GIT_LIBRARIES				:=	MacroLibX
OTHER_LIBRARIES				:=	m SDL2

# ***** FILE SETTINGS *********

common_source_directory		:=	lib/VecLibC/src/
common_build_directory		:=	lib/VecLibC/build/

SOURCE_DIRECTORY			:=	src/
BUILD_DIRECTORY				:=	build/
OBJECT_SUBDIRECTORY			:=	objs/
DEPENDENCY_SUBDIRECTORY		:=	deps/
REPORT_SUBDIRECTORY			:=	reports/
LOCAL_LIBRARY_DIRECTORY		:=	lib/

SOURCE_EXTENSION			:=	.c
OBJECT_EXTENSION			:=	.o

# ***** OUTPUT ****************

SUCCESS_MESSAGE				=	\
\\033[0;1;2m[\\033[0;1;31mMacroBoX\\033[0;1;2m] \
\\033[0;1mCompiled successfully!\\033[0m

DEBUG_SUCCESS_MESSAGE		=	\\033[0;2m(debug)\\033[0m
SANITIZE_SUCCESS_MESSAGE	=	\\033[0;2m(sanitized)\\033[0m

SILENT_NAMES				:=	libmbx.a

# ***** FORMAT ****************

COMPILER					=	cc
COMPILER_FLAGS				=	-Wall -Wextra -Werror
RELEASE_COMPILER_FLAGS		=	-O3 -flto -march=native -DNDEBUG
DEBUG_COMPILER_FLAGS		=	-O1 -g -DMBX_DEBUG=1
SANITIZE_COMPILER_FLAGS		=	-fsanitize=address -fsanitize=leak -fno-omit-frame-pointer

LINKER_FLAGS				=
RELEASE_LINKER_FLAGS		=	-flto
DEBUG_LINKER_FLAGS			=
SANITIZE_LINKER_FLAGS		=	-fsanitize=address -fsanitize=leak

PROGRAM_LINKER				=	cc
PROGRAM_COMPILER_FLAGS		=

SHARED_LINKER				=	cc -shared
SHARED_COMPILER_FLAGS		=	-fPIC

STATIC_LINKER				=	ar -rcs
STATIC_COMPILER_FLAGS		=

REPORT_BUILDER				:=	llvm-opt-report-14

# ***** COMMAND VARIABLES *****

sanitize					?=	0
san							?=	$(sanitize)

debug						?=	$(san)
d							?=	$(debug)

reports						?=	$(d)

force						?=	0
f							?=	$(force)

verbose						?=	0
v							?=	$(verbose)

no-dependencies				?=	0
no-deps						?=	$(no-dependencies)

# ***** MAKE ******************

MAKE						+=	\
d=$(d) san=$(san) f=$(f) v=$(v) no-deps=$(no-deps) reports=$(reports)

ifeq ($(v),0)
	MAKEFLAGS				+=	--silent
endif

# ***** UTILS *****************

uppercase					=	$(shell echo "$1" | tr '[:lower:]' '[:upper:]')
lowercase					=	$(shell echo "$1" | tr '[:upper:]' '[:lower:]')
capitalize					=	$(shell echo "$1" | sed 's/./\U&/')

is_shared 					=	$(filter %.so,$1)
is_static					=	$(filter %.a,$1)
is_not_shared 				=	$(filter-out %.so,$1)
is_not_static				=	$(filter-out %.a,$1)
is_zero						=	$(filter 0,$1)
is_not_zero					=	$(filter-out 0,$(if $1,$1,1))

make_object					=	$(patsubst %,$($1_object_directory)%$(OBJECT_EXTENSION),$(basename $2))
make_dependency				=	$(patsubst $($1_object_directory)%,$($1_dependency_directory)%.d,$(basename $2))
make_report					=	$(patsubst $($1_object_directory)%,$($1_report_directory)%.lst,$(basename $2))
make_hard_report			=	$(patsubst $($1_object_directory)%,$($1_report_directory)%.opt.yaml,$(basename $2))
make_ld_report				=	$(patsubst %,$($1_report_directory)%.lst,$1)
make_hard_ld_report			=	$(patsubst %,$($1_report_directory)%.opt.ld.yaml,$1)
make_hard_ld_report_linker	=	$(patsubst %,$($1_report_directory)%,$1)

get_lib_subfolder			=	$(patsubst $(LOCAL_LIBRARY_DIRECTORY)%/,%,$(dir $1))

# ***** PREPROCESS ************

define NAME_BUILDER
$1_source_directory				?=	$(SOURCE_DIRECTORY)
$1_build_directory				?=	$(BUILD_DIRECTORY)
$1_object_subdirectory			?=	$(OBJECT_SUBDIRECTORY)

$1_object_directory				:=	$$($1_build_directory)$$($1_object_subdirectory)
$1_objects						:=	$$(call make_object,$1,$$($1_files))
OBJECTS							+=	$$($1_objects)

ifeq ($(no-deps),0)
	$1_dependency_subdirectory	?=	$(DEPENDENCY_SUBDIRECTORY)
	$1_dependency_directory		:=	$$($1_build_directory)$$($1_dependency_subdirectory)
	$1_dependencies				:=	$$(call make_dependency,$1,$$($1_objects))
	DEPENDENCIES				+=	$$($1_dependencies)
endif

ifneq ($(reports),0)
	$1_report_subdirectory		?=	$(REPORT_SUBDIRECTORY)
	$1_report_directory			:=	$$($1_build_directory)$$($1_report_subdirectory)
endif
endef

OBJECTS						:=
DEPENDENCIES				:=

$(foreach exe,common $(NAMES),$(eval $(call NAME_BUILDER,$(exe))))

INCLUDES					:=	$(addprefix -I,$(INCLUDE_DIRECTORIES))

LIBRARY_FILES				:=	$(addprefix $(LOCAL_LIBRARY_DIRECTORY),$(LOCAL_LIBRARIES))
LIBRARY_DIRECTORIES			:=	$(dir $(LIBRARY_FILES))

RE_LIBRARIES				:=	$(filter-out $(NO_REBUILD_LIBRARIES),$(LOCAL_LIBRARIES))
RE_LIBRARY_FILES			:=	$(addprefix $(LOCAL_LIBRARY_DIRECTORY),$(RE_LIBRARIES))
RE_LIBRARY_DIRECTORIES		:=	$(dir $(RE_LIBRARY_FILES))

LIB_DIR_FLAGS				:=	$(addprefix -L,$(LIBRARY_DIRECTORIES))
LIB_NAME_FLAGS				:=	$(addprefix -l,$(patsubst lib%,%,$(basename $(notdir $(LOCAL_LIBRARIES)))) $(OTHER_LIBRARIES))
LIB_CLEAN_CALLS				:=	$(patsubst %,$(MAKE) -C % clean;,$(RE_LIBRARY_DIRECTORIES))
LIB_FCLEAN_CALLS			:=	$(patsubst %,$(MAKE) -C % fclean;,$(RE_LIBRARY_DIRECTORIES))

VPATH_WRAP					:=	-Wl,-rpath,'$$ORIGIN/%'
VPATH						:=	$(patsubst %,$(VPATH_WRAP),$(LIBRARY_DIRECTORIES))

# ***** STATIC CONDITIONS *****

ifeq ($(no-deps),0)
	COMPILER_FLAGS			+=	-MMD -MP -MF $$(call make_dependency,$1,$$@)
endif

ifneq ($(reports),0)
	COMPILER_FLAGS			+=	-fsave-optimization-record -foptimization-record-file=$$(call make_hard_report,$1,$$@)
	PROGRAM_LINKER			+=	-fsave-optimization-record -foptimization-record-file=$$(call make_hard_ld_report_linker,$1)
	SHARED_LINKER			+=	-fsave-optimization-record -foptimization-record-file=$$(call make_hard_ld_report_linker,$1)
endif

ifneq ($(d),0)
	COMPILER_FLAGS			+=	$(DEBUG_COMPILER_FLAGS)
	LINKER_FLAGS			+=	$(DEBUG_LINKER_FLAGS)
	SUCCESS_MESSAGE			+=	$(DEBUG_SUCCESS_MESSAGE)
else
	COMPILER_FLAGS			+=	$(RELEASE_COMPILER_FLAGS)
	LINKER_FLAGS			+=	$(RELEASE_LINKER_FLAGS)
	SUCCESS_MESSAGE			+=	$(RELEASE_SUCCESS_MESSAGE)
endif

ifneq ($(san),0)
	COMPILER_FLAGS			+=	$(SANITIZE_COMPILER_FLAGS)
	LINKER_FLAGS			+=	$(SANITIZE_LINKER_FLAGS)
	SUCCESS_MESSAGE			+=	$(SANITIZE_SUCCESS_MESSAGE)
endif

ifneq ($(f), 0)
	FORCE					:=	FORCE
endif

ifneq ($(call is_static,$(NAMES))),)
    COMPILER_FLAGS			+=	$(STATIC_COMPILER_FLAGS)
endif
ifneq ($(call is_shared,$(NAMES)),)
    COMPILER_FLAGS			+=	$(SHARED_COMPILER_FLAGS)
endif
ifeq ($(call is_not_static,$(call is_not_shared,$(NAMES))),)
    COMPILER_FLAGS			+=	$(PROGRAM_COMPILER_FLAGS)
endif

# ***** PRE-EXEC **************

$(eval $(LATE_EXEC))

# ***** RECIPES ***************

.PHONY: all clean fclean re lib dist
.NOTPARALLEL: re

all: $(NAMES)

FORCE:

-include $(DEPENDENCIES)

$(LIBRARY_FILES): $(FORCE)
	$(if $(filter $(call get_lib_subfolder,$@),$(GIT_LIBRARIES)),\
		git submodule update --init --recursive $(dir $@)\
	,)
	$(MAKE) f=0 -C $(dir $@) -j

clean:
	$(LIB_CLEAN_CALLS)
	rm -rf $(BUILD_DIRECTORY)

fclean:
	$(LIB_FCLEAN_CALLS)
	rm -rf $(BUILD_DIRECTORY)
	rm -f $(NAMES)

re: fclean all

lib:
	$(MAKE) f=1 $(LIBRARY_FILES)
	$(MAKE) all

dist:
	$(MAKE) d=0 san=0 reports=0 re
	$(MAKE) d=0 san=0 reports=0 clean

# ***** RECIPE MACROS *********

define NAMES_RECIPE
$1: $(LIBRARY_FILES) $(common_objects) $$($1_objects) $(FORCE)
	$(if $(call is_static,$1),
		$(STATIC_LINKER) $1 $(common_objects) $($1_objects),

		$(if $(call is_not_zero,$(reports)),
			mkdir -p $($1_report_directory)
		,)

		$(if $(call is_shared,$1),$(SHARED_LINKER),$(PROGRAM_LINKER))\
		$(LINKER_FLAGS) $$(VPATH) $(common_objects) $($1_objects)\
		$(LIB_DIR_FLAGS) $(LIB_NAME_FLAGS) -o $1

		$(if $(call is_not_zero,$(reports)),
			-$(REPORT_BUILDER) $(call make_hard_ld_report,$1) -o\
			$(call make_ld_report,$1,$1)\
			$(if $(call is_zero,$(v)),2>/dev/null,)
		,)
	)
	$(if $(filter $1, $(SILENT_NAMES)),,
		echo "$(SUCCESS_MESSAGE)"
	)
endef

define OBJECTS_RECIPE
$$($1_object_directory)%$(OBJECT_EXTENSION): $$($1_source_directory)%$(SOURCE_EXTENSION) $(FORCE)
	mkdir -p $$(dir $$@)

	$(if $(call is_zero,$(no-deps)),
		mkdir -p $$(dir $$(call make_dependency,$1,$$@))
	,)
	$(if $(call is_not_zero,$(reports)),
		mkdir -p $$(dir $$(call make_report,$1,$$@))
	,)

	$(COMPILER) $(COMPILER_FLAGS) $(INCLUDES) -c $$< -o $$@

	$(if $(call is_not_zero,$(no-reports)),
		-$(REPORT_BUILDER) $$(call make_hard_report,$1,$$@) -o\
		$$(call make_report,$1,$$@)\
		$(if $(call is_zero,$(v)),2>/dev/null,)
	,)
endef

$(foreach exe,$(NAMES),\
$(eval $(call NAMES_RECIPE,$(exe)))\
$(eval $(call OBJECTS_RECIPE,$(exe))))
