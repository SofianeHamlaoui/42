/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fibonacci.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shamlaou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/08 21:29:30 by shamlaou     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/09 13:36:59 by shamlaou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int		ft_fibonacci(int index)
{
	if (index < 0)
	{
		return (-1);
	}
	if (index == 1 || index == 2)
	{
		return (1);
	}
	else if (index == 0)
	{
		return (0);
	}
	return (ft_fibonacci(index - 2) + ft_fibonacci(index - 1));
}
