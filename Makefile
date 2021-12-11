NAME	:=	so_long

BONUS	:=	so_long

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

FLAGS	=	-Wall -Wextra -Werror

SYSTEM = $(shell uname)

ifeq (${SYSTEM}, Darwin)
INCS = -I ./includes -I ./libft/includes -I ./mlx_mac
LIBC = -L ./mlx_mac -lmlx -L ./libft -lft
MLX_FLAGS = -framework OpenGL -framework AppKit
MLX_USED = mlx_mac
endif

ifeq (${SERVER}, Linux)
INCS = -I ./includes -I ./libft -I ./mlx
LIBC = -L ./mlx -L ./libft
MLX_FLAGS	=	-L./mlx -lmlx -lX11 -lbsd -lXext -lm
MLX_USED = mlx
endif

all:		${NAME}

.c.o:
			${CC} ${FLAGS} ${INCS} -c $< -o $@

${NAME}:	${OBJS}
			@${MAKE} -C libft
			@${MAKE} -C ${MLX_USED}
			@${CC} ${FLAGS} ${INCS} ${LIBC} ${MLX_FLAGS} -o ${NAME} ${OBJS} -D BONUS=0

bonus:		
			@${MAKE} -C libft >/dev/null
			@${MAKE} -C ${MLX_USED} >/dev/null 2>&1
			@${CC} ${FLAGS} ${INCS} ${LIBC} ${MLX_FLAGS} -o ${NAME} ${SRCS} -D BONUS=1

clean:		
			@${MAKE} -C libft clean
			@${MAKE} -C ${MLX_USED} clean >/dev/null
			@rm -f ${OBJS}

fclean:		clean
			@${MAKE} -C libft fclean
			@rm -f ${NAME}

re:			fclean all

.PHONY:		all fclean clean all bonus
