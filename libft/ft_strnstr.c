/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhallad <mkhallad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 15:10:06 by mkhallad          #+#    #+#             */
/*   Updated: 2025/08/28 15:35:10 by mkhallad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!haystack && len == 0)
		return (NULL);
	if (needle[0] == '\0')
		return ((char *)(haystack));
	i = 0;
	while (i < len && haystack[i])
	{
		j = 0;
		while ((i + j) < len && haystack[i + j] == needle[j]
			&& needle[j] != '\0')
			j++;
		if (needle[j] == '\0')
			return ((char *)(&haystack[i]));
		i++;
	}
	return (NULL);
}
// int main (void)
// {
//     const char *text = "hello, world";
//     printf("%s\n", ft_strnstr(text, "world", 13));
//     printf("%s\n", ft_strnstr(text, "world", 5));
//     printf("%s\n", ft_strnstr(text, "", 13));
// }