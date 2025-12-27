# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daemo <daemo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/24 19:51:36 by rprieur           #+#    #+#              #
#    Updated: 2025/12/27 21:57:34 by daemo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
CFLAGS := -shared -o
OBJFLAGS := -Wall -Wextra -Werror -fPIC -g

NAME := libmbx.so

LIB := MacroLibX-2.2.2/libmlx.so
LIBFLAGS := -lSDL2 -lm

SRCF :=	color exit image init loop_end loop_start loop mouse screen settings window \
		events/events events/keyboard events/mouse events/window \
		math/clamp math/conv math/lerp math/loop math/minmax

VECF :=	add/add_d add/add_i add/add_to_d add/add_to_i add/add_to add/add \
		div/div_d div/div_i div/div_to_d div/div_to_i div/div_to div/div \
		mult/mult_d mult/mult_i mult/mult_to_d mult/mult_to_i mult/mult_to mult/mult \
		sub/sub_d sub/sub_i sub/sub_to_d sub/sub_to_i sub/sub_to sub/sub \
		abs cross dist dot eq is_zero length negative new normalize \
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
	@echo "\033[1m MacroBoX Compiled Successfully!\033[0m"

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
