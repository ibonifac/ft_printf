/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fct_wchars.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibonifac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 22:14:30 by ibonifac          #+#    #+#             */
/*   Updated: 2018/02/06 12:16:13 by ibonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	wstrlen(wchar_t *ws)
{
	wchar_t		*tmp;

	tmp = ws;
	while (*tmp != L'\0')
		tmp++;
	return (tmp - ws);
}

static int		count_wchars(t_flags *flags, t_join *lst, wchar_t *wstr,
					int *size)
{
	int		i;
	int		add;
	int		total;

	i = 0;
	add = 0;
	total = 0;
	while (i < *size)
	{
		if (wstr[i] <= 0x7F)
			add = 1;
		if (wstr[i] <= 0x7FF)
			add = 2;
		if (wstr[i] <= 0xFFFF)
			add = 3;
		if (wstr[i] <= 0x10FFFF)
			add = 4;
		total += add;
		if (flags->precision == PRECISION && (lst->instruct == S_CAP ||
			lst->instruct == S) && total == flags->precision_value)
			break ;
		i++;
	}
	*size = i;
	return (total);
}

t_join			*type_ws(t_flags *flags, t_join *lst, wchar_t *ws, int size)
{
	int		i;
	int		total;

	i = 0;
	if (lst->str)
		free(lst->str);
	total = count_wchars(flags, lst, ws, &size);
	lst->str = ft_strnew(1);
	while (i < size)
	{
		check_wchar(lst, ws[i]);
		i++;
	}
	i = ft_strlen(lst->str);
	if (flags->precision == PRECISION)
	{
		i = (i < flags->precision_value ?
				i : flags->precision_value);
		lst->str = ft_strsub_nfree(lst->str, 0, i, 1);
	}
	if (flags->zero && flags->field_width > i)
		lst->str = set_zero_left(i, flags->field_width, lst->str);
	else
		lst->str = space_x_num(flags, lst->str);
	return (lst);
}

t_join			*type_wc(t_flags *flags, t_join *lst, wint_t wc)
{
	wchar_t		wchar;

	if (!wc)
		lst->instruct = 42;
	if (wc < 0)
		o_len(0, -1);
	wchar = (wchar_t)wc;
	type_ws(flags, lst, &wchar, 1);
	return (lst);
}

t_join			*print_wstr(t_flags *flags, t_join *lst, wchar_t *wstr)
{
	if (!wstr)
		type_s(flags, lst, NULL);
	else
		type_ws(flags, lst, wstr, wstrlen(wstr));
	return (lst);
}
