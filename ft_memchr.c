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
	size_t	offset;

	offset = 0;
	while (offset < n)
	{
		if (*((unsigned char *)s + offset) == (unsigned char)c)
			return ((void *)s + offset);
		offset++;
	}
	return (NULL);
}
