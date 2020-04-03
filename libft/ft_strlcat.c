/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dochoi <dochoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 22:24:14 by dochoi            #+#    #+#             */
/*   Updated: 2020/04/03 19:59:11 by dochoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	i;
	size_t	destlen;
	size_t	tsize;

	i = 0;
	tsize = 0;
	destlen = 0;
	while (src[tsize] != '\0')
		tsize++;
	while (dst[destlen] != '\0')
		destlen++;
	if (dstsize == 0)
		return (tsize);
	if (dstsize < destlen)
		tsize += dstsize;
	else
		tsize += destlen;
	while (destlen + i + 1 < dstsize && src[i])
	{
		dst[destlen + i] = src[i];
		i++;
	}
	dst[destlen + i] = '\0';
	return (tsize);
}
