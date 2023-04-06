NAME = push_swap
NAMEB = checker

SRC = push_swap.c \
		move.c \
		move2.c \
		libf1.c \
		libf2.c \
		libf3.c \
		ft_intindex.c \
		ft_sort_3number.c \
		ft_sort_5number.c \
		ft_sort_100number.c \

SRCB = checker.c \
		move.c \
		move2.c \
		libf1.c \
		libf2.c \
		libf3.c \
		ft_intindex.c \
		ft_sort_3number.c \
		ft_sort_5number.c \
		ft_sort_100number.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \
 

OBJ = $(SRC:%.c=%.o)

OBJB = $(SRCB:%.c=%.o)


CFALGS =  -Wall -Wextra -Werror

CC = cc

INCLUDE = push_swap.h get_next_line/get_next_line.h

all: $(NAME)

$(NAME): $(OBJ)

bonus : $(NAMEB)

$(NAMEB): $(OBJB)

%.o : %.c $(INCLUDE)
	$(CC) $(CFALGS) -c $< -o $@

clean:
	@rm -rf $(OBJ) $(OBJB)

fclean: clean
	@rm -rf $(NAME)

re: fclean all