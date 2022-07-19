/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bruteforce_pick_check.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashitomi<ashitomi@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 20:23:51 by ashitomi          #+#    #+#             */
/*   Updated: 2022/07/19 11:39:36 by ashitomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_bruteforce_solution(t_state *states, t_state **result)
{
	while (states && !(*result))
	{
		if (!states->stack_b->size && !is_stack_ordered(states->stack_a, ZERO))
		{
			if (!add_state(result, states))
			{
				free_states(states);
				return (1);
			}
		}
		states = states->next;
	}
	return (0);
}

t_state	*pick_bruteforce_solution(t_state *states,
	size_t pos[2], t_stack *stack_b)
{
	t_state			*result;
	t_state			*new_states;
	t_state			*tmp;

	result = NULL;
	while (!result)
	{
		new_states = NULL;
		tmp = states;
		while (tmp)
		{
			if (bruteforce_choice_a(&new_states, tmp, pos, stack_b))
			{
				free_states(new_states);
				return (NULL);
			}
			tmp = tmp->next;
		}
		free_states(states);
		states = new_states;
		if (check_bruteforce_solution(states, &result))
			return (NULL);
	}
	free_states(states);
	return (result);
}
