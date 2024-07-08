/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najgharb <najgharb@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:18:31 by najgharb          #+#    #+#             */
/*   Updated: 2024/05/16 12:18:32 by najgharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char *temp)
{
	int		n;
	char	*line;

	n = 0;
	if (!temp || !temp[0])
		return (NULL);
	while (temp[n] != '\0' && temp[n] != '\n')
		n++;
	if (temp[n] == '\n')
		n++;
	line = malloc(n + 1);
	n = 0;
	while (temp[n] != '\0' && temp[n] != '\n')
	{
		line[n] = temp[n];
		n++;
	}
	line[n] = temp[n];
	if (line[n] == '\n')
		line[n + 1] = '\0';
	return (line);
}

char	*delete_line(char *temp, int n, char *line)
{
	int		index;
	char	*new_temp;

	index = 0;
	if (!temp || !temp[0])
	{
		free(temp);
		return (NULL);
	}
	while (temp[n + index] != '\0')
		index++;
	new_temp = malloc(index + 1);
	index = 0;
	while (temp[n + index] != '\0')
	{
		new_temp[index] = temp[n + index];
		index++;
	}
	new_temp[index] = '\0';
	free(temp);
	return (new_temp);
}

char	*ft_strchr(const char *string, int c)
{
	int	i;

	i = 0;
	if (!string)
		return (NULL);
	while (string[i] != '\0')
	{
		if (string[i] == (unsigned char)c)
			return ((char *)(string + i));
		i++;
	}
	if (string[i] == (unsigned char)c)
		return ((char *)(string + i));
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*s;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	s = (char *) malloc(i + j + 1);
	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 != NULL && s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		s[i + j] = s2[j];
		j++;
	}
	s[i + j] = '\0';
	free(s1);
	return (s);
}

int	ft_strlen(char *s)
{
	int	cont;

	if (s == NULL)
	{
		return (0);
	}
	cont = 0;
	while (*s != '\0')
	{
		s++;
		cont++;
	}
	return (cont);
}
