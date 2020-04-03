/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dochoi <dochoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 04:19:40 by dochoi            #+#    #+#             */
/*   Updated: 2020/04/03 20:43:48 by dochoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			ft_show_d_whatput(t_tag *tag, long long value)
{
	value > 0 ? (value) : (value *= -1);
	if (tag->c_swidth[1] == 'h')
		ft_putuint_std((int)value);
	else if (tag->c_swidth[0] == 'h')
		ft_putuint_std((int)value);
	else if (tag->c_swidth[3] == 'l')
		ft_putull_std(value);
	else if (tag->c_swidth[2] == 'l')
		ft_putull_std(value);
	else
		ft_putuint_std((int)value);
}

static void			ft_show_d_width(t_tag *tag, long long value, int n_z, int n_s)
{
	if (tag->c_flags[0] == '-')
	{
		ft_show_plusorspace(tag, value);
		if (tag->precision == 0 && value == 0)
			write(1, " ", 1);
		while (n_z--)
			write(1, "0", 1);
		if (tag->precision != 0 || value != 0)
			ft_show_d_whatput(tag, value);
		while (n_s--)
			write(1, " ", 1);
	}
	else
	{
		while (n_s--)
			write(1, " ", 1);
		if (tag->precision == 0 && value == 0)
			write(1, " ", 1);
		ft_show_plusorspace(tag, value);
		while (n_z--)
			write(1, "0", 1);
		if (tag->precision != 0 || value != 0)
			ft_show_d_whatput(tag, value);
	}
}

static void			ft_show_d_cal_zs(t_tag *tag, long long value, int size, int cal)
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
	ft_show_d_width(tag, value, n_z, n_s);
}

static long long	ft_show_d_value(t_tag *tag, va_list *ap)
{
	long long value;

	if (tag->c_swidth[1] == 'h')
		value = (char)va_arg(*ap, int);
	else if (tag->c_swidth[0] == 'h')
		value = (short int)va_arg(*ap, int);
	else if (tag->c_swidth[3] == 'l')
		value = (long long)va_arg(*ap, long long);
	else if (tag->c_swidth[2] == 'l')
		value = (long int)va_arg(*ap, long int);
	else
		value = (int)va_arg(*ap, int);
	return (value);
}

void				ft_show_d(t_tag *tag, va_list *ap)
{
	int			size;
	long long	value;
	int			cal;

	cal = 0;
	value = ft_show_d_value(tag, ap);
	size = ft_custom_size(value, 10);
	if ((tag->c_flags[4] == '+' && value >= 0) ||
	(tag->c_flags[3] == ' ' && value >= 0) || value < 0)
	{
		size++;
		cal++;
	}
	if (tag->width <= size && tag->precision <= size)
	{
		ft_show_plusorspace(tag, value);
		if (tag->precision == 0 && value == 0)
			return ;
		ft_show_d_whatput(tag, value);
	}
	else
		ft_show_d_cal_zs(tag, value, size, cal);
	tag->size += size;
}
