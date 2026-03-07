#include<stdio.h>

int bsearch(int arr[], int n, int x)
{
    int low = 0;
    int high = n-1;
    while(low < high)
    {
        int mid = (low + high)/2;
        if(arr[mid] == x)
        {
            return mid;
        }
        if(mid == 0 || arr[mid] != arr[mid-1])
        {
            return mid;
        }
        else if(x < arr[mid])
        {
            high = mid=1;
        }
        else
        {
            low = mid+1;
        }
    }
    return-1;
}
int main()
{
    int arr[] = {1,2,2,3,3,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("%d",bsearch(arr,n,3));
}