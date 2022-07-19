/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ac.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashitomi<ashitomi@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:39:36 by ashitomi          #+#    #+#             */
/*   Updated: 2022/07/19 11:39:36 by ashitomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_ac(int ac)
{
	if (ac == 2 || ac == 1)
		return (1);
	else
		return (0);
}

int	write_err_ac(int ac, char **av)
{
	if (ac == 2 && (av[1][0] == 'h' || (av[1][0] == '-' && av[1][1] == 'h')))
		return (usage());
	return (0);
}
