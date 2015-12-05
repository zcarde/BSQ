/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 12:23:25 by zcarde            #+#    #+#             */
/*   Updated: 2015/11/06 12:39:50 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static void	init_square(t_square *square)
{
	square->l_pos = -1;
	square->c_pos = -1;
	square->size = 0;
}

static int	check_square(int size, t_map *map, int l, int c)
{
	int		x;
	int		y;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (map->map[l + y][c + x] == map->obs)
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

static void	get_max_square(t_map *map, int l, int c)
{
	int			size;

	size = map->square.size;
	while (size <= map->nb_lines - l && size <= map->nb_col - c)
	{
		if (check_square(size, map, l, c))
		{
			if (size > map->square.size)
			{
				map->square.size = size;
				map->square.l_pos = l;
				map->square.c_pos = c;
			}
		}
		else
			break ;
		size++;
	}
}

static void	fill_max_square(t_map *map)
{
	int		c;
	int		l;

	l = 0;
	while (l < map->square.size)
	{
		c = 0;
		while (c < map->square.size)
		{
			map->map[l + map->square.l_pos][c + map->square.c_pos] = map->full;
			c++;
		}
		l++;
	}
}

void		get_map_square(t_map *map)
{
	int			l;
	int			c;

	if (!map)
		return ;
	l = 0;
	init_square(&map->square);
	while (l < map->nb_lines - map->square.size)
	{
		c = 0;
		while (c < map->nb_col - map->square.size)
		{
			get_max_square(map, l, c);
			c++;
		}
		l++;
	}
	fill_max_square(map);
}
