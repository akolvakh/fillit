/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 10:55:47 by akolvakh          #+#    #+#             */
/*   Updated: 2019/04/14 10:55:49 by akolvakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

typedef struct		s_piece
{
	int				fd;
	int				count;
	char			*tmp;
	char			buf[22];
	int				n_count;
}					t_piece;

typedef struct		s_data
{
	int				max_size;
	int				row_len;
	char			letter;
	int				p;
	int				mod;
}					t_data;

typedef struct		s_fillit
{
	char			**pieces;
	int				*nums;
	char			**array;
	char			*board;
	int				piececount;
	int				tiniestsize;
}					t_fillit;

int					*readit(char *file, char **pieces);
int					ft_validate(char *str, char **valid);
char				*ft_strtrimalt(char const *s);
char				**ft_set_pieces(void);
char				*makeboard(int size);
int					addpiece(char *piece, char *board, int i);
char				*removepiece(char *piece, char *board);
int					smallestboard(int i);
int					len_n(char *s);
char				**ft_true_pieces(int *arr, int count);
void				solve(char **pieces, char **board, int total,
												int tiniestsize);
#endif
