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
# V5.1

# ***** PROJECT ***************

NAMES					:=	libvec.so

common_files			:=	\
	add/add_d add/add_i add/add_to_d add/add_to_i add/add_to add/add			\
	conv/to_vec conv/to_vec2 conv/to_veci										\
	div/div_d div/div_i div/div_to_d div/div_to_i div/div_to div/div			\
	div/div_vd div/truediv														\
	groups/vecx2 groups/vecx2_xy groups/vecx3 groups/vecx4						\
	linear/cross linear/dist linear/dot linear/length linear/normalize			\
	linear/rotate																\
	math/abs math/eq math/is_zero math/negative math/round math/square			\
	mult/mult_d mult/mult_i mult/mult_to_d mult/mult_to_i mult/mult_to			\
	mult/mult mult/mult_vd														\
	new/from_angle new/new new/new_i new/zero									\
	sub/sub_d sub/sub_i sub/sub_to_d sub/sub_to_i sub/sub_to sub/sub			\
	print/print print/printi

LOCAL_LIBRARIES			:=
OTHER_LIBRARIES			:=	m

INCLUDE_DIRECTORIES		:=	include

# ***** FILE SETTINGS *********

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
\\033[0;1;2m[\\033[0;1;31m$(call uppercase,$1)\\033[0;1;2m] \
\\033[0;1mCompiled successfully!\\033[0m

DEBUG_SUCCESS_MESSAGE		=	\\033[0;2m(debug)\\033[0m
SANITIZE_SUCCESS_MESSAGE	=	\\033[0;2m(sanitized)\\033[0m

SILENT_NAMES				:=

# ***** FORMAT ****************

COMPILER					=	cc
COMPILER_FLAGS				=	-Wall -Wextra -Werror
RELEASE_COMPILER_FLAGS		=	-O3 -flto -march=native -DNDEBUG
DEBUG_COMPILER_FLAGS		=	-O1 -g
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

debug						?=	0
d							?=	$(debug)

sanitize					?=	0
san							?=	$(sanitize)

ifneq ($(sanitize),0)
	debug					:=	1
endif

verbose						?=	0
v							?=	$(verbose)

no-dependencies				?=	0
no-deps						?=	$(no-dependencies)

no-reports					?=	0

hard-reports				?=	0

# ***** MAKE ******************

MAKE						+=	\
d=$(d) san=$(san) v=$(v) no-deps=$(no-deps)\
no-reports=$(no-reports) hard-reports=$(hard-reports)

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
is_not_zero					=	$(filter-out 0,$1)

make_object					=	$(patsubst %,$($1_object_directory)%$(OBJECT_EXTENSION),$(basename $2))
make_dependency				=	$(patsubst $($1_object_directory)%,$($1_dependency_directory)%.d,$(basename $2))
make_report					=	$(patsubst $($1_object_directory)%,$($1_report_directory)%.lst,$(basename $2))
make_hard_report			=	$(patsubst $($1_object_directory)%,$($1_report_directory)%.opt.yaml,$(basename $2))
make_ld_report				=	$(patsubst %,$($1_report_directory)%.lst,$1)
make_hard_ld_report			=	$(patsubst %,$($1_report_directory)%.opt.ld.yaml,$1)
make_hard_ld_report_linker	=	$(patsubst %,$($1_report_directory)%,$1)

# ***** PREPROCESS ************

reports							:=	\
$(if $(or $(call is_zero,$(no-reports)),\
$(call is_not_zero,$(if $(hard-reports),$(hard-reports),1))),1,0)

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
FORCED_LIBRARY_FILES		:=	$(patsubst %,force_%,$(RE_LIBRARIES))

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

ifneq ($(call is_static,$(NAMES))),)
    COMPILER_FLAGS			+=	$(STATIC_COMPILER_FLAGS)
endif
ifneq ($(call is_shared,$(NAMES)),)
    COMPILER_FLAGS			+=	$(SHARED_COMPILER_FLAGS)
endif
ifeq ($(call is_not_static,$(call is_not_shared,$(NAMES))),)
    COMPILER_FLAGS			+=	$(PROGRAM_COMPILER_FLAGS)
endif

$(eval $(LATE_EXEC))

# ***** RECIPES ***************

.PHONY: all $(FORCED_LIBRARY_FILES) clean fclean re lib dist
.NOTPARALLEL: re lib

all: $(NAMES)

-include $(DEPENDENCIES)

$(LIBRARY_FILES):
	$(MAKE) -C $(dir $@) -j

$(FORCED_LIBRARY_FILES):
	$(MAKE) -C $(dir $(patsubst force_%,$(LOCAL_LIBRARY_DIRECTORY)%,$@))

clean:
	$(LIB_CLEAN_CALLS)
	rm -rf $(BUILD_DIRECTORY)

fclean:
	$(LIB_FCLEAN_CALLS)
	rm -rf $(BUILD_DIRECTORY)
	rm -f $(NAMES)

re: fclean all

lib: $(FORCED_LIBRARY_FILES) all

dist:
	$(MAKE) d=0 san=0 no-reports= clean
	$(MAKE) d=0 san=0 no-reports= hard-reports=0 re

# ***** RECIPE MACROS *********

define NAMES_RECIPE
$1: $(LIBRARY_FILES) $(common_objects) $$($1_objects)
	$(if $(call is_static,$1),
		$(STATIC_LINKER) $1 $(common_objects) $($1_objects),

		$(if $(call is_not_zero,$(reports)),
			mkdir -p $($1_report_directory)
		,)

		$(if $(call is_shared,$1),$(SHARED_LINKER),$(PROGRAM_LINKER))\
		$(LINKER_FLAGS) $$(VPATH)\
		$(common_objects) $($1_objects)\
		$(LIB_DIR_FLAGS) $(LIB_NAME_FLAGS) -o $1

		$(if $(call is_zero,$(no-reports)),
			-$(REPORT_BUILDER) $(call make_hard_ld_report,$1) -o\
			$(call make_ld_report,$1,$1) 2>/dev/null

			$(if $(call is_zero,$(hard-reports)),
				rm -f $(call make_hard_ld_report,$1)
			,)
		,)
	)
	$(if $(filter $1, $(SILENT_NAMES)),,
		echo "$(SUCCESS_MESSAGE)"
	)
endef

define OBJECTS_RECIPE
$$($1_object_directory)%$(OBJECT_EXTENSION): $$($1_source_directory)%$(SOURCE_EXTENSION)
	mkdir -p $$(dir $$@)

	$(if $(call is_zero,$(no-deps)),
		mkdir -p $$(dir $$(call make_dependency,$1,$$@))
	,)
	$(if $(call is_not_zero,$(reports)),
		mkdir -p $$(dir $$(call make_report,$1,$$@))
	,)

	$(COMPILER) $(COMPILER_FLAGS) $(INCLUDES) -c $$< -o $$@

	$(if $(call is_zero,$(no-reports)),
		-$(REPORT_BUILDER) $$(call make_hard_report,$1,$$@) -o\
		$$(call make_report,$1,$$@) 2>/dev/null

		$(if $(call is_zero,$(hard-reports)),
			rm -f $$(call make_hard_report,$1,$$@)
		,)
	,)
endef

$(foreach exe,$(NAMES),\
$(eval $(call NAMES_RECIPE,$(exe)))\
$(eval $(call OBJECTS_RECIPE,$(exe))))
