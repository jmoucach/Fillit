/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:37:35 by jmoucach          #+#    #+#             */
/*   Updated: 2018/12/14 11:51:46 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
}

int		backtrack(int map_size, char **map, t_trimino *piece)
{
	t_coord	pos;

	if (!piece)
	{
		ft_print_map(map, map_size);
		return (1);
	}
	pos.y_ref = -1;
	while (++(pos.y_ref) < map_size)
	{
		pos.x_ref = -1;
		while (++(pos.x_ref) < map_size)
		{
			if (is_placable(map,  map_size, piece->pattern, pos))
			{
				place_piece(&map, piece->pattern, pos);
				if (backtrack(map_size, map, piece->next) == 1)
					return (1);
				remove_piece(&map, piece->pattern, pos);
			}
		}
	}
	return (0);
}
