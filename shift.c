/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asubrama <asubrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 02:12:28 by asubrama          #+#    #+#             */
/*   Updated: 2019/11/08 23:36:36 by asubrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	shift_x(t_piece *piece, int n)
{
	piece->tetcoords[0] += n;
	piece->tetcoords[2] += n;
	piece->tetcoords[4] += n;
	piece->tetcoords[6] += n;
}

void	shift_y(t_piece *piece, int n)
{
	piece->tetcoords[1] += n;
	piece->tetcoords[3] += n;
	piece->tetcoords[5] += n;
	piece->tetcoords[7] += n;
}
