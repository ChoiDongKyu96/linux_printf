/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftostr_dochoi.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dochoi <dochoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 14:51:23 by dochoi            #+#    #+#             */
/*   Updated: 2020/03/13 22:26:49 by dochoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"
#include "libft.h"

void	ft_ftostr_parse_binary(char *base_binary, unsigned long long value)
{
	int		i;

	i = 0;
	while (i < 52)
	{
		if (value % 2 == 0)
			base_binary[i++] = 0;
		else
			base_binary[i++] = 1;
		value /= 2;
	}
}

void	ft_ftostr_add(char *base_add, int n)
{
	int			i;
	int			temp;
	char		str_temp[1101];

	ft_memcpy(str_temp, base_add, 1101);
	while (n--)
	{
		i = 1100;
		while (i > 0)
		{
			temp = (base_add[i] - '0') + (str_temp[i] - '0');
			if (temp >= 10)
			{
				base_add[i - 1] += 1;
				base_add[i] = temp - 10 + '0';
			}
			else
				base_add[i] = temp + '0';
			i--;
		}
	}
}

void	ft_ftostr_add_two(char *str_demical, char *base_add)
{
	int			i;
	int			temp;

	i = 1100;
	while (i > 0)
	{
		temp = (str_demical[i] - '0') + (base_add[i] - '0');
		if (temp >= 10)
		{
			str_demical[i - 1] += 1;
			str_demical[i] = temp - 10 + '0';
		}
		else
			str_demical[i] = temp + '0';
		i--;
	}
}

void	ft_ftostr_shift(char *str_demical, int *dot_idx)
{
	int	i;

	i = 0;
	while (i < 1100)
	{
		str_demical[i] = str_demical[i + 1];
		i++;
	}
	str_demical[i] = '0';
	(*dot_idx)--;
}

void	ft_ftostr_cal_men(char *base_binary, char *str_demical, int *dot_idx)
{
	int		i;
	char	base_add[1101];

	ft_memset(base_add, '0', sizeof(base_add));
	base_add[1100] = '1';
	i = 51;
	while (i >= 0)
	{
		ft_ftostr_shift(str_demical, dot_idx);
		ft_ftostr_add(base_add, 4);
		if (base_binary[i] == 1)
			ft_ftostr_add_two(str_demical, base_add);
		i--;
	}
}

int		ft_is_exactly5(char *str_demical, int idx, int *dot_idx)
{
	int	i;

	i = *dot_idx + idx + 2;
	while (i < 1101)
	{
		if (str_demical[i++] != '0')
			return (0);
	}
	return (1);
}

void	ft_round_bankers(char *str_demical, int idx, int *dot_idx)
{
	char	str_temp[1101];

	memset(str_temp, '0', sizeof(str_temp));
	if (*dot_idx + idx + 1> 1100)
		return ;

	str_temp[*dot_idx + idx + 1] = '5';
	if (str_demical[*dot_idx + idx + 1] > '5')
		ft_ftostr_add_two(str_demical, str_temp);
	else if (str_demical[*dot_idx + idx + 1] == '5')
	{
		if (!ft_is_exactly5(str_demical, idx, dot_idx) || (str_demical[*dot_idx + idx] % 2 != 0))
			ft_ftostr_add_two(str_demical, str_temp);
	}
}

void	ft_ftostr_parse(char *base_binary, char *str_demical, t_tag *tag, int *dot_idx)
{
	int	n_exponent;

	n_exponent = tag->t_udouble.parts.exponent - 1023;
	ft_ftostr_parse_binary(base_binary, tag->t_udouble.parts.mantisa);
	ft_ftostr_cal_men(base_binary, str_demical, dot_idx);
	str_demical[*dot_idx] = '1';
	if (n_exponent > 0)
		while (n_exponent--)
			ft_ftostr_add(str_demical, 1);
	else if (n_exponent < 0)
		while (n_exponent++)
		{
			ft_ftostr_add(str_demical, 4);
			(*dot_idx)--;
		}
}

void	ft_ftostr_set_point(char *str_demical, int *dot_idx)
{
	int i;

	i = 0;
	while (i < *dot_idx)
	{
		str_demical[i] = str_demical[i + 1];
		i++;
	}
	str_demical[i] = '.';
}

int		ft_ftostr_size(char *str_demical, int dot_idx, t_tag *tag)
{
	int i;
	int size;
	int sign;

	sign = tag->t_udouble.parts.sign;
	if (tag->t_udouble.parts.exponent == 2047ULL)
		if (tag->t_udouble.parts.mantisa == 2251799813685248ULL || tag->t_udouble.parts.mantisa == 0)
			return (3 + sign);
	size = 0;
	i = 0;
	while (str_demical[i] == '0' && i != dot_idx -1)
		i++;
	while (i < dot_idx)
	{
		size++;
		i++;
	}
	if (tag->precision > 0 || (tag->precision == 0 && tag->c_flags[2] == '#'))
		size++;
	if (sign == 1 || (tag->c_flags[4] == '+' && sign == 0) ||
	(tag->c_flags[3] ==' ' && sign == 0))
		sign = 1;
	return (size + tag->precision + sign);
}

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

int		ft_ftostr_dochoi_g_pre_cal_f(char	*str_demcial)
{
	int	i;
	int	size;
	int base;

	size = 15;
	i = 0;
	while(str_demcial[i] != '.')
		i++;
	i++;
	base = i;
	i = i + 14;
	while(i >= base)
	{
		if (str_demcial[i] != '0')
			break ;
		size--;
		i--;
	}
	return (size);
}

int		ft_ftostr_dochoi_g_pre_cal_e(char	*str_demcial)
{
	int	i;
	int	size;
	int base;

	size = 15;
	i = 0;
	while(str_demcial[i] != '0')
		i++;
	base = i;
	i = i + 14;
	while(i >= base)
	{
		if ( str_demcial[i] == '.')
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
	int 		n;

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
