SRCS =	./srcs/stdlib/ft_nbrlen_base.c \
		./srcs/char/ft_isdigit.c  \
		./srcs/list/ft_lstadd_front.c \
		./srcs/list/ft_lstadd_back.c \
		./srcs/print/ft_putaddr_fd.c \
		./srcs/print/ft_putchar_fd.c \
		./srcs/print/ft_putendl_fd.c \
		./srcs/char/ft_is_charset.c \
		./srcs/print/ft_putnbr_fd.c \
		./srcs/print/ft_putstr_fd.c \
		./srcs/string/ft_striteri.c \
		./srcs/list/ft_lstdelone.c \
		./srcs/string/ft_strjoin.c \
		./srcs/string/ft_strlcat.c \
		./srcs/string/ft_strlcpy.c \
		./srcs/string/ft_strmapi.c \
		./srcs/string/ft_strncmp.c \
		./srcs/string/ft_strnstr.c \
		./srcs/string/ft_strrchr.c \
		./srcs/string/ft_strtrim.c \
		./srcs/list/ft_lstclear.c \
		./srcs/print/ft_putnstr_fd.c \
		./srcs/stdlib/ft_nbrlen.c \
		./srcs/string/ft_strcat.c \
		./srcs/string/ft_strchr.c \
		./srcs/string/ft_strdup.c \
		./srcs/string/ft_strlen.c \
		./srcs/string/ft_substr.c \
		./srcs/char/ft_isalnum.c \
		./srcs/char/ft_isalpha.c \
		./srcs/char/ft_isascii.c \
		./srcs/char/ft_isprint.c \
		./srcs/char/ft_tolower.c \
		./srcs/char/ft_toupper.c \
		./srcs/list/ft_lstiter.c \
		./srcs/list/ft_lstlast.c \
		./srcs/list/ft_lstsize.c \
		./srcs/stdlib/ft_atoll.c \
		./srcs/string/ft_split.c \
		./srcs/list/ft_lstmap.c \
		./srcs/list/ft_lstnew.c \
		./srcs/math/ft_random.c \
 		./srcs/mem/ft_memccpy.c \
		./srcs/mem/ft_memmove.c \
		./srcs/stdlib/ft_atoi.c \
		./srcs/stdlib/ft_atol.c \
		./srcs/stdlib/ft_itoa.c \
		./srcs/mem/ft_calloc.c \
		./srcs/mem/ft_malloc.c \
		./srcs/mem/ft_memchr.c \
		./srcs/mem/ft_memcmp.c \
		./srcs/mem/ft_memcpy.c \
		./srcs/mem/ft_memset.c \
		./srcs/mem/ft_bzero.c \
		./srcs/mem/ft_clean.c \
		./srcs/math/ft_abs.c \
		./srcs/math/ft_max.c \
		./srcs/math/ft_min.c \
		./srcs/mem/ft_free.c \
		./srcs/math/ft_labs.c \
		./srcs/math/ft_llabs.c

# GNL

SRCS += ./srcs/string/gnl/get_next_line_utils.c \
		./srcs/string/gnl/get_next_line.c \

# FT_PRINTF

SRCS += ./srcs/print/printf/print_flag.c \
		./srcs/print/printf/ft_printf.c \
		./srcs/print/printf/print_arg.c \
		./srcs/print/printf/parse2.c \
		./srcs/print/printf/tools2.c \
		./srcs/print/printf/parse.c \
		./srcs/print/printf/tools.c \

OBJS = ${SRCS:.c=.o}

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
INCS = includes

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

all: ${NAME}

.c.o:
			@${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

$(NAME): $(OBJS) 
			@ar -rcs $(NAME) $(OBJS)
			@ echo "${_GREEN}libft.a compiled${_END}"

clean:
			@ echo "${_RED}Deleting libft's objects...${_END}"
			@${RM} ${OBJS} ${OBJSBONUS}

fclean: clean
			@ echo "${_RED}Deleting libft's library...${_END}"
			@${RM} ${NAME}

re: fclean all

.PHONY:		all clean fclean re