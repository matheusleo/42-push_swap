/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 21:48:24 by mleonard          #+#    #+#             */
/*   Updated: 2023/02/08 22:17:32 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <libft.h>
# define MIN_INT 0x80000000
# define MAX_INT 0x7fffffff

typedef struct s_push_swap
{
	t_list	*stack_a;
	t_list	*stack_b;
}			t_push_swap;

typedef struct s_stack_el
{
	int	value;
}			t_stack_el;

// Management functions
int shutdown(int status, t_push_swap *push_swap);

// User input handler
void	validate_input(int argc, char *argv[]);
void	parse_input(int argc, char *argv[], t_push_swap *push_swap);

// Error handler
void	error_handler(char *msg);

#endif
