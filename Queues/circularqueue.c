/*Program to implement circular queue*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define MAX_QUEUE 100
#define TRUE 1
#define FALSE 0

typedef struct QUEUE
{
    int rear;
    int front;
    int items[MAX_QUEUE];
} QUEUE;

void insert(int, QUEUE*);
int delete(QUEUE*);
int IsEmpty(QUEUE*);
void traverse(QUEUE*);
int IsFull(QUEUE*);

int main()
{

    QUEUE q;
    /*Original queue*/
    q.front = -1;
    q.rear = -1;

    int option = 0;
    char response;
    int k = 0, x = 0;
    do
    {
        //system("cls");
        printf("Program to perform operations on a circular queue\n\n");
        printf("  Press 1: To insert an item in the queue\n  Press 2: To delete an item fromt the queue\n  Press 3: To check if the queue is emptyn\n  Press 4:To traverse through the queue\n  Press 5: To check if the queue is full\n");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
            {
                if(IsFull(&q) == TRUE)
                {
                    printf("Overflow\n\n");
                }
                else
                {
                    printf("Enter the item to be inserted\n");
                    scanf("%d", &x);
                    insert(x, &q);
                }
                break;
            }
            case 2:
            {
                if(IsEmpty(&q) == TRUE)
                {
                    printf("Underflow\n\n");
                }
                else
                {
                    k = delete(&q);
                    printf("The deleted item is %d\n\n", k);
                }
                break;
            }
            case 3:
            {
                if(IsEmpty(&q) == TRUE)
                    printf("The queue is empty\n\n");
                else
                    printf("The queue is not empty\n\n");
                break;
            }
            case 4:
            {
                traverse(&q);
                break;
            }
            case 5:
            {
                if(IsFull(&q) == TRUE)
                {
                    printf("The queue is full\n\n");
                }
                else
                {
                    printf("The queue is not full\n\n");
                }
            }
            default:
            {
                printf("Worng option\n");
                break;
            }
        }
        printf("Do you want to perform another operation\n");
        printf("Press y/Y: For yes\nPress n/N: To exit\n");
        scanf("\n");
        scanf("%c", &response);
    }while(response == 'y' || response == 'Y');
}

int IsEmpty(QUEUE *qp)
{
    if((qp->rear == -1) && (qp->front == -1))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

int IsFull(QUEUE* qp)
{
	if(qp->rear == (MAX_QUEUE - 1) && (qp->front == 0))
		return TRUE;
	else if((qp->rear) == (qp->front - 1))
			return TRUE;
		else
			return FALSE;
}

void insert(int x, QUEUE *qp)
{

    if(IsEmpty(qp) == TRUE)
    {
        qp->rear = qp->rear + 1;
        qp->front = qp->front + 1;
        qp->items[qp->rear] = x;
        printf("The item inserted is %d\n\n", x);
    }
  	else if(qp->rear < (MAX_QUEUE - 1))
    {
        qp->rear = qp->rear + 1;
        qp->items[qp->rear] = x;
        printf("The item inserted is %d\n\n", x);
    }
       	else if(qp->rear == (MAX_QUEUE - 1))
        {
        	qp->rear = 0;
        	qp->items[qp->rear] = x;
        	printf("The item inserted is %d\n\n", x);
        }
}

int delete(QUEUE *qp)
{
    int k = 0;
    if(qp->rear == qp->front)
    {
        k = qp->items[qp->front];
        /*setting the queue to empty position*/
        qp->front = -1;
        qp->rear = -1;
        return k;
    }
    else if(qp->front == (MAX_QUEUE - 1))
        {
        k = qp->items[qp->front];
        qp->front = 0;
        return k;
        }
        else
        {
            k = qp->items[qp->front];
            qp->front = qp->front + 1;
            return k;
        }
}

void traverse(QUEUE *qp)
{
    int i = 0;
    if(IsEmpty(qp) == TRUE)
    {
        printf("Empty queue\n\n");
    }
    else
    {
    	if(qp->front <= qp->rear)
    	{
        	printf("The current queue is \n");
        	for(i = qp->front; i <= qp->rear; i++)
        	{
            	printf("%d ",qp->items[i]);
        	}
        }
        else
        {
        	printf("The current queue is \n");
        	for(i = qp->front; i <= (MAX_QUEUE - 1); i++)
        	{
        		printf("%d ",qp->items[i]);
        	}
        	for(i = 0; i <= qp->rear; i++)
        	{
        		printf("%d ",qp->items[i]);
        	}
        }
        printf("\n");
    }
}
