/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:34:17 by mleonard          #+#    #+#             */
/*   Updated: 2023/02/17 01:01:45 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	swap_swap(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("%s\n", SS);
}

void	swap_a(t_list **stack_a)
{
	swap(stack_a);
	ft_printf("%s\n", SA);
}

void	swap_b(t_list **stack_b)
{
	swap(stack_b);
	ft_printf("%s\n", SB);
}

void	swap(t_list **stack)
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
