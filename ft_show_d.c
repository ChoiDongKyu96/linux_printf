/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dochoi <dochoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 04:19:40 by dochoi            #+#    #+#             */
/*   Updated: 2020/03/06 00:18:08 by dochoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_dfs_out(int n)
{
	char	c;

	if (n == 0)
		return ;
	c = n % 10 + '0';
	ft_putnbr_dfs_out(n / 10);
	write(1, &c, 1);
}

void	ft_putnbr_stdout(int n, t_tag *tag)
{

	if (tag->c_flags[4] == '+' && n >= 0)
		write(1, "+", 1);
	else if (tag->c_flags[3] ==' ' && n >= 0)
		write(1, " ", 1);
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n == 0)
		write(1, "0", 1);
	else
		ft_putnbr_dfs_out(n);

}

int	ft_show_d_size(int value)
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

void	ft_show_d_width(t_tag *tag, int value, int remain)
{
	char c = ' ';

	tag->size += remain;
	if (tag->c_flags[0] == '-')
	{
		ft_putnbr_stdout(value, tag);
		while (remain--)
			write(1, &c, 1);
	}
	else
	{
		if (tag->c_flags[1] == '0')
			c = '0';
		while (remain--)
			write(1, &c, 1);
		ft_putnbr_stdout(value, tag);
	}
}

void	ft_show_d(t_tag *tag, int value)
{
	int size;

	size = ft_show_d_size(value);
	if (tag->c_flags[4] == '+' && value >= 0 ||
	tag->c_flags[3] ==' ' && value >= 0)
		size++;
	if (tag->width <= size)
		ft_putnbr_stdout(value, tag);
	else
		ft_show_d_width(tag, value, tag->width - size);
	tag->size += size;
}