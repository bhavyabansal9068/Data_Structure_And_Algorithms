#include <stdio.h>
void swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
void bubblesort(int A[],int n)
{
    int i;
    for(i=0;i<n-1;i++)
        {
            //It Will Sort In  Ascending Order.
            if(A[i]>A[i+1])
            {
                swap(&A[i],&A[i+1]);
            }
              bubblesort(A,n-1);
        }
  
}
int main()
{
    int n,A[n],i;
    printf("Enter the Number of Elements\n");
    scanf("%d",&n);
    printf("Enter the Elements of Array\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    bubblesort(A,n);
    for(i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    return 0;
}
