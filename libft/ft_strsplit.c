/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 10:26:32 by akolvakh          #+#    #+#             */
/*   Updated: 2019/01/21 11:08:28 by akolvakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		count_words(char c, char const *s)
{
	long long	i;
	int			count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && s[i])
		{
			while (s[i] != c && s[i])
				i++;
			count++;
		}
		if (s[i])
			i++;
	}
	return (count);
}

static size_t	count_letters(char c, char const *s)
{
	size_t i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char			**m;
	unsigned int	i;
	int				j;
	int				words;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	words = count_words(c, s);
	m = (char**)malloc((words + 1) * sizeof(m));
	if (!m)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		m[j] = ft_strsub(s, i, count_letters(c, &s[i]));
		while (s[i] != c && s[i])
			i++;
		j++;
	}
	m[words] = NULL;
	return (m);
}
