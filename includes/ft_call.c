/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egurfink <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 21:57:15 by egurfink          #+#    #+#             */
/*   Updated: 2017/04/13 21:57:16 by egurfink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			call_hex(t_spc *spc, va_list v_lst, int *count)
{
	if (spc->type == 'X')
	{
		spc->f[1]
		? to_hex_big_minus(spc, v_lst, count)
		: to_hex_big(spc, v_lst, count);
	}
	else
	{
		spc->f[1]
		? to_hex_minus(spc, v_lst, count)
		: to_hex(spc, v_lst, count);
	}
}

void			call_char(t_spc *spc, va_list v_lst, int *count)
{
	if (spc->type == 'C')
		to_char_big(spc, v_lst, count, 1);
	else
		to_char(spc, v_lst, count, 1);
}

void			call_int(t_spc *spc, va_list v_lst, int *count)
{
	if (spc->type == 'D')
	{
		spc->type = 'd';
		spc->ln = 3;
	}
	spc->f[1]
	? to_int_minus(spc, v_lst, count)
	: to_int(spc, v_lst, count);
}

void			init_struct(t_tmp **tmp, t_spc **spec)
{
	tmp_struct_init(tmp);
	struct_init(spec);
}

void			free_struct(t_spc **spec, t_tmp **tmp)
{
	free(*spec);
	free(*tmp);
}
