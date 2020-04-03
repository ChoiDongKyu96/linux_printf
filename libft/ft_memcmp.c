/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dochoi <dochoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:03:24 by dochoi            #+#    #+#             */
/*   Updated: 2020/04/03 19:55:41 by dochoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	char		*ptr1;
	char		*ptr2;

	ptr1 = (char*)s1;
	ptr2 = (char*)s2;
	i = 0;
	while (i < n)
	{
		if (ptr1[i] != ptr2[i])
			return ((unsigned char)(ptr1[i]) - (unsigned char)(ptr2[i]));
		i++;
	}
	return (0);
}
