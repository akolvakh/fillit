/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 10:16:30 by akolvakh          #+#    #+#             */
/*   Updated: 2019/01/21 10:52:30 by akolvakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_spaces(int c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
			|| c == '\r');
}

int			ft_atoi(const char *str)
{
	int		number;
	char	negative_number;

	number = 0;
	while (ft_spaces(*str))
		str++;
	negative_number = (*str == '-');
	if (*str == '-' || *str == '+')
		str++;
	while (*str != '\0' && ft_isdigit(*str))
	{
		number = number * 10 + (*str - '0');
		str++;
	}
	if (negative_number)
		return (-number);
	else
		return (number);
}
