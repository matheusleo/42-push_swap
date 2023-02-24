/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 23:18:26 by mleonard          #+#    #+#             */
/*   Updated: 2023/02/24 12:19:37 by mleonard         ###   ########.fr       */
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

void	execute_both_moves(t_stack_el *el, t_list **stack_a, t_list **stack_b)
{
	int			inc_a;
	int			inc_b;

	if (el->cost_a < 0)
		inc_a = 1;
	else
		inc_a = -1;
	if (el->cost_b < 0)
		inc_b = 1;
	else
		inc_b = -1;
	while (el->cost_a < 0 && el->cost_b < 0)
	{
		reverse_reverse(stack_a, stack_b);
		el->cost_a += inc_a;
		el->cost_b += inc_b;
	}
	while (el->cost_a > 0 && el->cost_b > 0)
	{
		rotate_rotate(stack_a, stack_b);
		el->cost_a += inc_a;
		el->cost_b += inc_b;
	}
}

void	execute_move(size_t pos_b, t_push_swap *push_swap)
{
	t_list		*node_b;
	t_stack_el	*el;

	node_b = stackfind_pos(push_swap->stack_b, pos_b);
	el = node_b->content;
	if (el->cost_a != 0 && el->cost_b != 0)
		execute_both_moves(el, &push_swap->stack_a, &push_swap->stack_b);
	if (el->cost_a)
		execute_move_a(el->cost_a, &push_swap->stack_a);
	if (el->cost_b)
		execute_move_b(el->cost_b, &push_swap->stack_b);
	push(&push_swap->stack_b, &push_swap->stack_a, PA);
}
