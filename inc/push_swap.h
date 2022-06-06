/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/31 12:38:35 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/06/06 19:04:26 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INTMIN -2147483648
# define INTMAX 2147483647

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# include "../libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}				t_stack;

typedef struct s_env
{
	t_stack		*stack_a;
	t_stack		*stack_b;
}				t_env;

void	parse_input(char **argv, t_env *env);
void	check_input(t_env *env);
void	addnode_front(t_stack **head, t_stack *new_node);
void	addnode_end(t_stack **head, t_stack *new);
void	sort_stack(t_env *env);
int		n_nodes(t_stack **head);
int		get_idx_for_val(t_stack **head, int value);
int		get_min_val(t_stack **head);
void	sort_2(t_env *env);
void	sort_3(t_env *env);
void	sort_4(t_env *env);
void	sort_5(t_env *env);
void	sort_6(t_env *env);
void	sort_radix(t_env *env);
void	indexer(t_stack **head);
int		isordered(t_stack **head);
void	swap_a(t_env *env);
void	swap_b(t_env *env);
void	swap_s(t_env *env);
void	insert_node(t_stack **head, t_stack *new_node, int pos);
void	rotate_a(t_env *env);
void	rotate_b(t_env *env);
void	rotate_s(t_env *env);
void	rrotate_a(t_env *env);
void	rrotate_b(t_env *env);
void	rrotate_s(t_env *env);
void	push_a(t_env *env);
void	push_b(t_env *env);
void	clean_and_exit(char *s, t_env *env, int exit_code);
t_stack	*popnode_front(t_stack **head);
t_stack	*get_last(t_stack **head);
t_stack	*popnode_end(t_stack **head);
t_stack	*popnode_front(t_stack **head);
t_stack	*newnode(int val, int index);
void	clean_nodes(t_stack **head);

#endif