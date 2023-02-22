/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:42:07 by mleonard          #+#    #+#             */
/*   Updated: 2023/02/21 12:38:52 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	is_stack_sorted(t_list *stack)
{
	t_list		*cur_node;
	t_stack_el	*cur_content;
	t_list		*next_node;
	t_stack_el	*next_content;

	cur_node = stack;
	next_node = stack->next;
	while (next_node)
	{
		cur_content = cur_node->content;
		next_content = next_node->content;
		if (cur_content->index > next_content->index)
			return (FALSE);
		cur_node = next_node;
		next_node = cur_node->next;
	}
	return (TRUE);
}

void	sort_stack(t_push_swap *push_swap)
{
	size_t	stack_size;

	stack_size = ft_lstsize(push_swap->stack_a);
	if (!is_stack_sorted(push_swap->stack_a))
	{
		if (stack_size <= 3)
			return (sort_short(push_swap));
		sort_long(push_swap);
	}
}
