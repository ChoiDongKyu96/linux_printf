/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dochoi <dochoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 19:53:07 by dochoi            #+#    #+#             */
/*   Updated: 2020/03/06 05:07:10 by dochoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int main()
{
	//ft_printf("abd%d %d", 1,"2" );
	//printf("|%*.*d*|", 20, 10, 12345);
	setbuf(stdout, NULL);
//printf("%d\n",printf("|%#f|\n", 2.3));
//ft_printf("%d\n", ft_printf("|% d|\n",23));
//ft_printf("|%#o|\n",20);
printf("%d\n",printf("|%o|\n", 2147486347));

//ft_printf("%d\n",ft_printf("|%+hhi|\n", 500));

// printf("|%*d|\n",20,2333);

// ft_printf("|%*d|\n",20,2333);

// printf("|%-*d|\n",10,2333);

// ft_printf("|%-*d|\n",10,2333);

// printf("|%-20d|\n",2333);

// ft_printf("|%-20d|\n",2333);

//ft_printf("|%*d|\n",20,2333);
//ft_printf("one%d two%d three%d four%d five%d\n", -1, 0, 333 ,2147483647, -2147483648);
	//printf("%d\n",prinf("%0*s\n", 10, "7890"));
//	ft_putnbr_fd(12345678, 1);
}
