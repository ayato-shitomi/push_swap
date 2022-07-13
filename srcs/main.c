/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashitomi<ashitomi@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 20:23:51 by ashitomi          #+#    #+#             */
/*   Updated: 2022/05/21 20:23:51 by ashitomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	We can only use these functions：
		read, write, malloc, free, exit

	sa	swap a
			swap the first 2 elements at the top of stack_a.
	sb	swap b
			swap the first 2 elements at the top of stack_b.
	ss	sa and sb
			do `sa` and `sb` at the same time.
	pa	push a
			take the first element at the top of stack_b
			and put it at the top of stack_a.
	pb	push b
			take the first element at the top of stack_a
			and put it at the top of stacl_b.
	ra	rotate a
			shift up all elements of stack_a by 1.
			The first element becomes the last one.
	rb	rotate b
			shift up all elements of stack_b by 1.
			The first element becomes the last one.
	rr	ra and rb
			do `ra` and `rb` at the same time.
	rra	reverse rotate a
			shift down all elements of stack_a by 1.
			The last element becomes the first one.
	rrb	reverse rotate b
			shift down all elements of stack_b by 1.
			The last element becomes the first one.
	rrr	rra and rrb
			do `rra` and `rrb` at the same time.
*/

#include "../includes/push_swap.h"

int	create_states_resolution(t_state **states)
{
	int				i;
	t_instruction	*tmp;
	t_state			*new;

	i = -DEPTH - 1;
	while (++i < DEPTH)
	{
		tmp = NULL;
		if (!i)
			new = new_state_instruction(states, *states, "pb");
		else if (i < 0)
		{
			new = new_state_instruction(states, *states, "ra");
			tmp = add_n_instructions(&new->instructions, "ra", DEPTH + i);
		}
		else if (i > 0)
		{
			new = new_state_instruction(states, *states, "rra");
			tmp = add_n_instructions(&new->instructions, "rra", i - 1);
		}
		execute_instructions(tmp, new->stack_a, new->stack_b);
		if (!new || (!tmp && i && i != -DEPTH && i != 1))
			return (1);
	}
	return (0);
}

int	can_pb(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a->size)
		return (0);
	if (stack_b->size < 2)
		return (1);
	else if (stack_a->array[0] > stack_b->array[0])
	{
		if (stack_a->array[0] < stack_b->array[stack_b->size - 1]
			&& stack_b->array[0] < stack_b->array[stack_b->size - 1])
			return (1);
		else if (stack_a->array[0] > stack_b->array[stack_b->size - 1]
			&& stack_b->array[0] > stack_b->array[stack_b->size - 1])
			return (1);
	}
	else if (stack_a->array[0] < stack_b->array[stack_b->size - 1]
		&& stack_b->array[stack_b->size - 1] < stack_b->array[0])
		return (1);
	return (0);
}

size_t	closer_pos_to_inf(int nb, t_stack *stack)
{
	size_t		pos;

	pos = 0;
	if (nb > stack->array[0] && nb < stack->array[stack->size - 1])
		return (pos);
	while (pos < stack->size && nb > stack->array[pos])
		pos++;
	if (pos != stack->size)
	{
		while (pos < stack->size - 1 && nb < stack->array[pos])
			pos++;
		if (pos == stack->size - 1 && stack->array[pos] > nb)
			pos = stack->size;
	}
	if (pos == stack->size)
	{
		pos = 1;
		while (pos < stack->size && stack->array[pos - 1] > stack->array[pos])
			pos++;
	}
	if (pos == stack->size)
		pos = 0;
	return (pos);
}

int	realign_and_fill_a(t_program *prg)
{
	t_instruction	*tmp;

	if (is_stack_ordered(&prg->stack_a, ZERO) == 0
		&& prg->stack_b.size == 0)
		return (0);
	if (prg->stack_b.size > 1 && align_stack_b(prg))
		return (1);
	while (prg->stack_b.size)
	{
		if (prg->stack_b.array[0] > prg->stack_a.array[prg->stack_a.size - 1]
			|| (prg->stack_b.array[0] < prg->stack_a.array[0]
				&& prg->stack_a.array[0]
				< prg->stack_a.array[prg->stack_a.size - 1]))
			tmp = add_instruction(&prg->instr, "pa");
		else
			tmp = add_instruction(&prg->instr, "rra");
		if (!tmp)
			return (1);
		execute_instructions(tmp, &prg->stack_a, &prg->stack_b);
	}
	if (align_stack_a(prg))
		return (1);
	return (0);
}

/*

*/

int	main(int ac, char **av)
{
	t_program	prg;
	int			debug;

	if (ac == 1)
		return (usage());
	if (ac < 2)
		return (0);
	if (init_stacks(ac, &av[1], &prg.stack_a, &prg.stack_b))
		return (1);
	prg.instr = NULL;
	debug = resolve(&prg);
	if (is_stack_ordered(&prg.stack_a, ZERO) == 1 && debug == 1)
	{
		free_instructions(prg.instr);
		return (ft_put_err_return_one());
	}
	print_instructions(prg.instr);
	free_prg(&prg);
	print_some(debug);
	return (0);
}
