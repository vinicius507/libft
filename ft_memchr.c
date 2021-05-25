/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 18:15:51 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/05/16 18:15:51 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*start;
	char	*end;

	start = (char *)s;
	end = (char *)s + n;
	while (start < end)
	{
		if (*start == (char)c)
			return (start);
		start++;
	}
	return (NULL);
}
