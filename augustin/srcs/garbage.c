/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 07:03:15 by aucousin          #+#    #+#             */
/*   Updated: 2022/06/02 07:34:42 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/minishell.h"

char	**msh_split_line(t_minishell *minishell)
// call with lines, 64, 0
{
	char	**tokens;
	char	*token;

	minishell->tokens = malloc(sizeof(char *) * buff_size);
	if (!tokens)
	{
		write(2, "allocution error.\n", 17);
		exit(EXIT_FAILURE);
	}
	token = ft_get_token(line, TOKEN_DELIMITERS);
	while (token)
	{
		tokens[pos] = token;
		pos++;
		if (pos >= buff_size)
		{
			buff_size += TOKEN_BUFFSIZE;
			tokens = ft_realloctab(tokens, buff_size);
			if (!tokens)
			{
				write(2, "allocution error.\n", 17);
				exit(EXIT_FAILURE);
			}
		}
	}
	tokens[pos] = NULL;
	return (tokens);
}

char	**msh_split_line(char *line, int buff_size, int pos)
// call with lines, 64, 0
{
	char	**tokens;
	char	*token;

	tokens = malloc(sizeof(char *) * buff_size);
	if (!tokens)
	{
		write(2, "allocution error.\n", 17);
		exit(EXIT_FAILURE);
	}
	token = ft_get_token(line, TOKEN_DELIMITERS);
	while (token)
	{
		tokens[pos] = token;
		pos++;
		if (pos >= buff_size)
		{
			buff_size += TOKEN_BUFFSIZE;
			tokens = ft_realloctab(tokens, buff_size);
			if (!tokens)
			{
				write(2, "allocution error.\n", 17);
				exit(EXIT_FAILURE);
			}
		}
	}
	tokens[pos] = NULL;
	return (tokens);
}

int		msh_count_tokens(char *line)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (line[i])
	{
		while (line[i] && line[i] == ' ')
		{
			i++;
		}
		if (line[i] && ft_isredirection(line[i]))
		{
			if (line[i + 1 && line[i] == line[i + 1]])
				i++;
			count++;
			i++;
		}
		else if (line[i] && ft_isalnum(line[i]))
		{
			while (line[i] && ft_isalnum(line[i]))
			{
				i++;
			}
			count++;
		}
		else if (line[i] && line[i] == '"')
		{
			i++;
			while (line[i] && line[i] != '"')
			{
				i++;
			}
			count++;
		}
		else if (line[i] && line[i] == 39)
		{
			i++;
			while (line[i] && line[i] != 39)
			{
				i++;
			}
			count++;
		}
	}
}
