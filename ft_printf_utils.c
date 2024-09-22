/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapalmer <dapalmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 18:51:14 by dapalmer          #+#    #+#             */
/*   Updated: 2019/12/18 17:41:05 by dapalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putpad(int i, int type)
{
	int j;

	j = 0;
	if (type == 0)
		while (i-- > 0)
		{
			ft_putchar('0');
			j++;
		}
	else
		while (i-- > 0)
		{
			ft_putchar(' ');
			j++;
		}
	return (j);
}

char	*ft_strtoupper(char *s)
{
	int i;

	i = -1;
	while (s[++i])
		if ((s[i] >= 'a') && (s[i] <= 'z'))
			s[i] -= 32;
	return (s);
}
