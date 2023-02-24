/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 00:34:07 by mleonard          #+#    #+#             */
/*   Updated: 2023/02/24 00:34:31 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_list	*get_greatest_idx_node(t_list *stack)
{
	t_list	*cur_node;
	size_t	cur_index;
	t_list	*greatest_node;

	cur_node = stack;
	greatest_node = stack;
	while (cur_node)
	{
		cur_index = get_stack_el(cur_node)->index;
		if (cur_index > get_stack_el(greatest_node)->index)
			greatest_node = cur_node;
		cur_node = cur_node->next;
	}
	return (greatest_node);
}

t_list	*get_smallest_idx_node(t_list *stack)
{
	t_list	*cur_node;
	size_t	cur_index;
	t_list	*smallest_node;

	cur_node = stack;
	smallest_node = stack;
	while (cur_node)
	{
		cur_index = get_stack_el(cur_node)->index;
		if (cur_index < get_stack_el(smallest_node)->index)
			smallest_node = cur_node;
		cur_node = cur_node->next;
	}
	return (smallest_node);
}
