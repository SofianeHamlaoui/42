#include <stdio.h>

int main(int ac, char **av)
{
	char *sep = "LOL";
	(void)ac;
	printf("%s\n", ft_strjoin(4, av + 1, sep));
	return (0);
}
