/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibonifac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 22:21:09 by ibonifac          #+#    #+#             */
/*   Updated: 2017/12/06 19:21:12 by ibonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	uintmax_t		i;
	char			*str2;

	i = 0;
	while (src[i])
		i++;
	str2 = (char*)malloc(sizeof(char) * i + 1);
	if (!str2)
		return (NULL);
	i = 0;
	while (src[i])
	{
		str2[i] = src[i];
		i++;
	}
	str2[i] = '\0';
	return (str2);
}
