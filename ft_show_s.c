/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dochoi <dochoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 17:58:49 by dochoi            #+#    #+#             */
/*   Updated: 2020/03/09 19:34:48 by dochoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_show_s_whatput(t_tag *tag, wchar_t *str)
{
	int		i;
	char	*cstr;

	i = 0;
	if (tag->c_swidth[2] == 'l' )
	{
		if (tag->precision != -1)
			while (str[i] && i < tag->precision)
				ft_show_wc(str[i++], tag);
		else
			while (str[i])
				ft_show_wc(str[i++], tag);
	}
	else
	{
		cstr = (char*)str;
		if (tag->precision != -1)
			while (cstr[i] && i < tag->precision)
				write(1, &cstr[i++], 1);
		else
			while (cstr[i])
				write(1, &cstr[i++], 1);
	}
}

static void		ft_show_s_width(t_tag *tag, wchar_t *str, int n_z, int n_s)
{
	if (tag->c_flags[0] == '-')
	{
		while (n_z--)
			write(1, "0", 1);
		ft_show_s_whatput(tag, str);
		while (n_s--)
			write(1, " ", 1);
	}
	else
	{
		while (n_s--)
			write(1, " ", 1);
		while (n_z--)
			write(1, "0", 1);
		ft_show_s_whatput(tag, str);
	}
}

static void		ft_show_s_sal_zs(t_tag *tag, wchar_t *str, int size)
{
	int	n_z;
	int	n_s;

	n_z = 0;
	n_s = 0;
	if (size < tag->width && size >= tag->precision)
		n_s = tag->width - size;
	else if (size >= tag->width && size  < tag->precision)
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
	ft_show_s_width(tag, str, n_z, n_s);
}

static void	*ft_show_s_str(t_tag *tag, va_list *ap)
{
	void *str;

	if (tag->c_swidth[2] == 'l')
		str = (wchar_t*)va_arg(*ap, wchar_t*);
	else
		str = (char*)va_arg(*ap, char*);
	return (str);
}

void			ft_show_s(t_tag *tag, va_list *ap)
{
	wchar_t	*str;
	int 	size;

	str = ft_show_s_str(tag, ap);
	if (str == 0 && tag->precision < 6 && tag->precision != -1)
		tag->c_swidth[2] == 'l' ? (str = (wchar_t*)L"\0") : (str = (wchar_t*)"\0");
	else if (str == 0)
		tag->c_swidth[2] == 'l' ? (str = (wchar_t*)L"(null)") : (str = (wchar_t*)"(null)");
	if (*((char*)str) == 0)
		tag->precision = 0;
	size = ft_custom_str_size(tag, str);
	if (tag->width <= size)
		ft_show_s_whatput(tag, str);
	else
		ft_show_s_sal_zs(tag, str, size);
	if (tag->c_swidth[2] != 'l')
		tag->size += size;
}