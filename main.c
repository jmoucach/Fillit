/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 13:33:50 by jmoucach          #+#    #+#             */
/*   Updated: 2018/12/06 17:16:32 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdlib.h>
int     ft_sqrt(int nb)
{
	int a;

	a = 0;
	while ((a <= nb / 2) && (a < 46341))
	{
		if (a * a >= nb)
			return (a);
		a++;
	}
	return (0);
}

/*int		ft_link_count(t_triminoes *lst)
{
	int i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
*/
char	**ft_map_maker(int map_size)
{
	char		**map;
	int			i;
	int			x;
	int			y;

	x = 0;
	i = 0;
	if (!(map = (char **)malloc(sizeof(*map) * (map_size + 1))))
		return (NULL);
	while (i < map_size)
	{
		if (!(map[i] = (char*)malloc(sizeof(**map) * (map_size + 1))))
			return (NULL);
		i++;
	}
	while (x < map_size)
	{
		y = 0;
		while (y < map_size)
		{
			map[x][y] = '.';
			y++;
		}
		map[x][y] = '\0';
		x++;
	}
	map[x] = 0;
	return (map);
}

void	ft_print_map(char **map, int map_size)
{
	int i;
	int j;
	
	j = 0;
	while (j < map_size)
	{
		i = 0;
		while (i < map_size)
		{
			ft_putchar(map[i][j]);
			i++;
		}
		ft_putchar('\n');
		j++;
	}
	return ;
}

int		main(int ac, char **av)
{
	int 		map_size;
//	t_triminoes	*piece;
	char		**map;

	(void)ac;

	if (ac == 2)
	{
		map_size = ft_sqrt(atoi(av[1]) * 4);
		map = ft_map_maker(map_size);
		while (backtrack(map_size, map, piece))
		{
			free(map);
			map_size++;
			map = ft_map_maker(map_size);
		}
		map[1][4] = 'a';
		ft_print_map(map, map_size);
	}
	else
		ft_putendl("usage: ./fillit target_file");
	return (0);
}
