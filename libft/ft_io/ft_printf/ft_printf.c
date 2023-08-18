/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:43:06 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/04 14:59:41 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>
#include "ft_printf.h"

int	ft_vprintf(const char *format, va_list ap)
{
	int	printed;

	printed = ft_vdprintf(STDOUT_FILENO, format, ap);
	return (printed);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		printed;

	va_start(ap, format);
	printed = ft_vprintf(format, ap);
	va_end(ap);
	return (printed);
}
