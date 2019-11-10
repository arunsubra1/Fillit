/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asubrama <asubrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 03:26:51 by asubrama          #+#    #+#             */
/*   Updated: 2019/11/09 00:29:25 by asubrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				main(int ac, char **av)
{
	t_piece		*tetlist;

	if (ac != 2)
	{
		ft_putstr("error\n");
		return (1);
	}
	if ((tetlist = parse(av[1])) == NULL)
	{
		ft_putstr("error\n");
		return (1);
	}
	solve(tetlist);
	free_tetlist(tetlist);
	return (0);
}
