NAME= minitalk
SERV= server
CLI= client
C_SRC= client.c utils.c
S_SRC= server.c utils.c
FLAGS= -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(CLI) $(SERV)

$(SERV):
	gcc $(FLAGS) $(S_SRC) -o $(SERV)

$(CLI):
	gcc $(FLAGS) $(C_SRC) -o $(CLI)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(CLI) $(SERV)

re: fclean all

.PHONY: clean fclean all re