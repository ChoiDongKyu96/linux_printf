/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftostr_dochoi.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dochoi <dochoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 14:51:23 by dochoi            #+#    #+#             */
/*   Updated: 2020/04/04 20:56:20 by dochoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_ftostr_dochoi_e(char *str_demical, t_tag *tag)
{
	char		base_binary[52];
	int			dot_idx;
	int			size;
	int			b_idx;

	dot_idx = 1100;
	tag->precision < 0 ? (tag->precision = 6) : 0;
	ft_memset(base_binary, 0, sizeof(base_binary));
	ft_memset(str_demical, '0', 1101);
	ft_ftostr_parse(base_binary, str_demical, tag, &dot_idx);
	ft_ftostr_set_point_e(str_demical, tag, &b_idx);
	size = ft_ftostr_e_size(str_demical, dot_idx, tag, b_idx);
	if (size < tag->width)
	{
		ft_put_f_width_dochoi_e(str_demical, tag, dot_idx, size);
		tag->size += tag->width;
	}
	else
	{
		ft_show_plusorspace_f(tag);
		ft_put_f_dochoi_e(str_demical, tag, dot_idx);
		tag->size += size;
	}
}

int		ft_ftostr_dochoi_g_pre_cal_f(char *str_demcial)
{
	int	i;
	int	size;
	int base;

	size = 15;
	i = 0;
	while (str_demcial[i] != '.')
		i++;
	i++;
	base = i;
	i = i + 14;
	while (i >= base)
	{
		if (str_demcial[i] != '0')
			break ;
		size--;
		i--;
	}
	return (size);
}

int		ft_ftostr_dochoi_g_pre_cal_e(char *str_demcial)
{
	int	i;
	int	size;
	int base;

	size = 15;
	i = 0;
	while (str_demcial[i] != '0')
		i++;
	base = i;
	i = i + 14;
	while (i >= base)
	{
		if (str_demcial[i] == '.')
			continue;
		if (str_demcial[i] != '0')
			break ;
		size--;
		i--;
	}
	return (size);
}

void	ft_ftostr_dochoi_g(char *str_demical, t_tag *tag)
{
	char		base_binary[52];
	int			dot_idx;
	int			b_idx;
	int			n;

	dot_idx = 1100;
	tag->precision < 0 ? (tag->precision = 6) : 0;
	ft_memset(base_binary, 0, sizeof(base_binary));
	ft_memset(str_demical, '0', 1101);
	ft_ftostr_parse(base_binary, str_demical, tag, &dot_idx);
	ft_ftostr_set_point_e(str_demical, tag, &b_idx);
	n = (int)((b_idx - dot_idx > 0 ? (b_idx - dot_idx) : (-b_idx + dot_idx)));
	tag->precision == 0 ? (tag->precision = 1) : 0;
	if (-4 <= n && n < tag->precision)
	{
		tag->precision = ft_ftostr_dochoi_g_pre_cal_f(str_demical);
		ft_ftostr_dochoi(str_demical, tag);
	}
	else
	{
		tag->precision = ft_ftostr_dochoi_g_pre_cal_e(str_demical);
		ft_ftostr_dochoi_e(str_demical, tag);
	}
}
