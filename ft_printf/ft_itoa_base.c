/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibonifac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 22:14:30 by ibonifac          #+#    #+#             */
/*   Updated: 2018/02/06 12:16:13 by ibonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		conv_hex(uintmax_t nb)
{
	if (nb >= 10)
		return (nb - 10 + 'a');
	else
		return (nb + '0');
}

char			*ft_itoa_base(uintmax_t n, uintmax_t base)
{
	uintmax_t		tmpn;
	int				i;
	char			*str;

	i = 0;
	tmpn = n;
	while (tmpn >= base)
	{
		tmpn /= base;
		i++;
	}
	if (!(str = (char*)malloc(sizeof(char) * (i + 2))))
		return (NULL);
	str[i + 1] = '\0';
	while (i >= 0)
	{
		tmpn = n % base;
		str[i] = conv_hex(tmpn);
		n /= base;
		i--;
	}
	return (str);
}
