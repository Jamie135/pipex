/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbureera <pbureera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 16:04:57 by pbureera          #+#    #+#             */
/*   Updated: 2022/10/22 16:19:53 by pbureera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../libft/libft.h"

void	print_error(void);
void	free_tabs(char **tab);
char	*find_path(char *cmd, char **envp);
void	exe_cmd(char *argv, char **envp);

void	arg_error(void);
int		open_file(char *argv, int i);
int		get_next_line(char **line);

#endif
