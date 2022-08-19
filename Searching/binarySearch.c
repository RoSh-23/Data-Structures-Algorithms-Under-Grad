/*** Program to implement binary search ***/
#include <stdio.h>
#include <stdlib.h>

/*
arguments:
	int* : takes the name of array
	int  : size of array
	int  : value to be searched
return type:
	int  : returns position if found otherwise -1
*/
int binarySearch(int*, int, int);
int smallest(int*, int, int);
void selectionSort(int*, int);

int main()
{
	int size, val, i, pos;
	int *arr;

	printf("\nEnter the size of the array:\n");
	scanf("%d", &size);

	arr = (int*)malloc(sizeof(int) * size);

	printf("\nEnter the elements of the array:\n");
	for(i = 0; i < size; i++)
		scanf("%d", arr + i);

    selectionSort(arr, size);

	printf("\nThe sorted array is:\n");
	for(i = 0; i < size; i++)
        printf("%d ", arr[i]);

	printf("\n\nEnter the value to be searched:\n");
	scanf("%d", &val);

	pos = binarySearch(arr, size, val);

	if(pos == -1)
		printf("\nElement not found.\n");
	else
		printf("\nElement %d found at position %d.\n", val, pos + 1);

	free(arr);

	return 0;
}

int binarySearch(int *ar, int n, int num)
{
	int beg = 0, end = n - 1, mid, position = -1, found = 0;

	while(beg <= end)
	{
	    mid = (beg + end) / 2;
		if(ar[mid] == num)
        {
			position = mid;
			found = 1;
			break;
        }
		else if(num > ar[mid])
				beg = mid + 1;
			else
				end = mid - 1;
	}
	return position;
}

int smallest(int arr[], int k, int n)
{
    int pos = k, small = arr[k], i;
    for(i = k + 1; i < n; i++)
    {
        if(arr[i] < small)
        {
            small = arr[i];
            pos = i;
        }
    }
    return pos;
}
void selectionSort(int arr[], int n)
{
    int k, pos, temp;
    for(k = 0;k < n; k++)
    {
        pos = smallest(arr, k, n);
        temp = arr[k];
        arr[k] = arr[pos];
        arr[pos] = temp;
    }
}
