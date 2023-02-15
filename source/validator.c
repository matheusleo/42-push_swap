/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 21:59:37 by mleonard          #+#    #+#             */
/*   Updated: 2023/02/15 01:13:25 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	is_all_num(char *arg)
{
	ssize_t	len;

	len = ft_strlen(arg);
	if (!len)
		error_handler(": arg with no len provided");
	while (len-- > 0)
	{
		if (!ft_isdigit(arg[len]) && arg[len] != '-' && arg[len] != '+')
			error_handler(arg);
	}
	return (TRUE);
}

void	validate_doubles(t_push_swap *push_swap)
{
	t_list		*node_cur;
	t_list		*cpy;
	t_stack_el	*stack_el;
	t_list		*new_node;

	node_cur = push_swap->stack_a;
	cpy = ft_lstnew(node_cur->content);
	while (node_cur->next)
	{
		node_cur = node_cur->next;
		stack_el = node_cur->content;
		if (find_nb_in_stack(cpy, stack_el->value))
		{
			ft_lstclear_nodes(&cpy);
			shutdown(EXIT_FAILURE, push_swap);
		}
		else
		{
			new_node = ft_lstnew(node_cur->content);
			ft_lstadd_back(&cpy, new_node);
		}
	}
	ft_lstclear_nodes(&cpy);
}

void	validate_input(int argc, char *argv[])
{
	size_t	counter;

	counter = 1;
	if (argc == 1)
		error_handler(": no arg provided");
	while (counter < argc)
	{
		is_all_num(argv[counter]);
		counter++;
	}
}
