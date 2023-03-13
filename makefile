NAME = push_swap

SRC = test1.c \
		move.c \
		move2.c \
		libf1.c \
		ft_sort_3number.c \
		ft_sort_5number.c \
 

OBJ = $(SRC:%.c=%.o)


CFALGS =  -Wall -Wextra -Werror

CC = cc

INCLUDE = push_swap.h

all: $(NAME)

$(NAME): $(OBJ)

%.o : %.c $(INCLUDE)
	@$(CC) $(CFALGS) -c $< -o $@


clean:
	@rm -rf $(OBJ) $(OBJB)

fclean: clean
	@rm -rf $(NAME)

re: fclean all