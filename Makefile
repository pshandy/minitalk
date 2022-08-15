CLIENT	=	client
SERVER	=	server

SRC_C	=	client1.c client2.c
SRC_S	=	server1.c
ADDS	=	additional1.c additional2.c additional3.c
HEADER	=	minitalk.h

CC			=	gcc -Wall -Wextra -Werror
RM			=	rm -f

all: $(SERVER) $(CLIENT)

$(SERVER): $(SRC_S) $(HEADER) $(ADDS)
	$(CC) $(SRC_S) $(ADDS) -o $(SERVER)

$(CLIENT): $(SRC_C) $(HEADER) $(ADDS)
	$(CC) $(SRC_C) $(ADDS) -o $(CLIENT)

clean:
	$(RM) $(CLIENT) $(SERVER)

fclean:
	$(RM) $(CLIENT) $(SERVER)

re: fclean all

bonus:	all

.PHONY: all clean fclean re bonus
