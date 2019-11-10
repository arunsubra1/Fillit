/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asubrama <asubrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 12:59:58 by asubrama          #+#    #+#             */
/*   Updated: 2019/11/10 00:49:54 by asubrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	locates first occurrence of nullterminated string s2 in s1 while searching
**	less than len amt of bytes.
*/

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t i;

	if (!*s2)
		return ((char *)s1);
	i = ft_strlen(s2);
	while (*s1 != '\0' && i <= len)
	{
		if (ft_strncmp(s1, s2, i) == 0)
			return ((char *)s1);
		s1++;
		len--;
	}
	return (NULL);
}
