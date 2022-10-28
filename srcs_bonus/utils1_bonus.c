/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbureera <pbureera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:17:26 by pbureera          #+#    #+#             */
/*   Updated: 2022/10/28 12:27:23 by pbureera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

void	exe_cmd(char *argv, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, ' ');
	path = find_path(cmd[0], envp);
	if (!path)
	{
		free_tabs(cmd);
		message_error(ERROR_CMD);
	}
	if (execve(path, cmd, envp) == -1)
	{
		free(path);
		free_tabs(cmd);
		message_error(ERROR_CMD);
	}
}

int	get_next_line(char **line)
{
	char	*buffer;
	int		i;
	int		r;
	char	c;

	i = 0;
	r = 0;
	buffer = (char *)malloc(10000);
	if (!buffer)
		return (-1);
	r = read(0, &c, 1);
	while (r && c != '\n' && c != '\0')
	{
		if (c != '\n' && c != '\0')
			buffer[i] = c;
		i++;
		r = read(0, &c, 1);
	}
	buffer[i] = '\n';
	buffer[++i] = '\0';
	*line = buffer;
	free(buffer);
	return (r);
}
