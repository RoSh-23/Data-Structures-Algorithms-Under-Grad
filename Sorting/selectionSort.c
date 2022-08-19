/*** Program to implement selection sort in C ***/
#include <stdio.h>
#include <stdlib.h>

/*
    Function to perform selection sort.
    input : pointer to the array to be sorted.
    input : size of the array.
*/
void selectionSort(int*, int);

/*
    Function to find the smallest element in a given array.
    input  : pointer to the array which is being sorted.
    input  : starting position from where the array is to be searched for smallest element.
    input  : size of the array.
    output : the position of the smallest element in the array.
*/
int findSmallest(int*, int, int);

/*
    Function to display the array on console.
    input : pointer to the array to be displayed.
    input : size of the array.
*/
void display(int*, int);

int main()
{
    int arrSize = 0, i = 0, *A = NULL;

    printf("-----Program to perform selection sort-----\n");

    printf("Enter the size of the array:\n");
    scanf("%d", &arrSize);

    A = (int*)malloc(arrSize * sizeof(int));
    if(A == NULL)
    {
        printf("Not enough memory space available\n");
        exit(1);
    }

    printf("Enter the elements of the array:\n");
    for(i = 0; i < arrSize; i++)
        scanf("%d", &A[i]);

    printf("The array before sorting is:\n");
    display(A, arrSize);

    selectionSort(A, arrSize);

    printf("The array after sorting is:\n");
    display(A, arrSize);

    free(A);

    return 0;
}

void display(int *arr, int n)
{
    int i = 0;
    for(i = 0; i < n; i++)
        printf("%6d  ", arr[i]);
    printf("\n");
}

void selectionSort(int *arr, int n)
{
    int i = 0, pos = 0, temp = 0;

    for(i = 0; i < n; i++)
    {
        pos = findSmallest(arr, i, n);
        temp = arr[pos];
        arr[pos] = arr[i];
        arr[i] = temp;
    }
}

int findSmallest(int *arr, int k, int n)
{
    int i = 0;
    int small = arr[k];     // initializing small with the first element of the section of array
    int pos = k;            // pos represents the position of the smallest element

    for(i = k + 1; i < n; i++)
    {
        if(small > arr[i])
        {
            small = arr[i];
            pos = i;
        }
    }

    return pos;
}
