/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 02:20:45 by aucousin          #+#    #+#             */
/*   Updated: 2022/06/09 10:32:35 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/minishell.h"

void	msh_execute_process(t_minishell *msh, t_process *proc)
{
	char	*cmd;
	int		i;

	i = 0;
	while (msh->paths[i])
	{
		cmd = ft_strjoin(msh->paths[i], proc->cmd[0]);
		if (!cmd)
			exit(EXIT_FAILURE);
		if (access(cmd, F_OK) == 0)
			execve(cmd, proc->cmd, msh->envp);
		free(cmd);
		i++;
	}
	write(2, "pipex: command not found: ", 26);
	write(2, proc->cmd[0], ft_strlen(proc->cmd[0]));
	write(2, "\n", 1);
	exit (1);
}

void	msh_child_process(t_minishell *msh, t_process *proc)
{
	if (proc->infile)
	{
		proc->file_in = open(proc->infile, O_RDONLY);
		if (dup2(proc->file_in, STDIN_FILENO < 0))
			perror("Fork: ");
	}
	else if (proc->piped)
	{
		if (dup2(proc->end[1], STDIN_FILENO < 0))
			perror("Fork: ");
	}
	if (proc->outfile)
	{
		proc->file_out = open(proc->outfile,
				O_CREAT | O_WRONLY | O_TRUNC, 0777);
		if (dup2(proc->file_out, STDOUT_FILENO < 0))
			perror("Fork: ");
	}
	else if (proc->next)
	{
		if (dup2(proc->next->end[0], STDOUT_FILENO < 0))
			perror("Fork: ");
	}
	msh_execute_process(msh, proc);
	if (proc->infile)
		close(proc->file_in);
	if (proc->outfile)
		close(proc->file_out);
}

int	msh_execute(t_minishell *msh)
{
	t_process	*l;
//	t_process	*tmp;
	int			status;

	l = msh->process;
	while (l)
	{
		if (l->next)
			pipe(l->next->end);
		l->child = fork();
		if (!l->child)
			msh_child_process(msh, l);
		l = l->next;
	}
	l = msh->process;
	while (l)
	{
		if (l->next)
		{
		close(l->next->end[0]);
		close(l->next->end[1]);
		}
		waitpid(l->child, &status, 0);
		l = l->next;
	}
	return (1);
}
