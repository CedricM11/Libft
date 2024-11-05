/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedricmartin <cedricmartin@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:52:03 by cedricmarti       #+#    #+#             */
/*   Updated: 2024/11/05 17:58:39 by cedricmarti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_striteri(char *s, void (*f)(unsigned int, char*))
{
    unsigned int    i;

    if (!s || !f)
        return;
    i = 0;
    while (s[i])
    {
        (*f)(i, s + i);
        i++;
    }
}