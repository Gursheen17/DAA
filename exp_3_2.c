#include <stdio.h>

// Recursive Binary Search function
int binarySearch(int arr[], int low, int high, int key)
{
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (arr[mid] == key)
        return mid;

    if (key < arr[mid])
        return binarySearch(arr, low, mid - 1, key);
    else
        return binarySearch(arr, mid + 1, high, key);
}

int main()
{
    int arr[100], n, key, index;

    // Read number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Read array elements
    printf("Enter elements in sorted order:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Read search element
    printf("Enter search element: ");
    scanf("%d", &key);

    // Call recursive binary search
    index = binarySearch(arr, 0, n - 1, key);

    // Display result
    if (index != -1)
        printf("Element found at index %d\n", index);
    else
        printf("Element not found.\n");

    return 0;
}