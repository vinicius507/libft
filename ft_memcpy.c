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
	size_t	offset;

	if (dest == src)
		return (dest);
	offset = 0;
	while (offset < n)
	{
		*((unsigned char *)dest + offset) = *((unsigned char *)src + offset);
		offset++;
	}
	return (dest);
}
