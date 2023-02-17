/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:34:12 by mleonard          #+#    #+#             */
/*   Updated: 2023/02/17 01:01:19 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static t_list	*lstfind_idx(t_list *lst, size_t target_idx)
{
	t_list	*cur_node;
	size_t	cur_idx;

	cur_node = lst;
	cur_idx = 0;
	if (!lst)
		return (NULL);
	while (cur_idx < target_idx && cur_node)
	{
		cur_node = cur_node->next;
		cur_idx++;
	}
	return (cur_node);
}

void	reverse_reverse(t_list **stack_a, t_list **stack_b)
{
	reverse(stack_a);
	reverse(stack_b);
	ft_printf("%s\n", RRR);
}

void	reverse_a(t_list **stack)
{
	reverse(stack);
	ft_printf("%s\n", RRA);
}

void	reverse_b(t_list **stack)
{
	reverse(stack);
	ft_printf("%s\n", RRB);
}

void	reverse(t_list **stack)
{
	t_list		*tail;
	t_list		*new_node;
	t_stack_el	*tail_content;
	t_list		*new_tail;

	if (ft_lstsize(*stack) > 1)
	{
		tail = ft_lstlast(*stack);
		tail_content = tail->content;
		new_node = ft_lstnew(tail_content);
		ft_lstadd_front(stack, new_node);
		new_tail = lstfind_idx(*stack, ft_lstsize(*stack) - 2);
		new_tail->next = NULL;
		free(tail);
	}
}
