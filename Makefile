
NAME		= philosophers

SRCS		=  srcs/philo.c srcs/atoi.c

OBJS		= $(SRCS:.c=.o)

CC		= cc
CFLAGS		=-Iincludes

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -lpthread

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

