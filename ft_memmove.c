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
	char	*temp;
	size_t	offset;

	temp = malloc(n);
	offset = -1;
	while (++offset < n)
		temp[offset] = ((char *)src)[offset];
	offset = -1;
	while (++offset < n)
		((char *)dest)[offset] = temp[offset];
	free(temp);
	return (dest);
}
