NAME = libftprintf.a
SRCS = $(wildcard *.c)
OBJS = $(wildcard *.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -c $(SRCS)
	ar -rc temp.a $(OBJS)
	ranlib temp.a
	ar -x libft.a
	ar -x temp.a
	ar -qc $(NAME) *.o
	rm temp.a
clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re:	fclean all