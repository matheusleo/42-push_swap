/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:32:56 by mleonard          #+#    #+#             */
/*   Updated: 2023/02/15 01:13:33 by mleonard         ###   ########.fr       */
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

int	find_nb_in_stack(t_list *stack, int nb)
{
	t_list		*node_cur;
	int			stack_val;
	t_stack_el	*aux;

	node_cur = stack;
	while (node_cur)
	{
		aux = node_cur->content;
		stack_val = aux->value;
		if (stack_val == nb)
			return (FOUND);
		node_cur = node_cur->next;
	}
	return (NOT_FOUND);
}
