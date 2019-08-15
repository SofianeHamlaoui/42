/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcapitalize.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shamlaou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/05 14:09:26 by shamlaou     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/05 14:43:53 by shamlaou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] <= 'Z' && str[i] >= 'A')
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}

int		ft_str_is_word(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] <= 'z' && str[i] >= 'a'))
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int i;
	int on_off;

	i = 0;
	on_off = 1;
	ft_strlowcase(str);
	while (str[i] != '\0')
	{
		if ((str[i] <= 'z' && str[i] >= 'a')
			|| (str[i] >= '0' && str[i] <= '9')
				|| (str[i] >= 'A' && str[i] <= 'Z'))
		{
			if (on_off == 1 && str[i] <= 'z' && str[i] >= 'a')
			{
				str[i] = str[i] - 32;
				on_off = 0;
			}
			else if (str[i] >= '0' && str[i] <= '9')
				on_off = 0;
		}
		else
			on_off = 1;
		i++;
	}
	return (str);
}
