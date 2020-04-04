/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dochoi <dochoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 23:48:35 by dochoi            #+#    #+#             */
/*   Updated: 2020/04/04 01:58:18 by dochoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (*needle == '\0')
		return ((char*)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		while (needle[j] && i + j < len)
		{
			if (haystack[i + j] != needle[j])
				break ;
			j++;
		}
		if (!needle[j])
			return ((char*)(haystack + i));
		i++;
	}
	return (0);
}
