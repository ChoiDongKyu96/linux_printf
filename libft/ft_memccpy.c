/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dochoi <dochoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 20:29:35 by dochoi            #+#    #+#             */
/*   Updated: 2020/04/04 00:39:21 by dochoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dest,
		const void *restrict src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char*)src)[i] == (unsigned char)c)
		{
			((unsigned char*)dest)[i] = ((unsigned char*)src)[i];
			i++;
			return ((unsigned char*)dest + i);
		}
		((unsigned char*)dest)[i] = ((unsigned char*)src)[i];
		i++;
	}
	return (0);
}
