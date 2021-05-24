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

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	temp;
	size_t	offset;

	if (dest == src)
		return (dest);
	if (src > dest)
	{
		offset = -1;
		while (++offset < n)
		{
			temp = ((char *)src)[offset];
			((char *)dest)[offset] = temp;
		}
	}
	else
	{
		while (n--)
		{
			temp = ((char *)src)[n];
			((char *)dest)[n] = temp;
		}
	}
	return (dest);
}
