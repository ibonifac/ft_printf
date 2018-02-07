/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibonifac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 22:14:30 by ibonifac          #+#    #+#             */
/*   Updated: 2018/02/06 12:16:13 by ibonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	set_sign(t_flags *flags, intmax_t nb)
{
	if (nb < 0 && (nb *= -1))
	{
		flags->sign = ft_strnew(1);
		flags->sign[0] = '-';
		return (nb);
	}
	else if (flags->plus)
	{
		flags->sign = ft_strnew(1);
		flags->sign[0] = '+';
		return (nb);
	}
	else if (flags->space)
	{
		flags->sign = ft_strnew(1);
		flags->sign[0] = ' ';
		return (nb);
	}
	return (nb);
}

t_join		*type_dui(t_flags *flags, uintmax_t num, t_join *lst)
{
	char	*tmp;
	int		len;

	if (lst->instruct != U && lst->instruct != U_CAP)
		num = set_sign(flags, num);
	tmp = ft_itoa_base(num, 10);
	len = ft_strlen(tmp);
	if (tmp[0] == '0' && flags->precision == PRECISION &&
		flags->precision_value == 0)
		tmp[0] = '\0';
	if (flags->precision && flags->precision_value > len)
		tmp = set_zero_left(len, flags->precision_value, tmp);
	if (flags->zero && flags->field_width > len && !flags->precision
			&& !flags->minus)
	{
		if (flags->sign)
			flags->field_width -= 1;
		tmp = set_zero_left(len, (flags->field_width),
		tmp);
	}
	if (flags->sign && lst->instruct != U)
		tmp = ft_strjoin_nfree(flags->sign, tmp, 3);
	tmp = space_x_num(flags, tmp);
	lst->str = replace_str(lst->str, tmp, 2);
	return (lst);
}

t_join		*type_o(t_flags *flags, uintmax_t num, t_join *lst)
{
	char	*tmp;
	int		len;

	if (!(tmp = ft_itoa_base(num, 8)))
		return (NULL);
	len = ft_strlen(tmp);
	if (tmp[0] == '0' && flags->precision && flags->precision_value == 0)
		tmp[0] = '\0';
	if (flags->sharp && tmp[0] != '0')
	{
		tmp = ft_strjoin_nfree("0", tmp, 2);
		len++;
	}
	if (flags->precision_value > len)
		tmp = set_zero_left(len, flags->precision_value, tmp);
	if (flags->zero && flags->field_width > len && !flags->precision
			&& !flags->minus)
		tmp = set_zero_left(len, flags->field_width, tmp);
	tmp = space_x_num(flags, tmp);
	lst->str = replace_str(lst->str, tmp, 2);
	return (lst);
}

t_join		*type_xp(t_flags *flags, uintmax_t num, t_join *lst)
{
	char	*tmp;
	int		len;

	tmp = ft_itoa_base(num, 16);
	len = ft_strlen(tmp);
	if (tmp[0] == '0' && flags->precision && flags->precision_value == 0)
		tmp[0] = '\0';
	if (flags->precision_value > len)
		if (!(tmp = set_zero_left(len, flags->precision_value, tmp)))
			return (NULL);
	while (flags->zero && flags->field_width > len && !flags->precision
			&& !flags->minus)
	{
		if (((flags->sharp && num > 0) || lst->instruct == P) &&
			flags->field_width == len + 2)
			break ;
		tmp = ft_strjoin_nfree("0", tmp, 2);
		len++;
	}
	if ((flags->sharp && num > 0) || lst->instruct == P)
		tmp = ft_strjoin_nfree("0x", tmp, 2);
	tmp = space_x_num(flags, tmp);
	lst->str = replace_str(lst->str, tmp, 2);
	return (lst);
}

t_join		*type_x_cap(t_flags *flags, uintmax_t num, t_join *lst)
{
	char	*tmp;
	int		len;

	tmp = ft_itoa_base(num, 16);
	len = ft_strlen(tmp);
	if (tmp[0] == '0' && flags->precision && flags->precision_value == 0)
		tmp[0] = '\0';
	tmp = ft_strupcase(tmp);
	if (flags->precision_value > len)
		tmp = set_zero_left(len, flags->precision_value, tmp);
	while (flags->zero && flags->field_width > len && !flags->precision
			&& !flags->minus)
	{
		if (((flags->sharp && num > 0) || lst->instruct == P) &&
			flags->field_width == len + 2)
			break ;
		tmp = ft_strjoin_nfree("0", tmp, 2);
		len++;
	}
	if ((flags->sharp && num > 0) || lst->instruct == P)
		tmp = ft_strjoin_nfree("0X", tmp, 2);
	tmp = space_x_num(flags, tmp);
	lst->str = replace_str(lst->str, tmp, 2);
	return (lst);
}
