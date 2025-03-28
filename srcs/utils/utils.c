/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:53:31 by tkeil             #+#    #+#             */
/*   Updated: 2025/03/28 17:12:13 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void    ft_free_ptr(char ***ptr)
{
    size_t  i;
    
    if (!ptr || !*ptr)
        return ;
    i = 0;
    while ((*ptr)[i])
    {
        free((*ptr)[i]);
        i++;
    }
    free(*ptr);
    (*ptr) = NULL;
}

size_t  ft_ptr_len(char **ptr)
{
    size_t  i;

    if (!ptr || !*ptr)
        return (0);
    i = 0;
    while (ptr[i])
        i++;
    return (i);
}
