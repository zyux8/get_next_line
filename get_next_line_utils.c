/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:31:25 by ohaker            #+#    #+#             */
/*   Updated: 2025/01/07 15:47:15 by ohaker           ###   ########.fr       */
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
	if (c == '\0')
		return ((char *)str);
	return (NULL);
}

char	*ft_strjoin(char *str1, char *str2)
{
	int		x;
	int		tlen;
	char	*buffer;
	char	*temp;

	if (!str1)
		str1 = ft_strdup("");
	if (!str2)
		str2 = "";
	tlen = ft_strlen(str1) + ft_strlen(str2);
	buffer = malloc((tlen + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	x = 0;
	temp = str1;
	while (*str1)
		buffer[x++] = *str1++;
	while (*str2)
		buffer[x++] = *str2++;
	free(temp);
	buffer[x] = '\0';
	return (buffer);
}

int	ft_strlen(char *str)
{
	int	x;

	if (!str)
		return (0);
	x = 0;
	while (str[x])
		x++;
	return (x);
}

char	*ft_strdup(char *s)
{
	char	*str;
	size_t	x;

	if (!s)
		return (NULL);
	x = 0;
	str = malloc((ft_strlen(s) + 1) * sizeof(*s));
	if (!str)
		return (NULL);
	while (s[x])
	{
		str[x] = s[x];
		x++;
	}
	str[ft_strlen(s)] = '\0';
	return (str);
}
