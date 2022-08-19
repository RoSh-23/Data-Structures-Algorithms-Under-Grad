/*** Program to implement bubble sort in C ***/
#include <stdio.h>
#include <stdlib.h>

/*
    Function to implement bubble sort.
    input : pointer to array to be sorted.
    input : size of array.
*/
void bubbleSort(int*, int);

/*
    Function to display the entered array.
    input : pointer to array to be displayed.
    input : size of array.
*/
void display(int*, int);

int main()
{
    int arrSize = 0, *arr = NULL, i = 0;
    printf("Enter the size of the array:\n");
    scanf("%d", &arrSize);

    arr = (int*)malloc(arrSize * sizeof(int));

    if(arr == NULL)
    {
        printf("Not enough memory\n");
        exit(1);
    }

    printf("Enter the elements of the array:\n");
    for(i = 0; i < arrSize; i++)
        scanf("%d", &arr[i]);

    printf("The array before sorting is:\n");
    display(arr, arrSize);

    bubbleSort(arr, arrSize);

    printf("The array after sorting is:\n");
    display(arr, arrSize);

    free(arr);

    return 0;
}

void display(int *A, int n)
{
    int i = 0;
    for(int i = 0; i < n; i++)
        printf("%d  ", A[i]);
    printf("\n");
}

void bubbleSort(int *A, int n)
{
    int i = 0, j = 0, temp = 0;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}
