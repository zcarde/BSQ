/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 12:21:12 by zcarde            #+#    #+#             */
/*   Updated: 2015/11/06 12:37:13 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	check_errors(char *str, t_map *map)
{
	if (!map && str)
		print_error(str, "Map error");
	else if (!map)
		print_error(NULL, "Map error");
}

void	print_error(char *file, char *error)
{
	if (file)
	{
		ft_putstr(file);
		ft_putstr(" : ");
	}
	ft_putstr(error);
	ft_putstr("\n");
}

void	exit_error(char *error)
{
	print_error(NULL, error);
	exit(1);
}
