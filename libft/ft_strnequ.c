/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 10:25:48 by akolvakh          #+#    #+#             */
/*   Updated: 2019/01/21 11:07:17 by akolvakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	if (!s1 || !s2 || n <= 0)
		return (1);
	i = -1;
	while (s1[++i] && s2[i] && i < n)
		if (s1[i] != s2[i])
			return (0);
	if (s1[i] != s2[i] && i < n)
		return (0);
	return (1);
}
