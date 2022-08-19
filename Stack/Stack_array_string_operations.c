/*Definitions of the stack operations of fucntions on the string of characters*/
#include <stdio.h>
#include <stdlib.h>
#include "Stack_array_string.h"
/*To check is the stack empty*/
int IsEmpty(stack* ps)
{
	if(ps->top == -1)
		return TRUE;
	else
		return FALSE;
}
/*To push a character onto the stack*/
void push(stack* ps, char ch)
{	
	if(ps->top == (MAX_SIZE - 1))
	{
		printf("Stack Overflow\n");
	}
	else
	{
		ps->top++;
		ps->str[ps->top] = ch;
	}
}
/*To pop a character from the stack*/
char pop(stack* ps)
{
	if(IsEmpty(ps) == TRUE)
	{
		printf("Stack Underflow\n");
	}
	else
	{
		return(ps->str[ps->top--]);
	}
}
/*To traverse through the stack*/
void traverse(stack* ps)
{
	if(IsEmpty(ps) == TRUE)
	{
		printf("Empty Stack\n");
	}
	else
	{
		for(int i = 0; i <= ps->top; i++)
		{
			printf("%c\n", ps->str[i]);
		}
	}
}