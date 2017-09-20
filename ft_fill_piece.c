/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_piece.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egurfink <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 22:15:32 by egurfink          #+#    #+#             */
/*   Updated: 2017/09/20 22:15:34 by egurfink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		fill_piece(t_t *s)
{
	int		i;

	s->piece_cord_x = 0;
	s->piece_cord_y = 0;
	i = 0;
	get_next_line(FD, &s->line);
	while (s->line[i] && !ft_isdigit(s->line[i]))
		i++;
	while (s->line[i] && ft_isdigit(s->line[i]))
	{
		s->piece_cord_x += s->line[i] - '0';
		s->piece_cord_x *= 10;
		i++;
	}
	s->piece_cord_x /= 10;
	i++;
	fill_piece_2(s, i);
}

void		fill_piece_2(t_t *s, int i)
{
	int		l;

	while (s->line[i] && ft_isdigit(s->line[i]))
	{
		s->piece_cord_y += s->line[i] - '0';
		s->piece_cord_y *= 10;
		i++;
	}
	s->piece_cord_y /= 10;
	i = 0;
	s->piece = (char **)malloc(sizeof(char *) * (s->piece_cord_x + 1));
	s->piece[s->piece_cord_x] = NULL;
	while (i < s->piece_cord_x)
	{
		l = 0;
		s->piece[i] = ft_strnew((size_t)(s->piece_cord_y + 1));
		get_next_line(FD, &s->line);
		while (s->line[l])
		{
			s->piece[i][l] = s->line[l];
			l++;
		}
		i++;
	}
}
