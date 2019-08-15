/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shamlaou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/07 13:44:02 by shamlaou     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/07 13:44:04 by shamlaou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*(str + i) != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int s_src;
	unsigned int s_dest;
	unsigned int i;

	s_src = ft_strlen(src);
	s_dest = ft_strlen(dest);
	i = 0;
	if (s_dest < size)
		s_src += s_dest;
	else
		s_src += size;
	if (size > 0)
	{
		while (*(src + i) && (i + s_dest) < size - 1)
		{
			*(dest + i + s_dest) = *(src + i);
			i++;
		}
		*(dest + s_dest + i) = '\0';
	}
	return (s_src);
}
