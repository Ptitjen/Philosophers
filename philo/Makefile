# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeulliot <jeulliot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/26 17:08:49 by jeulliot          #+#    #+#              #
#    Updated: 2022/05/24 17:08:58 by jeulliot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= src/main.c src/errors.c src/ft_atoi.c src/utils.c src/time.c src/events.c src/init.c

NAME	= philo

RM	= @rm -f

all:	$(NAME)

$(NAME):	${SRCS}			
			@gcc -Wall -Wextra -Werror -lpthread -D_REENTRANT -fsanitize=thread -g ${SRCS} -o ${NAME}
			

clean:

fclean:	clean
	${RM} ${NAME}

re:	fclean all
