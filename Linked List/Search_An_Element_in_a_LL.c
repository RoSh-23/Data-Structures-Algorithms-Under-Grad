/*** Program to implement a search a particular data in a linked list - focus on search_list function ***/
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

struct node
{
	int info;
	struct node *NEXT;
};

typedef struct node NODE;

NODE* createNode(void);
void insert(int, int);//insert(element,elementPosition)
int delete(int);//elementDeleted delete(position)
int elementCount(void);
int isEmpty(void);
void search_list(int);
void printList(void);

static NODE *start = NULL;

int main()
{
    char response;
    do
    {
        system("cls");
        printf("Program to perform operations on a linked list\n");

        int choice;
        int count = elementCount();
        printf("Press 1: To Insert\nPress 2: To Delete\nPress 3: To Display the list \nPress 4: To search an element in the list \nPress 5: To Exit\n");
        printf("\nEnter your choice\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {
                int insertInfo, position;

                printf("\nList before insertion is\n");
                printList();
                printf("Total elements are: %d\n", count);

                printf("\nTo insert at first: Enter position 1\nTo insert at last: Enter position %d\nTo insert in between: Enter position in range: (1-%d]",count + 1, count);
                printf("\nEnter the position: ");
                scanf("%d", &position);

                if(position < 1 || position > count + 1)
                {
                    printf("\nInvalid position entered\n");
                }
                else
                {
                    printf("\nEnter the element: ");
                    scanf("%d", &insertInfo);

                    insert(insertInfo, position);

                    printf("\n%d element inserted successfully\n", insertInfo);
                    printf("\nList after insertion\n");
                    printList();
                }
                break;
            }
            case 2:
            {
                if(isEmpty() == TRUE)
                {
                    printf("The list is empty\n");
                }
                else
                {
                    int position, deletedInfo;

                    printf("\nList before deletion is:\n");
                    printList();
                    printf("Total elements are: %d\n", count);

                    printf("\nTo delete first: Enter position 1\nTo delete last: Enter position %d\nTo delete in between: Enter position in range (1-%d)\n", count, count);
                    printf("\nEnter position: ");
                    scanf("%d", &position);

                    if(position < 1 || position > count)
                    {
                        printf("\nInvalid position entered\n");
                    }
                    else
                    {
                        deletedInfo = delete(position);

                        printf("\n%d successfully deleted\n", deletedInfo);

                        printf("List after deletion is:\n");
                        printList();
                    }
                }
                break;
            }
            case 3:
            {
                printList();
                break;
            }
            case 4:
            {
                int element;
                printf("Enter the element to be searched\n");
                scanf("%d", &element);
                search_list(element);
                break;
            }
            case 5:
            {
                exit(1);
            }
            default:
            {
                printf("Invalid choice\n");
                break;
            }
        }
    printf("\nDo you want to perform another operation? \nPress Y/y: for Yes \nPress N/n: for No\n");
    scanf("\n");
    scanf("%c", &response);
    }while(response == 'y' || response == 'Y');
}

//function which creates a new node
NODE* createNode(void)
{
	NODE* ptr;
	ptr = (NODE*)malloc(sizeof(NODE));
	ptr->NEXT = NULL;
	return(ptr);
}

//function to insert element in a list
void insert(int inputInfo, int position)
{
    NODE *temp = createNode();
    temp->info = inputInfo;

    int count = elementCount();


    if(position == 1)
    {
        temp->NEXT = start;
        start = temp;
    }
    else if(position == count + 1)
        {
            NODE* last = start;

            while(last->NEXT != NULL)
            {
                last = last->NEXT;
            }
            temp->NEXT = NULL;
            last->NEXT = temp;
        }
        else
        {
            int i;
            NODE *positionPtr, *positionPrevPtr;
            positionPtr = start;
            for(i = 0; i < position - 1; i++)
            {
                positionPrevPtr = positionPtr;
                positionPtr = positionPtr->NEXT;
            }

            temp->NEXT = positionPtr;
            positionPrevPtr->NEXT = temp;
        }
}

//function to delete a element from the list
int delete(int position)
{
    int deletedInfo;
    int count = elementCount();

    if(position == 1)
    {
        NODE* temp;
        temp = start;
        deletedInfo = temp->info;
        start = temp->NEXT;
        free(temp);
        return(deletedInfo);
    }
    else if(position == count)
        {
            NODE *lastPtr = NULL, *lastPrevPtr = NULL;

            lastPtr = start;
            while(lastPtr->NEXT != NULL)
            {
                lastPrevPtr = lastPtr;
                lastPtr = lastPtr->NEXT;
            }
            deletedInfo = lastPtr->info;
            lastPrevPtr->NEXT = NULL;
            free(lastPtr);

            return(deletedInfo);
        }
        else
        {
            NODE *positionPtr, *positionPrevPtr;
            int i;

            positionPtr = start;

            for(i = 0; i < (position - 1); i++)
            {
                positionPrevPtr = positionPtr;
                positionPtr = positionPtr->NEXT;
            }

            deletedInfo = positionPtr->info;
            positionPrevPtr->NEXT = positionPtr->NEXT;
            free(positionPtr);
            return deletedInfo;
        }
}
//function to display all elements of the list
void printList(void)
{
    if(isEmpty() == TRUE)
    {
        printf("Empty list\n");
    }
    else
    {
        NODE* temp = start;
        int i, count = elementCount();

        printf("%10s","List: ");
        while(temp != NULL)
        {
            printf("%5d ",temp->info);
            temp = temp->NEXT;
        }
        printf("%12s","\nPosition: ");

        for(i = 0; i < count; i++)
        {
            printf("%5d ", i + 1);
        }
        printf("\n");
    }
}



//function to search an element in the list
void search_list(int element)
{
    int freq = 0, i = 0;
    NODE* temp = start;
    while(temp != NULL)
    {
        if(element == temp->info)
        {
            freq++;
        }
        temp = temp->NEXT;
    }
    NODE* nodeptr_arr[freq + 1];
    int positionFound[freq], position = 1;
    temp = start;
    for(position = 1; temp != NULL; position++)
    {
        if(element == temp->info)
        {
            nodeptr_arr[i] = temp;
            positionFound[i] = position;
            i++;
        }
        temp = temp->NEXT;

    }
    nodeptr_arr[freq + 1] = NULL;
    printf("The positions where the element has been found are\n");
    for(i = 0; i < freq; i++)
    {
        printf("%d ", positionFound[i]);
    }
}

//function to check whether the list is empty or not
int isEmpty(void)
{
    if(start == NULL)
        return TRUE;
    else
        return FALSE;
}

//function which returns the number of elements present in the list
int elementCount(void)
{
    NODE* temp = start;
    int count = 0;
    while(temp != NULL)
    {
        count++;
        temp = temp->NEXT;
    }
    return(count);
}
