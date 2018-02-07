/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibonifac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 22:14:30 by ibonifac          #+#    #+#             */
/*   Updated: 2018/02/06 12:16:13 by ibonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*set_space_left(int len, int min, char *tmp)
{
	int		i;
	char	*tmp2;

	if (min - len <= 0)
		return (tmp);
	tmp2 = ft_strnew(min - len);
	i = 0;
	while (min > len)
	{
		tmp2[i] = ' ';
		min--;
		i++;
	}
	tmp2[i + 1] = '\0';
	tmp = ft_strjoin_nfree(tmp, tmp2, 3);
	return (tmp);
}

char			*set_space(int len, int min, char *tmp)
{
	int		i;
	char	*tmp2;

	if (min - len <= 0)
		return (tmp);
	tmp2 = ft_strnew(min - len);
	i = 0;
	while (min > len)
	{
		tmp2[i] = ' ';
		min--;
		i++;
	}
	tmp2[i + 1] = '\0';
	tmp = ft_strjoin_nfree(tmp2, tmp, 3);
	return (tmp);
}

char			*space_x_num(t_flags *flags, char *tmp)
{
	if (flags->minus == MINUS)
		tmp = set_space_left(ft_strlen(tmp), flags->field_width, tmp);
	tmp = set_space(ft_strlen(tmp), flags->field_width, tmp);
	return (tmp);
}
