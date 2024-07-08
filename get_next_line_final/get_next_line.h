/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najgharb <najgharb@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:18:44 by najgharb          #+#    #+#             */
/*   Updated: 2024/05/16 12:18:45 by najgharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

char	*ft_strchr(const char *string, int c);
char	*get_next_line(int fd);
char	*extract_line(char *temp);
char	*delete_line(char *temp, int n, char *line);
char	*ft_strjoin(char *temp, char *buffer);
int		ft_strlen(char *temp);

#endif
