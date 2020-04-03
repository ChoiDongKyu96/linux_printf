/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dochoi <dochoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 16:41:52 by dochoi            #+#    #+#             */
/*   Updated: 2020/04/03 21:04:56 by dochoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void					ft_show_o_whatput(t_tag *tag,
		unsigned long long value)
{
	const char *base;

	base = "012345678";
	if (tag->c_swidth[1] == 'h')
		ft_putbasei_std((unsigned char)value, base, 8);
	else if (tag->c_swidth[0] == 'h')
		ft_putbasei_std((unsigned short int)value, base, 8);
	else if (tag->c_swidth[3] == 'l')
		ft_putbasell_std((unsigned long long)value, base, 8);
	else if (tag->c_swidth[2] == 'l')
		ft_putbasell_std((unsigned long int)value, base, 8);
	else
		ft_putbasei_std((unsigned int)value, base, 8);
}

static void					ft_show_o_width(t_tag *tag,
		unsigned long long value,
		int n_z, int n_s)
{
	if (tag->c_flags[0] == '-')
	{
		ft_show_hash(tag, value);
		while (n_z--)
			write(1, "0", 1);
		if (tag->precision == 0 && value == 0)
			write(1, " ", 1);
		else
			ft_show_o_whatput(tag, value);
		while (n_s--)
			write(1, " ", 1);
	}
	else
	{
		while (n_s--)
			write(1, " ", 1);
		ft_show_hash(tag, value);
		while (n_z--)
			write(1, "0", 1);
		if (tag->precision == 0 && value == 0)
			write(1, " ", 1);
		else
			ft_show_o_whatput(tag, value);
	}
}

static void					ft_show_o_cal_zs(t_tag *tag,
		unsigned long long value, int size, int cal)
{
	int	n_z;
	int	n_s;

	n_z = 0;
	n_s = 0;
	if (size < tag->width && size >= tag->precision)
		n_s = tag->width - size;
	else if (size >= tag->width && size < tag->precision)
		n_z = tag->precision - size + cal;
	else if (tag->width > tag->precision)
	{
		n_s = tag->width - tag->precision - cal;
		n_z = tag->precision - size + cal;
	}
	else
		n_z = tag->precision - size + cal;
	if (tag->c_flags[0] != '-' && tag->c_flags[1] == '0'
	&& tag->precision == -1)
	{
		n_z += n_s;
		n_s = 0;
	}
	tag->size += (n_z + n_s);
	ft_show_o_width(tag, value, n_z, n_s);
}

static unsigned long long	ft_show_o_value(t_tag *tag, va_list *ap)
{
	unsigned long long	value;

	if (tag->c_swidth[1] == 'h')
		value = (unsigned char)va_arg(*ap, unsigned int);
	else if (tag->c_swidth[0] == 'h')
		value = (unsigned short int)va_arg(*ap, unsigned int);
	else if (tag->c_swidth[3] == 'l')
		value = (unsigned long long)va_arg(*ap, unsigned long long);
	else if (tag->c_swidth[2] == 'l')
		value = (unsigned long int)va_arg(*ap, unsigned long int);
	else
		value = (unsigned int)va_arg(*ap, unsigned int);
	return (value);
}

void						ft_show_o(t_tag *tag, va_list *ap)
{
	int					size;
	unsigned long long	value;
	int					cal;

	cal = 0;
	value = ft_show_o_value(tag, ap);
	size = ft_custom_size(value, 8);
	if (tag->c_flags[2] == '#' && value != 0)
	{
		size += 1;
		cal += 1;
	}
	if (tag->width <= size && tag->precision <= size)
	{
		if (tag->precision == 0 && value == 0)
			return ;
		ft_show_hash(tag, value);
		ft_show_o_whatput(tag, value);
	}
	else
		ft_show_o_cal_zs(tag, value, size, cal);
	tag->size += size;
}
