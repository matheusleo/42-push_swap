/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 20:45:55 by mleonard          #+#    #+#             */
/*   Updated: 2023/02/24 12:19:18 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static t_stack_el	*init_stack_el(void)
{
	t_stack_el	*el;

	el = (t_stack_el *)malloc(sizeof(t_stack_el));
	el->value = 0;
	el->index = 0;
	el->pos = 0;
	el->target_pos = 0;
	el->cost_a = 0;
	el->cost_b = 0;
	return (el);
}

static t_stack_el	*create_stack_el(char *nptr, t_push_swap *push_swap)
{
	t_stack_el	*temp;
	long int	nb_temp;

	temp = init_stack_el();
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

static t_push_swap	*create_stack(int argc, char **argv, t_push_swap *push_swap)
{
	int			idx;
	t_stack_el	*temp_nb;
	t_list		*new_node;

	idx = 1;
	temp_nb = create_stack_el(argv[idx], push_swap);
	push_swap->stack_a = ft_lstnew(temp_nb);
	idx++;
	while (idx < argc)
	{
		temp_nb = create_stack_el(argv[idx], push_swap);
		new_node = ft_lstnew(temp_nb);
		ft_lstadd_back(&push_swap->stack_a, new_node);
		idx++;
	}
	return (push_swap);
}

void	parse_input(int argc, char *argv[], t_push_swap *push_swap)
{
	create_stack(argc, argv, push_swap);
	set_pos(&push_swap->stack_a);
	validate_doubles(push_swap);
	set_indexes(&push_swap->stack_a);
}
