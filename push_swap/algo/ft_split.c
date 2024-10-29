/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vihane <vihane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 21:34:01 by vihane            #+#    #+#             */
/*   Updated: 2024/10/12 21:34:05 by vihane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	nb_of_word(char *str, char separator)
{
	int	countofword;
	int	i;

	i = 0;
	countofword = 0;
	while (str[i])
	{
		while (str[i] == separator)
			i++;
		while (str[i] && str[i] != separator)
		{
			++countofword;
			while (str[i] && str[i] != separator)
				i++;
		}
	}
	return (countofword);
}

char	*allocate_next_word(char **s, char separator)
{
	char	*next_word;
	char	*str;
	int		i;
	int		len;

	str = *s;
	while (*str == separator)
		str++;
	len = 0;
	while ((str[len] != separator) && str[len])
		len++;
	next_word = malloc((len + 1) * sizeof(char));
	if (!next_word)
		return (NULL);
	next_word[len] = '\0';
	i = 0;
	while (i < len)
	{
		next_word[i] = str[i];
		i++;
	}
	*s = str + len;
	return (next_word);
}

char	**ft_split(char *str, char separator)
{
	int		word_number;
	int		i;
	char	**result_str;

	word_number = nb_of_word(str, separator);
	if (!word_number)
		exit(1);
	result_str = malloc((word_number + 1) * sizeof(char *));
	if (!result_str)
		return (NULL);
	result_str[word_number] = NULL;
	i = 0;
	while (i < word_number)
	{
		result_str[i] = allocate_next_word(&str, separator);
		if (!result_str[i])
		{
			while (--i)
				free(result_str[i]);
			free(result_str);
			return (NULL);
		}
		i++;
	}
	return (result_str);
}
