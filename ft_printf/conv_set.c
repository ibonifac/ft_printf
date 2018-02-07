/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibonifac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 22:14:30 by ibonifac          #+#    #+#             */
/*   Updated: 2018/02/06 12:16:13 by ibonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*print_num(t_join *lst, t_flags *flags, va_list arg)
{
	intmax_t	num;

	if (lst->instruct == D || lst->instruct == D_CAP || lst->instruct == I)
		num = set_signed(flags, arg);
	else
		num = set_unsigned(flags, arg);
	if (lst->instruct == D || lst->instruct == U || lst->instruct == I ||
		lst->instruct == D_CAP || lst->instruct == U_CAP)
		type_dui(flags, (uintmax_t)num, lst);
	else if (lst->instruct == O || lst->instruct == O_CAP)
		type_o(flags, (uintmax_t)num, lst);
	else if (lst->instruct == X || lst->instruct == P)
		type_xp(flags, (uintmax_t)num, lst);
	else if (lst->instruct == X_CAP)
		type_x_cap(flags, (uintmax_t)num, lst);
	return (lst->str);
}

static char		*print_chars(t_join *lst, t_flags *flags, va_list arg)
{
	if (flags->length_modif == L)
	{
		if (lst->instruct == C || lst->instruct == C_CAP)
			lst = type_wc(flags, lst, va_arg(arg, wint_t));
		else if (lst->instruct == S || lst->instruct == S_CAP)
			lst = print_wstr(flags, lst, va_arg(arg, wchar_t*));
	}
	else
	{
		if (is_escapable(lst->instruct) == -1)
			lst = type_c(flags, lst, lst->instruct);
		if (lst->instruct == MODULO)
			lst = type_c(flags, lst, '%');
		else if (lst->instruct == C)
			lst = type_c(flags, lst, va_arg(arg, int));
		else if (lst->instruct == S)
			lst = type_s(flags, lst, va_arg(arg, char*));
	}
	return (lst->str);
}

t_join			*conv_set(t_join *lst, t_flags *flags, va_list arg)
{
	if (lst->instruct == D || lst->instruct == O || lst->instruct == U ||
		lst->instruct == X || lst->instruct == P || lst->instruct == D_CAP ||
		lst->instruct == O_CAP || lst->instruct == U_CAP ||
		lst->instruct == X_CAP || lst->instruct == I)
		print_num(lst, flags, arg);
	else if (lst->instruct == C || lst->instruct == S || lst->instruct ==
			C_CAP || lst->instruct == S_CAP || lst->instruct == MODULO ||
			is_escapable(lst->instruct) == -1)
		print_chars(lst, flags, arg);
	return (lst);
}
