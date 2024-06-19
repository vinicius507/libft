/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:54:20 by vgoncalv          #+#    #+#             */
/*   Updated: 2024/06/19 14:27:58 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	base_to_dec(char c, const char *base)
{
	const char	*digit;

	digit = ft_strchr(base, c);
	if (digit == NULL)
		return (-1);
	return (digit - base);
}

int	ft_atoi_base(const char *nptr, const char *base)
{
	int	num;
	int	sign;
	int	num_base;
	int	digit;

	while ((ft_isspace(*nptr)))
		nptr++;
	sign = 1;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	num = 0;
	num_base = ft_strlen(base);
	while (*nptr != '\0')
	{
		digit = base_to_dec(*nptr, base);
		if (digit == -1)
			return (num);
		num = (num * num_base) + (sign * digit);
		nptr++;
	}
	return (num);
}
