/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbureera <pbureera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 23:04:16 by pbureera          #+#    #+#             */
/*   Updated: 2022/10/18 23:04:16 by pbureera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

void	free_tabs(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	open_file(char *argv, int i)
{
	int	file;

	file = 0;
	if (i == 0)
	{
		file = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0777);
		if (file == -1)
			print_error(ERROR_OUTFILE);
	}
	else if (i == 1)
	{
		file = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (file == -1)
			print_error(ERROR_OUTFILE);
	}
	else if (i == 2)
	{
		file = open(argv, O_RDONLY, 0777);
		if (file == -1)
			print_error(ERROR_INFILE);
	}
	return (file);
}
