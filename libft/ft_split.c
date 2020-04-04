/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dochoi <dochoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:25:20 by dochoi            #+#    #+#             */
/*   Updated: 2020/04/04 03:48:59 by dochoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				free_all(unsigned int idx, char **pptr)
{
	unsigned int	i;

	i = 0;
	while (i < idx)
	{
		free(pptr[i]);
		i++;
	}
	free(pptr);
	return (0);
}

int				ptr_size(char **pptr, char const *s, char c)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	idx;

	j = 0;
	i = 0;
	idx = 0;
	while (1)
	{
		if ((s[i] == c || s[i] == '\0') && j != 0)
		{
			if (!(pptr[idx] = malloc(j + 1)))
				return (free_all(idx, pptr));
			pptr[idx][j] = '\0';
			j = 0;
			idx++;
		}
		else if (!(s[i] == c || s[i] == '\0'))
			j++;
		if (s[i] == '\0')
			break ;
		i++;
	}
	return (1);
}

unsigned int	pptr_size(char const *s, char c)
{
	unsigned int	i;
	unsigned int	size;
	unsigned int	j;

	j = 0;
	size = 0;
	i = 0;
	while (1)
	{
		if ((s[i] == c || s[i] == '\0') && j != 0)
		{
			j = 0;
			size++;
		}
		else if (s[i] != c && s[i] != '\0')
			j++;
		if (s[i] == '\0')
			break ;
		i++;
	}
	if (j == 0 && size == 0)
		return (0);
	return (size);
}

void			insert_str(char **pptr, char const *s, char c)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	idx;

	j = 0;
	i = 0;
	idx = 0;
	while (1)
	{
		if ((s[i] == c || s[i] == '\0') && j != 0)
		{
			j = 0;
			idx++;
		}
		else if (!(s[i] == c || s[i] == '\0'))
		{
			pptr[idx][j] = s[i];
			j++;
		}
		if (s[i] == '\0')
			break ;
		i++;
	}
}

char			**ft_split(char const *s, char c)
{
	char			**pptr;
	unsigned int	p_size;

	if (s == 0)
		return (0);
	p_size = pptr_size(s, c);
	if (!(pptr = (char**)malloc(sizeof(char*) * (p_size + 1))))
		return (0);
	pptr[p_size] = 0;
	if (!ptr_size(pptr, s, c))
		return (0);
	insert_str(pptr, s, c);
	return (pptr);
}
