/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_state.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashitomi<ashitomi@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 20:23:51 by ashitomi          #+#    #+#             */
/*   Updated: 2022/05/21 20:23:51 by ashitomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	init_new_state(t_state	*new)
{
	new->stack_a = NULL;
	new->stack_b = NULL;
	new->instructions = NULL;
	new->last_instr = NULL;
	new->next = NULL;
}

static void	write_new_state(t_state *new, t_state *state_from)
{
	new->stack_a = copy_stack(state_from->stack_a);
	new->stack_b = copy_stack(state_from->stack_b);
	new->instructions = copy_instructions(state_from->instructions);
}

t_state	*add_state(t_state **states, t_state *state_from)
{
	t_state	*tmp;
	t_state	*new;

	new = malloc(sizeof(t_state));
	init_new_state(new);
	if (!new)
		return (NULL);
	write_new_state(new, state_from);
	if (!new->stack_a || !new->stack_b
		|| (state_from->instructions && !new->instructions))
	{
		free_states(new);
		return (NULL);
	}
	tmp = *states;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (tmp)
		tmp->next = new;
	else
		*states = new;
	return (new);
}
