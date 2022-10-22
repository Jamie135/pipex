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

NAME = pipex

CC = gcc

CFLAGS = -Werror -Wall -Wextra

RM = rm -rf

SRCS = 	srcs/pipex.c\
		srcs/utils.c

OBJS 	= ${SRCS:.c=.o}

SRCS_BONUS = 	srcs_bonus/pipex_bonus.c\
				srcs_bonus/utils_bonus.c

OBJS_BONUS	= ${SRCS_BONUS:.c=.o}

all :	$(NAME)

$(NAME) :	$(OBJS)
	make re -C ./libft
	$(CC) $(CFLAGS) $(OBJS) -Llibft -lft -o $(NAME)

bonus :	$(OBJS_BONUS)
	make re -C ./libft
	$(CC) $(CFLAGS) $(OBJS_BONUS) -Llibft -lft -o $(NAME)

clean :
	make clean -C ./libft
	$(RM) $(NAME)
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean : clean
	make fclean -C ./libft
	$(RM) $(NAME)

re : fclean all