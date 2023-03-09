/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:43:03 by rel-mham          #+#    #+#             */
/*   Updated: 2022/10/13 23:07:02 by rel-mham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void	*s, int c, size_t	n)
{
	const char	*cstd_s;
	size_t		i;

	cstd_s = (char *)s;
	i = 0;
	while (n > 0)
	{
		if (cstd_s[i] == (char)c)
			return ((void *)cstd_s + i);
		i++;
		n--;
	}
	return (0);
}
