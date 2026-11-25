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
