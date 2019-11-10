/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asubrama <asubrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 00:19:44 by asubrama          #+#    #+#             */
/*   Updated: 2019/11/09 00:40:28 by asubrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

/*
**	create a struct of each piece and assign it 4 'x' coordinates
**	and 4 'y' coordinates which will be stored in tetcoords correponding
**	with the location of the '#'. *next points to the next item in the list.
**	call it by using t_piece instead of s_piece
*/

typedef struct			s_piece
{
	int					tetcoords[8];
	char				letter;
	int					x_coord;
	int					y_coord;
	struct s_piece		*next;
}						t_piece;

typedef struct			s_map
{
	char				**map_array;
}						t_map;

/*
**	validator
*/

int						hashcheck(char *str);
int						connect_checker(char *str);
int						valid(char *str, int size);

/*
**	shifter
*/

void					shift_x(t_piece *piece, int n);
void					shift_y(t_piece *piece, int n);

/*
**	parsing
*/

t_piece					*tetlist(char *buff, int size);
t_piece					*maketet(char *buff, char letter);
t_piece					*align(t_piece *align_piece);
t_piece					*parse(char *file);
void					free_tetlist(t_piece *list);

/*
** Map creation
*/

void					print_map(t_map *map, int size);
t_map					*new_map(int size);
int						round_up(int i);
size_t					count_tets(t_piece *tetlist);
void					free_map(t_map *map, int size);

/*
**	solver recursion
*/

int						solve_rec(t_map *map, t_piece *piece, int size);
int						inbounds(t_piece *piece, int size, char axis);
int						overlap(t_map *map, t_piece *piece);
void					place(t_piece *piece, t_map *map, char letter);
void					solve(t_piece *tetlist);

/*
**	main
*/

int						main(int ac, char **av);

#endif
