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

# DIRECTORIES ==================================================================

LIBFT_DIR	= libft/

SRCS_DIR	= src/

OBJS_DIR	= obj/

INCL_DIR	= inc/

# FILES ========================================================================

NAME	= push_swap

LIBFT	= $(LIBFT_DIR)libft.a

FUNC	= atol check_error check_stack \
		  init_stack main push reverse_rotate \
		  rotate sort split swap \

SRCS	= $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FUNC)))

OBJS	= $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FUNC)))

INCL	= $(INCL_DIR)push_swap.h

# COMMANDS =====================================================================

CC			= cc

CC_FLAGS	= -Wall -Wextra -Werror

AR			= ar

AR_FLAGS	= -rc

# RULES ========================================================================

all: 
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) $(NAME)


$(NAME): $(OBJS) Makefile
	$(CC) $(CC_FLAGS) $(OBJS) $(LIBFT) -o $(NAME)


$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(INCL) Makefile
	$(CC) $(CC_FLAGS) -c $< -o $@


clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)


fclean:
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(OBJS)
	rm -f $(NAME)


re: fclean all


.PHONY: all clean fclean re
