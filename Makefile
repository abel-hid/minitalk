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

SRC_C	=	client.c
SRC_S	=	server.c

OBJECTS = $(SRC_C:.c=.o)
B_OBJECTS = $(SRC_S:.c=.o)

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

all: $(SERVER) $(CLIENT)


$(SERVER): $(B_OBJECTS)
		$(CC) -o $@ $<

$(CLIENT): $(OBJECTS)
		$(CC) -o $@ $<

%.o: %.c
	$(CC) $(CFLAGS) -c $<


clean:
	$(RM) $(OBJECTS) $(B_OBJECTS)

fclean: clean
	$(RM) $(CLIENT) $(SERVER)

re: fclean $(CLIENT) $(SERVER)

.PHONY: all bonus clean fclean re
