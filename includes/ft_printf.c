/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egurfink <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 16:54:48 by egurfink          #+#    #+#             */
/*   Updated: 2017/03/25 16:16:18 by egurfink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			tmp_struct_init(t_tmp **str)
{
	(*str) = (t_tmp*)malloc(sizeof(t_tmp));
	(*str)->w = 0;
	(*str)->p = 0;
	(*str)->f = 0;
	(*str)->l = 0;
}

void			struct_init(t_spc **str)
{
	(*str) = (t_spc*)malloc(sizeof(t_spc));
	(*str)->wd = -1;
	(*str)->prc = -1;
	(*str)->f[0] = 0;
	(*str)->f[1] = 0;
	(*str)->f[2] = 0;
	(*str)->f[3] = 0;
	(*str)->f[4] = 0;
	(*str)->ln = -1;
	(*str)->type = '\0';
	(*str)->i = 1;
	(*str)->h = 0;
	(*str)->l = 0;
	(*str)->wand = 0;
	(*str)->neg = 0;
	(*str)->x = 0;
}

void			for_print(t_spc *spc, va_list v_lst, int *count)
{
	if (spc->type == 'd' || spc->type == 'D' || spc->type == 'i')
		call_int(spc, v_lst, count);
	else if (spc->type == 's' || spc->type == 'S')
		call_str(spc, v_lst, count);
	else if (spc->type == 'p')
		call_pointer(spc, v_lst, count);
	else if (spc->type == 'o' || spc->type == 'O')
		call_octal(spc, v_lst, count);
	else if (spc->type == 'u' || spc->type == 'U')
		call_uint(spc, v_lst, count);
	else if (spc->type == 'x' || spc->type == 'X')
		call_hex(spc, v_lst, count);
	else if (spc->type == 'c' || spc->type == 'C')
		call_char(spc, v_lst, count);
	else
		to_percent(spc, v_lst, count);
}

int				ft_magic(const char *str, va_list v_lst, int *count)
{
	t_tmp		*tmp;
	t_spc		*spec;

	init_struct(&tmp, &spec);
	while (str[spec->i] && ((tmp->f = if_flag(str[spec->i])) ||
			(tmp->w = if_width(str + spec->i)) ||
			(tmp->l = if_length(str + spec->i)) ||
			(tmp->p = if_precision(str + spec->i))))
	{
		if (tmp->f == 1)
			spec->i += find_flag(str + spec->i, spec);
		else if (tmp->w == 1)
			spec->i += find_width(str + spec->i, spec);
		else if (tmp->l == 1)
			spec->i += find_length(str + spec->i, spec);
		else if (tmp->p == 1)
			spec->i += find_precision(str + spec->i, spec);
	}
	spec->type = str[spec->i++];
	if (spec->type == '\0')
		return (spec->i - 1);
	for_print(spec, v_lst, count);
	free_struct(&spec, &tmp);
	return (spec->i);
}

int				ft_printf(const char *str, ...)
{
	va_list		ag;
	int			count;
	int			i;

	va_start(ag, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
			i += ft_magic(str + i, ag, &count);
		else
		{
			ft_putchar(str[i++]);
			count++;
		}
	}
	va_end(ag);
	return (count);
}
