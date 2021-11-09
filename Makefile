NAME	=	so_long

INCS	=	./includes

SRCS	=	srcs/so_long.c

OBJS	=	${SRCS:.c=.o}

CC		=	clang

FLAGS	=	-Wall -Wextra -Werror

MLX_FLAGS	=	-L./mlx -lmlx -lX11 -lbsd -lXext -lm

all:		${NAME}

${NAME}:	${OBJS}
			${MAKE}	-C libft
			${MAKE} -C mlx
			${CC} -o ${NAME} ${OBJS} ${FLAGS} ${MLX_FLAGS} libft/libft.a mlx/libmlx.a

clean:		
			${MAKE} -C libft clean
			${MAKE} -C mlx clean
			rm -f ${OBJS}

fclean:		clean
				${MAKE} -C libft fclean
				rm -f ${NAME}

re:			fclean all

.PHONY:		all fclean clean all



