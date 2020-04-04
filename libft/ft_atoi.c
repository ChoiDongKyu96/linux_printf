/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dochoi <dochoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:18:03 by dochoi            #+#    #+#             */
/*   Updated: 2020/04/04 03:23:09 by dochoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_atoi_2(const char *str, int minus)
{
	int answer;
	int i;

	i = 0;
	answer = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (minus * answer);
		answer = answer * 10 + (str[i] - '0');
		i++;
	}
	return (minus * answer);
}

static int	ft_is_max(const char *str, int minus)
{
	char	*temp;
	int		i;

	i = 0;
	if (minus == -1)
		temp = "9223372036854775808";
	else
		temp = "9223372036854775807";
	while (temp[i] && str[i])
	{
		if (i == 18 && (str[i] > '9' || str[i] <= temp[i]))
			break ;
		if (str[i] <= '9' && str[i] >= temp[i])
			i++;
		else
			break ;
	}
	if (i == 19 && minus == -1)
		return (0);
	else if (i == 19 && minus == 1)
		return (-1);
	return (1);
}

int			ft_atoi(const char *str)
{
	int	i;
	int	minus;
	int max_expt;

	minus = 1;
	i = -1;
	while (str[++i])
		if (!((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
			break ;
	if (str[i] == '-')
		minus = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if ((max_expt = ft_is_max(&str[i], minus)) != 1)
		return (max_expt);
	return (ft_atoi_2(&str[i], minus));
}
