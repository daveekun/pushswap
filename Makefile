NAME	=	push_swap
FLAGS	=	-Wall -Wextra -Werror
LIBFT	= 	libft/
LIB		=	$(LIBFT)libft.a
MAIN	=	src/main.c 
MAIN_B	=	checker_bonus/main.c
SRC_DIR	=	src/
SRC		=	$(addprefix $(SRC_DIR), go_to.c parse.c sort.c utils.c validate.c get_rotations.c)
SRC_M	=	$(addprefix $(SRC_DIR), stack.c stack_rotate.c)
SRC_B	=	$(addprefix checker_bonus/, stack_rotate_bonus.c stack_bonus.c)
OBJ_DIR	=	obj/
OBJ		=	$(addprefix $(OBJ_DIR), $(notdir $(SRC:.c=.o)))
OBJ_M	=	$(addprefix $(OBJ_DIR), $(notdir $(SRC_M:.c=.o)))
OBJ_B	=	$(addprefix $(OBJ_DIR), $(notdir $(SRC_B:.c=.o)))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(LIB) $(OBJ) $(OBJ_M) $(MAIN)
	@cc $(FLAGS) $(MAIN) $(OBJ) $(OBJ_M) $(LIB) -I $(LIBFT)includes -I include/ -o $(NAME)
	@echo "compiling push_swap"

$(LIB):
	@make -C $(LIBFT)

$(OBJ_DIR)%.o: $(SRC_DIR)/%.c
	@cc $(FLAGS) -c $< -I $(LIBFT)includes -I include/ -o $@
	@echo "compiling file $@"

$(OBJ_DIR)%.o: checker_bonus/%.c
	@cc $(FLAGS) -c $< -I $(LIBFT)includes -I include/ -o $@
	@echo "compiling file $@"

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

bonus: .bonus

.bonus: $(OBJ_DIR) $(LIB) $(OBJ) $(OBJ_B) $(MAIN_B)
	@cc $(FLAGS) $(MAIN_B) $(OBJ) $(OBJ_B) $(LIB) -I $(LIBFT)includes -I include/ -o checker
	@echo "compiling checker"
	@touch .bonus

clean:
	@rm -rf $(OBJ) $(OBJ_B)
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT) fclean
	@rm -rf .bonus

fclean: clean
	@rm -rf $(NAME)
	@rm -rf checker

re: fclean all