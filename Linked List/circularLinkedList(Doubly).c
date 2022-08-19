/*** Program to implement a circular doubly linked list ***/
#include <stdio.h>
#include  <stdlib.h>

#define TRUE 1
#define FALSE 0

struct node
{
    int info;
    struct node *LEFT;//pointer to the left of the current node
    struct node *RIGHT;//pointer to the right of the current node
};

typedef struct node NODE;

NODE* createNode(void);//function to create a node
void insert(int, int);//insert(element,elementPosition)
int delete(int);//elementDeleted delete(position)
int elementCount(void);
int isEmpty(void);
void printList(void);

static NODE *start = NULL;

int main()
{
    char response;
    do
    {
        system("cls");
        printf("Program to perform operations on a circular doubly linked list\n");

        int choice;
        int count = elementCount();
        printf("%s\n%s\n%s\n%s\n",  "Press 1: To Insert",
                                    "Press 2: To Delete",
                                    "Press 3: To Display",
                                    "Press 4: To Exit" );
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {
                int insertInfo, position;

                printf("\nList before insertion is\n");
                printList();
                printf("Total elements are: %d\n", count);

                printf("\nTo insert at first    : Enter position 1\nTo insert at last     : Enter position %d\nTo insert in between  : Enter position in range: (1-%d]",count + 1, count);
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

                    printf("\nTo delete first node  : Enter position 1\nTo delete last node   : Enter position %d\nTo delete in between  : Enter position in range (1-%d)\n", count, count);
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

//function to create a node
NODE* createNode(void)
{
    NODE *ptr;
    ptr = (NODE*)malloc(sizeof(NODE));
    ptr->RIGHT = NULL;
    ptr->LEFT = NULL;
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
        if(start == NULL)
        {
            temp->RIGHT = temp->LEFT = temp;
            start = temp;
            return;
        }
        if(count == 1)
        {
            start->RIGHT = start->LEFT = temp;
            temp->RIGHT = temp->LEFT = start;
            start = temp;
            return;
        }
        NODE *last = start;
        while(last->RIGHT != start)
        {
            last = last->RIGHT;
        }
        temp->LEFT = last;
        temp->RIGHT = start;
        last->RIGHT = temp;
        start = temp;
    }
    else if(position == count + 1)
        {
            NODE* lastPtr = start;

            while(lastPtr->RIGHT != start)
            {
                lastPtr = lastPtr->RIGHT;
            }
            temp->LEFT = lastPtr;
            temp->RIGHT = start;
            lastPtr->RIGHT = temp;
        }
        else
        {
            int i;
            NODE *positionPtr;
            positionPtr = start;
            for(i = 0; i < position - 1; i++)
            {
                positionPtr = positionPtr->RIGHT;
            }

            temp->RIGHT = positionPtr;
            temp->LEFT = positionPtr->LEFT;
            (positionPtr->LEFT)->RIGHT = temp;
            positionPtr->LEFT = temp;
        }
}

//function to delete a element from the list
int delete(int position)
{
    int deletedInfo;
    int count = elementCount();

    if(count == 1)
    {
        NODE* temp = start;
        int deletedInfo = temp->info;
        free(temp);
        start = NULL;
        return deletedInfo;
    }
    if(position == 1)
        {
            NODE* temp, *last;
            last = temp = start;
            while(last->RIGHT != start)
            {
                last = last->RIGHT;
            }
            deletedInfo = temp->info;
            start = temp->RIGHT;
            (temp->RIGHT)->LEFT = last;
            last->RIGHT = temp->RIGHT;
            free(temp);
            return(deletedInfo);
        }
        else if(position == count)
            {
                NODE *lastPtr = NULL;

                lastPtr = start;
                while(lastPtr->RIGHT != start)
                {
                    lastPtr = lastPtr->RIGHT;
                }
                deletedInfo = lastPtr->info;
                (lastPtr->LEFT)->RIGHT = start;
                start->LEFT = lastPtr->LEFT;
                free(lastPtr);

                return(deletedInfo);
            }
            else
            {
                NODE *positionPtr;
                int i;

                positionPtr = start;

                for(i = 0; i < (position - 1); i++)
                {
                    positionPtr = positionPtr->RIGHT;
                }

                deletedInfo = positionPtr->info;
                (positionPtr->LEFT)->RIGHT = positionPtr->RIGHT;
                (positionPtr->RIGHT)->LEFT = positionPtr->LEFT;
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
        NODE* temp = start->RIGHT;
        int i, count = elementCount();

        printf("%10s", "List: ");
        printf("%5d ",start->info);
        while(temp != start)
        {
            printf("%5d ",temp->info);
            temp = temp->RIGHT;
        }
        printf("%12s", "\nPosition: ");

        for(i = 0; i < count; i++)
        {
            printf("%5d ", i + 1);
        }

        printf("\n");
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
    if(start == NULL)
        return 0;
    else
    {
        NODE* temp = start->RIGHT;
        int count = 1;
        while(temp != start)
        {
            count++;
            temp = temp->RIGHT;
        }
        return(count);
    }
}
