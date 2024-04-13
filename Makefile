
NAME		= philo

HEADER		= ./includes/

SRCS		=srcs/init.c \
			srcs/parsing.c \
			srcs/main.c \
			srcs/simulation.c \
			srcs/utils.c \
			srcs/lock_unlock.c \
			srcs/safe_init.c \
			srcs/reaper.c\


OBJS		= $(SRCS:.c=.o)

CC		= gcc
CFLAGS		=  -g -I$(HEADER) -pthread -Wextra -Wall -Werror

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

