/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 23:37:01 by mleonard          #+#    #+#             */
/*   Updated: 2022/12/05 23:38:21 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_replace(char *ptr, int c, int pos)
{
	char	*replace;

	replace = ft_strdup(ptr);
	replace[pos] = c;
	return (replace);
}
