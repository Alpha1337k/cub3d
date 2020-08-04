/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: okruitho <okruitho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/10 21:50:34 by okruitho      #+#    #+#                 */
/*   Updated: 2020/06/10 21:50:36 by okruitho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char			*lastoccur;
	unsigned char	chr;

	chr = (unsigned char)c;
	lastoccur = 0;
	if (s[0] == '\0' && c == 0)
		return ((char *)s);
	if (s[0] == '\0')
		return (0);
	while (s[0] != '\0')
	{
		if (s[0] == chr)
		{
			lastoccur = (char *)s;
		}
		s++;
	}
	if (s[0] == '\0' && chr == 0)
		lastoccur = (char *)s;
	return (lastoccur);
}
