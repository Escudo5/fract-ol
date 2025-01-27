/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:02:33 by smarquez          #+#    #+#             */
/*   Updated: 2025/01/27 15:05:36 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void var_init(t_data *data)
{
    //data->color = 0xff0000;
    data->max_iter = 75;
    data->zoom_factor = 1.0;
    data->win_width = 800;
    data->win_height = 800;
    data->x_min = -2.0;
    data->x_max = 2.0;
    data->y_min = -2.0;
    data->y_max = 2.0;
    //data->color_set = 0;
    data->z_img = 0.0;
    data->z_re = 0.0;
    data->fractal = NULL;
    data->mlx = NULL;
    data->win = NULL;
    data->img = NULL;
    data->pixels = NULL;
}

