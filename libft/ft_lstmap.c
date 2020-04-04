/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dochoi <dochoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 02:54:53 by dochoi            #+#    #+#             */
/*   Updated: 2020/04/04 03:33:37 by dochoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*startlst;
	t_list	*templst;
	t_list	*prelst;

	startlst = 0;
	prelst = 0;
	if (lst == 0 || f == 0)
		return (0);
	while (lst)
	{
		if (!(templst = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&startlst, del);
			return (0);
		}
		if (startlst == 0)
			startlst = templst;
		else
			ft_lstadd_back(&prelst, templst);
		prelst = templst;
		lst = lst->next;
	}
	return (startlst);
}
