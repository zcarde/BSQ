/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 12:38:54 by zcarde            #+#    #+#             */
/*   Updated: 2015/11/06 12:38:57 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		main(int ac, char **av)
{
	t_map	*map;
	int		i;

	i = 1;
	if (ac == 1)
	{
		map = read_from_fd(0);
		check_errors(NULL, map);
		get_map_square(map);
		print_map(map);
		free_map(map);
	}
	else
	{
		while (i < ac)
		{
			map = read_from_file(av[i]);
			get_map_square(map);
			print_map(map);
			free_map(map);
			i++;
		}
	}
	return (0);
}
