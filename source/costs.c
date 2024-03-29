/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:56:29 by mleonard          #+#    #+#             */
/*   Updated: 2023/02/24 02:00:27 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	calculate_cost_b(t_list *stack_b)
{
	t_list		*cur_node;
	size_t		stack_size;
	t_stack_el	*cur_el;

	set_pos(&stack_b);
	cur_node = stack_b;
	stack_size = ft_lstsize(stack_b);
	while (cur_node)
	{
		cur_el = cur_node->content;
		if (cur_el->pos <= stack_size / 2)
			cur_el->cost_b = cur_el->pos;
		else
			cur_el->cost_b = cur_el->pos - stack_size;
		cur_node = cur_node->next;
	}
}

static void	calculate_cost_a(t_list *stack_a, t_list *stack_b)
{
	t_list		*node_b;
	size_t		stack_a_size;
	t_stack_el	*el_b;

	node_b = stack_b;
	stack_a_size = ft_lstsize(stack_a);
	while (node_b)
	{
		el_b = get_stack_el(node_b);
		if (el_b->target_pos <= stack_a_size / 2)
			el_b->cost_a = el_b->target_pos;
		else
			el_b->cost_a = el_b->target_pos - stack_a_size;
		node_b = node_b->next;
	}
}

size_t	get_cheapest_move_pos(t_list *stack)
{
	t_list		*cur_node;
	t_stack_el	*cur_el;
	size_t		smallest_cost;
	t_list		*node_smallest_cost;
	size_t		cur_cost;

	cur_node = stack;
	cur_el = cur_node->content;
	smallest_cost = get_abs(cur_el->cost_a) + get_abs(cur_el->cost_b);
	node_smallest_cost = cur_node;
	while (cur_node)
	{
		cur_el = cur_node->content;
		cur_cost = get_abs(cur_el->cost_a) + get_abs(cur_el->cost_b);
		if (cur_cost < smallest_cost)
		{
			node_smallest_cost = cur_node;
			smallest_cost = cur_cost;
		}
		cur_node = cur_node->next;
	}
	return (get_stack_el(node_smallest_cost)->pos);
}

void	calculate_costs(t_push_swap *push_swap)
{
	calculate_cost_a(push_swap->stack_a, push_swap->stack_b);
	calculate_cost_b(push_swap->stack_b);
}
