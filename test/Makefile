CC = cc
CFLAGS = -Wall -Wextra -Werror -g
NAME = push_swap
SOURCES = ft_putendl_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putchar_fd.c \
		ft_split.c ops_push.c ops_rev_rot.c ops_rot.c ops_swap.c ft_atoi.c \
		input_check.c push_swap.c sort_util.c utils.c ft_calloc.c initialize.c \
		linked_list.c sorting.c
OBJECTS = $(SOURCES:.c=.o)
RM = rm -f

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I .

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)
clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
