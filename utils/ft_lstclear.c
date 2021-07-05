/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturquin <mturquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 15:43:20 by mturquin          #+#    #+#             */
/*   Updated: 2021/02/10 13:46:20 by mturquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minirt.h"

void		ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (!*del)
		return ;
	while (*lst)
	{
		tmp = *lst;
		del((*lst)->content);
		*lst = tmp->next;
		free(tmp);
	}
	lst = NULL;
}
