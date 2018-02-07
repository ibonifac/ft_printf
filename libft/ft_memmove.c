/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibonifac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 22:21:09 by ibonifac          #+#    #+#             */
/*   Updated: 2017/12/06 19:21:12 by ibonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, unsigned long n)
{
	unsigned long	i;
	unsigned char	*dest;
	unsigned char	*src;

	dest = (unsigned char *)s1;
	src = (unsigned char *)s2;
	i = 0;
	if (src < dest)
	{
		while (++i <= n)
			dest[n - i] = src[n - i];
	}
	else
	{
		while (i < n)
		{
			dest[i] = src[i];
			i++;
		}
	}
	return (s1);
}
