/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 10:56:37 by akolvakh          #+#    #+#             */
/*   Updated: 2019/04/14 10:56:38 by akolvakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_set_pieces(void)
{
	static char		*valids[19];

	valids[0] = "##..##";
	valids[1] = "#...#...#...#";
	valids[2] = "####";
	valids[3] = "#..##..#";
	valids[4] = "##...##";
	valids[5] = "##.##";
	valids[6] = "#...##...#";
	valids[7] = "#...###";
	valids[8] = "#...#..##";
	valids[9] = "###...#";
	valids[10] = "##..#...#";
	valids[11] = "#.###";
	valids[12] = "#...#...##";
	valids[13] = "###.#";
	valids[14] = "##...#...#";
	valids[15] = "#..###";
	valids[16] = "#...##..#";
	valids[17] = "###..#";
	valids[18] = "#..##...#";
	return (valids);
}

int		ft_validatestr(char *str, char **valid)
{
	int		n;

	n = 0;
	while (n <= 18)
	{
		if (!(ft_strcmp(str, valid[n])))
			return (n + 1);
		n++;
	}
	return (-1);
}

int		ft_validatehash(char *str)
{
	int		i;
	int		hashcount;
	int		dotcount;

	i = 0;
	hashcount = 0;
	dotcount = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
			hashcount++;
		if (str[i] == '.')
			dotcount++;
		i++;
	}
	if (hashcount == 4 && dotcount == 12)
		return (1);
	else
		return (0);
}

char	*ft_removeline(char *str)
{
	int		i;
	int		z;
	char	*str2;

	i = 0;
	z = 0;
	str2 = ft_strnew(ft_strlen(str));
	while (str[i] != '\0')
	{
		if (str[i] != '\n')
		{
			str2[z] = str[i];
			z++;
		}
		i++;
	}
	free(str);
	return (str2);
}

int		ft_validate(char *str, char **valid)
{
	int i;

	i = 0;
	if (!(ft_validatehash(str)))
		return (-1);
	str = ft_strtrimalt(str);
	str = ft_removeline(str);
	i = ft_validatestr(str, valid);
	free(str);
	if (i >= 1)
		return (i - 1);
	return (-1);
}
