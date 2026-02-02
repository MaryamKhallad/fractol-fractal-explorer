/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhallad <mkhallad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 19:09:12 by mkhallad          #+#    #+#             */
/*   Updated: 2025/08/31 15:30:31 by mkhallad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
// int main (void)
// {
// 	char *str = "hello world";
// 	t_list *node = ft_lstnew(str);
// 	if (node == NULL)
// 	{
// 		printf("failed");
// 		return 1;
// 	}
// 	printf("node content: %s \n", (char *)node->content);
// 	free(node);
// 	return 0;
// }