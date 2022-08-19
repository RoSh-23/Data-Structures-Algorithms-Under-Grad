#include <stdio.h>
#include "Helpers.h"

int isOperator(char ch)
{
	if(ch == '+' ||ch == '-' || ch == '/' || ch == '*'  || ch == '$' || ch == '(' || ch == ')')
		return TRUE;
	else 
		return FALSE;
}
int precedence(int top,char op1,char op2)
{
	if(top == -1)
		return FALSE;
	else if(op1 == '(')
		return FALSE;
	else if(op1 == '$')
		return TRUE;
	else if(op1 == '*' || op1 == '/')
	{
		if(op2 == '$')
			return FALSE;
		else
			return TRUE;
	}
	else if(op2 == '+' || op2 == '-')
	{
		return TRUE;
	}
		else 
			return FALSE;
}