/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhallad <mkhallad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:43:27 by mkhallad          #+#    #+#             */
/*   Updated: 2025/08/28 15:09:04 by mkhallad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] == s2[i])
	{
		if (s2[i] == '\0')
			return (0);
		i++;
	}
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
// int main (void)
// {
//     printf("%d\n", ft_strncmp("hello", "hello", 5));
//     printf("%d\n", ft_strncmp("hello", "helpo", 5));
//     printf("%d\n", ft_strncmp("hello", "helloworld", 5));
//     // cuz the first 5 char r equale
//     printf("%d\n", ft_strncmp("hello", "hi", 2));
// }