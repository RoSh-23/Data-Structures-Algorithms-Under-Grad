/*Program to check the validity of a string by parentheses checking*/

#include <stdio.h>
#include <stdlib.h>
#include "Stack_array_string.h"

int matching(char , char );

int main(int argc, char const *argv[])
{	
	stack s;
	s.top = -TRUE;

	int valid = TRUE;

	printf("\nProgram to validate an expression\n");

	printf("Enter an expression\n");
	scanf("%s", s.str);

	for(int i = FALSE; s.str[i] != '\0'; i++)
	{
		if((s.str[i] == '(') || (s.str[i] == '[') || (s.str[i] == '{'))
		{
			push(&s, s.str[i]);
		}
		if((s.str[i] == ')') || (s.str[i] == ']') || (s.str[i] == '}'))
		{
			if(IsEmpty(&s) == TRUE)
			{
				valid = FALSE;
			}
			else
			{
				char deleted = pop(&s);
				if(matching(deleted, s.str[i]) != TRUE)
				{
					valid = FALSE;
				}
			}	
		}	
	}
	if(IsEmpty(&s) == FALSE)
	{
		valid = FALSE;
	}

	if(valid == TRUE)
		printf("%s\n","Valid String");
	else
		printf("%s\n","Invalid String");

	return 0;
}

int matching(char ch1, char ch2)
{
	if(ch1 == '(' && ch2 == ')')
		return TRUE;
	else if(ch1 == '{' && ch2 == '}')
		return TRUE;
		else if(ch1 == '[' && ch2 == ']')
			return TRUE;
			else 
				return FALSE;
}