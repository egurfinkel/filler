/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uu.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egurfink <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 21:56:51 by egurfink          #+#    #+#             */
/*   Updated: 2017/04/13 21:56:52 by egurfink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	w_base(t_spc *a)
{
	if (a->type == 'o' || a->type == 'O')
		return (8);
	if (a->type == 'x' || a->type == 'X' || a->type == 'p')
		return (16);
	else
		return (10);
}

void			call_uint(t_spc *spc, va_list v_lst, int *count)
{
	if (spc->type == 'U')
	{
		spc->type = 'u';
		spc->ln = 3;
	}
	spc->f[1]
	? to_uint_minus(spc, v_lst, count)
	: to_uint(spc, v_lst, count);
}

uintmax_t		get_uint(int len, va_list v_lst)
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

void			to_uint(t_spc *a, va_list v_lst, int *count)
{
	uintmax_t		ui;
	char			*s;
	char			symb;

	ui = get_uint(a->ln, v_lst);
	(ui == 0 && a->prc == 0)
	? (s = "")
	: (s = ft_itoa_base_u(ui, w_base(a)));
	(a->f[0])
	? (symb = '0')
	: (symb = ' ');
	if (a->wd < a->prc)
		a->wd = 0;
	if (a->wd >= a->prc && a->prc > ft_countnum(ui))
		a->wd -= a->prc;
	else
		a->wd -= (ft_strlen(s));
	(((size_t)a->prc > ft_strlen(s)) && (a->prc != -1))
	? (a->prc -= ft_strlen(s)) : (a->prc = 0);
	while (a->wd-- > 0 && ++(*count))
		ft_putchar(symb);
	while (a->prc-- > 0 && ++(*count))
		ft_putchar('0');
	while (s[a->x] && ++(*count))
		ft_putchar(s[a->x++]);
}

void			to_uint_minus(t_spc *a, va_list v_lst, int *count)
{
	uintmax_t	ui;
	char		*s;

	ui = get_uint(a->ln, v_lst);
	if (a->wd < a->prc)
		a->wd = 0;
	(ui == 0 && a->prc == 0)
	? (s = "")
	: (s = ft_itoa_base_u(ui, w_base(a)));
	if (a->wd >= a->prc && a->prc > ft_countnum(ui))
		a->wd -= a->prc;
	else
		a->wd -= ft_strlen(s);
	((size_t)a->prc > ft_strlen(s))
	? (a->prc -= ft_strlen(s)) : (a->prc = 0);
	ui = 0;
	while (a->prc-- > 0 && ++(*count))
		ft_putchar('0');
	while (s[ui] && ++(*count))
		ft_putchar(s[ui++]);
	while (a->wd-- > 0 && ++(*count))
		ft_putchar(' ');
}
