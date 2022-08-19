/*Program to implement stack through array*/
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define STACK_SIZE 100

typedef struct stack{
	int top;
	int items[STACK_SIZE];
}stack;

void push(stack*, int);
int pop(stack*);
void traverse(stack*);
int empty(stack*);


int main()
{

	stack s;
	s.top = -1;
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
				push(&s,x);
				break;
			}
			case 2:
			{
				 if(empty(&s) == TRUE)
                {
                    printf("The stack is empty\n");
                }
                else
                {
                    x = pop(&s);
                    printf("The element popped is %d\n", x);
                }
				break;
			}
			case 3:
			{
				traverse(&s);
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
}

int empty(struct stack *ps)
{
	if(ps->top == -1)
		return(TRUE);
	else
		return(FALSE);
}

int pop(struct stack *ps)
{
	if(empty(ps))
	{
		printf("%s","stack underflow");
	}
	else
	{
		return(ps->items[ps->top--]);
	}
}

void push(struct stack *ps, int x)
{
	if(ps->top == STACK_SIZE-1)
	{
		printf("%s\n", "stack overflow");
	}
	else
	{
		ps->items[++(ps->top)] = x;
	}
}

void traverse(struct stack *ps)
{
	printf("\n");
		int i = 0;
	if(empty(ps) == TRUE)
	{
		printf("Empty Stack\n");
	}/* end if */
	else
	{
		printf("The elements of the stack from top to bottom are\n");
		for(i = ps->top; i > -1; i--)
		{
			printf("%d\n", ps->items[i]);
		}/* End for */
	} /* End else */
}/* End traverse */
