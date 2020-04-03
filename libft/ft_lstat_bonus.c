/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dochoi <dochoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 17:19:12 by dochoi            #+#    #+#             */
/*   Updated: 2020/04/03 19:52:30 by dochoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstat_bonus(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;

	if (begin_list == 0)
		return (0);
	i = 0;
	while (i < nbr && begin_list)
	{
		i++;
		begin_list = begin_list->next;
	}
	return (begin_list);
}
