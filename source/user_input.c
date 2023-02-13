/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 21:59:37 by mleonard          #+#    #+#             */
/*   Updated: 2023/02/13 09:26:31 by mleonard         ###   ########.fr       */
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

static int	*convert_atoi(char *nptr, t_push_swap *push_swap)
{
	int	*temp;

	temp = (int *)malloc(sizeof(int));
	*temp = ft_atoi(nptr);
	if (*temp == 0 && nptr[0] != '0' && nptr[1] != '0' && nptr[2] != '0')
	{
		free(temp);
		shutdown(EXIT_FAILURE, push_swap);
	}
	return (temp);
}

void	parse_input(int argc, char *argv[], t_push_swap *push_swap)
{
	int		idx;
	int		*temp_nb;
	t_list	*new_node;

	idx = 1;
	temp_nb = convert_atoi(argv[idx], push_swap);
	push_swap->stack_a = ft_lstnew(temp_nb);
	idx++;
	while (idx < argc)
	{
		temp_nb = convert_atoi(argv[idx], push_swap);
		new_node = ft_lstnew(temp_nb);
		ft_lstadd_back(&push_swap->stack_a, new_node);
		idx++;
	}
	shutdown(EXIT_FAILURE, push_swap);
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
