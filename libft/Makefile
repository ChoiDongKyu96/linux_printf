# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dochoi <dochoi@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/03 14:47:59 by dochoi            #+#    #+#              #
#    Updated: 2020/04/04 21:43:33 by dochoi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ./ft_memset.c ./ft_bzero.c ./ft_memcpy.c ./ft_memccpy.c \
		./ft_memmove.c ./ft_memchr.c ./ft_memcmp.c ./ft_strlen.c \
		./ft_strlcpy.c ./ft_strlcat.c ./ft_strchr.c ./ft_strrchr.c \
		./ft_strnstr.c ./ft_strncmp.c ./ft_atoi.c ./ft_isalpha.c \
		./ft_isdigit.c ./ft_isalnum.c ./ft_isascii.c ./ft_isprint.c \
		./ft_tolower.c ./ft_toupper.c ./ft_calloc.c ./ft_strdup.c \
		./ft_substr.c ./ft_strjoin.c ./ft_strtrim.c ./ft_split.c \
		./ft_itoa.c ./ft_strmapi.c ./ft_putchar_fd.c ./ft_putstr_fd.c \
		./ft_putendl_fd.c ./ft_putnbr_fd.c
SRCS_BONUS = ./ft_lstadd_back.c ./ft_lstadd_front.c ./ft_lstclear.c ./ft_lstdelone.c\
		./ft_lstiter.c ./ft_lstlast.c ./ft_lstmap.c ./ft_lstnew.c ./ft_lstsize.c
CC = gcc
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
CFLAGS = -Wall -Wextra -Werror

ifdef WITH_BONUS
	OBJS_F = $(OBJS) $(OBJS_BONUS)
else
	OBJS_F = $(OBJS)
endif

 %.o: %.c
	gcc -c -o $@ ${CFLAGS} $<

$(NAME) :	$(OBJS_F)
	@echo "objs is ok\n"
	@ar -r $(NAME) $(OBJS_F)
	@ranlib $(NAME)
	@echo "complete\n"

bonus :
	make WITH_BONUS=1 all
	@echo "bonus complete\n"

all:	$(NAME)

clean:
	/bin/rm -f $(OBJS) $(OBJS_BONUS)

fclean:	clean
	/bin/rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re bonus
