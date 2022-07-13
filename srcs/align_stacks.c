/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   align_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashitomi<ashitomi@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 20:23:51 by ashitomi          #+#    #+#             */
/*   Updated: 2022/05/21 20:23:51 by ashitomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
	Count how many movements needed to align stack_a
	and the position of the element to align
*/

void	calcul_align_a(size_t *pos,
	size_t *mvt, t_stack *stack_a, t_stack *stack_b)
{
	*pos = 0;
	*mvt = 0;
	if (is_stack_ordered(stack_a, ZERO) == 0)
	{
		while (stack_a->array[*pos] < stack_a->array[*pos + 1]
			&& *pos < stack_a->size - 2)
			(*pos)++;
		if ((stack_b->size / 2) < *pos)
			*mvt = stack_a->size - (*pos + 1);
		else
			*mvt = *pos + 1;
	}
}

/*
    Count how many movements needed to align stack_b
	and the position of the element to align
*/

void	calcul_align_b(size_t *pos, size_t *mvt, t_stack *stack_b)
{
	*pos = 0;
	*mvt = 0;
	if (is_stack_ordered(stack_b, ONE))
	{
		while (stack_b->array[*pos + 1] < stack_b->array[*pos]
			&& *pos < stack_b->size - 1)
			(*pos)++;
		if (stack_b->size / 2 < *pos)
			*mvt = stack_b->size - (*pos + 1);
		else
			*mvt = *pos + 1;
	}
}

/*
	align stack a in order to get final solution
*/

int	align_stack_a(t_program *prg)
{
	size_t			i;
	size_t			num;
	t_instruction	*tmp;

	calcul_align_a(&i, &num, &prg->stack_a, &prg->stack_b);
	while (num)
	{
		if (prg->stack_b.size / 2 < i)
			tmp = add_instruction(&prg->instr, "rra");
		else
			tmp = add_instruction(&prg->instr, "ra");
		if (!tmp)
			return (1);
		execute_instructions(tmp, &prg->stack_a, &prg->stack_b);
		num--;
	}
	return (0);
}

/*
	align stack_b to fill stack_a
*/

int	align_stack_b(t_program *prg)
{
	size_t			i;
	size_t			num;
	t_instruction	*tmp;

	calcul_align_b(&i, &num, &prg->stack_b);
	while (num)
	{
		if (prg->stack_b.size / 2 < i)
			tmp = add_instruction(&prg->instr, "rrb");
		else
			tmp = add_instruction(&prg->instr, "rb");
		if (!tmp)
			return (1);
		execute_instructions(tmp, &prg->stack_a, &prg->stack_b);
		num--;
	}
	return (0);
}
