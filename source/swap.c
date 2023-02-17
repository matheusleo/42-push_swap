/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:34:17 by mleonard          #+#    #+#             */
/*   Updated: 2023/02/17 00:46:27 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	swap_swap(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a, PA);
	swap(stack_b, PB);
}

void	swap(t_list **stack, char *action_id)
{
	t_list		*first_node;
	t_list		*second_node;
	t_stack_el	*aux;

	if (ft_lstsize(*stack) > 1)
	{
		first_node = *stack;
		second_node = (*stack)->next;
		aux = first_node->content;
		first_node->content = second_node->content;
		second_node->content = aux;
		*stack = first_node;
	}
}
