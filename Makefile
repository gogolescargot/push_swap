# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 15:27:49 by ggalon            #+#    #+#              #
#    Updated: 2023/12/06 20:56:57 by ggalon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME_LIB = push_swap.a
NAME = push_swap

LIBFT_DIR = lib/
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)

FUNC = atol check_error check_stack init_stack main push reverse_rotate rotate sort split swap

SRCS_DIR = src/
SRCS = $(addsuffix .c, $(addprefix $(SRCS_DIR), $(FUNC)))

OBJS_DIR = obj/
OBJS = $(addsuffix .o, $(addprefix $(OBJS_DIR), $(FUNC)))

INCL = inc/push_swap.h

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME_LIB)
	cd lib; make

$(NAME_LIB): $(OBJS) Makefile
	ar -rcs $@ $(OBJS)
	$(CC) $(CFLAGS) $(NAME_LIB) $(LIBFT) -o $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(INCL) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	cd lib; make clean;

fclean:
	rm -f $(OBJS)
	rm -f $(NAME_LIB)
	rm -f $(NAME)
	cd lib; make fclean

re: fclean all
	
.PHONY: all clean fclean re
