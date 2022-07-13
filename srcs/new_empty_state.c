/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_empty_state.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashitomi<ashitomi@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 20:23:51 by ashitomi          #+#    #+#             */
/*   Updated: 2022/05/23 22:48:11 by ashitomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	new_empty_state_init_state(t_state *state)
{
	state->instructions = NULL;
	state->last_instr = NULL;
	state->next = NULL;
}

/*
static void write_new_stack_state(t_state *state, size_t max_size)
{
    state->stack_a = new_empty_stack(max_size);
    state->stack_b = new_empty_stack(max_size);
}
*/

static int	write_state_stack_b(t_state *state, size_t max_size)
{
	state->stack_b = new_empty_stack(max_size);
	if (!state->stack_b)
		return (1);
	return (0);
}

static int	write_state_stack_a(t_state *state, size_t max_size)
{
	state->stack_a = new_empty_stack(max_size);
	if (!state->stack_a)
		return (1);
	return (0);
}

t_state	*new_empty_state(t_stack *stack_a, t_stack *stack_b, size_t max_size)
{
	t_state		*state;

	state = malloc(sizeof(t_state));
	if (!state)
		return (NULL);
	if (stack_a)
		state->stack_a = copy_stack(stack_a);
	else if (write_state_stack_a(state, max_size) == 1)
	{
		free(state);
		return (NULL);
	}
	if (stack_b)
		state->stack_b = copy_stack(stack_b);
	else if (write_state_stack_b(state, max_size) == 1)
	{
		free(state);
		return (NULL);
	}
	new_empty_state_init_state(state);
	return (state);
}
