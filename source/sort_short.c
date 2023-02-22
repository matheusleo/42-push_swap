/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:23:04 by mleonard          #+#    #+#             */
/*   Updated: 2023/02/22 13:27:18 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static size_t	has_greatest_idx(t_list *stack)
{
	t_list	*cur_node;
	size_t	greatest_idx;
	size_t	cur_index;

	cur_node = stack;
	greatest_idx = 0;
	while (cur_node)
	{
		cur_index = get_stack_el(cur_node)->index;
		if (cur_index > greatest_idx)
			greatest_idx = cur_index;
		cur_node = cur_node->next;
	}
	return (get_stack_el(stack)->index == greatest_idx);
}

static size_t	has_smallest_idx(t_list *stack)
{
	t_list	*cur_node;
	size_t	smallest_idx;
	size_t	cur_index;

	cur_node = stack;
	smallest_idx = get_stack_el(stack)->index;
	while (cur_node)
	{
		cur_index = get_stack_el(cur_node)->index;
		if (cur_index < smallest_idx)
			smallest_idx = cur_index;
		cur_node = cur_node->next;
	}
	return (get_stack_el(stack)->index == smallest_idx);
}

void	sort_short(t_push_swap *push_swap)
{
	t_list		*stack_a;
	t_stack_el	*stack_a_content;

	stack_a = push_swap->stack_a;
	if (ft_lstsize(stack_a) == 2)
		return (swap_a(&push_swap->stack_a));
	else
	{
		while (!is_stack_sorted(stack_a))
		{
			stack_a_content = stack_a->content;
			if (has_greatest_idx(stack_a))
				rotate_a(&push_swap->stack_a);
			else if (has_smallest_idx(stack_a))
				reverse_a(&push_swap->stack_a);
			else
			{
				if (has_smallest_idx(stack_a->next))
					swap_a(&push_swap->stack_a);
				else
					reverse_a(&push_swap->stack_a);
			}
			stack_a = push_swap->stack_a;
		}
	}
}
