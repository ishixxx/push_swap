/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vihane <vihane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 20:06:59 by vihane            #+#    #+#             */
/*   Updated: 2024/05/27 19:33:31 by vihane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	found;
	char	*result;
	int		i;

	found = (char) c;
	result = NULL;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == found)
			result = (char *) &s[i];
		i++;
	}
	if (s[i] == found)
		result = (char *) &s[i];
	return (result);
}
