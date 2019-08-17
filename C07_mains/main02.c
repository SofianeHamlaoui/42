#include <stdio.h>

int ft_ultimate_range(int **range, int min, int max);

int    ft_atoi(char *str)
{
	int nbr;
	int sign;

	nbr = 0;
	sign = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f'
			|| *str == '\r' || *str == ' ')
		++str;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		++str;
	}
	while (*str >= '0' && *str <= '9')
	{
		nbr = nbr * 10 + *str - '0';
		++str;
	}
	return (nbr * sign);
}

int main(int argc, char **argv)
{
	if (argc != 3)
		return (-1);

	int *range;
	int i;
	int size;
	int res;

	range = NULL;
	size = ft_atoi(argv[2]) - ft_atoi(argv[1]);
	res = ft_ultimate_range(&range, ft_atoi(argv[1]), ft_atoi(argv[2]));

	i = 0;
	while (i < size)
	{
		printf(" [%d] ", range[i]);
		++i;
	}
	printf("\n\nla taille de notre tableau est : %d\n", res);
	printf("L'adresse de range vaut : %p", range);
	return (0);
}
