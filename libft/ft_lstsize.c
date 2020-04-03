/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dochoi <dochoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 01:54:34 by dochoi            #+#    #+#             */
/*   Updated: 2020/04/03 19:53:58 by dochoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	lstsize;

	if (lst == 0)
		return (0);
	lstsize = 1;
	while (lst->next)
	{
		lstsize++;
		lst = lst->next;
	}
	return (lstsize);
}
