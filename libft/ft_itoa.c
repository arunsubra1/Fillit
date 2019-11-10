/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asubrama <asubrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 21:49:29 by asubrama          #+#    #+#             */
/*   Updated: 2019/11/09 05:29:54 by asubrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	allocate memory for fresh string which whill hold the converted
**	int to ascii. hard code the lowest possible value. if int is
**	negative we set string to '-' and call the negative value into
**	itoa again and pass it as a positive and join the positive return
**	value with the negative to create a negative number.
**	if the value is higher than double digits we strjoin the 
**	whole number of n/10 and n%10 to recreate the int as an ascii value.
**	if number is less than 10 just store itself. return str
*/

char	*ft_itoa(int n)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	if (n == -2147483648)
		return (ft_strcpy(str, "-2147483648"));
	if (n < 0)
	{
		str[0] = '-';
		str[1] = '\0';
		str = ft_strjoin(str, ft_itoa(-n));
	}
	else if (n >= 10)
		str = ft_strjoin(ft_itoa(n / 10), ft_itoa(n % 10));
	else if (n < 10 && n >= 0)
	{
		str[0] = n + '0';
		str[1] = '\0';
	}
	return (str);
}
