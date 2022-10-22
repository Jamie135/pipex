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

CFLAGS = -Werror -Wall -Wextra -g

RM = rm -rf

SRCS = 	srcs/pipex.c\
		srcs/utils.c\
		libft/libft.a

OBJS 	= ${SRCS:.c=.o}

SRCS_BONUS = 	srcs_bonus/pipex_bonus.c\
				srcs_bonus/utils1_bonus.c\
				srcs_bonus/utils2_bonus.c\
				libft/libft.a

OBJS_BONUS	= ${SRCS_BONUS:.c=.o}


all :	$(NAME)

$(NAME) :
	make re -C ./libft
	gcc $(CFLAGS) $(SRCS) -o $(NAME)

clean :
	make clean -C ./libft
	$(RM) $(NAME)
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean : clean
	make fclean -C ./libft
	$(RM) $(NAME)

re : fclean all

bonus :
	make re -C ./libft
	gcc $(CFLAGS) $(SRCS_BONUS) -o $(NAME)