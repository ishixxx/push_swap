/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vihane <vihane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:13:11 by vihane            #+#    #+#             */
/*   Updated: 2024/06/04 17:04:25 by vihane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	void	*count;

	if (size != 0 && nmemb * size / size != nmemb)
		return (0);
	count = 0;
	total_size = size * nmemb;
	count = malloc(total_size);
	if (!count)
		return (NULL);
	ft_bzero(count, total_size);
	return (count);
}
