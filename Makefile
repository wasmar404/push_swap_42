FLAG = -Wall -Wextra -Werror

NAME = push_swap

SRC = sort_n.c \
      operations_helper.c \
      one_argument.c \
      one_argument_1.c \
      many_args.c \
      main.c \
	  linked_list.c \
      input.c \
      functions.c \
      free.c \
      error.c \
      cost.c \
	  common_operations.c \
      algo.c \
      algo_helper.c \
      utils/ft_atoi.c \
      utils/ft_split.c \
      stack_b/operations_stack_b.c \
      stack_a/target_of_a.c\
	  stack_a/operations_stack_a.c\
	  stack_a/create_list_a.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@gcc $(FLAG) -o $(NAME) $(OBJ)
	@echo "$(NAME) created"

%.o: %.c
	@gcc $(FLAG) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "OBJ deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted"

re: fclean all

.PHONY: all clean fclean re

