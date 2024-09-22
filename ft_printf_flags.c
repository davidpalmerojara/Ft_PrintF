/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapalmer <dapalmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 11:47:40 by dapalmer          #+#    #+#             */
/*   Updated: 2019/12/19 15:36:33 by dapalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_length(long n)
{
	int		len;

	len = 0;
	if (n < 0)
	{
		len = 1;
		n *= -1;
	}
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

void		ft_get_len(t_flag *flags, const char format)
{
	if (flags->trunc == 1)
		flags->tlen = flags->tlen * 10 + (format - '0');
	if (flags->trunc == 1 && flags->ptype == 0)
		flags->ptype = 1;
	if (flags->trunc == 0)
		flags->plen = flags->plen * 10 + (format - '0');
}

void		ft_get_star_big(t_flag *flags, int star)
{
	char	*string;
	int		i;

	i = ft_length(star);
	string = ft_calloc(i, 1);
	while (i--)
	{
		string[i] = star % 10 + '0';
		star /= 10;
	}
	while (string[++i])
		ft_get_len(flags, string[i]);
	free(string);
}

void		ft_get_star(t_flag *flags, int star)
{
	if (star < 0)
	{
		if (flags->trunc == 1)
		{
			flags->tlen = -1;
			flags->trunc = 0;
			return ;
		}
		flags->ptype = 1;
		flags->align = 1;
		flags->trunc = 0;
		star *= -1;
	}
	if (ft_length(star) == 1)
	{
		ft_get_len(flags, star + '0');
		return ;
	}
	ft_get_star_big(flags, star);
}

void		ft_get_flags(const char **format, t_flag *flags, va_list arg)
{
	while (**format == '-' || **format == '.' ||
	(**format >= '0' && **format <= '9') || **format == '*')
	{
		if (**format == '0' && (*(*format - 1) < '0' || *(*format - 1) > '9'))
			flags->ptype = 0;
		if (**format == '*')
			ft_get_star(flags, va_arg(arg, int));
		if (**format == '-')
			flags->align = 1;
		if (**format == '.')
		{
			flags->tlen = 0;
			flags->trunc = 1;
		}
		if ((**format >= '0' && **format <= '9'))
			ft_get_len(flags, **format);
		(*format)++;
	}
}
