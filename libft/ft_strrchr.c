/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 20:11:38 by rel-mham          #+#    #+#             */
/*   Updated: 2022/10/20 10:36:10 by rel-mham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char	*s, int c)
{
	int	size_s;

	size_s = 0;
	while (s[size_s] != '\0')
		size_s++;
	while (size_s >= 0)
	{
		if (s[size_s] == (char) c)
			return ((char *) s + size_s);
		size_s--;
	}
	return (NULL);
}
