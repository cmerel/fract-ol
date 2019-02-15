/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cmerel <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/07 18:19:26 by cmerel       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/07 18:19:26 by cmerel      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	if (to_find[0] == '\0')
		return ((char*)str);
	while (str[i] != '\0' && i <= len)
	{
		while ((str[i + j] == to_find[j]) && (i + j < len))
		{
			if (to_find[j + 1] == '\0')
			{
				return ((char *)(str + i));
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
