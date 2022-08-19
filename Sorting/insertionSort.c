/*** Program to implement insertion sort in C ***/
#include <stdio.h>
#include <stdlib.h>

/*
    Function to perform insertion sort.
    input : pointer to the array to be sorted.
    input : size of the array.
*/
void insertionSort(int*, int);

/*
    Function to display the array.
    input : pointer to the array to be displayed.
    input : size of the array.
*/
void display(int*, int);

int main()
{
    int arrSize = 0, i = 0, *arr = NULL;

    printf("------- Program to perform insertion sort -------\n");

    printf("\nEnter the size of the array:\n");
    scanf("%d", &arrSize);

    arr = (int*)malloc(arrSize * sizeof(int));
    if(arr == NULL)
    {
        printf("Not enough memory space\n");
        exit(1);
    }

    printf("\nEnter the elements of the array:\n");
    for(i = 0; i < arrSize; i++)
        scanf("%d", &arr[i]);

    printf("\nArray before sorting is:\n");
    display(arr, arrSize);

    insertionSort(arr, arrSize);

    printf("\nArray after sorting is:\n");
    display(arr, arrSize);

    free(arr);

    return 0;
}

void display(int *A, int n)
{
    int i = 0;
    for(i = 0; i < n; i++)
        printf("%d  ", A[i]);
    printf("\n");
}

void insertionSort(int *A, int n)
{
    int k = 0, j = 0, temp = 0;

    for(k = 1; k < n; k++)
    {
        temp = A[k];                    // element to be inserted in the sorted section of the array
        j = k - 1;                      // highest index of the sorted section of the array
        while((temp <= A[j]) && (j >= 0))
        {
            A[j + 1] = A[j];            // shift the element of the sorted section one position forward
            j--;
        }
        A[j + 1] = temp;                // if element to be inserted is larger than the element at highest index of the sorted area
                                        // then insert the element at j + 1 position i.e. make it the new largest element of the sorted section
    }
}
