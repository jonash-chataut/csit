#include <stdio.h>
#include <stdlib.h>
// Global variable
int top = -1;
// Functions for stack operation
int push(int max, int stack[]);
int pop(int max, int stack[]);
int display(int stack[]);
int peek(int stack[]);
// Main function
int main()
{
    int MAXSIZE;
    printf("****Basic operations of stack****\n  Complied by -> Jonash\n");
    printf("Enter the size of the stack-> ");
    scanf("%d", &MAXSIZE);
    int stack[MAXSIZE];

    while (1)
    {
        char ch;
        // Asking user for the operation
        printf("\n=========================\n");
        printf("       STACK MENU       \n");
        printf("=========================\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("5. Exit\n");
        printf("=========================\n");
        printf("Enter your choice-> ");
        scanf(" %c", &ch);
        // Using switch case to do user choice
        switch (ch)
        {
        case '1':
            push(MAXSIZE, stack);
            break;
        case '2':
            pop(MAXSIZE, stack);
            break;
        case '3':
            display(stack);
            break;
        case '4':
            peek(stack);
            break;
        case '5':
            printf("Program exited successfully!\n");
            exit(0);
        default:
            printf("Invalid choice!!! Please try again.\n");
        }
    }
    return 0;
}
// Function implementation
int push(int max, int stack[])
{
    int n;
    if (top == max - 1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        printf("Enter the element to be pushed-> ");
        scanf("%d", &n);
        top++;
        stack[top] = n;
        printf("Element pushed\n");
    }
    return 0;
}

int pop(int max, int stack[])
{
    if (top == -1)
    {
        printf("Stack underflow\n");
    }
    else
    {
        int pe = stack[top];
        top--;
        printf("Element popped: %d\n", pe);
    }
    return 0;
}

int display(int stack[])
{
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
    return 0;
}

int peek(int stack[])
{
    if (top == -1)
    {
        printf("Stack is empty!!! No top element :)\n");
    }
    else
    {
        printf("Top element is: %d\n", stack[top]);
    }
    return 0;
}
