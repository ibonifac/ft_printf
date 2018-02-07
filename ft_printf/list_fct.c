/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_fct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibonifac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 22:14:30 by ibonifac          #+#    #+#             */
/*   Updated: 2018/02/06 12:16:13 by ibonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_join					*new_lst(void)
{
	t_join		*elem;

	if (!(elem = (t_join*)malloc(sizeof(t_join))))
		return (NULL);
	elem->str = 0;
	elem->size = 0;
	elem->instruct = 0;
	elem->next = 0;
	return (elem);
}

static void				make_the_list_continue(const char *format,
						t_split_tool *tool, t_join *lst)
{
	lst->str = ft_strsub(format, tool->start, tool->len);
	lst->size = ft_strlen(lst->str);
}

void					make_the_list(const char *format, t_split_tool *tool,
						t_join *lst)
{
	if (!lst->str)
		make_the_list_continue(format, tool, lst);
	else
	{
		while (lst->next)
			lst = lst->next;
		lst->next = new_lst();
		lst = lst->next;
		make_the_list_continue(format, tool, lst);
	}
}
