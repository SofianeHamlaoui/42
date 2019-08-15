#include "ft_stock_str.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_show_tab(struct s_stock_str *par);
struct s_stock_str	*ft_strs_to_tab(int ac, char **av);

int main (void)
{
	int i;
	int j;

	i = 0;
	j = 0;

	char *str1 = "leooooooopu";
	char *str2 = "petit ";
	char *str3 = "anarchiste ";
	char *str4 = "tout rouge ";
	char *str5 = "et noir";
	struct s_stock_str *tab;

	char *str[5] = {str1, str2, str3, str4, str5};
	tab = ft_strs_to_tab(5, str);
	ft_show_tab(tab);

	while (tab[i].str != 0)
	{
		printf ("%s-%d-%s-\n", tab[i].str, tab[i].size, tab[i].copy);
		i++;
	}

}
