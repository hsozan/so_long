CC			= gcc -Wall -Wextra -Werror
LFLAGS		= -framework OpenGL -framework AppKit
NAME		= so_long
SRCS 		= src/*.c
CYAN		= \033[0;96m
BLUE		= \033[0;94m
WHITE		= \033[0;97m

all: $(NAME)
$(NAME): LIBS
	@$(CC) $(LFLAGS) $(SRCS) ./libft/libft.a minilibx/libmlx.a -I ./includes -o $(NAME)
	@echo "$(CYAN)so_long is ready to use !$(WHITE)"
LIBS:
	@make -C minilibx
	@make -C libft
	@echo "$(BLUE)Minilibx $(WHITE)and $(BLUE)LIBFT $(WHITE)Libraries are ready to use !$(WHITE)"
norm:
	@norminette src/*.c
	@norminette includes/*.h
	@norminette libft/*.c
	@norminette libft/*.h
run: re
	./$(NAME) maps/map_1.ber
clean:
	@rm -rf src/*.o
fclean: clean
	@rm -rf $(NAME)
	@make clean -C minilibx
	@make fclean -C libft
	@echo "$(BLUE)Project is clean$(WHITE)"
re: fclean all
