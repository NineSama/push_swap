/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 22:12:27 by mfroissa          #+#    #+#             */
/*   Updated: 2022/05/07 17:53:18 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*srcsrc;
	char	*destdest;
	size_t	i;

	srcsrc = (char *)src;
	destdest = (char *)dest;
	i = 0;
	while (i < n)
	{
		destdest[i] = srcsrc[i];
		i++;
	}
	return ((void *)destdest);
}
