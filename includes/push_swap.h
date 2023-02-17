/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 21:48:24 by mleonard          #+#    #+#             */
/*   Updated: 2023/02/17 00:42:09 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <libft.h>
# define NOT_FOUND 0
# define FOUND 1
# define PA "pa"
# define PB "pb"
# define SA "sa"
# define SB "sb"
# define SS "ss"
# define RA "ra"
# define RB "rb"
# define RR "rr"
# define RRA "rra"
# define RRB "rrb"
# define RRR "rrr"

typedef struct s_push_swap
{
	t_list	*stack_a;
	t_list	*stack_b;
}			t_push_swap;

typedef struct s_stack_el
{
	int	value;
	int	index;
	int	pos;
	int	target_pos;
	int	cost_a;
	int	cost_b;
}			t_stack_el;

// Management functions
int		shutdown(int status, t_push_swap *push_swap);

// Validate user input
void	validate_input(int argc, char *argv[]);
void	validate_doubles(t_push_swap *push_swap);

// Parse user input
void	parse_input(int argc, char *argv[], t_push_swap *push_swap);

// Error handler
void	error_handler(char *msg);

// Actions
void	push(t_list **from, t_list **to, char *action_id);
void	swap(t_list **stack, char *action_id);
void	swap_swap(t_list **stack_a, t_list **stack_b);
void	rotate(t_list **stack, char *action_id);
void	rotate_rotate(t_list **stack_a, t_list **stack_b);
void	reverse(t_list **stack, char *action_id);
void	reverse_reverse(t_list **stack_a, t_list **stack_b);

// Utils
void	ft_lstclear_nodes(t_list **list);
int		find_nb_in_stack(t_list *stack, int nb);

#endif
