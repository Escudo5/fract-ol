/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:47:18 by smarquez          #+#    #+#             */
/*   Updated: 2025/01/20 14:51:58 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int color_select(t_data *data)
{
    int color;
    
    if (data->iter == data->max_iter)
        color = 0x000000;  // Negro si no se escapa
    else
        color = (data->iter * 255 / data->max_iter) << 16; // Color gradiente en rojo

    return color;
}
