/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egurfink <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 19:02:59 by egurfink          #+#    #+#             */
/*   Updated: 2017/09/20 22:34:19 by egurfink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "includes/libft.h"
# include "includes/get_next_line.h"
# include "includes/ft_printf.h"
# define FD 0

typedef struct		s_s
{
	char			player;
	char			enemy;
	int				touch;
	char			**map;
	int				map_x;
	int				map_y;
	char			**piece;
	int				piece_cord_x;
	int				piece_cord_y;
	int				multi;
	char			*line;
	int				*to_place;
	int				*opponent;
	int				x_to_send;
	int				y_to_send;
	int				x_dis;
	int				y_dis;
	int				dis_for_current_x;
	int				dis_for_current_y;
	int				sum_dis;
}					t_t;

void				first_init(t_t *s);
void				fill_player(t_t *s);
void				fill_map(t_t *s);
void				fill_map_2(t_t *s);
void				fill_piece(t_t *s);
void				fill_piece_2(t_t *s, int i);
void				fill_arr_minus_one(t_t *s);
void				ft_write_map_fig(t_t *s);
int					place_figure(int x, int y, t_t *s);
void				add_tab(int x, int y, int *tab);
void				closest(t_t *s);
void				coordinates(t_t *s);

#endif
