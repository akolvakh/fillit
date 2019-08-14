/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 10:26:14 by akolvakh          #+#    #+#             */
/*   Updated: 2019/01/21 11:07:47 by akolvakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		r;

	i = 0;
	r = 0;
	if (!ft_strlen(needle))
		return ((char *)haystack);
	while (*haystack && len >= ft_strlen(needle))
	{
		while (needle[i])
		{
			if (needle[i] != haystack[i])
				r = 1;
			i++;
		}
		if (r == 0)
			return ((char *)haystack);
		len--;
		i = 0;
		r = 0;
		haystack++;
	}
	return (NULL);
}
