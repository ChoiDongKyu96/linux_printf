/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dochoi <dochoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:36:50 by dochoi            #+#    #+#             */
/*   Updated: 2020/04/04 00:43:48 by dochoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t i;

	if (dest == 0 && src == 0)
		return (0);
	i = 0;
	if ((unsigned long long)dest < (unsigned long long)src)
	{
		while (i < n)
		{
			((char*)dest)[i] = ((char*)src)[i];
			i++;
		}
	}
	else
	{
		while (i < n)
		{
			((char*)dest)[n - 1 - i] = ((char*)src)[n - 1 - i];
			i++;
		}
	}
	return (dest);
}
