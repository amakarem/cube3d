/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:32:23 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/07 19:31:26 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// mouse x-orientation
// rotation matrix: {{cos -sin}, {sin cos}}
// applied to player dir and camera plane (vectors)
void    ft_rotate(t_player *p, float angle)
{
    float   tmp_x;
    float   tmp_planeX;
    
    tmp_x = p->dirX;
    tmp_planeX = p->planeX;
    p->dirX = p->dirX * cos(angle) - p->dirY * sin(angle);
    p->dirY = tmp_x * sin(angle) + p->dirY * cos(angle);
    p->planeX = p->planeX * cos(angle) - p->planeY * sin(angle);
    p->planeY = tmp_planeX * sin(angle) + p->planeY * cos(angle);
}

// checking for wall colissions x/y
// seperatly, for allowing to slide along the wall
void	ft_action(char **map, t_player *p, float x_new, float y_new)
{
	if (map[(int)(p->posY)][(int)(x_new + WALL_DISTANCE)] != '1' &&
		map[(int)(p->posY)][(int)(x_new - WALL_DISTANCE)] != '1')
		p->posX = x_new;
	if (map[(int)(y_new + WALL_DISTANCE)][(int)(p->posX)] != '1' &&
		map[(int)(y_new - WALL_DISTANCE)][(int)(p->posX)] != '1')
		p->posY = y_new;
}

// translation
// front/back moving (w/s)
// left/right strafing (a/d)
void    ft_translate(char **map, t_player *p, t_keyboard k)
{
    float x_move;
    float y_move;
    float x_stra;
    float y_stra;

    x_move = 1.0f * p->dirX * SPEED;
    y_move = 1.0f * p->dirY * SPEED;
    x_stra = -1.0f * p->dirY * SPEED;
    y_stra = 1.0f * p->dirX * SPEED;
    if (k.w_down)
		ft_action(map, p, p->posX + x_move, p->posY + y_move);
	if (k.s_down)
		ft_action(map, p, p->posX - x_move, p->posY - y_move);
    if (k.a_down)
		ft_action(map, p, p->posX - x_stra, p->posY - y_stra);
	if (k.d_down)
		ft_action(map, p, p->posX + x_stra, p->posY + y_stra);
	if (k.left_down)
		ft_rotate(p, ROTATION_SPEED * -8.0f);
	if (k.right_down)
		ft_rotate(p, ROTATION_SPEED * 8.0f);
}

void ft_move_player(t_data *data, t_player *p)
{
    ft_translate(data->map, p, data->keyboard);
}
