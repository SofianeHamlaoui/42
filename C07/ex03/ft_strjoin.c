/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shamlaou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/14 13:31:23 by shamlaou     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/19 16:07:12 by shamlaou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*dest;
	int		len_str;
	int		i;

	len_str = 0;
	i = -1;
	while (++i < size)
		len_str = len_str + ft_strlen(strs[i]);
	len_str = len_str + ft_strlen(sep) * (size - 1);
	if (!(dest = malloc(sizeof(char) * (len_str + 1))))
		return (NULL);
	*dest = 0;
	i = -1;
	while (++i < size)
	{
		ft_strcat(dest, strs[i]);
		if (!(i == size - 1))
			ft_strcat(dest, sep);
	}
	if (size == 0)
	{
		dest = NULL;
		return (dest);
	}
	return (dest);
}
