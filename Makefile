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
WINDOWS_X = 1000
WINDOWS_Y = 1000
FLAGS	=	-Wall -Wextra -Werror
SYSTEM = $(shell uname)

_END=$'\x1b[0m
_BOLD=$'\x1b[1m
_UNDER=$'\x1b[4m
_REV=$'\x1b[7m

# Colors
_GREY=$'\x1b[30m
_RED=$'\x1b[31m
_GREEN=$'\x1b[32m
_YELLOW=$'\x1b[33m
_BLUE=$'\x1b[34m
_PURPLE=$'\x1b[35m
_CYAN=$'\x1b[36m
_WHITE=$'\x1b[37m

ifeq (${SYSTEM}, Darwin)
INCS = -I ./includes -I ./libft/includes -I ./mlx_mac
LIBC = -L ./mlx_mac -lmlx -L ./libft -lft
MLX_FLAGS = -Ofast -framework OpenGL -framework AppKit
MLX_USED = mlx_mac
HEADER_MESSAGE = SO_LONG IS COMPILING ON ${_YELLOW}MACOS${_END}
endif

ifeq (${SYSTEM}, Linux)
INCS = -I ./includes -I ./libft -I ./mlx
LIBC = -L ./mlx -L ./libft
MLX_FLAGS	=	-L./mlx -lmlx -lX11 -lbsd -lXext -lm
MLX_USED = mlx
HEADER_MESSAGE = SO_LONG IS COMPILING ON ${_GREEN}LINUX${_END}
endif

all:		${NAME}

.c.o:
			@${CC} ${FLAGS} ${INCS} -c $< -o $@

${NAME}:	${OBJS}
			@echo "[${HEADER_MESSAGE}]"
			@echo "[1 / 3] Compiling ${_CYAN}libft${_END}..."
			@${MAKE} -C libft >/dev/null
			@echo "[2 / 3] Compiling ${_RED}mlx${_END}..."
			@${MAKE} -C ${MLX_USED} >/dev/null 2>&1
			@echo "[3 / 3] Compiling ${_GREEN}so_long${_END}..."
			@${CC} ${FLAGS} ${INCS} ${LIBC} ${MLX_FLAGS} -o ${NAME} ${OBJS}
			@echo "${_CYAN}so_long's ${_PURPLE}ready ${_YELLOW}to ${_GREEN}be ${_RED}used${_END} !"

bonus:		${OBJS} ${SRCS}
			@echo "[${HEADER_MESSAGE} WITH BONUS]"
			@echo "[1 / 3] Compiling ${_CYAN}libft${_END}..."
			@${MAKE} -C libft >/dev/null
			@echo "[2 / 3] Compiling ${_RED}mlx${_END}..."
			@${MAKE} -C ${MLX_USED} >/dev/null 2>&1
			@echo "[3 / 3] Compiling ${_GREEN}so_long${_END}..."
			@${CC} -DBONUS -D WINDOWS_X=${WINDOWS_X} -D WINDOWS_Y=${WINDOWS_Y} ${FLAGS} ${INCS} ${LIBC} ${MLX_FLAGS} -o ${NAME} ${SRCS}
			@echo "${_CYAN}so_long's ${_PURPLE}ready ${_YELLOW}to ${_GREEN}be ${_RED}used${_END} !"

clean:		
			@echo "Deleting ${_CYAN}libft${_END} library..."
			@${MAKE} -C libft clean >/dev/null
			@echo "Deleting ${_RED}mlx${_END} library..."
			@${MAKE} -C ${MLX_USED} clean >/dev/null
			@echo "Deleting ${_GREEN}so_long${_END} binary files..."
			@rm -f ${OBJS}


fclean:		clean
			@${MAKE} -C libft fclean >/dev/null
			@echo "Deleting ${_GREEN}so_long${_END} executable..."
			@rm -f ${NAME}
			@echo "${_YELLOW}so_long's ${_GREEN}has ${_PURPLE}been ${_CYAN}cleaned${_END} !"

re:			fclean all

.PHONY:		all fclean clean all bonus
