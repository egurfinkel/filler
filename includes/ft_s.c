/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egurfink <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 21:56:10 by egurfink          #+#    #+#             */
/*   Updated: 2017/04/13 21:57:00 by egurfink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*get_string(va_list v_lst)
{
	return (va_arg(v_lst, char*));
}

void			string_magic(t_spc *a, int *count, const char *s, int i)
{
	if (s)
	{
		if (a->f[1] == 0 && a->f[0] == 1)
		{
			while (a->wd-- > 0 && ++(*count))
				write(1, "0", 1);
		}
		else
		{
			while (a->wd-- > 0 && ++(*count))
				write(1, " ", 1);
		}
		if (a->prc != -1 && (size_t)a->prc < ft_strlen(s))
		{
			while (i < a->prc && ++(*count))
				ft_putchar(s[i++]);
		}
		else
		{
			while (s[i] && ++(*count))
				ft_putchar(s[i++]);
		}
	}
}

void			to_string(t_spc *a, va_list v_lst, int *count)
{
	char	*s;
	int		i;

	i = 0;
	s = get_string(v_lst);
	(!s) ? (s = "(null)") : 0;
	(a->prc != -1 && (size_t)a->prc < ft_strlen(s))
	? (a->wd -= a->prc) : (a->wd -= ft_strlen(s));
	string_magic(a, count, s, i);
}

void			string_minus_magic(t_spc *a, int *count, const char *s, int i)
{
	if (s)
	{
		(a->prc != -1 && (size_t)a->prc < ft_strlen(s))
		? (a->wd -= a->prc) : (a->wd -= ft_strlen(s));
		if (a->prc != -1 && (size_t)a->prc < ft_strlen(s))
		{
			while (i < a->prc && ++(*count))
				ft_putchar(s[i++]);
		}
		else
		{
			while (s[i] && ++(*count))
				ft_putchar(s[i++]);
		}
		if (a->f[1] == 0 && a->f[0] == 1)
		{
			while (a->wd-- > 0 && ++(*count))
				write(1, "0", 1);
		}
		else
		{
			while (a->wd-- > 0 && ++(*count))
				write(1, " ", 1);
		}
	}
}

void			to_string_minus(t_spc *a, va_list v_lst, int *count)
{
	char	*s;
	int		i;

	i = 0;
	s = get_string(v_lst);
	(!s) ? (s = "(null)") : 0;
	string_minus_magic(a, count, s, i);
}
