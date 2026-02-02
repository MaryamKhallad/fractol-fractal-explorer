/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhallad <mkhallad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 19:22:42 by mkhallad          #+#    #+#             */
/*   Updated: 2025/08/31 16:30:13 by mkhallad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
// int main(void)
// {
// 	t_list a = {"one", NULL}, b = {"two", NULL}, c = {"three", NULL};
// 	a.next = &b; b.next = &c;
// 	printf("List size: %d\n", ft_lstsize(&a));
// }