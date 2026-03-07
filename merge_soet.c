#include<stdio.h>
void display (int arr[],int n)
{
    for (int i=0;i<n;i++)
    {
        printf("%d",arr[i]);
    }
    printf("\n");
}
void merge (int arr[], int low, int mid, int high)
{
    int n1 = mid - low+1;
    int n2 = high - mid;

    int arr1[n1];
    int arr2[n2];
    
    for (int i=0; i<n1; i++)
    arr1[i] = arr[low + i];

    for (int j=0; j<n2; j++)
    arr2[j] = arr[mid + 1 + j];

    int i=0,j=0,k=low;

    while (i<n1 && j<n2)
    {
        if (arr1[i] < arr2[j])
           arr[k++] = arr1[i++];
        else
           arr[k++] = arr2[j++];
    }
    while (i<n1)
       arr[k++] = arr1[i++];

    while(j<n2)
       arr[k++] = arr2[j++]; 
}
void merge_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high)/2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}
int main()
{
  int arr[] = {50,40,30,20,10};
  int n = sizeof(arr)/sizeof(arr[0]);
  display(arr,n);
  merge_sort(arr, 0, n-1);
  display(arr, n);

  return 0;
}