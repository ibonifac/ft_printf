/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub_nfree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibonifac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 22:21:09 by ibonifac          #+#    #+#             */
/*   Updated: 2017/12/06 19:21:12 by ibonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub_nfree(char *s, unsigned int start, size_t len, int option)
{
	char		*str;
	size_t		i;
	size_t		k;

	i = start;
	k = 0;
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (k < len && s && s[i])
	{
		str[k] = s[i];
		i++;
		k++;
	}
	str[k] = '\0';
	if (option == 1)
		if (s)
			free(s);
	return (str);
}
