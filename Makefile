
NAME		= philosophers

SRCS		=  srcs/init.c srcs/parsing.c srcs/philo.c srcs/simulation.c

OBJS		= $(SRCS:.c=.o)

CC		= cc
CFLAGS		= -Iincludes -g -lpthread

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

