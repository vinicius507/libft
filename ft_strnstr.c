/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 21:25:58 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/05/17 21:25:58 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// TODO: Finish the lazy way

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	b_size;
	size_t	l_size;

	b_size = ft_strlen(big);
	l_size = ft_strlen(little);
	if (l_size == 0)
		return ((char *)big);
	else if (l_size > b_size)
		return (NULL);
	while (len)
	{
		if (!ft_strncmp(big, little, l_size))
			return ((char *)big);
		len--;
	}
	return (NULL);
}
