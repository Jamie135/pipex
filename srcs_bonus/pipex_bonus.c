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

int	check_limiter(char *limiter, char *line)
{
	int	i;

	i = 0;
	if (ft_strlen(limiter) == ft_strlen(line) - 1)
	{
		while (line[i])
		{
			if (limiter[i] != line[i] && i > (int)ft_strlen(limiter))
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

void	here_doc_input(char *limiter, char *line, int fd)
{
	if (check_limiter(limiter, line))
		exit(EXIT_SUCCESS);
	write(1, "> ", 2);
	write(fd, line, ft_strlen(line));
}

void	here_doc(char *limiter, int argc)
{
	pid_t	file;
	int		fd[2];
	char	*line;

	if (argc < 6)
		message_error(ERROR_INPUT);
	if (pipe(fd) == -1)
		print_error(ERROR_PIPE);
	file = fork();
	if (file == 0)
	{
		write(1, "> ", 2);
		close(fd[0]);
		while (get_next_line(&line))
			here_doc_input(limiter, line, fd[1]);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		wait(NULL);
	}
}

void	do_process(char *argv, char **envp)
{
	int		fd[2];
	pid_t	pid1;

	if (pipe(fd) == -1)
		print_error(ERROR_PIPE);
	pid1 = fork();
	if (pid1 == -1)
		print_error(ERROR_FORK);
	if (pid1 == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		exe_cmd(argv, envp);
	}
	else
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[1]);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	filein;
	int	fileout;

	if (argc >= 5)
	{
		if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		{
			i = 3;
			fileout = open_file(argv[argc - 1], 0);
			here_doc(argv[2], argc);
		}
		else
		{
			i = 2;
			fileout = open_file(argv[argc - 1], 1);
			filein = open_file(argv[1], 2);
			dup2(filein, STDIN_FILENO);
		}
		while (i < argc - 2)
			do_process(argv[i++], envp);
		dup2(fileout, STDOUT_FILENO);
		exe_cmd(argv[argc - 2], envp);
	}
	message_error(ERROR_INPUT);
}
