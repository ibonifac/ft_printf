/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_by_step.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibonifac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 22:14:30 by ibonifac          #+#    #+#             */
/*   Updated: 2018/02/06 12:16:13 by ibonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void				second_step(t_join *lst, va_list arg,
						t_split_tool *tool)
{
	t_flags		flags;

	while (lst)
	{
		flags = init_flags();
		tool->i = 0;
		if (lst->instruct == 1 || lst->instruct == 2)
			make_the_conv_begin(lst, tool, &flags, arg);
		lst = lst->next;
	}
}

static uintmax_t		third_step(t_join *lst)
{
	uintmax_t		last_result;
	int				size;

	last_result = 0;
	while (lst)
	{
		size = ft_strlen(lst->str);
		if (lst->instruct == 42)
			size += 1;
		write(1, lst->str, size);
		last_result += size;
		lst = lst->next;
	}
	return (last_result);
}

int						first_step(const char *format, t_split_tool *tool,
						t_join *lst, va_list arg)
{
	intmax_t			last_result;

	if (!format[tool->i] || ft_strcmp(format, "%") == 0)
		return (0);
	while (format[tool->i])
		sort_str(format, tool, lst);
	second_step(lst, arg, tool);
	last_result = third_step(lst);
	if (lst)
		free_the_lst(lst);
	return (last_result);
}
