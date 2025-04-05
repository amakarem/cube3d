/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:02:22 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/04 15:20:05 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// sets everything to NULL -> in case something can not allocate,
// the cleardata function
// just frees all available heap allocations and it
// doesn't occur a bad access error.
void	ft_init_null(t_data **data)
{
	(*data)->mlx_ptr = NULL;
	(*data)->mlx_win = NULL;
	(*data)->buffer = NULL;
	(*data)->north = NULL;
	(*data)->south = NULL;
	(*data)->east = NULL;
	(*data)->west = NULL;
	(*data)->map = NULL;
	(*data)->wnd_h = 0;
	(*data)->wnd_w = 0;
	(*data)->floor_color = 0;
	(*data)->ceiling_color = 0;
}
