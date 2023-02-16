/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:08:13 by mleonard          #+#    #+#             */
/*   Updated: 2023/02/16 09:21:42 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	*lstpop(t_list **list)
{
	t_list	*head;
	void	*content;

	head = *list;
	*list = head->next;
	content = head->content;
	free(head);
	return (content);
}

void	push(t_list **from, t_list **to)
{
	t_list	*new_node;

	new_node = ft_lstnew((*from)->content);
	ft_lstadd_front(to, new_node);
	lstpop(from);
}
