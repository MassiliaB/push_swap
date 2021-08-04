#COLORS#
_END    = \033[0m
_GREEN  = \033[0;32m
_RED    = \033[0;31m
_BLUE   = \033[0;96m
_YELLOW = \033[0;33m
_MAG = \033[0;35m

NAME = push_swap

SRCS =  srcs/main.c \
		srcs/clean_all.c \
		srcs/utils.c \
		srcs/hundred.c \
		srcs/five_hundred.c \
		srcs/three_to_five.c \
		operations/push_ab.c \
		operations/swap_ab.c \
		operations/rotate_ab.c \
		operations/reverse_rotate.c \
		print_stack.c \

LIBFT   = libft/

OBJS = $(SRCS:.c=.o)

CC = clang #-g -fsanitize=address

CFLAGS = -Wall -Wextra -Werror 

RM = rm -f

.o.c = $(CC) ${CFLAGS} -c $< -o ${$<.c=.o}

all: ${NAME}

$(NAME): ${OBJS}
		@make --silent -C ${LIBFT}
		@${CC} -lncurses ${OBJS} ${LIBFT}/libft.a -o ${NAME}

clean:
		@make clean --silent -C libft/
		@${RM} ${OBJS}
		@${RM} ${NAME}
		@echo "$(_RED) Everything was cleaned. $(_END)"

fclean: clean
		@make fclean --silent -C libft/
		@${RM} ${NAME}
		@echo "$(_MAG) ██████╗ ██   ██╗███████╗ $(_END)"
		@echo "$(_MAG) ██╔══██╗██   ██║██╔════╝ $(_END)"
		@echo "$(_MAG) ██████╔╝███████║███████║ $(_END)"
		@echo "$(_MAG) ██╔══██╗ ╔═══██║██═════╗ $(_END)"
		@echo "$(_MAG) ██████╔╝ ██████║███████║ $(_END)"
		@echo "$(_MAG) ╚═════╝  ╚═════╝╚══════╝ $(_END)"

re: fclean all

.PHONY: all clean fclean re