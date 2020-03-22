# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dochoi <dochoi@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/22 23:40:58 by dochoi            #+#    #+#              #
#    Updated: 2020/03/23 01:05:37 by dochoi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
SRC_NAME = ./ft_custom_size.c ./ft_ftostr_dochoi.c ./ft_insert_n.c \
			./ft_parse_tab.c ./ft_printf.c ./ft_putbase_std.c \
			./ft_putdecimal_std.c ./ft_show_c.c ./ft_show_d.c ./ft_show_f.c \
			./ft_show_o.c ./ft_show_p.c ./ft_show_plus_space_hash.c ./ft_show_s.c \
			./ft_show_u.c ./ft_show_wc.c ./ft_show_xX.c ./ft_what_spcf.c
LIB_SRC_NAME = ./ft_memset.c ./ft_bzero.c ./ft_memcpy.c ./ft_memccpy.c \
		./ft_memmove.c ./ft_memchr.c ./ft_memcmp.c ./ft_strlen.c \
		./ft_strlcpy.c ./ft_strlcat.c ./ft_strchr.c ./ft_strrchr.c \
		./ft_strnstr.c ./ft_strncmp.c ./ft_atoi.c ./ft_isalpha.c \
		./ft_isdigit.c ./ft_isalnum.c ./ft_isascii.c ./ft_isprint.c \
		./ft_tolower.c ./ft_toupper.c ./ft_calloc.c ./ft_strdup.c \
		./ft_substr.c ./ft_strjoin.c ./ft_strtrim.c ./ft_split.c \
		./ft_itoa.c ./ft_strmapi.c ./ft_putchar_fd.c ./ft_putstr_fd.c \
		./ft_putendl_fd.c ./ft_putnbr_fd.c \
		./ft_lstadd_back.c ./ft_lstadd_front.c ./ft_lstclear.c ./ft_lstdelone.c\
		./ft_lstiter.c ./ft_lstlast.c ./ft_lstmap.c ./ft_lstnew.c ./ft_lstsize.c

OBJ_NAME = $(SRC_NAME:.c=.o)
LIB_OBJ_NAME = $(LIB_SRC_NAME:.c=.o)
OBJ_PATH = ./obj
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))
LIB_OBJ = $(addprefix $(OBJ_PATH)/, $(LIB_OBJ_NAME))
INC_LINK = -I./includes

$(OBJ_PATH)/%.o: %.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	gcc $(FLAGS) $(INC_LINK) -o $@ -c $<

all : $(NAME)

$(NAME) : $(OBJ) libft.a

	@ar -r $(NAME) $(OBJ) $(LIB_OBJ)
	@ranlib $(NAME)
	@echo "complete\n"

libft.a :
	@$(MAKE) -C ./lib/libft bonus
	@for i in $(LIB_OBJ_NAME); do cp ./lib/libft/$$i ./$(OBJ_PATH); done
	cp ./lib/libft/$@ ./
	@echo "moved lib's objfile\n"
clean :
	@$(MAKE) -C ./lib/libft clean
	@rm -rf ./obj libft.a
fclean :
	@$(MAKE) -C ./lib/libft fclean
	@rm -rf ./obj $(NAME) libft.a
re : fclean all
.PHONY: all clean fclean re