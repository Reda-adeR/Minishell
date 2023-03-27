/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharrass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:54:00 by aharrass          #+#    #+#             */
/*   Updated: 2023/03/20 21:56:39 by aharrass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	atoi_help2(const char *str, int i, int s)
{
	unsigned long	j;

	j = 0;
	while (ft_isdigit(str[i]))
	{
		j = j * 10 + str[i++] - '0';
		if (j > 9223372036854775807 && s == 1)
			return (-1);
		if (j > 9223372036854775807 && s == -1)
			return (0);
	}
	return (j * s);
}

long long	atoi_helper(const char *str, int i, int s)
{
	unsigned long	j;
	long long		k;

	j = 0;
	while (ft_isdigit(str[i]))
	{
		j = j * 10 + str[i++] - '0';
		if (j > 9223372036854775807)
		{
			ft_putendl_fd("exit\nminishell: exit: numeric argument required",
				2);
			return (-1);
		}
	}
	k = j * s;
	while (k > 255 || k < 0)
	{
		if (k > 255)
			k = k % 256;
		else if (k < 0)
			k += 256;
	}
	return (k);
}

long long	ft_atoi(const char *str, int f)
{
	int	i;
	int	s;

	i = 0;
	s = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		s *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	if (f == 0)
		return (atoi_help2(str, i, s));
	return (atoi_helper(str, i, s));
}
