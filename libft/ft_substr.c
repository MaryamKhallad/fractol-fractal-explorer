/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhallad <mkhallad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 15:13:25 by mkhallad          #+#    #+#             */
/*   Updated: 2025/08/31 17:57:48 by mkhallad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	slen;
	size_t	i;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	if (len > slen - start)
		len = slen - start;
	sub = (char *)malloc(len + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
// int main (void)
// {
// 	char *str = "hello, world";
// 	char *sub;
// 	sub = ft_substr(str, 7, 5);

// 	printf("substring: %s\n", sub);
// 	free(sub);

// 	sub = ft_substr(str, 0, 5);
// 	printf("substring: %s\n", sub);
// 	free(sub);

// 	sub = ft_substr(str, 20, 5);
// 	printf("substring: %s\n", sub);
// 	free(sub);
// 	return 0;
// }