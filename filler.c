/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egurfink <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 17:23:42 by egurfink          #+#    #+#             */
/*   Updated: 2017/05/09 17:26:54 by egurfink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/libft.h"
#include "includes/get_next_line.h"
#include "includes/ft_printf.h"

// find_piece_cords()   - find all possible variants of the token
// check_bounds()       - check whether the figure does not cross borders of the map
// Check_place()        - check whether the figure fits in a map, no overlap with enemy, 1 overlap with your territory

#define FD 0

typedef struct		s_s
{
    char			player;
    char			enemy;
    int				touch;
    char			**map;
    int				map_x;
    int				map_y;

    char 			**piece;
    int 			piece_cord_x;
    int 			piece_cord_y;
    int 			find;
    int 			index;
    int 			multi;
    int 			x;
    int 			y;
    char            *line;
    int             **matrix;
    //ARRS OPP AND TO_PLACE
    int             *to_place;//x * y * 2 | arr[1,2,3,4,4,4,5,7,-1,-1,-1,-1,-1]
    int             *opponent;//x * y * 2 | arr[2,5,3,7,4,3,6,7,-1,-1,-1,-1,-1]
    // x = 1 y = 1;
    int             x_to_send; //3
    int             y_to_send; //4
    int             x_dis_for_current_x; //1
    // +
    int             y_dis_for_current_y; //1
}					t_t;

void                first_init(t_t *s)
{
    s->player = 'X';
    s->enemy = 'O';
    s->touch = 0;
    s->map = NULL;
    s->map_x = 0;
    s->map_y = 0;
    s->piece = NULL;
    s->piece_cord_x = 0;
    s->piece_cord_y = 0;
    s->find = 0;
    s->index = 0;
    s->multi = 0;
    s->x = 0;
    s->y = 0;
    s->line = NULL;
    s->to_place = NULL;
    s->opponent = NULL;
    s->x_to_send = 0;
    s->y_to_send = 0;
    s->x_dis_for_current_x = 2048;
    s->y_dis_for_current_y = 2048;
}

void        fill_player(t_t *s)
{
    get_next_line(FD, &s->line);
    if (s->line[10] == '1')
    {
        s->player = 'O';
        s->enemy = 'X';
    }
}

void        fill_map(t_t *s)
{
    int i;

    i = 0;
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
    while (ft_isdigit(s->line[i]))
    {
        s->map_y += s->line[i] - '0';
        s->map_y *= 10;
        i++;
    }
    s->map_y /= 10;
    s->map = (char **)malloc(sizeof(char *) * (s->map_x + 1));
    s->map[s->map_x] = NULL;
    i = 0;
    while (i < s->map_x)
    {
        s->map[i] = ft_strnew((size_t)(s->map_y + 1));
        i++;
    }
    get_next_line(FD, &s->line);
    i = 0;
    int l;
    int p;
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

void        fill_piece(t_t *s)
{
    int     i;
    int     l;

    s->piece_cord_x = 0;
    s->piece_cord_y = 0;
    get_next_line(FD, &s->line);
    i = 0;
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
        s->piece[i] = ft_strnew((size_t) (s->piece_cord_y + 1));
        get_next_line(FD, &s->line);
        while (s->line[l])
        {
            s->piece[i][l] = s->line[l];
            l++;
        }
        i++;
    }
}

void        fill_arr_minus_one(t_t *s)
{
    int     multi;

    s->multi = (s->map_x * s->map_y) * 2;
    multi = s->multi;
    if (s->opponent == NULL)
        s->opponent = (int*)malloc(sizeof(int) * s->multi);
    if (s->to_place == NULL)
        s->to_place = (int*)malloc(sizeof(int) * s->multi);
    while (multi--)
    {
        s->opponent[multi] = -1;
        s->to_place[multi] = -1;
    }
}

void        fill_matrix(t_t *s)
{
    int     x;
    int     y;

    x = 0;
    s->matrix = (int**)malloc(sizeof(int*) * s->map_x);
    while (x < s->map_x)
    {
        s->matrix[x] = (int*)malloc(sizeof(int) * s->map_y);
        y = 0;
        while (y < s->map_y)
        {
            s->matrix[x][y] = s->index;
            y++;
        }
        x++;
    }
}

//void        a_star_map(t_t *s, int x, int y)
//{
//    s->index++;
//    (s->map[x][y] == s->enemy) ? (s->matrix[x][y] = -2) : (s->matrix[x][y] = s->index);
//    (s->map[x][y + 1] == s->enemy) ? (s->matrix[x][y + 1] = -2) : (s->matrix[x][y + 1] = s->index);
//    (s->map[x + 1][y] == s->enemy) ? (s->matrix[x + 1][y] = -2) : (s->matrix[x + 1][y] = s->index);
//    (s->map[x + 1][y + 1] == s->enemy) ? (s->matrix[x + 1][y + 1] = -2) : (s->matrix[x + 1][y + 1] = s->index);
//    (s->map[x - 1][y] == s->enemy) ? (s->matrix[x - 1][y] = -2) : (s->matrix[x - 1][y] = s->index);
//    (s->map[x][y - 1] == s->enemy) ? (s->matrix[x][y - 1] = -2) : (s->matrix[x][y - 1] = s->index);
//    (s->map[x - 1][y - 1] == s->enemy) ? (s->matrix[x - 1][y - 1] = -2) : (s->matrix[x - 1][y - 1] = s->index);
//    (s->map[x + 1][y - 1] == s->enemy) ? (s->matrix[x + 1][y - 1] = -2) : (s->matrix[x + 1][y - 1] = s->index);
//    (s->map[x - 1][y + 1] == s->enemy) ? (s->matrix[x - 1][y + 1] = -2) : (s->matrix[x - 1][y + 1] = s->index);
//    /////////////DEBUG//////////////
//    int i = 0;
//    while (i < s->map_x)
//    {
//        int j = 0;
//        while (j < s->map_y)
//        {
//            ft_printf("%d ", s->matrix[i][j]);
//            j++;
//        }
//        ft_printf("\n");
//        i++;
//    }
//}

//void        ft_write_map_fig(t_t *s)
//{
//    int i;
//    int j;
//    int k;
//
//    get_next_line(FD, &(s->line));
//    i = 0;
//    while (i < s->map_x)
//    {
//        j = 0;
//        k = 0;
//        get_next_line(FD, &(s->line));
//        while (ft_isdigit(s->line[k]) || s->line[k] == ' ')
//            k++;
//        while (j < s->map_y)
//        {
//            s->map[i][j] = s->line[k];
//            j++;
//            k++;
//        }
//        ft_strclr(s->line);
//        i++;
//    }
//    fill_piece(s);
//    i = 0;
//    while (s->piece[i])
//        i++;
//}

int			can_place_figure(int x, int y, t_t *s)
{
    int		count_x;
    int		count_y;

    count_x = -1;
    s->touch = 0;
    while (++count_x < s->piece_cord_x &&
           (s->piece_cord_x + x - 1) < s->map_x)
    {
        count_y = -1;
        while (++count_y < s->piece_cord_y &&
               (s->piece_cord_y + y - 1) < s->map_y)
        {
            if (s->piece[count_x][count_y] == '*' &&
                (s->map[count_x + x][count_y + y] == s->player
                 || s->map[count_x + x][count_y + y] == ft_tolower(s->player)))
                s->touch++;
            if (s->map[count_x + x][count_y + y] == s->enemy)
                return (0);
        }
    }
    return ((s->touch) != 1 ? 0 : 1);
}

//void        find_place(t_t *s)
//{
//    int     x;
//    int     y;
//
//    x = 0;
//    while (x < s->map_x)
//    {
//        y = 0;
//        while (y < s->map_y)
//        {
//            if (can_place_figure(x, y, s))
//            {
//                s->x = x;
//                s->y = y;
//                ft_printf("%d %d\n", x, y);
//                return ;
//            }
//            y++;
//        }
//        x++;
//    }
//    ft_printf("%d %d\n", 0, 0);
//}

void            add_tab(int x, int y, int *tab)
{
    int         i;

    i = 0;
    while (tab[i] != -1)
        i++;
    tab[i] = x;
    tab[i + 1] = y;
}

void			find_coordinates(t_t *s)
{
    int			x;
    int			y;


    x = -1;
    while (++x < s->map_x)
    {
        y = -1;
        while (++y < s->map_y)
        {
            if (can_place_figure(x, y, s))
                add_tab(x, y, s->to_place);
            if (s->map[x][y] == s->enemy || s->map[x][y] == ft_tolower(s->enemy))
                add_tab(x, y, s->opponent);
        }
    }
    //find_closest();
}

int			main()
{
    t_t *s;

    s = (t_t*)malloc(sizeof(t_t));
    first_init(s);
    fill_player(s);
    //fill_matrix(s);
    //find_enemy(s);
   // a_star_map(s, s->enemy_x, s->enemy_y);
    //find_coords_of_me(s);
  while (get_next_line(FD, &(s->line)) > 0)
  {
      fill_map(s);
      fill_piece(s);
      fill_arr_minus_one(s);
      //ft_write_map_fig(s);
      //find_enemy(s);
      //find_coords_of_me(s);
      //a_star_map(s, s->enemy_x, s->enemy_y);
      //find_coords_of_me(s);
      find_coordinates(s);
  }
//  ft_printf("%d %d", 0, 0);
//	ft_printf("\n%c %c\n", s->player, s->enemy);
//	ft_printf("%d %d\n", s->map_y, s->map_x);
//	ft_printf("%d %d\n", s->piece_cord_y, s->piece_cord_x);
//	ft_printf("%c\n", s->piece[0][0]);
    ft_printf("%d %d\n", 0, 0);
    return (0);
}

/*

$$$ exec p1 : [./a.out]
Plateau 15 17:
01234567890123456
000 .................
001 .................
002 .................
003 .................
004 .................
005 .................
006 .................
007 .................
008 ..O..............
009 .................
010 .................
011 .................
012 .............X...
013 .................
014 .................
Piece 3 5:
.****
...**
.....

 Plateau 15 17:
01234567890123456
000 .................
001 .................
002 .................
003 .................
004 .................
005 .................
006 .................
007 .................
008 ..O..............
009 .................
010 .................
011 .................
012 .............X...
013 .................
014 .................
Piece 1 3:
.**

 Plateau 15 17:
01234567890123456
000 .................
001 .................
002 .................
003 .................
004 .................
005 .................
006 .................
007 .................
008 ..O..............
009 .................
010 .................
011 .................
012 .............X...
013 .................
014 .................
Piece 2 4:
.**..
.***.

 */