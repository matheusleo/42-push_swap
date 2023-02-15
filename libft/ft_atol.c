/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 01:51:15 by mleonard          #+#    #+#             */
/*   Updated: 2023/02/15 02:04:40 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	jump_spaces(const char *nptr)
{
	size_t	offset;

	offset = 0;
	while (('\t' <= nptr[offset] && nptr[offset] <= '\r') \
						|| nptr[offset] == ' ')
		offset++;
	return (offset);
}

long int	ft_atol(const char *nptr)
{
	long int	res;
	long int	sign;
	size_t		index;

	res = 0;
	sign = 0;
	index = jump_spaces(nptr);
	if (ft_strncmp(nptr, "-9223372036854775808", 11) == 0)
		return (MIN_LONG);
	while (nptr[index] == '-' || nptr[index] == '+')
	{
		if (sign != 0)
			return (0);
		if (nptr[index] == '-')
			sign = -1;
		if (nptr[index] == '+')
			sign = 1;
		index++;
	}
	while ('0' <= nptr[index] && nptr[index] <= '9')
		res = (res * 10) + (nptr[index++] - '0');
	if (sign == 0)
		return (res);
	return (res * sign);
}
