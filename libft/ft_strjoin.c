/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dochoi <dochoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 15:11:38 by dochoi            #+#    #+#             */
/*   Updated: 2020/04/04 03:46:44 by dochoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	str_join_size(char const *s)
{
	unsigned int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	s1_size;
	unsigned int	s2_size;
	char			*str;
	unsigned int	i;

	if (s1 == 0 || s2 == 0)
		return (0);
	i = 0;
	s1_size = str_join_size(s1);
	s2_size = str_join_size(s2);
	if (!(str = malloc(s1_size + s2_size + 1)))
		return (0);
	while (i < s1_size)
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < s2_size)
	{
		str[i + s1_size] = s2[i];
		i++;
	}
	str[i + s1_size] = '\0';
	return (str);
}
