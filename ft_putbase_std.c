/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase_std.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dochoi <dochoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 15:34:57 by dochoi            #+#    #+#             */
/*   Updated: 2020/03/07 17:55:48 by dochoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putbasei_dfs_out(unsigned int n, const char *base,
 unsigned int n_base)
{
	char			c;
	unsigned int	i;

	if (n == 0)
		return ;
	i = n % n_base;
	c = base[i];
	ft_putbasei_dfs_out(n / n_base, base, n_base);
	write(1, &c, 1);
}

void	ft_putbasei_std(unsigned int n, const char *base,
 unsigned int n_base)
{
	if (n == 0)
		write(1, base, 1);
	else
		ft_putbasei_dfs_out(n , base, n_base);
}

static void	ft_putbasell_dfs_out(unsigned long long n,
 const char *base, unsigned long long  n_base)
{
	char			c;
	unsigned int	i;

	if (n == 0)
		return ;
	i = n % n_base;
	c = base[i];
	ft_putbasell_dfs_out(n / n_base, base, n_base);
	write(1, &c, 1);
}

void	ft_putbasell_std(unsigned long long n,
 const char *base, unsigned long long n_base)
{
	if (n == 0)
		write(1, &(*base), 1);
	else
		ft_putbasell_dfs_out(n , base, n_base);
}