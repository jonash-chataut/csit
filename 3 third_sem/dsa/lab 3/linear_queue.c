// Linear_queue_code
#include <stdio.h>
#include <stdlib.h>

int rear = -1;  // Index for the last element
int front = -1; // Index for the first element

int enqueue(int max, int queue[]);
int dequeue(int queue[]);
int display(int queue[]);

int main()
{
    int MAXSIZE;
    printf("****Basic operations of linear queue****\n  Complied by -> Jonash\n");
    printf("Enter the size of the queue: ");
    scanf("%d", &MAXSIZE);
    int queue[MAXSIZE];

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
            enqueue(MAXSIZE, queue);
            break;
        case '2':
            dequeue(queue);
            break;
        case '3':
            display(queue);
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

int enqueue(int max, int queue[])
{
    int n;
    if (rear == max - 1) // Queue is full
    {
        printf("Queue overflow. Cannot enqueue.\n");
    }
    else
    {
        printf("Enter the element to be enqueued: ");
        scanf("%d", &n);
        rear++;
        queue[rear] = n;
        printf("Element enqueued: %d\n", n);
    }
    return 0;
}

int dequeue(int queue[])
{
    if (front == rear) // Queue is empty
    {
        printf("Queue is empty. Cannot dequeue.\n");
    }
    else
    {
        front++;
        printf("Element dequeued: %d\n", queue[front]);
    }
    return 0;
}

int display(int queue[])
{
    if (front == rear) // Queue is empty
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Queue elements are:\n");
        for (int i = front + 1; i <= rear; i++)
        {
            printf("%d ", queue[i]);
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
