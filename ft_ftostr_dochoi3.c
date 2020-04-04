
#include "ft_printf.h"
#include "libft.h"

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