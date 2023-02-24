/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:35:30 by mleonard          #+#    #+#             */
/*   Updated: 2023/02/24 02:46:56 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static	t_list	*get_target_node(t_list *cur_node_b, t_push_swap *push_swap)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*target_node_a;
	int		base_idx;

	stack_a = push_swap->stack_a;
	stack_b = push_swap->stack_b;
	if (get_stack_el(cur_node_b)->index > \
		get_stack_el(get_greatest_idx_node(stack_a))->index)
	{
		target_node_a = get_smallest_idx_node(stack_a);
		return (target_node_a);
	}
	else
	{
		base_idx = get_stack_el(cur_node_b)->index;
		while (base_idx <= ft_lstsize(stack_a) + ft_lstsize(stack_b))
		{
			target_node_a = stackfind_idx(stack_a, base_idx);
			if (target_node_a)
				return (target_node_a);
			base_idx++;
		}
	}
	return (NULL);
}

void	set_target_pos(t_push_swap *push_swap)
{
	t_list	*cur_node_b;
	t_list	*target_node_a;

	cur_node_b = push_swap->stack_b;
	while (cur_node_b)
	{
		target_node_a = get_target_node(cur_node_b, push_swap);
		get_stack_el(cur_node_b)->target_pos = get_stack_el(target_node_a)->pos;
		cur_node_b = cur_node_b->next;
	}
}

void	order_sorted_stack(t_list **stack)
{
	t_list		*smallest_idx_node;
	t_stack_el	*smallest_idx_el;
	size_t		stack_size;

	smallest_idx_node = get_smallest_idx_node(*stack);
	smallest_idx_el = smallest_idx_node->content;
	stack_size = ft_lstsize(*stack);
	while (!is_stack_sorted(*stack))
	{
		if (smallest_idx_el->pos < stack_size / 2)
			rotate_a(stack);
		else
			reverse_a(stack);
	}
}

void	push_ordered(t_push_swap *push_swap)
{
	size_t		half_total_size;
	t_stack_el	*cur_el;

	half_total_size = ft_lstsize(push_swap->stack_a) / 2 + 1;
	while ((size_t)ft_lstsize(push_swap->stack_a) > half_total_size)
	{
		cur_el = push_swap->stack_a->content;
		if (cur_el->index < half_total_size)
			push(&push_swap->stack_a, &push_swap->stack_b, PB);
		else
			rotate_a(&push_swap->stack_a);
	}
	while ((size_t)ft_lstsize(push_swap->stack_a) > 3)
		push(&push_swap->stack_a, &push_swap->stack_b, PB);
}

void	sort_long(t_push_swap *push_swap)
{
	size_t	cheapest_move_pos;

	push_ordered(push_swap);
	sort_short(push_swap);
	while (ft_lstsize(push_swap->stack_b))
	{
		set_pos(&push_swap->stack_a);
		set_pos(&push_swap->stack_b);
		set_target_pos(push_swap);
		calculate_costs(push_swap);
		cheapest_move_pos = get_cheapest_move_pos(push_swap->stack_b);
		execute_move(cheapest_move_pos, push_swap);
	}
	order_sorted_stack(&push_swap->stack_a);
}
