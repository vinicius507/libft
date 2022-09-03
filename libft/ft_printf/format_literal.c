/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_literal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 19:25:36 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/03 14:44:43 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <libft/ft_string.h>

char	*format_literal(t_arg *arg)
{
	char		*str;

	str = ft_strdup("%");
	if (str == NULL)
		return (NULL);
	if (apply_width_literal(&str, arg))
		return (NULL);
	arg->printed += ft_strlen(str);
	return (str);
}
