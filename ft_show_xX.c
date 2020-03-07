/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_xX.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dochoi <dochoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 15:15:42 by dochoi            #+#    #+#             */
/*   Updated: 2020/03/07 16:03:16 by dochoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_show_xX_whatput(t_tag *tag, unsigned long long value)
{
	const char *base;
	if (*(tag->cur_ptr) == 'x')
		base = "0123456789abcdef";
	else if (*(tag->cur_ptr) == 'X')
		base = "0123456789ABCDEF";
	if (tag->c_swidth[1] == 'h')
		ft_putbasei_std((unsigned char)value, base, 16);
	else if (tag->c_swidth[0] == 'h')
		ft_putbasei_std((unsigned short int)value, base, 16);
	else if (tag->c_swidth[3] == 'l')
		ft_putbasell_std((unsigned long long)value, base, 16);
	else if (tag->c_swidth[2] == 'l')
		ft_putbasell_std((unsigned long int)value, base, 16);
	else
		ft_putbasei_std((unsigned int)value, base, 16);
}

static void	ft_show_xX_width(t_tag *tag, unsigned long long value,
 int n_z, int n_s)
{
	if (tag->c_flags[0] == '-')
	{
		ft_show_hash(tag);
		while (n_z--)
			write(1, "0", 1);
		ft_show_xX_whatput(tag, value);
		while (n_s--)
			write(1, " ", 1);
	}
	else
	{
		while (n_s--)
			write(1, " ", 1);
		ft_show_hash(tag);
		while (n_z--)
			write(1, "0", 1);
		ft_show_xX_whatput(tag, value);
	}
}

static void	ft_show_xX_cal_zs(t_tag *tag, unsigned long long value, int size, int cal)
{
	int	n_z;
	int	n_s;

	n_z = 0;
	n_s = 0;
	if (size < tag->width && size >= tag->precision)
		n_s = tag->width - size;
	else if (size >= tag->width && size  < tag->precision)
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
	ft_show_xX_width(tag, value, n_z, n_s);
}

static unsigned long long	ft_show_xX_value(t_tag *tag, va_list *ap)
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

void	ft_show_xX(t_tag *tag, va_list *ap)
{
	int			size;
	unsigned long long	value;
	int			cal;

	cal = 0;
	value = ft_show_xX_value(tag, ap);
	size = ft_custom_size(value, 16);
	if (tag->c_flags[2] == '#')
	{
		size += 2;
		cal += 2;;
	}
	if (tag->width <= size && tag->precision <= size)
	{
		ft_show_hash(tag);
		ft_show_xX_whatput(tag, value);
	}
	else
		ft_show_xX_cal_zs(tag, value, size, cal);
	tag->size += size;
}