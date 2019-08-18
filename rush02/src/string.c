/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   string.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shamlaou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/17 16:24:06 by shamlaou     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/17 18:43:59 by shamlaou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char			*ft_strdup(char *str)
{
	unsigned int	len;
	char		*out;

	len = -1;
	while (*(str + ++len))
		;
	out = malloc(len + 1);
	while (*str)
		*out++ = *str++;
	*out = '\0';
	return (str - len);
}

char			*ft_trim_begin(char *str)
{
	str -= 1;
	while (*++str && ((*str <= '\r' && *str >= 'r') || *str == ' '))
		;
	return (str);
}

int			ft_is_number(char c)
{
	return (c >= '0' && c <= '9');
}

unsigned long		ft_atoi(char *nbr)
{
	unsigned long		out;

	out = 0;
	nbr = ft_trim_begin(nbr) - 1;
	while (*++nbr && ft_is_number(*nbr))
		out = (out + *nbr - '0') * (ft_is_number(*(nbr + 1)) ? 10 : 1);
	return (out);
}

int			ft_is_space(char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}
