/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibonifac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 22:14:30 by ibonifac          #+#    #+#             */
/*   Updated: 2018/02/06 12:16:13 by ibonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			check_flags(t_join *lst, t_flags *flags, t_split_tool *tool)
{
	while (ft_strchr("#0+- ", lst->str[tool->i]))
	{
		if (lst->str[tool->i] == '#')
			flags->sharp = SHARP;
		else if (lst->str[tool->i] == '0')
			flags->zero = F_ZERO;
		else if (lst->str[tool->i] == '+')
			flags->plus = PLUS;
		else if (lst->str[tool->i] == '-')
			flags->minus = MINUS;
		else if (lst->str[tool->i] == ' ')
			flags->space = SPACE;
		tool->i++;
	}
	if (flags->minus != 0)
		flags->zero = NOTHING;
	else if (flags->plus != 0)
		flags->space = NOTHING;
}

static short		check_field_width(t_join *lst, t_flags *flags,
				t_split_tool *tool)
{
	if (ft_isdigit(lst->str[tool->i]) && lst->str[tool->i] != 0)
	{
		flags->field_width = ft_atoi(lst->str + tool->i);
		return (1);
	}
	return (0);
}

static short		check_precision(t_join *lst, t_flags *flags,
					t_split_tool *tool)
{
	if (lst->str[tool->i] == '.' && (ft_isdigit(lst->str[tool->i + 1]) == 1 ||
		lst->str[tool->i + 1] != 0))
	{
		tool->i++;
		flags->precision_value = ft_atoi(lst->str + tool->i);
		flags->precision = PRECISION;
		return (1);
	}
	return (0);
}

static int			check_length(t_join *lst, t_flags *flags,
					t_split_tool *tool)
{
	if (lst->str[tool->i] == 'h')
	{
		if ((lst->str[tool->i + 1]) == 'h')
		{
			tool->i++;
			flags->length_modif = HH;
		}
		else
			flags->length_modif = H;
	}
	else if (lst->str[tool->i] == 'l')
	{
		if ((lst->str[tool->i + 1]) == 'l')
		{
			tool->i++;
			return (flags->length_modif = LL);
		}
		return (flags->length_modif = L);
	}
	else if (lst->str[tool->i] == 'j')
		return (flags->length_modif = J);
	else if (lst->str[tool->i] == 'z')
		return (flags->length_modif = Z);
	return (NOTHING);
}

t_flags				*check_all_flags(t_join *lst, t_split_tool *tool,
					t_flags *flags)
{
	while (lst->str[tool->i] && (is_instruct(lst->str[tool->i]) == 0))
	{
		check_flags(lst, flags, tool);
		if (flags->field_width == 0)
		{
			if (check_field_width(lst, flags, tool) == 1)
			{
				while (ft_isdigit(lst->str[tool->i]))
					tool->i++;
			}
		}
		if (flags->precision_value == 0)
		{
			if (check_precision(lst, flags, tool) == 1)
			{
				flags->precision = PRECISION;
				while (ft_isdigit(lst->str[tool->i] == 1))
					tool->i++;
			}
		}
		check_length(lst, flags, tool);
		tool->i++;
	}
	return (flags);
}
