# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jenny <jenny@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/26 17:08:49 by jeulliot          #+#    #+#              #
#    Updated: 2022/05/25 15:51:44 by jenny            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo

INCLUDES = includes/philosophers.h

SRCS	= src/main.c \
			src/philosophers.c \
			src/init.c \
			src/events.c \
			src/errors.c \
			src/ft_atoi.c \
			src/time.c \
			src/close.c

OBJS	= ${SRCS:.c=.o}	

CFLAGS	= -Wall -Wextra -Werror

THREADFLAGS = -pthread -D_REENTRANT 

SANFLAGS = -fsanitize=thread -g

RM	= @rm -f

$(NAME):	${OBJS}			
			@gcc ${CFLAGS} ${THREADFLAGS} ${SRCS} -o ${NAME}

all:	$(NAME) ${OBJS} ${INCLUDES}

%.o: %.c ${INCLUDES}
		@gcc ${CFLAGS} -c $< -o $@

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re:	fclean all
