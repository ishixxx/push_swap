/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vihane <vihane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:22:26 by vihane            #+#    #+#             */
/*   Updated: 2024/06/04 11:51:33 by vihane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*src;
	int		i;

	i = 0;
	src = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (src == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		src[i] = s[i];
		i++;
	}
	src[i] = '\0';
	return (src);
}
