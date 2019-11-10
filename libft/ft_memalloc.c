/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asubrama <asubrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 12:42:54 by asubrama          #+#    #+#             */
/*   Updated: 2019/11/09 06:36:22 by asubrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	allocate memory into void variable with given size. set content to 0.
*/

void	*ft_memalloc(size_t size)
{
	void	*m;

	if (size <= 0)
		return (NULL);
	m = malloc(size);
	if (!m)
		return (NULL);
	ft_bzero(m, size);
	if (m)
		return (m);
	else
		return (NULL);
}
