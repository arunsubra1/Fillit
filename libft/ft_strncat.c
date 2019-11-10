/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asubrama <asubrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 10:36:01 by asubrama          #+#    #+#             */
/*   Updated: 2019/11/09 07:50:55 by asubrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	add s2 to the end of s1 while the total length of the string is
**	less than n
*/

char	*ft_strncat(char *s1, char *s2, size_t n)
{
	size_t i;
	size_t len;

	i = 0;
	while (s1[i] != '\0')
		i++;
	len = 0;
	while (s2[len] && len < n)
	{
		s1[i + len] = s2[len];
		len++;
	}
	s1[i + len] = '\0';
	return (s1);
}
