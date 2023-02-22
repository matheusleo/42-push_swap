/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:32:56 by mleonard          #+#    #+#             */
/*   Updated: 2023/02/22 09:57:27 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_stack_el	*get_next_el(t_list *stack)
{
	if (stack->next)
		return ((t_stack_el *)stack->next->content);
	return (NULL);
}

void	ft_lstclear_nodes(t_list **list)
{
	t_list	*cur_node;
	t_list	*next_node;

	cur_node = *list;
	next_node = (*list)->next;
	while (cur_node)
	{
		free(cur_node);
		cur_node = next_node;
		if (cur_node)
			next_node = cur_node->next;
	}
}

int	find_nb_in_stack(t_list *stack, int nb)
{
	t_list		*node_cur;
	int			stack_val;
	t_stack_el	*aux;

	node_cur = stack;
	while (node_cur)
	{
		aux = node_cur->content;
		stack_val = aux->value;
		if (stack_val == nb)
			return (FOUND);
		node_cur = node_cur->next;
	}
	return (NOT_FOUND);
}
