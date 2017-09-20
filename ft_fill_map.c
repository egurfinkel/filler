/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egurfink <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 22:15:20 by egurfink          #+#    #+#             */
/*   Updated: 2017/09/20 22:15:23 by egurfink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		fill_map(t_t *s)
{
	int		i;

	i = 0;
	get_next_line(FD, &s->line);
	while (!ft_isdigit(s->line[i]))
		i++;
	s->map_x = 0;
	while (ft_isdigit(s->line[i]))
	{
		s->map_x += s->line[i] - '0';
		s->map_x *= 10;
		i++;
	}
	s->map_x /= 10;
	i++;
	s->map_y = 0;
	while (ft_isdigit(s->line[i]))
	{
		s->map_y += s->line[i] - '0';
		s->map_y *= 10;
		i++;
	}
	s->map_y /= 10;
	fill_map_2(s);
}

void		fill_map_2(t_t *s)
{
	int		i;
	int		p;
	int		l;

	i = 0;
	s->map = (char **)malloc(sizeof(char *) * (s->map_x + 1));
	s->map[s->map_x] = NULL;
	while (i < s->map_x)
		s->map[i++] = ft_strnew((size_t)(s->map_y + 1));
	get_next_line(FD, &s->line);
	i = 0;
	while (i < s->map_x)
	{
		get_next_line(FD, &(s->line));
		l = 0;
		p = 4;
		while (s->line[p])
		{
			s->map[i][l] = s->line[p];
			l++;
			p++;
		}
		i++;
	}
}
