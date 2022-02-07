NAME	=	libftprintf.a

SRCS	= 	ft_printf.c \
			utils/ft_strlen.c \
			utils/ft_memcpy.c \
			utils/ft_strdup.c \
			utils/ft_putchar.c
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