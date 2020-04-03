/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dochoi <dochoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 17:03:46 by dochoi            #+#    #+#             */
/*   Updated: 2020/04/03 20:36:17 by dochoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_insert_n(t_tag *tag, va_list *ap)
{
	int	*ptr;

	ptr = (int*)va_arg(*ap, int*);
	if (ptr == 0)
		return ;
	*ptr = tag->size;
}
