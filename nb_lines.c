/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_lines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 12:32:50 by zcarde            #+#    #+#             */
/*   Updated: 2015/11/06 12:32:58 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		get_nb_lines(char *str, t_map *map)
{
	char	*nb_lines;
	int		i;

	if (str && (str[0] < '0' || str[0] > '9'))
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	nb_lines = ft_strsub(str, 0, i - 3);
	map->nb_lines = ft_atoi(nb_lines);
	free(nb_lines);
	return (map->nb_lines);
}

int		check_nb_lines(char *str, t_map *map)
{
	int		i;
	int		lines;
	int		col;

	i = 0;
	col = 0;
	lines = 0;
	while (str[i] && str[i] != '\n')
		i++;
	while (str[++i] && ++col && !(str[i] == '\n' && str[i - 1] != map->empty
			&& str[i - 1] != map->obs && str[i - 1] != map->full))
	{
		if (str[i] == '\n' && col - 1 != map->nb_col)
			return (0);
		else if (str[i] == '\n')
		{
			col = 0;
			lines++;
		}
	}
	if (str[i] == '\0' && (str[i - 1] == map->empty || str[i - 1] == map->obs))
		lines++;
	if (lines != map->nb_lines)
		return (0);
	return (1);
}
