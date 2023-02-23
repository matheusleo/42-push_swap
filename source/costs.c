/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:56:29 by mleonard          #+#    #+#             */
/*   Updated: 2023/02/22 22:54:43 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	calculate_cost_b(t_list *stack_b)
{
	t_list		*cur_node;
	int			stack_size;
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
	int			stack_a_size;
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

int	calculate_costs(t_push_swap *push_swap)
{
	calculate_cost_a(push_swap->stack_a, push_swap->stack_b);
	calculate_cost_b(push_swap->stack_b);
}
