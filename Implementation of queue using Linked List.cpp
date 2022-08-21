#include <stdio.h>
#include <stdlib.h>
struct node
{
    int val;
    struct node *link;
};
struct queue
{
    struct node *front;
    struct node *rear;
};
void createqueue(struct queue *q)
{
    q->front = NULL;
    q->rear = NULL;
}
void enqueue(struct queue *q,int x)
{
    struct node *t;
    t=(struct node*)malloc(sizeof(struct node));
    if(t==NULL)
    {
        printf("Queue is Full");
    }
    else
    {
        t->val=x;
        if(q->rear==NULL)
        {
            q->front=t;
            q->rear=t;
        }
        else
        {
        q->rear->link=t;
        t->link=NULL;
        q->rear=t;
        }
    }
}
int dequeue(struct queue *q)
{
    struct node *temp;
    int x=-1;
    if(q->front==NULL)
    {
        printf("Queue is Empty");
    }
    else
    {
        if(q->front==q->rear)
        {
            temp=q->front;
            free(temp);
        }
        temp=q->front;
        x=q->front->val;
        q->front=q->front->link;
        free(temp);
    }
    return x;
}
void display (struct queue q)
{
    while( (q.rear)->link != NULL)
    {
        printf("%d",(q.front)->val);
        q.front=(q.front)->link;
    }
}
int main()
{
   struct queue q;
   createqueue(&q);
   enqueue(&q,3);
   enqueue(&q,5);
   enqueue(&q,6);
   dequeue(&q);
  printf("%d\n",(q.front)->val);
  printf("%d\n",q.rear->val);
   
    return 0;
}

