/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 20:19:18 by rel-mham          #+#    #+#             */
/*   Updated: 2022/10/23 22:48:46 by rel-mham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*cstd_dest;
	char	*cstd_src;
	size_t	i;

	i = 0;
	cstd_dest = (char *)dest;
	cstd_src = (char *)src;
	if (cstd_dest == NULL && cstd_src == NULL)
		return (NULL);
	if (cstd_dest >= cstd_src)
	{
		i = len;
		while (i-- > 0)
			cstd_dest[i] = cstd_src[i];
	}
	while (i < len)
	{
		cstd_dest[i] = cstd_src[i];
		i++;
	}
	return (cstd_dest);
}
