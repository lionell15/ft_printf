NAME =		libftprintf.a

SRCS = 		ft_printf.c
OBJS	= 	$(SRCS:.c=.o)
CC	= 	gcc
RM	= 	rm -f
LIBC	= 	ar -rcs
FLAGS	= 	-Wall -Wextra -Werror

.c.o :
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	$(LIBC) $(NAME) $(OBJS)

all: $(NAME)

fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) $(OBJS) $(BONUS_O)

re: fclean all
