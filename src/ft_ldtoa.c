/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgocalv <vgocalv@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 11:07:17 by vgocalv           #+#    #+#             */
/*   Updated: 2021/08/09 11:07:17 by vgocalv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	get_nbr_str(char *str, long double n,
	size_t precision, size_t size_int)
{
	int		temp;
	size_t	offset;

	temp = n;
	offset = n < 0;
	while (offset < size_int)
	{
		if (n >= 0)
			str[offset++] = (int)(temp % 10) + '0';
		else
			str[offset++] = (int)((temp % 10) * -1) + '0';
		temp /= 10;
	}
	if (n < 0)
		n *= -1;
	offset += 1;
	while (precision--)
	{
		n = n - (int)n;
		str[offset++] = (int)(n * 10) + '0';
		n *= 10;
	}
}

char	*ft_ldtoa(long double n, size_t precision)
{
	int		temp;
	char	*str;
	size_t	size_int;

	if (precision < 0)
		return (NULL);
	size_int = 1 + (n < 0);
	temp = n / 10;
	while (temp)
	{
		size_int++;
		temp /= 10;
	}
	str = ft_calloc(size_int + precision + 2, sizeof(char));
	if (str == NULL)
		return (NULL);
	str[size_int] = '.';
	if (n < 0)
		str[0] = '-';
	get_nbr_str(str, n, precision, size_int);
	return (str);
}
