/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 14:44:58 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/05 16:13:46 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stddef.h>

void	ft_lstadd_back(t_list **lst, t_list *node)
{
	t_list	*temp;

	if (lst == NULL || node == NULL)
		return ;
	if (*lst == NULL)
		*lst = node;
	else
	{
		temp = ft_lstlast(*lst);
		temp->next = node;
		node->prev = temp;
	}
}
