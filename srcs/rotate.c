/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashitomi<ashitomi@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 20:23:51 by ashitomi          #+#    #+#             */
/*   Updated: 2022/07/19 11:39:36 by ashitomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reverse_rotate_stack(t_stack *stack)
{
	size_t	i;
	int		tmp;

	if (stack->size > 1)
	{
		tmp = stack->array[stack->size - 1];
		i = stack->size - 1;
		while (i > 0)
		{
			stack->array[i] = stack->array[i - 1];
			i--;
		}
		stack->array[0] = tmp;
	}
}

/*
	shift up all elemets of the stack by 1.
	the first one become the last one
*/

void	rotate_stack(t_stack *stack)
{
	size_t	i;
	int		tmp;

	if (stack->size > 1)
	{
		tmp = stack->array[0];
		i = 0;
		while (i < stack->size - 1)
		{
			stack->array[i] = stack->array[i + 1];
			i++;
		}
		stack->array[stack->size - 1] = tmp;
	}
}

t_instruction	*rotate(t_state *stt)
{
	t_instruction		*instr;
	size_t				mvt[2];
	size_t				min[2];
	size_t				min_mvt[2];

	mvt[0] = closer_pos_to_inf(stt->stack_a->array[0], stt->stack_b);
	min[0] = less_mvt_at_begin(mvt[0], &min_mvt[0], stt->stack_a, stt->stack_b);
	min[1] = less_mvt_at_end(mvt[0], &min_mvt[1], stt->stack_a, stt->stack_b);
	if (mvt[0] > stt->stack_b->size / 2)
		mvt[1] = stt->stack_b->size - mvt[0];
	else
		mvt[1] = mvt[0];
	if (stt->stack_a->size > 1 && (min[0] <= mvt[1] || min[1] <= mvt[1]))
		instr = rotate_a(stt, min, min_mvt);
	else if (mvt[0] > stt->stack_b->size / 2)
		instr = add_instruction(&stt->instructions, "rrb");
	else
		instr = add_instruction(&stt->instructions, "rb");
	return (instr);
}

t_instruction	*rotate_a(t_state *stt, size_t min[2], size_t min_mvt[2])
{
	t_instruction	*instr;

	if (min[0] <= min[1] && min_mvt[0] <= stt->stack_b->size / 2)
		instr = add_instruction(&stt->instructions, "rr");
	else if (min[0] < min[1] && min_mvt[0] > stt->stack_b->size / 2)
		instr = add_instruction(&stt->instructions, "ra");
	else if (min_mvt[1] > stt->stack_b->size / 2)
		instr = add_instruction(&stt->instructions, "rrr");
	else
		instr = add_instruction(&stt->instructions, "rra");
	return (instr);
}
