/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 12:34:08 by akolvakh          #+#    #+#             */
/*   Updated: 2019/01/21 11:05:25 by akolvakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		len_s1;
	size_t		len_s2;
	char		*alloc;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if ((alloc = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1))))
	{
		ft_strcpy(alloc, s1);
		ft_strcat(alloc, s2);
	}
	return (alloc);
}
