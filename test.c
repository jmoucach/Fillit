/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 13:45:20 by jmoucach          #+#    #+#             */
/*   Updated: 2018/12/07 17:21:45 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
void     place_piece(char ***map, char *pattern, char *pos)
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
			            if ((i == 3 || i == 2) && pattern[i] != '.' && pattern [i - 1] == '.')
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
    return (1);
}

int     is_placable(char **map, int map_size, char *pattern, char *pos)
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
			if ((i == 3 || i == 2) && pattern[i] != '.' && pattern [i - 1] == '.')
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

char **piece_placer(char *str, char **map, int map_size)
{
	int i;
	int j;
	char pos[3];
	int ret;

	pos[2] = '\0';
	i = 0;
	j = 0;

	while (j < map_size)
	{
		i = 0;
		while (i < map_size)
		{
			pos[0] = i + 48;
			pos[1] = j + 48;
			if ((ret = is_placable(map,  map_size, str, pos)) == 1)
			{
				place_piece(&map, str, pos);
				break ;
			}
			i++;
		}
		if (ret == 1)
				break;
		j++;
	}
	return (map);
}


