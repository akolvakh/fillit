/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 10:26:43 by akolvakh          #+#    #+#             */
/*   Updated: 2019/01/21 11:08:42 by akolvakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	int		r;

	r = 0;
	i = 0;
	if (!ft_strlen(needle))
		return ((char *)haystack);
	while (*haystack)
	{
		while (needle[i])
		{
			if (needle[i] != haystack[i])
				r = 1;
			i++;
		}
		if (r == 0)
			return ((char *)haystack);
		i = 0;
		r = 0;
		haystack++;
	}
	return (NULL);
}
