/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_something.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashitomi<ashitomi@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 20:23:51 by ashitomi          #+#    #+#             */
/*   Updated: 2022/07/19 11:39:36 by ashitomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	free_instructions(t_instruction *instructions)
{
	t_instruction	*next;

	while (instructions)
	{
		next = instructions->next;
		free(instructions->line);
		free(instructions);
		instructions = next;
	}
	return (1);
}

void	free_stack(t_stack *stack)
{
	free(stack->array);
	free(stack);
}

void	free_states(t_state *states)
{
	t_state			*tmp;
	t_state			*next;

	tmp = states;
	while (tmp)
	{
		next = tmp->next;
		free_stack(tmp->stack_a);
		free_stack(tmp->stack_b);
		free_instructions(tmp->instructions);
		free(tmp);
		tmp = next;
	}
}

int	free_prg(t_program *prg)
{
	free_instructions(prg->instr);
	free(prg->stack_a.array);
	free(prg->stack_b.array);
	return (0);
}
