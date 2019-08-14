/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 10:27:00 by akolvakh          #+#    #+#             */
/*   Updated: 2019/01/21 11:09:29 by akolvakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	size;
	size_t	start;
	char	*res;

	start = 0;
	if (s && 0 < (size = ft_strlen(s)))
	{
		while ((s[size - 1] >= 1 && s[size - 1] <= 19) || s[size - 1] == 32)
			--size;
		while ((s[start] >= 1 && s[start] <= 19) || s[start] == 32)
			++start;
		res = ft_strnew(size - start);
		if (size == 0)
			return (ft_strdup("\0"));
		if (res)
		{
			while (size-- > start)
				res[size - start] = s[size];
			return (res);
		}
		return (res);
	}
	return ((char *)s);
}
