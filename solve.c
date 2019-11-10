/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asubrama <asubrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 21:44:11 by asubrama          #+#    #+#             */
/*   Updated: 2019/11/09 01:20:03 by asubrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Create a map using the size of the tetlist, then call function
**	to solve the task using recursion and we start with the smallest map
**	size if the pieces dont fit we increase the size till it does.
**	Then print/free the map.
*/

void			solve(t_piece *tetlist)
{
	t_map		*map;
	int			size;

	size = round_up(count_tets(tetlist) * 4);
	map = new_map(size);
	while (!solve_rec(map, tetlist, size))
	{
		free_map(map, size);
		size++;
		map = new_map(size);
	}
	print_map(map, size);
	free_map(map, size);
}

/*
**	Reject anything thats not a piece. then check wether the y coordinates
**	of the '#' are inbounds and then check the x coordinates.
**	Then call the overlap function which checks the x and y coordinates of
**	the '#' while it is still inbounds to see if it is empty and if it is
**	empty then place letter that correlates to the piece then iterate to next
**	piece and if the next piece doesnt fit anywhere then go to previous
**	piece and empty it out and keep iterating to the next spot.
*/

int				solve_rec(t_map *map, t_piece *piece, int size)
{
	if (!piece)
		return (1);
	piece->x_coord = 0;
	piece->y_coord = 0;
	while (inbounds(piece, size, 'y'))
	{
		while (inbounds(piece, size, 'x'))
		{
			if (overlap(map, piece))
			{
				place(piece, map, piece->letter);
				if (solve_rec(map, piece->next, size))
					return (1);
				else
				{
					place(piece, map, '.');
				}
			}
			piece->x_coord++;
		}
		piece->x_coord = 0;
		piece->y_coord++;
	}
	return (0);
}

/*
**	checks if the '#' + x/y counter is within the map size.
*/

int				inbounds(t_piece *piece, int size, char axis)
{
	if (axis == 'y')
		return (piece->tetcoords[1] + piece->y_coord < size &&
				piece->tetcoords[3] + piece->y_coord < size &&
				piece->tetcoords[5] + piece->y_coord < size &&
				piece->tetcoords[7] + piece->y_coord < size);
	else
		return (piece->tetcoords[0] + piece->x_coord < size &&
				piece->tetcoords[2] + piece->x_coord < size &&
				piece->tetcoords[4] + piece->x_coord < size &&
				piece->tetcoords[6] + piece->x_coord < size);
}

/*
**	checks to see if the piece is on an empty spot and if not iterate
**	the x value and then the y till it does in previous function.
*/

int				overlap(t_map *map, t_piece *piece)
{
	int			i;
	int			x;
	int			y;

	i = 0;
	x = 0;
	y = 0;
	x = piece->tetcoords[i] + piece->x_coord;
	y = piece->tetcoords[i + 1] + piece->y_coord;
	while (i <= 6 && map->map_array[y][x] == '.')
	{
		i += 2;
		x = piece->tetcoords[i] + piece->x_coord;
		y = piece->tetcoords[i + 1] + piece->y_coord;
	}
	return (i == 8);
}

/*
**	takes the coordinates of the '#' that has met all the conditions
**	and substitutes it with the character assigned to the piece and
**	places it into our 2D array.
*/

void			place(t_piece *piece, t_map *map, char letter)
{
	int			i;
	int			x;
	int			y;

	i = 0;
	x = 0;
	y = 0;
	while (i <= 6)
	{
		x = piece->tetcoords[i] + piece->x_coord;
		y = piece->tetcoords[i + 1] + piece->y_coord;
		map->map_array[y][x] = letter;
		i += 2;
	}
}
