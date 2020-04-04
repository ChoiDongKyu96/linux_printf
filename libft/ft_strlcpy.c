/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dochoi <dochoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 20:37:17 by dochoi            #+#    #+#             */
/*   Updated: 2020/04/04 00:51:55 by dochoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	i;
	size_t	srcsize;

	if (dst == 0 || src == 0)
		return (0);
	i = 0;
	srcsize = 0;
	while (src[srcsize] != '\0')
		srcsize++;
	if (dstsize == 0)
		return (srcsize);
	while (i + 1 < dstsize && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srcsize);
}
