#include "push_swap.h"

void	ft_putstring(const char *str)
{
	int	len;

	if (str == NULL)
		return ;
	len = 0;
    while (str[len] != '\0')
        len++;
    write(1, str, len);
}

// Helper function to help record operation count
void    record_op(t_bench *bench, int *op_count)
{
    if (bench == NULL)
        return ;
    if (op_count != NULL)
        (*op_count)++;
    bench->total_ops++;
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	if (dest == NULL && src == NULL)
		return (NULL);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

char	*ft_strdup(const char *s)
{
	char		*dup;
	size_t		len;

	if (s == NULL)
		return (NULL);
	len = 0;
    while (s[len] != '\0')
        len++;
    len++;
	dup = (char *)malloc(len * sizeof(char));
	if (dup == NULL)
		return (NULL);
	ft_memcpy(dup, s, len);
	return (dup);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub_str;
	size_t			str_len;
	size_t			i;

	if (s == NULL)
		return (NULL);
	str_len = 0;
    while (s[str_len] != '\0')
        str_len++;
	if (start >= str_len)
		return (ft_strdup(""));
	if (len > str_len - start)
		len = str_len - start;
	sub_str = (char *)malloc((len + 1) * sizeof(char));
	if (sub_str == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		sub_str[i] = s[start + i];
		i++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}
