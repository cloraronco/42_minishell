/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 12:52:35 by aucousin          #+#    #+#             */
/*   Updated: 2022/06/03 14:50:42 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/minishell.h"

static int	echo_checkarg(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' && str[i + 1] == 'n')
	{
		i++;
		while (str[i])
		{
			if (str[i] != 'n')
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

int	msh_echo(char **args, int fd)
{
	int	i;
	int	checkarg;

	i = 0;
	checkarg = 0;
	while (args[i] && echo_checkarg(args[i]))
		i++;
	checkarg = i;
	while (args[i])
	{
		write(fd, args[i], ft_strlen(args[i]));
		if (args[i + 1])
			write(fd, " ", 1);
		i++;
	}
	if (checkarg)
		write(fd, "\n", 1);
	return (1);
}
