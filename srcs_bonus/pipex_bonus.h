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

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>

void	arg_error(void);
void	print_error(char *err);
void	free_tabs(char **tab);
int		open_file(char *argv, int i);
char	*find_env(char *name, char **env);
char	*find_path(char *cmd, char **env);
void	exe_cmd(char *cmd, char **env);

#endif
