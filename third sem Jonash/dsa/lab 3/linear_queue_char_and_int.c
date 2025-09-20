#include <stdio.h>
#include <stdlib.h>

int rear = -1;  // Index for the last element
int front = -1; // Index for the first element
// Structure to store the elements of the queue as integers or characters
typedef union
{
    int intValue;
    char charValue;
} Element;
// Function prototypes
int enqueue(int max, Element queue[], char types[]);
int dequeue(Element queue[], char types[]);
int display(Element queue[], char types[]);

int main()
{
    int MAXSIZE;
    printf("****Basic operations of linear queue****\n  Compiled by -> Jonash\n");
    printf("Enter the size of the queue: ");
    scanf("%d", &MAXSIZE);
    Element queue[MAXSIZE];
    char types[MAXSIZE]; // Array to track the type of each element ('i' for int, 'c' for char)
    // Menu-driven program
    while (1)
    {
        char ch;
        printf("\nEnter your choice:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        scanf(" %c", &ch);

        switch (ch)
        {
        case '1':
            enqueue(MAXSIZE, queue, types);
            break;
        case '2':
            dequeue(queue, types);
            break;
        case '3':
            display(queue, types);
            break;
        case '4':
            printf("Program exited successfully!!!\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
// Function to add an element to the queue
int enqueue(int max, Element queue[], char types[])
{
    if (rear == max - 1) // Queue is full
    {
        printf("Queue overflow. Cannot enqueue.\n");
    }
    else
    {
        printf("Enter the type of element to enqueue (i for integer, c for character): ");
        char type;
        scanf(" %c", &type);

        if (type == 'i')
        {
            int n;
            printf("Enter the integer to be enqueued: ");
            scanf("%d", &n);
            rear++;
            queue[rear].intValue = n;
            types[rear] = 'i';
            printf("Integer enqueued: %d\n", n);
        }
        else if (type == 'c')
        {
            char c;
            printf("Enter the character to be enqueued: ");
            scanf(" %c", &c);
            rear++;
            queue[rear].charValue = c;
            types[rear] = 'c';
            printf("Character enqueued: %c\n", c);
        }
        else
        {
            printf("Invalid type. Please use 'i' for integer or 'c' for character.\n");
        }
    }
    return 0;
}
// Function to remove an element from the queue
int dequeue(Element queue[], char types[])
{
    if (front == rear) // Queue is empty
    {
        printf("Queue is empty. Cannot dequeue.\n");
    }
    else
    {
        front++;
        if (types[front] == 'i')
        {
            printf("Integer dequeued: %d\n", queue[front].intValue);
        }
        else if (types[front] == 'c')
        {
            printf("Character dequeued: %c\n", queue[front].charValue);
        }
    }
    return 0;
}
// Function to display the elements of the queue
int display(Element queue[], char types[])
{
    if (front == rear) // Queue is empty
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Queue elements are:\n");
        printf(" ");
        for (int i = front + 1; i <= rear; i++)
        {
            if (types[i] == 'i')
            {
                printf("| %d ", queue[i].intValue);
            }
            else if (types[i] == 'c')
            {
                printf("| %c  ", queue[i].charValue);
            }
        }
        printf("\n");
        printf("F->");
        for (int i = front + 2; i <= rear; i++)
        {
            printf("    ");
        }
        printf(" <-R\n");
    }
    return 0;
}
