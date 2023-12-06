NAME = libft.a

SRC_DIR_LIBFT	=	src/libft
SRC_DIR_PRINTF	=	src/ft_printf
SRC_DIR_GNL 	=	src/get_next_line

SRCS_LIBFT		=	ft_isalnum.c ft_isprint.c ft_memcmp.c ft_putchar_fd.c ft_split.c \
					ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
					ft_itoa.c ft_memcpy.c  ft_putendl_fd.c ft_strchr.c  ft_strlcpy.c \
					ft_strnstr.c ft_tolower.c ft_bzero.c   ft_isascii.c  \
					ft_memmove.c ft_putnbr_fd.c  ft_strdup.c  ft_strlen.c  ft_strrchr.c \
					ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c  ft_memset.c  \
					ft_putstr_fd.c  ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_striteri.c

SRCS_PRINTF 	=	ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_putunbr.c \
					ft_putptr.c ft_puthexlowernbr.c ft_puthexuppernbr.c \
					ft_countstr.c ft_countdecnbr.c ft_countdecunbr.c ft_counthexnbr.c \
					ft_countptrnbr.c ft_percent_count.c ft_percent_put.c

SRCS_GNL		=		get_next_line.c get_next_line_utils.c

OBJS_DIR_LIBFT	=	obj/libft/
OBJS_DIR_PRINTF	=	obj/ft_printf/
OBJS_DIR_GNL	=	obj/get_next_line/

OBJS_LIBFT		=	$(addprefix $(OBJS_DIR_LIBFT), $(SRCS_LIBFT:.c=.o))
OBJS_PRINTF		=	$(addprefix $(OBJS_DIR_PRINTF), $(SRCS_PRINTF:.c=.o))
OBJS_GNL		=	$(addprefix $(OBJS_DIR_GNL), $(SRCS_GNL:.c=.o))

INCL			=	inc/libft.h

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS_LIBFT) $(OBJS_PRINTF) $(OBJS_GNL)
	ar -rcs $@ $^

$(OBJS_DIR_LIBFT)%.o: $(SRC_DIR_LIBFT)/%.c $(INCL) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR_PRINTF)%.o: $(SRC_DIR_PRINTF)/%.c $(INCL) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR_GNL)%.o: $(SRC_DIR_GNL)/%.c $(INCL) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS_LIBFT) $(OBJS_PRINTF) $(OBJS_GNL)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
