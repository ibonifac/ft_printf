/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibonifac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 22:21:09 by ibonifac          #+#    #+#             */
/*   Updated: 2017/12/06 19:21:12 by ibonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	unsigned char		*tmp;
	unsigned char		*tmp2;

	i = 0;
	tmp = (unsigned char*)s1;
	tmp2 = (unsigned char*)s2;
	if (n == 0)
		return (0);
	while (tmp[i] && tmp2[i])
	{
		if (tmp[i] != tmp2[i])
			return (tmp[i] - tmp2[i]);
		i++;
		if (!(i < n))
			return (tmp[i - 1] - tmp2[i - 1]);
	}
	return (tmp[i] - tmp2[i]);
}
