/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibonifac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 22:14:30 by ibonifac          #+#    #+#             */
/*   Updated: 2018/02/06 12:16:13 by ibonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

short				is_instruct(int c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' || c == 'i' ||
		c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x' || c == 'X' ||
		c == 'c' || c == 'C')
		return (1);
	if (c == '%')
		return (2);
	return (0);
}

static int			caps_modif(t_join *lst, t_flags *flags)
{
	if (lst->instruct == C_CAP || lst->instruct == S_CAP || lst->instruct ==
		D_CAP || lst->instruct == O_CAP || lst->instruct == U_CAP ||
		lst->instruct == P)
		return (flags->length_modif = L);
	return (0);
}

static int			check_instruct_caps(t_join *lst, t_split_tool *tool)
{
	if (lst->str[tool->i] == 'C')
		return (lst->instruct = C_CAP);
	else if (lst->str[tool->i] == 'S')
		return (lst->instruct = S_CAP);
	else if (lst->str[tool->i] == 'D')
		return (lst->instruct = D_CAP);
	else if (lst->str[tool->i] == 'O')
		return (lst->instruct = O_CAP);
	else if (lst->str[tool->i] == 'U')
		return (lst->instruct = U_CAP);
	else if (lst->str[tool->i] == 'X')
		return (lst->instruct = X_CAP);
	return (0);
}

static int			check_instruct(t_join *lst, t_split_tool *tool,
		t_flags *flags)
{
	if (lst->str[tool->i] == 's')
		return (lst->instruct = S);
	else if (lst->str[tool->i] == 'p')
		return (lst->instruct = P);
	else if (lst->str[tool->i] == 'd')
		return (lst->instruct = D);
	else if (lst->str[tool->i] == 'i')
		return (lst->instruct = I);
	else if (lst->str[tool->i] == 'o')
		return (lst->instruct = O);
	else if (lst->str[tool->i] == 'u')
		return (lst->instruct = U);
	else if (lst->str[tool->i] == 'x')
		return (lst->instruct = X);
	else if (lst->str[tool->i] == 'c')
		return (lst->instruct = C);
	else if (lst->str[tool->i] == '%')
		return (lst->instruct = MODULO);
	else if (is_escapable(lst->str[tool->i]) == -1)
	{
		if (flags->precision && flags->precision_value == 0)
			flags->precision_value = 1;
		return (lst->instruct = lst->str[tool->i]);
	}
	return (0);
}

t_join				*make_the_conv_begin(t_join *lst, t_split_tool *tool,
					t_flags *flags, va_list arg)
{
	check_all_flags(lst, tool, flags);
	tool->i = ft_strlen(lst->str) - 1;
	if (!(check_instruct(lst, tool, flags)) || lst->instruct == P)
	{
		check_instruct_caps(lst, tool);
		caps_modif(lst, flags);
	}
	return (conv_set(lst, flags, arg));
}
