/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asubrama <asubrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 00:32:23 by asubrama          #+#    #+#             */
/*   Updated: 2019/11/09 01:57:17 by asubrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	The parse function takes a file and reads through it and converts it
**	into a string (buff). we give buff a limit of 545 becuase the max
**	file size is 544 and we + 1 to account for the nullterminator.
**	If the file is the appropriate size we call a validator function
**	and if the string is valid we return the list of tetriminos we
**	created with the given file which we store into the buff string.
*/

t_piece			*parse(char *file)
{
	char		buff[545];
	int			fd;
	int			bytes;

	fd = open(file, O_RDONLY);
	bytes = read(fd, buff, 545);
	close(fd);
	if (bytes > 544 || bytes < 19)
		return (NULL);
	buff[bytes] = '\0';
	if (!valid(buff, bytes))
		return (NULL);
	return (tetlist(buff, bytes));
}

/*
**	When the tetlist function is called it takes the string that
**	was just validated and creates a struct for each tetris piece,
**	and these pieces have x and y coordinates and a letter assigned
**	to them in alphabetical order starting from 'A'.
**	In our while loop we assign A to our first piece by calling maketet,
**	and once we make the first piece we exit out of the loop and then
**	iterate through one letter as well as one tetris piece to the next
**	one and we maketet our next tetris piece which correlates to 'B'
**	and so on. Once the conditions of the while loop have been met
**	nullterminate the list and return the start of the linked list.
*/

t_piece			*tetlist(char *buff, int size)
{
	t_piece		*start;
	t_piece		*ongoing;
	int			i;
	char		letter;

	i = 0;
	letter = 'A';
	while (i < size)
	{
		if (letter == 'A')
		{
			start = maketet(buff + i, letter);
			ongoing = start;
		}
		else
		{
			ongoing->next = maketet(buff + i, letter);
			ongoing = ongoing->next;
		}
		letter++;
		i += 21;
	}
	ongoing->next = NULL;
	return (start);
}

/*
**	First we malloc space for the t_piece variable to the size
**	of the struct. then we iterate through the first 19 characters
**	looking for '#'. when it is found we start storing the x and y
**	values for each individual '#' into the piece vairable.
**	Tetcoords can store up to 8 total values which is the given int
**	size. And we alternate x starts at 0 and y starts at 1 and
**	to iterate through each x and y value we iterate the value by 2 to make
**	sure they arent the same i value and it will be x and y respectivly
**	[0][1], [2][3], [4][5], [6][7]. To calculate the x and y values as
**	coordinates we have to get the i value when i = '#' and when it
**	does we store the x value of it by using a ternary operator.
**	If the condition (i >= 5) is met then we do i modulus 5 which returns
**	the remainder of i / 5. else we just return the i value for x.
**	Since we arent using a float we find the y value the '#' by dividing i
**	by 5, ex. if buff[6] = '#' then we do 6/5 and the answer is 1.2 but
**	the decimal place is ignored. Assign this piece a letter and
**	align it by calling the align function.
*/

t_piece			*maketet(char *buff, char letter)
{
	t_piece		*piece;
	int			x;
	int			y;
	int			i;

	x = 0;
	y = 1;
	i = 0;
	if (!(piece = (t_piece*)malloc(sizeof(t_piece))))
		return (NULL);
	while (i < 20)
	{
		if (buff[i] == '#')
		{
			piece->tetcoords[x] = (i >= 5) ? (i % 5) : i;
			piece->tetcoords[y] = i / 5;
			x += 2;
			y += 2;
		}
		i++;
	}
	piece->x_coord = 0;
	piece->y_coord = 0;
	piece->letter = letter;
	return (align(piece));
}

/*
** aligns the piece to the top left of the map
*/

t_piece			*align(t_piece *align_piece)
{
	while (align_piece->tetcoords[0] != 0 &&
			align_piece->tetcoords[2] != 0 &&
			align_piece->tetcoords[4] != 0 &&
			align_piece->tetcoords[6] != 0)
		shift_x(align_piece, -1);
	while (align_piece->tetcoords[1] != 0 &&
			align_piece->tetcoords[3] != 0 &&
			align_piece->tetcoords[5] != 0 &&
			align_piece->tetcoords[7] != 0)
		shift_y(align_piece, -1);
	return (align_piece);
}

/*
**	free the linkedlist of tetriminos
*/

void			free_tetlist(t_piece *list)
{
	t_piece		*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}
