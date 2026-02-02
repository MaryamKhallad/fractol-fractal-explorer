/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhallad <mkhallad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 17:36:48 by mkhallad          #+#    #+#             */
/*   Updated: 2025/08/28 16:35:26 by mkhallad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	size_t				i;

	i = 0;
	str1 = s1;
	str2 = s2;
	while (i < n && str1[i] == str2[i])
		i++;
	if (i < n)
		return (str1[i] - str2[i]);
	return (0);
}
// int main (void)
// {
// 	char a[] = "hello";
// 	char b[] = "hello";
// 	char c[] = "helio";
// 	printf("%d\n", ft_memcmp(a,b,5));
// 	printf("%d\n", ft_memcmp(a,c,5));
// 	printf("%d\n", ft_memcmp(c,a,5));
// 	printf("%d\n", ft_memcmp(a,c,3));
// 	return 0;
// }
