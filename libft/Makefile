NAME = libft.a

SRCS =	ft_strlen.c ft_isalnum.c ft_isalpha.c\
		ft_isdigit.c ft_strcmp_bonus.c ft_atoi.c \

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS	= -Wall -Wextra -Werror -I.

RM = rm -f

LIB = ar rc ${NAME}

.c.o =  ${CC} ${CFLAGS} -c $< -o ${$<.c=.o}

$(NAME): ${OBJS}
		${LIB} ${OBJS}

all: ${NAME}

clean: 
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME} 

re: fclean all

.PHONY: all clean fclean re
