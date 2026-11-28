#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
#include <limits.h>

typedef struct s_node
{
 int    value;
 int    index;
 struct s_node *next;
 struct s_node *prev;
} t_node;

typedef struct s_stack
{
 t_node *top;
 t_node *bottom;
 int  size;
} t_stack;

typedef struct s_bench
{
 int  enabled;
 double disorder;
 char *strategy_name;
 char *complexity;
 int  total_ops;
 int  sa;
 int  sb;
 int  ss;
 int  pa;
 int  pb;
 int  ra;
 int  rb;
 int  rr;
 int  rra;
 int  rrb;
 int  rrr;
} t_bench;

void    ft_putstring(const char *str);
void    record_op(t_bench *bench, int *op_count);
void    *ft_memcpy(void *dest, const void *src, size_t n);
char    *ft_strdup(const char *s);
char    *ft_substr(char const *s, unsigned int start, size_t len);

char    **ft_split(char const *s, char c);
void    free_tokens(char **tokens);
int     process_tokens(char **tokens, t_stack *stack);
int     stack_append(t_stack *stack, int value);
int     parse_args(int argc, char **argv, t_stack *stack);

void    sa(t_stack *a, t_bench *bench);
void    sb(t_stack *b, t_bench *bench);
void    ss(t_stack *a, t_stack *b, t_bench *bench);
void    pa(t_stack *a, t_stack *b, t_bench *bench);
void    pb(t_stack *a, t_stack *b, t_bench *bench);
void    ra(t_stack *a, t_bench *bench);
void    rb(t_stack *b, t_bench *bench);
void    rr(t_stack *a, t_stack *b, t_bench *bench);
void    rra(t_stack *a, t_bench *bench);
void    rrb(t_stack *b, t_bench *bench);
void    rrr(t_stack *a, t_stack *b, t_bench *bench);


int     stack_append(t_stack *stack, int value);

void    sa(t_stack *a, t_bench *bench);
void    sb(t_stack *b, t_bench *bench);
void    ss(t_stack *a, t_stack *b, t_bench *bench);
void    pa(t_stack *a, t_stack *b, t_bench *bench);
void    pb(t_stack *a, t_stack *b, t_bench *bench);
void    ra(t_stack *a, t_bench *bench);
void    rb(t_stack *b, t_bench *bench);
void    rr(t_stack *a, t_stack *b, t_bench *bench);
void    rra(t_stack *a, t_bench *bench);
void    rrb(t_stack *b, t_bench *bench);
void    rrr(t_stack *a, t_stack *b, t_bench *bench);

double  compute_disorder(t_stack *a);
void    sort_complex(t_stack *a, t_stack *b, t_bench *bench);
void    sort_adaptive(t_stack *a, t_stack *b, t_bench *bench);

void    sort_simple(t_stack *a, t_stack *b, t_bench *bench);
void    sort_medium(t_stack *a, t_stack *b, t_bench *bench);
void    print_bench(t_bench *bench);

#endif