/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strxjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 13:22:20 by akolvakh          #+#    #+#             */
/*   Updated: 2019/04/15 13:22:21 by akolvakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char *s1, char *s2, int l)
{
	if (l == 1)
		free(s1);
	if (l == 2)
		free(s2);
	if (l == 3)
	{
		free(s1);
		free(s2);
	}
	else
		return ;
}

char		*ft_strxjoin(char *s1, char *s2, int l)
{
	size_t	i;
	size_t	z;
	char	*blank;
	size_t	len;

	i = 0;
	z = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(blank = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s1[i] != '\0')
	{
		blank[i] = s1[i];
		i++;
	}
	while (s2[z] != '\0')
		blank[i++] = s2[z++];
	blank[i] = '\0';
	ft_free(s1, s2, l);
	return (blank);
}
