/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 17:56:19 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/05/14 18:05:34 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned long int	*ls;
	unsigned long int	value;
	size_t				offset;
	size_t				counter;
	unsigned int		bytes_per_word;

	value = (c & 0xff);
	counter = 3;
	while ((1 << counter) < __WORDSIZE)
		value |= value << (1 << counter++);
	bytes_per_word = (1 << (counter - 3));
	offset = 0;
	while (n & (bytes_per_word - 1))
	{
		*((char *)s + offset++) = (char)c;
		n--;
	}
	ls = (unsigned long int *)(s + offset);
	n >>= (counter - 3);
	while (n--)
		*ls++ = value;
	return (s);
}
