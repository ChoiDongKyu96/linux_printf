/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dochoi <dochoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:18:03 by dochoi            #+#    #+#             */
/*   Updated: 2020/03/01 20:44:57 by dochoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int answer;
	int i;
	int minus;

	minus = 1;
	i = -1;
	answer = 0;
	while (str[++i])
	{
		if (!((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
			break ;
	}
	if (str[i] == '-')
		minus = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (minus * answer);
		answer = answer * 10 + (str[i] - '0');
		i++;
	}
	return (minus * answer);
}
