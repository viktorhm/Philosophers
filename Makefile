
NAME		= philosophers

HEADER		= ./includes/

SRCS		=  srcs/init.c srcs/parsing.c srcs/philo.c srcs/simulation.c

OBJS		= $(SRCS:.c=.o)

CC		= gcc
CFLAGS		= -Werror -Wall -Wextra -g -I$(HEADER) -pthread

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

