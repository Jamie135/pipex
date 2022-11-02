/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbureera <pbureera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 23:03:55 by pbureera          #+#    #+#             */
/*   Updated: 2022/10/18 23:03:55 by pbureera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child1_process(char **argv, char **envp, int *fd)
{
	int		filein;

	filein = open(argv[1], O_RDONLY, 0777);
	if (filein == -1)
		print_error(ERROR_INFILE);
	dup2(fd[1], STDOUT_FILENO);
	dup2(filein, STDIN_FILENO);
	close(fd[0]);
	close(filein);
	close(fd[1]);
	exe_cmd(argv[2], envp);
}

void	child2_process(char **argv, char **envp, int *fd)
{
	int		fileout;

	fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fileout == -1)
		print_error(ERROR_OUTFILE);
	dup2(fd[0], STDIN_FILENO);
	dup2(fileout, STDOUT_FILENO);
	close(fd[1]);
	close(fileout);
	close(fd[0]);
	exe_cmd(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			print_error(ERROR_PIPE);
		pid1 = fork();
		if (pid1 == -1)
			print_error("Fork");
		if (pid1 == 0)
			child1_process(argv, envp, fd);
		pid2 = fork();
		if (pid2 == -1)
			print_error("Fork");
		if (pid2 == 0)
			child2_process(argv, envp, fd);
		close_wait(fd[0], fd[1], pid1, pid2);
	}
	else
		message_error(ERROR_INPUT);
	return (0);
}
