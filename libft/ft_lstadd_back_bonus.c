/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhallad <mkhallad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 19:37:42 by mkhallad          #+#    #+#             */
/*   Updated: 2025/08/31 16:24:44 by mkhallad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		ptr = ft_lstlast(*lst);
		ptr ->next = new;
	}
}
// int main(void)
// {
//     t_list *list = NULL;

//     ft_lstadd_back(&list, ft_lstnew("Hello"));
//     ft_lstadd_back(&list, ft_lstnew("World"));

//     printf("%s %s\n", (char *)list->content, (char *)list->next->content);

//     return 0;
// }
