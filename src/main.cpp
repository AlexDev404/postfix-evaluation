// Name: Renee Banner
// Topic: Assignment 2
// Teacher: Ms. Vernelle Sylvester
// Subject: Data Stuctures
// Date:20th November, 2023

#include <iostream>
using std::cout;

class Stack {
public:
    int data;
    Stack *Next;
};

int calculate(char exp, int x, int y) {
    int result = 0;
    int j;

    if (exp == '+')
        result = y + x;

    else if (exp == '-')
    {
        if (x > y)
        {
            j = y;
            y = x;
            x = j;
        }
        result = y - x;
    }
    else if (exp == '*') {
        result = y * x;
    }
    else if (exp == '/') {
        if (x > y)
        {
            j = y;
            y = x;
            x = j;
        }
        result = y / x;
    }
    else if (exp == '^')
    {

        int d = 1;
        for (int i = 0; i < x; i++)
        {
            d = d * y;
        }
        result = d;
    }
    else if (exp == '%')
        result = y % x;

    return result;
}
bool isEmpty(Stack *&head)
{
    if (head == NULL)
        return true;
    else
        return false;
}
void push(int a, Stack **head)
{

    Stack *newNode = new Stack;
    newNode->data = a;
    newNode->Next = *head;
    *head = newNode;
}
void pop(Stack **head)
{
    if (isEmpty(*head))
        cout << "\nThe stack is empty";
    else
        *head = (*head)->Next;
}

void printStack(Stack *head)
{
    while (!isEmpty(head))
    {
        cout << "The answer to your expression is: " << head->data;
        pop(&head);
    }

    cout << "\nThe stack is now empty\n";
}

void evaluatePostfixExpression(string express, Stack *head)
{

    int i = 0;

    while (express[i] != '\0')
    {

        if (isdigit(express[i]))
            push(express[i] - '0', &head);

        else
        {
            int x = head->data;
            pop(&head);
            int y = head->data;
            pop(&head);
            push(calculate(express[i], x, y), &head);
        }
        i++;
    }
    printStack(head);
}
int main()
{
    Stack *head = NULL;
    string expression = "62+5*48/-";

    evaluatePostfixExpression(expression, head);
    return 0;
}