#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int top;
    int size;
    int *A;
};
void create(struct stack *s,int size)
{
    s->top==-1;
    s->size=size;
    s->A=(int *)malloc(s->size * sizeof(int));
}
void push(struct stack *s,int x)
{
    if(s->top==s->size)
    {
        printf("stack is full");
    }
    else
    {
        s->top++;
        s->A[s->top]=x;
    }
}
int pop(struct stack *s)
{
    int x=-1;
    if(s->top==-1)
    {
        printf("Stack is Empty");
    }
    else
    {
        x=s->A[s->top];
        s->top--;
    }
    return x;
}
void display(struct stack s)
{
    int i;
    for(i=1;i<=s.top;i++)
    {
        printf("%d ",s.A[i]);
    }
}
int main()
{
    struct stack s;
    create(&s,5);
    push(&s,1);
    push(&s,4);
    push(&s,5);
    push(&s,6);
    push(&s,8);
    pop(&s);
    display(s);
    return 0;
}
