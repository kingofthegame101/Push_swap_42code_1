#include "push_swap.h"

// Guard check. If stack is empty (i.e. NULL), stack size < 2, top node is empty (i.e no content), 
// bottom node is empty.
// Using the following example. stack of [10, 20, 30]
// Set first node to top, i.e. first = [10]
// Second node becomes the new top, set its previous to NULL
// First node->next becomes NULL here since previously it was needed to identify the second node.
// First node->previous is connected to bottom node. [10]->prev = [30]
// Bottom node->next is connected to first node. [30]->next = [10]
// New bottom node is set to first.
static void rotate_one(t_stack *stack)
{
    t_node  *first;

    if (stack == NULL || stack->size < 2 || stack->top == NULL || stack->bottom == NULL)
        return ;
    first = stack->top;
    stack->top = first->next;
    stack->top->prev = NULL;
    first->next = NULL;
    first->prev = stack->bottom;
    stack->bottom->next = first;
    stack->bottom = first;
}

void    ra(t_stack *a, t_bench *bench)
{
    if (a == NULL || a->size < 2 || a->top == NULL || a->bottom == NULL)
        return ;
    rotate_one(a);
    ft_putstring("ra\n");
    if (bench != NULL)
        record_op(bench, &bench->ra);
}

void    rb(t_stack *b, t_bench *bench)
{
    if (b == NULL || b->size < 2 || b->top == NULL || b->bottom == NULL)
        return ;
    rotate_one(b);
    ft_putstring("rb\n");
    if (bench != NULL)
        record_op(bench, &bench->rb);
}
// Create boolean variables to see if stack is not NULL, size >= 2, top and bottom are not NULL
// As long as either stacks can be rotated, we proceed further. Then run another check to see
// if a rotate be done.
void    rr(t_stack *a, t_stack *b, t_bench *bench)
{
    int can_rot_a;
    int can_rot_b;

    can_rot_a = (a != NULL && a->size >= 2 && a->top != NULL && a->bottom != NULL);
    can_rot_b = (b != NULL && b->size >= 2 && b->top != NULL && b->bottom != NULL);
    if (can_rot_a == 0 && can_rot_b == 0)
        return ;
    if (can_rot_a != 0)
        rotate_one(a);
    if (can_rot_b != 0)
        rotate_one(b);
    ft_putstring("rr\n");
    if (bench != NULL)
        record_op(bench, &bench->rr);
}
