/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dochoi <dochoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 23:38:42 by dochoi            #+#    #+#             */
/*   Updated: 2020/04/03 19:59:27 by dochoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			*ptr;

	i = 0;
	ptr = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			ptr = ((char*)(s + i));
		i++;
	}
	if (s[i] == (unsigned char)c)
		ptr = ((char*)(s + i));
	return (ptr);
}
