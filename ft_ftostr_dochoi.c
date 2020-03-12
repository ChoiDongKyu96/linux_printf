/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftostr_dochoi.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dochoi <dochoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 14:51:23 by dochoi            #+#    #+#             */
/*   Updated: 2020/03/12 00:10:23 by dochoi           ###   ########.fr       */
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
	char		str_temp[701];

	ft_memcpy(str_temp, base_add, 701);
	while (n--)
	{
		i = 700;
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

	i = 700;
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
	while (i < 700)
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
	char	base_add[701];

	ft_memset(base_add, '0', sizeof(base_add));
	base_add[700] = '1';
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

void	ft_ftostr_cal_plus(char *str_demical, int n_exponent)
{
	while (n_exponent--)
		ft_ftostr_add(str_demical, 1);
}

void	ft_ftostr_cal_minus(char *str_demical, int n_exponent, int *dot_idx)
{
	while (n_exponent++)
	{
		ft_ftostr_add(str_demical, 4);
		ft_ftostr_shift(str_demical, dot_idx);
	}
}

int		ft_is_exactly5(char *str_demical, int idx, int *dot_idx)
{
	int	i;

	i = *dot_idx + idx + 2;
	while (i < 701)
	{
		if (str_demical[i] != '0')
			return (0);
	}
	return (1);
}

void	ft_round_bankers(char *str_demical, int idx, int *dot_idx)
{
	char	str_temp[701];

	memset(str_temp, 0, sizeof(str_temp));
	if (*dot_idx + idx + 1> 700)
		return ;

	str_temp[*dot_idx + idx + 1] = '5';
	if (str_demical[*dot_idx + idx + 1] > '5')
		ft_ftostr_add_two(str_demical, str_temp);
	else if (str_demical[*dot_idx] == '5')
	{
		if (!ft_is_exactly5(str_demical, idx, dot_idx) && (str_demical[*dot_idx] % 2 != 0))
			ft_ftostr_add_two(str_demical, str_temp);
	}
}

void	ft_ftostr_parse(char *base_binary, char *str_demical, t_udouble u_value, int *dot_idx)
{
	int	n_exponent;

	n_exponent = u_value.parts.exponent - 1023;
	ft_ftostr_parse_binary(base_binary, u_value.parts.mantisa);
	ft_ftostr_cal_men(base_binary, str_demical, dot_idx);
	str_demical[*dot_idx] = '1';
	if (n_exponent > 0)
		ft_ftostr_cal_plus(str_demical, n_exponent);
	else if (n_exponent < 0)
		ft_ftostr_cal_minus(str_demical, n_exponent, dot_idx);
}

void	ft_ftostr_set_point(char *str_demical, int *dot_idx)
{
	int i = 0;

	i = 0;
	while (i < *dot_idx)
	{
		str_demical[i] = str_demical[i + 1];
		i++;
	}
	str_demical[i] = '.';
}

void	ft_ftostr_dochoi(double value, t_tag *tag)
{
	t_udouble	u_value;
	char		base_binary[52];
	char		str_demical[701];
	int			dot_idx;

	dot_idx = 700;
	ft_memset(base_binary, 0, sizeof(base_binary));
	ft_memset(str_demical, '0', sizeof(str_demical));
	u_value.value = value;
	ft_ftostr_parse(base_binary, str_demical, u_value, &dot_idx);
	ft_round_bankers(str_demical, tag->precision, &dot_idx);
	ft_ftostr_set_point(str_demical, &dot_idx);
	for(int i = 600; i < 701; i++)
	 	printf("%c", str_demical[i]);
	printf("\n");
}