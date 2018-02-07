/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibonifac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 22:21:09 by ibonifac          #+#    #+#             */
/*   Updated: 2017/12/06 19:21:12 by ibonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*tmp;
	unsigned char		*tmp2;
	size_t				i;
	unsigned char		kaka;

	tmp = (unsigned char *)src;
	tmp2 = (unsigned char *)dst;
	i = 0;
	kaka = (unsigned char)c;
	while (i < n)
	{
		if ((*tmp2++ = *tmp++) == kaka)
			return (tmp2);
		i++;
	}
	return (NULL);
}
