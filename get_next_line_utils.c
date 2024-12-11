/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:31:25 by ohaker            #+#    #+#             */
/*   Updated: 2024/12/10 20:51:28 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}
	return (NULL);
}

char	*ft_strjoin(char *str1, char *str2)
{
	int		x;
	char	*buffer;
	int		tlen;

	if (str1 == NULL || str2 == NULL)
		return (NULL);
	tlen = ft_strlen(str1) + ft_strlen(str2);
	buffer = malloc((tlen + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	x = 0;
	while (*str1)
		buffer[x++] = *str1++;
	while (*str2)
		buffer[x++] = *str2++;
	buffer[x] = '\0';
	return (buffer);
}

int	ft_strlen(char *str)
{
	int	x;

	x = 0;
	while (str[x])
		x++;
	return (x);
}
