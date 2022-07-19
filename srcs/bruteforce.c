/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bruteforce.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashitomi<ashitomi@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 20:23:51 by ashitomi          #+#    #+#             */
/*   Updated: 2022/07/19 11:39:36 by ashitomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	bruteforce_choice_a(t_state **new_states,
	t_state *tmp, size_t pos[2], t_stack *stack_b)
{
	if (tmp->stack_b->size < 2 && (!tmp->last_instr
			|| ft_strcmp(tmp->last_instr->line, "pa"))
		&& !new_state_instruction(new_states, tmp, "pb"))
		return (1);
	if (tmp->stack_b->size > 0 && (!tmp->last_instr
			|| ft_strcmp(tmp->last_instr->line, "pb"))
		&& !new_state_instruction(new_states, tmp, "pa"))
		return (1);
	if (!tmp->last_instr || (ft_strcmp(tmp->last_instr->line, "sa")
			&& ft_strcmp(tmp->last_instr->line, "sb")
			&& ft_strcmp(tmp->last_instr->line, "ss")))
	{
		if (!new_state_instruction(new_states, tmp, "sa"))
			return (1);
		if (1 < tmp->stack_b->size)
		{
			if (!new_state_instruction(new_states, tmp, "sb"))
				return (1);
			if (!new_state_instruction(new_states, tmp, "ss"))
				return (1);
		}
	}
	if (rotate_bruteforce_a(new_states, tmp, pos, stack_b))
		return (1);
	return (reverse_rotate_bruteforce_a(new_states, tmp, pos, stack_b));
}

int	reverse_rotate_bruteforce_a(t_state **new_states,
	t_state *tmp, size_t pos[2], t_stack *stack_b)
{
	size_t			j;
	t_instruction	*tmp_instr;

	tmp_instr = tmp->last_instr;
	j = 0;
	while (j++ < tmp->stack_a->size / 2
		&& tmp_instr && (!ft_strcmp(tmp_instr->line, "rra")
			|| !ft_strcmp(tmp_instr->line, "rrr")))
		tmp_instr = tmp->last_instr->prev;
	if (!tmp->last_instr || ((ft_strcmp(tmp->last_instr->line, "ra")
				&& ft_strcmp(tmp->last_instr->line, "rr")
				&& j < tmp->stack_a->size / 2)))
	{
		if (pos[0] > stack_b->size / 2 && !tmp->stack_b->size && pos[1])
		{
			pos[1]--;
			if (!new_state_instruction(new_states, tmp, "rrr"))
				return (1);
		}
		else if (!new_state_instruction(new_states, tmp, "rra"))
			return (1);
	}
	return (0);
}

int	bruteforce_order_a(t_program *prg)
{
	size_t			pos[2];
	t_state			*result;
	t_state			*states;

	calcul_align_b(&pos[0], &pos[1], &prg->stack_b);
	states = new_empty_state(&prg->stack_a, NULL, prg->stack_a.max_size);
	if (!states)
		return (1);
	result = pick_bruteforce_solution(states, pos, &prg->stack_b);
	if (!result)
	{
		free_states(states);
		return (1);
	}
	execute_instructions(result->instructions, &prg->stack_a, &prg->stack_b);
	if (!copy_and_concat_instructions(&prg->instr, result->instructions))
	{
		free_states(result);
		return (1);
	}
	free_states(result);
	return (0);
}

int	rotate_bruteforce_a(t_state **new_states,
	t_state *tmp, size_t pos[2], t_stack *stack_b)
{
	size_t			j;
	t_instruction	*tmp_instr;

	tmp_instr = tmp->last_instr;
	j = 0;
	while (j++ < tmp->stack_a->size / 2
		&& tmp_instr && (!ft_strcmp(tmp_instr->line, "ra")
			|| !ft_strcmp(tmp_instr->line, "rr")))
		tmp_instr = tmp->last_instr->prev;
	if (!tmp->last_instr || ((ft_strcmp(tmp->last_instr->line, "rra")
				&& ft_strcmp(tmp->last_instr->line, "rrr")
				&& j < tmp->stack_a->size / 2)))
	{
		if (pos[0] <= stack_b->size / 2 && !tmp->stack_b->size && pos[1])
		{
			pos[1]--;
			if (!new_state_instruction(new_states, tmp, "rr"))
				return (1);
		}
		else if (!new_state_instruction(new_states, tmp, "ra"))
			return (1);
	}
	return (0);
}
