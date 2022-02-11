NAME	=	libftprintf.a

SRCS	= 	ft_printf.c \
			src/ft_print_char.c \
			src/ft_print_str.c \
			src/ft_print_digits.c \
			src/ft_print_pointers.c \
			src/ft_print_unsigned.c \
			src/ft_print_hexa_low.c \
			src/ft_print_hexa_up.c
CC		= 	gcc
RM		= 	rm -f
LIBC	= 	ar -rcs
FLAGS	= 	-Wall -Wextra -Werror
OBJS	= 	$(SRCS:.c=.o)
.c.o :
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	$(LIBC) $(NAME) $(OBJS)

all: $(NAME)

fclean: clean
	$(RM) $(NAME) out

clean:
	$(RM) $(OBJS) $(BONUS_O)

re: fclean all

.PHONY: all clean fclean re .c.o