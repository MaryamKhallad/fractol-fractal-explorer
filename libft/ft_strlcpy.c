/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhallad <mkhallad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 19:15:10 by mkhallad          #+#    #+#             */
/*   Updated: 2025/08/27 17:51:29 by mkhallad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	i = 0;
	if (size != 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (src_len);
}
// int main()
// {
//     char src[] = "Hello, World!";
//     char dest[50];  // Make sure it's large enough to hold the copied string

//     size_t size = 10;  // Adjust the size as needed

//     size_t result = ft_strlcpy(dest, src, size);

//     // Print the result
//     printf("Source: %s\n", src);
//     printf("Destination (after strlcpy): %s\n", dest);
//     printf("Returned value (ft_strlen of source): %zu\n", result);

//     return (0);
// }