/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   dictionary.h                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shamlaou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/17 16:28:57 by shamlaou     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/17 21:47:40 by shamlaou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef DICTIONARY_H
# define DICTIONARY_H

typedef  struct	s_word 
{
	unsigned long		n;
	char			*word;
} t_word;

typedef struct	s_dictionary
{
	unsigned int		size;
	t_word			**words;
}				t_dictionary;

typedef enum	e_suported_langs 
{
	FR,
	EN,
	DE,
}				t_suported_langs;

t_word			*ft_fill_word(char *number, char *number_str);

t_dictionary		ft_fill_dictionary(char *dictionary_path);

void			ft_display_number(unsigned long number, char *dictionary_path);

#endif
