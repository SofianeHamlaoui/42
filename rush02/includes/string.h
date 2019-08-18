/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   string.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shamlaou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/17 16:25:55 by shamlaou     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/17 18:40:30 by shamlaou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H

char			*ft_strdup(char *str);
unsigned long		ft_atoi(char *nbr);
char			*ft_trim_begin(char *str);
int			ft_is_number(char c);
int			ft_is_space(char c);

#endif
