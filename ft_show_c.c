/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dochoi <dochoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 21:47:49 by dochoi            #+#    #+#             */
/*   Updated: 2020/04/03 20:48:19 by dochoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_show_c_whatput(t_tag *tag, wint_t value)
{
	int	ivalue;

	if (tag->c_swidth[2] == 'l')
		ft_show_wc(value, tag);
	else
	{
		ivalue = (int)value;
		write(1, &ivalue, 1);
	}
}

static void		ft_show_c_width(t_tag *tag, wint_t value, int n_z, int n_s)
{
	if (tag->c_flags[0] == '-')
	{
		while (n_z--)
			write(1, "0", 1);
		ft_show_c_whatput(tag, value);
		while (n_s--)
			write(1, " ", 1);
	}
	else
	{
		while (n_s--)
			write(1, " ", 1);
		while (n_z--)
			write(1, "0", 1);
		ft_show_c_whatput(tag, value);
	}
}

static void		ft_show_c_cal_zs(t_tag *tag, wint_t value, int size)
{
	int	n_z;
	int	n_s;

	n_z = 0;
	n_s = 0;
	if (size < tag->width && size >= tag->precision)
		n_s = tag->width - size;
	else if (size >= tag->width && size < tag->precision)
		n_z = tag->precision - size;
	else if (tag->width > tag->precision)
	{
		n_s = tag->width - tag->precision;
		n_z = tag->precision - size;
	}
	else
		n_z = tag->precision - size;
	n_s += n_z;
	n_z = 0;
	tag->size += (n_z + n_s);
	ft_show_c_width(tag, value, n_z, n_s);
}

static wint_t	ft_show_c_value(t_tag *tag, va_list *ap)
{
	wint_t value;

	if (tag->c_swidth[2] == 'l')
		value = (wint_t)va_arg(*ap, wint_t);
	else
		value = (int)va_arg(*ap, int);
	return (value);
}

void			ft_show_c(t_tag *tag, va_list *ap)
{
	wint_t value;

	value = ft_show_c_value(tag, ap);
	if (tag->width <= 1 && tag->precision <= 1)
		ft_show_c_whatput(tag, value);
	else
		ft_show_c_cal_zs(tag, value, 1);
	if (tag->c_swidth[2] != 'l')
		tag->size += 1;
}
