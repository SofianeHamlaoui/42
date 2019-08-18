/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   dictionary.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shamlaou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/17 16:28:57 by shamlaou     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/18 17:57:12 by shamlaou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "./../includes/stdio.h"
#include "./../includes/string.h"
#include "./../includes/dictionary.h"
#include <stdio.h>

t_word			*ft_fill_word(char *number, char *number_str)
{
	t_word			*word;

	word = malloc(sizeof(t_word));
	word->n = ft_atoi(number);
	word->word = ft_strdup(ft_trim_begin(number_str));
	(void)word;
	(void)number;
	(void)number_str;
	return (word);
}

t_dictionary	ft_fill_dictionary(char *dictionary_path)
{
	int				fd;
	t_dictionary	dict;
	t_word			*current_word;
	char			*file_buffer;
	char			*number_buffer;
	int				number_buffer_size;
	char			*word_buffer;
	int				word_buffer_size;
	int				waiting_number;
	dict.size 	= 0;
	waiting_number = 1;
	dict.words 	= malloc(sizeof(t_word));
	file_buffer = 0;
	word_buffer_size = 0;
	word_buffer = malloc(sizeof(char));
	number_buffer_size = 0;
	number_buffer = malloc(sizeof(char));
	fd = open(dictionary_path, O_RDONLY);
	if (fd < 0)
	{
		write(1, "Error - unable to open the dictionary path [", 44);
		ft_putstr(dictionary_path);
		write(1, "]", 1);
	}
	else
	{
		(void)file_buffer;
		file_buffer = ft_read_input(-1, fd);
		while (*file_buffer)
		{
			if (*file_buffer == ':')
			{
				waiting_number = 0;		
			}
			else if (*file_buffer == '\n' || !*(file_buffer + 1))
			{
				number_buffer[number_buffer_size] = '\0';
				word_buffer[word_buffer_size] = '\0';
				current_word = ft_fill_word(number_buffer, word_buffer);
				dict.size += 1;
				dict.words = realloc(dict.words, (dict.size + 1) * sizeof (t_word*));
				dict.words[dict.size - 1] = current_word;
				number_buffer_size = 0;
				number_buffer = malloc(sizeof(char));
				word_buffer = malloc(sizeof(char));
				word_buffer_size = 0;
				waiting_number = 1;
			}
			else
			{
				if (waiting_number)
				{
					number_buffer[number_buffer_size] = *file_buffer;
					number_buffer_size += 1;
					number_buffer = realloc(number_buffer, (number_buffer_size + 1) * sizeof(char));
				}
				else
				{
					word_buffer[word_buffer_size] = *file_buffer;
					word_buffer_size += 1;
					word_buffer = realloc(word_buffer, (word_buffer_size + 1) * sizeof(char));
				}
			}
			file_buffer += 1;
		}
		
		ft_putstr(file_buffer);
	}
	return (dict);
}


t_word			*get_word(unsigned long	number, t_dictionary *dict)
{
	unsigned int		i;

	i = dict->size;
	while (i > 0)
	{
		//printf("comparing %i with %i %s\n", number, dict->words[i - 1]->n, dict->words[i - 1]->word);
		if (dict->words[i - 1]->n == number)
		{
			return (dict->words[i - 1]);
		}
		i -= 1;
	}
	return (0);
}

#include <stdio.h>

unsigned long				find_ten_pow(unsigned long nb)
{
	if (nb == 0)
		return 0;
	else
		return 1 + find_ten_pow(nb / 10);
}

unsigned long				find_first_digit(unsigned long nb)
{
	if (nb / 10 < 10)
		return nb / 10;
	else
		return find_first_digit(nb / 10);
}

unsigned long				ft_pow(unsigned long nb, unsigned int pow)
{
	if (pow == 0)
		return (1);
	else if (pow == 1)
		return (1);
	else 
		return nb * ft_pow(nb, pow - 1);
}

void					reccursive_int_cvt(unsigned long number, t_dictionary *dict, unsigned int deep)
{
	t_word		*last_word;
	last_word	= dict->words[dict->size - 1 - deep];
	t_word		*current_word;

	if (number == 0)
		return ;
	current_word = get_word(number, dict);
	if (current_word > 0)
	{
		ft_putstr(current_word->word);
		return ;
	}
	else if (number / last_word->n > 0 && last_word->n % 10 == 0)
	{
		if (last_word->n / 10 >= 10)
		{	
			reccursive_int_cvt(number / last_word->n, dict, deep);
			write(1, " ", 1);
		}
		ft_putstr(last_word->word);
		write(1, " ", 1);
		reccursive_int_cvt(number % last_word->n, dict, deep);
	}
	else
	{
		reccursive_int_cvt(number, dict, deep + 1);
	}
}

void			ft_display_number(unsigned long number, char *dictionary_path)
{
	t_dictionary	dict;

	dict = ft_fill_dictionary(dictionary_path);
	if (number == 0)
		ft_putstr(get_word(0, &dict)->word);
	else
		reccursive_int_cvt(number, &dict, 0);
}
