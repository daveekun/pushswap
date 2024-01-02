NAME	=	push_swap

LIBFT	= 	libft/
LIB		=	$(LIBFT)libft.a
MAIN	=	src/main.c 
SRC_DIR	=	src/
SRC		=	$(addprefix $(SRC_DIR), stack.c go_to.c parse.c sort.c utils.c)
OBJ_DIR	=	obj/
OBJ		=	$(addprefix $(OBJ_DIR), $(notdir $(SRC:.c=.o)))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(LIB) $(OBJ) $(MAIN)
	@cc $(FLAGS) $(MAIN) $(OBJ) $(LIB) -I $(LIBFT)includes -I include/ -o $(NAME)
	@echo "compiling push_swap"

$(LIB):
	@make -C $(LIBFT)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@cc $(FLAGS) -c $< -I $(LIBFT)includes -I include/ -o $@
	@echo "compiling file $@"

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

clean:
	@rm -rf $(OBJ) $(OBJ_B)
	@rm -rf $(OBJ_DIR)
	@make fclean -C $(LIBFT)
	@rm -rf .bonus

fclean: clean
	@rm -rf $(NAME)

# @./$(NAME) `jot -r 3 1 1000 | tr '\n' ' '` | wc -l >> test3
test3: $(NAME)
	@./$(NAME) `jot -r 3 1 1000 | tr '\n' ' '` > test3

test5: $(NAME)
	@./$(NAME) `jot -r 5 1 1000 | tr '\n' ' '` | wc -l >> test5
	@./$(NAME) `jot -r 5 1 1000 | tr '\n' ' '` | wc -l >> test5
	@./$(NAME) `jot -r 5 1 1000 | tr '\n' ' '` | wc -l >> test5
	@./$(NAME) `jot -r 5 1 1000 | tr '\n' ' '` | wc -l >> test5
	@./$(NAME) `jot -r 5 1 1000 | tr '\n' ' '` | wc -l >> test5
	@./$(NAME) `jot -r 5 1 1000 | tr '\n' ' '` | wc -l >> test5
	@./$(NAME) `jot -r 5 1 1000 | tr '\n' ' '` | wc -l >> test5
	@./$(NAME) `jot -r 5 1 1000 | tr '\n' ' '` | wc -l >> test5
	@cat test5
	@rm test5

test100: $(NAME)
	@./$(NAME) `jot -r 100 1 1000 | tr '\n' ' '` | wc -l >> test100
	@./$(NAME) `jot -r 100 1 1000 | tr '\n' ' '` | wc -l >> test100
	@./$(NAME) `jot -r 100 1 1000 | tr '\n' ' '` | wc -l >> test100
	@./$(NAME) `jot -r 100 1 1000 | tr '\n' ' '` | wc -l >> test100
	@./$(NAME) `jot -r 100 1 1000 | tr '\n' ' '` | wc -l >> test100
	@./$(NAME) `jot -r 100 1 1000 | tr '\n' ' '` | wc -l >> test100
	@./$(NAME) `jot -r 100 1 1000 | tr '\n' ' '` | wc -l >> test100
	@./$(NAME) `jot -r 100 1 1000 | tr '\n' ' '` | wc -l >> test100
	@cat test100
	@rm test100

test500: $(NAME)
	@./$(NAME) `jot -r 500 1 1000 | tr '\n' ' '` | wc -l >> test500
	@./$(NAME) `jot -r 500 1 1000 | tr '\n' ' '` | wc -l >> test500
	@./$(NAME) `jot -r 500 1 1000 | tr '\n' ' '` | wc -l >> test500
	@./$(NAME) `jot -r 500 1 1000 | tr '\n' ' '` | wc -l >> test500
	@./$(NAME) `jot -r 500 1 1000 | tr '\n' ' '` | wc -l >> test500
	@./$(NAME) `jot -r 500 1 1000 | tr '\n' ' '` | wc -l >> test500
	@./$(NAME) `jot -r 500 1 1000 | tr '\n' ' '` | wc -l >> test500
	@./$(NAME) `jot -r 500 1 1000 | tr '\n' ' '` | wc -l >> test500
	@cat test500
	@rm test500

re: fclean all