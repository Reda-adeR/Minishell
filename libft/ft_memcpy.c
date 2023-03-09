/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:53:53 by rel-mham          #+#    #+#             */
/*   Updated: 2022/10/14 18:42:43 by rel-mham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ctd_src;
	unsigned char	*ctd_dst;
	unsigned int	i;

	ctd_src = (unsigned char *) src;
	ctd_dst = (unsigned char *) dst;
	i = 0;
	if (ctd_src == NULL && ctd_dst == NULL)
		return (NULL);
	while (i < n)
	{
		ctd_dst[i] = ctd_src[i];
		i++;
	}
	return (ctd_dst);
}
