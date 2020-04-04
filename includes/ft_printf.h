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
void			ft_put_f_width_dochoi_e(char *str_demical,t_tag *tag, int dot_idx, int size);
void			ft_put_f_dochoi_e(char *str_demical, t_tag *tag, int dot_idx);
void			ft_put_f_dochoi_enumber(int base_dot, int dot_idx);
void			ft_ftostr_set_point_e(char *str_demical, t_tag *tag, int *b_idx);
void			ft_ftostr_dochoi(char *str_demical, t_tag *tag);
int				ft_ftostr_e_size(char *str_demical, int dot_idx, t_tag *tag, int b_idx);
void			ft_show_plusorspace_f(t_tag *tag);
void			ft_put_nan_inf(t_tag *tag);
void			ft_put_f_dochoi(char *str_demical, t_tag *tag, int dot_idx);
void			ft_put_f_width_dochoi(char *str_demical, t_tag *tag, int dot_idx, int size);
int				ft_is_exactly5(char *str_demical, int idx, int *dot_idx);
void			ft_round_bankers(char *str_demical, int idx, int *dot_idx);
void			ft_ftostr_parse(char *base_binary, char *str_demical, t_tag *tag, int *dot_idx);
void			ft_ftostr_set_point(char *str_demical, int *dot_idx);
int				ft_ftostr_size(char *str_demical, int dot_idx, t_tag *tag);
void			ft_ftostr_parse_binary(char *base_binary, unsigned long long value);
void			ft_ftostr_add(char *base_add, int n);
void			ft_ftostr_add_two(char *str_demical, char *base_add);
void			ft_ftostr_shift(char *str_demical, int *dot_idx);
void			ft_ftostr_cal_men(char *base_binary, char *str_demical, int *dot_idx);
int				ft_ftostr_dochoi_g_pre_cal_f(char	*str_demcial);
int				ft_ftostr_dochoi_g_pre_cal_e(char	*str_demcial);

#endif
