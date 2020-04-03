/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dochoi <dochoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 02:35:12 by dochoi            #+#    #+#             */
/*   Updated: 2020/04/03 19:52:48 by dochoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;

	if (lst == 0 || *lst == 0 || del == 0)
		return ;
	while ((*lst))
	{
		ptr = (*lst);
		(*lst) = (*lst)->next;
		free(ptr);
		del(ptr->content);
	}
}
