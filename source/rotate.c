/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:34:15 by mleonard          #+#    #+#             */
/*   Updated: 2023/02/17 00:46:51 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	rotate_rotate(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a, RA);
	rotate(stack_b, RB);
}

void	rotate(t_list **stack, char *action_id)
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
	ft_printf("%s\n", action_id);
}
