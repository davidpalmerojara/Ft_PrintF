/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_types.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapalmer <dapalmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 13:09:36 by dapalmer          #+#    #+#             */
/*   Updated: 2019/12/20 16:10:37 by dapalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_type_int(va_list arg, t_flag *flags, char format)
{
	char	*string;
	int		count;

	count = 0;
	if (format == 'u')
		string = ft_ulltoa(va_arg(arg, unsigned int), 10);
	else
		string = ft_itoa(va_arg(arg, int));
	count += ft_putstr_n(string, flags);
	free(string);
	return (count);
}

int			ft_type_hex(va_list arg, t_flag *flags, char format)
{
	char	*string;
	int		count;

	count = 0;
	string = ft_ulltoa(va_arg(arg, unsigned int), 16);
	if (format == 'X')
		ft_strtoupper(string);
	count += ft_putstr_n(string, flags);
	free(string);
	return (count);
}

int			ft_type_ptr(va_list arg, t_flag *flags)
{
	char	*str;
	int		count;

	count = 0;
	str = ft_strjoin("0x", ft_ulltoa(va_arg(arg, long long unsigned int), 16));
	count += ft_putstr_ptr(str, flags);
	free(str);
	return (count);
}

int			ft_get_type(const char **format, va_list arg, t_flag *flags)
{
	if (**format == '%')
		return (ft_putchar_esc(flags, '%'));
	if (**format == 'c')
		return (ft_putchar_c(flags, arg));
	if (**format == 's')
		return (ft_putstr_c(va_arg(arg, char *), flags));
	if (**format == 'd' || **format == 'i' || **format == 'u')
		return (ft_type_int(arg, flags, **format));
	if (**format == 'p')
		return (ft_type_ptr(arg, flags));
	if (**format == 'x' || **format == 'X')
		return (ft_type_hex(arg, flags, **format));
	format++;
	return (0);
}
