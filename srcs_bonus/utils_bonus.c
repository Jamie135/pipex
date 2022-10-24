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

void	arg_error(void)
{
	ft_putstr_fd("Error: Invalid number of arguments\n", 2);
	ft_putstr_fd("Ex: ./pipex <file1> <cmd1> <cmd2> <...> <file2>\n", 1);
	ft_putstr_fd("    ./pipex \"here_doc\" <LIMITER> ", 1);
	ft_putstr_fd("<cmd> <cmd1> <file>\n", 1);
	exit(EXIT_SUCCESS);
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

	if (i == 0)
		file = open(argv, O_RDONLY, 0777);
	if (i == 1)
		file = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (i == 2)
		file = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (file == -1)
		exit(0);
	return (file);
}

char	*find_env(char *name, char **env)
{
	int		i;
	int		j;
	char	*sub;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		sub = ft_substr(env[i], 0, j);
		if (ft_strcmp(sub, name) == 0)
		{
			free(sub);
			return (env[i] + j + 1);
		}
		free(sub);
		i++;
	}
	return (NULL);
}

char	*find_path(char *cmd, char **env)
{
	int		i;
	char	**paths;
	char	*part_path;
	char	**s_cmd;
	char	*exec;

	i = -1;
	paths = ft_split(find_env("PATH", env), ':');
	s_cmd = ft_split(cmd, ' ');
	while (paths[++i])
	{
		part_path = ft_strjoin(paths[i], "/");
		exec = ft_strjoin(part_path, s_cmd[0]);
		free(part_path);
		if (access(exec, F_OK | X_OK) == 0)
		{
			free_tabs(s_cmd);
			return (exec);
		}
		free(exec);
	}
	free_tabs(paths);
	free_tabs(s_cmd);
	return (cmd);
}
