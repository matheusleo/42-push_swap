/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 20:45:55 by mleonard          #+#    #+#             */
/*   Updated: 2023/02/14 01:34:54 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static t_stack_el	*create_new_stack_el(char *nptr, t_push_swap *push_swap)
{
	t_stack_el	*temp;

	temp = (t_stack_el *)malloc(sizeof(t_stack_el));
	temp->value = ft_atoi(nptr);
	if (temp->value == 0 && nptr[0] != '0' && nptr[1] != '0' && nptr[2] != '0')
	{
		free(temp);
		shutdown(EXIT_FAILURE, push_swap);
	}
	return (temp);
}

static void	set_pos(t_stack_el *stack_el)
{
	static size_t	pos = 0;

	stack_el->pos = pos;
	pos++;
}

void	parse_input(int argc, char *argv[], t_push_swap *push_swap)
{
	int			idx;
	t_stack_el	*temp_nb;
	t_list		*new_node;

	idx = 1;
	temp_nb = create_new_stack_el(argv[idx], push_swap);
	push_swap->stack_a = ft_lstnew(temp_nb);
	idx++;
	while (idx < argc)
	{
		temp_nb = create_new_stack_el(argv[idx], push_swap);
		new_node = ft_lstnew(temp_nb);
		ft_lstadd_back(&push_swap->stack_a, new_node);
		idx++;
	}
	ft_lstiter(push_swap->stack_a, set_pos);
	validate_doubles(push_swap);
	ft_printf("from before shutdown of the parse_input - ");
	shutdown(EXIT_FAILURE, push_swap);
}
