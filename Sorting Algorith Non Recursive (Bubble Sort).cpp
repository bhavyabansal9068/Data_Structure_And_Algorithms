/* Sorting Algorith Non Recursive (Bubble Sort)*/
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
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            //It Will Sort In  Ascending Order.
            if(A[j]>A[j+1])
            {
                swap(&A[j],&A[j++]);
            }
            
        }
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
        printf("%d",A[i]);
    }
    return 0;
}
