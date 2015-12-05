/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 12:31:40 by zcarde            #+#    #+#             */
/*   Updated: 2015/11/06 12:39:37 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void		free_map(t_map *map)
{
	int		x;

	if (!map)
		return ;
	x = 0;
	while (x < map->nb_lines)
	{
		free(map->map[x]);
		x++;
	}
	free(map->map);
	free(map);
}

static int	malloc_map(char *str, t_map *map)
{
	int		i;

	i = 0;
	while (str[i] != '\n')
		i++;
	map->nb_col = i;
	map->map = (char **)malloc(sizeof(char *) * map->nb_lines);
	if (!map->map)
		return (0);
	i = 0;
	while (i < map->nb_lines)
	{
		map->map[i] = (char *)malloc(sizeof(char) * map->nb_col);
		if (!map->map[i])
			return (0);
		i++;
	}
	return (1);
}

static int	fill_map(char *str, t_map *map)
{
	int	x;
	int	y;
	int	i;

	i = -1;
	x = 0;
	y = 0;
	while (str[++i] && x < map->nb_lines)
	{
		if (str[i] == map->empty)
			map->map[x][y] = map->empty;
		else if (str[i] == map->obs)
			map->map[x][y] = map->obs;
		else if (str[i] == '\n')
		{
			y = -1;
			x++;
		}
		else
			return (0);
		if ((y >= map->nb_col || x >= map->nb_lines) && str[i] != '\n')
			return (0);
		y++;
	}
	return (1);
}

int			get_map(char *str, t_map *map)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (malloc_map(str + i + 1, map) == 0)
		return (0);
	if (fill_map(str + i + 1, map) == 0)
		return (0);
	return (1);
}
