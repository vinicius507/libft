/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 17:57:04 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/05/12 17:57:06 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;
	size_t	offset;

	s_len = ft_strlen(s);
	if (s_len < start)
		return (NULL);
	sub = malloc(len + 1);
	if (sub == NULL)
		return (NULL);
	offset = 0;
	while (offset < len && offset + start < s_len)
	{
		sub[offset] = s[offset + start];
		offset++;
	}
	sub[offset] = '\0';
	return (sub);
}
