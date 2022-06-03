/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 09:20:25 by aucousin          #+#    #+#             */
/*   Updated: 2022/06/02 07:59:24 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/minishell.h"

void	msh_get_tokens(t_minishell *msh, char *line)
{
	int		i;
	t_token	*token;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		while (line[i] && line[i] == ' ')
			i++;
		if (line[i] && ft_isprintsh(line[i]))
		{
			token = ft_tokennew(ft_strndup(&line[i], ft_len_alnum(&line[i])), TEXT);
			i += ft_len_alnum(&line[i]);
		}
		else if (line[i] && (line[i]) == 39)
		{
			if (ft_lenquote(&line[i]) == -1)
				ft_exit_fd(1, "unvalid single quote.");
			token = ft_tokennew(ft_strndup(&line[i], ft_lenquote(&line[i])), SQTEXT);
			i += ft_lenquote(&line[i]);
			printf("bloqued chapochapo\n");
		}
		else if (line[i] && (line[i]) == '"')
		{
			token = ft_tokennew(ft_strndup(&line[i], ft_lendbquote(&line[i])), DQTEXT);
			i += ft_lendbquote(&line[i]);
		}
		else if (line[i] && (line[i]) == '>' && ((line[i + 1] && line[i + 1] != '>') || !line[i + 1]))
		{
			token = ft_tokennew(ft_strndup(&line[i], 1), RRED);
			i += 1;
		}
		else if (line[i] && (line[i]) == '>' && line[i + 1] && line[i + 1] == '>')
		{
			token = ft_tokennew(ft_strndup(&line[i], 2), DRRED);
			i += 2;
		}
		else if (line[i] && (line[i]) == '<' && ((line[i + 1] && line[i + 1] != '<') || !line[i + 1]))
		{
			token = ft_tokennew(ft_strndup(&line[i], 1), LRED);
			i += 1;
		}
		else if (line[i] && (line[i]) == '<' && line[i + 1] && line[i + 1] == '<')
		{
			token = ft_tokennew(ft_strndup(&line[i], 2), DLRED);
			i += 2;
		}
		else if (line[i] && (line[i]) == '|' && ((line[i + 1] && line[i + 1] != '|') || !line[i + 1]))
		{
			token = ft_tokennew(ft_strndup(&line[i], 1), RRED);
			i += 1;
		}
		else if (line[i] && (line[i]) == '|' && line[i + 1] && line[i + 1] == '|')
		{
			token = ft_tokennew(ft_strndup(&line[i], 2), DRRED);
			i += 2;
		}
		else
		{
			i++;
		}
		ft_tokenadd_back(&msh->tokens, token);
	}
}