/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:37:35 by jmoucach          #+#    #+#             */
/*   Updated: 2018/12/07 17:51:47 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	place_piece(char ***map, char *pattern, char *pos)
{
	int x;
	int y;
	int x_ref;
	int y_ref;
	int i;

	i = 0;
	x_ref = pos[0] - 48;
	y_ref = pos[1] - 48;
	while (pattern[i])
	{
		if (pattern[i] != '.')
		{
			y = y_ref + i / 4;
			x = x_ref + i % 4;
			if ((i == 3 || i == 2) && pattern[i] != '.' && pattern[i - 1] == '.')
			{
				y = y_ref + 1;
				x = x_ref + (i - 4);
			}
			if (y == y_ref + 1)
			{
				y_ref = y;
				x_ref = x;
				pattern = pattern + i;
				i = 0;
			}
			(*map)[x][y] = pattern[i];
		}
		i++;
	}
}

int		is_placable(char **map, int map_size, char *pattern, char *pos)
{
	int x;
	int y;
	int x_ref;
	int y_ref;
	int i;

	i = 0;
	x_ref = pos[0] - 48;
	y_ref = pos[1] - 48;
	while (pattern[i])
	{
		if (pattern[i] != '.')
		{
			y = y_ref + i / 4;
			x = x_ref + i % 4;
			if ((i == 3 || i == 2) && pattern[i] != '.' && pattern[i - 1] == '.')
			{
				y = y_ref + 1;
				x = x_ref + (i - 4);
			}
			if (y == y_ref + 1)
			{
				y_ref = y;
				x_ref = x;
				pattern = pattern + i;
				i = 0;
			}
			if (x < 0 || x > map_size - 1 || y > map_size - 1 || map[x][y] != '.')
				return (0);
		}
		i++;
	}
	return (1);
}

void	ft_free_map(char ***map)
{
	int x;
	
	x = 0;
	while ((*map)[x])
	{
		ft_strdel(&((*map)[x]));
		x++;
	}
	free(*map);
	*map = NULL;
}
int		backtrack(int map_size, char **map, t_triminoes *piece)
{
	int i;
	int j;
	char pos[3];
	char **new_map;

	j = 0;
	if (!piece)
	{
		ft_print_map(map, map_size);
		return (1);
	}
	pos[2] = '\0';
	while (j < map_size)
	{
		i = 0;
		while (i < map_size)
		{
			pos[0] = i + 48;
			pos[1] = j + 48;
			if (is_placable(map,  map_size, piece->tetriminoes, pos))
			{
				new_map	= place_piece(&map, piece->tetrminoes, pos);
				if (backtrack(map_size, map, piece->next))
					return (1);
				ft_free_map(&map)
			}
			i++;
		}
		j++;
	}
	return (0);
}
