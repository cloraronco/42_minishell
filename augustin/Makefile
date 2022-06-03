NAME = minishell

READLINE_LIB_DIR_FLAG := -L$(shell brew --prefix readline)/lib
READLINE_INC_DIR_FLAG := -I$(shell brew --prefix readline)/include

SRC = main.c srcs/parsing.c srcs/utils.c srcs/list_utils.c srcs/read_line.c

OBJ = $(SRC:.c=.o)
OBJSDIR	= objs/
OBJS = $(addprefix $(OBJSDIR), $(OBJ))

FLAGS = -Wall -Wextra -Werror
LINKS = libft/libft.a

NONE		='\033[0m'
BLU			='\033[0;34m'
RED			='\033[0;31m'
GREEN		='\033[32m'
GRAY		='\033[2;37m'
CURSIVE		='\033[3m'

all: $(NAME)

$(OBJSDIR)%.o : %.c		hdrs/minishell.h libft/libft.a Makefile
	@mkdir -p $(OBJSDIR)
	@mkdir -p $(OBJSDIR)srcs
	@gcc $(READLINE_INC_DIR_FLAG) $(FLAGS) -c $< -o $@
	@echo $(CURSIVE)$(GRAY) "     - creating .o ..." $(NONE)

$(NAME): maker $(OBJS)
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
	@gcc $(FLAGS) $(OBJS) $(READLINE_LIB_DIR_FLAG) $(LINKS) -lreadline -o $(NAME) 
	@echo $(GREEN)"- Compiled -"$(NONE)
#	@rm $(OBJ)
	@echo $(CURSIVE)$(GRAY) "     Deleted object files" $(NONE)

maker:
		@make -C libft

exe: all
	@echo "     - Executing $(NAME)... \n"
	@./$(NAME)
	@echo "\n     - Done -"

clean:
	@echo $(CURSIVE)$(GRAY) "     - Removing object files..." $(NONE)
	@make clean -C libft
	@rm -rf $(OBJ)
	@rm -rf $(OBJSDIR)

fclean: clean
	@echo $(CURSIVE)$(GRAY) "     - Removing $(NAME)..." $(NONE)
	@rm -rf $(NAME)
	@rm -rf libft/libft.a

re: fclean all

.phony: re fclean all clean exe maker