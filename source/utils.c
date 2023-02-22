/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:32:56 by mleonard          #+#    #+#             */
/*   Updated: 2023/02/22 11:31:52 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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

t_stack_el	*get_stack_el(t_list *stack)
{
	if (stack)
		return ((t_stack_el *)stack->content);
	return (NULL);
}

void	set_pos(t_list **stack)
{
	size_t	pos;
	t_list	*cur_node;

	pos = 0;
	cur_node = *stack;
	while (cur_node)
	{
		get_stack_el(cur_node)->pos = pos;
		cur_node = cur_node->next;
		pos++;
	}
}

t_list	*stackfind_idx(t_list *stack, size_t idx)
{
	t_list		*cur_node;
	t_stack_el	*aux;

	cur_node = stack;
	while (cur_node)
	{
		aux = cur_node->content;
		if (aux->index == idx)
			return (cur_node);
		cur_node = cur_node->next;
	}
	return (NULL);
}
