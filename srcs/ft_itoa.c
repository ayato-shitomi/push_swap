/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashitomi<ashitomi@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 11:57:37 by ashitomi          #+#    #+#             */
/*   Updated: 2022/07/19 11:39:36 by ashitomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			cnt;
	char			*too;
	const char		*frm;

	frm = (const char *)src;
	too = (char *)dst;
	cnt = 0;
	if (frm == NULL && too == NULL)
		return (NULL);
	while (cnt < n)
	{
		too[cnt] = frm[cnt];
		cnt++;
	}
	return (dst);
}

static size_t	ft_count(int num)
{
	int		i;
	size_t	size;

	i = num;
	size = 1;
	if (i < 0)
	{
		i = -i;
		size++;
	}
	while (10 <= i)
	{
		i = i / 10;
		size++;
	}
	return (size);
}

static char	*ft_return_intmin(void)
{
	char	*res;

	res = (char *)ft_calloc(12, sizeof(char));
	if (!res)
		return (NULL);
	ft_memcpy(res, "-2147483648", 11);
	return (res);
}

char	*ft_itoa(int n)
{
	size_t	size;
	char	*result;

	if (n == -2147483648)
		return (ft_return_intmin());
	size = ft_count(n) - 1;
	result = (char *)ft_calloc(size + 2, sizeof(char));
	if (!result)
		return (NULL);
	if (n < 0)
	{
		n = -n;
		result[0] = '-';
	}
	while (10 <= n)
	{
		result[size--] = 48 + (n % 10);
		n = n / 10;
	}
	result[size] = 48 + n;
	return (result);
}
