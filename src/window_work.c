/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_work.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 17:03:01 by gweasley          #+#    #+#             */
/*   Updated: 2020/09/06 17:03:03 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

void	create_mlx_image(t_map *map)
{
	map->pix_m = (int *)mlx_get_data_addr(map->img,
	&(map->bits_per_pixel), &(map->size_line), &(map->endian));
	mlx_clear_window(map->mlx, map->win);
	mlx_put_image_to_window(map->mlx, map->win, map->img, 400, 50);
}

void    change_player_pos(t_map *map, int key){
    if (key == 126 && map->player_y > 0 &&
        map->field[map->player_y - 1][map->player_x] == 0)
        map->player_y--;
    if (key == 125 && map->player_y < map->height &&
        map->field[map->player_y + 1][map->player_x] == 0)
        map->player_y++;
    if (key == 123 && map->player_x > 0 &&
        map->field[map->player_y][map->player_x - 1] == 0)
        map->player_x--;
    if (key == 124 && map->player_x < map->width &&
        map->field[map->player_y][map->player_x + 1] == 0)
        map->player_x++;
}

int		deal_hook(int key, t_map *param)
{
	if (key == 53){
		write(1, "EXIT\n", 5);
	    exit(0);
    }
    if (key >= 123 && key <= 126)
        change_player_pos(param, key);
    print_map(param);
	return (0);
}