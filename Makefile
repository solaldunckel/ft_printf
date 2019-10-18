# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/07 12:02:19 by sdunckel          #+#    #+#              #
#    Updated: 2019/10/18 21:51:32 by sdunckel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a

SRCS_LIST		= \
					ft_ft.c \
					ft_ft2.c \
					ft_parse.c \
					ft_printf.c \
					ft_libft.c \
					ft_printer.c
SRCS			= $(addprefix ${FOLDER}/, ${SRCS_LIST})

OBJS			= ${SRCS:.c=.o}

HEADER			= includes
FOLDER			= srcs

CC				= gcc
CFLAGS 			= #-Wall -Wextra -Werror
RM				= rm -f

all:			${NAME}

$(NAME):		${OBJS}
				@ar -rcs ${NAME} ${OBJS}
				@${CC} ${CFLAGS} ${SRCS} main.c -I ${HEADER} -o ft_printf

%.o: %.c
				@${CC} ${CFLAGS} -c -o $@ $< -I ${HEADER}

clean:
				@${RM} ${OBJS}

fclean:			clean
				@${RM} ${NAME} ft_printf

re:				fclean all

.PHONY: 		all fclean clean re
