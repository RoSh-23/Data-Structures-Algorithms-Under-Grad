/*** Program to represent a polynomial class in one variable using linked list ***/
#include <iostream>
using namespace std;

class polynomial
{
private:
    static int polyCount;
    //structure - a container for a polynomial term
    typedef struct polyTerm_
    {
        float coefficient;
        int exponent;
        struct polyTerm_ *NEXT;
    }polyTerm;
    polyTerm *polyPtr; //Pointer that holds the address of the first term of the polynomial
public:
    polynomial(); //Constructor
    void displayPoly(); //Method to display a polynomial
    void add2Poly(polynomial&, polynomial&); //Method to add two polynomials
    void appendTerm(float, int); //Method to append a term to a existing polynomial
    ~polynomial(); //Destructor
};

int polynomial::polyCount = 0;

polynomial::polynomial() : polyPtr(NULL)
{
    polyCount++;
}

void polynomial::displayPoly()
{
    polyTerm *temp = polyPtr;
    cout << "\nThe polynomial is:\n";
    while(temp->NEXT != NULL)
    {
        if(temp->coefficient > 0)
            cout << temp->coefficient << "x" << "^" << temp->exponent << " + ";
        temp = temp->NEXT;
    }
    cout << temp->coefficient << endl;
}

void polynomial::appendTerm(float c, int e)
{
    polyTerm *temp = polyPtr;
    if(temp == NULL)
    {
        temp = new polyTerm;
        polyPtr = temp;
    }
    else
    {
        while(temp->NEXT != NULL)
        {
            temp = temp->NEXT;
        }
        temp->NEXT = new polyTerm;
        temp = temp->NEXT;
    }
    temp->coefficient = c;
    temp->exponent = e;
    temp->NEXT = NULL;
}

void polynomial::add2Poly(polynomial &pol1, polynomial &pol2)
{
    polyTerm *temp1 = pol1.polyPtr;
    polyTerm *temp2 = pol2.polyPtr;

    while((temp1 != NULL) || (temp2 != NULL))
    {
        if(temp1 == NULL)
        {
            while(temp2 != NULL)
            {
                this->appendTerm(temp2->coefficient, temp2->exponent);
                temp2 = temp2->NEXT;
            }
        }
        else if(temp2 == NULL)
            {
                while(temp1 != NULL)
                {
                    this->appendTerm(temp1->coefficient, temp1->exponent);
                    temp1 = temp1->NEXT;
                }
            }
            else if(temp1->exponent > temp2->exponent)
                {
                    while(temp1->exponent != temp2->exponent)
                    {
                        this->appendTerm(temp1->coefficient, temp1->exponent);
                        temp1 = temp1->NEXT;
                    }
                }
                else if(temp1->exponent == temp2->exponent)
                    {
                        float coe;
                        coe = temp1->coefficient + temp2->coefficient;
                        this->appendTerm(coe, temp1->exponent);
                        temp1 = temp1->NEXT;
                        temp2 = temp2->NEXT;
                    }
                    else
                    {
                        while(temp2->exponent != temp1->exponent)
                        {
                            this->appendTerm(temp2->coefficient, temp2->exponent);
                            temp2 = temp2->NEXT;
                            if(temp2->exponent < temp1->exponent)
                            {
                                this->appendTerm(temp1->coefficient, temp1->exponent);
                                temp1 = temp1->NEXT;
                            }
                        }
                    }
    }
}

polynomial::~polynomial()
{
    polyTerm *temp = polyPtr;
    while(temp != NULL)
    {
        delete temp;
        temp = temp->NEXT;
    }
}

int main()
{

    polynomial p1, p2;

    p1.appendTerm(1.4, 5);
    p1.appendTerm(1.5, 4);
    p1.appendTerm(1.7, 2);
    p1.appendTerm(1.8, 1);
    p1.appendTerm(1.9, 0);

    p2.appendTerm(1.5, 6);
    p2.appendTerm(2.5, 5);
    p2.appendTerm(-3.5, 4);
    p2.appendTerm(4.5, 3);
    p2.appendTerm(6.5, 1);

    p1.displayPoly();
    p2.displayPoly();

    polynomial sum;
    sum.add2Poly(p1, p2);

    cout << "The sum of above two polynomials is:\n";
    sum.displayPoly();

    return 0;
}
