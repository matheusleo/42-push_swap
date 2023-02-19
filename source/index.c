/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 11:16:55 by mleonard          #+#    #+#             */
/*   Updated: 2023/02/19 17:01:11 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static t_list	*stackfind_idx(t_list *stack, size_t idx)
{
	t_list		*cur_node;
	t_stack_el	*aux;

	cur_node = stack;
	while (cur_node)
	{
		aux = cur_node->content;
		if (aux->index == idx)
			return (cur_node);
		cur_node = cur_node->next;
	}
	return (NULL);
}

static t_list	*get_smallest_no_idx(t_list *stack)
{
	t_list		*node_cur;
	t_list		*smallest;
	t_stack_el	*node_content;
	t_stack_el	*smallest_content;

	node_cur = stack;
	smallest = node_cur;
	while (smallest && ((t_stack_el *)smallest->content)->index)
		smallest = smallest->next;
	if (!smallest)
		return (NULL);
	while (node_cur)
	{
		node_content = node_cur->content;
		smallest_content = smallest->content;
		if (node_content->value < smallest_content->value \
			&& !node_content->index)
			smallest = node_cur;
		node_cur = node_cur->next;
	}
	return (smallest);
}

static int	is_all_indexed(t_list *stack)
{
	t_stack_el	*aux;
	t_list		*cur_node;

	cur_node = stack;
	while (cur_node)
	{
		aux = cur_node->content;
		if (aux->index < 1)
			return (FALSE);
		cur_node = cur_node->next;
	}
	return (TRUE);
}

t_list	*set_indexes(t_list **stack)
{
	size_t	cur_idx;
	t_list	*aux;

	cur_idx = 1;
	while (!is_all_indexed(*stack))
	{
		aux = get_smallest_no_idx(*stack);
		if (!aux)
			return (NULL);
		((t_stack_el *)aux->content)->index = cur_idx;
		cur_idx++;
	}
	return (*stack);
}
