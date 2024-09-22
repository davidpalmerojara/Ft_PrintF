/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapalmer <dapalmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 09:58:27 by dapalmer          #+#    #+#             */
/*   Updated: 2019/12/18 14:00:27 by dapalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putint_pos(char *s, t_flag *flg, int c)
{
	if (flg->align == 1)
	{
		if (flg->trunc == 1)
			c += ft_putpad(flg->tlen - (int)ft_strlen(s), 0);
		c += ft_putstr_s(s, -1);
		if (flg->tlen > (int)ft_strlen(s))
			return (c += ft_putpad(flg->plen - flg->tlen, flg->ptype));
		return (c += ft_putpad(flg->plen - (int)ft_strlen(s), flg->ptype));
	}
	else
	{
		if (flg->tlen > (int)ft_strlen(s))
			c += ft_putpad(flg->plen - flg->tlen, 1);
		else
			c += ft_putpad(flg->plen - (int)ft_strlen(s), flg->ptype);
		if (flg->trunc == 1)
			c += ft_putpad(flg->tlen - (int)ft_strlen(s), 0);
		return (c += ft_putstr_s(s, -1));
	}
}

int		ft_putint_neg(char *s, t_flag *flg, int c)
{
	if (flg->align == 1)
	{
		ft_putchar('-');
		if (flg->trunc == 1)
			c += ft_putpad(flg->tlen - (int)ft_strlen(s + 1), 0);
		c += ft_putstr_s(s + 1, -1);
		if (flg->tlen > (int)ft_strlen(s + 1))
			return (c += ft_putpad(flg->plen - flg->tlen - 1, flg->ptype));
		return (c += ft_putpad(flg->plen - ft_strlen(s + 1) - 1, flg->ptype));
	}
	else
	{
		if (!flg->ptype)
			ft_putchar('-');
		if (flg->tlen > (int)ft_strlen(s + 1))
			c += ft_putpad(flg->plen - flg->tlen - 1, flg->ptype);
		else
			c += ft_putpad(flg->plen - (int)ft_strlen(s + 1) - 1, flg->ptype);
		if (flg->ptype)
			ft_putchar('-');
		if (flg->trunc == 1)
			c += ft_putpad(flg->tlen - (int)ft_strlen(s + 1), 0);
		return (c += ft_putstr_s(s + 1, -1));
	}
}

int		ft_putstr_n(char *s, t_flag *flg)
{
	int c;

	c = 0;
	if (flg->trunc == 1 && flg->tlen == 0 && flg->plen == 0)
		return (0);
	if (flg->trunc == 1 && flg->tlen == 0)
		return (c += ft_putpad(flg->plen, flg->ptype));
	if (*s == '-')
		c += ft_putint_neg(s, flg, c) + 1;
	else
		c += ft_putint_pos(s, flg, c);
	return (c);
}
