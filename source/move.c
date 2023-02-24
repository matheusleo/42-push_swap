/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 23:18:26 by mleonard          #+#    #+#             */
/*   Updated: 2023/02/24 01:15:27 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	execute_move_b(int cost_b, t_list **stack_b)
{
	int	inc;

	if (cost_b < 0)
		inc = 1;
	else
		inc = -1;
	while (cost_b != 0)
	{
		if (inc == 1)
			reverse_b(stack_b);
		else
			rotate_b(stack_b);
		cost_b += inc;
	}
}

void	execute_move_a(int cost_a, t_list **stack_a)
{
	int	inc;

	if (cost_a < 0)
		inc = 1;
	else
		inc = -1;
	while (cost_a != 0)
	{
		if (inc > 0)
			reverse_a(stack_a);
		else
			rotate_a(stack_a);
		cost_a += inc;
	}
}

void	execute_move(size_t pos_b, t_push_swap *push_swap)
{
	t_list		*node_b;
	t_stack_el	*el;

	node_b = stackfind_pos(push_swap->stack_b, pos_b);
	el = node_b->content;
	execute_move_a(el->cost_a, &push_swap->stack_a);
	execute_move_b(el->cost_b, &push_swap->stack_b);
	push(&push_swap->stack_b, &push_swap->stack_a, PA);
}
