NAME	= libftprintf.a
SRCS	= ft_printf.c ft_printf_utils.c ft_various.c ft_numbers_utils.c
CC		= gcc
OBJS	= ${SRCS:.c=.o}
LOBJS	= $(addprefix Libft/, *.o)
HEADER	= printflib.h
CFLAGS	= -Wall -Wextra -Werror $(IDIR)
RM		= rm -f

all:		${NAME}

$(NAME):	${SRCS} ${HEADER}
	make -C Libft/
	${CC} ${CFLAGS} -c ${SRCS}
	ar rc $(NAME) ${OBJS} ${LOBJS}

clean:
	${RM} ${OBJS} ${BONOBJS}
	make clean -C Libft/

fclean:		clean
	${RM} ${NAME}
	make fclean -C Libft/
			

re:			fclean all