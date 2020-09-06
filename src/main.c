/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 16:37:26 by gweasley          #+#    #+#             */
/*   Updated: 2020/09/06 16:37:47 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

void print_map(t_map *map){
    int i;
    int j;

    i = 0;
    while (i < map->height){
        j = 0;
        while (j < map->width){
			if (i == map->player_y && j == map->player_x)
				write(1, "x", 1);
			else if(map->field[i][j] == 0)
				write(1, " ", 1);
            else 
				write(1, "#", 1);
            j++;
        }
        printf("\n");
        i++;
    }

}

int init_mlx(t_map *map){
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, WIDTH + 405, WIDTH + 100, "win1");
	map->img = mlx_new_image(map->mlx, WIDTH, WIDTH);
	return (1);
}

int main(int argc, char **argv){

    t_map map;

    str_file_count(argv[1], &map);
    if (map.height == -1 || !fill_map(argv[1], &map) || !init_mlx(&map))
	{
		write(1, "ERROR\n", 6);
		// free_struct(&map);
		return (0);
	}
	mlx_hook(map.win, 2, 5, deal_hook, &map);
	create_mlx_image(&map);
    print_map(&map);
	mlx_loop(map.mlx);
    argc++;
    return (0);
}
