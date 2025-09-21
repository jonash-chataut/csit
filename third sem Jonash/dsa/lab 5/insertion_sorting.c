#include <stdio.h>
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        // Display the array state before insertion
        printf("Array before inserting %d: ", key);
        for (int k = 0; k < n; k++)
        {
            printf("%d ", arr[k]);
        }
        printf("\n");

        // Shift elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        while (j >= 0 && arr[j] > key)
        {
            // Display the shift operation
            printf("Shifting %d to the right\n", arr[j]);

            arr[j + 1] = arr[j];
            j--;
        }
        // Insert the stored key at its correct position in sorted array
        arr[j + 1] = key;

        // Display the array state after insertion
        printf("Array after inserting %d: ", key);
        for (int k = 0; k < n; k++)
        {
            printf("%d ", arr[k]);
        }
        printf("\n\n");
    }
}

int main()
{
	printf("\t*****Complied by Jonash Chataut*****\n");
    int arr_size;
    printf("\t******INSERTION SORT******\n\n");
    printf("Enter the size of the array: ");
    scanf("%d", &arr_size);

    int arr[arr_size];
    printf("Enter the elements of the array:");
    for (int i = 0; i < arr_size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nGiven array is:\n");
    for (int i = 0; i < arr_size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    // Sorting the array using insertion sort in ascending order
    insertionSort(arr, arr_size);

    printf("\nSorted array is:\n");
    for (int i = 0; i < arr_size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}