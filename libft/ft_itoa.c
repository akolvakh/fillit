/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 10:17:59 by akolvakh          #+#    #+#             */
/*   Updated: 2019/01/21 10:55:50 by akolvakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_counter(long n)
{
	int i;

	i = 1;
	if (n < 0)
		n = -n;
	while (n >= 10)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	int		count;
	long	number;
	int		negative;
	char	*str;

	number = n;
	negative = (number < 0 ? 1 : 0);
	count = ft_counter(number);
	str = ft_strnew(count + negative);
	if (str == NULL)
		return (NULL);
	if (negative)
	{
		number = -number;
		str[0] = '-';
	}
	while (count > 0)
	{
		str[count + negative - 1] = (number % 10) + '0';
		count--;
		number /= 10;
	}
	return (str);
}
