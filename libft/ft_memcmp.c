/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:06:33 by rel-mham          #+#    #+#             */
/*   Updated: 2022/10/13 23:08:14 by rel-mham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void	*s1, const void	*s2, size_t	n)
{
	unsigned char	*cstd_s1;
	unsigned char	*cstd_s2;
	size_t			i;

	cstd_s1 = (unsigned char *)s1;
	cstd_s2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (cstd_s1[i] != cstd_s2[i])
			return (cstd_s1[i] - cstd_s2[i]);
		i++;
	}
	return (0);
}
