/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbureera <pbureera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 02:19:19 by pbureera          #+#    #+#             */
/*   Updated: 2022/11/02 16:47:25 by pbureera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_error(char *err)
{
	perror(err);
	exit(EXIT_FAILURE);
}

int	message_error(char *err)
{
	write(2, err, ft_strlen(err));
	return (1);
}

void	cmd_error(char *argv, char **cmd)
{
	free_tabs(cmd);
	message_error(ERROR_CMD);
	ft_putendl_fd(argv, 2);
	exit(EXIT_FAILURE);
}

void	close_wait(int fd1, int fd2, pid_t pid1, pid_t pid2)
{
	close(fd1);
	close(fd2);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

void	free_tabs(char **tab)
{
	size_t	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			if (tab[i])
			{
				free(tab[i]);
				tab[i] = NULL;
			}
			i++;
		}
		free(tab);
		tab = NULL;
	}
}
