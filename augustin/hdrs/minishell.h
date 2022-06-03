/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:37:47 by aucousin          #+#    #+#             */
/*   Updated: 2022/06/02 09:08:42 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define BUFFER_SIZE 2048
# define TOKEN_BUFFSIZE 64
# define TOKEN_DELIMITERS "\t\r\n\a"
# define TEXT 1
# define SQTEXT 8
# define DQTEXT 9
# define PIPE 2
# define DPIPE 3
# define RRED 4
# define DRRED 5
# define LRED 6
# define DLRED 7

# define READING 1
# define FINISHED 0

// INCLUDES

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>

// STRUCTS FOR CONVENIANCE

typedef struct s_token
{
	char			*str;
	int				type;
	struct s_token	*next;
}					t_token;

typedef struct s_minishell
{
	int				status;
	char			*line;
	char			**tokenstab;
	char			**args;
	t_token			*tokens;
}		t_minishell;

// MANDATORY FCTS

char	*ft_read_line(int buff_size, int pos, int c);
void	msh_get_tokens(t_minishell *msh, char *line);

// list utils

t_token	*ft_tokennew(char *str, int type);
void	ft_tokenadd_back(t_token **alst, t_token *new);
void	ft_printlist(t_token *list);

// utils

char	*ft_strndup(char const *src, int n);
int		ft_len_alnum(char *str);
int		ft_lenquote(char *str);
int		ft_lendbquote(char *str);
void	ft_exit_fd(int fd, char *str);
char	*ft_realloc(char *str, int size);
int		ft_isprintsh(int c);

#endif