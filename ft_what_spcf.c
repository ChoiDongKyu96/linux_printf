/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_what_spcf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dochoi <dochoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 04:13:38 by dochoi            #+#    #+#             */
/*   Updated: 2020/03/08 17:30:17 by dochoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_is_spcf_width(t_tag *tag)
{
	if (*(tag->cur_ptr - 1) == 'h')
	{
		tag->c_swidth[0] = 'h';
		if (*(tag->cur_ptr - 2) == 'h')
			tag->c_swidth[1] = 'h';
	}
	else if (*(tag->cur_ptr - 1) == 'l')
	{
		tag->c_swidth[2] = 'l';
		if (*(tag->cur_ptr - 2) == 'l')
			tag->c_swidth[3] = 'l';
	}
}

static void ft_show_per(t_tag *tag)
{
	write(1, "%", 1);
	tag->size++;
}

void		ft_what_spcf(t_tag *tag, va_list *ap, unsigned int spc)
{
	ft_is_spcf_width(tag);
	if (spc == 0)
		ft_show_c(tag, ap);
	else if (spc == 1)
		ft_show_s(tag, ap);
	else if (spc == 2)
		ft_show_p(tag, ap);
	else if (spc == 3 || spc == 4)
		ft_show_d(tag, ap);
	else if (spc == 5)
		ft_show_u(tag, ap);
	else if (spc == 6 || spc == 7)
		ft_show_xX(tag, ap);
	else if (spc == 8)
		ft_show_per(tag);
	else if (spc == 9)
		ft_insert_n(tag, ap);
	else if (spc == 13)
		ft_show_o(tag, ap);
}