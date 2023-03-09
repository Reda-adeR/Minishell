/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mham <rel-mham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:12:05 by rel-mham          #+#    #+#             */
/*   Updated: 2023/03/03 07:34:03 by rel-mham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_stack	*ft_lstnew(char c)
{
	t_stack	*list1;

	list1 = malloc(sizeof(t_stack));
	if (!list1)
		return (NULL);
	list1->c = c;
	list1->next = NULL;
	return (list1);
}

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		new->next = *lst;
		*lst = new;
	}
}

int	ft_lstsize(t_stack *lst)
{
	int	i;

	i = 0;
	if (lst)
	{
		i++;
		while (lst->next)
		{
			lst = lst->next;
			i++;
		}
	}
	return (i);
}

void	add_push(t_stack **lst, char c)
{
	t_stack	*new;

	new = ft_lstnew(c);
	ft_lstadd_front(lst, new);
}

void	free_lst(t_stack *lst)
{
	while (lst)
	{
		free(lst);
		lst = lst->next;
	}
}
