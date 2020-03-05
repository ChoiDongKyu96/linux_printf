/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlls_std.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dochoi <dochoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 03:47:20 by dochoi            #+#    #+#             */
/*   Updated: 2020/03/06 05:04:32 by dochoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putll_dfs_out(long long n)
{
	char	c;

	if (n == 0)
		return ;
	c = n % 10 + '0';
	ft_putll_dfs_out(n / 10);
	write(1, &c, 1);
}

void	ft_putll_std(long long n)
{
	if (n == -9223372036854775808ULL)
	{
		write(1, "-9223372036854775808", 20);
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
		ft_putll_dfs_out(n);
}


void	ft_putull_dfs_out(unsigned long long n)
{
	char	c;

	if (n == 0)
		return ;
	c = n % 10 + '0';
	ft_putull_dfs_out(n / 10);
	write(1, &c, 1);
}

void	ft_putull_std(unsigned long long n)
{
	if (n == 0)
		write(1, "0", 1);
	else
		ft_putull_dfs_out(n);
}