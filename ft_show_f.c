/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dochoi <dochoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 19:39:07 by dochoi            #+#    #+#             */
/*   Updated: 2020/03/13 22:15:11 by dochoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_show_f(t_tag *tag, va_list *ap)
{
	double		value;
	char		str_demical[1101];

	value = (double)va_arg(*ap, double);
	tag->t_udouble.value = value;
	if (*(tag->cur_ptr) == 'f')
		ft_ftostr_dochoi(str_demical, tag);
	else if(*(tag->cur_ptr) == 'e')
		ft_ftostr_dochoi_e(str_demical, tag);
	else if(*(tag->cur_ptr) == 'g')
		ft_ftostr_dochoi_g(str_demical, tag);
}