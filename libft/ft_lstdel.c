/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 10:33:45 by akolvakh          #+#    #+#             */
/*   Updated: 2019/01/21 10:56:37 by akolvakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list *ptr;
	t_list *list;

	if (alst == NULL)
		return ;
	list = *alst;
	while (list != NULL)
	{
		ptr = list->next;
		ft_lstdelone(&list, del);
		list = ptr;
	}
	*alst = NULL;
}
