/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 17:56:07 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/05/12 17:56:09 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	offset;

	offset = 0;
	while (offset < n)
	{
		*((char *)dest + offset) = *((char *)src + offset);
		if (*((char *)dest + offset) == c)
			return (dest + offset + 1);
		offset++;
	}
	return (NULL);
}
