/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtawil <mtawil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 14:25:36 by mtawil            #+#    #+#             */
/*   Updated: 2026/07/05 16:42:07 by mtawil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void init_player(t_cub *game){
    char c;
    c = game->map[(int)game->player.y][(int)game->player.x];
    if (c == 'N')
    {
        game->player.dir_x = 0;
        game->player.dir_y = -1;
    }
    else if (c == 'S') {
        game->player.dir_x = 0;
        game->player.dir_y = 1;
    }
    else if (c == 'E') {
        game->player.dir_x = 1;// x = 0 , y == 1 -> x = -1 y = 0
        game->player.dir_y = 0;
    }
    else if (c == 'W') {
        game->player.dir_x = -1;
        game->player.dir_y = 0;
    }
    game->player.plane_x = -game->player.dir_y * 0.66;
    game->player.plane_y = game->player.dir_x * 0.66;
    
    game->player.x += 0.5;
    game->player.y += 0.5;
}
