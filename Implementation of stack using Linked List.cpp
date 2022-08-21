#include <stdio.h>
#include <stdlib.h>
struct node
{
    int val;
    struct node* link;
}*top=NULL;
void push(struct node *s,int x)
{
    s=top;
    struct node *t = (struct node *)malloc(sizeof(struct node));
    if(t==NULL)
    {
        printf("stack is full");
    }
    else
    {
        t->val=x;
        t->link=top;
        top=t;
    }
}
int pop(struct node *s)
{
    s=top;
    struct node *temp;

    int x=-1;
    if(top==NULL)
    {
       printf("stack is empty");
    }
    else
    {
        temp=top;
        x=top->val;
        top=top->link;
        temp->link=NULL;
        free(temp);
    }
    return x;
}
void display(struct node *s)
{
    struct node *temp;
    s=top;
    temp=top;
    while(temp->link!=NULL)
    {
        printf("%d ",temp->val);
        temp=temp->link;
    }
    printf("%d",temp->val);
}
int main()
{
   struct node s;
   push(&s,3);
   push(&s,4);
   push(&s,5);
   pop(&s);
  
   display(&s);
    return 0;
}


