/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/04 17:11:01 by zcarde            #+#    #+#             */
/*   Updated: 2015/11/06 12:37:25 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# define BUFF_SIZE	1024

typedef struct	s_square
{
	int			l_pos;
	int			c_pos;
	int			size;
}				t_square;

typedef struct	s_map
{
	int			nb_lines;
	int			nb_col;
	char		empty;
	char		obs;
	char		full;
	t_square	square;
	char		**map;
}				t_map;

void	ft_putchar(char c);
void	ft_putstr(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
int		ft_atoi(char *str);
void	ft_putnbr(int n);
char	*ft_strsub(char *s, unsigned int start, size_t len);

void	exit_error(char *error);
void	print_error(char *file, char *error);
void	check_errors(char *str, t_map *map);

void	get_map_square(t_map *map);

t_map	*read_from_fd(int fd);
t_map	*read_from_file(char *file);

int		get_map(char *str, t_map *map);
void	free_map(t_map *map);

int		check_nb_lines(char *str, t_map *map);
int		get_nb_lines(char *str, t_map *map);

void	print_map(t_map *map);

int		check_map_chars(t_map *map);
void	get_map_chars(char *str, t_map *map);

#endif