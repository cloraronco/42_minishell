/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:51:22 by aucousin          #+#    #+#             */
/*   Updated: 2022/06/02 09:15:52 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./hdrs/minishell.h"

void	msh_init(t_minishell *msh)
{
	msh->status = 1;
	msh->tokens = NULL;
}

void	msh_loop(void)
{
	t_minishell	msh;
	char		*tmp;
	//char		*readline;

	msh_init(&msh);
	//readline = ft_readline();
	while (msh.status != FINISHED)
	{
		// printf("minish >");
		write(0, "minish >  ", 9);
		tmp = ft_read_line(BUFFER_SIZE, 0, 0);
		msh.line = readline(tmp);
		free(tmp);
		add_history(msh.line);
		//msh_get_tokens(&msh, msh.line);
		printf("line = %s\n", msh.line);
		//ft_printlist(msh.tokens);
	}
}

int	main()
{
	msh_loop();
}