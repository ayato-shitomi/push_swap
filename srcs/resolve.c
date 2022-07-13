/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashitomi<ashitomi@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 20:23:51 by ashitomi          #+#    #+#             */
/*   Updated: 2022/05/23 22:50:21 by ashitomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	c(t_instruction *a)
{
	return (count_instructions(a));
}

/*
static void print_prg_stack_a(t_program *prg, int n)
{
	int	c;

	c = 0;
	printf("%d > ", n);
	while (c < prg->stack_a.size)
	{
		printf("%d ", prg->stack_a.array[c]);
		c++;
	}
	printf("\n");
}
*/

int	pick_solution(t_program *prg, t_state *states)
{
	t_state			*solution;
	t_state			*tmp_state;

	solution = NULL;
	tmp_state = states->next;
	while (tmp_state)
	{
		if (!solution || c(tmp_state->instructions) < c(solution->instructions))
			solution = tmp_state;
		tmp_state = tmp_state->next;
	}
	if (!solution)
		solution = states;
	if (solution->instructions)
	{
		execute_instructions(solution->instructions,
			&prg->stack_a, &prg->stack_b);
		prg->instr = copy_instructions(solution->instructions);
		if (!prg->instr)
		{
			free_states(states);
			return (1);
		}
	}
	return (0);
}

int	large_resolve(t_state *states)
{
	t_instruction	*tmp;
	t_state			*tmp_state;

	tmp_state = states->next;
	while (tmp_state)
	{
		while (tmp_state->stack_a->size > 5)
		{
			if (can_pb(tmp_state->stack_a, tmp_state->stack_b))
				tmp = add_instruction(&tmp_state->instructions, "pb");
			else
				tmp = rotate(tmp_state);
			if (!tmp)
			{
				free_states(states);
				return (1);
			}
			execute_instructions(tmp, tmp_state->stack_a, tmp_state->stack_b);
		}
		tmp_state = tmp_state->next;
	}
	return (0);
}

int	resolve(t_program *prg)
{
	t_state			*states;

	states = new_empty_state(&prg->stack_a,
			&prg->stack_b, prg->stack_a.max_size);
	if (!states)
		return (1);
	if (prg->stack_a.size > 5
		&& (create_states_resolution(&states) || large_resolve(states)))
	{
		free_states(states);
		return (1);
	}
	if (pick_solution(prg, states))
	{
		free_states(states);
		return (1);
	}
	free_states(states);
	return (resolve_return(prg));
}
