/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:35:58 by smarquez          #+#    #+#             */
/*   Updated: 2025/01/16 17:41:32 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

#ifndef FRACTOL_H
#define FRACTOL_H

typedef struct f_data
{
    void *mlx;
    void *win;
    void *img;
    char *addr;
    int bpp;
    int line_len;
    int endian;
    int     win_width;
    int     win_height;
}f_data;



#endif 