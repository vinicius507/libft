/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:54:51 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/05/22 16:54:51 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	counter;
	int	digits;

	digits = 1;
	counter = n / 10;
	while (counter)
	{
		counter /= 10;
		digits++;
	}
	if (n < 0)
		ft_putchar_fd('-', fd);
	else
		n *= -1;
	while (digits--)
	{
		ft_putchar_fd((n % 10) + '0', fd);
		n /= 10;
	}
}
