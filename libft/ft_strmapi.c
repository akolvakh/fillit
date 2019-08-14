/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 10:24:48 by akolvakh          #+#    #+#             */
/*   Updated: 2019/01/21 11:06:32 by akolvakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	unsigned int	i;
	char			*str;

	i = -1;
	if (s && f)
	{
		str = ft_strnew(ft_strlen(s));
		if (str)
			while (s[++i])
				str[i] = f(i, s[i]);
		return (str);
	}
	return (NULL);
}
