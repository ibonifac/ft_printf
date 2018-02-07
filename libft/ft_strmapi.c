/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibonifac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 22:21:09 by ibonifac          #+#    #+#             */
/*   Updated: 2017/12/06 19:21:12 by ibonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int			i;
	char		*strmapi;

	if (s == 0 || f == 0)
		return (0);
	strmapi = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (strmapi == 0)
		return (0);
	i = -1;
	while (s[++i])
		strmapi[i] = f(i, s[i]);
	strmapi[i] = '\0';
	return (strmapi);
}
