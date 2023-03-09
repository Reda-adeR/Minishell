/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mham <rel-mham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 21:11:11 by rel-mham          #+#    #+#             */
/*   Updated: 2023/03/09 14:40:39 by rel-mham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*ft_lstfinalnew(void)
{
	t_cmd	*new;

	new = malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	new->in = -2;
	new->out = -2;
	new->param = NULL;
	new->heredoc = NULL;
	new->next = NULL;
	return (new);
}

t_cmd	*ft_lstlast(t_cmd	*s)
{
	if (!s)
		return (s);
	while (s->next)
		s = s->next;
	return (s);
}

void	ft_lstadd_backfinal(t_cmd **env, t_cmd *new)
{
	t_cmd	*tmp;

	if (!*env)
	{
		*env = new;
		return ;
	}
	tmp = ft_lstlast(*env);
	tmp->next = new;
}

void	fill_the_list(t_lex *g, t_cmd **lst_final)
{
	t_cmd	*new;
	char	*full_cmd;
	char	*full_heredoc;
	int	i = 0;

	while (g->splited2[i])
	{
		new = ft_lstfinalnew();
		full_cmd = ft_strdup("");
		full_heredoc = ft_strdup("");
		while (g->splited2[i] && ft_strcmp(g->splited2[i], "|"))
		{
			if (ft_strcmp(g->splited2[i], "<<") && ft_strcmp(g->splited2[i], "<") && ft_strcmp(g->splited2[i], ">>") && ft_strcmp(g->splited2[i], ">") && ft_strcmp(g->splited2[i], "|"))
			{
				while (g->splited2[i] && ft_strcmp(g->splited2[i], "<<") && ft_strcmp(g->splited2[i], "<") && ft_strcmp(g->splited2[i], ">>") 
						&& ft_strcmp(g->splited2[i], ">") && ft_strcmp(g->splited2[i], "|"))
				{
					full_cmd = ft_strjoin(full_cmd, g->splited2[i]);
					full_cmd = ft_strjoin(full_cmd, " ");
					i++;
				}
				i--;
				new->param = ft_split_qk(full_cmd, ' ');
				free(full_cmd);
			}
			else if (!ft_strcmp(g->splited2[i], ">"))
			{
				if (!ft_strcmp(g->splited2[i + 1], "|"))
				{
					i++;
					new->out = open(g->splited2[i + 1], O_CREAT | O_RDONLY | O_WRONLY | O_TRUNC, 0644);
					if (new->out == -1)
					{
						printf("Minishell: ");
						perror(g->splited2[i + 2]);
					}
				}
				else
				{
					new->out = open(g->splited2[i + 1], O_CREAT | O_WRONLY | O_RDONLY | O_TRUNC, 0644);
					if (new->out == -1)
					{
						printf("%s\n", g->splited2[i + 1]);
						printf("Minishell: ");
						perror(g->splited2[i + 1]);
					}
				}
				i++;
			}
			else if (!ft_strcmp(g->splited2[i], "<"))
			{
				if (!ft_strcmp(g->splited2[i + 1], ">"))
					i++;
				new->in = open(g->splited2[i + 1], O_RDONLY);
				if (new->in == -1)
				{
					printf("Minishell: ");
					perror(g->splited2[i + 1]);
				}
				i++;
			}
			else if (!ft_strcmp(g->splited2[i], ">>"))
			{
				new->out = open(g->splited2[i + 1], O_CREAT | O_APPEND | O_RDWR, 0644);
				if (new->out == -1)
				{
					printf("Minishell: ");
					perror(g->splited2[i + 1]);
				}
				i++;
			}
			else if (!ft_strcmp(g->splited2[i], "<<"))
			{
				i++;
				full_heredoc = ft_strjoin(full_heredoc, g->splited2[i]);
				full_heredoc = ft_strjoin(full_heredoc, " ");
			}
			if (g->splited2[i])
				i++;
		}
		if (!*full_heredoc)
				{
					free (full_heredoc);
					full_heredoc = NULL;
				}
		if (full_heredoc)
		{
			new->heredoc = ft_split_qk(full_heredoc, ' ');
			free(full_heredoc);
		}
		ft_lstadd_backfinal(lst_final, new);
		if (g->splited2[i])
			i++;
	}
}