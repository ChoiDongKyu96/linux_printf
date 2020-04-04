/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dochoi <dochoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 18:21:06 by dochoi            #+#    #+#             */
/*   Updated: 2020/04/04 18:35:31 by dochoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <wchar.h>
# include <stdint.h>
# include "libft.h"

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
	union		u_double
	{
		double	value;

		struct	s_part
		{
			uint64_t mantisa : 52;
			uint64_t exponent : 11;
			uint64_t sign : 1;
		}		parts;
	}			t_udouble;
}				t_tag;

int				ft_printf(const char *format, ...);
void			ft_what_spcf(t_tag *tag, va_list *ap, unsigned int spc);
void			ft_parse_tab(t_tag *tag, va_list *ap);
void			ft_show_d(t_tag *tag, va_list *ap);
void			ft_putuint_std(unsigned int n);
void			ft_putull_std(unsigned long long n);
int				ft_custom_size(long long value, long long base);
void			ft_show_c(t_tag *tag, va_list *ap);
void			ft_show_s(t_tag *tag, va_list *ap);
void			ft_show_u(t_tag *tag, va_list *ap);
void			ft_show_xx(t_tag *tag, va_list *ap);
void			ft_show_o(t_tag *tag, va_list *ap);
void			ft_show_f(t_tag *tag, va_list *ap);
void			ft_show_p(t_tag *tag, va_list *ap);
void			ft_insert_n(t_tag *tag, va_list *ap);
void			ft_putbasell_std(unsigned long long n,
		const char *base, unsigned long long n_base);
void			ft_putbasei_std(unsigned int n, const char *base,
		unsigned int n_base);
void			ft_show_plusorspace(t_tag *tag, long long value);
void			ft_show_hash(t_tag *tag, long long value);
int				ft_custom_str_size(t_tag *tag, wchar_t *str);
void			ft_show_wc(wint_t c, t_tag *tag);
void			ft_ftostr_dochoi(char *str_demical, t_tag *tag);
void			ft_ftostr_dochoi_e(char *str_demical, t_tag *tag);
void			ft_ftostr_dochoi_g(char *str_demical, t_tag *tag);

#endif
