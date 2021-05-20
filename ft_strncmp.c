/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 21:43:46 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/05/17 21:43:46 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	offset;

	offset = 0;
	while (offset < n)
	{
		if (s1[offset] != s2[offset])
			return (s1[offset] - s2[offset]);
		offset++;
	}
	return (0);
}
