/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_chars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 12:22:41 by zcarde            #+#    #+#             */
/*   Updated: 2015/11/06 12:23:07 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		check_map_chars(t_map *map)
{
	if (map->empty == map->obs || map->empty == map->full)
		return (0);
	if (map->obs == map->full)
		return (0);
	return (1);
}

void	get_map_chars(char *str, t_map *map)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	map->empty = str[i - 3];
	map->obs = str[i - 2];
	map->full = str[i - 1];
}
