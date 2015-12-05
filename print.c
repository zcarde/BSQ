/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 12:30:35 by zcarde            #+#    #+#             */
/*   Updated: 2015/11/06 12:30:45 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	print_map(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	if (!map)
		return ;
	while (x < map->nb_lines)
	{
		y = 0;
		while (y < map->nb_col)
		{
			ft_putchar(map->map[x][y]);
			y++;
		}
		ft_putstr("\n");
		x++;
	}
}
