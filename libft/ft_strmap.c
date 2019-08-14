/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 10:59:40 by akolvakh          #+#    #+#             */
/*   Updated: 2019/01/21 11:06:10 by akolvakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f) (char))
{
	const char	*res;
	char		*str;

	if (s && f)
	{
		str = ft_strnew(ft_strlen(s));
		if (str)
		{
			res = str;
			while (*s)
			{
				*str = f(*s);
				s++;
				str++;
			}
			return ((char *)res);
		}
	}
	return (NULL);
}
