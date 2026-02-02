/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhallad <mkhallad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 15:38:02 by mkhallad          #+#    #+#             */
/*   Updated: 2025/09/01 12:33:18 by mkhallad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char			*src;
	unsigned char				uc;
	size_t						i;

	src = s;
	uc = c;
	i = 0;
	while (i < n)
	{
		if (src[i] == uc)
			return ((void *)(src + i));
		i++;
	}
	return (NULL);
}
// int main (void)
// {
// 	char str[] = "hello, world!";
// 	char *res = ft_memchr(str, 'w', 13);
// 	if (res)
// 		printf("found : %s\n", res);
// 	else
// 	printf("not found\n");

// 	return 0;
// }