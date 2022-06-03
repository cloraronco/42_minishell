/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 06:55:47 by aucousin          #+#    #+#             */
/*   Updated: 2022/06/02 07:35:01 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/minishell.h"

t_token	*ft_tokennew(char *str, int type)
{
	t_token	*list;

	list = malloc(sizeof(t_token));
	if (!list)
		return (NULL);
	list->next = NULL;
	list->str = str;
	list->type = type;
	return (list);
}

void	ft_tokenadd_back(t_token **alst, t_token *new)
{
	if (!*alst)
		*alst = new;
	else if ((*alst)->next)
		ft_tokenadd_back(&(*alst)->next, new);
	else
		(*alst)->next = new;
}

void	ft_printlist(t_token *list)
{
	int	i;

	i = 0;
	while (list)
	{
		printf("-----------------------------------\n");
		printf("| i = %d                            \n", i);
		printf("| list->str : %s            \n", list->str);
		printf("| list->type : %d            \n", list->type);
		printf("-----------------------------------\n");
		list = list->next;
		i++;
	}
}
