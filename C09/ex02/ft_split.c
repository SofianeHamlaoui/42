/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_split.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shamlaou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/21 04:31:56 by shamlaou     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/21 20:51:40 by shamlaou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

int			ft_verifcharset(char str, char *charset)
{
	while (*charset)
	{
		if (str == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int			ft_nb_mots(char *str, char *charset)
{
	int count;
	int i;

	i = -1;
	count = 0;
	while (str[++i])
	{
		if (!ft_verifcharset(str[i], charset) && i == 0)
			count++;
		else if (ft_verifcharset(str[i], charset))
			if (!ft_verifcharset(str[i - 1], charset))
				count++;
	}
	return (count);
}

char		*ft_matab(char *str, char *charset, int *i)
{
	int		a;
	char	*dest;
	int		b;

	b = 0;
	a = 0;
	while (!ft_verifcharset(str[a + *i], charset) && str[a + *i])
		a++;
	if (!(dest = malloc(sizeof(char) * (a + 1))))
		return (0);
	while (b < a)
	{
		dest[b++] = str[*i];
		*i = *i + 1;
	}
	dest[b] = '\0';
	return (dest);
}

char		**ft_split(char *str, char *charset)
{
	int		nmots;
	int		i;
	int		a;
	char	**dest;

	i = 0;
	a = 0;
	nmots = ft_nb_mots(str, charset);
	if (!(dest = malloc(sizeof(*dest) * (nmots + 1))))
		return (0);
	while (str[i])
	{
		dest[a] = ft_matab(str, charset, &i);
		if (dest[a][0] != '\0')
			a++;
		else
			i++;
	}
	dest[a] = 0;
	return (dest);
}
