/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:18:41 by smarquez          #+#    #+#             */
/*   Updated: 2025/01/21 13:24:54 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int mouse_zoom(int button, int x, int y, t_data *data)
{
    (void)data;  // Esto "ignora" el parámetro data
    printf("Mouse event: button=%d, x=%d, y=%d\n", button, x, y);
    return (0);
}
