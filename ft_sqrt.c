/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 22:49:56 by jmoucach          #+#    #+#             */
/*   Updated: 2018/12/05 15:08:19 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_sqrt(int nb)
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

int main(int ac, char **av)
{
	(void)ac;
	printf("%i", ft_sqrt(atoi(av[1])));
	return (0);
}
