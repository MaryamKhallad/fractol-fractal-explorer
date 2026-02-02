/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhallad <mkhallad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:52:39 by mkhallad          #+#    #+#             */
/*   Updated: 2025/08/28 17:53:31 by mkhallad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr != NULL)
		ft_memset(ptr, 0, nmemb * size);
	return (ptr);
}
// int main (void)
// {
// 	int *arr = ft_calloc(5, sizeof(int));
// 	if (!arr)
// 	{
// 		printf("allocation failed\n");
// 		return 1;
// 	}
// 	for (int i = 0; i < 5 ; i++)
// 	{
// 		printf("%d", arr[i]);
// 	}

// 	printf("\n");
// 	free(arr);
// 	return 0;
// } //op : 0 0 0 0 0