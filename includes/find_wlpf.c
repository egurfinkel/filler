/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_wlpf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egurfink <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 21:57:45 by egurfink          #+#    #+#             */
/*   Updated: 2017/04/13 21:57:46 by egurfink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				find_flag(const char *s, t_spc *a)
{
	if (*s == '0')
		a->f[0] = 1;
	else if (*s == '-')
		a->f[1] = 1;
	else if (*s == '+')
		a->f[2] = 1;
	else if (*s == '#')
		a->f[3] = 1;
	else if (*s == ' ')
		a->f[4] = 1;
	return (1);
}

int				find_width(const char *s, t_spc *a)
{
	a->wd = ft_atoi(s);
	return (ft_countnum(a->wd));
}

int				find_precision(const char *s, t_spc *a)
{
	int			prec;

	prec = 1;
	s++;
	if (*s != '-' && *s != '+')
	{
		a->prc = ft_atoi((char*)s);
		prec += ft_countnum(a->prc);
		if (*s == '0')
			prec++;
	}
	return (prec);
}

void			find_ln_magic(const char *s, t_spc *a)
{
	if (ft_strncmp("z", s, 1) == 0 && a->ln < 5)
		a->ln = 5;
	else if (ft_strncmp("j", s, 1) == 0 && a->ln < 6)
		a->ln = 6;
	else if (a->h > 0 && a->ln < 2)
	{
		a->ln = (a->h % 2 == 0) ? 1 : 2;
		a->h = 0;
	}
	else if (a->l > 0 && a->ln < 4)
	{
		a->ln = (a->l % 2 == 0) ? 3 : 4;
		a->l = 0;
	}
}

int				find_length(const char *s, t_spc *a)
{
	int			i;

	i = 0;
	if (a->h == 0 && a->l == 0)
	{
		while (s[i] && s[i] != '%')
		{
			(s[i] == 'h') ? a->h++ : 0;
			(s[i] == 'l') ? a->l++ : 0;
			i++;
		}
	}
	find_ln_magic(s, a);
	if (a->ln == 1 || a->ln == 3)
		return (2);
	return (1);
}
