#include<stdio.h>
void display(int arr[], int n)
{
    printf("Array element -->\n");
    for ( int i=0; i<n; i++)
    {
        printf("%d",arr[i]);
    }
    printf("\n");
}
int delete(int arr[], int n, int x)
{
    int i;
    for(i=0; i<n; i++)
    {
        if(i == n)
        {
            break;
        }
    }
    if(arr [i] == n)
    return n;
    for (int j=i; j<n-1; j++)
    {
        arr[j]=arr[j+1];
    }
    return n-1;
}
int main()
{
    int arr[]={5,5,5,5,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int x = 5;
    display(arr,n);

    n = delete(arr,n,10);
    display(arr,n);
}