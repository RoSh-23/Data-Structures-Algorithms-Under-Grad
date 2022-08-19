/*** Program to implement quick sort in C ***/
#include <stdio.h>
#include <stdlib.h>
const int SIZE = 100;

void quickSort(int*, int, int);
int partition(int*, int, int);
void display(int*, int);

int main()
{
    int arrSize = 0, A[SIZE];

    printf("------ Program to implement quick sort ------\n");
    printf("\nEnter the size of the array:\n");
    scanf("%d", &arrSize);

    printf("\nEnter the elements of the array:\n");
    for(int i = 0; i < arrSize; i++)
        scanf("%d", &A[i]);

    printf("\nArray before sorting is:\n");
    display(A, arrSize);

    quickSort(A, 0, arrSize - 1);

    printf("\nArray after sorting is:\n");
    display(A, arrSize);

    return 0;
}

void display(int *arr, int n)
{
    for(int i = 0; i < n; i++)
        printf("%3d ", arr[i]);
    printf("\n");
}

int partition(int *arr, int beg, int end)
{
    int left, right, temp, pivotLoc, flag;
    pivotLoc = left = beg;
    right = end;
    flag = 0;
    while(flag != 1)
    {
        while((arr[pivotLoc] <= arr[right]) && (pivotLoc != right))
        {
            right--;
        }
        if(pivotLoc == right)
        {
            flag = 1;
        }
        else if(arr[pivotLoc] > arr[right])
        {
            temp = arr[pivotLoc];
            arr[pivotLoc] = arr[right];
            arr[right] = temp;
            pivotLoc = right;
        }

        if(flag != 1)
        {
            while((arr[pivotLoc]) >= arr[left] && (pivotLoc != left))
            {
                left++;
            }
            if(pivotLoc == left)
            {
                flag = 1;
            }
            else if(arr[pivotLoc] < arr[left])
            {
                temp = arr[pivotLoc];
                arr[pivotLoc] = arr[left];
                arr[left] = temp;
                pivotLoc = left;
            }
        }
    }
    return pivotLoc;
}

void quickSort(int *arr, int beg, int end)
{
    int pivotLoc;
    if(beg < end)
    {
        pivotLoc = partition(arr, beg, end);
        quickSort(arr, beg, pivotLoc - 1);
        quickSort(arr, pivotLoc + 1, end);
    }
}
