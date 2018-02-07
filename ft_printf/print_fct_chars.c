/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fct_chars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibonifac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 22:14:30 by ibonifac          #+#    #+#             */
/*   Updated: 2018/02/06 12:16:13 by ibonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*set_zero_left(int len, int min, char *tmp)
{
	int		i;
	char	*tmp2;

	if (min - len <= 0)
		return (tmp);
	if (!(tmp2 = ft_strnew(min - len)))
		return (NULL);
	i = 0;
	while (min > len)
	{
		tmp2[i] = '0';
		min--;
		i++;
	}
	tmp2[i + 1] = '\0';
	if (!(tmp = ft_strjoin_nfree(tmp2, tmp, 3)))
		return (NULL);
	return (tmp);
}

t_join			*type_c(t_flags *flags, t_join *lst, char c)
{
	char	*tmp;

	if (c == '\0')
	{
		if (flags->field_width)
			flags->field_width -= 1;
		lst->instruct = 42;
	}
	tmp = ft_strnew(1);
	tmp[0] = c;
	lst->str = replace_str(lst->str, tmp, 0);
	lst = type_s(flags, lst, tmp);
	if (tmp)
		free(tmp);
	return (lst);
}

static t_join	*free_nfill(t_join *lst)
{
	if (lst->str)
		free(lst->str);
	lst->str = ft_strdup_nfree("(null)", 0);
	lst->instruct = 43;
	return (lst);
}

t_join			*type_s(t_flags *flags, t_join *lst, char *s)
{
	int		size;

	if (!s)
		lst = free_nfill(lst);
	else
		lst->str = replace_str(lst->str, s, 0);
	size = ft_strlen(lst->str);
	if (flags->precision == PRECISION)
	{
		if (lst->instruct == MODULO && flags->precision_value == 0)
			flags->precision_value = 1;
		size = (size < flags->precision_value ? size : flags->precision_value);
		lst->str = ft_strsub_nfree(lst->str, 0, size, 1);
	}
	if (flags->zero && flags->field_width > size)
	{
		lst->str = set_zero_left(size, flags->field_width,
		lst->str);
	}
	else
		lst->str = space_x_num(flags, lst->str);
	return (lst);
}
