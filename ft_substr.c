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
	size_t	size;
	size_t	limit;

	size = ft_strlen(s);
	if (size > start)
		return (NULL);
	if (start + len > size)
		limit = size;
	else
		limit = start + len;
	sub = malloc(limit - start + 1);
	if (sub == NULL)
		return (NULL);
	s += start;
	ft_strlcpy(sub, s, len);
	return (sub);
}
