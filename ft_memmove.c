/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 12:51:56 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/05/14 18:44:10 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static void	cpy_bwd(void *dest, const void *src, size_t n)
{
	const unsigned long int	*srcp;
	unsigned long int		*destp;
	size_t					counter;
	unsigned int			bytes_per_word;

	counter = 3;
	while ((1 << counter) < __WORDSIZE)
		counter++;
	bytes_per_word = (1 << (counter - 3));
	src += n;
	dest += n;
	while (n & (bytes_per_word - 1))
	{
		*((char *)--dest) = *((char *)--src);
		n--;
	}
	n >>= (counter - 3);
	srcp = (unsigned long int *)(src);
	destp = (unsigned long int *)(dest);
	while (n--)
		*--destp = *--srcp;
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest == src)
		return (dest);
	if (src < dest && dest < src + n)
		cpy_bwd(dest, src, n);
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
