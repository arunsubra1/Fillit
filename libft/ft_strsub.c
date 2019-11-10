/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asubrama <asubrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 23:07:44 by asubrama          #+#    #+#             */
/*   Updated: 2019/11/10 00:57:48 by asubrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	create new null terminated string size of len set the new string
**	equal to the start parameter and copy contents up to len bytes.
**	return new string.
*/

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (s && (str = ft_strnew(len)))
	{
		i = 0;
		while (i < len)
		{
			str[i] = s[i + start];
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
