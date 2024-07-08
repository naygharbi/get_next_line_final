/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najgharb <najgharb@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:18:40 by najgharb          #+#    #+#             */
/*   Updated: 2024/05/16 12:18:41 by najgharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_temp(int fd, char *temp, char *buffer)
{
	ssize_t	byte_read;

	byte_read = 1;
	while (!ft_strchr(temp, '\n') && byte_read != 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			free(temp);
			return (NULL);
		}
		buffer[byte_read] = '\0';
		temp = ft_strjoin(temp, buffer);
	}
	free(buffer);
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*temp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	temp = get_temp(fd, temp, buffer);
	line = extract_line(temp);
	temp = delete_line(temp, ft_strlen(line), line);
	return (line);
}

/* int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	(void)argc;
	(void)argv;
	fd = open("gnl.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (0);
} */
