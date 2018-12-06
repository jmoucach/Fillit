/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:37:35 by jmoucach          #+#    #+#             */
/*   Updated: 2018/12/06 16:15:23 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_chose_place(char *pattern, char **map, int map_size)
{

}

int		backtrack(int map_size, char **map, t_triminoes *piece)
{
	int ret;
	char	**new_map;

	if (!piece)
	{
		ft_print_map(new_map, map_size);
		return (1);
	}
	while ((new_map = ft_chose_place(piece->t_triminoes, map, map_size)))
	{
		if ((ret = ft_backtrack(map_size, new_map, piece->next)) == 1)
			break ;	
		ret = 0;
	}
	return (ret);
}
