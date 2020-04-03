/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dochoi <dochoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 20:29:35 by dochoi            #+#    #+#             */
/*   Updated: 2020/04/03 20:10:41 by dochoi           ###   ########.fr       */
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
		if (((char*)src)[i] == (unsigned char)c)
		{
			((char*)dest)[i] = ((char*)src)[i];
			i++;
			return ((char*)dest + i);
		}
		((char*)dest)[i] = ((char*)src)[i];
		i++;
	}
	return (0);
}
