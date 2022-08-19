/*** Program to represent a polynomial in one variable using linked list ***/
#include <stdio.h>
#include <stdlib.h>

typedef struct polynomialTerm
{
    float coefficient;              // variable to hold the coefficient
    int exponent;                   // variable to hold the exponent
    struct polynomialTerm *NEXT;    // Pointer to the next polynomial term
}polyTerm;

void displayPoly(polyTerm*);                // function to display the entire polynomial
polyTerm* appendTerm(polyTerm*, float, int);     // function to append a term to an existing polynomial
polyTerm* add2Poly(polyTerm*, polyTerm*);   // function to add to polynomials
void destruct(polyTerm*);                   // function to destruct a polynomial

int main()
{
    polyTerm *p1 = NULL, *p2 = NULL;

    p1 = appendTerm(p1, 1.4, 5);
    p1 = appendTerm(p1, 1.5, 4);
    p1 = appendTerm(p1, 1.7, 2);
    p1 = appendTerm(p1, 1.8, 1);
    p1 = appendTerm(p1, 1.9, 0);

    p2 = appendTerm(p2, 1.5, 6);
    p2 = appendTerm(p2, 2.5, 5);
    p2 = appendTerm(p2, -3.5, 4);
    p2 = appendTerm(p2, 4.5, 3);
    p2 =  appendTerm(p2, 6.5, 1);

    displayPoly(p1);
    displayPoly(p2);

    polyTerm *sum;
    sum = add2Poly(p1, p2);

    printf("The sum of above two polynomials is:\n");
    displayPoly(sum);

    destruct(p1);
    destruct(p2);
    destruct(sum);

    return 0;
}

void displayPoly(polyTerm *polyPtr)
{
    polyTerm *temp = polyPtr;   // temp to traverse through the polynomial
    printf("\nThe polynomial is:\n");
    while(temp->NEXT != NULL)
    {
        if(temp->coefficient > 0)
            printf("%.1fx^%d + ", temp->coefficient, temp->exponent);
        temp = temp->NEXT;
    }
    printf("%.1f\n", temp->coefficient);
}

polyTerm* appendTerm(polyTerm* polyPtr, float c, int e)     // function to append a term to an existing polynomial
{
    polyTerm *temp = polyPtr;
    if(temp == NULL)
    {
        temp = (polyTerm*)malloc(sizeof(polyTerm));
        polyPtr = temp;
    }
    else
    {
        while(temp->NEXT != NULL)
        {
            temp = temp->NEXT;
        }
        temp->NEXT = (polyTerm*)malloc(sizeof(polyTerm));
        temp = temp->NEXT;
    }
    temp->coefficient = c;
    temp->exponent = e;
    temp->NEXT = NULL;
    return polyPtr;
}

polyTerm* add2Poly(polyTerm* pol1, polyTerm* pol2)
{
    polyTerm *temp1 = pol1;
    polyTerm *temp2 = pol2;
    polyTerm *sum = NULL;

    while((temp1 != NULL) || (temp2 != NULL))
    {
        if(temp1 == NULL)
        {
            while(temp2 != NULL)
            {
                sum = appendTerm(sum, temp2->coefficient, temp2->exponent);
                temp2 = temp2->NEXT;
            }
        }
        else if(temp2 == NULL)
            {
                while(temp1 != NULL)
                {
                    sum = appendTerm(sum, temp1->coefficient, temp1->exponent);
                    temp1 = temp1->NEXT;
                }
            }
            else if(temp1->exponent > temp2->exponent)
                {
                    while(temp1->exponent != temp2->exponent)
                    {
                        sum = appendTerm(sum, temp1->coefficient, temp1->exponent);
                        temp1 = temp1->NEXT;
                    }
                }
                else if(temp1->exponent == temp2->exponent)
                    {
                        float coe;
                        coe = temp1->coefficient + temp2->coefficient;
                        sum = appendTerm(sum, coe, temp1->exponent);
                        temp1 = temp1->NEXT;
                        temp2 = temp2->NEXT;
                    }
                    else
                    {
                        while(temp2->exponent != temp1->exponent)
                        {
                            sum = appendTerm(sum, temp2->coefficient, temp2->exponent);
                            temp2 = temp2->NEXT;
                            if(temp2->exponent < temp1->exponent)
                            {
                                sum = appendTerm(sum, temp1->coefficient, temp1->exponent);
                                temp1 = temp1->NEXT;
                            }
                        }
                    }
    }
    return sum;
}

void destruct(polyTerm* polyPtr)
{
    polyTerm *temp = polyPtr;
    while(temp != NULL)
    {
        free(temp);
        temp = temp->NEXT;
    }
}
