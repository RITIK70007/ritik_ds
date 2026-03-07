#include<stdio.h>
void display ( int arr[],int n)
{
    for (int i=0;i<n;i++)
    {
        printf("%d",arr[i]);
    }
    printf("\n");
}
void insertion_sort (int arr[],int n)
{
    for (int i=0;i<n;i++)
    {
        int j=i;
        while (j>0 && arr[j]<arr[j-1])
        {
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
    }
}
int main()
{
    int arr[] = {50,40,30,20,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    display(arr,n);
    insertion_sort(arr,n);
    display(arr,n);
    
    return 0;
}
