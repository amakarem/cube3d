/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:39:37 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/03 22:07:43 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void    ft_putpxl(t_img **img, int x, int y, uint32_t color)
{
    int offset;

	printf("putpxl: x = %i, y = %i\n", x, y);

    offset = x * ((*img)->bpp / 8) + y * (*img)->linelen;
    *((uint32_t *)((*img)->data + offset)) = color;
}

void    ft_clean_window(t_data *data)
{
    int  x;
    int  y;

	y = 0;
    while (y < data->wnd_h)
    {
        x = 0;
        while (x < data->wnd_w)
            ft_putpxl(&data->buffer, x++, y, 0);
        y++;
    }
}
