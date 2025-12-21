# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daemo <daemo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/24 19:51:36 by rprieur           #+#    #+#              #
#    Updated: 2025/12/21 11:22:29 by daemo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
CFLAGS := -shared -o
OBJFLAGS := -Wall -Wextra -Werror -fPIC -g

NAME := libmbx.so

LIB := MacroLibX-2.2.2/libmlx.so
LIBFLAGS := -lSDL2 -lm

SRCF := exit image init loop mouse window \
		events/events events/keyboard events/mouse events/window \
		vectors/vector2 vectors/vector2i vectors/vector3 vectors/vector3i

SRCDIR := src/
SRC := $(addprefix $(SRCDIR), $(addsuffix .c, $(SRCF)))

HDR :=	includes

OBJDIR := objs/
OBJ := $(patsubst $(SRCDIR)%.c, $(OBJDIR)%.o, $(SRC))

# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(NAME) $(OBJ)
	@echo "\033[1mCompiled Successfully!\033[0m"

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

.PHONY: all clean fclean re mlx full
