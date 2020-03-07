/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dochoi <dochoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 17:42:22 by dochoi            #+#    #+#             */
/*   Updated: 2020/03/07 17:54:28 by dochoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_show_p_whatput(t_tag *tag, unsigned long int value)
{
	const char *base;

	(void)tag;
	base = "0123456789abcdef";
	ft_putbasell_std((unsigned long int)value, base, 16);
}

static void	ft_show_p_width(t_tag *tag, unsigned long int value,
 int n_z, int n_s)
{
	if (tag->c_flags[0] == '-')
	{
		ft_show_hash(tag);
		while (n_z--)
			write(1, "0", 1);
		ft_show_p_whatput(tag, value);
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
		ft_show_p_whatput(tag, value);
	}
}

static void	ft_show_p_cal_zs(t_tag *tag, unsigned long int value, int size, int cal)
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
	ft_show_p_width(tag, value, n_z, n_s);
}

static unsigned long int	ft_show_p_value(t_tag *tag, va_list *ap)
{
	unsigned long int	value;

	(void)tag;
	value = (unsigned long int)va_arg(*ap, unsigned long int);
	return (value);
}

void	ft_show_p(t_tag *tag, va_list *ap)
{
	int			size;
	unsigned long int	value;
	int			cal;

	cal = 0;
	value = ft_show_p_value(tag, ap);
	size = ft_custom_size(value, 16);
		size += 2;
		cal += 2;;
	if (tag->width <= size && tag->precision <= size)
	{
		ft_show_hash(tag);
		ft_show_p_whatput(tag, value);
	}
	else
		ft_show_p_cal_zs(tag, value, size, cal);
	tag->size += size;
}