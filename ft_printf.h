/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapalmer <dapalmer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 12:49:46 by dapalmer          #+#    #+#             */
/*   Updated: 2019/12/19 15:38:31 by dapalmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef struct	s_flag
{
	int			plen;
	int			tlen;
	int			ptype;
	int			align;
	int			trunc;
}				t_flag;

int				ft_printf(const char *format, ...);
void			ft_get_flags(const char **format, t_flag *flags, va_list arg);
int				ft_get_type(const char **format, va_list arg, t_flag *flags);

int				ft_putchar(const char c);
int				ft_putchar_c(t_flag *flags, va_list arg);
int				ft_putchar_esc(t_flag *flags, char arg);
int				ft_putstr_c(char *s, t_flag *flags);
int				ft_putstr_s(char *s, int tlen);
int				ft_putstr_n(char *s, t_flag *flags);
int				ft_putstr_ptr(char *s, t_flag *flags);

int				ft_putpad(int i, int type);
char			*ft_strtoupper(char *s);
char			*ft_ulltoa(unsigned long long nb, const unsigned base);

#endif
