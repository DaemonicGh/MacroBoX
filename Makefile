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

CC := cc
CFLAGS := -shared -o
OBJFLAGS := -Wall -Wextra -Werror -fPIC -g

NAME := libmbx.so

LIB := MacroLibX-2.2.2/libmlx.so
LIBFLAGS := -lSDL2 -lm

SRCF :=	color draw_viewport exit font image init loop_end loop_start loop \
		mouse screen settings region window \
		drawing/clear drawing/get_pixel drawing/rect drawing/region drawing/line \
		drawing/set_pixel drawing/text \
		events/events events/keyboard events/mouse events/window \
		math/clamp math/conv math/lerp math/loop math/minmax math/sign \
		utils/bsign utils/palloc utils/time

VECF :=	add/add_d add/add_i add/add_to_d add/add_to_i add/add_to add/add \
		div/div_d div/div_i div/div_to_d div/div_to_i div/div_to div/div \
		groups/2vec groups/2vec_xy groups/3vec groups/4vec \
		mult/mult_d mult/mult_i mult/mult_to_d mult/mult_to_i mult/mult_to mult/mult \
		sub/sub_d sub/sub_i sub/sub_to_d sub/sub_to_i sub/sub_to sub/sub \
		abs cross dist dot eq implicit_new is_zero length negative new normalize \
		print printi rotate round square to_vec to_veci zero

VECDIR := vectors/
SRCDIR := src/
OBJDIR := objs/
HDR    := includes

VEC := $(addprefix $(VECDIR), $(VECF))
SRCF += $(VEC)
SRC := $(addprefix $(SRCDIR), $(addsuffix .c, $(SRCF)))
OBJ := $(patsubst $(SRCDIR)%.c, $(OBJDIR)%.o, $(SRC))

# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(NAME) $(OBJ)
	@echo "\033[1mMacroBoX Compiled Successfully!\033[0m"

$(OBJDIR)%.o: $(SRCDIR)%.c | $(OBJDIR)
	@mkdir -p $(dir $@)
	@$(CC) -c $(OBJFLAGS) -I $(HDR) $< -o $@

$(OBJDIR):
	@mkdir $(OBJDIR)

clean:
	@rm -f $(OBJ)
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

mlx:
	@$(MAKE) --no-print-directory -C MacroLibX-2.2.2 -j

full: mlx all

norm:
	@-norminette $(SRC)

.PHONY: all clean fclean re mlx full norm
