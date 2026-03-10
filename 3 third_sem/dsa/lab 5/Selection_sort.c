#include <stdio.h>

void selectionSort(int A[], int n, int choice)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i; // considered first value as the minimun/maximum value in array
        printf("Pass %d:\n", i + 1);
        // Print array after each pass
        for (int k = 0; k < n; k++)
        {
            printf("%d\t ", A[k]);
        }
        printf("\n");

        // Find the index of the minimum/maximum element
        for (int j = i + 1; j < n; j++)
        {
            if ((choice == 1 && A[j] < A[min_index]) || (choice == 2 && A[j] > A[min_index]))
            {
                min_index = j;
            }
        }
        // Swap the found minimum/maximum element with the i element
        if (min_index != i)
        {
            int temp = A[min_index];
            A[min_index] = A[i];
            A[i] = temp;
        }
    }

    // Print the sorted array
    printf("\n\nThe sorted data is:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t ", A[i]);
    }
    printf("\n");
}

int main()
{
	printf("\t*****Complied by Jonash Chataut*****\n");
    printf("\t*****SELECTION SORT******\n\n");
    printf("Enter the no. of terms to be sorted: ");
    int terms;
    scanf("%d", &terms);
    int numbers[terms];
    printf("Enter the numbers to be sorted: ");
    for (int i = 0; i < terms; i++)
    {
        scanf("%d", &numbers[i]);
    }
    printf("\nChoose sorting order:\n");
    printf("1. Ascending\n");
    printf("2. Descending\n");
    printf("\nEnter your choice: ");
    int choice;
    scanf("%d", &choice);
    printf("\n");
    if (choice == 1 || choice == 2)
        selectionSort(numbers, terms, choice);
    else
        printf("\nNo option found.");

    return 0;
}