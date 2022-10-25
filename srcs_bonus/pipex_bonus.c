/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbureera <pbureera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 18:10:07 by pbureera          #+#    #+#             */
/*   Updated: 2022/10/22 18:10:07 by pbureera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	exe_cmd(char *cmd, char **env)
{
	char	**s_cmd;
	char	*path;

	s_cmd = ft_split(cmd, ' ');
	path = find_path(s_cmd[0], env);
	if (execve(path, s_cmd, env) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(s_cmd[0], 2);
		free_tabs(s_cmd);
		exit(0);
	}
}

void	here_doc_input(char **argv, int *fd)
{
	char	*line;

	close(fd[0]);
	while (1)
	{
		line = get_next_line(0);
		if (ft_strncmp(line, argv[2], ft_strlen(argv[2])) == 0)
		{
			free(line);
			exit(0);
		}
		ft_putstr_fd(line, fd[1]);
		free(line);
	}
}

void	here_doc(char **argv)
{
	int		fd[2];
	pid_t	pid1;

	if (pipe(fd) == -1)
		exit(0);
	pid1 = fork();
	if (pid1 == -1)
		exit(0);
	if (pid1 == 0)
		here_doc_input(argv, fd);
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
		wait(NULL);
	}
}

void	mult_cmd(char *cmd, char **env)
{
	pid_t	pid1;
	int		fd[2];

	if (pipe(fd) == -1)
		exit(0);
	pid1 = fork();
	if (pid1 == -1)
		exit(0);
	if (pid1 == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		exe_cmd(cmd, env);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
	}
}

int	main(int argc, char **argv, char **env)
{
	int		i;
	int		fd_in;
	int		fd_out;

	if (argc < 5)
		arg_error();
	if (ft_strcmp(argv[1], "here_doc") == 0)
	{
		if (argc < 6)
			arg_error();
		i = 3;
		fd_out = open_file(argv[argc - 1], 2);
		here_doc(argv);
	}
	else
	{
		i = 2;
		fd_in = open_file(argv[1], 0);
		fd_out = open_file(argv[argc - 1], 1);
		dup2(fd_in, 0);
	}
	while (i < argc - 2)
		mult_cmd(argv[i++], env);
	dup2(fd_out, 1);
	exe_cmd(argv[argc - 2], env);
}
