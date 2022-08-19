/*** Program to implement queue through linked list ***/
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
void insert(int);
int delete(void);
int IsEmpty(void);
void traverse(void);

static NODE *front = NULL;
static NODE *rear = NULL;

int main()
{
    int option = 0;
    char response;
    int k = 0, x = 0;
    do
    {
        system("cls");
        printf("Program to perform operations on a linear queue\n");
        printf("  Press 1: To insert an item in the queue\n  Press 2: To delete an item from the queue\n  Press 3: To check wether the queue is emptyn\n  Press 4:To traverse through the queue\n");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
            {
                printf("Enter the item to be inserted\n");
                scanf("%d", &x);
                insert(x);
                break;
            }
            case 2:
            {
                if(IsEmpty() == TRUE)
                {
                    printf("Underflow\n");
                }
                else
                {
                    k = delete();
                    printf("The deleted item is %d\n", k);
                }
                break;
            }
            case 3:
            {
                if(IsEmpty() == TRUE)
                    printf("The queue is empty\n");
                else
                    printf("The queue is not empty\n");
                break;
            }
            case 4:
            {

            	traverse();
                break;
            }
            default:
            {
                printf("Invalid option\n");
                break;
            }
        }
        printf("Do you want to perform another operation\n");
        printf("Press y/Y: For yes\nPress n/N: To exit\n");
        scanf("\n");
        scanf("%c", &response);
    }while(response == 'y' || response == 'Y');
}

NODE* createNode(void)
{
	NODE* ptr;
	ptr = (NODE*)malloc(sizeof(NODE));
	ptr->NEXT = NULL;
	return(ptr);
}

int IsEmpty(void)
{
    if((front == NULL) && (rear == NULL))
        return TRUE;
    else
        return FALSE;
}

void insert(int inputInfo)
{
    NODE *temp = createNode();
    temp->info = inputInfo;
    temp->NEXT = NULL;
    if(IsEmpty() == TRUE)
    {
        rear = front = temp;
    }
    else
    {
        rear->NEXT = temp;
        rear = temp;
    }
    printf("The item inserted is %d\n", inputInfo);
}

int delete(void)
{
    int deletedInfo;
    NODE* temp;
    temp = front;
    deletedInfo = temp->info;
    if(rear == front)
    {
        front = rear = NULL;
    }
    else
    {
        front = temp->NEXT;
    }
    free(temp);
    return(deletedInfo);
}

void traverse(void)
{
    if(IsEmpty() == TRUE)
    {
        printf("Empty Queue\n");
    }
    else
    {
        NODE* temp = front;
        int i;

        printf("%10s","Queue: \n");
        while(temp != NULL)
        {
            printf("%5d \n",temp->info);
            temp = temp->NEXT;
        }
    }
}
