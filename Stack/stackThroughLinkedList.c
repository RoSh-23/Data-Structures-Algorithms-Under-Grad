/*** Program to implement stack through linked list ***/
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
void push(int);
int pop(void);
void traverse(void);
int isEmpty(void);

static NODE *start = NULL;

int main()
{
    char response = 'Y';
	int option = 0;
	int x;
	do
	{
		system("cls");
		printf("Program to perform operations on a stack\n");
		printf("\nPress:\n 1: To push an item into the stack\n 2: To pop an item from the stack\n 3: To traverse through the stack\n");
		scanf("%d", &option);
		switch(option)
		{
			case 1:
			{
				printf("Enter the element to be pushed\n");
				scanf("%d", &x);
				push(x);
				break;
			}
			case 2:
			{
                if(isEmpty() == TRUE)
                {
                    printf("The stack is empty\n");
                }
                else
                {
                    x = pop();
                    printf("The element popped is %d\n", x);
                }
				break;
			}
			case 3:
			{
				traverse();
				break;
			}
			default:
			{
				printf("\nInvalid option\n");
				break;
			}
		}/* End switch */
		printf("\nPress\n(Y/y): To do another operation OR To select another option\n(N/n): To stop\n");
		scanf("\n");
		scanf("%c", &response);
		}while((response == 'Y') || (response == 'y'));/* End do-while */

    return 0;
}

NODE* createNode(void)
{
	NODE* ptr;
	ptr = (NODE*)malloc(sizeof(NODE));
	ptr->NEXT = NULL;
	return(ptr);
}

int isEmpty(void)
{
    if(start == NULL)
        return TRUE;
    else
        return FALSE;
}

void push(int inputInfo)
{
    NODE *temp = createNode();
    temp->info = inputInfo;
    temp->NEXT = start;
    start = temp;
}

int pop(void)
{
    int deletedInfo;
    NODE* temp;
    temp = start;
    deletedInfo = temp->info;
    start = temp->NEXT;
    free(temp);
    return(deletedInfo);
}

void traverse(void)
{
    if(isEmpty() == TRUE)
    {
        printf("Empty Stack\n");
    }
    else
    {
        NODE* temp = start;
        int i;

        printf("%10s","Stack: \n");
        while(temp != NULL)
        {
            printf("%5d \n",temp->info);
            temp = temp->NEXT;
        }
    }
}
