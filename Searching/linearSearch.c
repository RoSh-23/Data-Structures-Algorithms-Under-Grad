/*** Program to implement linear search ***/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

/*
arguments
	int* : name of array
	int  : size of array
	int  : value to be searched
return type
	int  : -1 for not found
			position for successful search
*/
int linearSearch(int*, int, int);

int main()
{
	int size, i, val, position;
	int *arr;

	printf("Enter the size of the array:\n");
	scanf("%d", &size);

	arr = (int*)malloc(sizeof(int) * size);
	if(arr == NULL)
    {
        printf("Not enough memory space\n");
        exit(1);
    }

	printf("Enter the elements of the array\n");
	for(i = 0; i < size; i++)
		scanf("%d", arr + i);

	printf("\nEnter the value to be searched in the array\n");
	scanf("%d", &val);

	position = linearSearch(arr, size, val);

	if(position == -1)
		printf("\nElement not found.\n");
	else
		printf("\nElement found at position %d\n", position + 1);

    free(arr);

	return 0;
}

int linearSearch(int *ar, int n, int v)
{
	int pos = -1, i;
	for(i = 0; i < n; i++)
	{
		if(ar[i] == v)
        {
			pos = i;
			break;
        }
	}
	return pos;
}
