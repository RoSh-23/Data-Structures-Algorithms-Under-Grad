/*Program to reverse a string using stack*/
#include <stdio.h>
#include "Stack_array_string.h"

int main(){

	stack s;
	s.top = -1;
	char input_str[100];

	printf("Program to reverse a string\n");
	scanf("%[^\n]", input_str);

	for(int i = 0; input_str[i] != '\0'; i++){
		push(&s, input_str[i]);
	}

	while(IsEmpty(&s) != TRUE){
		printf("%c", s.str[s.top]);
		pop(&s);
	}

	return 0;
}