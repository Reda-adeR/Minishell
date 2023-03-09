/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:55:09 by rel-mham          #+#    #+#             */
/*   Updated: 2022/10/19 13:32:40 by rel-mham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_int(long int n)
{
	int	len_int;

	len_int = 0;
	if (n <= 0)
		len_int++;
	while (n > 0 || n < 0)
	{
		n = n / 10;
		len_int++;
	}
	return (len_int);
}

static char	*fill_str(long int ncpy, int len, char *str)
{
	int		swp;

	swp = 0;
	if (ncpy == 0)
	{
		str[0] = 0 + '0';
		str[1] = '\0';
		return (str);
	}
	if (ncpy < 0)
	{
		str[0] = '-';
		ncpy = ncpy * -1;
		swp = 1;
	}
	str[len] = '\0';
	while (len-- > swp)
	{
		str[len] = (ncpy % 10) + 48;
		ncpy = ncpy / 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	long int	nb;
	char		*str;
	int			len;

	nb = n;
	len = len_int(nb);
	str = malloc(len * sizeof (char) + 1);
	if (!str)
		return (NULL);
	str = fill_str(nb, len, str);
	return (str);
}
