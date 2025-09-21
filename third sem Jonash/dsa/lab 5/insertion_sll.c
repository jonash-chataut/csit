#include <stdio.h>
#include <stdlib.h>

// Define the node structure with typedef
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Function to create a new node
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at beginning (modifies head, so we need Node**)
void insertAtBeginning(Node **head, int data)
{
    Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Insert at end (uses single pointer since we're not changing head)
void insertAtEnd(Node *head, int data)
{
    Node *newNode = createNode(data);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
}

// Insert at specific position (modifies head if position=1)
void insertAtPosition(Node **head, int data, int position)
{
    if (position < 1)
    {
        printf("Invalid position! Position starts at 1.\n");
        return;
    }

    if (position == 1)
    {
        insertAtBeginning(head, data);
        return;
    }

    Node *newNode = createNode(data);
    Node *current = *head;

    // Traverse to the node before the desired position
    for (int i = 1; current != NULL && i < position - 1; i++)
    {
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Position exceeds list length!\n");
        free(newNode);
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// Print the linked list
void printList(Node *head)
{
    Node *current = head;
    printf("List: ");
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Free memory
void freeList(Node *head)
{
    Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    Node *head = NULL; // Start with empty list

    // Insertions
    insertAtBeginning(&head, 10); // Note: &head is passed
    insertAtEnd(head, 20);        // head is passed directly
    insertAtPosition(&head, 15, 2);
    insertAtPosition(&head, 5, 1);

    // Print the list
    printList(head); // Output: 5 -> 10 -> 15 -> 20 -> NULL

    // Clean up
    freeList(head);
    return 0;
}