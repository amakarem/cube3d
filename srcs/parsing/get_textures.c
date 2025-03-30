/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 16:09:09 by tkeil             #+#    #+#             */
/*   Updated: 2025/03/30 16:09:39 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int ft_file_to_image(void *mlx, char *file, int *w, int *h)
{
    void    *img;
    char    *extension;

    img = NULL;
    extension = file + (ft_strlen(file) - 4);
    if (!ft_strncmp(extension, ".xpm", 4))
        img = mlx_xpm_file_to_image(mlx, file, w, h);
    else if (!ft_strncmp(extension, ".png", 4))
        img = mlx_png_file_to_image(mlx, file, w, h);
    else
        return (NULL);
    return (img);
}

static int ft_get_tex(t_texture **tex, void *mlx, char *file)
{
    int *w;
    int *h;

    w = &(*tex)->width;
    h = &(*tex)->height;
    (*tex)->img = ft_file_to_image(mlx, file, w, h);
    if (!(*tex)->img)
        return (0);
    (*tex)->data = mlx_get_data_addr((*tex)->img, &(*tex)->bpp, &(*tex)->linelen, &(*tex)->endian);
    if (!(*tex)->data)
        return (0);
    return (1);
}

int    ft_get_textures(t_data **data, char **split)
{
    if (!ft_strncmp(split[0], "NO", ft_strlen(split[0])))
    {
        if (!ft_get_tex(&(*data)->north, (*data)->mlx_ptr, split[1]))
            return (0);
    }
    else if (!ft_strncmp(split[0], "SO", ft_strlen(split[0])))
    {
        if (!ft_get_tex(&(*data)->south, (*data)->mlx_ptr, split[1]))
            return (0);
    }
    else if (!ft_strncmp(split[0], "EA", ft_strlen(split[0])))
    {
        if (!ft_get_tex(&(*data)->east, (*data)->mlx_ptr, split[1]))
            return (0);
    }
    else if (!ft_strncmp(split[0], "WE", ft_strlen(split[0])))
    {
        if (!ft_get_tex(&(*data)->west, (*data)->mlx_ptr, split[1]))
            return (0);
    }
    return (1);
}
