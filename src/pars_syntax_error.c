/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_syntax_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mham <rel-mham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:52:19 by rel-mham          #+#    #+#             */
/*   Updated: 2023/03/27 14:46:24 by rel-mham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*pipe_syntax(t_lex *g)
{
	int		i;
	int		j;
	int		len;
	char	*ret;

	len = ft_double_strlen(g->splited2) - 1;
	j = 0;
	i = 0;
	if (!ft_strcmp(g->splited2[i], "|"))
		return (put_stx_idx(g, "|", i));
	else if (!ft_strcmp(g->splited2[i], ">")
		&& !ft_strcmp(g->splited2[i + 1], "|") && g->splited2[i + 2] == NULL)
		return (put_stx_idx(g, "|", i));
	ret = pipe_syntax_helper(g);
	if (!ret)
	{
		if (!ft_strcmp(g->splited2[len], "|"))
			return (put_stx_idx(g, "|", len));
		else if (!ft_strcmp(g->splited2[len], ">")
			|| !ft_strcmp(g->splited2[len], "<")
			|| !ft_strcmp(g->splited2[len], "<<")
			|| !ft_strcmp(g->splited2[len], ">>"))
			return (put_stx_idx(g, g->splited2[len], len));
	}
	return (ret);
}

char	*syntax_check(t_lex *g)
{
	char	*err;

	if (ft_double_strlen(g->splited2) < 2 && (!ft_strcmp(g->splited2[0], "<")
			|| !ft_strcmp(g->splited2[0], ">") || !ft_strcmp(g->splited2[0],
				"<<") || !ft_strcmp(g->splited2[0], ">>")))
		return (put_stx_idx(g, g->splited2[0], 0));
	else if (!ft_strcmp(g->splited2[0], "<")
		&& !ft_strcmp(g->splited2[1], ">") && g->splited2[2] == NULL)
		return (put_stx_idx(g, g->splited2[0], 0));
	g->k = 0;
	g->space_exist = 0;
	while (g->line[g->k])
	{
		g->here = 0;
		red_syntax_helper(g);
		if (g->line[g->k])
			g->k++;
	}
	err = pipe_syntax(g);
	if (err != NULL)
		return (err);
	return (NULL);
}

int	quotes_check(t_lex *g)
{
	g->id = 0;
	g->sq = 0;
	g->dq = 0;
	while (g->line[g->id])
	{
		quotes_check_helper(g);
		if (g->line[g->id])
			g->id++;
	}
	if ((g->sq % 2) || (g->dq % 2))
		return (0);
	else
		return (1);
}
