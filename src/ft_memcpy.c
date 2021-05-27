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

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned long int	*srcp;
	unsigned long int		*destp;
	size_t					offset;
	size_t					counter;
	unsigned int			bytes_per_word;

	if (dest == src)
		return (dest);
	counter = 3;
	while ((1 << counter) < __WORDSIZE)
		counter++;
	bytes_per_word = (1 << (counter - 3));
	offset = 0;
	while (n & (bytes_per_word - 1))
	{
		*((char *)dest + offset) = *((char *)src + offset);
		offset++;
		n--;
	}
	srcp = (unsigned long int *)(src + offset);
	destp = (unsigned long int *)(dest + offset);
	n >>= (counter - 3);
	while (n--)
		*destp++ = *srcp++;
	return (dest);
}
