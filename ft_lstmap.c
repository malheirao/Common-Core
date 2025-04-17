/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmanzani <lmanzani@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 22:49:47 by lmanzani          #+#    #+#             */
/*   Updated: 2025/04/17 22:49:47 by lmanzani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

static t_list	*ft_newl(t_list *list, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	void	*content;

	if (!list || !f || !del)
		return (NULL);
	content = f(list->content);
	new_lst = ft_lstnew(content);
	if (!new_lst)
	{
		del(content);
		return (NULL);
	}
	return (new_lst);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*head;

	new_lst = ft_newl(lst, f, del);
	if (!new_lst)
		return (NULL);
	head = new_lst;
	lst = lst->next;
	while (lst)
	{
		new_lst->next = ft_lstnew(f(lst->content));
		if (!new_lst->next)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		new_lst = new_lst->next;
		lst = lst->next;
	}
	new_lst->next = NULL;
	return (head);
}