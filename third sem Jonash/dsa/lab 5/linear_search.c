#include<stdio.h>

int search(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++) // loop through the array
        if (arr[i] == x)        // if x is present at i
            return i;           // return index of element
    return -1;
}

// Driver's code
int main()
{
	printf("\t*****Complied by Jonash Chataut*****\n");
    printf("\t******LINEAR SEARCH ALGORITHM ******\n\n");
    int n;
    printf("Enter size of array: ");
    scanf("%d",&n);

    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    int x;
    char choice;
    while(1)
    {
    printf("Enter element to search: ");
    scanf("%d", &x);

    int result = search(arr, n, x);
    (result == -1) ? printf("Element is not present in array") : printf("Element is present at index(starting from index 0): %d\n",result);
    printf("Do you want to continue (y/n)? ");
    scanf(" %c", &choice);
    if (choice != 'y' && choice != 'Y')
        break;
    }
    return 0;
}