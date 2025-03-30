/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaners.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:53:14 by tkeil             #+#    #+#             */
/*   Updated: 2025/03/30 20:02:19 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void    ft_clear_buffer(void *mlx, t_img **buffer)
{
    if (!buffer || !*buffer)
        return ;
    if ((*buffer)->img)
        mlx_destroy_image(mlx, (*buffer)->img);
    free(*buffer);
    *buffer = NULL;
}

void    ft_clear_texture(void *mlx, t_texture **texture)
{
    if (!texture || !*texture)
        return ;
    if ((*texture)->img)
        mlx_destroy_image(mlx, (*texture)->img);
    free(*texture);
    *texture = NULL;
}

void    ft_clear_window(void *mlx, void **win)
{
    if (!win || !*win)
        return ;
    mlx_destroy_window(mlx, *win);
    *win = NULL;
}

void    ft_cleardata(t_data **data)
{
    if (!data || !*data)
        return;
    ft_free_ptr(&(*data)->map);
    ft_clear_texture((*data)->mlx_ptr, &(*data)->north);
    ft_clear_texture((*data)->mlx_ptr, &(*data)->south);
    ft_clear_texture((*data)->mlx_ptr, &(*data)->east);
    ft_clear_texture((*data)->mlx_ptr, &(*data)->west);
    ft_clear_buffer((*data)->mlx_ptr, &(*data)->buffer);
    ft_clear_window((*data)->mlx_ptr, &(*data)->mlx_win);
    (*data)->mlx_ptr = NULL;
    free(*data);
    *data = NULL;
}
