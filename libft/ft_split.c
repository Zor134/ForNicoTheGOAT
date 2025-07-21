/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laudinot <laudinot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 00:37:58 by laudinot          #+#    #+#             */
/*   Updated: 2025/07/16 18:25:51 by laudinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// je veux gerer int min max et qu un seul signe et que des chiffres 
void	ft_free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
char **ft_check_split(char **str)
{
	int	i;
	int	j;
	int	sign;

	i = 0;
	while (str[i])
	{
		j = 0;
		sign = 0;
		while (str[i][j])
		{
			if ((str[i][j] == '-' || str[i][j] == '+') && sign == 0)
			{	
				j++;
				sign++;
			}
			if (!str[i][j])
				return (NULL);
			if (str[i][j] > '9' || str[i][j] < '0')
				return (NULL);
			j++;
		}
		if (ft_atol(str[i]) > 2147483647 || ft_atol(str[i]) < -2147483648)
			return (NULL);
		i++;
	}
	return(str);
}

int	ft_countword(char const *s, char c)
{
	int	i;
	int	wordcount;

	wordcount = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			wordcount++;
		i++;
	}
	return (wordcount);
}

char	**ft_fill(char **result, char const *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] == '\0')
			break ;
		j = 0;
		while (s[i + j] != c && s[i + j] != '\0')
			j++;
		result[k] = malloc(sizeof(char) * (j + 1));
		if (!result[k])
			return (NULL);
		ft_strlcpy(result[k], (char *)(s + i), j + 1);
		i += j;
		k++;
	}
	result[k] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	char	**returnstr;

	if (!s || !ft_countword(s, c))
		return (NULL);
	result = malloc(sizeof(char *) * (ft_countword(s, c) + 1));
	if (!result)
		return (NULL);
	returnstr = ft_fill(result, s, c);
	if (!ft_check_split(returnstr))
	{
		ft_free_split(returnstr);
		returnstr = NULL;
	}
	return (returnstr);
}

