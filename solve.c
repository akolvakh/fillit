/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 10:56:32 by akolvakh          #+#    #+#             */
/*   Updated: 2019/04/15 13:19:19 by akolvakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**do_mallocs_and_populate(char *truepiece[20], int *vals, int count)
{
	char	**array;
	int		i;

	if (!(array = (char **)ft_memalloc(sizeof(char *) * (count + 1))))
		return (NULL);
	i = 0;
	while (i < count)
	{
		if (!(array[i] = (char *)ft_memalloc(sizeof(char) * 49)))
			return (NULL);
		ft_strcpy(array[i], truepiece[vals[i]]);
		i++;
	}
	return (array);
}

char	**ft_true_pieces(int *arr, int count)
{
	static char		*truepiece[20];

	truepiece[0] = "##\n##";
	truepiece[1] = "#\n#\n#\n#";
	truepiece[2] = "####";
	truepiece[3] = ".#\n##\n#";
	truepiece[4] = "##.\n.##";
	truepiece[5] = ".##\n##";
	truepiece[6] = "#.\n##\n.#";
	truepiece[7] = "#..\n###";
	truepiece[8] = ".#\n.#\n##";
	truepiece[9] = "###\n..#";
	truepiece[10] = "##\n#.\n#";
	truepiece[11] = "..#\n###";
	truepiece[12] = "#.\n#.\n##";
	truepiece[13] = "###\n#";
	truepiece[14] = "##\n.#\n.#";
	truepiece[15] = ".#.\n###\n";
	truepiece[16] = "#.\n##\n#";
	truepiece[17] = "###\n.#";
	truepiece[18] = ".#\n##\n.#";
	truepiece[19] = "##\n##";
	return (do_mallocs_and_populate(truepiece, arr, count));
}

int		placepieces(char **pieces, char *board, int piece, int total)
{
	int		i;
	int		x;

	if (piece == -1)
		i = 0;
	else
		i = piece;
	x = -1;
	while (board[++x])
	{
		if (board[x] == '.' && addpiece(pieces[i], board, x))
		{
			if ((i + 1) == total)
				return (1);
			else if ((i + 1) != total)
			{
				if (placepieces(pieces, board, ++i, total))
					return (1);
			}
			removepiece(pieces[i--], board);
		}
		removepiece(pieces[i], board);
	}
	return (0);
}

void	solve(char **pieces, char **board, int total, int tiniestsize)
{
	while (placepieces(pieces, *board, -1, total) == 0)
	{
		free(*board);
		*board = makeboard(tiniestsize++);
	}
	ft_putstr(*board);
}
