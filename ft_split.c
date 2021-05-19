/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:23:29 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/05/19 16:23:29 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_wordsnum(const char *s, char c)
{
	int		is_word;
	size_t	words;

	words = 0;
	is_word = 0;
	while (*s)
	{
		if (!is_word && *s != c)
		{
			is_word = 1;
			words++;
		}
		else if (is_word && *s == c)
			is_word = 0;
		s++;
	}
	return (words);
}

static size_t	get_wordlen(const char *s, char c)
{
	size_t	offset;

	offset = 0;
	while (s[offset] && s[offset] != c)
		offset++;
	return (offset++);
}

static char	*worddup(const char *s, size_t len)
{
	char	*str;
	size_t	offset;

	str = malloc(len + 1);
	offset = 0;
	while (offset < len)
	{
		str[offset] = s[offset];
		offset++;
	}
	str[offset] = '\0';
	return (str);
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	size_t	len;
	size_t	words;
	size_t	counter;

	words = get_wordsnum(s, c);
	res = malloc((words + 1) * sizeof(char *));
	if (res == NULL)
		return (NULL);
	counter = 0;
	while (counter < words)
	{
		len = get_wordlen(s, c);
		if (len)
		{
			res[counter] = worddup(s, len);
			counter++;
		}
		s += len + 1;
	}
	res[counter] = NULL;
	return (res);
}
