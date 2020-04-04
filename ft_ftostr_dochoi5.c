/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftostr_dochoi5.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dochoi <dochoi@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 20:37:17 by dochoi            #+#    #+#             */
/*   Updated: 2020/04/04 20:37:23 by dochoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"
#include "libft.h"

void	ft_ftostr_dochoi(char *str_demical, t_tag *tag)
{
	char		base_binary[52];
	int			dot_idx;
	int			size;

	dot_idx = 1100;
	if (tag->precision < 0)
		tag->precision = 6;
	ft_memset(base_binary, 0, sizeof(base_binary));
	ft_memset(str_demical, '0', 1101);
	ft_ftostr_parse(base_binary, str_demical, tag, &dot_idx);
	ft_round_bankers(str_demical, tag->precision, &dot_idx);
	ft_ftostr_set_point(str_demical, &dot_idx);
	size = ft_ftostr_size(str_demical, dot_idx, tag);
	if (size < tag->width)
	{
		ft_put_f_width_dochoi(str_demical, tag, dot_idx, size);
		tag->size += tag->width;
	}
	else
	{
		ft_show_plusorspace_f(tag);
		ft_put_f_dochoi(str_demical, tag, dot_idx);
		tag->size += size;
	}
}

void	ft_ftostr_set_point_e(char *str_demical, t_tag *tag, int *b_idx)
{
	int i;

	i = 0;
	while (1)
	{
		if (str_demical[i] != '0')
			break ;
		i++;
	}
	*b_idx = i;
	ft_round_bankers(str_demical, tag->precision, &i);
	i = 0;
	while (1)
	{
		if (str_demical[i] != '0')
			break ;
		i++;
	}
	str_demical[i - 1] = str_demical[i];
	str_demical[i] = '.';
}

void	ft_put_f_dochoi_enumber(int base_dot, int dot_idx)
{
	unsigned int n;

	n = (unsigned int)((base_dot - dot_idx > 0 ? (base_dot - dot_idx) : (-base_dot + dot_idx)));
	write(1, "e", 1);
	(base_dot - dot_idx > 0 ? (write(1, "-", 1))  : (write(1, "+", 1)));
	if (n < 10)
		write(1, "0", 1);
	ft_putuint_std(n);
}

void	ft_put_f_dochoi_e(char *str_demical, t_tag *tag, int dot_idx)
{
	int	i;
	int	precision;
	int	base_dot;

	if (tag->t_udouble.parts.exponent == 2047ULL)
		if (tag->t_udouble.parts.mantisa == 2251799813685248ULL || tag->t_udouble.parts.mantisa == 0)
			{
				ft_put_nan_inf(tag);
				return ;
			}
	i = 0;
	precision = tag->precision;
	while (str_demical[i] == '0' && i < 1101)
		i++;
	while (str_demical[i] != '.')
		write(1, &str_demical[i++], 1);
	base_dot = i;
	if (precision > 0 || tag->c_flags[2] =='#')
		write(1, &str_demical[i++], 1);
	if (precision > 0)
		while (precision--)
			i < 1101 ? (write(1, &str_demical[i++], 1)) : (write(1, "0", 1));
	ft_put_f_dochoi_enumber(base_dot, dot_idx);
}

void	ft_put_f_width_dochoi_e(char *str_demical, t_tag *tag, int dot_idx, int size)
{
	char	c;
	int		w_size;

	w_size = tag->width - size;
	c = ' ';
	if (tag->c_flags[1] == '0')
		c = '0';
	if (tag->c_flags[0] == '-')
	{
		ft_show_plusorspace_f(tag);
		ft_put_f_dochoi(str_demical, tag, dot_idx);
		while(w_size--)
			write(1, " ", 1);
	}
	else
	{
		if (tag->c_flags[1] == '0')
			ft_show_plusorspace_f(tag);
		while(w_size--)
			write(1, &c, 1);
		if (tag->c_flags[1] != '0')
			ft_show_plusorspace_f(tag);
		ft_put_f_dochoi(str_demical, tag, dot_idx);
	}
}
