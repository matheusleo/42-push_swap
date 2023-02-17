/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 20:45:55 by mleonard          #+#    #+#             */
/*   Updated: 2023/02/17 00:43:36 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static t_stack_el	*create_new_stack_el(char *nptr, t_push_swap *push_swap)
{
	t_stack_el	*temp;
	long int	nb_temp;

	temp = (t_stack_el *)malloc(sizeof(t_stack_el));
	nb_temp = ft_atol(nptr);
	if ((nb_temp < MIN_INT || nb_temp > MAX_INT) \
		|| (nb_temp == 0 && nptr[0] != '0' && nptr[1] != '0' && nptr[2] != '0'))
	{
		free(temp);
		shutdown(EXIT_FAILURE, push_swap);
	}
	temp->value = nb_temp;
	return (temp);
}

static void	set_pos(t_stack_el *stack_el)
{
	static size_t	pos = 0;

	stack_el->pos = pos;
	pos++;
}

void	ft_test(t_list *list)
{
	t_stack_el	*stack_el;

	stack_el = list->content;
	ft_printf("value from list %d\n", stack_el);
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
}
