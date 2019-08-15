/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strs_to_tab.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shamlaou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/14 15:34:58 by shamlaou     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/14 22:06:04 by shamlaou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int						ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*(str + i))
	{
		i++;
	}
	return (i);
}

char					*ft_strdup(char *src)
{
	char		*str;
	int			i;

	i = 0;
	str = (char *)malloc(sizeof(*src) * ft_strlen(src) + 1);
	if (str == NULL)
		return (0);
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

struct s_stock_str		*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str			*stocks;
	int							i;

	if (!(stocks = malloc(sizeof(struct s_stock_str) * (ac + 1))))
		return (NULL);
	stocks->size = 0;
	stocks->str = 0;
	stocks->copy = 0;
	i = 0;
	while (i != ac)
	{
		if (!(stocks[i].size = (int)malloc(sizeof(int))))
			return (NULL);
		stocks[i].size = ft_strlen(av[i]);
		if (!(stocks[i].str = malloc(sizeof(char) * ft_strlen(av[i]))))
			return (NULL);
		stocks[i].str = av[i];
		stocks[i].copy = ft_strdup(av[i]);
		i++;
	}
	stocks[i].str = 0;
	return (stocks);
}
