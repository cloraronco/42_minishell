/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:50:29 by aucousin          #+#    #+#             */
/*   Updated: 2022/06/03 14:57:12 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/minishell.h"

int	msh_pwd(int fd)
{
	char	*str;

	str = getcwd(NULL, 0);
	if (!str)
		return (-1);
	write(fd, str, ft_strlen(str));
	write(fd, "\n", 1);
	free(str);
	return (1);
}
