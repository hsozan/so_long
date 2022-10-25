CC			= gcc
FLAGS		= -Wall -Wextra -Werror
LFLAGS		= -framework OpenGL -framework AppKit
NAME		= so_long
#BNAME		= so_long_bonus
SRCS 		= src/so_long.c src/ft_error.c src/ft_check_utils.c src/ft_check.c src/ft_check_valid.c
#BSRCS		= bonus/so_long_b.c bonus/convert_xpms_b.c bonus/ft_create_map_b.c bonus/ft_init_map_b.c bonus/ft_split_fs_b.c bonus/key_events_b.c bonus/so_long_utils_b.c bonus/ft_animator_b.c
OBJS		= $(SRCS:.c=.o)
#BOBJS		= $(BSRCS:.c=.o)<
all: $(NAME)

$(NAME): LIBS $(OBJS)
	$(CC) $(LFLAGS) $(FLAGS) $(SRCS) ./libft/libft.a minilibx/libmlx.a -I ./includes -o $(NAME)
#bonus: $(BNAME)

#$(BNAME): $(MINILIBX) $(BOBJS)
#$(CC) $(LFLAGS) $(FLAGS) $(BOBJS) -o $(BNAME) ./ft_printf/libftprintf.a ./libft/libft.a minilibx/libmlx.a

LIBS:
	@make -C minilibx
	@make -C libft
norm:
	@norminette src/*.c include/*.h
#@norminette bonus/*.c
run: all
	./$(NAME) maps/map_1.ber
clean:
	rm -rf $(OBJS)
#	rm -rf $(BOBJS)

fclean: clean
	rm -rf $(NAME)
#	rm -rf $(BNAME)
	@make clean -C minilibx
	@make fclean -C libft
re: fclean all
.PHONY: clean run fclean re all norm
