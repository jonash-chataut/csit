#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int key;
    struct node *left, *right;
} s_node;

// Create a node
s_node *newNode(int item)
{
    s_node *temp = (s_node *)malloc(sizeof(s_node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Inorder Traversal
void inorder(s_node *root)
{
    if (root != NULL)
    {
        // Traverse left
        inorder(root->left);

        // Traverse root
        printf("%d -> ", root->key);
        // cout << root->key << " -> ";

        // Traverse right
        inorder(root->right);
    }
}

// Insert a node
s_node *insert(s_node *node, int key)
{
    // Return a new node if the tree is empty
    if (node == NULL)
        return newNode(key);

    // Traverse to the right place and insert the node
    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    return node;
}

// Find the inorder successor
struct node *minValueNode(struct node *node)
{
    struct node *current = node;

    // Find the leftmost leaf
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key)
{
    // Return if the tree is empty
    if (root == NULL)
        return root;

    // Find the node to be deleted
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else
    {
        // If the node is with only one child or no child
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // If the node has two children
        struct node *temp = minValueNode(root->right);

        // Place the inorder successor in position of the node to be deleted
        root->key = temp->key;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// function to search a key in a BST
s_node *search(s_node *root, int key)
{

    // Base Cases: root is null or key
    // is present at root
    if (root == NULL || root->key == key)
        return root;
    // Key is greater than root's key
    else if (root->key < key)
        return search(root->right, key);
    // Key is smaller than root's key
    else if (root->key > key)
        return search(root->left, key);
    else
    {
        return NULL;
    }
}

// free memory
void freeTree(s_node *root)
{
    if (root)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main()
{
    printf("\t*****Complied by Jonash Chataut*****\n");
    s_node *root = NULL;
    s_node *srh;
    int choice, key;
    while (1)
    {
        printf("Enter your choice\n1. Insertion\n2. Deletion\n3. Traversal(Inorder)\n4. Search\n5. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the key to be inserted: ");
            scanf("%d", &key);
            root = insert(root, key);
            break;

        case 2:
            printf("Enter the key to be deleted: ");
            scanf("%d", &key);
            root = deleteNode(root, key);
            break;

        case 3:
            inorder(root);
            printf("\n");
            break;

        case 4:
            printf("Enter the key to search: ");
            scanf("%d", &key);
            srh = search(root, key);
            srh ? printf("Key found\n") : printf("Key not found\n");
            break;

        case 5:
            freeTree(root);
            exit(0);

        default:
            printf("Wrong choice!!\nTry again...");
        }
    }
    return 0;
}
