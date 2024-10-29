/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vihane <vihane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:55:01 by vihane            #+#    #+#             */
/*   Updated: 2024/06/04 11:49:39 by vihane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	len_size(int n)
{
	long	nbr;
	int		i;

	nbr = n;
	i = 0;
	if (nbr < 0)
	{
		nbr = nbr * -1;
		i++;
	}
	if (nbr == 0)
		nbr = 1;
	while (nbr > 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long int		num;
	char			*result;
	int				len;

	num = n;
	len = len_size(n);
	result = (char *)malloc(sizeof(char) * len + 1);
	if (!result)
		return (NULL);
	result[len--] = 0;
	if (num == 0)
	{
		result[0] = '0';
	}
	if (n < 0)
	{
		result[0] = '-';
		num = num * -1;
	}
	while (num > 0)
	{
		result[len--] = num % 10 + '0';
		num = num / 10;
	}
	return (result);
}
