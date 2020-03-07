/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_plus_space_hash.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dochoi <dochoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 16:18:30 by dochoi            #+#    #+#             */
/*   Updated: 2020/03/07 17:44:04 by dochoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_show_plusorspace(t_tag *tag, long long value)
{
	if (tag->c_flags[4] == '+' && value >= 0)
		write(1, "+", 1);
	else if (tag->c_flags[3] ==' ' && value >= 0)
		write(1, " ", 1);
	else if (value < 0)
		write(1, "-", 1);
}

void	ft_show_hash(t_tag *tag)
{
	if (tag->c_flags[2] == '#')
	{
		if (*(tag->cur_ptr) == 'x')
			write(1, "0x", 2);
		else if (*(tag->cur_ptr) == 'X')
			write(1, "0X", 2);
	}
	else if (*(tag->cur_ptr) == 'p')
		write(1, "0x", 2);
}
