/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vihane <vihane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:46:33 by vihane            #+#    #+#             */
/*   Updated: 2024/05/27 20:13:38 by vihane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*second;
	const char	*first;
	size_t		i;

	i = 0;
	first = s1;
	second = s2;
	while (i < n)
	{
		if (((unsigned char *)first)[i] != ((unsigned char *)second)[i])
			return (((unsigned char *)first)[i] - ((unsigned char *)second)[i]);
		i++;
	}
	return (0);
}
