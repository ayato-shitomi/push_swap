/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashitomi<ashitomi@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 20:23:51 by ashitomi          #+#    #+#             */
/*   Updated: 2022/07/19 11:39:36 by ashitomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
	swap the first two elemets at the top of stack
*/

void	swap_stack(t_stack *stack)
{
	int	tmp;

	if (stack->size > 1)
	{
		tmp = stack->array[0];
		stack->array[0] = stack->array[1];
		stack->array[1] = tmp;
	}
}

/*
	take the first elemets at the top of stack2 and put it at the top of stack1
*/

void	push_stack(t_stack *stack1, t_stack *stack2)
{
	if (stack2->size > 0)
	{
		stack1->size++;
		reverse_rotate_stack(stack1);
		stack1->array[0] = stack2->array[0];
		rotate_stack(stack2);
		stack2->size--;
	}
}
