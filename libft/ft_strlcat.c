/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asubrama <asubrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 11:06:46 by asubrama          #+#    #+#             */
/*   Updated: 2019/11/09 07:40:32 by asubrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	return total lenght of the string initial length of dst plus whatever 
**	was appended from src
*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t k;
	size_t i;

	i = 0;
	k = 0;
	while (dst[i] && dst[i] != '\0' && i < size)
		i++;
	while ((src[k]) && ((k + i + 1) < size))
	{
		dst[i + k] = src[k];
		k++;
	}
	if (i != size)
		dst[i + k] = '\0';
	return (i + ft_strlen(src));
}
