/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shamlaou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/21 17:34:46 by shamlaou     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/21 17:36:28 by shamlaou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */
#include <stdio.h>

char    **ft_split(char *str, char *charset);

int        main(int ac, char **av)
{
	(void)ac;
	char **tab;
	int i;
	
	i = 0;
	tab = 0;
	tab = ft_split(av[1], av[2]);
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
}
