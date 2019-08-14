/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maptools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 10:56:10 by akolvakh          #+#    #+#             */
/*   Updated: 2019/04/14 10:56:12 by akolvakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		len_n(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\n')
		i++;
	return (i);
}

char	*makeboard(int size)
{
	char	*board;
	int		pos;
	int		realsize;
	int		stor;

	pos = 0;
	realsize = ((size + 1) * size);
	stor = 0;
	board = ft_strnew(realsize);
	ft_memset(board, '.', realsize);
	while (pos < size)
	{
		stor = stor + (realsize / size);
		board[stor - 1] = '\n';
		pos++;
	}
	return (board);
}

int		smallestboard(int i)
{
	int		size;

	size = 0;
	while (i > size * size)
	{
		size++;
		if (size > 46340)
			return (0);
	}
	return (size);
}
