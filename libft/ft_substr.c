/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 18:51:50 by mfroissa          #+#    #+#             */
/*   Updated: 2022/05/16 08:07:19 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	lensrc;
	size_t	i;

	i = 0;
	lensrc = ft_strlen(s);
	if (len + start > lensrc)
		len = lensrc - start;
	if (start > lensrc)
		return (ft_calloc(1, sizeof (char)));
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	if (start < (unsigned int)lensrc)
	{
		while (i < len)
		{
			str[i] = s[start];
			start++;
			i++;
		}
	}
	str[i] = '\0';
	return (str);
}
/*
int	main()
{
	char	str[10] = "yocomment";

	printf("%s\n", ft_substr(str, 1, 20));
	return (0);
}*/
