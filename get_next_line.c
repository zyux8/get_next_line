/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:31:04 by ohaker            #+#    #+#             */
/*   Updated: 2024/12/11 20:27:43 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*leftover;


}

char	*ft_read_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*result;
	int			newline;
	int			bytes_read;

	result = NULL;
	newline = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!newline)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		result = ft_strjoin(result, buffer);
		if (ft_strchr(buffer, '\n'))
			newline = 1;
	}
	return (result);
}

