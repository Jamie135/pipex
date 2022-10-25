/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbureera <pbureera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 16:04:57 by pbureera          #+#    #+#             */
/*   Updated: 2022/10/25 17:12:11 by pbureera         ###   ########.fr       */
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

char	*find_path(char *cmd, char **envp);
void	exe_cmd(char *argv, char **envp);
int		get_next_line(char **line);
void	print_error(char *err);
void	arg_error(void);
void	free_tabs(char **tab);
int		open_file(char *argv, int i);

#endif
