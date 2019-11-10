/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asubrama <asubrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 11:43:57 by asubrama          #+#    #+#             */
/*   Updated: 2019/11/10 02:10:34 by asubrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	trim spaces from begenning and end of string. Create new string to store
**	contents of modified *s. iterate through initial spaces (i). Go to end of
**	string iterate through spaces backwards (j). create new string equal to
**	size of j and copy contents of s + i (initial string + index to start)
**	up to the length of 
*/

char	*ft_strtrim(char const *s)
{
	unsigned int	i;
	unsigned int	j;
	char			*str;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] && ft_isspace(s[i]))
		i++;
	j = ft_strlen(&s[i]);
	while (s[i] && ft_isspace(s[j + i]))
		j--;
	if (!(str = ft_strnew(j)))
		return (NULL);
	ft_strncpy(str, (s + i), j);
	str[i] = '\0';
	return (str);
}
