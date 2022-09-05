/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:36:09 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/04 14:59:03 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <libft/ft_string.h>

/**
 * @brief Writes a string on a file descriptor.
 * @param s
 */
void	ft_putstr_fd(char *s, int fd)
{
	size_t	size;

	if (s == NULL)
		return ;
	size = ft_strlen(s);
	(void)write(fd, s, size);
}
