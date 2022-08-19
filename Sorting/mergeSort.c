/*** Program to implement merge sort in C. ***/
#include <stdio.h>
#include <stdlib.h>
const int SIZE = 100;
/*
    Function which combines the sub-arrays to form a sorted array.
    input : pointer to array containing the sub-arrays.
    input : beginning index of the sub-array.
    input : middle index of the sub-array.
    input : last index of the sub-array.
*/
void merge(int*, int, int, int);

/*
    Function to perform merge sort.
    input : pointer to the array to be sorted.
    input : beginning index of the array.
    input : last index of the array.
*/
void mergeSort(int*, int, int);

/*
    Function to display the array.
    input : pointer to the array to be displayed.
    input : size of the array.
*/
void display(int*, int);

int main()
{
    int arrSize = 0, i = 0;

    printf("------ Program to perform merge sort on an array ------\n");

    printf("\nEnter the size of the array:\n");
    scanf("%d", &arrSize);

    int A[SIZE];

    printf("\nEnter the elements of the array:\n");
    for(i = 0; i < arrSize; i++)
        scanf("%d", &A[i]);

    printf("\nArray before sorting is:\n");
    display(A, arrSize);

    mergeSort(A, 0, (arrSize - 1));

    printf("\nArray after sorting is:\n");
    display(A, arrSize);

    return 0;
}

void display(int *arr, int n)
{
    int  i = 0;
    for(int i = 0; i < n; i++)
        printf("%6d  ", arr[i]);
    printf("\n");
}

void merge(int *arr, int beg, int mid, int end)
{
    const int n = (end - beg) + 1;          // n represents the size of the array.

    int temp[SIZE];

    int i = beg, j = mid + 1, index = beg, k  = 0;    // index represents the index of the temp array.

    while((i <= mid) && (j <= end))
    {
        if(arr[i] < arr[j])
        {
            temp[index] = arr[i];
            i++;
        }
        else
        {
            temp[index] = arr[j];
            j++;
        }
        index++;
    }

    if(i > mid)
    {
        while(j <= end)
        {
            temp[index] = arr[j];
            index++;
            j++;
        }
    }
    else
    {
        while(i <= mid)
        {
            temp[index] = arr[i];
            index++;
            i++;
        }
    }

    for(k = beg; k <= end; k++)
    {
        arr[k] = temp[k];
    }
}

void mergeSort(int* arr, int beg, int end)
{
    int mid = 0;
    if(beg < end)
    {
        mid = (beg + end) / 2;
        mergeSort(arr, beg, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, beg, mid, end);
    }
}
