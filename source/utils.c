/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 23:01:04 by mleonard          #+#    #+#             */
/*   Updated: 2023/02/24 00:33:59 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_lstclear_nodes(t_list **list)
{
	t_list	*cur_node;
	t_list	*next_node;

	cur_node = *list;
	next_node = (*list)->next;
	while (cur_node)
	{
		free(cur_node);
		cur_node = next_node;
		if (cur_node)
			next_node = cur_node->next;
	}
}

size_t	get_abs(int nb)
{
	size_t	abs;

	if (nb < 0)
		abs = nb * -1;
	else
		abs = nb;
	return (abs);
}
