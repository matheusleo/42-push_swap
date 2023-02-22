/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:23:04 by mleonard          #+#    #+#             */
/*   Updated: 2023/02/22 09:10:20 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort_short(t_push_swap *push_swap)
{
	t_list		*stack_a;
	t_stack_el	*stack_a_content;

	stack_a = push_swap->stack_a;
	if (ft_lstsize(stack_a) == 2)
		return (swap_a(&stack_a));
	else
	{
		while (!is_stack_sorted(stack_a))
		{
			stack_a_content = stack_a->content;
			if ((stack_a_content->index == 3))
				rotate_a(&stack_a);
			else if ((stack_a_content->index == 1))
				reverse_a(&stack_a);
			else if ((stack_a_content->index == 2))
			{
				if (((t_stack_el *)stack_a->next->content)->index == 1)
					swap_a(&stack_a);
				else
					reverse_a(&stack_a);
			}
			stack_a = push_swap->stack_a;
		}
	}
}
