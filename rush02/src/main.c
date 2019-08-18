
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "./../includes/string.h"
#include "./../includes/stdio.h"
#include "./../includes/dictionary.h"

char	*g_default_dict = "./dictionary/en.dict";

int	main(int argc, char **argv)
{
	char		*dictionary_buffer;
	char		*number_buffer;

	dictionary_buffer = 0;
	number_buffer = 0;
	// no entry, ask for int and maybe dictionnary
	if (argc == 1)
	{
		write(1, "Please enter a number: ", 23);
		number_buffer = ft_read_input((char)10, STDIN_FILENO);
		write(1, "Please enter a dictionary (press x if none): ", 45);
		dictionary_buffer = ft_read_input((char)10, STDIN_FILENO);
		if (dictionary_buffer[0] == 'x' && dictionary_buffer[1] == '\0')
			dictionary_buffer = ft_strdup(g_default_dict);
	}
	// only a number given
	else if (argc == 2)
	{
		number_buffer = ft_strdup(argv[1]);	
		dictionary_buffer = ft_strdup(g_default_dict);
	}
	// number + dictionary given
	else if (argc == 3)
	{
		number_buffer = ft_strdup(argv[1]);
		dictionary_buffer = ft_strdup(argv[2]);	
	}
	// error
	else
	{
		write(1, "Error - Invalid argument count. \n", 33);
		return (1);		
	}
	ft_display_number(ft_atoi(number_buffer), dictionary_buffer);
	write(1, "\n", 1);
	return (0);
}
