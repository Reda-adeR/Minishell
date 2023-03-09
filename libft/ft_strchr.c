/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mham <rel-mham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:55:19 by rel-mham          #+#    #+#             */
/*   Updated: 2023/02/24 18:04:32 by rel-mham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char	*s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char )c)
			return ((char *) s + i);
		i++;
	}
	if ((char)c == '\0')
		return ((char *) s + i);
	return (NULL);
}

#include<stdio.h>
int main()
{
	printf("%s\n", ft_strchr(";cghg|wchel|dash", '|'));
}