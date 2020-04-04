/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dochoi <dochoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 00:24:53 by dochoi            #+#    #+#             */
/*   Updated: 2020/04/04 21:04:24 by dochoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	unsigned char put[2];

	if (c >= 0)
		write(fd, &c, 1);
	else
	{
		put[0] = ((unsigned char)c >> 6) + 192;
		put[1] = (((unsigned char)c & 63) + 128);
		write(fd, put, 2);
	}
}
