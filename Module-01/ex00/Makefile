NAME = BraiiiiiiinnnzzzZ
SRCS = main.cpp newZombie.cpp randomChump.cpp Zombie.cpp
OBJS = $(SRCS:.cpp=.o)
C = c++ -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	$(C) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re