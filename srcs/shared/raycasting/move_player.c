/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:32:23 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/08 18:12:55 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// mouse x-orientation
// rotation matrix: {{cos -sin}, {sin cos}}
// applied to player dir and camera plane (vectors)
void	ft_rotate(t_player *p, float angle)
{
	float	tmp_x;
	float	tmp_planex;

	tmp_x = p->dirx;
	tmp_planex = p->planex;
	p->dirx = p->dirx * cos(angle) - p->diry * sin(angle);
	p->diry = tmp_x * sin(angle) + p->diry * cos(angle);
	p->planex = p->planex * cos(angle) - p->planey * sin(angle);
	p->planey = tmp_planex * sin(angle) + p->planey * cos(angle);
}

// checking for wall colissions x/y
// seperatly, for allowing to slide along the wall
void	ft_action(char **map, t_player *p, float x_new, float y_new)
{
	if (map[(int)(p->posy)][(int)(x_new + WALL_DISTANCE)] != '1' &&
		map[(int)(p->posy)][(int)(x_new - WALL_DISTANCE)] != '1')
		p->posx = x_new;
	if (map[(int)(y_new + WALL_DISTANCE)][(int)(p->posx)] != '1' &&
		map[(int)(y_new - WALL_DISTANCE)][(int)(p->posx)] != '1')
		p->posy = y_new;
}

// translation
// front/back moving (w/s)
// left/right strafing (a/d)
void	ft_translate(t_data *data, char **map, t_player *p, t_keyboard k)
{
	float	x_move;
	float	y_move;
	float	x_stra;
	float	y_stra;

	x_move = 1.0f * p->dirx * SPEED;
	y_move = 1.0f * p->diry * SPEED;
	x_stra = -1.0f * p->diry * SPEED;
	y_stra = 1.0f * p->dirx * SPEED;
	if (k.w_down)
		ft_action(map, p, p->posx + x_move, p->posy + y_move);
	if (k.s_down)
		ft_action(map, p, p->posx - x_move, p->posy - y_move);
	if (k.a_down)
		ft_action(map, p, p->posx - x_stra, p->posy - y_stra);
	if (k.d_down)
		ft_action(map, p, p->posx + x_stra, p->posy + y_stra);
	if (k.left_down)
		ft_rotate(p, ROTATION_SPEED * -8.0f);
	if (k.right_down)
		ft_rotate(p, ROTATION_SPEED * 8.0f);
	if (k.up_pressed && data->center_h < data->wnd_h)
		data->center_h += 20;
	if (k.down_pressed && data->center_h > 0)
		data->center_h -= 20;
}

void	ft_move_player(t_data *data, t_player *p)
{
	ft_translate(data, data->map, p, data->keyboard);
}
