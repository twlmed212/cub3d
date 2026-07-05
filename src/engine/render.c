/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtawil <mtawil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 14:35:29 by mtawil            #+#    #+#             */
/*   Updated: 2026/07/03 14:19:43 by mtawil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void    my_pixel_put(t_img *img, int x, int y, int color) {
    char    *dst;
    dst = img->data + (y * img->line_len + x * (img->bpp / 8));
    *(unsigned int *)dst = color;
}

int     render_frame(void *param)
{
    t_cub   *game;
    int     x ;
    int     y;

    game = (t_cub *)param;
    y = 0;
    x = 0;
    while(y < WIN_HEIGHT){
        x = 0;
        while(x < WIN_WIDTH){
            my_pixel_put(&game->img, x, y, 0x00FFFF00);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(game->mlx, game->win, game->img.ptr, 0, 0);
    return (0);
}

