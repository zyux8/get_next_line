/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:27:54 by ohaker            #+#    #+#             */
/*   Updated: 2025/01/06 21:31:26 by ohaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(GET_NEXT_LINE_H)
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_read_line(int fd);
int		ft_strlen(char *str);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_strchr(const char *str, char c);
char	*get_left(char *str);
char	*ft_get_line(char *str);
char	*ft_strdup(char *s);

#endif // GET_NEXT_LINE_H
