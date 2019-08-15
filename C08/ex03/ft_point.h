/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_point.h                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shamlaou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/14 15:34:38 by shamlaou     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/14 17:09:06 by shamlaou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_POINT_H
# define FT_POINT_H

typedef struct				s_point
{
	int	x;
	int	y;
}							t_point;

void						set_point(t_point *point);

#endif
