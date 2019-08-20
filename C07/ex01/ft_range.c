/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_range.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shamlaou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/12 18:06:36 by shamlaou     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/17 15:04:13 by shamlaou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int		*ret;
	int		i;

	i = 0;
	if (min >= max)
	{
		return (NULL);
	}
	if (!(ret = malloc(sizeof(int) * (max - min))))
		return (NULL);
	while (min < max)
	{
		ret[i] = min;
		i++;
		min++;
	}
	return (ret);
}
