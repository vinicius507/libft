/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 14:26:27 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/04 16:19:03 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <libft/ft_mem.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*item;

	item = ft_calloc(1, sizeof(t_list));
	if (item == NULL)
		return (NULL);
	item->content = content;
	return (item);
}
