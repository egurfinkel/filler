/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egurfink <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 21:56:33 by egurfink          #+#    #+#             */
/*   Updated: 2017/04/13 21:56:36 by egurfink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t		get_octal(int len, va_list v_lst)
{
	if (len == 1)
		return (unsigned char)(va_arg(v_lst, unsigned int));
	else if (len == 2)
		return (unsigned short)(va_arg(v_lst, unsigned int));
	else if (len == 3)
		return (va_arg(v_lst, unsigned long));
	else if (len == 4)
		return (va_arg(v_lst, unsigned long long int));
	else if (len == 5)
		return (va_arg(v_lst, size_t));
	else if (len == 6)
		return (va_arg(v_lst, uintmax_t));
	else
		return (va_arg(v_lst, unsigned int));
}

void			call_octal(t_spc *spc, va_list v_lst, int *count)
{
	if (spc->type == 'O')
	{
		spc->type = 'o';
		spc->ln = 3;
	}
	spc->f[1]
	? to_octal_minus(spc, v_lst, count)
	: to_octal(spc, v_lst, count);
}

void			to_octal(t_spc *a, va_list v_lst, int *count)
{
	uintmax_t	o;
	char		*s;

	o = get_octal(a->ln, v_lst);
	(o > 0 && a->f[3] && a->prc--) ? (a->wd--) : 0;
	if (a->wd < a->prc)
		a->wd = 0;
	(s = ft_itoa_base_u(o, w_base(a)));
	(o == 0 && a->prc == 0) ? s = "" : 0;
	(o == 0 && a->f[3]) ? s = "0" : 0;
	if (a->wd >= a->prc && a->prc > ft_countnum(o))
		a->wd -= a->prc;
	else
		a->wd -= (ft_strlen(s));
	(((size_t)a->prc > ft_strlen(s)) && (a->prc != -1))
	? (a->prc -= ft_strlen(s)) : (a->prc = 0);
	while (!a->f[0] && a->wd-- > 0 && ++(*count))
		ft_putchar(' ');
	while (a->f[0] && a->wd-- > 0 && ++(*count))
		ft_putchar('0');
	while (a->prc-- > 0 && ++(*count))
		ft_putchar('0');
	(o > 0 && a->f[3] && ++(*count)) ? ft_putchar('0') : 0;
	while (s[a->x] && ++(*count))
		ft_putchar(s[a->x++]);
}

void			to_octal_minus(t_spc *a, va_list v_lst, int *count)
{
	uintmax_t	o;
	char		*s;

	o = get_octal(a->ln, v_lst);
	if (a->wd < a->prc)
		a->wd = 0;
	(o == 0 && a->prc == 0)
	? (s = "")
	: (s = ft_itoa_base_u(o, w_base(a)));
	(o == 0 && a->f[3] && ++(*count)) ? s = "0" : 0;
	(a->f[3]) ? a->wd-- : 0;
	if (a->wd >= a->prc && a->prc > ft_countnum(o))
		a->wd -= a->prc;
	else
		a->wd -= (ft_strlen(s));
	(((size_t)a->prc > ft_strlen(s)) && (a->prc != -1))
	? (a->prc -= ft_strlen(s)) : (a->prc = 0);
	(o > 0 && a->f[3] && ++(*count)) ? ft_putchar('0') : 0;
	o = 0;
	while (a->prc-- > 0 && ++(*count))
		ft_putchar('0');
	while (s[o] && ++(*count))
		ft_putchar(s[o++]);
	while (a->wd-- > 0 && ++(*count))
		ft_putchar(' ');
}
