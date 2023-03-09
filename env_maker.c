/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_maker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mham <rel-mham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:49:00 by rel-mham          #+#    #+#             */
/*   Updated: 2023/03/06 18:29:21 by rel-mham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_trim(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (ft_strdup(""));
	if (str[i] == '\"' && str[ft_strlen(str) - 1] == '\"')
	{
		str[ft_strlen(str) - 1] = '\0';
		return (ft_strdup(str + 1));
	}
	else if (str[i] == '\'' && str[ft_strlen(str) - 1] == '\'')
	{
		str[ft_strlen(str) - 1] = '\0';
		return (ft_strdup(str + 1));
	}
	else
		return (ft_strdup(str));
}

t_env	*ft_lstnew2(char *var, int f)
{
	t_env	*new;
	char	**tmp;
	int		i;

	i = 0;
	(void)f;
	new = malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	tmp = ft_split(var, '=');
	if (f == 1)
		free(var);
	if (tmp[0][ft_strlen(tmp[0]) - 1] == '+')
		tmp[0][ft_strlen(tmp[0]) - 1] = '\0';
	new->var = tmp[0];
	new->value = ft_trim(tmp[1]);
	new->next = NULL;
	if (tmp[1])
		free(tmp[1]);
	free(tmp);
	return (new);
}


t_env	*ft_lstadd_back(t_env **env, t_env *new)
{
	t_env	*tmp;

	tmp = *env;
	if (!*env)
		return (new);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (*env);
}


char *ft_get_value(char *var)
{
	t_env	*tmp;

	tmp = g_env.env;
	while (tmp)
	{
		if (ft_strcmp(tmp->var, var) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

void	make_env(char **envp)
{
	int i;

	i = 0;
	
	if (*envp)
	{
		g_env.env = ft_lstnew2(envp[i++], 0);
		while (envp[i])
		{
			if (envp[i + 1] == NULL)
			{
				ft_lstadd_back(&g_env.env, ft_lstnew2("_=/usr/bin/env", 0));
				i++;
			}
			else if (ft_strncmp(envp[i], "OLDPWD", 6) == 0)
				i++;
			else
				ft_lstadd_back(&g_env.env, ft_lstnew2(envp[i++], 0));
		}
	}
	else
	{
		g_env.env = ft_lstnew2(ft_strjoin("PWD=", getcwd(NULL, 0)), 1);
		ft_lstadd_back(&g_env.env, ft_lstnew2("SHLVL=1", 0));
		ft_lstadd_back(&g_env.env, ft_lstnew2("_=/usr/bin/env", 0));
	}
}




