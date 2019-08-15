/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rush02.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shamlaou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/03 18:11:16 by shamlaou     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/04 20:53:46 by mandric     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_horizontal_others_lines(int width)
{
	int	nb_etoile;

	nb_etoile = width - 2;
	ft_putchar('B');
	while (nb_etoile > 0)
	{
		nb_etoile--;
		ft_putchar(' ');
	}
	width == 1 ? '\0' : ft_putchar('B');
}

void	ft_horizontal_fandl(int width, int *flag)
{
	int		nb_etoile;

	nb_etoile = width - 2;
	if (*flag == 1)
		ft_putchar('C');
	if (*flag == 0)
		ft_putchar('A');
	while (nb_etoile > 0)
	{
		nb_etoile--;
		ft_putchar('B');
	}
	if (*flag == 0 && width > 1)
		ft_putchar('A');
	if (*flag == 1 && width > 1)
	{
		ft_putchar('C');
		ft_putchar('\n');
	}
}

void	rush(int a, int b)
{
	int cont;
	int z;

	z = 0;
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
		z = 1;
		if (b > 1)
			ft_horizontal_fandl(a, &z);
	}
}
