#include "push_swap.h"

static size_t	ft_int_count(char const *s, char c)
{
	size_t	int_count;
	int		in_int;
	size_t	i;

	int_count = 0;
	in_int = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && in_int == 0)
		{
			in_int = 1;
			int_count++;
		}
		else if (s[i] == c)
			in_int = 0;
		i++;
	}
	return (int_count);
}

static void	*free_all(char **arr, size_t i)
{
	while (i > 0)
	{
		i--;
		free(arr[i]);
	}
	free(arr);
	return (NULL);
}

static size_t	ft_skip_delimiters(char const *s, char c, size_t start)
{
	while (s[start] != '\0' && s[start] == c)
		start++;
	return (start);
}

static size_t	ft_get_int_len(char const *s, char c, size_t start)
{
	size_t	i;

	i = 0;
	while (s[start + i] != '\0' && s[start + i] != c)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	size_t		int_count;
	char		**arr;
	size_t		i;
	size_t		start;

	if (s == NULL)
		return (NULL);
	int_count = ft_int_count(s, c);
	arr = malloc((int_count + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	i = 0;
	start = 0;
	while (i < int_count)
	{
		start = ft_skip_delimiters(s, c, start);
		arr[i] = ft_substr(s, start, ft_get_int_len(s, c, start));
		if (arr[i] == NULL)
			return (free_all(arr, i));
		i++;
		start += ft_get_int_len(s, c, start);
	}
	arr[i] = NULL;
	return (arr);
}