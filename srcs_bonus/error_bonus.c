/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbureera <pbureera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:17:26 by pbureera          #+#    #+#             */
/*   Updated: 2022/10/25 17:17:54 by pbureera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	arg_error(void)
{
	ft_putstr_fd("Error: Invalid number of arguments\n", 2);
	ft_putstr_fd("Ex: ./pipex infile cmd1 cmd2 ... outfile\n", 1);
	ft_putstr_fd("    ./pipex here_doc LIMITER cmd cmd1 file\n", 1);
	exit(EXIT_SUCCESS);
}

void	print_error(char *err)
{
	perror(err);
	exit(EXIT_FAILURE);
}
