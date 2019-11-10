/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asubrama <asubrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 23:19:14 by asubrama          #+#    #+#             */
/*   Updated: 2019/11/09 05:13:10 by asubrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	join 2 strings together regardless if they have contents within them
**	if no content return a fresh string size of 0. if only one string
**	has content we ft_strdup that string. otherwise we get the length of
**	both strings and create a new string with enough memory to hold contents
**	from both strings and copy the first string into the new string and then
**	cat the second string into the copied one. return the new string.
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*str;

	if (!s1 && !s2)
		return ("");
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	return (str);
}
