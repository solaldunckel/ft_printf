# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/07 12:02:19 by sdunckel          #+#    #+#              #
#    Updated: 2019/10/11 09:59:10 by sdunckel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= ft_printf

SRCS			= \
					ft_ft.c \
					ft_ft2.c \
					ft_parse.c \
					ft_printf.c
OBJS			= ${SRCS:.c=.o}

HEADER			= ft_printf.h

CC				= gcc
CFLAGS 			= #-Wall -Wextra -Werror
RM				= rm -f

all:			${NAME}

$(NAME):		${OBJS}

%.o: %.c
				@${CC} ${CFLAGS} -c -o $@ $< -I ${HEADER}

clean:
				@${RM} ${OBJS}

fclean:			clean
				@${RM} ${NAME}

re:				fclean all

.PHONY: 		all fclean clean re
