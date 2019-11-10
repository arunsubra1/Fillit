/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asubrama <asubrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 03:59:41 by asubrama          #+#    #+#             */
/*   Updated: 2019/11/09 01:18:21 by asubrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Round up to the nearest whole number to get size of the map.
**	If the number of blocks require a grid that is not a whole number we
**	want to round the number up to create a square where the pieces will fit.
*/

int				round_up(int i)
{
	int			size;

	size = 2;
	while (size * size < i)
		size++;
	return (size);
}

/*
**	Allocate memory for map, allocate memory for 2D array in map.
**	Each individual i value is a row the length of size and we add '\n' to
**	it with ft_strnew. then set everything to '.'
*/

t_map			*new_map(int size)
{
	t_map		*map;
	int			i;

	map = (t_map*)ft_memalloc(sizeof(t_map));
	map->map_array = (char**)ft_memalloc(sizeof(char*) * size);
	i = 0;
	while (i < size)
	{
		map->map_array[i] = ft_strnew(size);
		ft_memset(map->map_array[i], '.', size);
		i++;
	}
	return (map);
}

/*
**	counts the amount of tetriminos in the given list.
*/

size_t			count_tets(t_piece *tetlist)
{
	size_t		counter;

	counter = 0;
	while (tetlist)
	{
		tetlist = tetlist->next;
		counter++;
	}
	return (counter);
}

/*
**	prints map one row at a time
*/

void			print_map(t_map *map, int size)
{
	int			i;

	i = 0;
	while (i < size)
	{
		ft_putstr(map->map_array[i]);
		ft_putchar('\n');
		i++;
	}
}

/*
**	frees map
*/

void			free_map(t_map *map, int size)
{
	int			i;

	i = 0;
	while (i < size)
	{
		ft_memdel((void **)&(map->map_array[i]));
		i++;
	}
	ft_memdel((void **)&(map->map_array));
	ft_memdel((void **)&map);
}
