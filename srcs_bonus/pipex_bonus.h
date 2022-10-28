/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbureera <pbureera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 16:04:57 by pbureera          #+#    #+#             */
/*   Updated: 2022/10/28 11:49:58 by pbureera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../libft/libft.h"

# define ERROR_INFILE "Infile"
# define ERROR_OUTFILE "Outfile"
# define ERROR_INPUT "Invalid number of arguments\nEx: ./pipex infile cmd1 cmd2 ... outfile\n    ./pipex here_doc LIMITER cmd cmd1 ... outfile\n"
# define ERROR_PIPE "Pipe"
# define ERROR_FORK "Fork"
# define ERROR_CMD "Command not found\n"

char	*find_path(char *cmd, char **envp);
void	exe_cmd(char *argv, char **envp);
int		get_next_line(char **line);
void	print_error(char *err);
int		message_error(char *err);
void	free_tabs(char **tab);
int		open_file(char *argv, int i);

#endif
