/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhallad <mkhallad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 19:31:46 by mkhallad          #+#    #+#             */
/*   Updated: 2025/08/31 16:27:45 by mkhallad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*ptr;

	if (!lst)
		return (NULL);
	ptr = lst;
	while (ptr->next != NULL)
		ptr = ptr->next;
	return (ptr);
}
// int main(void)
// {
//     t_list *list = NULL;

//     ft_lstadd_back(&list, ft_lstnew("Hello"));
//     ft_lstadd_back(&list, ft_lstnew("World"));

//     t_list *last = ft_lstlast(list);
//     printf("Last node: %s\n", (char *)last->content);

//     return 0;
// }