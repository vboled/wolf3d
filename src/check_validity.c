/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 16:38:16 by gweasley          #+#    #+#             */
/*   Updated: 2020/09/06 16:38:18 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		word_count(char *s, char c)
{
	int i;

	i = 0;
	if (*s == '\0')
		return (1);
	while (*s != '\0')
	{
		while (*s == c)
			++s;
		if (*s != '\0')
		{
			++i;
			while (*s != c && *s != '\0')
				++s;
		}
	}
	if (i == 0)
		return (1);
	return (i);
}

int		is_suitable(char *line, int *num_of_point)
{
	int		num;

	num = word_count(line, ' ');
	if (*num_of_point == -2)
		*num_of_point = num;
	else if (*num_of_point != num)
		return (0);
	while (*line)
	{
		if (!(*line >= '0' && *line <= '9')
		&& *line != ' ' && *line != '\n' && *line != '-')
			return (0);
		line++;
	}
	return (1);
}

void	str_file_count(char *filename, t_map *c)
{
	int		fd;
	int		ret;
	char	*line;

	fd = open(filename, O_RDONLY);
	c->width = -2;
	c->height = 0;
	while (1)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1 || (ret && !is_suitable(line, (&c->width))))
		{
			c->height = -1;
			close(fd);
			return ;
		}
		if (!ret)
		{
			free(line);
			close(fd);
			return ;
		}
		(c->height)++;
		free(line);
	}
}
