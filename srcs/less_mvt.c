/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_mvt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashitomi<ashitomi@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 20:23:51 by ashitomi          #+#    #+#             */
/*   Updated: 2022/07/19 11:39:36 by ashitomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

size_t	less_mvt_at_begin(size_t minimal_mvt,
	size_t *min_mvt, t_stack *stack_a, t_stack *stack_b)
{
	size_t		i;
	size_t		min;
	size_t		tmp[2];

	if (minimal_mvt > stack_b->size / 2)
		minimal_mvt = stack_b->size - minimal_mvt;
	min = minimal_mvt + 1;
	i = 0;
	while (++i < stack_a->size && i < minimal_mvt)
	{
		tmp[0] = closer_pos_to_inf(stack_a->array[i], stack_b);
		tmp[1] = stack_b->size - tmp[0];
		if ((tmp[0] > stack_b->size / 2 && i + tmp[1] < min)
			|| (tmp[0] >= i && tmp[0] < min) || (tmp[0] < i && i < min))
			*min_mvt = tmp[0];
		if (tmp[0] > stack_b->size / 2 && i + tmp[1] < min)
			min = i + tmp[1];
		else if (tmp[0] >= i && tmp[0] < min)
			min = tmp[0];
		else if (tmp[0] < i && i < min)
			min = i;
	}
	return (min);
}

/*
	Warn
		- `a` means `stack_a`
		- `b` means `stack_b`
*/

size_t	less_mvt_at_end(size_t minimal_mvt,
	size_t *min_mvt, t_stack *a, t_stack *b)
{
	size_t		i;
	size_t		m;
	size_t		t[2];

	if (minimal_mvt > b->size / 2)
		minimal_mvt = b->size - minimal_mvt;
	m = minimal_mvt + 1;
	i = a->size;
	while (--i > 0 && (a->size - i) < minimal_mvt)
	{
		t[0] = closer_pos_to_inf(a->array[i], b);
		t[1] = b->size - t[0];
		if ((t[0] > b->size / 2 && t[1] >= (a->size - i) && t[1] < m)
			|| (t[0] > b->size / 2 && t[1] < (a->size - i)
				&& (a->size - i) < m) || ((a->size - i) + t[0] < m))
			*min_mvt = t[0];
		if (t[0] > b->size / 2 && t[1] >= (a->size - i) && t[1] < m)
			m = t[1];
		else if (t[0] > b->size / 2
			&& t[1] < (a->size - i) && (a->size - i) < m)
			m = (a->size - i);
		else if ((a->size - i) + t[0] < m)
			m = (a->size - i) + t[0];
	}
	return (m);
}
