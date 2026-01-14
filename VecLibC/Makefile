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
CFLAGS := -Wall -Wextra -Werror -fPIC -g

NAME := libvec.so

LIB := -lm

SRCF :=	add/add_d add/add_i add/add_to_d add/add_to_i add/add_to add/add \
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
OBJDIR := objs/
HDR    := includes/

SRC := $(addprefix $(SRCDIR), $(addsuffix .c, $(SRCF)))
OBJ := $(patsubst $(SRCDIR)%.c, $(OBJDIR)%.o, $(SRC))

# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) -shared -o $(NAME) $(OBJ) $(LIB)
	@echo "\033[1mVecLibC Compiled Successfully!\033[0m"

$(OBJDIR)%.o: $(SRCDIR)%.c | $(OBJDIR)
	@mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) -I $(HDR) $< -o $@

$(OBJDIR):
	@mkdir $(OBJDIR)

clean:
	@rm -f $(OBJ)
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

norm:
	@-norminette $(SRC)

.PHONY: all clean fclean re norm
