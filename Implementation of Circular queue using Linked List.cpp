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
void creatqueue(struct queue *q)
{
    q->front=NULL;
    q->rear->link=q->front;
}
void enqueue(struct queue *q,int x)
{
    struct node *t;
    t=(struct node*)malloc(sizeof(struct node));
    if(t==NULL)
    { 
        printf("queue is full");
    }
    else
    {
        t->val=x;
        if(q->front==NULL)
        {
            q->front=q->rear=t;
        }
        else
        {
            t->link=q->rear->link;
            q->rear->link=t;
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
        printf("queue is empty");
    }
    else
    {
        if(q->front==q->rear)
        {
            temp=q->front=q->rear;
            free(temp);
        }
        else
        {
        temp=q->front;
        q->rear->link=q->front->link;
        q->front=q->front->link;
        temp->link=NULL;
        x=temp->val;
        free(temp);
        }
    }
    return x;
}
int main()
{
   struct queue q;
   enqueue(&q,4);
   enqueue(&q,2);
   enqueue(&q,3);
   enqueue(&q,6);
   dequeue(&q);
   
    
   printf("%d ",(q.front)->val);
   printf("%d ",(q.rear)->val);
   

    return 0;
}