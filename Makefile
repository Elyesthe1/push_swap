SRCS = push_swap.c\
	   utils.c\
	   utils2.c\
	   lst.c\
	   lst2.c\
	   instruction.c\
       instruction2.c\
	   parsing.c\
	   sort.c\
	   sortutils.c\


CC = cc
RM = rm -f
FLAGS = -Wall -Werror -Wextra 
NAME = push_swap
OBJS = $(SRCS:.c=.o)

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	cc -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean
