/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 21:48:18 by mleonard          #+#    #+#             */
/*   Updated: 2023/02/17 00:45:56 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	shutdown(int status, t_push_swap *push_swap)
{
	ft_lstclear(&(push_swap->stack_a), free);
	ft_lstclear(&(push_swap->stack_b), free);
	if (status == EXIT_FAILURE)
		error_handler("");
	exit(status);
}

t_push_swap	init_push_swap(void)
{
	t_push_swap	push_swap;

	push_swap.stack_a = NULL;
	push_swap.stack_b = NULL;
	return (push_swap);
}

int	main(int argc, char *argv[])
{
	t_push_swap	push_swap;

	validate_input(argc, argv);
	push_swap = init_push_swap();
	parse_input(argc, argv, &push_swap);
	shutdown(EXIT_SUCCESS, &push_swap);
}
