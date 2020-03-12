/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_custom_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dochoi <dochoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 16:14:13 by dochoi            #+#    #+#             */
/*   Updated: 2020/03/08 21:06:21 by dochoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_custom_size(long long value, long long base)
{
	int	size;

	size = 0;

	if (value == 0)
		return (1);
	while (value != 0)
	{
		value /= base;
		size++;
	}
	return (size);
}

int		ft_custom_str_size(t_tag *tag, wchar_t *str)
{
	char	*cstr;
	int 	size;

	size = 0;
	if (tag->c_swidth[2] == 'l' )
	{
		if (tag->precision != -1)
			while (str[size] && size < tag->precision)
				size++;
		else
			while (str[size])
	 			size++;
	}
	else
	{
		cstr = (char*)str;
		if (tag->precision != -1)
			while (cstr[size] && size < tag->precision)
				size++;
		else
			while (cstr[size])
				size++;
	}
	return (size);
}