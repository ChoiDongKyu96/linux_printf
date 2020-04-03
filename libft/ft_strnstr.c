/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dochoi <dochoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 23:48:35 by dochoi            #+#    #+#             */
/*   Updated: 2020/04/03 20:00:22 by dochoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		is_eqal(const char *haystack, const char *needle,
		size_t i, size_t neddle_size)
{
	size_t	j;

	j = 0;
	while (j < neddle_size)
	{
		if (needle[j] != haystack[i + j])
		{
			return (0);
			break ;
		}
		j++;
	}
	return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needle_size;

	needle_size = 0;
	while (needle[needle_size])
		needle_size++;
	if (needle_size == 0)
		return ((char*)haystack);
	i = 0;
	if (len < needle_size)
		return (0);
	while (i < len - needle_size + 1)
	{
		if (is_eqal(haystack, needle, i, needle_size))
			return ((char*)(haystack + i));
		i++;
	}
	return (0);
}
