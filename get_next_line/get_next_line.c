/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 19:09:33 by geonwkim          #+#    #+#             */
/*   Updated: 2024/09/06 19:09:33 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*ft_strdup(char *src)
// {
// 	char	*dest;
// 	int		i;

// 	i = 0;
// 	while (src[i])
// 		i++;
// 	dest = (char *)malloc(sizeof(char) * (i + 1));
// 	i = -1;
// 	while (src[++i])
// 		dest[i] = src[i];
// 	dest[i] = '\0';
// 	return (dest);
// }

char	*ft_strdup(char *str)
{
	int	i;
	int	len;
	char *dup;

	i = 0;
	len = 0;
	while (str[len])
		len++;
	dup = malloc(sizeof(*str) * (len + 1));
	if (dup != NULL)
	{
		while (str[i])
		{
			dup[i] = str[i];
			i++;
		}
		dup[i] = '\0';
	}
	return (dup);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		line[70000];
	static int	buffer_readed;
	static int 	buffer_pos;
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (buffer_pos >= buffer_readed)
		{
			buffer_readed = read(fd, buffer, BUFFER_SIZE);
			buffer_pos = 0;
			if (buffer_readed <= 0)
				break ;
		}
		line[i++] = buffer[buffer_pos++];
		if (line[i - 1] == '\n')
			break ;
	}
	line[i] = '\0';
	if (i == 0)
		return (NULL);
	return (ft_strdup(line));
}
