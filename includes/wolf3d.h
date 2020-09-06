/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 16:38:47 by gweasley          #+#    #+#             */
/*   Updated: 2020/09/06 16:38:55 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include "get_next_line.h"
# include <mlx.h>
# include <math.h>
# define WIDTH 800

typedef struct          s_map
{
    void				*mlx;
	void				*win;
	void				*img;
    int					*pix_m;
	int					bits_per_pixel;
	int					size_line;
	int					endian;
    int                 width;
    int                 height;
    int                 player_x;
    int                 player_y;
    int                 **field;
}                       t_map;

void            print_map(t_map *map);
int             deal_hook(int key, t_map *param);
void            create_mlx_image(t_map *map);
int             fill_map(char *filename, t_map *map);
void            str_file_count(char *filename, t_map *c);
#endif
