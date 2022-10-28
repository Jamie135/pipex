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

char	**create_path(char **envp)
{
	char	**paths;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (envp[len])
		len++;
	while (ft_strnstr(envp[i], "PATH", 4) == 0 && i < len - 1)
		i++;
	if (ft_strnstr(envp[i], "PATH", 4) == 0)
		return(NULL);
	paths = ft_split(envp[i] + 5, ':');
	return(paths);
}

char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*part_path;
	char	*exec;
	int		i;

	paths = create_path(envp);
	if (!paths)
		return (0);
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		exec = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(exec, F_OK) == 0)
		{
			free_tabs(paths);
			return (exec);
		}
		free(exec);
		i++;
	}
	free_tabs(paths);
	return (0);
}
