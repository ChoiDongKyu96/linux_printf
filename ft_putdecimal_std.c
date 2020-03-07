/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdecimal_std.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dochoi <dochoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 03:46:01 by dochoi            #+#    #+#             */
/*   Updated: 2020/03/07 17:03:05 by dochoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putuint_dfs_out(unsigned int n)
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

static void	ft_putull_dfs_out(unsigned long long n)
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