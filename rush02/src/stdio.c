/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   stdio.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shamlaou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/17 17:54:22 by shamlaou     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/17 19:38:48 by shamlaou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putstr(char *str)
{
	unsigned int	i;

	i = 0;
	while (*(str + i))
		write(1, str + i++, 1);
}

char	*ft_read_input(char delimiter, int fd)
{
	unsigned int	input_len;
	char			*input_buffer;

	input_len = 0;
	input_buffer = malloc(sizeof(char));
	while (1)
	{
		if (!read(fd, input_buffer + input_len, 1))
			break ;
		if ((int)*(input_buffer + input_len) == (int)delimiter)
			break ;
		input_len += 1;
		input_buffer = realloc(input_buffer, (input_len + 1) * sizeof(char));
	}
	input_buffer = realloc(input_buffer, (input_len + 1) * sizeof(char));
	*(input_buffer + input_len) = '\0';
	return (input_buffer);
}
