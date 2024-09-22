/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapalmer <dapalmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 14:51:53 by dapalmer          #+#    #+#             */
/*   Updated: 2019/12/18 16:44:27 by dapalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putstr_s(char *s, int tlen)
{
	int count;

	count = 0;
	if (!s)
		return (0);
	if (tlen >= 0)
		while (*s && tlen > 0)
		{
			count++;
			ft_putchar(*s++);
			tlen--;
		}
	else
		while (*s)
		{
			count++;
			ft_putchar(*s++);
		}
	return (count);
}

int		ft_putstr_right_null(char *s, t_flag *flags)
{
	int count;

	count = 0;
	if (flags->tlen >= 0)
		count += ft_putstr_s(s, flags->tlen);
	else
		count += ft_putstr_s(s, flags->tlen);
	if (flags->tlen < 0)
		count += ft_putpad(flags->plen -= 6, flags->ptype);
	if (flags->tlen == 0)
		count += ft_putpad(flags->plen, flags->ptype);
	if (flags->tlen > 0)
	{
		if (flags->tlen > 6)
			count += ft_putpad(flags->plen -= 6, flags->ptype);
		if (flags->tlen <= 6)
			count += ft_putpad(flags->plen - flags->tlen, flags->ptype);
	}
	return (count);
}

int		ft_putstr_left_null(char *s, t_flag *flags)
{
	int count;

	count = 0;
	if (flags->tlen < 0)
		count += ft_putpad(flags->plen -= 6, flags->ptype);
	if (flags->tlen == 0)
		count += ft_putpad(flags->plen, flags->ptype);
	if (flags->tlen > 0)
	{
		if (flags->tlen > 6)
			count += ft_putpad(flags->plen -= 6, flags->ptype);
		if (flags->tlen <= 6)
			count += ft_putpad(flags->plen - flags->tlen, flags->ptype);
	}
	if (flags->tlen >= 0)
		count += ft_putstr_s(s, flags->tlen);
	else
		count += ft_putstr_s(s, flags->tlen);
	return (count);
}

void	ft_pad_len(t_flag *flags, size_t len)
{
	if (flags->tlen > 0 && flags->tlen < (int)len)
		flags->plen -= flags->tlen;
	else if (flags->tlen == 0)
		;
	else
		flags->plen -= len;
}

int		ft_putstr_c(char *s, t_flag *flags)
{
	int count;

	count = 0;
	if (flags->trunc == 1 && flags->plen == 0 && flags->tlen == 0)
		return (0);
	if (s == NULL)
	{
		if (flags->align == 0)
			return (ft_putstr_left_null("(null)", flags));
		if (flags->align == 1)
			return (ft_putstr_right_null("(null)", flags));
	}
	ft_pad_len(flags, ft_strlen(s));
	if (flags->align == 0)
		count += ft_putpad(flags->plen, flags->ptype);
	if (flags->tlen >= 0)
		count += ft_putstr_s(s, flags->tlen);
	else
		count += ft_putstr_s(s, flags->tlen);
	if (flags->align == 1)
		count += ft_putpad(flags->plen, 1);
	return (count);
}
