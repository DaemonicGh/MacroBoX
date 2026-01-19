# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daemo <daemo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/24 19:51:36 by rprieur           #+#    #+#              #
#    Updated: 2026/01/02 20:11:02 by daemo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKE = make --no-print-directory

CC := cc
CFLAGS := -Wall -Wextra -Werror -fPIC -g -O2 -march=native -flto -DNDEBUG

NAME := libmbx.so

LIB := -LMacroLibX-2.2.2 -lmlx \
       -Wl,-rpath,'$$ORIGIN/MacroLibX-2.2.2' \
       -lSDL2 -lm

SRCF :=	mouse screen \
		types/color types/font types/image types/settings types/region types/window \
		app/draw_viewport app/exit app/init app/loop app/loop_start app/loop_end \
		drawing/clear drawing/get_pixel drawing/rect drawing/region drawing/region_scaled \
		drawing/line drawing/set_pixel drawing/set_pixel_raw drawing/set_pixel_tools \
		drawing/set_pixel_unsafe drawing/text drawing/subregion_scaled \
		inputs/check inputs/press inputs/special \
		inputs/events/events inputs/events/keyboard inputs/events/mouse inputs/events/window \
		math/clamp math/is_integer math/move_towards math/lerp math/wrap math/minmax math/sign \
		utils/bsign utils/palloc utils/time

VECF := add/add_d add/add_i add/add_to_d add/add_to_i add/add_to add/add \
		conv/to_vec conv/to_veci \
		div/div_d div/div_i div/div_to_d div/div_to_i div/div_to div/div \
		groups/vecx2 groups/vecx2_xy groups/vecx3 groups/vecx4 \
		linear/cross linear/dist linear/dot linear/length linear/normalize linear/rotate \
		math/abs math/eq math/is_zero math/negative math/round math/square\
		mult/mult_d mult/mult_i mult/mult_to_d mult/mult_to_i mult/mult_to mult/mult \
		new/implicit_new new/new new/zero \
		sub/sub_d sub/sub_i sub/sub_to_d sub/sub_to_i sub/sub_to sub/sub \
		print/print print/printi

SRCDIR := src/
VECDIR := VecLibC/src/
OBJDIR := objs/
HDR    := includes/

VEC := $(addprefix $(VECDIR), $(addsuffix .c, $(VECF)))

SRC := $(addprefix $(SRCDIR), $(addsuffix .c, $(SRCF)))
SRC += $(VEC)

OBJ := $(patsubst %.c, $(OBJDIR)%.o, $(SRC))

# **************************************************************************** #

all: $(NAME)

$(NAME): lib $(OBJ)
	@$(CC) -shared -o $(NAME) $(OBJ) $(LIB)
	@echo "\033[1mMacroBoX Compiled Successfully!\033[0m"

$(OBJDIR)%.o: %.c | $(OBJDIR)
	@mkdir -p $(dir $@)
	@$(CC) -c $(CFLAGS) -I $(HDR) $< -o $@

$(OBJDIR):
	@mkdir $(OBJDIR)

clean:
	@rm -f $(OBJ)
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

lib:
	@$(MAKE) -C MacroLibX-2.2.2 -j

norm:
	@-norminette $(SRC) $(HDR)**

.PHONY: all clean fclean re lib norm
