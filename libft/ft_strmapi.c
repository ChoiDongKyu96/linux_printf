/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dochoi <dochoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 23:40:05 by dochoi            #+#    #+#             */
/*   Updated: 2020/04/04 03:49:43 by dochoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (s == 0 || f == 0)
		return (0);
	while (s[i])
		i++;
	if (!(str = (char*)malloc(i + 1)))
		return (0);
	str[i] = '\0';
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	i = 0;
	while (s[i])
	{
		str[i] = f(i, str[i]);
		i++;
	}
	return (str);
}
