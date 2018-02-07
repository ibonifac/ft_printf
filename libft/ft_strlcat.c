/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibonifac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 22:21:09 by ibonifac          #+#    #+#             */
/*   Updated: 2017/12/06 19:21:12 by ibonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

unsigned long	ft_strlcat(char *dest, char const *src, unsigned long n)
{
	unsigned long i;
	unsigned long l_dest;
	unsigned long l_src;

	i = 0;
	l_dest = ft_strlen(dest);
	l_src = ft_strlen(src);
	if (n <= l_dest)
		return (n + l_src);
	while (i < (n - l_dest - 1) && src[i] != '\0')
	{
		dest[l_dest + i] = src[i];
		i++;
	}
	dest[l_dest + i] = '\0';
	return (l_dest + l_src);
}
