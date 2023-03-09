/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mham <rel-mham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 16:54:09 by rel-mham          #+#    #+#             */
/*   Updated: 2023/03/03 15:26:01 by rel-mham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	str_alloc(char **splited, char const *s, char c, int nbr_word)
{
	int					i;
	unsigned int		start;
	size_t				len;

	start = 0;
	i = -1;
	while (++i < nbr_word)
	{
		len = 0;
		while (s[start] && s[start] == c)
			start++;
		while (s[start] && s[start] != c)
		{
			start++;
			len++;
		}
		splited[i] = ft_substr(s, start - len, len);
		if (!splited[i])
			free_me(splited, i);
	}
}

static int	word_count(char const *str, char c)
{
	int	i;
	int	nbr_word;

	nbr_word = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			nbr_word++;
			while (str[i] && str[i] != c)
				i++;
		}
		if (str[i])
			i++;
	}
	return (nbr_word);
}

char	**ft_split(char const *s, char c)
{
	char	**splited;
	int		nbr_word;

	if (!s)
		return (NULL);
	nbr_word = word_count(s, c);
	splited = malloc((nbr_word + 1) * sizeof (char *));
	if (!splited)
		return (NULL);
	str_alloc(splited, s, c, nbr_word);
	splited[nbr_word] = NULL;
	return (splited);
}
