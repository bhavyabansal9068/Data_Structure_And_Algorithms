#include <stdio.h>
void search(int A[],int n,int key)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        if(A[i]==key)
        printf("Key found at index %d",i);
    }
}
int main()
{
    int n,A[n],x,i;
    printf("Enter Number Of Elements In Array");
    scanf("%d",&n);
    printf("Enter the Elements Of Array");
    for(i=0;i<n;i++)
    {
        scanf("%d",&A[i]);    
    }
    printf("Enter the key you want to search");
    {
        scanf("%d",&x);
    }
    search(A,n,x);
    return 0;
}
