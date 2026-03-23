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
# V5.2

# ***** PROJECT ***************

NAMES					:=	libvec.so libmbx.so

libmbx.so_files			:=	\
	app/loop/in_out app/loop/loop app/loop/start_end							\
	app/exit app/init															\
	color/blend color/math color/new											\
	drawing/clear drawing/rect drawing/region drawing/region_scaled				\
	drawing/line drawing/text 													\
	drawing/pixel/get drawing/pixel/get_unsafe drawing/pixel/set				\
	drawing/pixel/raw drawing/pixel/tools drawing/pixel/set_unsafe				\
	handlers/font handlers/image handlers/region handlers/screen				\
	handlers/settings handlers/viewport handlers/window handlers/window_extras	\
	inputs/btn inputs/check inputs/cursor inputs/events inputs/press			\
	inputs/events/keyboard inputs/events/mouse inputs/events/window				\
	math/clamp math/dist_to_range math/is_integer math/lerp math/minmax			\
	math/move_towards math/sign math/trunc_up math/wrap 						\
	math/vector/len_clamp math/vector/len_move_towards math/vector/sign			\
	_private/time

libvec.so_files			:=	\
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

LOCAL_LIBRARIES			:=	MacroLibX-2.2.2/libmlx.so
NO_REBUILD_LIBRARIES	:=	MacroLibX-2.2.2/libmlx.so
OTHER_LIBRARIES			:=	m SDL2

INCLUDE_DIRECTORIES		:=	include \
	lib/MacroLibX-2.2.2/includes lib/VecLibC/include

# ***** FILE SETTINGS *********

libvec.so_source_directory	:=	lib/VecLibC/src/
libvec.so_build_directory	:=	lib/VecLibC/build/

SOURCE_DIRECTORY		:=	src/
BUILD_DIRECTORY			:=	build/
OBJECT_SUBDIRECTORY		:=	objs/
DEPENDENCY_SUBDIRECTORY	:=	deps/
LOCAL_LIBRARY_DIRECTORY	:=	lib/

SOURCE_EXTENSION		:=	.c
OBJECT_EXTENSION		:=	.o

define LATE_EXEC
	libmbx.so_objects += $$(libvec.so_objects)
endef

# ***** OUTPUT ****************

SUCCESS_MESSAGE			=	\
\\033[0;1;2m[\\033[0;1;31m$(call uppercase,$@)\\033[0;1;2m] \
\\033[0;1mCompiled successfully!\\033[0m

DEBUG_SUCCESS_MESSAGE	=	\\033[0;2m(debug)\\033[0m
SANITIZE_SUCCESS_MESSAGE=	\\033[0;2m(sanitized)\\033[0m

# ***** FORMAT ****************

COMPILER				:=	cc
COMPILER_FLAGS			=	-Wall -Wextra -Werror -MMD -MP -MF $(call make_dependency,$($1_object_directory),$($1_dependency_directory),$@)
RELEASE_COMPILER_FLAGS	=	-O3 -flto -march=native -DNDEBUG
DEBUG_COMPILER_FLAGS	=	-O1 -g
SANITIZE_COMPILER_FLAGS	=	-fsanitize=address -fsanitize=leak -fno-omit-frame-pointer

LINKER_FLAGS			=
RELEASE_LINKER_FLAGS	=	-flto
DEBUG_LINKER_FLAGS		=
SANITIZE_LINKER_FLAGS	=	-fsanitize=address -fsanitize=leak

PROGRAM_LINKER			:=	cc
PROGRAM_COMPILER_FLAGS	=

SHARED_LINKER			:=	cc -shared
SHARED_COMPILER_FLAGS	=	-fPIC

STATIC_LINKER			:=	ar -rcs
STATIC_COMPILER_FLAGS	=

# ***** COMMAND VARIABLES *****

d						?=	0
debug					?=	$(d)

san						?=	0
sanitize				?=	$(san)

v						?=	0
verbose					?=	$(v)

ifneq ($(sanitize),0)
	debug				:=	1
endif

# ***** MAKE ******************

MAKE					+=	debug=$(debug) sanitize=$(sanitize) verbose=$(verbose)

ifeq ($(verbose),0)
	MAKEFLAGS			+=	--silent
endif

# ***** UTILS *****************

uppercase				=	$(shell echo "$1" | tr '[:lower:]' '[:upper:]')
lowercase				=	$(shell echo "$1" | tr '[:upper:]' '[:lower:]')
capitalize				=	$(shell echo "$1" | sed 's/./\U&/')

is_shared 				=	$(filter %.so,$1)
is_static				=	$(filter %.a,$1)
is_not_shared 			=	$(filter-out %.so,$1)
is_not_static			=	$(filter-out %.a,$1)

make_object				=	$(addprefix $1,$(addsuffix $(OBJECT_EXTENSION), $(basename $2)))
make_dependency			=	$(patsubst $1%$(OBJECT_EXTENSION),$2%.d,$3)

# ***** PREPROCESS ************

$(foreach exe,$(NAMES),$(eval \
$(exe)_source_directory ?= $(SOURCE_DIRECTORY)))
$(foreach exe,$(NAMES),$(eval \
$(exe)_build_directory ?= $(BUILD_DIRECTORY)))
$(foreach exe,$(NAMES),$(eval \
$(exe)_object_subdirectory ?= $(OBJECT_SUBDIRECTORY)))
$(foreach exe,$(NAMES),$(eval \
$(exe)_dependency_subdirectory ?= $(DEPENDENCY_SUBDIRECTORY)))

$(foreach exe,$(NAMES),$(eval \
$(exe)_object_directory := $($(exe)_build_directory)$($(exe)_object_subdirectory)))
$(foreach exe,$(NAMES),$(eval \
$(exe)_dependency_directory := $($(exe)_build_directory)$($(exe)_dependency_subdirectory)))

$(foreach exe,$(NAMES),$(eval \
$(exe)_objects := $(call make_object,$($(exe)_object_directory),$($(exe)_files))))
$(foreach exe,$(NAMES),$(eval \
$(exe)_dependencies := $(call make_dependency,$($($(exe)_object_directory),$($(exe)_dependency_directory),$(exe)_objects))))

COMMON_OBJECTS			:=	$(call make_object,$(COMMON_FILES))
OBJECTS					:=	$(COMMON_OBJECTS)

$(foreach exe,$(NAMES),$(eval \
OBJECTS += $($(exe)_objects)))

DEPENDENCIES			:=	$(call make_dependency,$(OBJECT_DIRECTORY),$(DEPENDENCY_DIRECTORY),$(COMMON_OBJECTS))

$(foreach exe,$(NAMES),$(eval \
DEPENDENCIES += $($(exe)_dependecies)))

INCLUDES				:=	$(addprefix -I,$(INCLUDE_DIRECTORIES))

LIBRARY_FILES			:=	$(addprefix $(LOCAL_LIBRARY_DIRECTORY),$(LOCAL_LIBRARIES))
LIBRARY_DIRECTORIES		:=	$(dir $(LIBRARY_FILES))

RE_LIBRARIES			:=	$(filter-out $(NO_REBUILD_LIBRARIES),$(LOCAL_LIBRARIES))
RE_LIBRARY_FILES		:=	$(addprefix $(LOCAL_LIBRARY_DIRECTORY),$(RE_LIBRARIES))
RE_LIBRARY_DIRECTORIES	:=	$(dir $(RE_LIBRARY_FILES))

LIB_DIR_FLAGS			:=	$(addprefix -L,$(LIBRARY_DIRECTORIES))
LIB_NAME_FLAGS			:=	$(addprefix -l,$(patsubst lib%,%, $(basename $(notdir $(LOCAL_LIBRARIES)))) $(OTHER_LIBRARIES))
LIB_CLEAN_CALLS			:=	$(patsubst %,$(MAKE) -C % clean;,$(RE_LIBRARY_DIRECTORIES))
LIB_FCLEAN_CALLS		:=	$(patsubst %,$(MAKE) -C % fclean;,$(RE_LIBRARY_DIRECTORIES))

VPATH_WRAP				:=	-Wl,-rpath,'$$ORIGIN/%'
VPATH					:=	$(patsubst %,$(VPATH_WRAP),$(LIBRARY_DIRECTORIES))

$(eval $(LATE_EXEC))

# ***** STATIC CONDITIONS *****

ifneq ($(debug),0)
	COMPILER_FLAGS		+=	$(DEBUG_COMPILER_FLAGS)
	LINKER_FLAGS		+=	$(DEBUG_LINKER_FLAGS)
	SUCCESS_MESSAGE		+=	$(DEBUG_SUCCESS_MESSAGE)
else
	COMPILER_FLAGS		+=	$(RELEASE_COMPILER_FLAGS)
	LINKER_FLAGS		+=	$(RELEASE_LINKER_FLAGS)
	SUCCESS_MESSAGE		+=	$(RELEASE_SUCCESS_MESSAGE)
endif

ifneq ($(sanitize),0)
	COMPILER_FLAGS		+=	$(SANITIZE_COMPILER_FLAGS_COMPILER_FLAGS)
	LINKER_FLAGS		+=	$(SANITIZE_LINKER_FLAGS)
	SUCCESS_MESSAGE		+=	$(SANITIZE_SUCCESS_MESSAGE)
endif

ifneq ($(patsubst %.so,%,$(NAMES)), $(NAMES))
    COMPILER_FLAGS		+=	$(SHARED_COMPILER_FLAGS)
else ifneq ($(patsubst %.a,%,$(NAMES))), $(NAMES))
    COMPILER_FLAGS		+=	$(STATIC_COMPILER_FLAGS)
else
    COMPILER_FLAGS		+=	$(PROGRAM_COMPILER_FLAGS)
endif

# ***** RUNTIME ***************

select_linker			=	$(if $(call is_shared,$1),\
							$(SHARED_LINKER),$(if $(call is_static,$1),\
							$(STATIC_LINKER),$(PROGRAM_LINKER)))

select_link_command		=	$(if $(call is_static,$@),\
							$(call select_linker, $@) $@ $(OBJECTS),\
							$(call select_linker, $@) $(LINKER_FLAGS) $(VPATH)\
							$(COMMON_OBJECTS) $($@_objects)\
							$(LIB_DIR_FLAGS) $(LIB_NAME_FLAGS) -o $@)

# ***** RECIPES ***************

.PHONY: all clean fclean re dist
.NOTPARALLEL: re

all: $(NAMES)

-include $(DEPENDENCIES)

$(LIBRARY_FILES):
	$(MAKE) -C $(dir $@) -j

clean:
	$(LIB_CLEAN_CALLS)
	rm -rf $(BUILD_DIRECTORY)

fclean:
	$(LIB_FCLEAN_CALLS)
	rm -rf $(BUILD_DIRECTORY)
	rm -f $(NAMES)

re: fclean all

dist:
	$(MAKE) debug=0 sanitize=0 re
	$(MAKE) debug=0 sanitize=0 clean

# ***** RECIPE MACROS *********

define NAMES_RECIPE
$1: $(LIBRARY_FILES) $(COMMON_OBJECTS) $$($1_objects)
	$$(select_link_command)
	@echo "$$(SUCCESS_MESSAGE)"
endef

define OBJECTS_RECIPE
$$($1_object_directory)%$(OBJECT_EXTENSION): $$($1_source_directory)%$(SOURCE_EXTENSION)
	mkdir -p $$(dir $$@) $$(dir $$(call make_dependency,$($1_object_directory),$($1_dependency_directory),$$@))
	$(COMPILER) $$(COMPILER_FLAGS) $(INCLUDES) -c $$< -o $$@
endef

$(foreach exe,$(NAMES),$(eval $(call NAMES_RECIPE,$(exe))))
$(foreach exe,$(NAMES),$(eval $(call OBJECTS_RECIPE,$(exe))))
