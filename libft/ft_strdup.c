/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhallad <mkhallad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 17:54:34 by mkhallad          #+#    #+#             */
/*   Updated: 2025/08/28 18:04:49 by mkhallad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*p;

	p = (char *)malloc(ft_strlen(s1) + 1);
	if (p == NULL)
		return (NULL);
	ft_memcpy(p, s1, ft_strlen(s1) + 1);
	return (p);
}
// int main (void)
// {
// 	char *original = "hello, world";
// 	char *copy = ft_strdup(original);
// 	if(copy)
// 	{
// 		printf("original : %s\n", original);
// 		printf("copy:    %s\n", copy);
// 		free(copy);
// 	}
// 	else
// 		printf("allocation failed");
// 	return 0;
// }