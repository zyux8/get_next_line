/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:31:04 by ohaker            #+#    #+#             */
/*   Updated: 2024/12/21 19:54:34 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*result;
	int			bytes_read;

	result = NULL;
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		result = ft_strjoin(result, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (result);
}

char	*ft_get_line(char *str)
{
	int		x;
	char	*buffer;

	if (!str || !*str)
		return (NULL);
	x = 0;
	while (str[x] && str[x] != '\n')
		x++;
	if (str[x] == '\n')
		x++;
	buffer = malloc(x + 1);
	if (!buffer)
		return (NULL);
	x = 0;
	while (str[x] && str[x] != '\n')
	{
		buffer[x] = str[x];
		x++;
	}
	if (str[x] == '\n')
		buffer[x++] = '\n';
	buffer[x] = '\0';
	return (buffer);
}

char	*get_left(char *str)
{
	int		x;
	int		y;
	char	*line;
	int		len;

	len = ft_strlen(str);
	if (!str)
	{
		free(str);
		return (NULL);
	}
	x = 0;
	while (str[x] && str[x] != '\n')
		x++;
	if (str[x] == '\n')
		x++;
	if (x >= len)
	{
		free(str);
		return (NULL);
	}
	line = malloc(len - x + 1);
	if (!line)
		return (NULL);
	y = 0;
	while (str[x])
		line[y++] = str[x++];
	line[y] = '\0';
	free(str);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*new_data;
	static char	*leftover;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	new_data = ft_read_line(fd);
	if (!new_data && !leftover)
	{
		free(new_data);
		return (NULL);
	}
	temp = leftover;
	leftover = ft_strjoin(leftover, new_data);
	free(temp);
	free(new_data);
	line = ft_get_line(leftover);
	temp = leftover;
	leftover = get_left(leftover);
	free(temp);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("test.txt", O_RDONLY);
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("Line: %s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }
