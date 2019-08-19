/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ahcherch <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/15 18:26:47 by ahcherch     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/19 16:02:02 by ahcherch    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

char *ft_strjoin(int size, char **strs, char *sep);

#include <stdio.h>

int		main()
{
	char *strs[] = {"abcdef", "ghijk" ,"lmnopq"};
	char sep[] = "*";
	printf("%s", ft_strjoin(3, strs, sep));

}
