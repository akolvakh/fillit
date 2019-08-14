/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 10:19:56 by akolvakh          #+#    #+#             */
/*   Updated: 2019/01/21 10:58:19 by akolvakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*source;
	unsigned char	var;
	size_t			i;

	source = (unsigned char *)s;
	var = (unsigned char)c;
	i = -1;
	while (++i < n)
		if (source[i] == var)
			return (source + i);
	return (NULL);
}
