/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapalmer <dapalmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 12:37:00 by dapalmer          #+#    #+#             */
/*   Updated: 2019/12/19 15:34:36 by dapalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putchar(const char c)
{
	write(1, &c, 1);
	return (1);
}

int		ft_putchar_esc(t_flag *flags, char arg)
{
	int count;

	count = 0;
	if (flags->align == 0)
		count = count + ft_putpad(flags->plen - 1, flags->ptype);
	ft_putchar(arg);
	count++;
	if (flags->align == 1)
		count = count + ft_putpad(flags->plen - 1, 1);
	return (count++);
}

int		ft_putchar_c(t_flag *flags, va_list arg)
{
	int count;

	count = 0;
	if (flags->align == 0)
		count = count + ft_putpad(flags->plen - 1, flags->ptype);
	ft_putchar((char)va_arg(arg, int));
	count++;
	if (flags->align == 1)
		count = count + ft_putpad(flags->plen - 1, flags->ptype);
	return (count++);
}
