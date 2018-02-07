/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_button.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibonifac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 22:14:30 by ibonifac          #+#    #+#             */
/*   Updated: 2018/02/06 12:16:13 by ibonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags					init_flags(void)
{
	t_flags		tmp;

	tmp.length_modif = 0;
	tmp.sharp = 0;
	tmp.zero = 0;
	tmp.plus = 0;
	tmp.minus = 0;
	tmp.space = 0;
	tmp.field_width = 0;
	tmp.precision = 0;
	tmp.precision_value = 0;
	tmp.length = 0;
	tmp.sign = NULL;
	return (tmp);
}

t_split_tool			init_tool(void)
{
	t_split_tool tmp;

	tmp.i = 0;
	tmp.start = 0;
	tmp.len = 0;
	return (tmp);
}

char					*replace_str(char *dst, char *src, int option)
{
	int			i;

	i = 0;
	if (dst)
		free(dst);
	dst = ft_strnew(ft_strlen(src));
	dst = ft_memmove(dst, src, ft_strlen(src));
	if (option != 0)
	{
		if (option == 1 || option == 3)
			if (dst)
				free(dst);
		if (option == 2 || option == 3)
			if (src)
				free(src);
	}
	return (dst);
}

void					free_the_lst(t_join *lst)
{
	t_join		*tmp;

	tmp = lst;
	while (tmp && lst)
	{
		tmp = lst->next;
		if (lst && lst->str)
			free(lst->str);
		if (lst)
			free(lst);
		lst = tmp;
	}
}
