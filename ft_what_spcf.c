/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_what_spcf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dochoi <dochoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 04:13:38 by dochoi            #+#    #+#             */
/*   Updated: 2020/03/06 04:48:05 by dochoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_is_spcf_width(t_tag *tag)
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

void	ft_what_spcf(t_tag *tag, va_list *ap, unsigned int spc)
{
	ft_is_spcf_width(tag);
	if (spc == 3 || spc == 4)
		ft_show_d(tag, ap);
}