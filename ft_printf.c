/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dochoi <dochoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:53:09 by dochoi            #+#    #+#             */
/*   Updated: 2020/03/05 23:38:47 by dochoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_init_tab(t_tag *tag)
{
	tag->specifiers = "cspdiuxX%nfge";
	tag->flags = "-0# +";
	tag->size = 0;

}

void	ft_memset_tab(t_tag *tag)
{
	ft_memset(tag->c_flags, 0, sizeof(tag->c_flags));
	tag->precision = -1;
	tag->width = 0;
}

int		ft_printf(const char *format, ...)
{
	va_list ap;
	t_tag	tag;

	tag.cur_ptr = format;
	ft_init_tab(&tag);
	va_start(ap, format);
	while (*(tag.cur_ptr))
	{
		if (*(tag.cur_ptr) == '%')
		{
			tag.cur_ptr++;
			ft_memset_tab(&tag);
			ft_parse_tab(&tag, &ap);
		}
		else
		{
			write(1, tag.cur_ptr, 1);
			tag.size++;
		}
		tag.cur_ptr++;
	}
	va_end(ap);
	return (tag.size);
}