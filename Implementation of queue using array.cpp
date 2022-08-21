#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int front;
    int rear;
    int size;
    int *A;
};
void create(struct queue *q,int size)
{
    q->front=0;
    q->rear=0;
    q->size=size;
    q->A=(int *)malloc(q->size * sizeof(int));
}
void enqueue(struct queue *q,int x)
{
    if(q->rear==q->size)
    {
        printf("Queue is Full");
    }
    else
    {
         q->rear++;
        q->A[q->rear]=x;
        
    }
}
int dequeue(struct queue *q)
{
    int x=-1;
    if(q->front==q->rear)
    {
        printf("Queue is Empty");
    }
    else
    {
        x=q->A[q->front];
        q->front++;
    }
    return x;
}
void display(struct queue q)
{
    int i;
    for(i=q.front+1;i<=q.rear;i++)
    {
        printf("%d ",q.A[i]);
    }
}
int main()
{
    struct queue q;
    create(&q,5);
    enqueue(&q,1);
    enqueue(&q,5);
    enqueue(&q,3);
    enqueue(&q,6);
    enqueue(&q,8);
    dequeue(&q);
    dequeue(&q);
    display(q);
    

    return 0;
}