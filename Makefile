# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbureera <pbureera@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 23:03:19 by pbureera          #+#    #+#              #
#    Updated: 2022/10/18 23:03:19 by pbureera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PIPEX	= pipex
PIPEX_B  = pipex_bonus

SRCS 	= srcs/pipex.c srcs/utils.c
OBJS 	= ${SRCS:.c=.o}

SRCS_B	= srcs/pipex_bonus.c srcs/utils.c srcs/utils_bonus.c
OBJS_B	= ${SRCS_B:.c=.o}

INCLUDES	= -Iincludes

CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror -g

.c.o:		%.o : %.c
					gcc ${CFLAGS} ${INCLUDES} -c $< -o $(<:.c=.o)

all: 		${PIPEX}

${PIPEX}:	${OBJS}
					make re -C ./libft
					$(CC) ${OBJS} -Llibft -lft -o ${PIPEX}

bonus:		${PIPEX_B}

${PIPEX_B}:	${OBJS_B}
					make re -C ./libft
					$(CC) ${OBJS_B} -Llibft -lft -o ${PIPEX_B}

clean:
					make clean -C ./libft
					rm -f ${OBJS} ${OBJS_B}

fclean: 	clean
					make fclean -C ./libft
					rm -f $(NAME)
					rm -f ${PIPEX}

re:			fclean all

re_bonus:	fclean bonus

.PHONY: all clean fclean re re_bonus bonus