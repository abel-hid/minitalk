# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abel-hid <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/01 16:16:30 by abel-hid          #+#    #+#              #
#    Updated: 2023/01/01 16:16:34 by abel-hid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CLIENT	=	client
SERVER	=	server

C	=	client_bonus
S	=	server_bonus

SRC_C	=	client.c\
			utils.c\

SRC_S	=	server.c \
			utils.c


BONUS_SRC_C = client_bonus.c\
				utils.c\
				utils2.c\

BONUS_SRC_S = server_bonus.c \
				utils.c\
				utils2.c\


C_OBJECTS = $(SRC_C:.c=.o)
S_OBJECTS = $(SRC_S:.c=.o)

BONUS_C_OBJECTS = $(BONUS_SRC_C:.c=.o)
BONUS_S_OBJECTS = $(BONUS_SRC_S:.c=.o)


CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

all: $(SERVER) $(CLIENT)


$(SERVER): $(S_OBJECTS)
		$(CC) $(CFLAGS) $(S_OBJECTS) -o $(SERVER)

$(CLIENT): $(C_OBJECTS)
		$(CC) $(CFLAGS) $(C_OBJECTS) -o $(CLIENT)


bonus : $(S) $(C)

 $(S): $(BONUS_S_OBJECTS)
	$(CC) $(CFLAGS) $(BONUS_S_OBJECTS) -o $(S)

$(C): $(BONUS_C_OBJECTS)
	$(CC) $(CFLAGS) $(BONUS_C_OBJECTS) -o $(C)

%.o: %.c minitalk.h bonus_minitalk.h
	$(CC) $(CFLAGS) -c $<


clean:
	$(RM) $(C_OBJECTS) $(S_OBJECTS) $(BONUS_S_OBJECTS) $(BONUS_C_OBJECTS)

fclean: clean
	$(RM) $(CLIENT) $(SERVER) $(S) $(C)

re: fclean $(CLIENT) $(SERVER) $(S) $(C)

.PHONY: all bonus clean fclean re
