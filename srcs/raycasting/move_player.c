/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:32:23 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/05 20:16:52 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// mouse x-orientation
// rotation matrix
// {{cos -sin}, {sin cos}}
// applied to player dir and camera plane (vectors)
void    ft_rotate(char **map, t_player *p, float angle)
{
    (void)map;
    (void)p;
    (void)angle;
}

// checking for wall colissions x/y
// seperatly, for allowing to slide along the wall
void	ft_action(char **map, t_player *p, int x_new, int y_new)
{
	if (map[(int)p->posY][x_new])
        p->posX = x_new;
    if (map[y_new][(int)p->posX])
        p->posY = y_new;
}

// translation
// front/back moving (w/s)
// left/right strafing (a/d)
void    ft_translate(char **map, t_player *p, t_keyboard k)
{
    int x_move;
    int y_move;
    int x_stra;
    int y_stra;

    x_move = p->dirX * SPEED;
    y_move = p->dirY * SPEED;
    x_stra = -p->dirY * SPEED;
    y_stra = p->dirX * SPEED;
    if (k.w_down)
        ft_action(map, p, p->posX + x_move, p->posY + y_move);
	if (k.s_down)
        ft_action(map, p, p->posX - x_move, p->posY - y_move);
    if (k.a_down)
        ft_action(map, p, p->posX + x_stra, p->posY + y_stra);
	if (k.d_down)
        ft_action(map, p, p->posX - x_stra, p->posY - y_stra);
}

void ft_move_player(t_data *data, t_player *p)
{
    // ft_rotate(data->map, p);
    ft_translate(data->map, p, data->keyboard);
}
