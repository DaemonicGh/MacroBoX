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

COMMON_FILES			:=	\
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

SOURCE_DIRECTORY		:=	src/
BUILD_DIRECTORY			:=	build/
OBJECT_SUBDIRECTORY		:=	objs/
DEPENDENCY_SUBDIRECTORY	:=	deps/
LOCAL_LIBRARY_DIRECTORY	:=	lib/

SOURCE_EXTENSION		:=	.c
OBJECT_EXTENSION		:=	.o

# ***** OUTPUT ****************

SUCCESS_MESSAGE			=	\
\\033[0;1;2m[\\033[0;1;33m$(call uppercase,$@)\\033[0;1;2m] \
\\033[0;1mCompiled successfully!\\033[0m

DEBUG_SUCCESS_MESSAGE	=	\\033[0;2m(debug)\\033[0m
SANITIZE_SUCCESS_MESSAGE=	\\033[0;2m(sanitized)\\033[0m

# ***** FORMAT ****************

COMPILER				:=	cc
COMPILER_FLAGS			=	-Wall -Wextra -Werror -MMD -MP -MF $(call make_dependency,$@)
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

make_object				=	$(addprefix $(OBJECT_DIRECTORY),$(addsuffix $(OBJECT_EXTENSION), $(basename $1)))
make_dependency			=	$(patsubst $(OBJECT_DIRECTORY)%$(OBJECT_EXTENSION),$(DEPENDENCY_DIRECTORY)%.d,$1)

# ***** PREPROCESS ************

OBJECT_DIRECTORY		:=	$(BUILD_DIRECTORY)$(OBJECT_SUBDIRECTORY)
DEPENDENCY_DIRECTORY	:=	$(BUILD_DIRECTORY)$(DEPENDENCY_SUBDIRECTORY)

COMMON_OBJECTS			:=	$(call make_object,$(COMMON_FILES))
OBJECTS					:=	$(COMMON_OBJECTS)
$(foreach exe,$(NAMES),\
$(eval $(exe)_objects := $(call make_object,$($(exe)_files)))\
$(eval OBJECTS += $($(exe)_objects)))

DEPENDENCIES			:=	$(call make_dependency,$(OBJECTS))

INCLUDES				:=	$(addprefix -I,$(INCLUDE_DIRECTORIES))

LIBRARY_FILES			:=	$(addprefix $(LOCAL_LIBRARY_DIRECTORY),$(LOCAL_LIBRARIES))
LIBRARY_DIRECTORIES		:=	$(dir $(LIBRARY_FILES))
LIB_DIR_FLAGS			:=	$(addprefix -L,$(LIBRARY_DIRECTORIES))
LIB_NAME_FLAGS			:=	$(addprefix -l,$(patsubst lib%,%, $(basename $(notdir $(LOCAL_LIBRARIES)))) $(OTHER_LIBRARIES))
LIB_CLEAN_CALLS			:=	$(patsubst %,$(MAKE) -C % clean;,$(LIBRARY_DIRECTORIES))
LIB_FCLEAN_CALLS		:=	$(patsubst %,$(MAKE) -C % fclean;,$(LIBRARY_DIRECTORIES))

VPATH_WRAP				:=	-Wl,-rpath,'$$ORIGIN/%'
VPATH					:=	$(patsubst %,$(VPATH_WRAP),$(LIBRARY_DIRECTORIES))

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

$(OBJECT_DIRECTORY)%$(OBJECT_EXTENSION): $(SOURCE_DIRECTORY)%$(SOURCE_EXTENSION)
	mkdir -p $(dir $@) $(dir $(call make_dependency,$@))
	$(COMPILER) $(COMPILER_FLAGS) $(INCLUDES) -c $< -o $@

-include $(DEPENDENCIES)

$(LIBRARY_FILES):
		$(MAKE) -C $(dir $@)

clean:
	$(LIB_CLEAN_CALLS)
	rm -rf $(BUILD_DIRECTORY)

fclean:
	$(LIB_FCLEAN_CALLS)
	rm -rf $(BUILD_DIRECTORY)
	rm -f $(LIBRARY_FILES) $(NAMES)

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

$(foreach exe,$(NAMES),$(eval $(call NAMES_RECIPE,$(exe))))

