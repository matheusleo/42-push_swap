/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:34:15 by mleonard          #+#    #+#             */
/*   Updated: 2023/02/17 01:01:32 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	rotate_rotate(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("%s\n", RR);
}

void	rotate_a(t_list **stack_a)
{
	rotate(stack_a);
	ft_printf("%s\n", RA);
}

void	rotate_b(t_list **stack_b)
{
	rotate(stack_b);
	ft_printf("%s\n", RB);
}


void	rotate(t_list **stack)
{
	t_stack_el	*node_content;
	t_list		*head;
	t_list		*tail;

	if (ft_lstsize(*stack) > 1)
	{
		head = *stack;
		node_content = (*stack)->content;
		tail = ft_lstnew(node_content);
		ft_lstadd_back(stack, tail);
		*stack = (*stack)->next;
		free(head);
	}
}
