/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asubrama <asubrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 16:40:53 by asubrama          #+#    #+#             */
/*   Updated: 2019/11/09 03:49:03 by asubrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	In this function we turn an ascii value character to an integer.
**	We iterate through special characters declared in ft_isspace.
**	if there is a '-' sign we multiply by '-1' to turn it into negative.
**	then we check the character while it is a number we take the first nbr
**	and subtracts from '0' to get itself and if the nbr goes into the tens
**	and hundreds place we multiply the first number we create by 10 to add
**	a decimal place then add the following number then multiply the sum of
**	the first 2 numbers by 10 and then add the 3rd number and repeat till
**	the number is too large or there are no more characters to convert
*/

int	ft_atoi(const char *str)
{
	int			i;
	long long	nbr;
	int			sign;

	i = 0;
	sign = 1;
	nbr = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}
	return (nbr * sign);
}
