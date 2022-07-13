/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashitomi<ashitomi@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 20:23:51 by ashitomi          #+#    #+#             */
/*   Updated: 2022/05/21 20:23:51 by ashitomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*ft_strdup_char(const char *str, char stop)
{
	int		i;
	char	*ret;

	i = 0;
	while (str[i] && str[i] != stop)
		i++;
	ret = malloc((i + 1) * sizeof(char));
	if (!ret)
		return (0);
	i = -1;
	while (str[++i] && str[i] != stop)
		ret[i] = str[i];
	ret[i] = '\0';
	return (ret);
}

int	ft_atoi_pushswap(const char *str, int *num)
{
	char	*ptr;
	long	nbr;
	int		sign;
	size_t	i;

	ptr = (char *)str;
	nbr = 0;
	sign = 1;
	if (*ptr == '-' && ptr++)
		sign *= -1;
	if (*ptr == '\0')
		return (1);
	i = 0;
	while (*ptr >= '0' && *ptr <= '9' && i++ < 10)
		nbr = nbr * 10 + *ptr++ - '0';
	if (*ptr != '\0' || nbr * sign > 2147483647 || nbr * sign < -2147483648)
		return (1);
	*num = nbr * sign;
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	print_some(int	debug)
{
	if (debug == 7)
		write(1, "ra\n", 3);
	if (debug == 8)
		write(1, "rra\n", 4);
	if (debug == 9)
	{
		write(1, "rra\n", 4);
		write(1, "rra\n", 4);
	}
	return ;
}
