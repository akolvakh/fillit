/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 10:56:23 by akolvakh          #+#    #+#             */
/*   Updated: 2019/04/22 16:47:20 by akolvakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		*do_reads(t_piece datastuff, int *p, char **pieces)
{
	int	i;

	i = ft_validate(datastuff.buf, pieces);
	if (i == -1)
		return (NULL);
	else if (i == 0)
		p[datastuff.count] = 19;
	else
		p[datastuff.count] = i;
	return (p);
}

int		count_pound(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
			j++;
		i++;
	}
	return (j);
}

int		count_n(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			j++;
		i++;
	}
	return (j);
}

int		bufcheck(t_piece datastuff)
{
	if ((!(datastuff.buf[0] == '#' || datastuff.buf[0] == '.')) ||
		(!(datastuff.buf[19] == '\n')) || (count_pound(datastuff.buf) != 4))
		return (0);
	return (1);
}

int		*readit(char *file, char **pieces)
{
	t_piece	datastuff;
	int		*piece;

	if (!(datastuff.fd = open(file, O_RDONLY)))
		return (0);
	if (!(piece = (int *)ft_memalloc(sizeof(int) * 27)))
		return (0);
	datastuff.count = 0;
	datastuff.n_count = 0;
	while ((datastuff.count <= 26) &&
		(read(datastuff.fd, datastuff.buf, 21) != 0))
	{
		if (!(bufcheck(datastuff)))
			return (0);
		if (!(piece = do_reads(datastuff, piece, pieces)))
			return (0);
		datastuff.n_count = datastuff.n_count + count_n(datastuff.buf);
		ft_bzero(datastuff.buf, 21);
		datastuff.count++;
	}
	if ((datastuff.count - 1) > 26 || datastuff.count == 0
		|| datastuff.n_count > ((datastuff.count * 5) - 1))
		return (0);
	close(datastuff.fd);
	return (piece);
}
