/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashitomi<ashitomi@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 22:48:42 by ashitomi          #+#    #+#             */
/*   Updated: 2022/05/23 22:48:42 by ashitomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	if_do_ra(t_program *prg)
{
	t_stack	*tmp;

	tmp = copy_stack(&prg->stack_a);
	rotate_stack(tmp);
	if (is_stack_ordered(tmp, ZERO) == 0)
	{
		rotate_stack(&prg->stack_a);
		free_stack(tmp);
		return (7);
	}
	free_stack(tmp);
	return (0);
}

int	if_do_rra(t_program *prg)
{
	t_stack	*tmp;

	tmp = copy_stack(&prg->stack_a);
	reverse_rotate_stack(tmp);
	if (is_stack_ordered(tmp, ZERO) == 0)
	{
		reverse_rotate_stack(&prg->stack_a);
		free_stack(tmp);
		return (8);
	}
	free_stack(tmp);
	return (0);
}

int	if_do_rra_two(t_program *prg)
{
	t_stack	*tmp;

	tmp = copy_stack(&prg->stack_a);
	reverse_rotate_stack(tmp);
	reverse_rotate_stack(tmp);
	if (is_stack_ordered(tmp, ZERO) == 0)
	{
		reverse_rotate_stack(&prg->stack_a);
		reverse_rotate_stack(&prg->stack_a);
		free_stack(tmp);
		return (9);
	}
	free_stack(tmp);
	return (0);
}

int	resolve_return(t_program *prg)
{
	if (bruteforce_order_a(prg))
		return (1);
	if (realign_and_fill_a(prg))
		return (1);
	if (if_do_ra(prg) == 7)
		return (7);
	else if (if_do_rra(prg) == 8)
		return (8);
	else if (if_do_rra_two(prg) == 9)
		return (9);
	return (0);
}
