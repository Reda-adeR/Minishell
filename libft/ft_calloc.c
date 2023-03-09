/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:37:24 by rel-mham          #+#    #+#             */
/*   Updated: 2022/10/13 23:13:17 by rel-mham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t	count, size_t	size)
{
	unsigned char	*space;

	if (count && size > SIZE_MAX / count)
		return (NULL);
	space = malloc(count * size);
	if (!space)
		return (NULL);
	ft_bzero(space, count * size);
	return (space);
}
