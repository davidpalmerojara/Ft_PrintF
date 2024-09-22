/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapalmer <dapalmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 12:43:44 by dapalmer          #+#    #+#             */
/*   Updated: 2019/12/19 15:35:17 by dapalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "limits.h"

void		ft_reset_struct(t_flag *flags)
{
	flags->align = 0;
	flags->plen = 0;
	flags->ptype = -1;
	flags->tlen = -1;
	flags->trunc = 0;
}

int			ft_get_format(const char *format, va_list arg)
{
	t_flag	flags;
	int		count;

	count = 0;
	ft_reset_struct(&flags);
	while (format && *format)
	{
		if (*format == '%')
		{
			format++;
			ft_get_flags(&format, &flags, arg);
			count = count + ft_get_type(&format, arg, &flags);
		}
		else
			count += ft_putchar(*format);
		if (!*format++)
			break ;
		ft_reset_struct(&flags);
	}
	return (count);
}

int			ft_printf(const char *format, ...)
{
	va_list	arg;
	int		done;

	va_start(arg, format);
	done = ft_get_format(format, arg);
	va_end(arg);
	return (done);
}
