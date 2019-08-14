/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movepiece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 10:56:16 by akolvakh          #+#    #+#             */
/*   Updated: 2019/04/14 10:56:18 by akolvakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	get_letter(char *piece)
{
	while (*piece)
	{
		if (ft_isupper(*piece))
			return (*piece);
		piece++;
	}
	return (0);
}

int		addpiece_ext(char *piece, char *board, int i, t_data dims)
{
	while (piece[dims.p] && board[i])
	{
		while (i < dims.max_size && piece[dims.p] && piece[dims.p] != '\n')
		{
			if (board[i] == '.')
				board[i++] = piece[dims.p++];
			else if (piece[dims.p] == dims.letter)
				return (0);
			else
			{
				dims.p++;
				i++;
			}
			dims.mod++;
		}
		if (piece[dims.p] == '\n')
			dims.p++;
		if (!piece[dims.p])
			return (1);
		i += dims.row_len - dims.mod;
		if (i >= dims.max_size)
			return (0);
		dims.mod = 0;
	}
	return (0);
}

int		addpiece(char *piece, char *board, int i)
{
	t_data dims;

	dims.max_size = ft_strlen(board);
	dims.row_len = len_n(board) + 1;
	dims.letter = get_letter(piece);
	dims.p = 0;
	dims.mod = 0;
	while (piece[dims.p] && piece[dims.p] == '.')
	{
		dims.p++;
		dims.mod++;
	}
	if (addpiece_ext(piece, board, i, dims) == 1)
		return (1);
	return (0);
}

char	*removepiece(char *piece, char *board)
{
	int		n;
	int		i2;

	n = 0;
	i2 = 0;
	while (board[n] != '\0')
	{
		while (piece[i2] == '.')
			i2++;
		if (board[n] == piece[i2])
			board[n] = '.';
		n++;
	}
	return (board);
}
