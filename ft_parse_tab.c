/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dochoi <dochoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 01:13:39 by dochoi            #+#    #+#             */
/*   Updated: 2020/03/05 23:45:49 by dochoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_what_spcf(t_tag *tag, va_list *ap, unsigned int spc)
{
	if (spc == 3)
		ft_show_d(tag, (int)va_arg(*ap, int));
}

void	ft_parse_flag(t_tag *tag)
{
	unsigned int	i;

	i = 0;

	while (tag->flags[i])
	{
		if (tag->flags[i] == *(tag->cur_ptr))
			tag->c_flags[i] = tag->flags[i];
		i++;
	}
}

void	ft_parse_width(t_tag *tag)
{
	unsigned int	i;

	i = 0;
	while (1)
	{
		if (*(tag->cur_ptr) < '0' || *(tag->cur_ptr) > '9')
			return ;
		tag->width = ((tag->width) * 10) + *(tag->cur_ptr) - '0';
		tag->cur_ptr++;
	}
}

void	ft_parse_precision(t_tag *tag , va_list *ap)
{
	unsigned int	i;

	i = 0;
	tag->cur_ptr++;
	if (*(tag->cur_ptr) == '*')
	{
		tag->precision = (int)va_arg(*ap, int);
		return ;
	}
	tag->precision = 0;
		while (1)
	{
		if (*(tag->cur_ptr) < '0' || *(tag->cur_ptr) > '9')
			return ;
		tag->precision = ((tag->precision) * 10) + *(tag->cur_ptr) - '0';
		tag->cur_ptr++;
	}
}

void	ft_parse_tab(t_tag *tag, va_list *ap)
{
	int	i;

	while (*(tag->cur_ptr))
	{
		ft_parse_flag(tag);
		i = -1;
		while (tag->specifiers[++i])
			if (tag->specifiers[i] == *(tag->cur_ptr))
			{
				ft_what_spcf(tag, ap, i);
				return ;
			}
		if (*(tag->cur_ptr) == '.')
			ft_parse_precision(tag, ap);
		else if (*(tag->cur_ptr) >= '1' && *(tag->cur_ptr) <= '9')
			ft_parse_width(tag);
		else if ((*(tag->cur_ptr) == '*'))
		{
			tag->width = (int)va_arg(*ap, int);
			tag->cur_ptr++;
		}
		else
			tag->cur_ptr++;
	}
}