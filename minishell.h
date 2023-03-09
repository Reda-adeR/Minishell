/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mham <rel-mham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:37:39 by rel-mham          #+#    #+#             */
/*   Updated: 2023/03/09 14:30:29 by rel-mham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include <dirent.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "libft/libft.h"

typedef struct s_stack
{
	char			c;
	struct s_stack	*next;
}	t_stack;

typedef struct s_lex
{
	int		i;
	int		j;
	int		k;
	int		idx;
	int		space_exist;
	int		here;
	int		len;
	int		sq;
	int		dq;
	int		id;
	char	**splited1;
	char	**splited2;
	char	**sub_split;
	char	*line;
	char	*new_line_tmp;
	char	*new_line_join;
}		t_lex;

typedef struct s_cmd
{
	int				in;
	int				out;
	int				err;
	char			**heredoc;
	char			**param;
	struct s_cmd	*next;
}		t_cmd;

typedef struct s_envp
{
	char			*var;
	char			*value;
	struct s_envp	*next;
}					t_env;

typedef struct s_export
{
	char			*var;
	struct s_export	*next;
}					t_export;

struct				s_env
{
	int				status;
	t_env			*env;
	t_export		*export;
};

struct s_env		g_env;

void	make_env(char **envp);
void	free_sub_split(char **splited);
char 	*ft_get_value(char *var);
int		lex(t_lex *g);
void	expand_me(t_lex *g);
char	*lst_to_str(t_stack *lst);
void	ft_transfert(t_lex *g);
int		quotes_check(t_lex *g);
char	*syntax_check(t_lex *g);
int		ft_lstsize(t_stack *lst);
t_stack	*ft_lstnew(char c);
void	add_push(t_stack **lst, char c);
void	free_lst(t_stack *lst);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void	fill_the_list(t_lex *g, t_cmd **lst_final);

#endif
