int main()
{
	int x;
	int y;
	int *tab;

	x = 0;
	y = 100;

	tab = ft_range(x, y);

	int i = 0;
	while (i < 100)
	{
		printf(" [%d] ", tab[i]);
		++i;
	}
	return (0);

}
