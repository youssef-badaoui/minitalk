HEADER = minitalk.h

SER_SRC = server.c tools.c
SER_OBJ = $(SER_SRC:.c=.o)

CL_SRC = client.c tools.c
CL_OBJ = $(CL_SRC:.c=.o)

SER_SRC_BONUS = server_bonus.c tools.c
SER_OBJ_BONUS = $(SER_SRC_BONUS:.c=.o)

CL_SRC_BONUS = client_bonus.c tools.c
CL_OBJ_BONUS = $(CL_SRC_BONUS:.c=.o)

CC = cc

FLAGS = -Wall -Wextra -Werror

EX_SER = server

EX_CL = client

NAME = Minitalk

all: $(NAME)

$(NAME): $(SER_OBJ) $(CL_OBJ)
	$(CC) $(FLAGS) $(SER_SRC) -o $(EX_SER)
	$(CC) $(FLAGS) $(CL_SRC) -o $(EX_CL)

%.o : %.c
	$(CC) $(FLAGS) -c $<

bonus: $(SER_OBJ_BONUS) $(CL_OBJ_BONUS)
	$(CC) $(FLAGS) $(SER_SRC_BONUS) -o $(EX_SER)
	$(CC) $(FLAGS) $(CL_SRC_BONUS) -o $(EX_CL)

clean:
	rm -f $(SER_OBJ) $(CL_OBJ) $(SER_OBJ_BONUS) $(CL_OBJ_BONUS)

fclean: clean
	rm -f $(EX_CL) $(EX_SER)

re: fclean all