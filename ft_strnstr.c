/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedricmartin <cedricmartin@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:03:27 by cedricmarti       #+#    #+#             */
/*   Updated: 2024/11/04 18:23:40 by cedricmarti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strnstr(const char *big, const char *little, size_t len)
{
    size_t  i;
    size_t  j;
    size_t  len_little;

    if (little[0] == '\0')
        return ((char *) big);
    i = 0;
    len_little = ft_strlen(little);
    while (big[i] && i < len)
    {
        j = 0;
        while (big[i + j] && little[j] && i + j < len && big[i + j] == little[j])
            j++;
        if (j == len_little)
            return ((char *) big + i);
        i++;
    }
    return (NULL);
}