#include "push_swap.h"

// Guard check. If stack is empty (i.e. NULL), stack size < 2, top node is empty (i.e no content), 
// top->next node is empty (next node no content). Do not execute.
// Using the following example. stack of [10, 20, 30]
// first = stack->top. Setting the first node to contain 10
// second = first->next. Setting the next node after first to be 20
// first->next = second->next. Replacing the old pointer to 20 with new pointer to 30.
// if (second->next != NULL). Which means if there is a value after second node, reconnect third node
// prev to first node.[30]->prev -> [10]
// Next set second node as the top node and reconnect first node prev to second node.
// If the stack size is 2, set first as bottom, following the struct setting in header.
static void swap_top_two(t_stack *stack)
{
    t_node  *first;
    t_node  *second;

    if (stack == NULL || stack->size < 2 || stack->top == NULL || stack->top->next == NULL)
        return ;
    first = stack->top;
    second = first->next;
    first->next = second->next;
    if (second->next != NULL)
        second->next->prev = first;
    second->prev = NULL;
    second->next = first;
    first->prev = second;
    stack->top = second;
    if (stack->size == 2)
        stack->bottom = first;
}

// Guard check, then execute swap_top_two function. Print action. Lastly update operation count.
void sa(t_stack *a, t_bench *bench)
{
    if (a == NULL || a->size < 2 || a->top == NULL || a->top->next == NULL)
        return ;
    swap_top_two(a);
    ft_putstring("sa\n");
    if (bench != NULL)
        record_op(bench, &bench->sa);
}

void sb(t_stack *b, t_bench *bench)
{
    if (b == NULL || b->size < 2 || b->top == NULL || b->top->next == NULL)
        return ;
    swap_top_two(b);
    ft_putstring("sb\n");
    if (bench != NULL)
        record_op(bench, &bench->sb);
}

// Create boolean variables to see if stack is not NULL and size >= 2.
// As long as either stacks can be swapped, we proceed further. Then run another check to see
// if a swap be done.
void ss(t_stack *a, t_stack *b, t_bench *bench)
{
    int can_swap_a;
    int can_swap_b;

    can_swap_a = (a != NULL && a->size >= 2 && a->top != NULL && a->top->next != NULL);
    can_swap_b = (b != NULL && b->size >= 2 && b->top != NULL && b->top->next != NULL);
    if (can_swap_a == 0 && can_swap_b == 0)
        return ;
    if (can_swap_a != 0)
        swap_top_two(a);
    if (can_swap_b != 0)
        swap_top_two(b);
    ft_putstring("ss\n");
    if (bench != NULL)
        record_op(bench, &bench->ss);
}
