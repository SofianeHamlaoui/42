/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ahcherch <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/15 18:26:47 by ahcherch     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/20 23:41:11 by shamlaou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

char *ft_strjoin(int size, char **strs, char *sep);

#include <stdio.h>

int		main(int ac, char **av)
{
	char sep[] = "*";
	printf("%s", ft_strjoin(ac, av, sep));

}
