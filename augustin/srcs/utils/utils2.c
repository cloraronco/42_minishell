/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 10:25:05 by aucousin          #+#    #+#             */
/*   Updated: 2022/06/09 10:26:10 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/minishell.h"

int	ft_tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

int	ft_len_total(int size, char **strs, char *sep)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (i < size)
	{
		len += ft_strlen(strs[i]);
		if (i < size - 1)
			len += ft_strlen(sep);
		i++;
	}
	return (len);
}

char	*ft_tabjoin(int size, char **strs, char *sep)
{
	char	*join;
	int		i;

	i = 0;
	join = malloc((ft_len_total(size, strs, sep) + 1) * sizeof(char));
	if (!join)
		return (NULL);
	join[0] = '\0';
	while (i < size)
	{
		ft_strcat(join, strs[i]);
		if (i < size - 1)
			ft_strcat(join, sep);
		i++;
	}
	return (join);
}
