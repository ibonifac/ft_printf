/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibonifac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 22:14:30 by ibonifac          #+#    #+#             */
/*   Updated: 2018/02/06 12:16:13 by ibonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						ft_printf(const char *restrict format, ...)
{
	va_list			arg;
	int				last_return;
	t_join			*lst;
	t_split_tool	tool;

	if (!format)
		return (0);
	tool = init_tool();
	lst = new_lst();
	va_start(arg, format);
	last_return = first_step(format, &tool, lst, arg);
	va_end(arg);
	return (last_return);
}
