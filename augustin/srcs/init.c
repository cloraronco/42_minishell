/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 08:04:34 by aucousin          #+#    #+#             */
/*   Updated: 2022/06/09 10:26:00 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/minishell.h"

void	ft_add_slash(t_minishell *pipex)
{
	int		i;
	char	*tmp;

	i = 0;
	while (pipex->paths[i])
	{
		if (pipex->paths[i][ft_strlen(pipex->paths[i]) - 1] != '/')
		{
			tmp = pipex->paths[i];
			pipex->paths[i] = ft_strjoin(tmp, "/");
			free(tmp);
		}
		i++;
	}
}

void	msh_init(t_minishell *msh, char **envp)
{
	char	*path;
	char	*tmp;
	int		i;

	msh->status = 1;
	msh->tokens = NULL;
	msh->process = NULL;
	msh->tokenstab = NULL;
	msh->args = NULL;
	msh->envp = envp;
	msh->line = NULL;
	tmp = ft_tabjoin(ft_tablen(envp), envp, "\n");
	if (!tmp)
		return ;
	i = ft_strlen(ft_strstr(tmp, "PATH="));
	path = ft_substr(tmp, ft_strlen(tmp) - i + 5, i - 5);
	free(tmp);
	if (!path)
		return ;
	msh->paths = ft_split(path, ':');
	free(path);
	ft_add_slash(msh);
}
