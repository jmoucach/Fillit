/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 12:32:54 by fgaribot          #+#    #+#             */
/*   Updated: 2018/12/14 13:47:58 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		add_tetrimino(char *str, t_trimino **alst)
{
	t_trimino		*new;
	char			*tmp;
	t_trimino		*first;

	first = *alst;
	if (!(new = malloc(sizeof(t_trimino))))
	{
		ft_putstr("Error");
		exit(EXIT_FAILURE);
	}
	new->next = NULL;
	if (!(tmp = ft_strdup(str)))
	{
		ft_putstr("Error");
		exit(EXIT_FAILURE);
	}
	new->pattern = tmp;
	if ((*alst)->pattern == NULL)
	{
		*alst = new;
		return ;
	}
	while ((*alst)->next != NULL)
		(*alst) = (*alst)->next;
	(*alst)->next = new;
//	ft_strdel(&str);
	*alst = first;
}

int			ft_test_tetriminoes(char *piece, int i)
{
	char			*test[19];

	test[0] = "###...#";
	test[1] = "###..#";
	test[2] = "###.#";
	test[3] = "##.##";
	test[4] = "####";
	test[5] = "##..##";
	test[6] = "##...##";
	test[7] = "#...#..##";
	test[8] = "#..##...#";
	test[9] = "##...#...#";
	test[10] = "#...##...#";
	test[11] = "#...#...#...#";
	test[12] = "#..##..#";
	test[13] = "#...###";
	test[14] = "#..###";
	test[15] = "#.###";
	test[16] = "##..#...#";
	test[17] = "#...##..#";
	test[18] = "#...#...##";
	while (i < 19 && ft_strcmp(piece, test[i]) != 0)
		i++;
	return (i >= 19 ? 0 : 1);
}

int			valid_size(int fd, t_trimino **alst)
{
	int				i;
	int				j;
	char			*line;
	char			*candidate_tetrimino;
	char			*tmp;

	i = -1;
	while (get_next_line(fd, &line) == 1 && ++i < 5)
	{
		j = ft_countchar(line, '\n');
		if ((i < 4 && j != 4) || (i == 4 && j != 0))
			return (0);
		if (!(candidate_tetrimino = (i == 0 ? ft_strdup(line) : candidate_tetrimino)))
			return (0);
		if (i != 0 && i < 4)
		{
			if (!(tmp = ft_strjoin(candidate_tetrimino, line)))
				return (0);
			free(candidate_tetrimino);
			candidate_tetrimino = tmp;
		}
		if (i == 3)
		{
			add_tetrimino(candidate_tetrimino, alst);
			free(candidate_tetrimino);
		}
//		i == 3 ? add_tetrimino(candidate_tetrimino, alst) : 1;
//		i == 3 ? free(tmp) : 1;
		i = (i == 4 ? -1 : i);
		free(line);
	}
	return (i == 3 ? 1 : 0);
}

int			ft_neighbour(char *str)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (str[i] == '.' || str[i] == '#')
	{
		if (str[i] == '#')
		{
			j = (i >= 4 && str[i - 4] == '#') ? j + 1 : j;
			j = (i > 0 && str[i - 1] == '#') ? j + 1 : j;
			j = (str[i + 1] == '#') ? j + 1 : j;
			j = (i < 12 && str[i + 4] == '#') ? j + 1 : j;
		}
		i++;
	}
	return (i != 16 || (j != 6 && j != 8) ? 0 : 1);
}

int			valid_tetrimino(t_trimino **lst)
{
	static int		k;
	t_trimino		*first;

	first = *lst;
	while (*lst != NULL)
	{
		if (!ft_neighbour((*lst)->pattern))
			return (0);
		(*lst)->pattern = ft_strtrimc((*lst)->pattern, '.');
		if (!ft_test_tetriminoes((*lst)->pattern, 0))
			return (0);
		ft_replace((*lst)->pattern, '#', k++ + 65);
		*lst = (*lst)->next;
	}
	*lst = first;
	return (1);
}

t_trimino	*tritreminoes(char *av)
{
	int				fd;
	t_trimino		*lst;

	if (!(lst = malloc(sizeof(t_trimino))))
		return (NULL);
	lst->next = NULL;
	lst->pattern = NULL;
	fd = open(av, O_RDONLY);
	if (!(valid_size(fd, &lst)))
	{
		ft_putendl("error");
		exit(EXIT_FAILURE);
	}
	if (!(valid_tetrimino(&lst)))
	{
		ft_putendl("bad tetrimino");
		exit(EXIT_FAILURE);
	}
	return (lst);
}
/*
int			main(int ac, char **av)
{
	t_trimino		*lst;

	(void)ac;
	lst = tritreminoes(av[1]);
	while (lst)
	{
		ft_putendl(lst->pattern);
		lst = lst->next;
	}
}*/
