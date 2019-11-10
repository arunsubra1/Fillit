/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asubrama <asubrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 16:38:53 by asubrama          #+#    #+#             */
/*   Updated: 2019/11/09 08:34:17 by asubrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	splits the strings int an array of strings seperated by char c,
**	iterate k to spell out the word, k to iterate through a string,
**	and i to look for char c and as index start for strsub
*/

char	**ft_strsplit(char const *s, char c)
{
	int				i;
	int				j;
	int				k;
	char			**t;

	i = 0;
	j = 0;
	k = 0;
	if (!s)
		return (NULL);
	if (!(t = (char **)ft_memalloc(sizeof(char *) * (ft_wordcount(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		if (s[i] != c && s[i])
		{
			while (s[i + k] != c && s[i + k])
				k++;
			t[j++] = ft_strsub(s, i, k);
			i += k - 1;
			k = '\0';
		}
		i++;
	}
	return (t);
}
