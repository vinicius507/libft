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
	int		cmp_value;
	size_t	offset;

	cmp_value = 0;
	if (n > 0)
	{
		offset = 0;
		while (offset < n - 1
			&& s1[offset] != '\0'
			&& s2[offset] != '\0' && s1[offset] == s2[offset])
			offset++;
		cmp_value = (unsigned char)s1[offset] - (unsigned char)s2[offset];
	}
	return (cmp_value);
}
