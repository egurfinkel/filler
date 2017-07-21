/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egurfink <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 21:56:42 by egurfink          #+#    #+#             */
/*   Updated: 2017/04/13 21:56:44 by egurfink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			call_pointer(t_spc *spc, va_list v_lst, int *count)
{
	spc->f[1]
	? to_pointer_minus(spc, v_lst, count)
	: to_pointer(spc, v_lst, count);
}

void			to_pointer(t_spc *a, va_list v_lst, int *count)
{
	uintmax_t	p;
	char		*s;

	p = va_arg(v_lst, unsigned long);
	(p == 0 && a->prc == 0)
	? (s = "")
	: (s = ft_itoa_base_u(p, w_base(a)));
	(a->wd < a->prc) ? a->wd = 0 : 0;
	if (a->wd >= a->prc && a->prc > ft_countnum(p))
		a->wd -= a->prc;
	else
		a->wd -= (ft_strlen(s));
	(((size_t)a->prc > ft_strlen(s)) && (a->prc != -1))
	? (a->prc -= ft_strlen(s)) : (a->prc = 0);
	(*count) += 2;
	a->wd -= 2;
	while (!a->f[0] && a->wd-- > 0 && ++(*count))
		ft_putchar(' ');
	while (a->f[0] && a->wd-- > 0 && ++(*count))
		ft_putchar('0');
	ft_putstr("0x");
	while (a->prc-- > 0 && ++(*count))
		ft_putchar('0');
	while (s[a->x] && ++(*count))
		ft_putchar((char)ft_tolower((s[a->x++])));
}

void			to_pointer_minus(t_spc *a, va_list v_lst, int *count)
{
	uintmax_t	p;
	char		*s;

	p = va_arg(v_lst, unsigned long);
	if (a->wd < a->prc)
		a->wd = 0;
	(p == 0 && a->prc == 0)
	? (s = "")
	: (s = ft_itoa_base_u(p, w_base(a)));
	if (a->wd >= a->prc && a->prc > ft_countnum(p))
		a->wd -= a->prc;
	else
		a->wd -= (ft_strlen(s));
	(((size_t)a->prc > ft_strlen(s)) && (a->prc != -1))
	? (a->prc -= ft_strlen(s)) : (a->prc = 0);
	p = 0;
	ft_putstr("0x");
	while (a->prc-- > 0 && ++(*count))
		ft_putchar('0');
	(*count) += 2;
	a->wd -= 2;
	while (s[p] && ++(*count))
		ft_putchar((char)ft_tolower(s[p++]));
	while (a->wd-- > 0 && ++(*count))
		ft_putchar(' ');
}

void			to_percent(t_spc *a, va_list v_lst, int *count)
{
	to_char(a, v_lst, count, 0);
}
