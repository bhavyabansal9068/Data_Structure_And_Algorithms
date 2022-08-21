#include <stdio.h>
#include <stdlib.h>
#include <iostream>
struct queue
{
  int size;
  int rear;
  int front;
  int *A;
};
void
create (struct queue *q, int size)
{
  q->front = -1;
  q->rear = -1;
  q->size = size;
  q->A = new int[q->size];
}

void
enqueue (struct queue *q, int x)
{
  if ((q->rear + 1) % q->size == q->front)
    {
      printf ("Queue is full");
    }
  else
    {
      q->rear = (q->rear + 1) % q->size;
      q->A[q->rear] = x;
    }
}

int
dequeue (struct queue *q)
{
  int x = -1;
  if (q->rear == q->front)
    {
      printf ("queue is empty");
    }
  else
    {
      x = q->A[q->front];
      q->front = (q->front + 1) % q->size;
    }
  return x;
}

void
display (struct queue q)
{
  int i;
  i = q.front + 1;
  do
    {
      printf ("%d ", q.A[i]);
      i = (i + 1) % q.size;
    }
  while (i != (q.rear + 1) % q.size);
}

int
main ()
{
  struct queue q;
  create (&q, 5);
  enqueue (&q, 1);
  enqueue (&q, 2);
  enqueue (&q, 3);
  enqueue (&q, 4);
  enqueue (&q, 5);
  dequeue (&q);
  dequeue (&q);

  display (q);

  return 0;
}
