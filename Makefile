NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
SRC_NAME = ./ft_custom_size.c ./ft_ftostr_dochoi.c ./ft_insert_n.c \
			./ft_parse_tab.c ./ft_printf.c ./ft_putbase_std.c \
			./ft_putdecimal_std.c ./ft_show_c.c ./ft_show_d.c ./ft_show_f.c \
			./ft_show_o.c ./ft_show_p.c ./ft_show_plus_space_hash.c ./ft_show_s.c \
			./ft_show_u.c ./ft_show_wc.c ./ft_show_xX.c ./ft_what_spcf.c
SRC_PATH = ./
SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_PATH = ./obj
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))
INC_LINK = -I./includes
LIBFT = -L./lib/libft -lft

.c.o:
		${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

all : $(NAME)
$(NAME) : $(OBJ) libft
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	gcc $(FLAGS) $(INC_LINK) -o $@ -c $<
# libft compile
libft :
	@$(MAKE) -C ./lib/libft all
clean :
	@$(MAKE) -C ./lib/libft clean
	@rm -rf ./obj
fclean :
	@$(MAKE) -C ./lib/libft fclean
	@rm -rf ./obj $(NAME)
re : fclean all
.PHONY: all clean fclean re