/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_comb.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shamlaou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/01 16:45:11 by shamlaou     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/02 12:12:49 by shamlaou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_chiffre(int a, int b, int c)
{
	ft_putchar(a + 48);
	ft_putchar(b + 48);
	ft_putchar(c + 48);
	if (a != 7)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb(void)
{
	int aa;
	int ab;
	int ac;

	aa = 0;
	while (aa <= 7)
	{
		ab = aa + 1;
		while (ab <= 8)
		{
			ac = ab + 1;
			while (ac <= 9)
			{
				ft_chiffre(aa, ab, ac);
				ac++;
			}
			ab++;
		}
		aa++;
	}
}
