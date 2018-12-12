/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 13:45:20 by jmoucach          #+#    #+#             */
/*   Updated: 2018/12/12 13:29:32 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
#include <stdlib.h>

t_coord	case_check(char **pattern, int *i, t_coord pos)
{
	if ((*i % 3 || *i % 2) && (*pattern)[*i] != '.' &&
			(*pattern)[*i - 1] == '.')
	{
		pos.y = pos.y_ref + 1;
		pos.x = pos.x_ref + (*i - 4);
	}
	if (pos.y == pos.y_ref + 1)
	{
		pos.y_ref = pos.y;
		pos.x_ref = pos.x;
		*pattern = *pattern + *i;
		*i = 0;
	}
	return (pos);
}

void	place_piece(char ***map, char *pattern, t_coord pos)
{
	int		i;

	i = 0;
	while (pattern[i])
	{
		if (pattern[i] != '.')
		{
			pos.x = pos.x_ref + i % 4;
			pos.y = pos.y_ref + i / 4;
			pos = case_check(&pattern, &i, pos);
			(*map)[pos.x][pos.y] = pattern[i];
		}
		i++;
	}
}

int		is_placable(char **map, int map_size, char *pattern, t_coord pos)
{
	int		i;

	i = 0;
	while (pattern[i])
	{
		if (pattern[i] != '.')
		{
			pos.x = pos.x_ref + i % 4;
			pos.y = pos.y_ref + i / 4;
			pos = case_check(&pattern, &i, pos);
			if (pos.x < 0 || pos.x > map_size - 1 || pos.y > map_size - 1 ||
					map[pos.x][pos.y] != '.')
				return (0);
		}
		i++;
	}
	return (1);
}

char	**piece_placer(char *str, char **map, int map_size)
{
	t_coord	pos;
	int		ret;

	pos.y_ref = -1;
	while (++(pos.y_ref) < map_size)
	{
		pos.x_ref = -1;
		while (++(pos.x_ref) < map_size)
		{
			if ((ret = is_placable(map, map_size, str, pos)) == 1)
			{
				place_piece(&map, str, pos);
				break ;
			}
		}
		if (ret == 1)
			break ;
	}
	return (map);
}
