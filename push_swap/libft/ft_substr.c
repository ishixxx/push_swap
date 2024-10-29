/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vihane <vihane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:12:31 by vihane            #+#    #+#             */
/*   Updated: 2024/05/30 12:50:55 by vihane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sschaine;
	size_t	i;
	size_t	j;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	sschaine = ft_calloc((len + 1), sizeof(char));
	if (sschaine == NULL)
		return (NULL);
	j = start;
	i = 0;
	while ((i < len) && j < ft_strlen(s))
	{
		sschaine[i] = s[j];
		i++;
		j++;
	}
	sschaine[i] = '\0';
	return (sschaine);
}
