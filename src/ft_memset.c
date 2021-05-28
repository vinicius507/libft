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

static inline void	*wordwise_set(unsigned long int *s,
	unsigned long int value,
	size_t *n,
	unsigned int bytes_per_word)
{
	while (*n >= bytes_per_word)
	{
		*s++ = value;
		*n -= bytes_per_word;
	}
	return (s);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned long int	value;
	size_t				counter;
	size_t				offset;
	unsigned int		bytes_per_word;

	value = (c & 0xff);
	counter = 3;
	while ((1 << counter) < __WORDSIZE)
		value |= (value << (1 << counter++));
	bytes_per_word = (1 << (counter - 3));
	offset = 0;
	while (((unsigned long int)s & (bytes_per_word - 1)) && n)
	{
		*((char *)s + offset++) = (char)c;
		n--;
	}
	offset = wordwise_set(s + offset, value, &n, bytes_per_word) - s;
	while (n--)
		*((char *)s + offset++) = (char)c;
	return (s);
}
