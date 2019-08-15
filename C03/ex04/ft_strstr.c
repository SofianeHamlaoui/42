/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shamlaou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/06 15:22:48 by shamlaou     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/06 18:03:30 by shamlaou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int tofind;

	i = 0;
	tofind = 0;
	if (to_find[i] == '\0')
	{
		return (str);
	}
	while (str[i] != '\0')
	{
		tofind = 0;
		while (str[i + tofind] == to_find[tofind])
		{
			if (to_find[tofind + 1] == '\0')
			{
				return (str + i);
			}
			tofind++;
		}
		i++;
	}
	return (0);
}
