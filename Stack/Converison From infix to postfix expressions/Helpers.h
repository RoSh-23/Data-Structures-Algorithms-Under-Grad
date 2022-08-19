/*Helper functions header file for evaluating a postfix*/
/*and converting an infix expression into postfix*/
#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

extern int isOperator(char);
extern int precedence(int,char,char);