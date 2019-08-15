#include <stdio.h>
#include "ft_stock_str.h"
struct s_stock_str *ft_strs_to_tab(int ac, char **av);

int main (void)
{
	int i;
	int j;

	i = 0;
	j = 0;

//	printf("%lu\n", sizeof("bidule chouettehdshfsghfsghfsghfghs"));

	char *str1 = "le ";
	char *str2 = "petit ";
	char *str3 = "anarchiste ";
	char *str4 = "tout rouge ";
	char *str5 = "et noir";
	struct s_stock_str *tab_struct;

	char *str[5] = {str1, str2, str3, str4, str5};
	tab_struct = ft_strs_to_tab(5, str);
	while (tab_struct[i].str != 0)
	{
		printf ("%d - %s - %s\n", tab_struct[i].size, tab_struct[i].str, tab_struct[i].copy);
		i++;
	}
}
