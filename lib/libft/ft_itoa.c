/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dochoi <dochoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 21:59:59 by dochoi            #+#    #+#             */
/*   Updated: 2020/03/03 20:09:24 by dochoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	itoa_ptr_size(long long ln)
{
	unsigned int	size;

	size = 0;
	if (ln < 0)
		size = 1;
	while (ln != 0)
	{
		ln /= 10;
		size++;
	}
	return (size);
}

char			*is_zero_itoa(void)
{
	char	*ptr;

	if (!(ptr = (char*)malloc(2)))
		return (0);
	ptr[1] = '\0';
	ptr[0] = '0';
	return (ptr);
}

char			*ft_itoa(int n)
{
	unsigned int	size;
	char			*ptr;
	long long		ln;
	unsigned int	i;

	if (n == 0)
		return (is_zero_itoa());
	ln = (long long)n;
	size = itoa_ptr_size(ln);
	if (!(ptr = (char*)malloc(size + 1)))
		return (0);
	ptr[size] = '\0';
	i = 0;
	if (n < 0)
	{
		ptr[0] = '-';
		ln *= -1;
	}
	while (ln != 0)
	{
		ptr[size - 1 - i] = (ln % 10) + '0';
		ln /= 10;
		i++;
	}
	return (ptr);
}
