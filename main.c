/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 10:56:05 by akolvakh          #+#    #+#             */
/*   Updated: 2019/04/14 10:56:06 by akolvakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		count_pieces(int *arr)
{
	int		i;

	i = 0;
	while ((i <= 26) && arr[i])
		i++;
	return (i);
}

char	**set_val_pieces(char **array, int piececount)
{
	int		i;
	int		n;
	int		p;

	i = 0;
	p = piececount;
	while (i < p)
	{
		n = 0;
		while (array[i][n] != 0)
		{
			if (array[i][n] == '#')
				array[i][n] = (i + 65);
			n++;
		}
		i++;
	}
	return (array);
}

int		fillit(char **argv)
{
	t_fillit storage;

	storage.array = ft_set_pieces();
	if (!(storage.nums = readit(argv[1], storage.array)))
	{
		return (0);
	}
	storage.piececount = count_pieces(storage.nums);
	storage.tiniestsize = smallestboard(storage.piececount * 4);
	storage.board = makeboard(storage.tiniestsize);
	storage.pieces = ft_true_pieces(storage.nums, storage.piececount);
	storage.pieces = set_val_pieces(storage.pieces, storage.piececount);
	solve(storage.pieces, &storage.board,
			storage.piececount, storage.tiniestsize);
	free(storage.pieces);
	free(storage.board);
	return (1);
}

int		main(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_putstr("usage: fillit [target_file]\n");
		return (0);
	}
	else if (argc == 2)
	{
		if (!(fillit(argv)))
			ft_putstr("error\n");
	}
	else
		ft_putstr("error\n");
	return (0);
}
