#include <stdio.h>
#include <stdlib.h>
int number[50];
int binarySearch(int A[], int l, int r, int key)
{
    if (l <= r)
    {
        int mid = (l + r) / 2;
        if (A[mid] == key)
            return mid;
        else if (A[mid] < key)
            return binarySearch(A, mid + 1, r, key);
        else
            return binarySearch(A, l, mid - 1, key);
    }
    return -1;
}

int main()
{
	printf("\t*****Complied by Jonash Chataut*****\n");
    int total;
    printf("\t******BINARY SEARCH ALGORITHM ******\n\n");
    printf("Enter the total no. of data:");
    scanf("%d", &total);
    printf("\nEnter the data now (Ascending order only):\n");
    for (int i = 0; i < total; i++)
    {
        scanf("%d", &number[i]);
    }
    while (1)
    {
        printf("\nEnter the number to be searched on the array: ");
        int temp;
        scanf("%d", &temp);
        int index = binarySearch(number, 0, total - 1, temp);
        if (index != -1)
            printf("Search is found at index %d.\n", index);
        else
            printf("Search is not found.\n");

        printf("Do you want to continue(y/n)?");
        char choice;
        scanf(" %c", &choice);
        if (choice != 'y' && choice != 'Y')
            break;
    }
    return 0;
}