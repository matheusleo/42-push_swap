/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ternary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:55:26 by mleonard          #+#    #+#             */
/*   Updated: 2022/10/09 17:58:42 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_ternary(int codition, void *return_true, void *return_false)
{
	if (codition)
		return (return_true);
	return (return_false);
}
