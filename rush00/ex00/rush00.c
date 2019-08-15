/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rush01.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shamlaou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/03 18:11:16 by shamlaou     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/04 20:01:13 by mandric     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_horizontal_others_lines(int width)
{
	int	nb_etoile;

	nb_etoile = width - 2;
	ft_putchar('|');
	while (nb_etoile > 0)
	{
		nb_etoile--;
		ft_putchar(' ');
	}
	width == 1 ? '\0' : ft_putchar('|');
}

void	ft_horizontal_fandl(int width, int *flag)
{
	int		nb_etoile;

	*flag = 0;
	nb_etoile = width - 2;
	ft_putchar('o');
	while (nb_etoile > 0)
	{
		nb_etoile--;
		ft_putchar('-');
	}
	ft_putchar('o');
}

void	rush(int a, int b)
{
	int cont;
	int z;

	z = 1;
	cont = 1;
	if (a > 0 && b > 0)
	{
		ft_horizontal_fandl(a, &z);
		ft_putchar('\n');
		while (cont < b - 1)
		{
			ft_horizontal_others_lines(a);
			cont++;
			ft_putchar('\n');
		}
		z = 0;
		if (b > 1)
			ft_horizontal_fandl(a, &z);
		ft_putchar('\n');
	}
}
