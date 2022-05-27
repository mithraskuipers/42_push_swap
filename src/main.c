/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/25 23:09:34 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/05/27 11:09:19 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	superbob(t_env *env, int nbr);

void	sort_stack(t_env *env)
{
	int	stack_len;

	stack_len = n_nodes(&env->stack_a);
	if ((stack_len) == 2)
		sort_2(&env->stack_a);
	else if ((stack_len) == 3)
		sort_3(&env->stack_a);
	else if ((stack_len) == 4)
		sort_4(&env->stack_a, &env->stack_b);
	else if ((stack_len) == 5)
		sort_5(&env->stack_a, &env->stack_b);
	else if ((stack_len) == 6)
		sort_6(&env->stack_a, &env->stack_b);
	else
		superbob(env, 19);
}

void	check_input(t_env *env)
{
	if (ps_hasduplicates(&env->stack_a))
		msg_exit("Error", 2);
	if (ps_isordered(&env->stack_a))
		exit(2);
}

void	findNum(t_env *env, int num, int buf)
{
	int	x;
	int	y;
	int	atoi;

	while (1)
	{
		atoi = env->stack_a->value;
		if (num == INTMIN)
			return ;
		if ((num - buf) <= atoi && (num + buf) >= atoi)
			return ;
		x = get_idx_for_value(&env->stack_a, num);
		y = n_nodes(&env->stack_a) / 2;
		if (x < y)
		{
			rotate_a(&env->stack_a);
		}
		else
		{
			rrotate_a(&env->stack_a);
		}
	}
}

void	findNumB(t_env *env, int num)
{
	int	x;
	int	y;
	int	atoi;

	while (1)
	{
		atoi = env->stack_b->value;
		if (atoi == num)
			return ;
		x = get_idx_for_value(&env->stack_b, num);
		if (env->stack_b->next && env->stack_b->next->value == num)
			swap_b(&env->stack_b);
		else
		{
			y = n_nodes(&env->stack_b) / 2;
			if (x < y)
				rotate_b(&env->stack_b);
			else
				rrotate_b(&env->stack_b);
		}
	}
}

void	superbob(t_env *env, int nbr)
{
	if (ps_isordered(&env->stack_a))
	{
		return;
	}
	while (n_nodes(&env->stack_a) > 1)
	{
		findNum(env, get_min_value(&env->stack_a), nbr);
		if ((ps_isordered(&env->stack_a)) && (env->stack_a->value > env->stack_b->value))
		{
			break;
		}
		push_b(&env->stack_a, &env->stack_b);
	}
	push_b(&env->stack_a, &env->stack_b);
	while (n_nodes(&env->stack_b) > 0)
	{
		findNumB(env, get_max_value(&env->stack_b));
		push_a(&env->stack_a, &env->stack_b);
	}
}


int	main(int argc, char **argv)
{
	t_env	*env;

	if (argc < 2)
		exit(2);
	env = ft_calloc(1, sizeof(t_env));
	if ((!env))
		msg_exit("Error", 2);
	parse_input(argv, env);
	check_input(env);
	sort_stack(env);
	//swap_a(&env->stack_a); // leak!
	//push_b(&env->stack_a, &env->stack_b); // leak!
	//swap_b(&env->stack_b); // ???
	//print_forwards(&env->stack_a);
	//system("leaks push_swap");
	//free (env);
	return (0);
}

/*
TODO: Eval tests
ARG="1 5 2 4 3" && ./push_swap $ARG | ./checker_linux $ARG
6 instructions! even less than 8

ARG=" 888 -2 11 -2093 5" && ./push_swap $ARG | ./checker_linux $ARG
ARG=" 888 -2 11 -2093 5" && ./push_swap $ARG | wc -l
10 instructions! no more than 12!
*/
