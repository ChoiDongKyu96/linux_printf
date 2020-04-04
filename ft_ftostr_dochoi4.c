/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftostr_dochoi4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dochoi <dochoi@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 20:37:11 by dochoi            #+#    #+#             */
/*   Updated: 2020/04/04 20:37:13 by dochoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"
#include "libft.h"

int		ft_ftostr_e_size(char *str_demical, int dot_idx, t_tag *tag, int b_idx)
{
	int	i;
	int	size;
	int	sign;

	sign = tag->t_udouble.parts.sign;
	if (tag->t_udouble.parts.exponent == 2047ULL)
		if (tag->t_udouble.parts.mantisa == 2251799813685248ULL || tag->t_udouble.parts.mantisa == 0)
			return (3 + sign);
	size = 0;
	i = 0;
	while (str_demical[i] == '0' && i != b_idx -1)
		i++;
	while (i < b_idx)
	{
		size++;
		i++;
	}
	if (tag->precision > 0 || (tag->precision == 0 && tag->c_flags[2] == '#'))
		size++;
	if (sign == 1 || (tag->c_flags[4] == '+' && sign == 0) ||
	(tag->c_flags[3] ==' ' && sign == 0))
		sign = 1;
	return (size + tag->precision + sign + 4 + (dot_idx - b_idx >= 100 || dot_idx - b_idx <= -100 ));
}

void	ft_show_plusorspace_f(t_tag *tag)
{
	int sign;

	sign = tag->t_udouble.parts.sign;
	if (tag->c_flags[4] == '+' && sign == 0)
		write(1, "+", 1);
	else if (tag->c_flags[3] ==' ' && sign == 0)
		write(1, " ", 1);
	else if (sign == 1)
		write(1, "-", 1);
}

void	ft_put_nan_inf(t_tag *tag)
{
	if (tag->t_udouble.parts.mantisa == 2251799813685248ULL)
		write(1, "nan", 3);
	else if (tag->t_udouble.parts.mantisa == 0)
		write(1, "inf", 3);
}
void	ft_put_f_dochoi(char *str_demical, t_tag *tag, int dot_idx)
{
	int	i;
	int	precision;

	if (tag->t_udouble.parts.exponent == 2047ULL)
		if (tag->t_udouble.parts.mantisa == 2251799813685248ULL || tag->t_udouble.parts.mantisa == 0)
			{
				ft_put_nan_inf(tag);
				return ;
			}
	i = 0;
	precision = tag->precision;
	while (str_demical[i] == '0' && i != dot_idx -1)
		i++;
	while (i < dot_idx)
		write(1, &str_demical[i++], 1);
	if (precision > 0 || tag->c_flags[2] =='#')
		write(1, &str_demical[i++], 1);
	if (precision > 0)
		while (precision--)
			i < 1101 ? (write(1, &str_demical[i++], 1)) : (write(1, "0", 1));
}

void	ft_put_f_width_dochoi(char *str_demical, t_tag *tag, int dot_idx, int size)
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
