/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_wc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dochoi <dochoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 19:21:10 by dochoi            #+#    #+#             */
/*   Updated: 2020/04/03 21:05:50 by dochoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** 63		00111111
** 128		10000000
** 192		11000000
** 224		11100000
** 240		11110000
**
** put[0][1]	11000001 10000000
** UTF-8
** U-00000000 - U-0000007F:  0xxxxxxx (1byte : ENG)
** U-00000080 - U-000007FF:  110xxxxx 10xxxxxx
** U-00000800 - U-0000FFFF:  1110xxxx 10xxxxxx 10xxxxxx (3 bytes : KOR)
** U-00010000 - U-001FFFFF:  11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
** U-00200000 - U-03FFFFFF:  111110xx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx
** U-04000000 - U-7FFFFFFF:  1111110x 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx
** 10xxxxxx
** ex) c = 128, put[0][1] -> 11000001 10000000
*/

static void		oct_4(wint_t c)
{
	unsigned char put[4];

	put[0] = (c >> 18) + 240;
	put[1] = ((c >> 12) & 63) + 128;
	put[2] = ((c >> 6) & 63) + 128;
	put[3] = ((c & 63) + 128);
	write(1, put, 4);
}

static void		oct_3(wint_t c)
{
	unsigned char put[3];

	put[0] = (c >> 12) + 224;
	put[1] = ((c >> 6) & 63) + 128;
	put[2] = ((c & 63) + 128);
	write(1, put, 3);
}

static void		oct_2(wint_t c)
{
	unsigned char put[2];

	put[0] = (c >> 6) + 192;
	put[1] = ((c & 63) + 128);
	write(1, put, 2);
}

static void		oct_1(wint_t c)
{
	write(1, &c, 1);
}

void			ft_show_wc(wint_t c, t_tag *tag)
{
	if (c <= 127)
	{
		tag->size += 1;
		oct_1(c);
	}
	if (c >= 127 && c <= 2047)
	{
		tag->size += 2;
		oct_2(c);
	}
	if (c >= 2048 && c <= 65535)
	{
		tag->size += 3;
		oct_3(c);
	}
	if (c >= 65536 && c <= 2097151)
	{
		tag->size += 4;
		oct_4(c);
	}
}
