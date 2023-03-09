/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mham <rel-mham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 10:51:57 by rel-mham          #+#    #+#             */
/*   Updated: 2023/03/09 12:50:02 by rel-mham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*strfinal;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	strfinal = malloc(sizeof (char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!strfinal)
		return (NULL);
	while (s1[i] != '\0')
	{
		strfinal[i] = s1[i];
		i++;
	}
	while (*s2)
	{
		strfinal[i] = *s2;
		s2++;
		i++;
	}
	strfinal[i] = '\0';
	free(s1);
	return (strfinal);
}
