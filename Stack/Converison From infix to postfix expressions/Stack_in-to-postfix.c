/*Program to convert an expression from infix to postfix*/
#include <stdio.h>
#include <stdlib.h>
#include "Stack_array_string.h"
#include "Helpers.h"

int main(int argc, char const *argv[])
{
	char op, response;
	
	
	do
	{
		char infix[MAX_SIZE] = {0}, postfix[MAX_SIZE] = {0};
		int i = 0;
		stack opstack;
		opstack.top = -1;
		char symb;
		system("clear");
		printf("Program to convert an infix expression to a postfix expression\n");
		printf("Enter an infix expression\n");
		scanf("%s", infix);

		for(int j = 0; (symb = infix[j]) != '\0'; j++)
		{
			if((isOperator(symb)) == TRUE)
			{
				if(symb == '(')
				{
					push(&opstack, symb);
					
				}
				else if(symb == ')')
				{
					while(opstack.str[opstack.top] != '(')
					{
						op = pop(&opstack);

						postfix[i] = op;
						i++;
					}
					pop(&opstack);
	
				}	
					else if((precedence(opstack.top,opstack.str[opstack.top], symb)) == TRUE)
					{
						op = pop(&opstack);
						postfix[i] = op;
						i++;
						push(&opstack, symb);
						
					}
						else
						{
							push(&opstack, symb);
							
						}
			}
			else
			{
				postfix[i] = symb;
				i++;
				
			}	

		}
		while(opstack.top != -1)
		{
			op = pop(&opstack);
			postfix[i] = op;
			i++;
			
		}
		printf("Infix: %s\n", infix);
		printf("Postfix: %s\n", postfix);
		printf("\nPress\ny/Y: To convert another expression\nn/N To exit\n");
		scanf("\n");
		scanf("%c", &response);
	}while(response == 'y' || response == 'Y');	

	return 0;
}