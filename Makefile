NAME	=	libftprintf.a

SRCS	= 	ft_printf.c \
			src/ft_print_char.c \
			src/ft_print_str.c \
			src/ft_print_digits.c \
			src/ft_print_pointers.c \
			utils/ft_isdigit.c \
			utils/ft_itoa.c \
			utils/ft_memcpy.c \
			utils/ft_strlen.c \
			utils/ft_memcpy.c \
			utils/ft_strdup.c \
			utils/ft_putchar.c \
			utils/ft_putsp.c \
			utils/ft_str_tolower.c \
			utils/ft_u_itoa.c \
			utils/ft_utl_base.c

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

program:
	${CC} ${FLAGS} main.c -lftprintf -L. -o out

fclean: clean
	$(RM) $(NAME) out

clean:
	$(RM) $(OBJS) $(BONUS_O)

re: fclean all

.PHONY: all clean fclean program re .c.o