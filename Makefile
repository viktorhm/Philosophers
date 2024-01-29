
NAME		= philosophers

SRCS		=  srcs/main.c

OBJS		= $(SRCS:.c=.o)

CC		= cc
CFLAGS		=-Iincludes

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

