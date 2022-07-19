/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashitomi<ashitomi@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 20:23:51 by ashitomi          #+#    #+#             */
/*   Updated: 2022/07/19 11:39:36 by ashitomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
static void	put(t_program *prg)
{
	int	m = 0;
	char *str;
	write(1, "debug :", ft_strlen("debug :"));
	while (m < (int)prg->stack_a.size)
	{
		str = ft_itoa(prg->stack_a.array[m]);
		write(1, str, ft_strlen(str));
		write(1, " ", 1);
		free(str);
		m++;
	}
	write(1, "\n\n", 2);
}
*/

int	main(int ac, char **av)
{
	t_program	prg;
	t_program	prg2;
	int			debug;

	if (check_ac(ac))
		return (write_err_ac(ac, av));
	if (init_stacks(ac, &av[1], &prg.stack_a, &prg.stack_b))
		return (1);
	instr_null(&prg);
	if (is_stack_ordered(&prg.stack_a, ZERO) == 0)
		return (free_prg(&prg));
	debug = resolve(&prg);
	if (is_stack_ordered(&prg.stack_a, ZERO) == 1 && debug == 1)
		return (free_prg(&prg) + ft_put_err_return_one());
	if (6 <= prg.stack_a.size && prg.stack_a.size < 100
		&& is_stack_ordered(&prg.stack_a, ZERO) == 1)
	{
		print_ins_and_some_and_free(&prg, debug);
		if (init_stacks(ac, &av[1], &prg2.stack_a, &prg2.stack_b))
			return (1);
		return (second_resolve(&prg2) + free_prg(&prg2));
	}
	return (print_ins_and_some(&prg, debug) + free_prg(&prg));
}
