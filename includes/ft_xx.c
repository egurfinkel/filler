/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egurfink <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 21:56:26 by egurfink          #+#    #+#             */
/*   Updated: 2017/04/13 21:56:28 by egurfink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t		get_hex(int len, va_list v_lst)
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

void			to_hex(t_spc *a, va_list v_lst, int *count)
{
	uintmax_t	x;
	char		*s;

	x = get_hex(a->ln, v_lst);
	(a->f[3]) ? a->wd -= 2 : 0;
	(x == 0 && a->prc == 0)
	? (s = "")
	: (s = ft_itoa_base_u(x, w_base(a)));
	if (a->wd < a->prc)
		a->wd = 0;
	if (a->wd >= a->prc && a->prc > ft_countnum(x))
		a->wd -= a->prc;
	else
		a->wd -= (ft_strlen(s));
	(((size_t)a->prc > ft_strlen(s)) && (a->prc != -1))
	? (a->prc -= ft_strlen(s)) : (a->prc = 0);
	while (!a->f[0] && a->wd-- > 0 && ++(*count))
		ft_putchar(' ');
	((a->f[3]) && (x > 0) && (*count += 2)) ? (ft_putstr("0x")) : 0;
	while (a->f[0] && !a->f[1] && a->wd-- > 0 && ++(*count))
		ft_putchar('0');
	while (a->prc-- > 0 && ++(*count))
		ft_putchar('0');
	while (s[a->x] && ++(*count))
		ft_putchar((char)ft_tolower((s[a->x++])));
}

void			to_hex_minus(t_spc *a, va_list v_lst, int *count)
{
	uintmax_t	x;
	char		*s;

	x = get_hex(a->ln, v_lst);
	(a->f[3]) ? a->wd -= 2 : 0;
	if (a->wd < a->prc)
		a->wd = 0;
	(x == 0 && a->prc == 0)
	? (s = "")
	: (s = ft_itoa_base_u(x, w_base(a)));
	if (a->wd >= a->prc && a->prc > ft_countnum(x))
		a->wd -= a->prc;
	else
		a->wd -= (ft_strlen(s));
	((a->f[3]) && (x > 0) && (*count += 2)) ? (ft_putstr("0x")) : 0;
	(((size_t)a->prc > ft_strlen(s)) && (a->prc != -1))
	? (a->prc -= ft_strlen(s)) : (a->prc = 0);
	while (a->prc-- > 0 && ++(*count))
		ft_putchar('0');
	while (s[a->x] && ++(*count))
		ft_putchar((char)ft_tolower(s[a->x++]));
	while (a->wd-- > 0 && ++(*count))
		ft_putchar(' ');
}

void			to_hex_big(t_spc *a, va_list v_lst, int *count)
{
	uintmax_t	x;
	char		*s;

	x = get_hex(a->ln, v_lst);
	(x == 0 && a->prc == 0) ? (s = "")
	: (s = ft_itoa_base_u(x, w_base(a)));
	(a->f[3]) ? a->wd -= 2 : 0;
	(a->wd < a->prc) ? a->wd = 0 : 0;
	if (a->wd >= a->prc && a->prc > ft_countnum(x))
		a->wd -= a->prc;
	else
		a->wd -= (ft_strlen(s));
	(((size_t)a->prc > ft_strlen(s)) && (a->prc != -1))
	? (a->prc -= ft_strlen(s)) : (a->prc = 0);
	while (!a->f[0] && a->wd-- > 0 && ++(*count))
		ft_putchar(' ');
	((a->f[3]) && (x > 0) && (*count += 2)) ? (ft_putstr("0X")) : 0;
	while (!a->f[0] && a->wd-- > 0 && ++(*count))
		ft_putchar(' ');
	while (a->f[0] && !a->f[1] && a->wd-- > 0 && ++(*count))
		ft_putchar('0');
	while (a->prc-- > 0 && ++(*count))
		ft_putchar('0');
	while (s[a->x] && ++(*count))
		ft_putchar(s[a->x++]);
}

void			to_hex_big_minus(t_spc *a, va_list v_lst, int *count)
{
	uintmax_t	x;
	char		*s;

	x = get_hex(a->ln, v_lst);
	(a->f[3]) ? a->wd -= 2 : 0;
	if (a->wd < a->prc)
		a->wd = 0;
	(x == 0 && a->prc == 0)
	? (s = "")
	: (s = ft_itoa_base_u(x, w_base(a)));
	if (a->wd >= a->prc && a->prc > ft_countnum(x))
		a->wd -= a->prc;
	else
		a->wd -= (ft_strlen(s));
	((a->f[3]) && (x > 0) && (*count += 2)) ? (ft_putstr("0X")) : 0;
	(((size_t)a->prc > ft_strlen(s)) && (a->prc != -1))
	? (a->prc -= ft_strlen(s)) : (a->prc = 0);
	while (a->prc-- > 0 && ++(*count))
		ft_putchar('0');
	while (s[a->x] && ++(*count))
		ft_putchar(s[a->x++]);
	while (!a->f[0] && a->wd-- > 0 && ++(*count))
		ft_putchar(' ');
	while (a->f[0] && !a->f[1] && a->wd-- > 0 && ++(*count))
		ft_putchar('0');
}
