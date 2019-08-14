/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 10:48:41 by akolvakh          #+#    #+#             */
/*   Updated: 2019/01/21 11:04:20 by akolvakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strequ(char const *s1, char const *s2)
{
	size_t	i;

	if (!s1 && !s2)
		return (1);
	if (!s1 || !s2)
		return (0);
	i = -1;
	while (s1[++i] && s2[i])
		if (s1[i] != s2[i])
			return (0);
	if (s1[i] != s2[i])
		return (0);
	return (1);
}
