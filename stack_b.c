#include <stdio.h>
#include <stdlib.h>
typedef struct Stack {
    int* arr;
    int size;
    int top;
} Stack;
int pop(Stack* st);
void push(Stack* st, int i);
int peek(Stack* st);
Stack* createStack(int s);
int main()
{
    Stack* st = createStack(1000);
    int n, q, k;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &q);
        if (q == 1)
        {
            q = pop(st);
            if (q == -1)    printf("No Food\n");
            else    printf("%d\n", q);
        }
        else
        {
            scanf("%d", &q);
            push(st, q);
        }
    }
    return 0;
    
}

Stack* createStack(int s)
{
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->size = s;
    stack->top = -1;
    stack->arr = (int*) malloc(stack->size * sizeof(int));
    return stack;
}
 
int pop(Stack* st)
{
    if (st->top == -1)  return -1;
    else
    {
        return st->arr[st->top--];
    }
}
void push(Stack* st, int i)
{
    if (st->top == st->size - 1)    printf("OVERFLOW\n");
    else
    {
        st->top = st->top + 1;
        st->arr[st->top] = i;
    }
}
int peek(Stack* st)
{
    return st->arr[st->top];
}

    