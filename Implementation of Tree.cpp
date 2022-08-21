#include <stdio.h>
#include <stdlib.h>
struct node
{
  struct node *lchild;
  int data;
  struct node *rchild;
} *root = NULL;
struct queue
{
  int size;
  int front;
  int rear;
  struct node **A;
};
void
create (struct queue *q, int size)
{
  q->size = size;
  q->front = q->rear = 0;
  q->A = (struct node **) malloc (q->size * sizeof (struct node *));
}

void
enqueue (struct queue *q,struct  node * x)
{
  if ((q->rear + 1) % q->size == q->front)
    printf ("stack is full");
  else
    {
      q->rear = (q->rear + 1) % q->size;
      q->A[q->rear] = x;
    }
}

struct node *
dequeue (struct queue *q)
{
  struct node *x = NULL;
  if (q->front == q->rear)
    printf ("queue is empty");
  else
    {
      q->front = (q->front + 1) % q->size;
      x = q->A[q->front];
    }
  return x;
}

int
isempty (struct queue q)
{
  if (q.front == q.rear)
    return 1;
  else
    return 0;
}

void
preorder (struct node *p)
{
  if (p)
    {
      printf ("%d ", p->data);
      preorder (p->lchild);
      preorder (p->rchild);
    }

}

void
inorder (struct node *p)
{
  if (p)
    {
      inorder (p->lchild);
      printf ("%d ", p->data);
      inorder (p->rchild);
    }

}

void
postorder (struct node *p)
{
  if (p)
    {
      postorder (p->lchild);
      postorder (p->rchild);
      printf ("%d ", p->data);
    }

}
void binarytree()
{
    int x;
    struct queue q;
    struct node *p,*temp;
    create(&q,100);
    struct node *root = (struct node*)malloc(sizeof(struct node));
    p=(struct node*)malloc(sizeof(struct node));
    printf("Enter Value Of Root Node ");
    scanf("%d",&x);
    root->data=x;
    root->lchild=root->rchild=NULL;
    enqueue(&q,root);
    while(!isempty(q))
    {
        p=dequeue(&q);
        printf("Enter left child of %d ",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            temp=(struct node*)malloc(sizeof(struct node));
            temp->data=x;
            temp->lchild=temp->rchild=NULL;
            p->lchild=temp;
            enqueue(&q,temp);
        }
        printf("Enter right child of %d ",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
           temp=(struct node*)malloc(sizeof(struct node));
            temp->data=x;
            temp->lchild=temp->rchild=NULL;
            p->rchild=temp;
            enqueue(&q,temp);
        }
    }
}

void
insert (int key)
{
  struct node *t, *r, *p;
  p = root;
  r=(struct node*)malloc(sizeof(struct node));
  if (root == NULL)
    {
     t=(struct node*)malloc(sizeof(struct node));
      t->data = key;
      t->lchild = t->rchild = NULL;
      root = t;
      return;
    }
  while (p != NULL)
    {
      r = p;
      if (key < p->data)
	{
	  p = p->lchild;
	}
      else if (key > p->data)
	{
	  p = p->rchild;
	}
      else
	{
	  return;
	}
    }
  t=(struct node*)malloc(sizeof(struct node));
  t->data = key;
  t->lchild = t->rchild = NULL;
  if (key < r->data)
    {
      r->lchild = t;
    }
  else
    {
      r->rchild = t;
    }

}

struct node * successor(struct node *p)
{
    while(p && p->lchild!=NULL)
    {
        
        p=p->lchild;
    }
    return p;
}
struct node * preceder(struct node *p)
{
    while(p && p->rchild!=NULL)
    {
        
        p=p->rchild;
    }
    return p;
}
struct node*
deletele (struct node * p, int key)
{
  struct node *q;
  if (p == NULL)
    {
      return NULL;
    }
  if (key < p->data)
    {
      p->lchild = deletele (p->lchild, key);
    }
  else if (key > p->data)
    {
      p->rchild = deletele (p->rchild, key);
    }
  else 
   {
      if (p->lchild==NULL && p->rchild==NULL)
            return NULL;
       
        else if (p->lchild == NULL) {
            struct node* temp = p->rchild;
            free(p);
            return temp;
        }
        else if (p->rchild == NULL) {
            struct node* temp = p->lchild;
            free(p);
            return temp;
        } 
       
	  q = successor(p->rchild);
	  p->data = q->data;
	  p->rchild = deletele (p->rchild, q->data);
	
    }
    return p;
   

}
int main()
{
    
   
  
  insert (40);
  insert (60);
  insert (30);
  insert (10);
  insert (20);
  insert (50);
  insert (70);
  deletele(root,10);
  inorder (root);
    return 0;
}

