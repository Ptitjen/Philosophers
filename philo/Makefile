# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeulliot <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/26 17:08:49 by jeulliot          #+#    #+#              #
#    Updated: 2022/04/26 17:08:51 by jeulliot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= main.c errors.c ft_atoi.c utils.c ft_putnbr_fd.c

NAME	= philo

RM	= @rm -f

all:	$(NAME)

$(NAME):	${SRCS}
			@gcc -Wall -Wextra -Werror -lpthread -D_REENTRANT ${SRCS} -o ${NAME}
			

clean:

fclean:	clean
	${RM} ${NAME}

re:	fclean all
