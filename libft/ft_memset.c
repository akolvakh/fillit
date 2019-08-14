/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 10:54:41 by akolvakh          #+#    #+#             */
/*   Updated: 2019/01/21 10:59:34 by akolvakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *pointer;

	pointer = (unsigned char *)b;
	while (len > 0)
	{
		len--;
		*pointer++ = (unsigned char)c;
	}
	return (b);
}
