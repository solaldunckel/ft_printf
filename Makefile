# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/07 12:02:19 by sdunckel          #+#    #+#              #
#    Updated: 2019/10/17 14:01:05 by sdunckel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= ft_printf

SRCS_LIST		= \
					ft_ft.c \
					ft_ft2.c \
					ft_parse.c \
					ft_printf.c \
					ft_printer.c \
					main.c
SRCS			= $(addprefix ${FOLDER}/, ${SRCS_LIST})

OBJS			= ${SRCS:.c=.o}

HEADER			= includes
FOLDER			= srcs

CC				= gcc
CFLAGS 			= #-Wall -Wextra -Werror
RM				= rm -f

all:			${NAME}

$(NAME):		${OBJS}
				@${CC} ${CFLAGS} ${SRCS} -I ${HEADER} -o ${NAME}

%.o: %.c
				@${CC} ${CFLAGS} -c -o $@ $< -I ${HEADER}

clean:
				@${RM} ${OBJS}

fclean:			clean
				@${RM} ${NAME}

re:				fclean all

.PHONY: 		all fclean clean re
