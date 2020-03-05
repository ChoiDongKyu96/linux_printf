/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dochoi <dochoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 04:19:40 by dochoi            #+#    #+#             */
/*   Updated: 2020/03/06 05:01:15 by dochoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_show_d_size(long long value)
{
	int	size;

	size = 0;

	if (value == 0)
		return (1);
	if (value < 0)
		size++;
	while (value != 0)
	{
		value /= 10;
		size++;
	}
	return (size);
}

void	ft_show_d_whatput(t_tag *tag, long long value)
{
	if (tag->c_swidth[1] == 'h')
		ft_putint_std((char)value);
	else if (tag->c_swidth[0] == 'h')
		ft_putint_std((short int)value);
	else if (tag->c_swidth[3] == 'l')
		ft_putll_std((long long)value);
	else if (tag->c_swidth[2] == 'l')
		ft_putll_std((long int)value);
	else
		ft_putint_std((int)value);
}

void	ft_show_plusorspace(t_tag *tag, long long value)
{
	if (tag->c_flags[4] == '+' && value >= 0)
		write(1, "+", 1);
	else if (tag->c_flags[3] ==' ' && value >= 0)
		write(1, " ", 1);
}

void	ft_show_d_width(t_tag *tag, long long value, int remain)
{
	char c = ' ';
	tag->size += remain;
	if (tag->c_flags[0] == '-')
	{
		ft_show_plusorspace(tag, value);
		ft_show_d_whatput(tag, value);
		while (remain--)
			write(1, &c, 1);
	}
	else
	{
		if (tag->c_flags[1] == '0')
		{
			c = '0';
			ft_show_plusorspace(tag, value);
		}
		while (remain--)
			write(1, &c, 1);
		if (c != '0')
			ft_show_plusorspace(tag, value);
		ft_show_d_whatput(tag, value);
	}
}

void	ft_show_d(t_tag *tag, va_list *ap)
{
	int size;
	long long value;

	if (tag->c_swidth[1] == 'h')
		value = (char)va_arg(*ap, int);
	else if (tag->c_swidth[0] == 'h')
		value = (short int)va_arg(*ap, int);
	else if (tag->c_swidth[3] == 'l')
		value = (long long)va_arg(*ap, long long );
	else if (tag->c_swidth[2] == 'l')
		value = (long int)va_arg(*ap, long int);
	else
		value = (int)va_arg(*ap, int);
	size = ft_show_d_size(value);
	if (tag->c_flags[4] == '+' && value >= 0 ||
	tag->c_flags[3] ==' ' && value >= 0)
		size++;
	if (tag->width <= size)
	{
		ft_show_plusorspace(tag, value);
		ft_show_d_whatput(tag, value);
	}
	else
		ft_show_d_width(tag, value, tag->width - size);
	tag->size += size;
}