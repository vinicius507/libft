/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 19:28:56 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/05/16 19:28:56 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	offset;

	offset = 0;
	if (size > 0)
	{
		while (offset < size - 1)
		{
			dest[offset] = src[offset];
			offset++;
		}
		dest[offset] = '\0';
	}
	offset = 0;
	while (src[offset] != '\0')
		offset++;
	return (offset);
}