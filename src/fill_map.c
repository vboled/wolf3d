/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 16:38:04 by gweasley          #+#    #+#             */
/*   Updated: 2020/09/06 16:38:06 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			**map_alloc(int width, int height)
{
	int			i;
	int			j;
	int		**map;

	i = 0;
	j = 0;
	if (!(map = (int **)malloc(sizeof(int *) * width)))
		return (0);
	while (i < height)
	{
		if (!(map[i] = (int *)malloc(sizeof(int) * height)))
		{
			while (j < i)
			{
				free(map[j]);
				j++;
			}
			free(map);
			return (0);
		}
		i++;
	}
	return (map);
}

int     put_in_points(int *map_line, char *line, t_map *c)
{
	int		i;
    int     player_placer;

	i = 0;
    player_placer = 0;
	while (i < c->width)
	{
		*map_line = ft_atoi(line);
        if (*map_line  == -1){
            c->player_x = i;
            *map_line = 0;
            player_placer = 1;
        }
		while (*line && *line != ' ')
			line++;
		while (*line == ' ')
			line++;
		map_line++;
		i++;
	}
    return (player_placer);
}

int     fill_map(char *filename, t_map *map){
    int			i;
	char		*line;
	int			fd;

    map->field = map_alloc(map->width, map->height);
    if (!map->field)
        return (0);
    fd = open(filename, O_RDONLY);
	i = 0;
	while (i < map->height)
	{
		if (get_next_line(fd, &line) == -1)
		{
			close(fd);
			return (0);
		}
		if (put_in_points(map->field[i], line, map))
            map->player_y = i;
		free(line);
		i++;
	}
	close(fd);
	return (1);
}
