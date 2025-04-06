/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 19:30:28 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/06 19:47:07 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include "cub3D.h"

void            ft_minimap(void);
void            ft_rotate(t_player *p, float angle);
int				ft_mousemove(int x, int y, void *param);
int				ft_mouse_up(int button, int x, int y, void *param);
int				ft_mouse_down(int button, int x, int y, void *param);

#endif
