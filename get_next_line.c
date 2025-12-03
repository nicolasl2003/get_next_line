/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilinott <nilinott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:30:35 by nilinott          #+#    #+#             */
/*   Updated: 2025/12/03 18:52:09 by nilinott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int	nbread;
	static char buf[BUFFER_SIZE + 1];

	nbread = -1;
	fd = open("dict.txt", O_RDONLY);
	if (fd == -1)
		return (NULL);
	while (nbread != 0 || buf[nbread] != '\n')
	{
		nbread = read(fd, buf, BUFFER_SIZE);
		buf[nbread] = '\0';

		printf("%s", buf);
		if (nbread == -1)
			return (NULL);
	}
	close(fd);
}

#include <stdio.h>
int	main(void)
{
	printf("%s", get_next_line(1));
}
