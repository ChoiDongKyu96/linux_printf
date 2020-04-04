/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dochoi <dochoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 15:40:38 by dochoi            #+#    #+#             */
/*   Updated: 2020/04/04 03:47:56 by dochoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	strtrim_size(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

unsigned int	finish_point(char *check, const char *s1,
		unsigned int end_point)
{
	unsigned int	i;

	if (end_point == 0)
		return (0);
	i = end_point - 1;
	while (i != 0)
	{
		if (check[(unsigned char)s1[i]] == 0)
			break ;
		i--;
	}
	return (i + 1);
}

void			init_str(char *check, char const *set)
{
	unsigned int	i;

	i = 0;
	while (i < 256)
		check[i++] = 0;
	i = 0;
	while (set[i])
		check[(unsigned char)set[i++]] = 1;
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char			check[256];
	unsigned int	i;
	unsigned int	j;
	unsigned int	end;
	char			*str;

	if (s1 == 0 || set == 0)
		return (0);
	init_str(check, set);
	i = -1;
	while (s1[++i])
		if (check[(unsigned char)s1[i]] == 0)
			break ;
	end = finish_point(check, s1, strtrim_size(s1));
	if (i >= end)
		str = malloc(1);
	else
		str = malloc(end - i + 1);
	if (str == 0)
		return (0);
	j = 0;
	while (i < end)
		str[j++] = s1[i++];
	str[j] = '\0';
	return (str);
}
