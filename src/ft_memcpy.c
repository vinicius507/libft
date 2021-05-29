/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 17:55:30 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/05/15 00:13:06 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline void	*wordcpy(unsigned long int *dest,
	unsigned long int *src,
	size_t *n,
	unsigned int bytes_per_word)
{
	while (*n >= bytes_per_word)
	{
		*dest++ = *src++;
		*n -= bytes_per_word;
	}
	return (dest);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t					offset;
	size_t					counter;
	unsigned int			bpw;

	if (dest == src)
		return (dest);
	counter = 3;
	while ((1 << counter) < __WORDSIZE)
		counter++;
	bpw = (1 << (counter - 3));
	offset = 0;
	while ((unsigned long int)dest & (bpw - 1) && n)
	{
		*((char *)dest + offset) = *((char *)src + offset);
		offset++;
		n--;
	}
	offset = wordcpy(dest + offset, (void *)src + offset, &n, bpw) - dest;
	while (n--)
	{
		*(char *)(dest + offset) = *(char *)(src + offset);
		offset++;
	}
	return (dest);
}
