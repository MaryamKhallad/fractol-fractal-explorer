/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhallad <mkhallad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 19:16:16 by mkhallad          #+#    #+#             */
/*   Updated: 2025/08/31 16:28:35 by mkhallad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
// int main(void)
// {
//     t_list *list = NULL;

//     ft_lstadd_front(&list, ft_lstnew("World"));
//     ft_lstadd_front(&list, ft_lstnew("Hello"));

//     printf("%s %s\n", (char *)list->content, (char *)list->next->content);

//     return 0;
// }