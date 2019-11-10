/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asubrama <asubrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 20:05:49 by asubrama          #+#    #+#             */
/*   Updated: 2019/11/09 08:20:34 by asubrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	counts block of characters delimited by int c (counts words)
*/

int	ft_wordcount(char const *s, int c)
{
	int i;
	int numwrds;

	i = 0;
	numwrds = 0;
	if (s[i] != c)
		numwrds++;
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c)
			numwrds++;
		i++;
	}
	return (numwrds);
}
