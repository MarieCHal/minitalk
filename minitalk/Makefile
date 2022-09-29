# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchalard <mchalard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/30 15:08:51 by mchalard          #+#    #+#              #
#    Updated: 2022/03/31 10:27:01 by mchalard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Wextra -Werror
CC = gcc
src1 = utils.c
obj1=$(src1:.c=.o)
server = server
client = client
all: $(server) $(client)

$(server):$(obj1) 	utils.h
	$(CC) $(FLAG) server.c $(obj1) -o $(server)
$(client):$(obj1) 	utils.h
	$(CC) $(FLAG) client.c $(obj1) -o $(client)
%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -rf $(obj1)
fclean: clean
	rm -rf $(client) $(server)
re: fclean all