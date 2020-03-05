/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dochoi <dochoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 18:21:06 by dochoi            #+#    #+#             */
/*   Updated: 2020/03/06 04:48:16 by dochoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct	s_tag
{
	char		*specifiers;
	char		*flags;
	char		c_swidth[4];
	char		c_flags[5];
	const char	*cur_ptr;
	int			size;
	int			precision;
	int			width;
}				t_tag;

int		ft_printf(const char *format, ...);
void	ft_what_spcf(t_tag *tag, va_list *ap, unsigned int spc);
void	ft_parse_tab(t_tag *tag, va_list *ap);
void	ft_show_d(t_tag *tag, va_list *ap);
void	ft_putint_std(int n);
void	ft_putuint_std(unsigned int n);
void	ft_putull_std(unsigned long long n);
void	ft_putll_std(long long n);

#endif
