/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 14:28:42 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/05 16:19:38 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stddef.h>

void	ft_lstadd_front(t_list **lst, t_list *node)
{
	if (lst == NULL || node == NULL)
		return ;
	if (*lst != NULL)
	{
		node->next = *lst;
		(*lst)->prev = node;
	}
	*lst = node;
}
