NAME	=	so_long

INCS	=	./includes

SRCS	=	srcs/so_long.c \
			srcs/ennemies/move_ennemies.c \
			srcs/ennemies/ennemies.c \
			srcs/display/display.c \
			srcs/display/print_texture.c \
			srcs/parsing/check_map.c \
			srcs/parsing/get_map.c \
			srcs/parsing/manage_map.c \
			srcs/player/move_player.c \
			srcs/player/check_player.c \
			srcs/tools/tools.c \
			srcs/tools/color.c \
			srcs/tools/x_init.c \
			srcs/exit/exit.c \
			srcs/exit/free.c

OBJS	=	${SRCS:.c=.o}

CC		=	clang

FLAGS	=	-Wall -Wextra -Werror -I -g3

MLX_FLAGS	=	-L./mlx -lmlx -lX11 -lbsd -lXext -lm

all:		${NAME}

${NAME}:	${OBJS}
			${MAKE} -C libft
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



