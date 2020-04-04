
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