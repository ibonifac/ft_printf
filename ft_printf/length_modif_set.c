/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_modif_set.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibonifac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 22:14:30 by ibonifac          #+#    #+#             */
/*   Updated: 2018/02/06 12:16:13 by ibonifac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	set_signed(t_flags *flags, va_list arg)
{
	if (flags->length_modif == HH)
		return ((char)va_arg(arg, int));
	if (flags->length_modif == H)
		return ((short)va_arg(arg, int));
	if (flags->length_modif == L)
		return (va_arg(arg, long));
	if (flags->length_modif == LL)
		return (va_arg(arg, long long));
	if (flags->length_modif == J)
		return (va_arg(arg, intmax_t));
	if (flags->length_modif == Z)
		return (va_arg(arg, ssize_t));
	return (va_arg(arg, int));
}

uintmax_t	set_unsigned(t_flags *flags, va_list arg)
{
	if (flags->length_modif == HH)
		return ((unsigned char)va_arg(arg, unsigned int));
	if (flags->length_modif == H)
		return ((unsigned short)va_arg(arg, unsigned int));
	if (flags->length_modif == L)
		return (va_arg(arg, unsigned long));
	if (flags->length_modif == LL)
		return (va_arg(arg, uintmax_t));
	if (flags->length_modif == J)
		return (va_arg(arg, uintmax_t));
	if (flags->length_modif == Z)
		return (va_arg(arg, size_t));
	return (va_arg(arg, unsigned int));
}
