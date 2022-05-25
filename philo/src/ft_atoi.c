/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenny <jenny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:04:57 by jeulliot          #+#    #+#             */
/*   Updated: 2022/05/25 11:01:41 by jenny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_str_is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	ft_is_whitespace(char c)
{
	if (c == 32 || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

static int	ft_is_operator(char c)
{
	if (c == '-' || c == '+')
	{
		if (c == '-')
			return (-1);
		if (c == '+')
			return (1);
	}
	return (0);
}

static int	ft_sp(const char *s1, const char *s2, int n)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i ++;
	}
	if (i == n)
		return (0);
	if (s1[i] == '\0' && s2[i] == '\0')
		return (0);
	if (s1[i] == '\0')
		return (-1);
	if (s2[i] == '\0')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				m;
	int				k;
	int				n;

	i = 0;
	m = 1;
	n = 0;
	while (ft_is_whitespace(str[i]) == 1)
		i ++;
	if (ft_is_operator(str[i]) != 0)
		m = ft_is_operator(str[i]);
	if (ft_is_operator(str[i]) != 0)
		i ++;
	k = 0;
	while (ft_str_is_num(str[i + k]) == 1 && str[i + k] != '\0')
	{
		n = n * 10 + str[i + k] - 48;
		k ++;
		if (k >= 19 && ft_sp(str + i, "9223372036854775807", 19) && m == 1)
			return (-1);
		if (k >= 19 && ft_sp(str + i, "9223372036854775808", 19) && m == -1)
			return (0);
	}
	return (m * n);
}
