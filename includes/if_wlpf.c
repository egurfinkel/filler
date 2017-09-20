/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_wlpf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egurfink <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 21:57:38 by egurfink          #+#    #+#             */
/*   Updated: 2017/04/13 21:57:39 by egurfink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				if_width(const char *s)
{
	if (*s != '0' && ft_isdigit(*s))
		return (1);
	return (0);
}

int				if_length(const char *s)
{
	if (ft_strncmp("hh", s, 2) == 0)
		return (1);
	if (ft_strncmp("h", s, 1) == 0)
		return (1);
	if (ft_strncmp("ll", s, 2) == 0)
		return (1);
	if (ft_strncmp("l", s, 1) == 0)
		return (1);
	if (ft_strncmp("z", s, 1) == 0)
		return (1);
	if (ft_strncmp("j", s, 1) == 0)
		return (1);
	return (0);
}

int				if_precision(const char *s)
{
	if (*s == '.')
		return (1);
	return (0);
}

int				if_flag(const char ch)
{
	if (ch == '+' || ch == '-' || ch == '0' || ch == ' ' || ch == '#')
		return (1);
	return (0);
}
