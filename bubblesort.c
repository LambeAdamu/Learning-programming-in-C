#include<stdio.h>
#include<stdlib.h>

void swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
} 

void bubblesort(int arr[], int max)
{
    int i;
    for(int j=0; j<max - 1; j++)
    {
    for(i = 0; i < max-1-j; i++)
    {
        if(arr[i] > arr[i+1]){swap(arr[i],arr[i+1]); }
    }
    }
}

void print(int arr[], int max)
{
    for(int i=0; i<max; i++) {printf(" %d ",arr[i]);}
}

int main()
{
    int arr[] = {3, 4, 1, 2, 7, 9};
   bubblesort(arr,6);
    print(arr, 6);
    return 0;
}