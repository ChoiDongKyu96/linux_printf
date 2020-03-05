/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putints_std.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dochoi <dochoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 03:46:01 by dochoi            #+#    #+#             */
/*   Updated: 2020/03/06 05:04:04 by dochoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putint_dfs_out(int n)
{
	char	c;

	if (n == 0)
		return ;
	c = n % 10 + '0';
	ft_putint_dfs_out(n / 10);
	write(1, &c, 1);
}

void	ft_putint_std(int n)
{
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
		ft_putint_dfs_out(n);
}

void	ft_putuint_dfs_out(unsigned int n)
{
	char	c;

	if (n == 0)
		return ;
	c = n % 10 + '0';
	ft_putuint_dfs_out(n / 10);
	write(1, &c, 1);
}

void	ft_putuint_std(unsigned int n)
{
	if (n == 0)
		write(1, "0", 1);
	else
		ft_putuint_dfs_out(n);
}