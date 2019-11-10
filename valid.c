/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asubrama <asubrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 00:39:45 by asubrama          #+#    #+#             */
/*   Updated: 2019/11/09 00:51:01 by asubrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Valid function calls functions connect_checker and hashcheck
**	in a while loop as long as the iterater does not surpass the size.
**	We check to see if hashcheck equals the appropriate amount of '#' and
**	if the connect_checker equals the appropriate amount of adjacencies.
**	if these conditions are met iterate to the next block of string (i += 21)
*/

int				valid(char *str, int size)
{
	int			i;

	i = 0;
	while (i <= size)
	{
		if (hashcheck(str + i) != 4)
			return (0);
		if (connect_checker(str + i) != 6 && connect_checker(str + i) != 8)
			return (0);
		i += 21;
	}
	return (1);
}

/*
**	connect_checker checks to see if each individual '#' character has an
**	adjacency and we do this by creating a counter integer and
**	while we iterate through the string we (counter += 1) or count++ to count
**	the number of adjacencies. We do this because there are only 2 possible
**	outcomes 6 or 8 to how many adjacencies our given tetrominos
**	can possibly have.
*/

int				connect_checker(char *str)
{
	int			i;
	int			counter;

	i = 0;
	counter = 0;
	while (i < 19)
	{
		if (str[i] == '#')
		{
			if (i + 1 <= 18 && str[i + 1] == '#')
				counter++;
			if (i - 1 >= 0 && str[i - 1] == '#')
				counter++;
			if (i + 5 <= 18 && str[i + 5] == '#')
				counter++;
			if (i - 5 >= 0 && str[i - 5] == '#')
				counter++;
		}
		i++;
	}
	return (counter);
}

/*
**	We create a function to check our input file to make sure it meets
**	the correct format and is exactly what we are looking for.
**	First we check to make sure there is a string and the string has a
**	newline character ('\n').
**	Then we create a while loop which loops through the contents of an
**	individual piece, and we check within that block to make sure there
**	are the right characters that we are looking for, and then we
**	check to see while str[i] == newline if we add a 1 to the value
**	of the i and that value modulus 5 is not equal to zero then we return
**	false. Otherwise we iterate through the string and create a counter
**	integer to count all the '#' characters and then return the amount of
**	'#' read.
*/

int				hashcheck(char *str)
{
	int			i;
	int			counter;

	i = 0;
	counter = 0;
	while (i < 19)
	{
		if (str[i] && str[i] != '\n' && str[i] != '.' && str[i] != '#')
			return (0);
		if (str[i] == '\n' && !(((i + 1) % 5) == 0))
			return (0);
		if (str[i] == '#')
			counter++;
		i++;
	}
	if (!str[i] || str[i] != '\n')
		return (0);
	return (counter);
}
